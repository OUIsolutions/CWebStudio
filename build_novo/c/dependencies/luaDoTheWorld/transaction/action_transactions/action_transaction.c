

LuaCEmbedResponse  *action_transaction_get_transaction_type_code(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwActionTransaction *transaction = (DtwActionTransaction *) LuaCembedTable_get_long_prop(self,ACTION_TRANSACTION_POINTER);
    return LuaCEmbed_send_long(transaction->action_type);
}

LuaCEmbedResponse  *action_transaction_get_transaction_type(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwActionTransaction *transaction = (DtwActionTransaction *) LuaCembedTable_get_long_prop(self,ACTION_TRANSACTION_POINTER);
   int type = transaction->action_type;
   const char *converted = DtwActionTransaction_convert_action_to_string(type);
   return LuaCEmbed_send_str_reference(converted);
}


LuaCEmbedResponse  *action_transaction_get_content(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwActionTransaction *transaction = (DtwActionTransaction *) LuaCembedTable_get_long_prop(self,ACTION_TRANSACTION_POINTER);
    if(!transaction->content){
        return NULL;
    }
    return LuaCEmbed_send_raw_string_reference((char*)transaction->content, transaction->size);
}


LuaCEmbedResponse  *action_transaction_set_content(LuaCEmbedTable *self,LuaCEmbed *args){
    Writeble  *write_obj = create_writeble(args,0);
    if(write_obj->error){
        LuaCEmbedResponse *response =  write_obj->error;
        Writeble_free(write_obj);
        return  response;
    }
    DtwActionTransaction *transaction = (DtwActionTransaction *) LuaCembedTable_get_long_prop(self,ACTION_TRANSACTION_POINTER);

    if(transaction->content){
        free(transaction->content);
    }
    transaction->content = (unsigned  char *)malloc((write_obj->size + 1)* sizeof(unsigned  char));
    memcpy(transaction->content,write_obj->content,write_obj->size);
    transaction->size = write_obj->size;
    Writeble_free(write_obj);
    return NULL;
}


LuaCEmbedResponse  *action_transaction_set_source(LuaCEmbedTable *self,LuaCEmbed *args){
    char *new_source = LuaCEmbed_get_str_arg(args, 0);

    if (LuaCEmbed_has_errors(args)) {
        char *error = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error);
    }

    DtwActionTransaction *transaction = (DtwActionTransaction *) LuaCembedTable_get_long_prop(self,
                                                                                          ACTION_TRANSACTION_POINTER);

    if (transaction->source != NULL) {
        free(transaction->source);
    }
    transaction->source = strdup(new_source);

    return NULL;
}

LuaCEmbedResponse  *action_transaction_set_dest(LuaCEmbedTable *self,LuaCEmbed *args){

    char *new_dest = LuaCEmbed_get_str_arg(args,0);

    if(LuaCEmbed_has_errors(args)) {
        char * error = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error);
    }
    DtwActionTransaction *transaction = (DtwActionTransaction *) LuaCembedTable_get_long_prop(self,ACTION_TRANSACTION_POINTER);

    if (transaction->dest != NULL) {
        free(transaction->dest);
    }
    transaction->dest = strdup(new_dest);

    return NULL;
}

LuaCEmbedResponse  *action_transaction_get_source(LuaCEmbedTable *self,LuaCEmbed *args){

    DtwActionTransaction *transaction = (DtwActionTransaction *) LuaCembedTable_get_long_prop(self,
                                                                                          ACTION_TRANSACTION_POINTER);
    if (transaction->source) {
        return LuaCEmbed_send_str_reference(transaction->source);
    }
    return NULL;
}

LuaCEmbedResponse  *action_transaction_get_dest(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwActionTransaction *transaction = (DtwActionTransaction*)LuaCembedTable_get_long_prop(self,ACTION_TRANSACTION_POINTER);
    if(transaction->dest){
        return LuaCEmbed_send_str_reference(transaction->dest);
    }
    return  NULL;
}

LuaCEmbedTable *raw_create_action_transaction(LuaCEmbed *args,DtwActionTransaction *transaction){
    LuaCEmbedTable * table = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_set_long_prop(table,DTW_TYPE,DTW_ACTION_TRANSACTION_TYPE);
    LuaCEmbedTable_set_long_prop(table,ACTION_TRANSACTION_POINTER,(long long)transaction);
    LuaCEmbedTable_set_method(table,LUA_DO_THE_WORLD_GET_DEST,action_transaction_get_dest);
    LuaCEmbedTable_set_method(table,LUA_DO_THE_WORLD_SET_DEST,action_transaction_set_dest);
    LuaCEmbedTable_set_method(table,LUA_DO_THE_WORLD_GET_SOURCE,action_transaction_get_source);
    LuaCEmbedTable_set_method(table, LUA_DO_THE_WORLD_SET_SOURCE, action_transaction_set_source);
    LuaCEmbedTable_set_method(table, LUA_DO_THE_WORLD_GET_TRANSACTION_TYPE_TEXT, action_transaction_get_transaction_type);
    LuaCEmbedTable_set_method(table, LUA_DO_THE_WORLD_GET_TRANSACTION_TYPE_CODE,action_transaction_get_transaction_type_code);
    LuaCEmbedTable_set_method(table, LUA_DO_THE_WORLD_GET_CONTENT, action_transaction_get_content);
    LuaCEmbedTable_set_method(table, LUA_DO_THE_WORLD_SET_CONTENT, action_transaction_set_content);

    return  table;
}