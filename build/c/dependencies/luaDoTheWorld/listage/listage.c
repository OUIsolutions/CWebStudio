
LuaCEmbedResponse  * aply_listage(LuaCEmbed *args,DtwStringArray* (*callback)(const char *folder,bool concat_path)){
    char *source = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }
    bool concat_path = false;
    if(LuaCEmbed_get_total_args(args) >= 2){
        concat_path = LuaCEmbed_get_bool_arg(args,1);
    }
    DtwStringArray * listage = callback(source,concat_path);
    DtwStringArray_sort(listage);
    LuaCEmbedTable * table = LuaCembed_new_anonymous_table(args);
    for(int i = 0; i < listage->size; i++){
        char * current_value = listage->strings[i];
        LuaCEmbedTable_append_string(table,current_value);
    }

    LuaCEmbedTable *final = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_append_table(final,table);
    LuaCEmbedTable_append_long(final,listage->size);
    DtwStringArray_free(listage);
    return LuaCEmbed_send_multi_return(final);
}

LuaCEmbedResponse  * list_files(LuaCEmbed *args){
    return aply_listage(args,dtw_list_files);
}

LuaCEmbedResponse  * list_dirs(LuaCEmbed *args){
    return aply_listage(args,dtw_list_dirs);

}

LuaCEmbedResponse  * list_all(LuaCEmbed *args){
    return aply_listage(args,dtw_list_all);
}

LuaCEmbedResponse  * list_files_recursively(LuaCEmbed *args){
   return aply_listage(args,dtw_list_files_recursively);
}

LuaCEmbedResponse  * list_dirs_recursively(LuaCEmbed *args){
    return aply_listage(args,dtw_list_dirs_recursively);
}

LuaCEmbedResponse  * list_all_recursively(LuaCEmbed *args){
    return aply_listage(args,dtw_list_all_recursively);
}
