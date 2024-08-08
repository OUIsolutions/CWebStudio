
void private_DtwResurce_destroy_primary_key(DtwResource *self) {


    if (!DtwResource_is_file(self)) {
        return;
    }

    DtwResource *root = self->mother->mother->mother;
    DtwResource *pk_index_folder = DtwResource_sub_resource(root->index_resource, "%s", self->name);
    long size;
    bool is_binary;
    unsigned char *possible_pk_value = DtwResource_get_any(self, &size, &is_binary);
    char *pk_sha = dtw_generate_sha_from_any(possible_pk_value, size);

    DtwResource *pk_index_value = DtwResource_sub_resource(pk_index_folder, "%s", pk_sha);

    if(DtwResource_error(self)){
        return;
    }

    free(pk_sha);
    if (self->allow_transaction) {
        DtwTransaction_delete_any(self->root_props->transaction, pk_index_value->path);
    } else {
        dtw_remove_any(pk_index_value->path);
    }


}
void private_DtwResource_destroy_all_primary_keys(DtwResource *self){
    DtwSchema * schema = (DtwSchema*)self->mother->mother->attached_schema;
    for(int i = 0; i < schema->primary_keys->size; i++){
        char *current_pk = schema->primary_keys->strings[i];
        DtwResource *son = DtwResource_sub_resource(self,"%s",current_pk);
        private_DtwResurce_destroy_primary_key(son);

        if(DtwResource_error(self)){
            return;
        }

    }
}
void DtwResource_destroy(DtwResource *self){
    if(DtwResource_error(self)){
        return;
    }


    if(self->schema_type == PRIVATE_DTW_SCHEMA_ELEMENT){
        self->root_props->is_writing_schema = true;
        private_DtwResource_destroy_all_primary_keys(self);
        self->root_props->is_writing_schema =false;
    }

    if(private_DtwResource_its_a_pk(self)){
        self->root_props->is_writing_schema = true;
        private_DtwResurce_destroy_primary_key(self);
        self->root_props->is_writing_schema =false;

    }

    if(DtwResource_error(self)){
        return;
    }

    if(self->root_props->is_writing_schema == false){
        if(
                self->schema_type == PRIVATE_DTW_SCHEMA_VALUE
                || self->schema_type == PRIVATE_DTW_SCHEMA_INDEX
                || self->schema_type == PRIVATE_DTW_SCHEMA_PK_FOLDER
                || self->schema_type == PRIVATE_DTW_SCHEMA_PK_VALUE
        ){
            private_DtwResource_raise_error(
                    self,
                    DTW_RESOURCE_ONLY_ROOT_SCHEMA_CANN_MODIFY_SCHEMA_PROPS,
                    "you cannot delete a internal schema part"
            );
        }
    }

    if(DtwResource_error(self)){
        return;
    }


    if(self->allow_transaction){
        DtwTransaction_delete_any(self->root_props->transaction,self->path);
    }
    else{
        dtw_remove_any(self->path);
    }

}

void DtwResource_destroy_sub_resource(DtwResource *self, const char *key){
    if(DtwResource_error(self)){
        return;
    }
    DtwResource *son = DtwResource_sub_resource(self, "%s",key);
    DtwResource_destroy(son);
}

