
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

    char *dir = DtwPath_get_dir(self);
    int  dirs_string_size = (int)strlen(dir);
    int total_dirs = 0;
    int start_point = 0;
    int end_point = dirs_string_size;

    for(int i= 0 ;i < dirs_string_size;i++ ){
        char current = dir[i];
        if(current == '/' || current =='\\'){
            total_dirs+=1;
        }
        if(total_dirs == converted_start_index){
            start_point = i;
        }

        if(total_dirs == (converted_end_index + 1)){
            end_point = i;
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
    if(starter && !rest){
        buffer = private_dtw_formatt("%s/%s",starter,dir);
    }
    if(!starter && rest){
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

void DtwPath_remove_sub_dirs_at_index(DtwPath *self, int start, int end){

    int size = DtwPath_get_total_dirs(self);
    if(size == 0){
        return ;
    }
    int converted_start_index = (int)private_dtw_convert_index(start, size);
    int converted_end_index = (int)private_dtw_convert_index(end, size);


    char *start_dirs = NULL;
    if(converted_start_index > 0){
        start_dirs = DtwPath_get_sub_dirs_from_index(self, 0, converted_start_index - 1);
    }

    char *end_dirs = DtwPath_get_sub_dirs_from_index(self, converted_end_index + 1, -1);

    if(start_dirs){
        char *buffer = private_dtw_formatt("%s/%s",start_dirs,end_dirs);
        DtwPath_set_dir(self,buffer);
        free(buffer);
    }

    if(!start_dirs){
        DtwPath_set_dir(self,end_dirs);
    }

}

void DtwPath_remove_sub_dirs_at(DtwPath *self,const char *str){
    char *current_dir = DtwPath_get_dir(self);
    int index = (int)dtw_index_of_string(current_dir,str);
    if(index == -1){
        return;
    }

    int start = private_dtw_count_dirs_before(current_dir,index);
    int end = private_dtw_count_dirs_before(current_dir,index+ (int)strlen(str));
    printf("start %d\n",start);

    printf("end %d\n",end);
    DtwPath_remove_sub_dirs_at_index(self, start, end - 1);
}