

LuaCEmbedResponse  * generate_sha_from_file(LuaCEmbed *args){
    char *source = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }

    char *sha = dtw_generate_sha_from_file(source);
    if(!sha){
        char *formmated  = private_LuaCembed_format(FILE_NOT_FOUND,source);
        LuaCEmbedResponse  *response = LuaCEmbed_send_error(formmated);
        free(formmated);
        return response;
    }
    LuaCEmbedResponse *response = LuaCEmbed_send_str(sha);
    free(sha);
    return response;
}
LuaCEmbedResponse  * generate_sha_from_folder_by_content(LuaCEmbed *args){
    char *source = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }

    DtwHash *hash = newDtwHash();
    bool result = DtwHash_digest_folder_by_content(hash,source);
    if(!result){
        char *content = private_LuaCembed_format(FILE_NOT_FOUND,source);
        LuaCEmbedResponse*response = LuaCEmbed_send_error(content);
        free(content);
        DtwHash_free(hash);
        return response;
    }
    LuaCEmbedResponse *response = LuaCEmbed_send_str(hash->hash);
    DtwHash_free(hash);
    return response;
}

LuaCEmbedResponse  * generate_sha_from_folder_by_last_modification(LuaCEmbed *args){
    char *source = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }

    DtwHash *hash = newDtwHash();
    bool result = DtwHash_digest_folder_by_last_modification(hash,source);
    if(!result){
        char *content = private_LuaCembed_format(FILE_NOT_FOUND,source);
        LuaCEmbedResponse*response = LuaCEmbed_send_error(content);
        free(content);
        DtwHash_free(hash);
        return response;
    }
    LuaCEmbedResponse *response = LuaCEmbed_send_str(hash->hash);
    DtwHash_free(hash);
    return response;
}

LuaCEmbedResponse  * generate_sha(LuaCEmbed *args){
    Writeble write_obj = create_writeble(args,0);
    if(write_obj.error){
        return write_obj.error;
    }
    char  *sha = dtw_generate_sha_from_any(write_obj.content,write_obj.size);
    Writeble_free(&write_obj);
    LuaCEmbedResponse *response = LuaCEmbed_send_str(sha);
    free(sha);
    return response;
}

