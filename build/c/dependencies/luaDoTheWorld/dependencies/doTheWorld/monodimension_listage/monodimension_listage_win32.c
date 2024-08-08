
#ifdef _WIN32


bool private_dtw_verify_if_add(const int expected_type, WIN32_FIND_DATAA entry){
    #define WIN32_FILETYPE 32

    if (expected_type == DTW_FILE_TYPE && entry.dwFileAttributes == WIN32_FILETYPE) {
        return true;
    }

    if (expected_type == DTW_FOLDER_TYPE && entry.dwFileAttributes != WIN32_FILETYPE){
        return true;
    }

    if (expected_type == DTW_ALL_TYPE) {
        return true;
    }
    
    return false;
}

bool private_dtw_verify_if_skip(WIN32_FIND_DATAA *entry){
    if (strcmp(entry->cFileName, ".") == 0 || strcmp(entry->cFileName, "..") == 0) {
        return true;
    }
    return false;
}

struct DtwStringArray *  dtw_list_basic(const char *path,int expected_type,bool concat_path){

    WIN32_FIND_DATAA file_data;
    HANDLE file_handle;
    char search_path[MAX_PATH];

    //array of directories
    struct DtwStringArray *dirs = newDtwStringArray();
    int i = 0;

    // build the search path string
    snprintf(search_path, MAX_PATH, "%s\\*", path);

    // try to open the directory
    if ((file_handle = FindFirstFileA(search_path, &file_data)) == INVALID_HANDLE_VALUE) {
        return dirs;
    }

    do {
        // skip "." and ".." directories
        if (private_dtw_verify_if_skip(&file_data)){
            continue;
        }

        // verify if it's a file or directory
        if (private_dtw_verify_if_add(expected_type, file_data)) {
            
            if(concat_path){
                // allocate memory for the directory
                if(path[strlen(path) - 1] == '\\' || path[strlen(path) - 1] == '/'){
                    char *generated_dir = (char*)malloc(strlen(path) + strlen(file_data.cFileName) + 1);
                    sprintf(generated_dir, "%s%s", path, file_data.cFileName);
                    DtwStringArray_append(dirs, generated_dir);
                    free(generated_dir);
                }
                else{
                    char *generated_dir = (char*)malloc(strlen(path) + strlen(file_data.cFileName) + 2);
                    

                    sprintf(generated_dir, "%s/%s", path, file_data.cFileName);
                   
                    DtwStringArray_append(dirs, generated_dir);
                    free(generated_dir);
                }
                
    
            }
            else{
                DtwStringArray_append(dirs, file_data.cFileName);
            
            }

            i++;
        }
    } while (FindNextFileA(file_handle, &file_data) != 0);

        if(expected_type == DTW_FOLDER_TYPE){
            private_dtw_add_end_bar_to_dirs_string_array(dirs);   
        }
    
    FindClose(file_handle);

    return dirs;
}
#endif