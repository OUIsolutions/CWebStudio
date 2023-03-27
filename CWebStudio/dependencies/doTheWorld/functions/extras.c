
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
        #ifdef _WIN32
            if(!dtw_ends_with(dirs->strings[i], "\\")){
                char *formated_dir =  (char*)malloc(strlen(dirs->strings[i]) + 3); 
                sprintf(formated_dir,"%s\\\0",dirs->strings[i]);
                dirs->set_value(dirs,i,formated_dir);
                free(formated_dir);
            }
        #else
            if(!dtw_ends_with(dirs->strings[i], "/")){
                char *formated_dir =  (char*)malloc(strlen(dirs->strings[i]) + 3);
                sprintf(formated_dir,"%s/",dirs->strings[i]);
                dirs->set_value(dirs,i,formated_dir);
                free(formated_dir);
            }
        #endif
       
            
              
    }
}

char *dtw_concat_path(const char *path1, const char *path2){
    char *path = (char *)malloc(strlen(path1) + strlen(path2) + 3);
    #ifdef _WIN32
        if(dtw_ends_with(path1, "\\")){
            sprintf(path,"%s%s",path1,path2);

        }
        else{
            sprintf(path,"%s\\%s",path1,path2);

        }
    #else 
        if(dtw_ends_with(path1, "/")){
            sprintf(path,"%s%s",path1,path2);

        }
        else{
            sprintf(path,"%s/%s",path1,path2);
      
        }
    #endif 

    return path;
}