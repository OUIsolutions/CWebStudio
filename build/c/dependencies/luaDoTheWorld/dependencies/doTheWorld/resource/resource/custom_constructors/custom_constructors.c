

DtwResource * DtwResource_sub_resource_next(DtwResource *self, const char *end_path){
    if(DtwResource_error(self)){
        return NULL;
    }
    long  size = dtw_get_total_itens_of_dir(self->path);
    if(size < 0){
        size = 0;
    }
    while(true){

        char *path = NULL;
        if(end_path){
            path = private_dtw_realoc_formatting(path,"%ld%s",size,end_path);
        }

        else{
            path = private_dtw_realoc_formatting(path,"%ld",size);
        }

        DtwResource *new_element = DtwResource_sub_resource_ensuring_not_exist(self,"%s",path);
        free(path);
        if(DtwResource_error(self)){
            return NULL;
        }

        if(new_element){
            return new_element;
        }
        size = size+1;
    }
}


DtwResource * DtwResource_sub_resource_now(DtwResource *self, const char *end_path){
    if(DtwResource_error(self)){
        return NULL;
    }
    bool empty_already_exist = false;


    while(true){

        long now = dtw_get_time();
        char *time = dtw_convert_unix_time_to_string(now);
        char *path = NULL;

        if(empty_already_exist){
            char *token = DtwRandonizer_generate_token(self->root_props->randonizer,10);
            path = private_dtw_realoc_formatting(path,"%s--%s",time,token);
            free(token);
        }
        else{
            path = private_dtw_realoc_formatting(path,"%s",time);
        }

        free(time);

        if(end_path){
            path = private_dtw_realoc_formatting(path,"%s%s",path,end_path);
        }

        DtwResource *new_element = DtwResource_sub_resource_ensuring_not_exist(self,"%s",path);

        free(path);


        if(DtwResource_error(self)){
            return NULL;
        }
        if(new_element){
            return new_element;
        }
        empty_already_exist = true;
    }
}


DtwResource * DtwResource_sub_resource_now_in_unix(DtwResource *self, const char *end_path){
    if(DtwResource_error(self)){
        return NULL;
    }
    bool empty_already_exist = false;

    while(true){

        long now = dtw_get_time();
        char *path = NULL;

        if(empty_already_exist){
            char *token = DtwRandonizer_generate_token(self->root_props->randonizer,10);
            path = private_dtw_realoc_formatting(path,"%ld--%s",now,token);
            free(token);
        }
        else{
            path = private_dtw_realoc_formatting(path,"%ld",now);
        }

        if(end_path){
            path = private_dtw_realoc_formatting(path,"%s%s",path,end_path);
        }

        DtwResource *new_element = DtwResource_sub_resource_ensuring_not_exist(self,"%s",path);

        free(path);


        if(DtwResource_error(self)){
            return NULL;
        }
        if(new_element){
            return new_element;
        }
        empty_already_exist = true;
    }
}

DtwResource * DtwResource_sub_resource_random(DtwResource *self, const char *end_path){
    if(DtwResource_error(self)){
        return NULL;
    }
    while(true){

        char *path = NULL;
        char *token = DtwRandonizer_generate_token(self->root_props->randonizer,15);
        path = private_dtw_realoc_formatting(path,"%s",token);
        free(token);

        if(end_path){
            path = private_dtw_realoc_formatting(path,"%s%s",path,end_path);
        }

        DtwResource *new_element = DtwResource_sub_resource_ensuring_not_exist(self,"%s",path);
        free(path);
        if(DtwResource_error(self)){
            return NULL;
        }

        if(new_element){
            return new_element;
        }

    }
}


