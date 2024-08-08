

void DtwPath_set_extension(struct DtwPath *self, const char *extension){

    const char *dir = DtwPath_get_dir(self);
    if(!dir){
        dir = "";
    }
    const char *name = DtwPath_get_name(self);
    if(!name){
        name = "";
    }
    free(self->path);
    char *formated_extension = dtw_replace_string(extension,".","");
    self->path= private_dtw_formatt("%s%s.%s",dir,name,formated_extension);
    free(formated_extension);
}


void DtwPath_set_name(struct DtwPath * self, const char * name){
    const char *dir = DtwPath_get_dir(self);
    if(!dir){
        dir = "";
    }
    char *extension = DtwPath_get_extension(self);
    free(self->path);

    if(extension){
        self->path = private_dtw_formatt("%s%s.%s",dir,name,extension);
    }
    if(!extension){
        self->path = private_dtw_formatt("%s%s",dir,name);
    }
}



void DtwPath_set_full_name(struct DtwPath * self, const char * full_name){
    const char *dir = DtwPath_get_dir(self);
    if(!dir){
        dir = "";
    }
    free(self->path);
    self->path = private_dtw_formatt("%s%s",dir,full_name);

}


void DtwPath_set_dir(struct DtwPath *self, const char *dir){
    const char * full_name = DtwPath_get_full_name(self);
    if(!full_name){
        full_name = "";
    }
    free(self->path);
    char *buffer = private_dtw_formatt("%s/%s",dir,full_name);
    self->path = private_dtw_format_path(buffer);
    free(buffer);

}


void DtwPath_set_path(struct DtwPath *self, const char *target_path) {
    free(self->path);
    self->path = private_dtw_format_path(target_path);
}


void DtwPath_add_start_dir(struct DtwPath *self, const char *start_dir){
    char *element = dtw_concat_path(start_dir,self->path);
    free(self->path);
    self->path = private_dtw_format_path(element);
    free(element);
}

void DtwPath_add_end_dir(struct DtwPath *self, const char *end_dir){
    const char *dir = DtwPath_get_dir(self);
    if(!dir){
        dir = "";
    }
    const char * full_name = DtwPath_get_full_name(self);
    if(!full_name){
        full_name = "";
    }
    free(self->path);

    char *buffer = private_dtw_formatt("%s/%s/%s",dir,end_dir,full_name);
    self->path = private_dtw_format_path(buffer);
    free(buffer);
}

void DtwPath_replace_dirs(DtwPath *self,const char *str,const char *dir){
    char *self_dir = DtwPath_get_dir(self);

    char *formatted_entry = NULL;
    if(dtw_starts_with(self_dir,str)){
       formatted_entry = private_dtw_formatt("%s/",dir);
    }
    else{
        formatted_entry = private_dtw_formatt("/%s/",dir);

    }
    char * formated_dir = dtw_replace_string(self_dir,str,formatted_entry);
    DtwPath_set_dir(self,formated_dir);
    free(formated_dir);
    free(formatted_entry);

}