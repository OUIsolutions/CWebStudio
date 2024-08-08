





DtwHash * newDtwHash(){
    DtwHash *self = (DtwHash*) malloc(sizeof(DtwHash));
    self->hash = dtw_generate_sha_from_string("");
    return self;
}

bool  DtwHash_digest_any(DtwHash *self,unsigned char *content,long size){
    if(content == NULL){
        return false;
    }
    char *generated = dtw_generate_sha_from_any(content,size);
    char result[300] ={0};
    sprintf(result,"%s%s",self->hash,generated);
    free(generated);
    free(self->hash);
    self->hash = dtw_generate_sha_from_string(result);
    return true;
}

bool  DtwHash_digest_string(DtwHash * self, const char *content){
    return DtwHash_digest_any(self,(unsigned char *)content, (long)strlen(content));
}

void DtwHash_digest_long(DtwHash * self,long content){
    char formated[20] ={0};
    sprintf(formated,"%ld",content);
    DtwHash_digest_string(self,formated);
}

void DtwHash_digest_double(DtwHash * self,double content){
    char formated[20] ={0};
    sprintf(formated,"%lf",content);
    DtwHash_digest_string(self,formated);
}

void DtwHash_digest_bool(DtwHash * self,bool content){
    char formated[20] ={0};
    sprintf(formated,"%d",(bool)content);
    DtwHash_digest_string(self,formated);
}

bool  DtwHash_digest_file(DtwHash * self, const char *path){

    long size;
    unsigned  char *content = dtw_load_binary_content(path,&size);
    if(!content){
        return false;
    }
    DtwHash_digest_any(self,content,size);
    free(content);
    return true;
}

bool  DtwHash_digest_entity_last_modification(DtwHash * self, const char *path){
    long last_modification = dtw_get_entity_last_motification_in_unix(path);
    if(last_modification == -1){
        return false;
    }
    DtwHash_digest_long(self,last_modification);
    return true;
}


bool  DtwHash_digest_string_array(DtwHash *self,DtwStringArray *element){
    if(element->size == 0){
        return false;
    }
    DtwStringArray  *clone = DtwStringArray_clone(element);
    DtwStringArray_sort(clone);

    for(int i =0 ; i < clone->size; i++){
        DtwHash_digest_string(self,clone->strings[i]);
    }
    DtwStringArray_free(clone);
    return  true;
}

bool  DtwHash_digest_string_array_last_modifications(DtwHash *self,DtwStringArray *element){
    if(element->size == 0){
        return false;
    }
    DtwStringArray  *clone = DtwStringArray_clone(element);
    DtwStringArray_sort(clone);
    for(int i =0 ; i < clone->size; i++){
        DtwHash_digest_entity_last_modification(self, clone->strings[i]);
    }
    DtwStringArray_free(clone);
    return true;
}

bool DtwHash_digest_string_array_last_modifications_adding_name(DtwHash *self,DtwStringArray *element){
    if(element->size == 0){
        return false;
    }
    DtwStringArray  *clone = DtwStringArray_clone(element);
    DtwStringArray_sort(clone);
    for(int i =0 ; i < clone->size; i++){
        DtwHash_digest_string(self,clone->strings[i]);
        DtwHash_digest_entity_last_modification(self, clone->strings[i]);
    }
    DtwStringArray_free(clone);
    return true;
}


bool DtwHash_digest_string_array_content(DtwHash *self,DtwStringArray *element){
    if(element->size == 0){
        return false;
    }
    DtwStringArray  *clone = DtwStringArray_clone(element);
    DtwStringArray_sort(clone);
    for(int i =0 ; i < clone->size; i++){
        DtwHash_digest_file(self,clone->strings[i]);
    }
    DtwStringArray_free(clone);
    return true;
}

bool DtwHash_digest_string_array_content_adding_name(DtwHash *self,DtwStringArray *element){
    if(element->size == 0){
        return false;
    }
    DtwStringArray  *clone = DtwStringArray_clone(element);
    DtwStringArray_sort(clone);
    for(int i =0; i < clone->size; i++){
        DtwHash_digest_string(self,clone->strings[i]);
        DtwHash_digest_file(self,clone->strings[i]);
    }
    DtwStringArray_free(clone);
    return true;
}


bool DtwHash_digest_folder_by_last_modification(DtwHash *self,const char *path){
    DtwStringArray  *folder = dtw_list_all_recursively(path,DTW_NOT_CONCAT_PATH);
    if(folder->size == 0){
        DtwStringArray_free(folder);
        return false;
    }
    DtwStringArray_sort(folder);
    for(int i =0; i < folder->size; i++){
        DtwHash_digest_string(self,folder->strings[i]);
        char *formated_path = dtw_concat_path(path,folder->strings[i]);

        DtwHash_digest_entity_last_modification(self, formated_path);
        free(formated_path);
    }
    DtwStringArray_free(folder);
    return true;
}

bool DtwHash_digest_folder_by_content(DtwHash *self,const char *path){

    DtwStringArray  *folder = dtw_list_all_recursively(path,DTW_NOT_CONCAT_PATH);
    if(folder->size == 0){
        DtwStringArray_free(folder);
        return false;
    }
    DtwStringArray_sort(folder);
    for(int i =0; i < folder->size; i++){
        DtwHash_digest_string(self,folder->strings[i]);
        char *formated_path = dtw_concat_path(path,folder->strings[i]);
        DtwHash_digest_file(self,formated_path);
        free(formated_path);
    }
    DtwStringArray_free(folder);
    return true;
}

void  DtwHash_free(DtwHash *self){
    free(self->hash);
    free(self);
}