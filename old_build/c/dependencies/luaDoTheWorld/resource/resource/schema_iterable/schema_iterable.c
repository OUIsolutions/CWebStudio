
LuaCEmbedResponse * schema_list_resources(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResourceArray  *elements = DtwResource_get_schema_values(resource);

    if(DtwResource_error(resource)){
        char *error_mensage = DtwResource_get_error_message(resource);
        LuaCEmbedResponse *response = LuaCEmbed_send_error(error_mensage);
        DtwResource_clear_errors(resource);
        return  response;
    }

    LuaCEmbedTable *multi_response = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable *response = LuaCembed_new_anonymous_table(args);

    LuaCEmbedTable_append_table(multi_response,response);
    LuaCEmbedTable_append_long(multi_response,elements->size);

    for(int i = 0; i < elements->size; i++) {
        DtwResource*current = elements->resources[i];
        LuaCEmbedTable  *sub = raw_create_resource(args,current);
        LuaCEmbedTable_append_table(response,sub);
    }

    return LuaCEmbed_send_multi_return(multi_response);
}

LuaCEmbedResponse * try_schema_list_resources(LuaCEmbedTable *self,LuaCEmbed *args) {
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResourceArray  *elements = DtwResource_get_schema_values(resource);

    resource_protect(resource,args)
    LuaCEmbedTable *multi_response =  LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_append_bool(multi_response,true);

    LuaCEmbedTable *listage = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_append_table(multi_response,listage);
    LuaCEmbedTable_append_long(multi_response,elements->size);

    for(int i = 0; i < elements->size; i++) {
        DtwResource*current = elements->resources[i];
        LuaCEmbedTable  *sub = raw_create_resource(args,current);
        LuaCEmbedTable_append_table(listage,sub);
    }

    return  LuaCEmbed_send_multi_return(multi_response);

}

LuaCEmbedResponse * schema_find_resource(LuaCEmbedTable *self,LuaCEmbed *args){

    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);

    DtwResourceArray  *elements = DtwResource_get_schema_values(resource);
    if(DtwResource_error(resource)){
        char *error_mensage = DtwResource_get_error_message(resource);
        LuaCEmbedResponse *response = LuaCEmbed_send_error(error_mensage);
        DtwResource_clear_errors(resource);
        return  response;
    }


    for(int i = 0; i < elements->size; i++) {
        DtwResource*current = elements->resources[i];
        LuaCEmbedTable  *sub = raw_create_resource(args,current);

        LuaCEmbedTable *args_to_callback = LuaCembed_new_anonymous_table(args);
        LuaCEmbedTable_append_table(args_to_callback,sub);
        LuaCEmbedTable  *user_response = LuaCEmbed_run_args_lambda(args,0,args_to_callback,1);

        if(LuaCEmbed_has_errors(args)){
            char *error = LuaCEmbed_get_error_message(args);
            return LuaCEmbed_send_error(error);
        }
        long size = LuaCEmbedTable_get_full_size(user_response);
        bool return_element = false;
        if(size > 0 ){
            return_element = LuaCEmbedTable_get_bool_by_index(user_response,0);
        }
        if(LuaCEmbed_has_errors(args)){

            char *error = LuaCEmbed_get_error_message(args);
            return LuaCEmbed_send_error(error);
        }

        if(return_element) {
            return LuaCEmbed_send_table(sub);
        }
    }

    return NULL;
}



