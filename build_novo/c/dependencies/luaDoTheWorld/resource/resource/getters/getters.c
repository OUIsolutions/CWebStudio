LuaCEmbedResponse * resource_to_string(LuaCEmbedTable  *self,LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    int  type = DtwResource_type(resource);
    if(type == DTW_NOT_FOUND || type == DTW_FOLDER_TYPE ){
        return  LuaCEmbed_send_str(resource->path);
    }
    long size;
    bool is_binary;
    unsigned  char *content =  DtwResource_get_any(resource,&size,&is_binary);
    return LuaCEmbed_send_raw_string_reference((char*)content,size);

}


LuaCEmbedResponse * resource_to_number(LuaCEmbedTable  *self,LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    double value = DtwResource_get_double(resource);
    if(DtwResource_error(resource)){
        char *error_message = DtwResource_get_error_message(resource);
        LuaCEmbedResponse *response = LuaCEmbed_send_error(error_message);
        DtwResource_clear_errors(resource);
        return response;
    }
    return LuaCEmbed_send_double(value);
}

LuaCEmbedResponse * resource_value(LuaCEmbedTable  *self,LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    int type = DtwResource_type(resource);

    if(type == DTW_FOLDER_TYPE || type == DTW_NOT_FOUND){
        return NULL;
    }

    if(type == DTW_COMPLEX_DOUBLE_TYPE || type == DTW_COMPLEX_LONG_TYPE){
        double value = DtwResource_get_double(resource);
        return LuaCEmbed_send_double(value);
    }

    if(type == DTW_COMPLEX_BOOL_TYPE){
        bool value= DtwResource_get_bool(resource);
        return LuaCEmbed_send_bool(value);
    }

    if(type == DTW_COMPLEX_BINARY || type == DTW_COMPLEX_STRING_TYPE){

        long size;
        bool is_binary;
        unsigned  char *content =  DtwResource_get_any(resource,&size,&is_binary);
        return LuaCEmbed_send_raw_string_reference((char*)content,size);
    }

    return NULL;
}
LuaCEmbedResponse * resource_value_string(LuaCEmbedTable  *self,LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    int type = DtwResource_type(resource);
    if(type != DTW_NOT_FOUND && type != DTW_FOLDER_TYPE){
        long size;
        bool is_binary;
        unsigned  char *content =  DtwResource_get_any(resource,&size,&is_binary);
        return LuaCEmbed_send_raw_string_reference((char*)content,size);
    }
    return NULL;
}

LuaCEmbedResponse * resource_value_number(LuaCEmbedTable  *self,LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    int type = DtwResource_type(resource);

    if(type == DTW_COMPLEX_DOUBLE_TYPE || type == DTW_COMPLEX_LONG_TYPE){
        double value = DtwResource_get_double(resource);
        return LuaCEmbed_send_double(value);
    }

    return NULL;
}

LuaCEmbedResponse * resource_value_bool(LuaCEmbedTable  *self,LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    int type = DtwResource_type(resource);


    if(type == DTW_COMPLEX_BOOL_TYPE){
        bool value= DtwResource_get_bool(resource);
        return LuaCEmbed_send_bool(value);
    }


    return NULL;
}

LuaCEmbedResponse * resource_value_from_sub_resource(LuaCEmbedTable  *self,LuaCEmbed *args){
    char *src = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }

    DtwResource  *master = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource *sub = DtwResource_sub_resource(master,src);

    int type = DtwResource_type(sub);

    if(type == DTW_FOLDER_TYPE || type == DTW_NOT_FOUND){
        return NULL;
    }
    if(type == DTW_COMPLEX_DOUBLE_TYPE || type == DTW_COMPLEX_LONG_TYPE){
        double value = DtwResource_get_double(sub);
        return LuaCEmbed_send_double(value);
    }


    if(type == DTW_COMPLEX_BOOL_TYPE){
        bool value= DtwResource_get_bool(sub);
        return LuaCEmbed_send_bool(value);
    }

    if(type == DTW_COMPLEX_BINARY || type == DTW_COMPLEX_STRING_TYPE ){
        long size;
        unsigned  char *content =  DtwResource_get_binary(sub,&size);
        return LuaCEmbed_send_raw_string_reference((char*)content,size);
    }

    return NULL;
}

LuaCEmbedResponse * resource_to_boolean(LuaCEmbedTable  *self,LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    bool value = DtwResource_get_bool(resource);
    if(DtwResource_error(resource)){
        char *error_message = DtwResource_get_error_message(resource);
        LuaCEmbedResponse *response = LuaCEmbed_send_error(error_message);
        DtwResource_clear_errors(resource);
        return response;
    }
    return LuaCEmbed_send_bool(value);
}