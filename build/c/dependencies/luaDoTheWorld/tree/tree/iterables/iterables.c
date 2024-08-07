
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
        int response_type =LuaCEmbedTable_get_type_by_index(response,0);
        if(response_type != LUA_CEMBED_NIL){
            bool is_the_value = LuaCEmbedTable_get_bool_by_index(response,0);
            if(LuaCEmbed_has_errors(args)){
                char *error_msg = LuaCEmbed_get_error_message(args);
                return LuaCEmbed_send_error(error_msg);
            }

            if(is_the_value){
                return  LuaCEmbed_send_table(tree_part);
            }
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
        LuaCEmbedTable *response = LuaCEmbed_run_args_lambda(args,0,args_to_call,1);
        if(LuaCEmbed_has_errors(args)){
            char *error_msg = LuaCEmbed_get_error_message(args);
            return LuaCEmbed_send_error(error_msg);
        }
        int response_type =LuaCEmbedTable_get_type_by_index(response,0);
        if(response_type != LUA_CEMBED_NIL){
            bool is_the_value = LuaCEmbedTable_get_bool_by_index(response,0);
            if(LuaCEmbed_has_errors(args)){
                char *error_msg = LuaCEmbed_get_error_message(args);
                return LuaCEmbed_send_error(error_msg);
            }

            if(is_the_value){
                total+=1;
            }
        }

    }
    return LuaCEmbed_send_long(total);
}


LuaCEmbedResponse *tree_map(LuaCEmbedTable *self, LuaCEmbed *args){

    DtwTree *self_tree = (DtwTree*)LuaCembedTable_get_long_prop(self,TREE_POINTER);
    LuaCEmbedTable *final_map = LuaCembed_new_anonymous_table(args);

    for(int i =0; i < self_tree->size;i++){
        LuaCEmbedTable *tree_part = create_tree_part_reference(args,self_tree->tree_parts[i]);
        LuaCEmbedTable *args_to_call = LuaCembed_new_anonymous_table(args);
        LuaCEmbedTable_append_table(args_to_call,tree_part);
        LuaCEmbedTable *response = LuaCEmbed_run_args_lambda(args,0,args_to_call,1);
        if(LuaCEmbed_has_errors(args)){
            char *error_msg = LuaCEmbed_get_error_message(args);
            return LuaCEmbed_send_error(error_msg);
        }
        int response_type =LuaCEmbedTable_get_type_by_index(response,0);
        if(response_type!= LUA_CEMBED_NIL && response_type != LUA_CEMBED_NOT_FOUND){
            LuaCEmbedTable_append_evaluation(final_map,"%s[1]",response->global_name);
        }

    }
    return LuaCEmbed_send_table(final_map);
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
