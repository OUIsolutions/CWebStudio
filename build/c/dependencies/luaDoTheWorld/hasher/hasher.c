
LuaCEmbedResponse * hasher_digest_path(LuaCEmbedTable *self,LuaCEmbed *args){
    char *path = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }
    DtwHash *hash = (DtwHash*)LuaCembedTable_get_long_prop(self,HASH_POINTER);
    int type =dtw_entity_type(path);

    if(type== DTW_FILE_TYPE){
        DtwHash_digest_file(hash,path);
    }
    if(type == DTW_FOLDER_TYPE){
        DtwHash_digest_folder_by_content(hash,path);
    }

    return LuaCEmbed_send_str(hash->hash);
}

LuaCEmbedResponse * hasher_digest_file(LuaCEmbedTable *self,LuaCEmbed *args){
    char *filename = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }

    DtwHash *hash = (DtwHash*)LuaCembedTable_get_long_prop(self,HASH_POINTER);
    DtwHash_digest_file(hash,filename);
    return NULL;
}

LuaCEmbedResponse * hasher_digest_folder_by_content(LuaCEmbedTable *self, LuaCEmbed *args){
    char *folder = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }

    DtwHash *hash = (DtwHash*)LuaCembedTable_get_long_prop(self,HASH_POINTER);
    DtwHash_digest_folder_by_content(hash,folder);
    return NULL;
}

LuaCEmbedResponse * hasher_digest_folder_by_last_modification(LuaCEmbedTable *self, LuaCEmbed *args){
    char *folder = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }


    DtwHash *hash = (DtwHash*)LuaCembedTable_get_long_prop(self,HASH_POINTER);
    DtwHash_digest_folder_by_last_modification(hash,folder);
    return NULL;
}



LuaCEmbedResponse * delete_hasher(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwHash *hash = (DtwHash*)LuaCembedTable_get_long_prop(self,HASH_POINTER);
    DtwHash_free(hash);
    return NULL;
}

LuaCEmbedResponse * hasher_digest(LuaCEmbedTable *self,LuaCEmbed *args){
    Writeble  *write_obj = create_writeble(args,0);
    if(write_obj->error){
        LuaCEmbedResponse *response =  write_obj->error;
        Writeble_free(write_obj);
        return  response;
    }
    DtwHash *hash = (DtwHash*)LuaCembedTable_get_long_prop(self,HASH_POINTER);
    DtwHash_digest_any(hash,write_obj->content,write_obj->size);
    Writeble_free(write_obj);
    return NULL;
}

LuaCEmbedResponse * hasher_get_value(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwHash *hash = (DtwHash*)LuaCembedTable_get_long_prop(self,HASH_POINTER);
    return LuaCEmbed_send_str(hash->hash);
}


LuaCEmbedResponse * create_hasher(LuaCEmbed *args){
    LuaCEmbedTable * self = LuaCembed_new_anonymous_table(args);
    DtwHash *hash = newDtwHash();
    LuaCEmbedTable_set_long_prop(self,HASH_POINTER,(long long)hash);
    LuaCEmbedTable_set_method(self,DIGEST_PATH,hasher_digest_path);
    LuaCEmbedTable_set_method(self, DIGESST_METHOD, hasher_digest);
    LuaCEmbedTable_set_method(self, TO_STRING_METHOD, hasher_get_value);
    LuaCEmbedTable_set_method(self, GET_VALUE_METHOD, hasher_get_value);
    LuaCEmbedTable_set_method(self, DIGESST_FILE_METHOD, hasher_digest_file);
    LuaCEmbedTable_set_method(self, DIGESST_FOLDER_BY_CONTENT_METHOD, hasher_digest_folder_by_content);
    LuaCEmbedTable_set_method(self, DIGESST_FOLDER_BY_LAST_MODIFICATION_METHOD, hasher_digest_folder_by_last_modification);
    LuaCEmbedTable_set_method(self, DELETE_METHOD, delete_hasher);
    return LuaCEmbed_send_table(self);
}
