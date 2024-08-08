

LuaCEmbedResponse * tree_part_exist_in_hardware(LuaCEmbedTable *self,LuaCEmbed *args) {
    DtwTreePart *self_part  = (DtwTreePart*)LuaCembedTable_get_long_prop(self,TREE_PART_POINTER);
    return  LuaCEmbed_send_bool(self_part->content_exist_in_hardware);
}


LuaCEmbedResponse * tree_part_exis(LuaCEmbedTable *self,LuaCEmbed *args) {
    DtwTreePart *self_part  = (DtwTreePart*)LuaCembedTable_get_long_prop(self,TREE_PART_POINTER);
    if(self_part->content_exist_in_hardware) {
        return  LuaCEmbed_send_bool(true);
    }
    if(self_part->content) {
        return  LuaCEmbed_send_bool(true);
    }
    return LuaCEmbed_send_bool(false);

}


LuaCEmbedResponse * tree_part_get_value(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwTreePart *self_part  = (DtwTreePart*)LuaCembedTable_get_long_prop(self,TREE_PART_POINTER);

    if(self_part->content){
        return LuaCEmbed_send_raw_string((char*)self_part->content,self_part->content_size);
    }
    return NULL;
}

LuaCEmbedResponse * tree_part_to_string(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwTreePart *self_part  = (DtwTreePart*)LuaCembedTable_get_long_prop(self,TREE_PART_POINTER);

    if(self_part->content){
        return LuaCEmbed_send_raw_string((char*)self_part->content,self_part->content_size);
    }
    return LuaCEmbed_send_str(DtwPath_get_path(self_part->path));
}

LuaCEmbedResponse * tree_part_set_value(LuaCEmbedTable *self,LuaCEmbed *args){
    Writeble  *write_obj = create_writeble(args,0);
    if(write_obj->error){
        LuaCEmbedResponse *response =  write_obj->error;
        Writeble_free(write_obj);
        return  response;
    }
    DtwTreePart *self_part  = (DtwTreePart*)LuaCembedTable_get_long_prop(self,TREE_PART_POINTER);
    DtwTreePart_set_any_content(self_part,write_obj->content,write_obj->size,write_obj->is_binary);
    Writeble_free(write_obj);
    return LuaCEmbed_send_table(self);
}


LuaCEmbedResponse * tree_part_hardware_remove(LuaCEmbedTable *self,LuaCEmbed *args){
    bool set_as_action = true;
    if(LuaCEmbed_get_arg_type(args,0) != LUA_CEMBED_NIL){
        set_as_action = LuaCEmbed_get_bool_arg(args,0);
    }

    if(LuaCEmbed_has_errors(args)){
        const char *error_menssage = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_menssage);
    }

    DtwTreePart *self_part  = (DtwTreePart*)LuaCembedTable_get_long_prop(self,TREE_PART_POINTER);
    DtwTreePart_hardware_remove(self_part,set_as_action);
    return LuaCEmbed_send_table(self);
}

LuaCEmbedResponse * tree_part_hardware_write(LuaCEmbedTable *self,LuaCEmbed *args){

    bool set_as_action = true;
    if(LuaCEmbed_get_arg_type(args,0) != LUA_CEMBED_NIL){
        set_as_action = LuaCEmbed_get_bool_arg(args,0);
    }

    if(LuaCEmbed_has_errors(args)){
        const char *error_menssage = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_menssage);
    }


    DtwTreePart *self_part  = (DtwTreePart*)LuaCembedTable_get_long_prop(self,TREE_PART_POINTER);
    DtwTreePart_hardware_write(self_part,set_as_action);
    return LuaCEmbed_send_table(self);
}

LuaCEmbedResponse * tree_part_hardware_modify(LuaCEmbedTable *self,LuaCEmbed *args){

    bool set_as_action = true;
    if(LuaCEmbed_get_arg_type(args,0) != LUA_CEMBED_NIL){
        set_as_action = LuaCEmbed_get_bool_arg(args,0);
    }

    if(LuaCEmbed_has_errors(args)){
        const char *error_menssage = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_menssage);
    }

    DtwTreePart *self_part  = (DtwTreePart*)LuaCembedTable_get_long_prop(self,TREE_PART_POINTER);
    DtwTreePart_hardware_modify(self_part,set_as_action);
    return LuaCEmbed_send_table(self);
}

LuaCEmbedResponse * tree_part_get_content_sha(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwTreePart *self_part  = (DtwTreePart*)LuaCembedTable_get_long_prop(self,TREE_PART_POINTER);
    if(self_part->current_sha){
        return LuaCEmbed_send_str(self_part->current_sha);
    }
    return NULL;
}


LuaCEmbedResponse * tree_part_unload_content(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwTreePart *self_part  = (DtwTreePart*)LuaCembedTable_get_long_prop(self,TREE_PART_POINTER);
    DtwTreePart_free_content(self_part);
    return LuaCEmbed_send_table(self);
}

LuaCEmbedResponse * tree_part_load_content(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwTreePart *self_part  = (DtwTreePart*)LuaCembedTable_get_long_prop(self,TREE_PART_POINTER);
    DtwTreePart_load_content_from_hardware(self_part);
    return LuaCEmbed_send_table(self);
}

LuaCEmbedResponse *tree_part_is_blob(LuaCEmbedTable *self, LuaCEmbed *args){
    DtwTreePart *self_part  = (DtwTreePart*)LuaCembedTable_get_long_prop(self,TREE_PART_POINTER);
    return  LuaCEmbed_send_bool(self_part->is_binary);
}

LuaCEmbedTable * create_tree_part_reference(LuaCEmbed *args,DtwTreePart *part){
    LuaCEmbedTable *self = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_set_long_prop(self,TREE_PART_POINTER,(long long)part);
    LuaCEmbedTable_set_long_prop(self,DTW_TYPE,DTW_TREE_PART_TYPE);
    LuaCEmbedTable *path = create_path_reference(args,part->path);
    LuaCEmbedTable_set_sub_table_prop(self,PATH_PROPS,path);
    LuaCEmbedTable_set_method(self,GET_VALUE_METHOD,tree_part_get_value);
    LuaCEmbedTable_set_method(self,SET_VALUE_METHOD,tree_part_set_value);
    LuaCEmbedTable_set_method(self,HARDWARE_REMOVE_METHOD,tree_part_hardware_remove);
    LuaCEmbedTable_set_method(self,HARDWARE_MODIFY_METHOD,tree_part_hardware_modify);
    LuaCEmbedTable_set_method(self,HARWARE_WRITE_METHOD,tree_part_hardware_write);
    LuaCEmbedTable_set_method(self,GET_SHA_METHOD,tree_part_get_content_sha);
    LuaCEmbedTable_set_method(self,UNLOAD_METHOD,tree_part_unload_content);
    LuaCEmbedTable_set_method(self,TO_STRING_METHOD,tree_part_to_string);
    LuaCEmbedTable_set_method(self,IS_BLOB_FUNC,tree_part_is_blob);
    LuaCEmbedTable_set_method(self,LOAD_METHOD,tree_part_load_content);
    LuaCEmbedTable_set_method(self,TREE_PART_CONTENT_EXIST,tree_part_exis);
    LuaCEmbedTable_set_method(self,TREE_PART_CONTENT_EXIST_IN_HARDWARE,tree_part_exist_in_hardware);
    return self;
}



