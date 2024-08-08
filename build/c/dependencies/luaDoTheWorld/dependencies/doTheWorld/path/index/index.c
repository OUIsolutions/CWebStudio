
int DtwPath_get_total_dirs(DtwPath *self){
    int size = 0;
    int path_size = (int)strlen(self->path);
    for(int i = 0; i < path_size;i++){
        char current = self->path[i];
        if(current == '/' || current =='\\'){
            size+=1;
        }
    }
    return size;
}

char *DtwPath_get_sub_dirs_from_index(DtwPath *self, int start, int end){

    int size = DtwPath_get_total_dirs(self);
    if(size == 0){
        return NULL;
    }
    int converted_start_index = (int)private_dtw_convert_index(start, size);
    int converted_end_index = (int)private_dtw_convert_index(end, size);

    if(converted_start_index == -1  || converted_end_index == -1){
        return  NULL;
    }

    char *dir = DtwPath_get_dir(self);
    int  dirs_string_size = (int)strlen(dir);
    int total_dirs = 0;
    bool start_defined = false;
    bool end_defined  = false;
    int start_point = 0;
    int end_point = dirs_string_size;

    for(int i= 0 ;i < dirs_string_size;i++ ){
        char current = dir[i];
        if(current == '/' || current =='\\'){
            total_dirs+=1;
            continue;
        }
        if(total_dirs == converted_start_index  &&!start_defined){
            start_point = i;
            start_defined = true;
        }

        if(total_dirs == (converted_end_index + 1)&&!end_defined){
            end_point = i;
            end_defined = true;
        }
    }
    char *buffer = private_dtw_sub_str(dir,start_point,end_point);
    return privateDtwStringArray_append_if_not_included(self->garbage,buffer);
}



int private_dtw_count_dirs_before(const char *dirs,int index){
    int total = 0;
    for(int i =index; i >=0; i--){
        char current_char = dirs[i];
        if(current_char == '\\' || current_char == '/' ){
            total+=1;
        }
    }
    return  total;
}

void DtwPath_insert_dir_at_index(DtwPath *self, int index, const char *dir){

    int size = DtwPath_get_total_dirs(self);
    int converted_index = (int)private_dtw_convert_index(index,size+1);

    if(converted_index == -1){
        return  ;
    }
    char * starter = NULL;
    if(converted_index > 0){
        starter = DtwPath_get_sub_dirs_from_index(self, 0, converted_index - 1);
    }

    const char *rest =NULL;
    if(converted_index < size){
        rest = DtwPath_get_sub_dirs_from_index(self, converted_index, -1);
    }


     char *buffer =NULL;
    if(starter && rest){
        buffer = private_dtw_formatt("%s/%s/%s",starter,dir,rest);
    }
    if(starter && rest==NULL){
        buffer = private_dtw_formatt("%s/%s",starter,dir);
    }
    if(starter == NULL && rest){
        buffer = private_dtw_formatt("%s/%s",dir,rest);
    }

    if(!starter && !rest){
        buffer = (char*)dir;
    }

    DtwPath_set_dir(self,buffer);

    if(starter || rest){
        free(buffer);
    }
}



void DtwPath_remove_sub_dirs_at_index(DtwPath *self, int start, int end){

    int size = DtwPath_get_total_dirs(self);
    if(size == 0){
        return ;
    }
    int converted_start_index = (int)private_dtw_convert_index(start, size);
    int converted_end_index = (int)private_dtw_convert_index(end, size);

    if(converted_start_index == -1  || converted_end_index == -1){
        return  ;
    }
    char *start_dir = NULL;
    if(converted_start_index != 0){
        start_dir = DtwPath_get_sub_dirs_from_index(self,0,converted_start_index-1);
    }

    char *end_dir = DtwPath_get_sub_dirs_from_index(self,converted_end_index+1,-1);

    if(start_dir != NULL  && end_dir != NULL){
        char *full_dir = dtw_concat_path(start_dir,end_dir);
        DtwPath_set_dir(self,full_dir);
        free(full_dir);
        return ;
    }
    if(start_dir != NULL){
        DtwPath_set_dir(self,start_dir);
    }

    if(end_dir != NULL){
        DtwPath_set_dir(self,end_dir);
    }


}

