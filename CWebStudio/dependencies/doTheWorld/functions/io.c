
#ifdef __linux__
#define dtw_create_dir(path) mkdir(path,0777)
#elif _WIN32
#define dtw_create_dir(path) _mkdir(path)
#endif



void dtw_create_dir_recursively(const char *path){
    bool check = dtw_create_dir(path);
  
    int size_path = strlen(path);
    for(int i=0;i <  size_path;i++){
        if(path[i] == '\\'  || path[i] == '/'   && i != size_path - 1){
            
            char * current_path = (char*)malloc(i + 1);
            current_path[i] = '\0';
            strncpy(current_path,path,i);
          
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



void dtw_remove_any(const char* path) {
    //means is an file
    if(remove(path) == 0){
        return;
    }
    
    struct DtwStringArray *files = dtw_list_files_recursively(path,DTW_CONCAT_PATH);
    int size = files->size;
    for(int i = 0; i < size; i++){
        remove(files->strings[i]);
    }
    files->free_string_array(files);


    struct DtwStringArray *dirs = dtw_list_dirs_recursively(path,DTW_CONCAT_PATH);
    size = dirs->size;
    for(int i = dirs->size -1; i >=0; i--){
        rmdir(dirs->strings[i]);
    }
    dirs->free_string_array(dirs);
    //remove / to the path 
    
    
   
 
}


unsigned char *dtw_load_any_content(const char * path,int *size,bool *is_binary){
    FILE *file = fopen(path,"rb");
    if(file == NULL){
        free(file);
        return NULL;
    }
    fseek(file,0,SEEK_END);
    *size = ftell(file);
    fseek(file,0,SEEK_SET);
    unsigned char *content = (unsigned char*)malloc(*size +1);
    fread(content,1,*size,file);

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
    FILE *file = fopen(path,"r");
    if(file == NULL){
        return NULL;
    }
    fseek(file,0,SEEK_END);
    int size = ftell(file);
    fseek(file,0,SEEK_SET);
    char *content = (char*)malloc(size +1);
    fread(content,1,size,file);
    content[size] = '\0';
    fclose(file);
    return content;
}


unsigned char *dtw_load_binary_content(const char * path,int *size){
    FILE *file = fopen(path,"rb");
    if(file == NULL){
        return NULL;
    }
    fseek(file,0,SEEK_END);
    *size = ftell(file);
    fseek(file,0,SEEK_SET);
    unsigned char *content = (unsigned char*)malloc(*size);
    fread(content,1,*size,file);
    fclose(file);
    return content;
}


bool dtw_write_any_content(const char *path,unsigned  char *content,int size){
    //Iterate through the path and create directories if they don't exist
    
    for(int i = strlen(path)-1;i > 0;i--){
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

    FILE *file = fopen(path,"wb");
    if(file == NULL){
   
        return false;
    }
    
    fwrite(content, sizeof(char),size, file);
    
    fclose(file);
    return true;
}


bool dtw_write_string_file_content(const char *path,const char *content){
    int size;
    if(content == NULL){
        size = 0;
    }
    else{
        size = strlen(content);
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

bool dtw_copy_any(const char* src_path,const  char* dest_path,bool merge) {

    //verify if is an file
    int type = dtw_entity_type(src_path);
    if(type == DTW_NOT_FOUND){
        return false;
    }

    if(type == DTW_FILE_TYPE){
    
        int size;
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
    dirs->free_string_array(dirs);
    

    struct DtwStringArray *files = dtw_list_files_recursively(src_path,DTW_CONCAT_PATH);
   
    for(int i = 0; i < files->size; i++){
        int file_size;
        bool is_binary;
        unsigned char *content = dtw_load_any_content(files->strings[i],&file_size,&is_binary);
        char *new_path = private_dtw_change_beginning_of_string(files->strings[i],src_path_size,dest_path);

        dtw_write_any_content(new_path,content,file_size);
        free(content);
        free(new_path);

       
    }

    files->free_string_array(files);
    
    return true;
    
}

void dtw_move_any(const char* src_path, const char* dest_path,bool merge) {
    dtw_copy_any(src_path,dest_path,merge);
    dtw_remove_any(src_path);
}
