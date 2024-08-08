

char * DtwPath_get_name(struct DtwPath *self){

    long path_size = (long)strlen(self->path);
    long start = 0;
    long end = path_size;
    for(long i = path_size-1; i >=0; i--){
        char current_char = self->path[i];
        if(current_char == '/' || current_char == '\\'){
            start = i+1;
            break;
        }
        if(current_char == '.'){
            end = i;
        }
    }
    if(end - start == 0){
        return NULL;
    }

    char *buffer = private_dtw_sub_str(self->path,start,end);
    return privateDtwStringArray_append_if_not_included(self->garbage,buffer);

}
char * DtwPath_get_extension(struct DtwPath *self){
    long path_size = (long)strlen(self->path);
    long start = -1;
    long end = path_size;
    for(long i = path_size-1; i >=0; i--){
        char current_char = self->path[i];
        if(current_char == '.'){
            start = i+1;
            break;
        }
    }
    if(start == -1){
        return  NULL;
    }
    char *buffer = private_dtw_sub_str(self->path,start,end);
    return privateDtwStringArray_append_if_not_included(self->garbage,buffer);
}

char * DtwPath_get_full_name(struct DtwPath *self){
    long path_size = (long)strlen(self->path);
    long start = 0;
    long end = path_size;
    for(long i = path_size-1; i >=0; i--){
        char current_char = self->path[i];
        if(current_char == '/' || current_char == '\\'){
            start = i+1;
            break;
        }
    }
    if(end - start == 0){
        return NULL;
    }
    char *buffer = private_dtw_sub_str(self->path,start,end);
    return privateDtwStringArray_append_if_not_included(self->garbage,buffer);
}

char * DtwPath_get_dir(struct DtwPath *self){
    long path_size = (long)strlen(self->path);
    long start = 0;
    long end = -1;
    for(long i = path_size-1; i >=0; i--){
        char current_char = self->path[i];
        if(current_char == '/' || current_char == '\\'){
            end = i+1;
            break;
        }
    }
    if(end == -1){
        return NULL;
    }

    char *buffer = private_dtw_sub_str(self->path,start,end);
    return privateDtwStringArray_append_if_not_included(self->garbage,buffer);
}

char * DtwPath_get_path(struct DtwPath *self){
    return self->path;
}


