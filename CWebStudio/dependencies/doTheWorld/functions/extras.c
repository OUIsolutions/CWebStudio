
char * dtw_generate_sha_from_file(const char *path){
    return calc_sha_256_from_file_returning_string(path);
}


char * dtw_generate_sha_from_string(const char *string){
    return calc_sha_256_from_string_returning_string(string);
}


long int dtw_get_file_last_motification_in_unix(const char *path){
    struct stat attr;
    stat(path, &attr);
    // convert to unix time
    time_t last_modification_in_unix = attr.st_mtime;
    return last_modification_in_unix;
}

char * dtw_convert_unix_time_to_string(long int unix_time){
    struct tm * timeinfo;
    #ifdef _WIN32
        //get timeinfo from windows
        time_t rawtime = unix_time;
        timeinfo = localtime(&rawtime);
    #else
        timeinfo = localtime(&unix_time);
    #endif
    char *time_string = (char *)malloc(100);
    strftime(time_string, 100, "%Y-%m-%d %H:%M:%S", timeinfo);
    return time_string;
}

char * dtw_get_file_last_motification_in_string(const char *path){
    long int last_modification_in_unix = dtw_get_file_last_motification_in_unix(path);
    char *last_modification_in_string = dtw_convert_unix_time_to_string(last_modification_in_unix);
    return last_modification_in_string;
}

const char * private_dtw_convert_action_to_string(short action){
    switch (action){
        case DTW_REMOVE:
            return "remove";
        case DTW_WRITE:
            return "write";
        case DTW_MODIFY:
            return "modify";
    }
    return NULL;
}

short private_dtw_convert_string_to_action(const char *action){
    if(strcmp(action,"remove") == 0){
        return DTW_REMOVE;
    }
    if(strcmp(action,"write") == 0){
        return DTW_WRITE;
    }
    if(strcmp(action,"modify") == 0){
        return DTW_MODIFY;
    }
    return -1;
}

void private_dtw_add_end_bar_to_dirs_string_array(struct DtwStringArray * dirs){
    for(int i = 0; i < dirs->size; i++){
  
        if(!dtw_ends_with(dirs->strings[i], "/") || !dtw_ends_with(dirs->strings[i],"\\")){
            char *formated_dir =  (char*)malloc(strlen(dirs->strings[i]) + 3);
            sprintf(formated_dir,"%s/",dirs->strings[i]);
            dirs->set_value(dirs,i,formated_dir);
            free(formated_dir);
        }    
            
         
    }
}

char *dtw_concat_path(const char *path1, const char *path2){
    char *path = (char *)malloc(strlen(path1) + strlen(path2) + 3);

        if(dtw_ends_with(path1, "/") || dtw_ends_with(path1, "\\")){
            sprintf(path,"%s%s",path1,path2);

        }
        else{
            sprintf(path,"%s/%s",path1,path2);
      
        }
    return path;
}

struct DtwStringArray* private_dtw_remove_start_path(struct DtwStringArray *paths,const char *path_to_remove){
    int size_to_remove = strlen(path_to_remove);
    
    if(dtw_ends_with(path_to_remove,"/")){
        size_to_remove+=1;
    }

    struct DtwStringArray *new_array = dtw_constructor_string_array();

    for(int i =0; i < paths->size; i++){

        char *current_path_string = paths->strings[i];
        int current_path_string_size = strlen(current_path_string);

        char *new_string = (char*)malloc(current_path_string_size +2);
        new_string[current_path_string_size] =0;

        strcpy(new_string,current_path_string);
        memmove(
                new_string,
                current_path_string+size_to_remove,
                strlen(current_path_string) - size_to_remove +1
        );
        if(strcmp(new_string,"/") == 0){
            free(new_string);
            continue;
        }
        new_array->add_string(new_array,new_string);
        free(new_string);

    }
    return new_array;
}

void private_dtw_remove_double_bars(struct DtwStringArray*path){
    for(int i =0;i< path->size;i++){
        char *current_string = path->strings[i];
        int current_string_len = strlen(current_string);
        if(current_string_len <2){
            continue;
        }

        char last_char = current_string[current_string_len-1];
        char last_last_char = current_string[current_string_len-2];
        if(last_char == '/' && last_last_char =='/'){
            current_string[current_string_len-1] ='\0';
        }
    }
}