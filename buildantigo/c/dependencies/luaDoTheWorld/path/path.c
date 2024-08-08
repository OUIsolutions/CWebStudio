
LuaCEmbedResponse *path_changed(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwPath *self_path = (DtwPath*)LuaCembedTable_get_long_prop(self,PATH_POINTER);
    return LuaCEmbed_send_bool(DtwPath_changed(self_path));
}
LuaCEmbedResponse *path_unpack(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwPath *self_path = (DtwPath*)LuaCembedTable_get_long_prop(self,PATH_POINTER);
    int total_dirs = DtwPath_get_total_dirs(self_path);
    int size= total_dirs;
    LuaCEmbedTable *elements =LuaCembed_new_anonymous_table(args);
    for(int i =0;i <total_dirs;i++){
        char *current=DtwPath_get_sub_dirs_from_index(self_path,i,i);
        LuaCEmbedTable_append_string(elements,current);
    }
    char *full_name = DtwPath_get_full_name(self_path);
    if(full_name !=NULL){
        LuaCEmbedTable_append_string(elements,full_name);
        size+=1;
    }
    LuaCEmbedTable *final_response =LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_append_table(final_response,elements);
    LuaCEmbedTable_append_long(final_response,size);
    return LuaCEmbed_send_multi_return(final_response);




    return NULL;
}

LuaCEmbedResponse *path_add_start_dir(LuaCEmbedTable *self,LuaCEmbed *args){
    char *start_dir = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error);
    }
    DtwPath *self_path = (DtwPath*)LuaCembedTable_get_long_prop(self,PATH_POINTER);
    DtwPath_add_start_dir(self_path,start_dir);
    return LuaCEmbed_send_table(self);
}


LuaCEmbedResponse *path_add_end_dir(LuaCEmbedTable *self,LuaCEmbed *args){
    char *end_dir = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error);
    }
    DtwPath *self_path = (DtwPath*)LuaCembedTable_get_long_prop(self,PATH_POINTER);
    DtwPath_add_end_dir(self_path,end_dir);
    return LuaCEmbed_send_table(self);
}

LuaCEmbedResponse *path_get_dir(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwPath *self_path = (DtwPath*)LuaCembedTable_get_long_prop(self,PATH_POINTER);
    char *dir = DtwPath_get_dir(self_path);
    if(dir == NULL){
        return NULL;
    }
    return  LuaCEmbed_send_str_reference(dir);

}

LuaCEmbedResponse *path_get_extension(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwPath *self_path = (DtwPath*)LuaCembedTable_get_long_prop(self,PATH_POINTER);
    char *extension = DtwPath_get_extension(self_path);
    if(extension == NULL){
        return  NULL;
    }
    return  LuaCEmbed_send_str_reference(extension);
}

LuaCEmbedResponse *path_get_name(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwPath *self_path = (DtwPath*)LuaCembedTable_get_long_prop(self,PATH_POINTER);
    char * fullname = DtwPath_get_full_name(self_path);
    if(fullname== NULL){
        return  NULL;
    }
    return  LuaCEmbed_send_str_reference(fullname);
}

LuaCEmbedResponse *path_get_only_name(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwPath *self_path = (DtwPath*)LuaCembedTable_get_long_prop(self,PATH_POINTER);
    char *name = DtwPath_get_name(self_path);
    if(name == NULL){
        return NULL;
    }
    return  LuaCEmbed_send_str_reference(name);
}

LuaCEmbedResponse *path_get_full_path(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwPath *self_path = (DtwPath*)LuaCembedTable_get_long_prop(self,PATH_POINTER);
    return  LuaCEmbed_send_str_reference(DtwPath_get_path(self_path));
}

LuaCEmbedResponse *path_to_string(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwPath *self_path = (DtwPath*)LuaCembedTable_get_long_prop(self,PATH_POINTER);
    return  LuaCEmbed_send_str_reference(DtwPath_get_path(self_path));
}

LuaCEmbedResponse *path_set_name(LuaCEmbedTable *self,LuaCEmbed *args){
    char *new_full_name = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error);
    }
    DtwPath *self_path = (DtwPath*)LuaCembedTable_get_long_prop(self,PATH_POINTER);

    DtwPath_set_full_name(self_path,new_full_name);
    return LuaCEmbed_send_table(self);
}

LuaCEmbedResponse *path_set_only_name(LuaCEmbedTable *self,LuaCEmbed *args){
    char *new_name = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error);
    }
    DtwPath *self_path = (DtwPath*)LuaCembedTable_get_long_prop(self,PATH_POINTER);

    DtwPath_set_name(self_path,new_name);
    return LuaCEmbed_send_table(self);
}

