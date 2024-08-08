
bool get_table_props_or_default_bool(LuaCEmbedTable *table,const char *prop,bool default_value){
    if(table == NULL){
        return default_value;
    }
    if(LuaCEmbedTable_get_type_prop(table,prop) != LUA_CEMBED_NIL){
        return LuaCembedTable_get_bool_prop(table,prop);
    }
    return default_value;
}

LuaCEmbedResponse * concat_path(LuaCEmbed *args){
    char *path1 = LuaCEmbed_get_str_arg(args,0);
    char *path2 = LuaCEmbed_get_str_arg(args,1);

    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }
    char *value = dtw_concat_path(path1,path2);
    LuaCEmbedResponse *response = LuaCEmbed_send_str(value);
    free(value);
    return  response;
}
LuaCEmbedResponse * starts_with(LuaCEmbed *args){
    char *content =  LuaCEmbed_get_str_arg(args,0);
    char *comparation =  LuaCEmbed_get_str_arg(args,1);

    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }
    bool result = dtw_starts_with(content,comparation);
    return LuaCEmbed_send_bool(result);
}

LuaCEmbedResponse * ends_with(LuaCEmbed *args){
    char *content =  LuaCEmbed_get_str_arg(args,0);
    char *comparation =  LuaCEmbed_get_str_arg(args,1);

    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }
    bool result = dtw_ends_with(content,comparation);
    return LuaCEmbed_send_bool(result);
}

