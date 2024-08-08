


LuaCEmbedResponse *private_LuaCEmbedReturn_raw(){
    LuaCEmbedResponse *self = (LuaCEmbedResponse*)malloc(sizeof(LuaCEmbedResponse));
    *self = (LuaCEmbedResponse){0};
    return self;
}

LuaCEmbedResponse  * LuaCEmbed_send_bool(bool value){
    LuaCEmbedResponse * self= private_LuaCEmbedReturn_raw();
    self->type = PRIVATE_LUA_CEMBED_BOOL_RESPONSE;
    self->num_val = (double)value;
    return self;
}


LuaCEmbedResponse * LuaCEmbed_send_str(const char *text){
    LuaCEmbedResponse * self= private_LuaCEmbedReturn_raw();
    self->type = PRIVATE_LUA_CEMBED_STRING_RESPONSE;
    self->string_size = (long)strlen(text);
    self->string_val  =  (char*)malloc(sizeof(char) * self->string_size +1);
    memcpy(self->string_val,text,self->string_size);
    self->string_val[self->string_size] = '\0';
    return self;
}

LuaCEmbedResponse * LuaCEmbed_send_raw_string(const char *text,long size){
    LuaCEmbedResponse * self= private_LuaCEmbedReturn_raw();
    self->type = PRIVATE_LUA_CEMBED_STRING_RESPONSE;
    self->string_size = size;
    self->string_val  =  (char*)malloc(sizeof(char) * self->string_size +1);
    memcpy(self->string_val,text,self->string_size);
    self->string_val[self->string_size] = '\0';
    return self;
}

LuaCEmbedResponse * LuaCEmbed_send_str_reference(const char *text){
    LuaCEmbedResponse * self= private_LuaCEmbedReturn_raw();
    self->type = PRIVATE_LUA_CEMBED_STRING_RESPONSE;
    self->string_size = (long)strlen(text);
    self->string_val  = (char*)text;
    self->its_string_ref = true;
    return self;
}

LuaCEmbedResponse * LuaCEmbed_send_raw_string_reference(const  char *text,long size){
    LuaCEmbedResponse * self= private_LuaCEmbedReturn_raw();
    self->type = PRIVATE_LUA_CEMBED_STRING_RESPONSE;
    self->string_size = size;
    self->string_val  = (char*)text;
    self->its_string_ref = true;
    return  self;
}



LuaCEmbedResponse * LuaCEmbed_send_error(const char *format,...){

    va_list args;
    va_start(args,format);
    char *error = private_LuaCembed_format_vaarg(format,args);
    va_end(args);

    LuaCEmbedResponse * self= private_LuaCEmbedReturn_raw();
    self->type = PRIVATE_LUA_CEMBED_ERROR_RESPONSE;
    self->string_val  = error;
    return self;
}


LuaCEmbedResponse * LuaCEmbed_send_multi_return(LuaCEmbedTable *table){
    LuaCEmbedResponse * self= private_LuaCEmbedReturn_raw();
    self->type = PRIVATE_LUA_CEMBED_MULTI_RESPONSE;
    lua_getglobal(table->main_object->state,table->global_name);
    lua_setglobal(table->main_object->state,PRIVATE_LUA_CEMBED_TABLE_RETURN);
    return self;
}

LuaCEmbedResponse * LuaCEmbed_send_table(LuaCEmbedTable *table){
    LuaCEmbedResponse * self= private_LuaCEmbedReturn_raw();
    self->type = PRIVATE_LUA_CEMBED_TABLE_RESPONSE;
    lua_getglobal(table->main_object->state,table->global_name);
    lua_setglobal(table->main_object->state,PRIVATE_LUA_CEMBED_TABLE_RETURN);
    return self;
}

LuaCEmbedResponse * LuaCEmbed_send_evaluation(const char *code){
    LuaCEmbedResponse * self= private_LuaCEmbedReturn_raw();
    self->type = PRIVATE_LUA_CEMBED_EVALUATION;
    self->string_val  = strdup(code);
    return self;
}

LuaCEmbedResponse  * LuaCEmbed_send_double(double value){
    LuaCEmbedResponse * self= private_LuaCEmbedReturn_raw();
    self->type = PRIVATE_LUA_CEMBED_DOUBLE_RESPONSE;
    self->num_val = value;
    return self;
}

LuaCEmbedResponse  * LuaCEmbed_send_long(long value){
    LuaCEmbedResponse * self= private_LuaCEmbedReturn_raw();
    self->type = PRIVATE_LUA_CEMBED_LONG_RESPONSE;
    self->num_val = (double)value;
    return self;
}



void private_LuaCEmbedResponse_free(LuaCEmbedResponse  *self){

    if(self->string_val && self->its_string_ref == false){
        free(self->string_val);
    }
    free(self);
}
