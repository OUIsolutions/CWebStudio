
LuaCEmbedResponse * private_resource_sub_resource_raw(LuaCEmbedTable  *self, LuaCEmbed *args,const char *src){
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource *sub_resource = DtwResource_sub_resource(resource,"%s",src);
    LuaCEmbedTable  *sub = raw_create_resource(args,sub_resource);
    return LuaCEmbed_send_table(sub);
}

LuaCEmbedResponse * resource_sub_resource_index(LuaCEmbedTable  *self, LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);

    int type = LuaCEmbed_get_arg_type(args,1);
    if(type == LUA_CEMBED_NUMBER){
        long raw_index =  LuaCEmbed_get_long_arg(args,1);
        long  i = raw_index-1;
        DtwResourceArray  *elements = DtwResource_sub_resources(resource);

        if(i >=elements->size || i  < 0){
            return NULL;
        }
        DtwResource *current = elements->resources[i];
        LuaCEmbedTable  *sub = raw_create_resource(args,current);
        LuaCEmbedTable *response = LuaCembed_new_anonymous_table(args);
        LuaCEmbedTable_append_long(response,raw_index);
        LuaCEmbedTable_append_table(response,sub);
        return LuaCEmbed_send_multi_return(response);
    }

    char *src = LuaCEmbed_get_str_arg(args,1);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }
    return private_resource_sub_resource_raw(self,args,src);
}



LuaCEmbedResponse * resource_sub_resource_method(LuaCEmbedTable  *self, LuaCEmbed *args){
    char *src = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }
    return private_resource_sub_resource_raw(self,args,src);
}

LuaCEmbedResponse * resource_sub_resource_next(LuaCEmbedTable  *self,LuaCEmbed *args){
    const char *src = "";
    if(LuaCEmbed_get_total_args(args) > 0){
        src  = LuaCEmbed_get_str_arg(args,0);
    }
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }

    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource *sub_resource = DtwResource_sub_resource_next(resource,src);
    LuaCEmbedTable  *sub = raw_create_resource(args,sub_resource);
    return LuaCEmbed_send_table(sub);
}

LuaCEmbedResponse * resource_sub_resource_now(LuaCEmbedTable  *self,LuaCEmbed *args){
    const char *src = "";
    if(LuaCEmbed_get_total_args(args) > 0){
        src  = LuaCEmbed_get_str_arg(args,0);
    }
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }

    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource *sub_resource = DtwResource_sub_resource_now(resource,src);
    LuaCEmbedTable  *sub = raw_create_resource(args,sub_resource);
    return LuaCEmbed_send_table(sub);
}

LuaCEmbedResponse * resource_sub_resource_now_in_unix(LuaCEmbedTable  *self,LuaCEmbed *args){
    const char *src = "";
    if(LuaCEmbed_get_total_args(args) > 0){
        src  = LuaCEmbed_get_str_arg(args,0);
    }
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }

    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource *sub_resource = DtwResource_sub_resource_now_in_unix(resource,src);
    LuaCEmbedTable  *sub = raw_create_resource(args,sub_resource);
    return LuaCEmbed_send_table(sub);
}

