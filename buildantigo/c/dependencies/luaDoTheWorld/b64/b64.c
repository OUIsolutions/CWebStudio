
LuaCEmbedResponse  * base64_encode_file(LuaCEmbed *args){
    char *source = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }
    char * b64_string =  dtw_convert_binary_file_to_base64(source);
    if(!b64_string){
        char *formated  = private_LuaCembed_format(FILE_NOT_FOUND, source);
        LuaCEmbedResponse  *response = LuaCEmbed_send_error(formated);
        free(formated);
        return response;
    }

    LuaCEmbedResponse  *response = LuaCEmbed_send_str(b64_string);
    free(b64_string);
    return response;
}


LuaCEmbedResponse  * base64_decode(LuaCEmbed *args){

    char *source = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }
    long size;
    unsigned char *content = dtw_base64_decode(source,&size);
    content[size] = '\0';
    LuaCEmbedResponse* response =  LuaCEmbed_send_raw_string((char*)content,size);
    free(content);
    return response;

}

LuaCEmbedResponse  * base64_encode(LuaCEmbed *args){
    Writeble write_obj = create_writeble(args,0);
    if(write_obj.error){
        return write_obj.error;
    }

    char *created = dtw_base64_encode(write_obj.content,write_obj.size);
    Writeble_free(&write_obj);
    LuaCEmbedResponse *response = LuaCEmbed_send_str(created);
    free(created);
    return response;
}

