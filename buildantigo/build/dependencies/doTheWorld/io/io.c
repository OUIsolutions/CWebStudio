
#ifdef __linux__
#define dtw_create_dir(path) mkdir(path,0777)
#elif _WIN32
#define dtw_create_dir(path) _mkdir(path)
#endif



void dtw_create_dir_recursively(const char *path){

    int entity =dtw_entity_type(path);

    if(entity == DTW_FOLDER_TYPE){
        return;
    }

    if(entity == DTW_FILE_TYPE){
        remove(path);
    }


    long size_path = strlen(path);
    for(int i=0;i <  size_path;i++){
        if((path[i] == '\\'  || path[i] == '/' )  &&( i != size_path - 1)){
            
            char * current_path = (char*)malloc(i + 1);
            current_path[i] = '\0';
            strncpy(current_path,path,i);

            if(dtw_entity_type(current_path) == DTW_FILE_TYPE){
                remove(current_path);
            }

            dtw_create_dir(current_path);

            free(current_path);
        }
    }

    dtw_create_dir(path);
}

char *dtw_get_current_dir(){
    char *path = (char*)malloc(1024);
    getcwd(path,1024);
    char*path_with_bar = (char*)malloc(strlen(path) + 2);
    sprintf(path_with_bar,"%s/",path);
    free(path);
    return path_with_bar;
}



bool dtw_remove_any(const char* path) {
    //means is an file
    if(remove(path) == 0){
        return true;
    }
    
    struct DtwStringArray *files = dtw_list_files_recursively(path,DTW_CONCAT_PATH);
    int files_size = files->size;
    for(int i = 0; i < files_size; i++){
        remove(files->strings[i]);
    }
    DtwStringArray_free(files);


    struct DtwStringArray *dirs = dtw_list_dirs_recursively(path,DTW_CONCAT_PATH);
    int dirs_size = dirs->size;
    for(int i = dirs->size -1; i >=0; i--){
        rmdir(dirs->strings[i]);
    }
    DtwStringArray_free(dirs);
    //remove / to the path 
    if(files_size ||dirs_size){
        return true;
    }    
    return false;
    
 
}



unsigned char *dtw_load_any_content(const char * path,long *size,bool *is_binary){

    *is_binary = false;
    *size = 0;

    int entity = dtw_entity_type(path);
    if(entity != DTW_FILE_TYPE){
        return NULL;
    }
    FILE  *file = fopen(path,"rb");

    if(!file){
        return NULL;
    }


    if(fseek(file,0,SEEK_END) == -1){
        fclose(file);
        return NULL;
    }


    *size = ftell(file);

    if(*size == -1){
        fclose(file);
        return NULL;
    }

    if(*size == 0){
        fclose(file);
        return NULL;
    }


    if(fseek(file,0,SEEK_SET) == -1){
        fclose(file);
        return NULL;
    }

    unsigned char *content = (unsigned char*)malloc(*size +1);
    int bytes_read = fread(content,1,*size,file);
    if(bytes_read <=0 ){
        free(content);
        fclose(file);
        return NULL;
    }


    *is_binary = false;
    for(int i = 0;i < *size;i++){
        if(content[i] == 0){
            *is_binary = true;
            break;
        }
    }
    if(!*is_binary){
        content[*size] = '\0';
    }

    fclose(file);
    return content;
}


char *dtw_load_string_file_content(const char * path){
    long size;
    bool is_binary;
    unsigned char *element = dtw_load_any_content(path,&size,&is_binary);
    if(!element){

        if(dtw_entity_type(path) == DTW_FILE_TYPE){
            return strdup("");
        }
        return NULL;
    }

    if(is_binary){
        free(element);
        return NULL;
    }
    return (char*)element;
}


unsigned char *dtw_load_binary_content(const char * path,long *size){
    bool is_binary;
    return dtw_load_any_content(path,size,&is_binary);
}


bool dtw_write_any_content(const char *path,unsigned  char *content,long size){
    //Iterate through the path and create directories if they don't exist
    int entity_type =dtw_entity_type(path);
    if(entity_type == DTW_FOLDER_TYPE){
        dtw_remove_any(path);
    }


    if(entity_type == DTW_NOT_FOUND){
        long path_size = (long)strlen(path);
        for(long i = path_size-1;i > 0;i--){
            //runs in negative mode til / or \ is found
            if(path[i] == '\\' || path[i] == '/'){
                char *dir_path =(char*)malloc(i +2);
                dir_path[i] = '\0';
                strncpy(dir_path,path,i);

                dtw_create_dir_recursively(dir_path);
                free(dir_path);

                break;
            }
        }
    }

    FILE *file = fopen(path,"wb");
    if(file == NULL){
   
        return false;
    }
    
    fwrite(content, sizeof(char),size, file);
    
    fclose(file);
    return true;
}


bool dtw_write_string_file_content(const char *path,const char *content){
    long size;
    if(content == NULL){
        size = 0;
    }
    else{
        size = (long)strlen(content);
    }
    return dtw_write_any_content(path,(unsigned char*)content,size);
}


