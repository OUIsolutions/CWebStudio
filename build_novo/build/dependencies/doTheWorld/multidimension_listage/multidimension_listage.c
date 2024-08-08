
 DtwStringArray * dtw_list_dirs_recursively(const char *path,bool concat_path){

        struct  DtwStringArray *dirs  = newDtwStringArray();
        //verify if the path is a directory
    
        int entity_type = dtw_entity_type(path);
        if(entity_type != DTW_FOLDER_TYPE){
                return dirs;
        }
      
        
        DtwStringArray_append(dirs, (char*)path);

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
            DtwStringArray_merge(dirs, sub_dirs);
                DtwStringArray_free(sub_dirs);
                i++;
               
        }
        //unsifth path in dirs 
     private_dtw_remove_double_bars_from_string_array(dirs);

        if(!concat_path){

            struct DtwStringArray *removed =  private_dtw_remove_start_path(dirs,path);
            DtwStringArray_free(dirs);
            return removed;
        }
        return dirs;
}



 DtwStringArray *  dtw_list_files_recursively(const char *path,bool concat_path){
    
    struct DtwStringArray *dirs = dtw_list_dirs_recursively(path,DTW_CONCAT_PATH);
    
    struct  DtwStringArray *files = newDtwStringArray();
    for(int i = 0; i < dirs->size; i++){
        struct DtwStringArray *sub_files = dtw_list_basic(dirs->strings[i],DTW_FILE_TYPE,DTW_CONCAT_PATH);
        DtwStringArray_merge(files, sub_files);
        DtwStringArray_free(sub_files);
    }

    DtwStringArray_free(dirs);

    if(!concat_path){

        struct DtwStringArray *removed =  private_dtw_remove_start_path(files,path);
        DtwStringArray_free(files);
        return removed;
    }

    return files;
}


 DtwStringArray * dtw_list_all_recursively(const char *path,bool concat_path){

    struct DtwStringArray *dirs = dtw_list_dirs_recursively(path,DTW_CONCAT_PATH);
    
    struct DtwStringArray *all = newDtwStringArray();
    
    for(int i = 0; i < dirs->size; i++){

        if(!dtw_ends_with(dirs->strings[i], "/") || !dtw_ends_with(dirs->strings[i], "\\") ){

            char *formated_dir =  (char*)malloc(strlen(dirs->strings[i]) + 2);
            sprintf(formated_dir,"%s/",dirs->strings[i]);
            DtwStringArray_append(all, formated_dir);
            free(formated_dir);
        }

        else{
            DtwStringArray_append(all, dirs->strings[i]);
        }

        struct DtwStringArray *sub_files = dtw_list_basic(dirs->strings[i],DTW_FILE_TYPE,true);
        DtwStringArray_merge(all,sub_files);
        DtwStringArray_free(sub_files);
    }
    DtwStringArray_free(dirs);
     private_dtw_remove_double_bars_from_string_array(all);
    if(!concat_path){

        struct DtwStringArray *removed =  private_dtw_remove_start_path(all,path);
        DtwStringArray_free(all);
        return removed;
    }
    return all;
}