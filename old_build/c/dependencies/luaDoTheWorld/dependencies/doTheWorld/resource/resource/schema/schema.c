
bool private_DtwResource_its_a_pk(DtwResource *self){
    if(self->schema_type != PRIVATE_DTW_SCHEMA_ELEMENT_PROP){
        return false;
    }
    DtwResource *ancestor = self->mother->mother->mother;
    DtwSchema * schema = ancestor->attached_schema;
    return DtwStringArray_find_position(schema->primary_keys,self->name) !=-1;
}

void privateDtwResource_ensure_its_possible_to_sub_resource(DtwResource *self){

    if(self->root_props->is_writing_schema){
        return;
    }

    if(self->schema_type == 0){

        return;
    }


    if(self->schema_type != PRIVATE_DTW_SCHEMA_ELEMENT && self->schema_type != PRIVATE_DTW_SCHEMA_ELEMENT_PROP){

        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_IMPOSSIBLE_TO_ADD_SUB_RESOURCE_INSIDE_SCHEMA_STRUCT,
                "impossible to add sub resource inside schema struct "
        );
        return ;
    }

    if(private_DtwResource_its_a_pk(self)){
        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_PRIMARY_KEY_CANNOT_HAVE_SUB_RESOURCE,
                "primary key %s cannot have a sub resource",
                self->name
        );
        return;
    }

}


DtwResource * DtwResource_new_schema_insertion(DtwResource *self){

    if(DtwResource_error(self)){
        return NULL;
    }
    if(self->schema_type != PRIVATE_DTW_SCHEMA_ROOT || self->datatabase_schema){
        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_IMPSSIBLE_TO_ADD_INSERTION_OUTSIDE_ROOT_SCHEMA,
                "only root schema can generate insertions");
        return NULL;
    }
    self->root_props->is_writing_schema = true;

    DtwResource  *created = DtwResource_sub_resource_random(self->values_resource,NULL);
    self->root_props->is_writing_schema = false;
    return created;
}

DtwResource  *DtwResource_find_by_name_id(DtwResource *self, const char *name){

    if(DtwResource_error(self)){
        return NULL;
    }
    if(self->schema_type != PRIVATE_DTW_SCHEMA_ROOT){
        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_ONLY_ROOT_SCHEMA_CAN_FIND_BY_ID_OR_PK,
                "only root schema can find by id or pk"
                );
        return NULL;
    }
    self->root_props->is_writing_schema = true;

    DtwResource *element = DtwResource_sub_resource(self->values_resource,name);

    if(DtwResource_type(element) == DTW_NOT_FOUND){
        return NULL;
    }
    self->root_props->is_writing_schema = false;

    return element;
}
DtwResource * DtwResource_find_by_primary_key_with_binary(DtwResource *self, const char *primary_key, unsigned  char *value, long size){
    if(DtwResource_error(self)){
        return NULL;
    }
    if(self->schema_type != PRIVATE_DTW_SCHEMA_ROOT){
        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_ONLY_ROOT_SCHEMA_CAN_FIND_BY_ID_OR_PK,
                "only root schema can find by id or pk"
                );
        return NULL;
    }
    self->root_props->is_writing_schema = true;

    DtwResource *primary_key_folder = DtwResource_sub_resource(self->index_resource, "%s", primary_key);
    char *sha = dtw_generate_sha_from_any(value,size);
    DtwResource *index_value = DtwResource_sub_resource(primary_key_folder,"%s",sha);
    free(sha);
    if(DtwResource_type(index_value) == DTW_NOT_FOUND){
        return NULL;
    }
    char *element_folder = DtwResource_get_string(index_value);
    if(DtwResource_error(self)){
        return NULL;
    }
    if(element_folder == NULL){
        return NULL;
    }

    DtwResource *founded_resource = DtwResource_sub_resource(self->values_resource, "%s", element_folder);
    self->root_props->is_writing_schema = false;
    return founded_resource;
}



DtwResource * DtwResource_find_by_primary_key_with_string(DtwResource *self, const char *key, const char *value){
    if(DtwResource_error(self)){
        return NULL;
    }
    return DtwResource_find_by_primary_key_with_binary(self,key,(unsigned char*)value, (long)strlen(value));
}


void DtwResource_dangerous_remove_schema_prop(DtwResource*self,const char *prop){
    if(DtwResource_error(self)){
        return ;
    }
    if(self->schema_type != PRIVATE_DTW_SCHEMA_ROOT){
        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_ONLY_ROOT_SCHEMA_CANN_MODIFY_SCHEMA_PROPS,
                "only root schema can modify schema props"
        );
        return;
    }
    self->root_props->is_writing_schema = true;

    bool allow_transaction = self->allow_transaction;

    DtwResourceArray * all_values = DtwResource_sub_resources(self->values_resource);
    DtwTransaction * transaction = self->root_props->transaction;
    for(int i = 0; i < all_values->size; i++){
        DtwResource *current = all_values->resources[i];
        DtwResource *prop_to_remove = DtwResource_sub_resource(current,"%s",prop);
        if(allow_transaction){
            DtwTransaction_delete_any(transaction,prop_to_remove->path);
        }else{
            dtw_remove_any(prop_to_remove->path);
        }

    }
    DtwResource *index_element = DtwResource_sub_resource(self->index_resource,"%s",prop);
    if(allow_transaction){
        DtwTransaction_delete_any(transaction,index_element->path);
    }else{
        dtw_remove_any(index_element->path);
    }
    self->root_props->is_writing_schema = false;

}


void DtwResource_dangerous_rename_schema_prop(DtwResource*self,const char *prop,const char *new_name){
    if(DtwResource_error(self)){
        return ;
    }
    if(self->schema_type != PRIVATE_DTW_SCHEMA_ROOT){
        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_ONLY_ROOT_SCHEMA_CANN_MODIFY_SCHEMA_PROPS,
                "only root schema can modify schema props"
        );
        return;
    }
    self->root_props->is_writing_schema = true;
    bool allow_transaction = self->allow_transaction;

    DtwResourceArray * all_values = DtwResource_sub_resources(self->values_resource);
    DtwTransaction * transaction = self->root_props->transaction;
    for(int i = 0; i < all_values->size; i++){
        DtwResource *current = all_values->resources[i];
        DtwResource *prop_to_remove = DtwResource_sub_resource(current,"%s",prop);
        DtwResource *new_prop = DtwResource_sub_resource(current,"%s",new_name);
        if(allow_transaction){
            DtwTransaction_move_any_merging(transaction,prop_to_remove->path,new_prop->path);
        }else{
            dtw_move_any(prop_to_remove->path,new_prop->path,DTW_MERGE);
        }

    }


    DtwResource *index_element = DtwResource_sub_resource(self->index_resource,"%s",prop);
    DtwResource *new_index = DtwResource_sub_resource(self->index_resource,"%s",new_name);
    if(allow_transaction){
        DtwTransaction_move_any_merging(transaction,index_element->path,new_index->path);
    }else{
        dtw_move_any(index_element->path,new_index->path,DTW_MERGE);
    }
    self->root_props->is_writing_schema = false;

}



DtwDatabaseSchema * DtwResource_newDatabaseSchema(DtwResource *self){
    if(DtwResource_error(self)){
        return  NULL;
    }
    privateDtwResource_ensure_its_possible_to_sub_resource(self);

    if(DtwResource_error(self)){
        return  NULL;
    }

    if(self->datatabase_schema){
        return self->datatabase_schema;
    }

    self->datatabase_schema = private_newDtwDtatabaseSchema();
    return self->datatabase_schema;
}