int dtw_entity_type(const char *path){
    //returns 1 for file, 2 for directory, -1 for not found
    struct stat path_stat; 

    if(stat(path,&path_stat) == 0){
        if(S_ISREG(path_stat.st_mode)){
            return DTW_FILE_TYPE;
        }else if(S_ISDIR(path_stat.st_mode)){
            return DTW_FOLDER_TYPE;
        }
    }
    return DTW_NOT_FOUND;

}


int dtw_complex_entity_type(const char *path){
    int entity = dtw_entity_type(path);
    if(entity != DTW_FILE_TYPE){
        return entity;
    }
    long size;
    bool is_binary;
    char *data = (char*)dtw_load_any_content(path,&size,&is_binary);
    if(is_binary){
        free(data);
        return DTW_COMPLEX_BINARY;
    }

    if(
       strcmp(data,"t") == 0 ||
       strcmp(data,"f") == 0 ||
       strcmp(data,"true") == 0 ||
       strcmp(data,"false") == 0
       ){
        free(data);
        return DTW_COMPLEX_BOOL_TYPE;
    }

    
    double value;
    int result = sscanf(data,"%lf",&value);
    if(result == 0){
        free(data);
        return DTW_COMPLEX_STRING_TYPE;
    }
    for(int i = 0; i < size; i++){
        char current = data[i];
        if(current == '.'){
            free(data);
            return DTW_COMPLEX_DOUBLE_TYPE;
        }
    }
    free(data);
    return DTW_COMPLEX_LONG_TYPE;
}

long dtw_get_total_itens_of_dir(const char *path){

    #ifdef __linux__

        DIR *dir = opendir(path);
        if (dir == NULL) {
        return -1;
        }
        int i = 0;
        while ((readdir(dir)) != NULL){
            i++;
        }
        closedir(dir);
        return i -2;
    #else 
        WIN32_FIND_DATA findFileData;
            HANDLE hFind = FindFirstFile(path, &findFileData);

            if (hFind == INVALID_HANDLE_VALUE) {
                return -1;
            }

            int i = 0;
            do {
                if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                    i++;
                }
            } while (FindNextFile(hFind, &findFileData) != 0);

            FindClose(hFind);
            return i;
    
    #endif 
}

const char *dtw_convert_entity(int entity_type){
    if(entity_type == DTW_FILE_TYPE){
        return "file";
    }
    if(entity_type == DTW_FOLDER_TYPE){
        return "folder";
    }
    if(entity_type == DTW_NOT_FOUND){
        return "null";
    }
    if(entity_type == DTW_COMPLEX_BINARY){
        return "binary";
    }
    if(entity_type == DTW_COMPLEX_STRING_TYPE){
        return "string";
    }
    if(entity_type == DTW_COMPLEX_BOOL_TYPE){
        return "bool";
    }
    if(entity_type == DTW_COMPLEX_LONG_TYPE){
        return "long";
    }
    if(entity_type == DTW_COMPLEX_DOUBLE_TYPE){
        return "double";
    }
    return "invalid";
}   

bool dtw_copy_any(const char* src_path,const  char* dest_path,bool merge) {

    //verify if is an file
    int type = dtw_entity_type(src_path);
    if(type == DTW_NOT_FOUND){
        return false;
    }

    if(type == DTW_FILE_TYPE){
    
        long size;
        bool is_binary;
        unsigned char *content = dtw_load_any_content(src_path,&size,&is_binary);
        bool result =  dtw_write_any_content(dest_path,content,size);
        free(content);
        return result;
    }
    //means is an directory

    //remove the previous directory if merge is false
    if(!merge){
        dtw_remove_any(dest_path);
    }
    //creating dirs
    struct DtwStringArray *dirs = dtw_list_dirs_recursively(src_path,DTW_CONCAT_PATH);
    
    int size = dirs->size;
    int src_path_size = strlen(src_path);

    for(int i = 0; i < size; i++){        
        char *new_path_dir = private_dtw_change_beginning_of_string(dirs->strings[i],src_path_size,dest_path);
        dtw_create_dir_recursively(new_path_dir);
        free(new_path_dir);
    }
    DtwStringArray_free(dirs);


    struct DtwStringArray *files = dtw_list_files_recursively(src_path,DTW_CONCAT_PATH);
   
    for(int i = 0; i < files->size; i++){
        long file_size;
        bool is_binary;
        unsigned char *content = dtw_load_any_content(files->strings[i],&file_size,&is_binary);
        char *new_path = private_dtw_change_beginning_of_string(files->strings[i],src_path_size,dest_path);

        dtw_write_any_content(new_path,content,file_size);
        free(content);
        free(new_path);

       
    }

    DtwStringArray_free(files);
    
    return true;
    
}

bool dtw_move_any(const char* src_path, const char* dest_path,bool merge) {
    bool result = dtw_copy_any(src_path,dest_path,merge);
    dtw_remove_any(src_path);
    return result;
}
