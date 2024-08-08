

LuaCEmbedResponse  * load_file(LuaCEmbed *args){
    char *filename = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }

    long  size;
    unsigned  char *content = dtw_load_binary_content(filename,&size);
    if(content == NULL) {
        return  NULL;
    }

    LuaCEmbedResponse  *response  = LuaCEmbed_send_raw_string((char*)content,size);
    free(content);
    return  response;
}

LuaCEmbedResponse  * write_file(LuaCEmbed *args){
    char *filename = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }
    bool writed = false;
    long total_args = LuaCEmbed_get_total_args(args);
    if(total_args == 0){
        writed  = dtw_write_string_file_content(filename,"");
        return LuaCEmbed_send_bool(writed);
    }
    Writeble  *write_obj = create_writeble(args,1);
    if(write_obj->error){
        LuaCEmbedResponse *response =  write_obj->error;
        Writeble_free(write_obj);
        return  response;
    }
    writed = dtw_write_any_content(filename,write_obj->content,write_obj->size);
    Writeble_free(write_obj);
    return  LuaCEmbed_send_bool(writed);


}
LuaCEmbedResponse  * is_dir(LuaCEmbed *args){
    char *source = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }
    int type = dtw_entity_type(source);
    return LuaCEmbed_send_bool(type == DTW_FOLDER_TYPE);
}

LuaCEmbedResponse  * exist(LuaCEmbed *args){
    char *source = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }
    int type = dtw_entity_type(source);
    return LuaCEmbed_send_bool(type != DTW_NOT_FOUND);
}

LuaCEmbedResponse  * is_blob(LuaCEmbed *args){

    Writeble  *write_obj = create_writeble(args,1);
    if(write_obj->error){
        LuaCEmbedResponse *response =  write_obj->error;
        Writeble_free(write_obj);
        return  response;
    }
    bool is_binary = write_obj->is_binary;
    Writeble_free(write_obj);
    return LuaCEmbed_send_bool(is_binary);

}

LuaCEmbedResponse  * is_file(LuaCEmbed *args){
    char *source = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }
    int type = dtw_entity_type(source);
    return LuaCEmbed_send_bool(type == DTW_FILE_TYPE);
}

LuaCEmbedResponse  * is_blob_file(LuaCEmbed *args){
    char *source = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }
    int type = dtw_complex_entity_type(source);
    return LuaCEmbed_send_bool(type == DTW_COMPLEX_BINARY);
}




LuaCEmbedResponse  * copy_any_overwriting(LuaCEmbed *args){
    char *source = LuaCEmbed_get_str_arg(args,0);
    char *dest = LuaCEmbed_get_str_arg(args,1);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }

    bool writed = dtw_copy_any(source,dest,DTW_NOT_MERGE);
    return LuaCEmbed_send_bool(writed);
}


LuaCEmbedResponse  * copy_any_merging(LuaCEmbed *args){
    char *source = LuaCEmbed_get_str_arg(args,0);
    char *dest = LuaCEmbed_get_str_arg(args,1);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }
    bool writed = dtw_copy_any(source,dest,DTW_MERGE);
    return LuaCEmbed_send_bool(writed);
}

LuaCEmbedResponse  * move_any_overwriting(LuaCEmbed *args){
    char *source = LuaCEmbed_get_str_arg(args,0);
    char *dest = LuaCEmbed_get_str_arg(args,1);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }
    bool writed = dtw_move_any(source,dest,DTW_NOT_MERGE);
    return LuaCEmbed_send_bool(writed);
}
LuaCEmbedResponse  * move_any_merging(LuaCEmbed *args){
    char *source = LuaCEmbed_get_str_arg(args,0);
    char *dest = LuaCEmbed_get_str_arg(args,1);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }
    bool writed = dtw_move_any(source,dest,DTW_MERGE);
    return LuaCEmbed_send_bool(writed);
}


LuaCEmbedResponse  * remove_any(LuaCEmbed *args){
    char *source = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }
    bool writed = dtw_remove_any(source);
    return LuaCEmbed_send_bool(writed);
}


