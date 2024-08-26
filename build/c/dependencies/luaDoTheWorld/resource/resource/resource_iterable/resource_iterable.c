
LuaCEmbedResponse * resource_list(LuaCEmbedTable  *self,LuaCEmbed *args) {
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResourceArray  *elements = DtwResource_sub_resources(resource);
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


LuaCEmbedResponse * resource_foreach(LuaCEmbedTable  *self,LuaCEmbed *args) {


    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResourceArray  *elements = DtwResource_sub_resources(resource);

    for(int i =0; i < elements->size; i++) {
        DtwResource *current = elements->resources[i];
        LuaCEmbedTable  *sub = raw_create_resource(args,current);
        LuaCEmbedTable *args_to_callback = LuaCembed_new_anonymous_table(args);
        LuaCEmbedTable_append_table(args_to_callback,sub);
        LuaCEmbed_run_args_lambda(args,0,args_to_callback,0);

        if(LuaCEmbed_has_errors(args)){
            char *error = LuaCEmbed_get_error_message(args);
            return LuaCEmbed_send_error(error);
        }

    }
    return LuaCEmbed_send_table(self);

}

LuaCEmbedResponse * resource_filter(LuaCEmbedTable  *self,LuaCEmbed *args) {
    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResourceArray  *elements = DtwResource_sub_resources(resource);

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
        if(size >0){
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
LuaCEmbedResponse * resource_map(LuaCEmbedTable  *self,LuaCEmbed *args) {
    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResourceArray  *elements = DtwResource_sub_resources(resource);

    LuaCEmbedTable * multi_response = LuaCembed_new_anonymous_table(args);

    LuaCEmbedTable *response = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_append_table(multi_response,response);
    long size_mapped  = 0;
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
            size_mapped+=1;
            LuaCEmbedTable_append_evaluation(response,"%s[1]",user_response->global_name);
        }

    }
    LuaCEmbedTable_append_long(multi_response,size_mapped);
    return LuaCEmbed_send_multi_return(multi_response);
}

LuaCEmbedResponse * resource_count(LuaCEmbedTable  *self,LuaCEmbed *args) {
    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResourceArray  *elements = DtwResource_sub_resources(resource);
    long total  = 0;
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
        if(size >0){
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


LuaCEmbedResponse * resource_find(LuaCEmbedTable  *self,LuaCEmbed *args) {
    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResourceArray  *elements = DtwResource_sub_resources(resource);
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
        if(size >0){
            append_element = LuaCEmbedTable_get_bool_by_index(user_response,0);
        }

        if(LuaCEmbed_has_errors(args)){
            char *error = LuaCEmbed_get_error_message(args);
            return LuaCEmbed_send_error(error);
        }
        if(append_element) {
            return LuaCEmbed_send_table(sub);
        }
    }

    return NULL;
}