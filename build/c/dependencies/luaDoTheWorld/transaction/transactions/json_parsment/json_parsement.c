
LuaCEmbedResponse * transaction_dumps_to_json_file(LuaCEmbedTable *self,LuaCEmbed *args) {

    char *filename = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }
    DtwTransaction *t = (DtwTransaction*)LuaCembedTable_get_long_prop(self,TRANSACTION_POINTER);
    DtwTransaction_dumps_to_json_file(t,filename);

    return  LuaCEmbed_send_table(self);
}

LuaCEmbedResponse * transaction_dumps_to_json_string(LuaCEmbedTable *self,LuaCEmbed *args) {

    DtwTransaction *t = (DtwTransaction*)LuaCembedTable_get_long_prop(self,TRANSACTION_POINTER);
    cJSON *parsed = DtwTransaction_dumps_to_json(t);
    char * content = cJSON_Print(parsed);

    LuaCEmbedResponse  *response = LuaCEmbed_send_str(content);
    cJSON_Delete(parsed);
    free(content);
    return response;
}

LuaCEmbedResponse * create_empty_transaction_from_json_string(LuaCEmbed *args) {

    char *content = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }
    UniversalGarbage *garbage = newUniversalGarbage();

    cJSON * parsed = cJSON_Parse(content);
    UniversalGarbage_add(garbage,cJSON_Delete,parsed);
    if(parsed == NULL) {
        LuaCEmbedResponse *response  = LuaCEmbed_send_error(INVALID_JSON_STRING);
        UniversalGarbage_free(garbage);
        return  response;
    }

    DtwTransaction * transaction_obj = newDtwTransaction_from_json(parsed);
    if(transaction_obj == NULL) {
        DtwJsonTransactionError * error =  dtw_validate_json_transaction(parsed);
        UniversalGarbage_add(garbage,DtwJsonTransactionError_free,error);
        LuaCEmbedResponse *response  = LuaCEmbed_send_error(error->mensage);
        UniversalGarbage_free(garbage);
        return  response;
    }

    LuaCEmbedTable * self = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_set_method(self,IS_A_REF,false);
    private_transaction_add_base_methods(self,transaction_obj);
    UniversalGarbage_free(garbage);
    return LuaCEmbed_send_table(self);


}


LuaCEmbedResponse * create_empty_transaction_from_json_file(LuaCEmbed *args) {

    char *filename = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }
    UniversalGarbage *garbage = newUniversalGarbage();

    char *content = dtw_load_string_file_content(filename);
    UniversalGarbage_add_simple(garbage,content);

    if(content == NULL) {
        char *error = private_LuaCembed_format(FILE_NOT_FOUND,filename);
        UniversalGarbage_add_simple(garbage,error);
        LuaCEmbedResponse *response  = LuaCEmbed_send_error(error);
        UniversalGarbage_free(garbage);
        return  response;
    }
    cJSON * parsed = cJSON_Parse(content);
    UniversalGarbage_add(garbage,cJSON_Delete,parsed);


    if(parsed == NULL) {
        char *error = private_LuaCembed_format(INVALID_JSON_FILE,filename);
        UniversalGarbage_add_simple(garbage,error);
        LuaCEmbedResponse *response  = LuaCEmbed_send_error(error);
        UniversalGarbage_free(garbage);
        return  response;
    }


    DtwTransaction * transaction_obj = newDtwTransaction_from_json(parsed);
    if(transaction_obj == NULL) {
        DtwJsonTransactionError * error =  dtw_validate_json_transaction(parsed);
        UniversalGarbage_add(garbage,DtwJsonTransactionError_free,error);
        LuaCEmbedResponse *response  = LuaCEmbed_send_error(error->mensage);
        UniversalGarbage_free(garbage);
        return  response;
    }

    LuaCEmbedTable * self = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_set_method(self,IS_A_REF,false);
    private_transaction_add_base_methods(self,transaction_obj);
    UniversalGarbage_free(garbage);
    return LuaCEmbed_send_table(self);


}