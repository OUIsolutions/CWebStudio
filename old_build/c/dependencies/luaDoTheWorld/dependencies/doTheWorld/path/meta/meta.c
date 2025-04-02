
void DtwPath_insert_dir_after(DtwPath *self,const char *str,const char *dir){
    char *current_dir = DtwPath_get_dir(self);
    int index = (int)dtw_index_of_string(current_dir,str);
    if(index == -1){
        return;
    }

    int start = private_dtw_count_dirs_before(current_dir,index)+1;
    DtwPath_insert_dir_at_index(self, start, dir);
}

void DtwPath_insert_dir_before(DtwPath *self,const char *str,const char *dir){
    char *current_dir = DtwPath_get_dir(self);
    int index = (int)dtw_index_of_string(current_dir,str);
    if(index == -1){
        return;
    }
    int start = private_dtw_count_dirs_before(current_dir,index);
    DtwPath_insert_dir_at_index(self, start, dir);
}

void DtwPath_remove_sub_dirs_at(DtwPath *self,const char *str){
    char *current_dir = DtwPath_get_dir(self);
    int index = (int)dtw_index_of_string(current_dir,str);
    if(index == -1){
        return;
    }

    int start = private_dtw_count_dirs_before(current_dir,index);
    int end = private_dtw_count_dirs_before(current_dir,index+ (int)strlen(str));
    DtwPath_remove_sub_dirs_at_index(self, start, end - 1);
}