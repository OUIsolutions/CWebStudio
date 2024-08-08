

DtwResource *new_DtwResource(const char *path){
    DtwResource *self = (DtwResource*) malloc(sizeof (DtwResource));
    *self =(DtwResource){0};

    self->path = strdup(path);
    self->name = strdup(path);
    self->sub_resources = newDtwResourceArray();
    self->allow_transaction = true;
    self->use_locker_on_unique_values = true;
    self->cache_sub_resources = true;
    self->root_props = private_newDtwResourceRootProps();

    return self;
}   

DtwResource * DtwResource_sub_resource(DtwResource *self,const  char *format, ...){
    if(DtwResource_error(self)){
        return NULL;
    }


    privateDtwResource_ensure_its_possible_to_sub_resource(self);

    if(DtwResource_error(self)){
        return NULL;
    }


    if(self->were_renamed){
        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_RENAMED_RESOURCE_CANNOT_HAVE_SONS,
                "you cannot create a sub resurce from a renamed resource",
                self->name
        );
        return NULL;
    }


    va_list args;
    va_start(args, format);
    char *name = private_dtw_format_vaarg(format,args);
    va_end(args);


    DtwResource * Already_Exist = DtwResourceArray_get_by_name((DtwResourceArray*)self->sub_resources,name);
    if(Already_Exist){
        free(name);
        return Already_Exist;
    }

    DtwResource *new_element = (DtwResource*) malloc(sizeof (DtwResource));
    *new_element =(DtwResource){0};

    if(self->schema_type == PRIVATE_DTW_SCHEMA_VALUE){
        new_element->schema_type = PRIVATE_DTW_SCHEMA_ELEMENT;
    }
    if(self->schema_type ==PRIVATE_DTW_SCHEMA_ELEMENT){
        new_element->schema_type = PRIVATE_DTW_SCHEMA_ELEMENT_PROP;
    }

    if(self->schema_type == PRIVATE_DTW_SCHEMA_INDEX){
        new_element->schema_type = PRIVATE_DTW_SCHEMA_PK_FOLDER;
    }
    if(self->schema_type == PRIVATE_DTW_SCHEMA_PK_FOLDER){
        new_element->schema_type = PRIVATE_DTW_SCHEMA_PK_VALUE;
    }



    new_element->allow_transaction = self->allow_transaction;
    new_element->use_locker_on_unique_values = self->use_locker_on_unique_values;
    new_element->root_props = self->root_props;
    //copied elements

    new_element->mother = self;
    new_element->path = dtw_concat_path(self->path, name);
    new_element->name = strdup(name);


    new_element->cache_sub_resources = self->cache_sub_resources;
    new_element->sub_resources = newDtwResourceArray();

    if(self->datatabase_schema && self->root_props->is_writing_schema == false){
        new_element->attached_schema = privateDtwDtatabaseSchema_get_sub_schema(self->datatabase_schema, name);
    }

    if(self->schema_type == PRIVATE_DTW_SCHEMA_ELEMENT){
        DtwResource * ancestor = self->mother->mother;
        new_element->attached_schema = privateDtwSchema_get_sub_schema(ancestor->attached_schema, name);
    }



    if(new_element->attached_schema){
        self->root_props->is_writing_schema = true;
        new_element->schema_type = PRIVATE_DTW_SCHEMA_ROOT;
        new_element->values_resource = DtwResource_sub_resource(new_element,DTW_SCHEMA_DEFAULT_VALUES_NAME);
        new_element->values_resource->schema_type = PRIVATE_DTW_SCHEMA_VALUE;
        new_element->index_resource = DtwResource_sub_resource(new_element,DTW_SCHEMA_DEFAULT_INDEX_NAME);
        new_element->index_resource->schema_type = PRIVATE_DTW_SCHEMA_INDEX;
    }



    if(self->cache_sub_resources){
        DtwResourceArray_append((DtwResourceArray*)self->sub_resources,new_element);
    }


    free(name);
    return new_element;

}
DtwResource * DtwResource_sub_resource_ensuring_not_exist(DtwResource *self,const  char *format, ...){
    if(DtwResource_error(self)){
        return NULL;
    }
    va_list args;
    va_start(args, format);
    char *name = private_dtw_format_vaarg(format,args);
    va_end(args);
;

    DtwResource *possible_emptiy  = DtwResourceArray_get_by_name(
            (DtwResourceArray*)self->sub_resources,
            name
    );
    if(possible_emptiy){
        return NULL;
    }

    bool old_cache_value = self->cache_sub_resources;
    self->cache_sub_resources = false;
    possible_emptiy = DtwResource_sub_resource(self,"%s",name);
    possible_emptiy->cache_sub_resources = old_cache_value;
    self->cache_sub_resources = old_cache_value;
    if(self->use_locker_on_unique_values){
        DtwResource_lock(possible_emptiy);
    }

    int type = DtwResource_type(possible_emptiy);

    if(type == DTW_NOT_FOUND){


            if(self->cache_sub_resources){
                DtwResourceArray_append((DtwResourceArray*)self->sub_resources,possible_emptiy);
            }
            free(name);
            return possible_emptiy;
    }
    DtwResource_unlock(possible_emptiy);
    DtwResource_free(possible_emptiy);
    free(name);
    return  NULL;

}

void DtwResource_free(DtwResource *self){
    if(!self){
        return;
    }

    bool is_root = self->mother == NULL;
    if(is_root){
        privateDtwResourceRootProps_free(self->root_props);
    }

    if(self->datatabase_schema){
        private_new_DtwDtatabaseSchema_free(self->datatabase_schema);
    }

    DtwResourceArray_free((DtwResourceArray*)self->sub_resources);



    if(self->value_any){
        free(self->value_any);
    }


    free(self->path);
    free(self->name);
    free(self);
}