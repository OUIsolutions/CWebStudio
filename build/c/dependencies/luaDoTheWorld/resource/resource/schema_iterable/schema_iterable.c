
LuaCEmbedResponse * schema_list_resources(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResourceArray  *elements = DtwResource_sub_resources(resource->values_resource);
    LuaCEmbedTable *response = LuaCembed_new_anonymous_table(args);
    for(int i = 0; i < elements->size; i++) {
        DtwResource*current = elements->resources[i];
        LuaCEmbedTable  *sub = raw_create_resource(args,current);
        LuaCEmbedTable_append_table(response,sub);
    }
    return LuaCEmbed_send_table(response);
}

LuaCEmbedResponse * schema_find_resource(LuaCEmbedTable *self,LuaCEmbed *args){

    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResourceArray  *elements = DtwResource_sub_resources(resource->values_resource);
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

        bool possible_return = LuaCEmbedTable_get_bool_by_index(user_response,0);
        if(possible_return){
            return LuaCEmbed_send_table(sub);
        }
    }

    return NULL;
}



LuaCEmbedResponse * schema_count_resource(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResourceArray  *elements = DtwResource_sub_resources(resource->values_resource);
    long size = 0;
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

        bool possible_return = LuaCEmbedTable_get_bool_by_index(user_response,0);
        if(possible_return){
            size+=1;
        }
    }

    return LuaCEmbed_send_long(size);
}

LuaCEmbedResponse * schema_map_resource(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResourceArray  *elements = DtwResource_sub_resources(resource->values_resource);
    LuaCEmbedTable *response = LuaCembed_new_anonymous_table(args);

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
        if(size ==1){
            LuaCEmbedTable_append_evaluation(response,"%s[1]",user_response->global_name);
        }


    }

    return LuaCEmbed_send_table(response);
}

LuaCEmbedResponse * resource_schema_each(LuaCEmbedTable *self, LuaCEmbed *args){
    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResourceArray  *elements = DtwResource_get_schema_values(resource);

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