LuaCEmbedResponse *path_set_extension(LuaCEmbedTable *self,LuaCEmbed *args){
    char *new_extension = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error);
    }
    DtwPath *self_path = (DtwPath*)LuaCembedTable_get_long_prop(self,PATH_POINTER);

    DtwPath_set_extension(self_path,new_extension);
    return LuaCEmbed_send_table(self);
}

LuaCEmbedResponse *path_set_dir(LuaCEmbedTable *self,LuaCEmbed *args){
    char *new_dir = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error);
    }
    DtwPath *self_path = (DtwPath*)LuaCembedTable_get_long_prop(self,PATH_POINTER);

    DtwPath_set_dir(self_path,new_dir);
    return LuaCEmbed_send_table(self);
}

LuaCEmbedResponse *path_set_path(LuaCEmbedTable *self,LuaCEmbed *args){
    char *new_path = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error);
    }
    DtwPath *self_path = (DtwPath*)LuaCembedTable_get_long_prop(self,PATH_POINTER);

    DtwPath_set_path(self_path,new_path);
    return LuaCEmbed_send_table(self);
}

LuaCEmbedResponse *path_replace_dirs(LuaCEmbedTable *self,LuaCEmbed *args){
    char *old_dir = LuaCEmbed_get_str_arg(args,0);
    char *new_dir = LuaCEmbed_get_str_arg(args,1);
    if(LuaCEmbed_has_errors(args)){
        char *error = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error);
    }
    DtwPath *self_path = (DtwPath*)LuaCembedTable_get_long_prop(self,PATH_POINTER);

    DtwPath_replace_dirs(self_path,old_dir,new_dir);
    return LuaCEmbed_send_table(self);
}

LuaCEmbedResponse *path_get_total_dirs(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwPath *self_path = (DtwPath*)LuaCembedTable_get_long_prop(self,PATH_POINTER);
    return  LuaCEmbed_send_long(DtwPath_get_total_dirs(self_path));
}

LuaCEmbedResponse *path_get_sub_dirs_from_index(LuaCEmbedTable *self,LuaCEmbed *args){
    long start_index = LuaCEmbed_get_long_arg(args,0);
    long end_index = LuaCEmbed_get_long_arg(args,1);
    if(LuaCEmbed_has_errors(args)){
        char *error = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error);
    }
    DtwPath *self_path = (DtwPath*)LuaCembedTable_get_long_prop(self,PATH_POINTER);
    char *sub_dirs = DtwPath_get_sub_dirs_from_index(self_path,start_index,end_index);
    if(sub_dirs == NULL){
        return NULL;
    }
    return LuaCEmbed_send_str_reference(sub_dirs);;
}

LuaCEmbedResponse *path_insert_dir_at_index(LuaCEmbedTable *self,LuaCEmbed *args){
    long index = LuaCEmbed_get_long_arg(args,0);
    char *dir = LuaCEmbed_get_str_arg(args,1);
    if(LuaCEmbed_has_errors(args)){
        char *error = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error);
    }
    DtwPath *self_path = (DtwPath*)LuaCembedTable_get_long_prop(self,PATH_POINTER);
    DtwPath_insert_dir_at_index(self_path,index,dir);
    return LuaCEmbed_send_table(self);
}

LuaCEmbedResponse *path_remove_sub_dir_at_index(LuaCEmbedTable *self,LuaCEmbed *args){
    long start = LuaCEmbed_get_long_arg(args,0);
    long end = LuaCEmbed_get_long_arg(args,1);
    if(LuaCEmbed_has_errors(args)){
        char *error = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error);
    }
    DtwPath *self_path = (DtwPath*)LuaCembedTable_get_long_prop(self,PATH_POINTER);
    DtwPath_remove_sub_dirs_at_index(self_path,start,end);
    return LuaCEmbed_send_table(self);
}

LuaCEmbedResponse *path_insert_dir_after(LuaCEmbedTable *self,LuaCEmbed *args){
    char *after_dir  = LuaCEmbed_get_str_arg(args,0);
    char *dir = LuaCEmbed_get_str_arg(args,1);

    if(LuaCEmbed_has_errors(args)){
        char *error = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error);
    }
    DtwPath *self_path = (DtwPath*)LuaCembedTable_get_long_prop(self,PATH_POINTER);
    DtwPath_insert_dir_after(self_path,after_dir,dir);
    return LuaCEmbed_send_table(self);
}

LuaCEmbedResponse *path_insert_dir_before(LuaCEmbedTable *self,LuaCEmbed *args){
    char *before_dir  = LuaCEmbed_get_str_arg(args,0);
    char *dir = LuaCEmbed_get_str_arg(args,1);

    if(LuaCEmbed_has_errors(args)){
        char *error = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error);
    }
    DtwPath *self_path = (DtwPath*)LuaCembedTable_get_long_prop(self,PATH_POINTER);
    DtwPath_insert_dir_before(self_path,before_dir,dir);
    return LuaCEmbed_send_table(self);
}

