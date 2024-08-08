
DtwDatabaseSchema *private_newDtwDtatabaseSchema(){
    DtwDatabaseSchema *self = (DtwDatabaseSchema*) malloc(sizeof (DtwDatabaseSchema));
    *self = (DtwDatabaseSchema){0};
    self->value_name = DTW_SCHEMA_DEFAULT_VALUES_NAME;
    self->index_name = DTW_SCHEMA_DEFAULT_INDEX_NAME;
    self->sub_schemas = (struct DtwSchema **)malloc(0);
    return  self;
}


DtwSchema * privateDtwDtatabaseSchema_get_sub_schema(DtwDatabaseSchema *self,const char *name){

    for(int i = 0; i < self->size; i++){
        DtwSchema  *current = self->sub_schemas[i];

        if(strcmp(current->name,name) == 0){
            return  current;
        }

    }
    return NULL;
}

DtwSchema * DtwDtatabaseSchema_new_subSchema(DtwDatabaseSchema *self,const char *name){
    DtwSchema *subSchema = private_newDtwSchema(name);
    self->sub_schemas = ( DtwSchema **) realloc(self->sub_schemas, (self->size + 1) * sizeof( DtwSchema *));
    self->sub_schemas[self->size] = subSchema;
    self->size+=1;
    return subSchema;
}



void private_new_DtwDtatabaseSchema_free(DtwDatabaseSchema *self){
    for (int i = 0; i < self->size; i++) {
        private_newDtwSchema_free((DtwSchema *) self->sub_schemas[i]);
    }
    free(self->sub_schemas);
    free(self);
}

