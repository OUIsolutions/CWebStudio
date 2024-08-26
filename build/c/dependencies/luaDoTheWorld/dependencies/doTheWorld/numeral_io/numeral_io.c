
long dtw_load_long_file_content_setting_error(const char *path,int *error){
    char *data = dtw_load_string_file_content(path);
    if(!data){
        *error = DTW_NOT_FOUND;
        return DTW_NOT_FOUND;
    }
    long value = -1;
    int result = sscanf(data,"%ld",&value);
    free(data);
    if(result){
        return value;
    }
    *error = DTW_NOT_NUMERICAL;
    return DTW_NOT_NUMERICAL;
}


long dtw_load_long_file_content(const char * path){
   int error;
   return dtw_load_long_file_content_setting_error(path,&error);
}


double dtw_load_double_file_content_setting_error(const char * path, int *error){
    char *data = dtw_load_string_file_content(path);
    if(!data){
        *error = DTW_NOT_FOUND;
        return DTW_NOT_FOUND;
    }
    double value = -1;
    int result = sscanf(data,"%lf",&value);
    free(data);
    if(result){
    
        return value;
    }
    *error = DTW_NOT_NUMERICAL;
    return DTW_NOT_NUMERICAL;
}


double dtw_load_double_file_content(const char * path){
    int error;
    return dtw_load_double_file_content_setting_error(path,&error);
}


bool dtw_load_bool_file_content_setting_error(const char * path, int *error){
    char *data = dtw_load_string_file_content(path);
    if(!data){
        *error = DTW_NOT_FOUND;
        return false;
    }

    if(strcmp(data,"true") == 0 || strcmp(data,"t") == 0){
        free(data);
        return true;
    }

    if(strcmp(data,"false") == 0 || strcmp(data,"f") == 0){
        free(data);
        return false;
    }
    free(data);
    *error = DTW_NOT_BOOL;
    return false;

}


bool dtw_load_bool_file_content(const char * path){
    int error;
    return dtw_load_bool_file_content_setting_error(path,&error);
    
}



void dtw_write_long_file_content(const char *path, long value){
    char result[30] ={0};
    sprintf(result,"%ld",value);
    dtw_write_string_file_content(path,result);
}


void dtw_write_double_file_content(const char *path,double value){
    char result[30] ={0};
    sprintf(result,"%lf",value);
    dtw_write_string_file_content(path,result);
}


void dtw_write_bool_file_content(const char *path, bool value){
    if(value){
        dtw_write_string_file_content(path,"t");
    }
    else{
        dtw_write_string_file_content(path,"f");
    }
}


