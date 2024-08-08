
void DtwResource_set_any_in_sub_resource(DtwResource *self,const char *key, unsigned char *element, long size,bool is_binary) {
    if(DtwResource_error(self)){
        return ;
    }

    DtwResource *created = DtwResource_sub_resource(self,"%s",key);
    DtwResource_set_any(created, element, size,is_binary);
}

void DtwResource_set_binary_in_sub_resource(DtwResource *self,const char *key, unsigned char *element, long size){
    if(DtwResource_error(self)){
        return ;
    }

    DtwResource *created = DtwResource_sub_resource(self,"%s",key);
    DtwResource_set_binary(created, element, size);
}

void DtwResource_set_binary_sha_in_sub_resource(DtwResource *self, const char *key, unsigned  char *value, long size){
    if(DtwResource_error(self)){
        return ;
    }
    DtwResource *created = DtwResource_sub_resource(self,"%s",key);
    DtwResource_set_binary_sha(created,value,size);
}


void DtwResource_set_string_sha_in_sub_resource(DtwResource *self, const char *key, const char *value){
    if(DtwResource_error(self)){
        return ;
    }
    DtwResource *created = DtwResource_sub_resource(self,"%s",key);
    DtwResource_set_string_sha(created,value);
}

void DtwResource_set_string_in_sub_resource(DtwResource *self, const char *key, const  char *element){
    if(DtwResource_error(self)){
        return ;
    }

    DtwResource *created = DtwResource_sub_resource(self,"%s",key);
    DtwResource_set_string(created,element);
}

void DtwResource_set_long_in_sub_resource(DtwResource *self, const char *key, long element){
    if(DtwResource_error(self)){
        return ;
    }
    DtwResource *created = DtwResource_sub_resource(self,"%s",key);
    DtwResource_set_long(created,element);
}

void DtwResource_set_double_in_sub_resource(DtwResource *self, const char *key, double element){
    if(DtwResource_error(self)){
        return ;
    }

    DtwResource *created = DtwResource_sub_resource(self,"%s",key);
    DtwResource_set_double(created,element);
}

void DtwResource_set_bool_in_sub_resource(DtwResource *self,const char *key, bool element){
    if(DtwResource_error(self)){
        return ;
    }

    DtwResource *created = DtwResource_sub_resource(self,"%s",key);
    DtwResource_set_bool(created,element);
}
