
char * dtw_generate_sha_from_file(const char *path){
    return calc_sha_256_from_file_returning_string(path);
}

char * dtw_generate_sha_from_any(void *anything , long size){
    if(anything ==NULL) {
        return NULL;
    }
    return calc_sha_256_returning_string(anything,size);
}   

char * dtw_generate_sha_from_string(const char *string){
    if(string == NULL) {
        return  NULL;
    }
    return calc_sha_256_from_string_returning_string(string);
}


long int dtw_get_entity_last_motification_in_unix(const char *path){
    struct stat attr;
    if(stat(path, &attr) != 0) {
        return -1;
    }

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

char * dtw_get_entity_last_motification_in_string(const char *path){
    long int last_modification_in_unix = dtw_get_entity_last_motification_in_unix(path);
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
            DtwStringArray_set_value(dirs, i, formated_dir);
            free(formated_dir);
        }    
            
         
    }
}



struct DtwStringArray* private_dtw_remove_start_path(struct DtwStringArray *paths,const char *rm_path){

    char *path_to_remove = dtw_replace_string(rm_path,"//","/");

    int size_to_remove = strlen(path_to_remove) +1;

    if(dtw_ends_with(path_to_remove,"/")){
        size_to_remove-=1;
    }


    struct DtwStringArray *new_array = newDtwStringArray();

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
        if(strcmp(new_string,"/") == 0  || strcmp(new_string,"") == 0){
            free(new_string);
            continue;
        }

        DtwStringArray_append(new_array, new_string);
        free(new_string);

    }
    free(path_to_remove);
    return new_array;
}


long dtw_get_time(){
#ifdef DTW_DEBUG_TIME
    return 0;
#endif
    return time(NULL);
}
long private_dtw_convert_index(long index,long size){

    long converted_index = index;

    if(converted_index < 0){
        converted_index = size + converted_index;
    }

    if(converted_index >= size){
       return size -1;
    }
    if(converted_index < 0){
        return 0;
    }

    return converted_index;
}