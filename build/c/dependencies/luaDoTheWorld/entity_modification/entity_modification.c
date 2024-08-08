
LuaCEmbedResponse * lua_get_entity_last_modification_in_unix(LuaCEmbed *args) {
    char *file = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)) {
        char *error_msg =  LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }
    long last_modification = dtw_get_entity_last_motification_in_unix(file);
    if(last_modification == -1) {
        return NULL;
    }
    return LuaCEmbed_send_long(last_modification);
}


LuaCEmbedResponse * lua_get_entity_last_modification(LuaCEmbed *args) {
    char *file = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)) {
        char *error_msg =  LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }
    char *last_modification = dtw_get_entity_last_motification_in_string(file);
    if(last_modification == NULL) {
        return NULL;
    }
    LuaCEmbedResponse *response  = LuaCEmbed_send_str(last_modification);
    free(last_modification);
    return  response;
}
