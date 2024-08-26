LuaCEmbedResponse * transaction_write(LuaCEmbedTable *self,LuaCEmbed *args){

    char *filename = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }


    Writeble  *write_obj = create_writeble(args,1);
    if(write_obj->error){
        LuaCEmbedResponse *response =  write_obj->error;
        Writeble_free(write_obj);
        return  response;
    }

    DtwTransaction *t = (DtwTransaction*)LuaCembedTable_get_long_prop(self,TRANSACTION_POINTER);
    DtwTransaction_write_any(t,filename,write_obj->content,write_obj->size,write_obj->is_binary);
    Writeble_free(write_obj);
    return  LuaCEmbed_send_table(self);
}


LuaCEmbedResponse * transaction_remove_any(LuaCEmbedTable *self,LuaCEmbed *args) {
    char *source = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }
    DtwTransaction *t = (DtwTransaction*)LuaCembedTable_get_long_prop(self,TRANSACTION_POINTER);
    DtwTransaction_delete_any(t,source);
    return  LuaCEmbed_send_table(self);
}

LuaCEmbedResponse * transaction_copy_any(LuaCEmbedTable *self,LuaCEmbed *args) {
    char *source = LuaCEmbed_get_str_arg(args,0);
    char *dest = LuaCEmbed_get_str_arg(args,1);

    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }
    DtwTransaction *t = (DtwTransaction*)LuaCembedTable_get_long_prop(self,TRANSACTION_POINTER);
    DtwTransaction_copy_any(t,source,dest);
    return  LuaCEmbed_send_table(self);
}

LuaCEmbedResponse * transaction_move_any(LuaCEmbedTable *self,LuaCEmbed *args) {
    char *source = LuaCEmbed_get_str_arg(args,0);
    char *dest = LuaCEmbed_get_str_arg(args,1);

    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }
    DtwTransaction *t = (DtwTransaction*)LuaCembedTable_get_long_prop(self,TRANSACTION_POINTER);
    DtwTransaction_move_any(t,source,dest);
    return  LuaCEmbed_send_table(self);
}
