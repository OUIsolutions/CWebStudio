
unsigned char *DtwResource_get_any(DtwResource *self, long *size, bool *is_binary){
    if(DtwResource_error(self)){
        return NULL;
    }
    DtwResource_load_if_not_loaded(self);
    *size = self->value_size;
    *is_binary = self->is_binary;

    if(!self->value_any){
        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_ELEMENT_NOT_EXIST,
                "element at #path# not exist"
                );
        return NULL;
    }

    return self->value_any;


}

unsigned char *DtwResource_get_any_from_sub_resource(DtwResource *self, long *size, bool *is_binary,const char *format,...){
    if(DtwResource_error(self)){
        return NULL;
    }
    va_list args;
    va_start(args, format);
    char *name = private_dtw_format_vaarg(format,args);
    va_end(args);

    DtwResource *element = DtwResource_sub_resource(self,"%s",name);
    free(name);
    return DtwResource_get_any(element,size,is_binary);

}

unsigned char *DtwResource_get_binary(DtwResource *self, long *size){
    if(DtwResource_error(self)){
        return NULL;
    }
    bool is_binary;

    return DtwResource_get_any(self,size,&is_binary);
}

unsigned char *DtwResource_get_binary_from_sub_resource(DtwResource *self, long *size,const char *format,...){
    if(DtwResource_error(self)){
        return NULL;
    }

    va_list args;
    va_start(args, format);
    char *name = private_dtw_format_vaarg(format,args);
    va_end(args);

    DtwResource *element = DtwResource_sub_resource(self,"%s",name);
    free(name);
    return DtwResource_get_binary(element,size);
}


char *DtwResource_get_string(DtwResource *self){
    if(DtwResource_error(self)){
        return NULL;
    }

    long size;
    bool is_binary;
    char *result =  (char *)DtwResource_get_any(self,&size,&is_binary);

    if(is_binary){
        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_ELEMENT_NOT_STRING,
                "element at #path# its an binary"
        );
        return NULL;
    }

    return result;
}


char *DtwResource_get_string_from_sub_resource(DtwResource *self,const char *format,...){
    if(DtwResource_error(self)){
        return NULL;
    }

    va_list args;
    va_start(args, format);
    char *name = private_dtw_format_vaarg(format,args);
    va_end(args);


    DtwResource *element = DtwResource_sub_resource(self,"%s",name);
    free(name);
    return DtwResource_get_string(element);
}


long DtwResource_get_long(DtwResource *self){

    if(DtwResource_error(self)){
        return -1;
    }

    char *element = DtwResource_get_string(self);

    if(DtwResource_error(self)){
        return -1;
    }

    long value;
    int result = sscanf(element,"%ld",&value);
    if(result == 0){
        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_ELEMENT_NOT_LONG,
                "element at #path# its not long"
        );
        return -1;
    }
    return value;
}


long DtwResource_get_long_from_sub_resource(DtwResource *self,const char *format,...){
    if(DtwResource_error(self)){
        return -1;
    }
    va_list args;
    va_start(args, format);
    char *name = private_dtw_format_vaarg(format,args);
    va_end(args);


    DtwResource *element = DtwResource_sub_resource(self,"%s",name);
    free(name);
    return DtwResource_get_long(element);
}


double DtwResource_get_double(DtwResource *self){
    if(DtwResource_error(self)){
        return -1;
    }

    char *element = DtwResource_get_string(self);
    if(DtwResource_error(self)){
        return -1;
    }

    double value;
    int result = sscanf(element,"%lf",&value);
    if(result == 0){
        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_ELEMENT_NOT_DOUBLE,
                "element at #path# its not long"
        );
        return-1;
    }
    return value;
}

double DtwResource_get_double_from_sub_resource(DtwResource *self,const char *format,...){

    if(DtwResource_error(self)){
        return -1;
    }

    va_list args;
    va_start(args, format);
    char *name = private_dtw_format_vaarg(format,args);
    va_end(args);


    DtwResource *element = DtwResource_sub_resource(self,"%s",name);
    free(name);
    return DtwResource_get_double(element);
}


bool DtwResource_get_bool(DtwResource *self){
    if(DtwResource_error(self)){
        return false;
    }
    char *element = DtwResource_get_string(self);
    if(DtwResource_error(self)){
        return false;
    }

    if(strcmp(element,"true") == 0 || strcmp(element,"t") == 0){
        return true;
    }
    if(strcmp(element,"false") == 0 || strcmp(element,"f") == 0){
        return false;
    }

    private_DtwResource_raise_error(
            self,
            DTW_RESOURCE_ELEMENT_NOT_BOOL,
            "element at #path# its not bool"
    );
    return false;
}

bool DtwResource_get_bool_from_sub_resource(DtwResource *self,const char *format,...){
    if(DtwResource_error(self)){
        return false;
    }

    va_list args;
    va_start(args, format);
    char *name = private_dtw_format_vaarg(format,args);
    va_end(args);

    DtwResource *element = DtwResource_sub_resource(self,"%s",name);
    free(name);
    return DtwResource_get_bool(element);
}