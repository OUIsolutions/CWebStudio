LuaCEmbedResponse *tree_list(LuaCEmbedTable *self, LuaCEmbed *args) {
    DtwTree *self_tree = (DtwTree*)LuaCembedTable_get_long_prop(self,TREE_POINTER);
    LuaCEmbedTable *multi_response = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable *elements = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_append_table(multi_response,elements);
    LuaCEmbedTable_append_long(multi_response,self_tree->size);

    for(int i =0; i < self_tree->size;i++){
        LuaCEmbedTable *tree_part = create_tree_part_reference(args,self_tree->tree_parts[i]);
        LuaCEmbedTable_append_table(elements,tree_part);
    }

    return LuaCEmbed_send_multi_return(multi_response);
}

LuaCEmbedResponse *tree_find(LuaCEmbedTable *self, LuaCEmbed *args){
    DtwTree *self_tree = (DtwTree*)LuaCembedTable_get_long_prop(self,TREE_POINTER);

    for(int i =0; i < self_tree->size;i++){
        LuaCEmbedTable *tree_part = create_tree_part_reference(args,self_tree->tree_parts[i]);
        LuaCEmbedTable *args_to_call = LuaCembed_new_anonymous_table(args);
        LuaCEmbedTable_append_table(args_to_call,tree_part);
        LuaCEmbedTable *response = LuaCEmbed_run_args_lambda(args,0,args_to_call,1);
        if(LuaCEmbed_has_errors(args)){
            char *error_msg = LuaCEmbed_get_error_message(args);
            return LuaCEmbed_send_error(error_msg);
        }
        long size = LuaCEmbedTable_get_full_size(response);
        bool return_element = false;
        if(size > 0 ){
            return_element = LuaCEmbedTable_get_bool_by_index(response,0);
        }
        if(LuaCEmbed_has_errors(args)){

            char *error = LuaCEmbed_get_error_message(args);
            return LuaCEmbed_send_error(error);
        }

        if(return_element) {
            return LuaCEmbed_send_table(tree_part);
        }

    }
    return NULL;
}


LuaCEmbedResponse *tree_count(LuaCEmbedTable *self, LuaCEmbed *args){
    DtwTree *self_tree = (DtwTree*)LuaCembedTable_get_long_prop(self,TREE_POINTER);
    long total = 0;
    for(int i =0; i < self_tree->size;i++){
        LuaCEmbedTable *tree_part = create_tree_part_reference(args,self_tree->tree_parts[i]);
        LuaCEmbedTable *args_to_call = LuaCembed_new_anonymous_table(args);
        LuaCEmbedTable_append_table(args_to_call,tree_part);
        LuaCEmbedTable *user_response = LuaCEmbed_run_args_lambda(args,0,args_to_call,1);
        if(LuaCEmbed_has_errors(args)){
            char *error_msg = LuaCEmbed_get_error_message(args);
            return LuaCEmbed_send_error(error_msg);
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
            total+=1;
        }

    }
    return LuaCEmbed_send_long(total);
}

LuaCEmbedResponse *tree_filter(LuaCEmbedTable *self, LuaCEmbed *args){

    DtwTree *self_tree = (DtwTree*)LuaCembedTable_get_long_prop(self,TREE_POINTER);
    LuaCEmbedTable *multi_response = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable *final_map = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_append_table(multi_response,final_map);
    long total = 0;


    for(int i =0; i < self_tree->size;i++){
        LuaCEmbedTable *tree_part = create_tree_part_reference(args,self_tree->tree_parts[i]);
        LuaCEmbedTable *args_to_call = LuaCembed_new_anonymous_table(args);
        LuaCEmbedTable_append_table(args_to_call,tree_part);
        LuaCEmbedTable *user_response = LuaCEmbed_run_args_lambda(args,0,args_to_call,1);

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
            LuaCEmbedTable_append_table(final_map,tree_part);
        }

    }
    LuaCEmbedTable_append_long(multi_response,total);

    return  LuaCEmbed_send_multi_return(multi_response);
}


LuaCEmbedResponse *tree_map(LuaCEmbedTable *self, LuaCEmbed *args){

    DtwTree *self_tree = (DtwTree*)LuaCembedTable_get_long_prop(self,TREE_POINTER);
    LuaCEmbedTable *multi_response = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable *final_map = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_append_table(multi_response,final_map);
    LuaCEmbedTable_append_long(multi_response,self_tree->size);


    for(int i =0; i < self_tree->size;i++){
        LuaCEmbedTable *tree_part = create_tree_part_reference(args,self_tree->tree_parts[i]);
        LuaCEmbedTable *args_to_call = LuaCembed_new_anonymous_table(args);
        LuaCEmbedTable_append_table(args_to_call,tree_part);
        LuaCEmbedTable *user_response = LuaCEmbed_run_args_lambda(args,0,args_to_call,1);

        if(LuaCEmbed_has_errors(args)){
            char *error = LuaCEmbed_get_error_message(args);
            return LuaCEmbed_send_error(error);
        }
        long size = LuaCEmbedTable_get_full_size(user_response);
        if(size >0){
            LuaCEmbedTable_append_evaluation(final_map,"%s[1]",user_response->global_name);
        }

    }
    return  LuaCEmbed_send_multi_return(multi_response);
}




LuaCEmbedResponse *tree_foreach(LuaCEmbedTable *self, LuaCEmbed *args){

    DtwTree *self_tree = (DtwTree*)LuaCembedTable_get_long_prop(self,TREE_POINTER);

    for(int i =0; i < self_tree->size;i++){
        LuaCEmbedTable *tree_part = create_tree_part_reference(args,self_tree->tree_parts[i]);
        LuaCEmbedTable *args_to_call = LuaCembed_new_anonymous_table(args);
        LuaCEmbedTable_append_table(args_to_call,tree_part);
        LuaCEmbed_run_args_lambda(args,0,args_to_call,1);
        if(LuaCEmbed_has_errors(args)){
            char *error_msg = LuaCEmbed_get_error_message(args);
            printf("pegou aqui\n");
            return LuaCEmbed_send_error(error_msg);
        }

    }
    return NULL;
}
