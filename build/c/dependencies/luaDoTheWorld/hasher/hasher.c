
LuaCEmbedResponse * hasher_digest_file(LuaCEmbedTable *self,LuaCEmbed *args){
    char *filename = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }

    DtwHash *hash = (DtwHash*)LuaCembedTable_get_long_prop(self,HASH_POINTER);
    if(!DtwHash_digest_file(hash,filename)){
        char *file_not_found = private_LuaCembed_format(FILE_NOT_FOUND,filename);
        LuaCEmbedResponse *response = LuaCEmbed_send_error(file_not_found);
        free(file_not_found);
        return response;
    }
    return NULL;
}

LuaCEmbedResponse * hasher_digest_folder_by_content(LuaCEmbedTable *self, LuaCEmbed *args){
    char *folder = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }

    DtwHash *hash = (DtwHash*)LuaCembedTable_get_long_prop(self,HASH_POINTER);
    if(!DtwHash_digest_folder_by_content(hash,folder)){
        char *folder_not_found = private_LuaCembed_format(FOLDER_NOT_FOUND,folder);
        LuaCEmbedResponse *response = LuaCEmbed_send_error(folder_not_found);
        free(folder_not_found);
        return response;
    }
    return NULL;
}

LuaCEmbedResponse * hasher_digest_folder_by_last_modification(LuaCEmbedTable *self, LuaCEmbed *args){
    char *folder = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }


    DtwHash *hash = (DtwHash*)LuaCembedTable_get_long_prop(self,HASH_POINTER);
    if(!DtwHash_digest_folder_by_last_modification(hash,folder)){
        char *folder_not_found = private_LuaCembed_format(FOLDER_NOT_FOUND,folder);
        LuaCEmbedResponse *response = LuaCEmbed_send_error(folder_not_found);
        free(folder_not_found);
        return response;
    }
    return NULL;
}



LuaCEmbedResponse * delete_hasher(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwHash *hash = (DtwHash*)LuaCembedTable_get_long_prop(self,HASH_POINTER);
    DtwHash_free(hash);
    return NULL;
}

LuaCEmbedResponse * hasher_digest(LuaCEmbedTable *self,LuaCEmbed *args){
    Writeble write_obj = create_writeble(args,0);
    if(write_obj.error){
        return write_obj.error;
    }
    DtwHash *hash = (DtwHash*)LuaCembedTable_get_long_prop(self,HASH_POINTER);
    DtwHash_digest_any(hash,write_obj.content,write_obj.size);
    Writeble_free(&write_obj);
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
    LuaCEmbedTable_set_method(self, DIGESST_METHOD, hasher_digest);
    LuaCEmbedTable_set_method(self, TO_STRING_METHOD, hasher_get_value);
    LuaCEmbedTable_set_method(self, GET_VALUE_METHOD, hasher_get_value);
    LuaCEmbedTable_set_method(self, DIGESST_FILE_METHOD, hasher_digest_file);
    LuaCEmbedTable_set_method(self, DIGESST_FOLDER_BY_CONTENT_METHOD, hasher_digest_folder_by_content);
    LuaCEmbedTable_set_method(self, DIGESST_FOLDER_BY_LAST_MODIFICATION_METHOD, hasher_digest_folder_by_last_modification);
    LuaCEmbedTable_set_method(self, DELETE_METHOD, delete_hasher);
    return LuaCEmbed_send_table(self);
}