LuaCEmbedResponse * schema_count_resource(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);

    DtwResourceArray  *elements = DtwResource_get_schema_values(resource);
    if(DtwResource_error(resource)){
        char *error_mensage = DtwResource_get_error_message(resource);
        LuaCEmbedResponse *response = LuaCEmbed_send_error(error_mensage);
        DtwResource_clear_errors(resource);
        return  response;
    }

    long total = 0;
    for(int i = 0; i < elements->size; i++) {
        DtwResource*current = elements->resources[i];
        LuaCEmbedTable  *sub = raw_create_resource(args,current);

        LuaCEmbedTable *args_to_callback = LuaCembed_new_anonymous_table(args);
        LuaCEmbedTable_append_table(args_to_callback,sub);
        LuaCEmbedTable  *user_response = LuaCEmbed_run_args_lambda(args,0,args_to_callback,1);

        if(LuaCEmbed_has_errors(args)){
            char *error = LuaCEmbed_get_error_message(args);
            return LuaCEmbed_send_error(error);
        }
        long size = LuaCEmbedTable_get_full_size(user_response);
        bool append_element = false;
        if(size > 0 ){
            append_element = LuaCEmbedTable_get_bool_by_index(user_response,0);
        }
        if(LuaCEmbed_has_errors(args)){

            char *error = LuaCEmbed_get_error_message(args);
            return LuaCEmbed_send_error(error);
        }

        if(append_element) {
            total+=1;
        }
    }

    return LuaCEmbed_send_long(total);
}
LuaCEmbedResponse * schema_filter_resource(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);


    DtwResourceArray  *elements = DtwResource_get_schema_values(resource);
    if(DtwResource_error(resource)){
        char *error_mensage = DtwResource_get_error_message(resource);
        LuaCEmbedResponse *response = LuaCEmbed_send_error(error_mensage);
        DtwResource_clear_errors(resource);
        return  response;
    }
    LuaCEmbedTable * multi_response = LuaCembed_new_anonymous_table(args);

    LuaCEmbedTable *response = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_append_table(multi_response,response);
    long total = 0;
    for(int i = 0; i < elements->size; i++) {
        DtwResource*current = elements->resources[i];
        LuaCEmbedTable  *sub = raw_create_resource(args,current);

        LuaCEmbedTable *args_to_callback = LuaCembed_new_anonymous_table(args);
        LuaCEmbedTable_append_table(args_to_callback,sub);
        LuaCEmbedTable  *user_response = LuaCEmbed_run_args_lambda(args,0,args_to_callback,1);

        if(LuaCEmbed_has_errors(args)){
            char *error = LuaCEmbed_get_error_message(args);
            return LuaCEmbed_send_error(error);
        }

        long size = LuaCEmbedTable_get_full_size(user_response);
        bool append_element = false;
        if(size ==1){
            append_element = LuaCEmbedTable_get_bool_by_index(user_response,0);
        }

        if(LuaCEmbed_has_errors(args)){
            char *error = LuaCEmbed_get_error_message(args);
            return LuaCEmbed_send_error(error);
        }
        if(append_element) {
            total+=1;
            LuaCEmbedTable_append_table(response,sub);
        }


    }
    LuaCEmbedTable_append_long(multi_response,total);
    return LuaCEmbed_send_multi_return(multi_response);
}

LuaCEmbedResponse * schema_map_resource(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);


    DtwResourceArray  *elements = DtwResource_get_schema_values(resource);
    if(DtwResource_error(resource)){
        char *error_mensage = DtwResource_get_error_message(resource);
        LuaCEmbedResponse *response = LuaCEmbed_send_error(error_mensage);
        DtwResource_clear_errors(resource);
        return  response;
    }
    LuaCEmbedTable * multi_response = LuaCembed_new_anonymous_table(args);

    LuaCEmbedTable *response = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_append_table(multi_response,response);
    long total_mapped = 0;
    for(int i = 0; i < elements->size; i++) {
        DtwResource*current = elements->resources[i];
        LuaCEmbedTable  *sub = raw_create_resource(args,current);

        LuaCEmbedTable *args_to_callback = LuaCembed_new_anonymous_table(args);
        LuaCEmbedTable_append_table(args_to_callback,sub);
        LuaCEmbedTable  *user_response = LuaCEmbed_run_args_lambda(args,0,args_to_callback,1);

        if(LuaCEmbed_has_errors(args)){
            char *error = LuaCEmbed_get_error_message(args);
            return LuaCEmbed_send_error(error);
        }
        long size = LuaCEmbedTable_get_full_size(user_response);
        if(size >0){
            total_mapped+=1;
            LuaCEmbedTable_append_evaluation(response,"%s[1]",user_response->global_name);
        }
    }
    LuaCEmbedTable_append_long(multi_response,total_mapped);
    return LuaCEmbed_send_multi_return(multi_response);
}

LuaCEmbedResponse * resource_schema_each(LuaCEmbedTable *self, LuaCEmbed *args){
    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);

    DtwResourceArray  *elements = DtwResource_get_schema_values(resource);
    if(DtwResource_error(resource)){
        char *error_mensage = DtwResource_get_error_message(resource);
        LuaCEmbedResponse *response = LuaCEmbed_send_error(error_mensage);
        DtwResource_clear_errors(resource);
        return  response;
    }

    if(DtwResource_error(resource)){
        char *message = DtwResource_get_error_message(resource);
        return LuaCEmbed_send_error(message);
    }

    for(int i = 0; i < elements->size; i++) {
        DtwResource*current = elements->resources[i];
        LuaCEmbedTable  *sub = raw_create_resource(args,current);
        LuaCEmbedTable *args_to_callback = LuaCembed_new_anonymous_table(args);
        LuaCEmbedTable_append_table(args_to_callback,sub);
        LuaCEmbed_run_args_lambda(args,0,args_to_callback,0);
    }
    if(LuaCEmbed_has_errors(args)){
        printf("%s\n",LuaCEmbed_get_error_message(args));
    }

    return NULL;
}
