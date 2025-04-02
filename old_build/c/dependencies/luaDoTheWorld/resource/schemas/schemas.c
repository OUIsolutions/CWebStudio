
LuaCEmbedResponse  * set_schema_index_name(LuaCEmbedTable *self,LuaCEmbed *args) {
    char *index_name =  LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)) {
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }
    DtwSchema *schema = (DtwSchema*)LuaCembedTable_get_long_prop(self,SCHEMA_POINTER);
    schema->index_name =index_name;
    return LuaCEmbed_send_table(self);
}

LuaCEmbedResponse  * set_schema_value_name(LuaCEmbedTable *self,LuaCEmbed *args) {
    char *value_name =  LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)) {
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }
    DtwSchema *schema = (DtwSchema*)LuaCembedTable_get_long_prop(self,SCHEMA_POINTER);
    schema->value_name =value_name;
    return LuaCEmbed_send_table(self);
}


LuaCEmbedResponse  * add_schema_primary_keys(LuaCEmbedTable *self,LuaCEmbed *args){

    DtwSchema *schema = (DtwSchema*)LuaCembedTable_get_long_prop(self,SCHEMA_POINTER);
    int arg_type = LuaCEmbed_get_arg_type(args,0);
    if(arg_type == LUA_CEMBED_STRING){
        char *value = LuaCEmbed_get_str_arg(args,0);
        DtwSchema_add_primary_key(schema,value);
        return LuaCEmbed_send_table(self);
    }

    if(arg_type != LUA_CEMBED_TABLE){
        return LuaCEmbed_send_error(ARGUMENT_NOT_IN_STRING_OR_STRING_ARRAY);
    }

    LuaCEmbedTable *string_array = LuaCEmbed_get_arg_table(args,0);
    long size = LuaCEmbedTable_get_full_size(string_array);
    for(int i = 0; i < size;i++){
        int current_type = LuaCEmbedTable_get_type_by_index(string_array,i);
        if(current_type != LUA_CEMBED_STRING){
            return LuaCEmbed_send_error(ARGUMENT_NOT_IN_STRING_OR_STRING_ARRAY);
        }
    }

    for(int i = 0; i < size;i++){
        char *current_value = LuaCEmbedTable_get_string_by_index(string_array,i);
        DtwSchema_add_primary_key(schema,current_value);
    }
    return LuaCEmbed_send_table(self);
}

LuaCEmbedResponse  * schema_add_sub_schema(LuaCEmbedTable *self,LuaCEmbed *args){
    char *name = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *message = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(message);
    }

    DtwSchema *schema = (DtwSchema*)LuaCembedTable_get_long_prop(self,SCHEMA_POINTER);
    DtwSchema *sub_schmea = DtwSchema_new_subSchema(schema,name);
    LuaCEmbedTable *created_table = raw_create_schema(args,sub_schmea);
    return LuaCEmbed_send_table(created_table);
}

LuaCEmbedTable  * raw_create_schema(LuaCEmbed *args,DtwSchema *schema){
    LuaCEmbedTable *created= LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_set_long_prop(created,SCHEMA_POINTER,(long long )schema);
    LuaCEmbedTable_set_method(created,ADD_PRIMARY_KEYS,add_schema_primary_keys);
    LuaCEmbedTable_set_method(created,ADD_SUB_SCHEMA_METHOD,schema_add_sub_schema);
    LuaCEmbedTable_set_method(created,SET_INDEX_NAME_METHOD,set_schema_index_name);
    LuaCEmbedTable_set_method(created,SET_VALUE_NAME_METHOD,set_schema_value_name);
    return created;
}