LuaCEmbedResponse *path_remove_sub_dirs_at(LuaCEmbedTable *self,LuaCEmbed *args){
    char *dirs_to_remove  = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error);
    }
    DtwPath *self_path = (DtwPath*)LuaCembedTable_get_long_prop(self,PATH_POINTER);
    DtwPath_remove_sub_dirs_at(self_path,dirs_to_remove);
    return LuaCEmbed_send_table(self);
}

LuaCEmbedResponse *path_delete(LuaCEmbedTable *self,LuaCEmbed *args){

    bool its_a_ref = LuaCembedTable_get_bool_prop(self,IS_A_REF);
    if(!its_a_ref){
        DtwPath *self_path = (DtwPath*)LuaCembedTable_get_long_prop(self,PATH_POINTER);
        DtwPath_free(self_path);
    }

    return NULL;
}

LuaCEmbedTable *raw_create_path(LuaCEmbed *args,DtwPath *path){
    LuaCEmbedTable *self = LuaCembed_new_anonymous_table(args);

    LuaCEmbedTable_set_long_prop(self,PATH_POINTER,(long long )path);
    LuaCEmbedTable_set_method(self,PATH_ADD_END_DIR_METHOD,path_add_end_dir);
    LuaCEmbedTable_set_method(self,PATH_CHANGED_METHOD,path_changed);
    LuaCEmbedTable_set_method(self,PATH_ADD_START_DIR_METHOD,path_add_start_dir);
    LuaCEmbedTable_set_method(self,GET_DIR_METHOD,path_get_dir);
    LuaCEmbedTable_set_method(self,GET_EXTENSION_METHOD,path_get_extension);
    LuaCEmbedTable_set_method(self,GET_NAME_METHOD,path_get_name);
    LuaCEmbedTable_set_method(self,GET_ONLY_NAME_METHOD,path_get_only_name);
    LuaCEmbedTable_set_method(self,TO_STRING_METHOD,path_to_string);
    LuaCEmbedTable_set_method(self,PATH_GET_FULL_PATH_METHOD,path_get_full_path);
    LuaCEmbedTable_set_method(self,SET_EXTENSION_METHOD,path_set_extension);
    LuaCEmbedTable_set_method(self,PATH_SET_ONLY_NAME_METHOD,path_set_only_name);
    LuaCEmbedTable_set_method(self,PATH_SET_NAME_METHOD,path_set_name);
    LuaCEmbedTable_set_method(self,PATH_SET_DIR_METHOD,path_set_dir);
    LuaCEmbedTable_set_method(self,PATH_SET_PATH_METHOD,path_set_path);

    LuaCEmbedTable_set_method(self,PATH_REPLACE_DIRS_METHOD,path_replace_dirs);
    LuaCEmbedTable_set_method(self,PATH_GET_TOTAL_DIRS_METHOD,path_get_total_dirs);
    LuaCEmbedTable_set_method(self,PATH_GET_SUB_DIRS_FROM_INDEX_METHOD,path_get_sub_dirs_from_index);
    LuaCEmbedTable_set_method(self,PATH_INSERT_DIR_AT_INDEX_METHOD,path_insert_dir_at_index);
    LuaCEmbedTable_set_method(self,PATH_REMOVE_SUB_DIR_AT_INDEX_METHOD,path_remove_sub_dir_at_index);
    LuaCEmbedTable_set_method(self,PATH_INSERT_DIR_AFTER_METHOD,path_insert_dir_after);
    LuaCEmbedTable_set_method(self,PATH_INSERT_DIR_BEFORE_METHOD,path_insert_dir_before);
    LuaCEmbedTable_set_method(self,PATH_REMOVE_SUB_DIRS_AT_METHOD,path_remove_sub_dirs_at);
    LuaCEmbedTable_set_method(self,PATH_UNPACK,path_unpack);
    LuaCEmbedTable_set_method(self,DELETE_METHOD,path_delete);

    return self;
}

LuaCEmbedTable *create_path_reference(LuaCEmbed *args,DtwPath *path){
    LuaCEmbedTable *self =  raw_create_path(args,path);
    LuaCEmbedTable_set_bool_prop(self,IS_A_REF,true);
    return self;
}


LuaCEmbedResponse *create_path(LuaCEmbed *args){
    char *content = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error);
    }
    DtwPath *path = newDtwPath(content);
    LuaCEmbedTable *self =  raw_create_path(args,path);
    LuaCEmbedTable_set_bool_prop(self,IS_A_REF,false);
    return LuaCEmbed_send_table(self);
}

