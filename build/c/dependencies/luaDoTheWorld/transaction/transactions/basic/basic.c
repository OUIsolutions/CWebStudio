





LuaCEmbedResponse * transaction_commit(LuaCEmbedTable *self,LuaCEmbed *args) {

    const char *path = NULL;
    if(LuaCEmbed_get_total_args(args) > 0){
        path  = LuaCEmbed_get_str_arg(args,0);
    }
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }
    DtwTransaction *t = (DtwTransaction*)LuaCembedTable_get_long_prop(self,TRANSACTION_POINTER);
    DtwTransaction_commit(t,path);
    return  LuaCEmbed_send_table(self);
}



LuaCEmbedResponse * transaction_delete(LuaCEmbedTable *self,LuaCEmbed *args) {
    DtwTransaction *t = (DtwTransaction*)LuaCembedTable_get_long_prop(self,TRANSACTION_POINTER);
    bool ref = LuaCembedTable_get_bool_prop(self,IS_A_REF);

    if(!ref){
        DtwTransaction_free(t);
    }
    return  NULL;
}


void  private_transaction_add_base_methods(LuaCEmbedTable *self,DtwTransaction *transaction){
    LuaCEmbedTable_set_long_prop(self,TRANSACTION_POINTER,(long long)transaction);
    LuaCEmbedTable_set_method(self,WRITE_METHOD,transaction_write);
    LuaCEmbedTable_set_method(self,COPY_ANY_METHOD,transaction_copy_any);
    LuaCEmbedTable_set_method(self,REMOVE_ANY_METHOD,transaction_remove_any);
    LuaCEmbedTable_set_method(self,MOVE_ANY_METHOD,transaction_move_any);
    LuaCEmbedTable_set_method(self,COPY_ANY_METHOD,transaction_copy_any);
    LuaCEmbedTable_set_method(self,COMMIT_METHOD,transaction_commit);
    LuaCEmbedTable_set_method(self,DUMP_TO_JSON_FILE_METHOD,transaction_dumps_to_json_file);
    LuaCEmbedTable_set_method(self,DUMP_TO_JSON_STRING,transaction_dumps_to_json_string);
    LuaCEmbedTable_set_method(self,LIST_METHOD,transaction_list);
    LuaCEmbedTable_set_method(self,EACH_METHOD,transaction_foreach);
    LuaCEmbedTable_set_method(self,MAP_METHOD,transaction_map);
    LuaCEmbedTable_set_method(self,COUNT_METHOD,transaction_count);
    LuaCEmbedTable_set_method(self,INDEX_METHOD,transaction_index);
    LuaCEmbedTable_set_method(self,FIND_METHOD,transaction_find);
    LuaCEmbedTable_set_method(self,FILTER_METHOD,transaction_filter);
    LuaCEmbedTable_set_method(self,DELETE_METHOD,transaction_delete);

}


LuaCEmbedResponse * transaction_new_transaction(LuaCEmbed *args){
    LuaCEmbedTable * self = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_set_bool_prop(self,IS_A_REF,false);
    DtwTransaction *transaction = newDtwTransaction();
    LuaCEmbedTable_set_long_prop(self,TRANSACTION_POINTER,(long)transaction);
    if(LuaCEmbed_has_errors(self->main_object)){
        printf("error %s\n", LuaCEmbed_get_error_message(self->main_object));
    }

    private_transaction_add_base_methods(self,transaction);
    return LuaCEmbed_send_table(self);
}
