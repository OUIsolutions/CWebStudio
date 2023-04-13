
struct DtwStringArray * dtw_list_dirs_recursively(const char *path,bool concat_path){

        struct  DtwStringArray *dirs  = dtw_constructor_string_array();
        //verify if the path is a directory
    
        int entity_type = dtw_entity_type(path);
        if(entity_type != DTW_FOLDER_TYPE){
                return dirs;
        }
      
        
        dirs->add_string(dirs,path);
        private_dtw_add_end_bar_to_dirs_string_array(dirs);
        int i = 0;
        //The size of dirs will increase til it reaches the end of the array
        while(i < dirs->size){                
                struct DtwStringArray *sub_dirs = dtw_list_basic(
                    dirs->strings[i],
                    DTW_FOLDER_TYPE,
                    true
                    );
                //merge the two dirs
                dirs->merge_string_array(dirs,sub_dirs);
                sub_dirs->free_string_array(sub_dirs);
                i++;
               
        }
        //unsifth path in dirs 
        private_dtw_remove_double_bars(dirs);

        if(!concat_path){

            struct DtwStringArray *removed =  private_dtw_remove_start_path(dirs,path);
            dirs->free_string_array(dirs);
            return removed;
        }
        return dirs;
}



struct DtwStringArray *  dtw_list_files_recursively(const char *path,bool concat_path){
    
    struct DtwStringArray *dirs = dtw_list_dirs_recursively(path,DTW_CONCAT_PATH);
    
    struct  DtwStringArray *files = dtw_constructor_string_array();
    
    for(int i = 0; i < dirs->size; i++){
        struct DtwStringArray *sub_files = dtw_list_basic(dirs->strings[i],DTW_FILE_TYPE,DTW_CONCAT_PATH);
        files->merge_string_array(files,sub_files);
        sub_files->free_string_array(sub_files);
    }
    dirs->free_string_array(dirs);

    if(!concat_path){

        struct DtwStringArray *removed =  private_dtw_remove_start_path(files,path);
        files->free_string_array(files);
        return removed;
    }

    return files;
}


struct DtwStringArray * dtw_list_all_recursively(const char *path,bool concat_path){

    struct DtwStringArray *dirs = dtw_list_dirs_recursively(path,DTW_CONCAT_PATH);
    
    struct DtwStringArray *all = dtw_constructor_string_array();
    
    for(int i = 0; i < dirs->size; i++){

        if(!dtw_ends_with(dirs->strings[i], "/") || !dtw_ends_with(dirs->strings[i], "\\") ){
            char *formated_dir =  (char*)malloc(strlen(dirs->strings[i]) + 2);
            sprintf(formated_dir,"%s/",dirs->strings[i]);
            all->add_string(all,formated_dir);
            free(formated_dir);
        }
        else{
            all->add_string(all,dirs->strings[i]);
        }


        struct DtwStringArray *sub_files = dtw_list_basic(dirs->strings[i],DTW_FILE_TYPE,true);
        all->merge_string_array(all,sub_files);
        sub_files->free_string_array(sub_files);
    }
    dirs->free_string_array(dirs);
    private_dtw_remove_double_bars(all);
    if(!concat_path){

        struct DtwStringArray *removed =  private_dtw_remove_start_path(all,path);
        all->free_string_array(all);
        return removed;
    }
    return all;
}