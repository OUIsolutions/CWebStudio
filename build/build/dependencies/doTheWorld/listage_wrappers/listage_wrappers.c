

 DtwStringArray * dtw_list_files(const char *path, bool concat_path){
    return dtw_list_basic(path,  DTW_FILE_TYPE, concat_path);
}

 DtwStringArray * dtw_list_dirs(const char *path, bool concat_path){
    return dtw_list_basic(path,DTW_FOLDER_TYPE, concat_path);
}

 DtwStringArray *  dtw_list_all(const char *path,  bool concat_path){
    return dtw_list_basic(path, DTW_ALL_TYPE, concat_path);
}
