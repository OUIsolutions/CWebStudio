//
// Created by mateusmoutinho on 05/08/23.
//
void private_dtw_resource_set_primary_key(DtwResource *self, unsigned  char *element, long size){

    self->root_props->is_writing_schema = true;
    DtwResource * ancestor = self->mother->mother->mother;
    DtwResource *index_resource =ancestor->index_resource;
    DtwResource *pk_folder = DtwResource_sub_resource(index_resource,"%s",self->name);

    char *sha = dtw_generate_sha_from_any(element,size);
    DtwResource  *pk_value = DtwResource_sub_resource(pk_folder,sha);
    free(sha);
    char *mothers_name =self->mother->name;

    if(DtwResource_is_file(pk_value)) {
        char *content = DtwResource_get_string(pk_value);
        if (DtwResource_error(self)) {
            self->root_props->is_writing_schema = false;
            return;
        }

        //means its the same
        if (strcmp(content, mothers_name) == 0) {
            self->root_props->is_writing_schema = false;
            return;
        }

        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_PRIMARY_KEY_ALREADY_EXIST,
                "primary key: %s already exist",
                self->name
        );
        self->root_props->is_writing_schema = false;
        return;

    }
    DtwResource_set_string(pk_value,mothers_name);
    self->root_props->is_writing_schema = false;

}
void DtwResource_set_any(DtwResource *self, unsigned char *element, long size,bool is_binary){
    if(DtwResource_error(self)){
        return ;
    }
    DtwResource_unload(self);

    if(private_DtwResource_its_a_pk(self)){
        private_dtw_resource_set_primary_key(self, element, size);
    }

    if(DtwResource_error(self)){
        return;
    }

    if(self->allow_transaction){
        DtwTransaction_write_any(self->root_props->transaction,self->path,element,size,is_binary);
    }
    else{
        dtw_write_any_content(self->path,element,size);
    }

    self->loaded = true;
    self->value_size = size;
    self->is_binary = is_binary;
    self->value_any = (unsigned  char *) malloc(size+1);

    self->value_any[size]= '\0';
    memcpy(self->value_any,element,size);
}
void DtwResource_set_binary(DtwResource *self, unsigned char *element, long size){
    DtwResource_set_any(self,element,size,true);
}

void DtwResource_set_string(DtwResource *self,const  char *element){
    DtwResource_set_any(self,(unsigned char *)element,strlen(element),false);
}

void DtwResource_set_binary_sha(DtwResource *self, unsigned  char *value, long size){
    if(DtwResource_error(self)){
        return ;
    }
    char *generated_sha = dtw_generate_sha_from_any(value,size);
    DtwResource_set_string(self,generated_sha);
    free(generated_sha);
}

void DtwResource_set_string_sha(DtwResource *self,const char *value){
    if(DtwResource_error(self)){
        return ;
    }
    DtwResource_set_binary_sha(self,(unsigned char*)value, (long)strlen(value));
}








void DtwResource_set_long(DtwResource *self,long element){
    if(DtwResource_error(self)){
        return ;
    }
    if(self->allow_transaction){
        DtwTransaction_write_long(self->root_props->transaction,self->path,element);
    }
    else{
        dtw_write_long_file_content(self->path,element);
    }
    DtwResource_unload(self);
    self->loaded = true;
    char result[20] ={0};
    sprintf(result,"%ld",element);
    self->value_any = (unsigned char *)strdup(result);

}

void DtwResource_set_double(DtwResource *self,double element){
    if(DtwResource_error(self)){
        return ;
    }
    if(self->allow_transaction){
        DtwTransaction_write_double(self->root_props->transaction,self->path,element);
    }
    else{
        dtw_write_double_file_content(self->path,element);
    }
    DtwResource_unload(self);
    self->loaded = true;
    char result[20] ={0};
    sprintf(result,"%lf",element);
    self->value_any = (unsigned char *)strdup(result);


}

void DtwResource_set_bool( DtwResource *self,bool element){
    if(DtwResource_error(self)){
        return ;
    }
    if(self->allow_transaction){
        DtwTransaction_write_bool(self->root_props->transaction,self->path,element);
    }
    else{
        dtw_write_bool_file_content(self->path,element);
    }

    DtwResource_unload(self);
    self->loaded = true;
    if(element){
        self->value_any = (unsigned char*)strdup("true");
    }
    else{
        self->value_any = (unsigned char*)strdup("false");

    }

}
