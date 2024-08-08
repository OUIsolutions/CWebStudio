

DtwMultiFileLocker *newDtwMultiFileLocker(){
    DtwMultiFileLocker *self = (DtwMultiFileLocker*) malloc(sizeof (DtwMultiFileLocker));

    self->process = getpid();
    self->total_checks = DTW_MULTIFILE_LOCKER_TOTAL_CHECK;
    self->max_lock_time = DTW_MULTIFILE_LOCKER_MAX_TIMEOUT;
    self->max_wait = DTW_MULFILE_LOCKER_MAX_WAIT;
    self->locked_elements = newDtwStringArray();

    return self;
}




int  DtwMultiFIleLocker_lock(DtwMultiFileLocker *self, const char *element) {

    if(DtwStringArray_find_position(self->locked_elements,element) != -1){
        return DTW_LOCKER_LOCKED;
    }

    const char *LOCK_FOLDER = ".lock";
    const int LOCK_FOLDER_SIZE = (int)strlen(LOCK_FOLDER);
    char *file = (char*)malloc(strlen(element) +  LOCK_FOLDER_SIZE + 10);
    sprintf(file,"%s%s",element,LOCK_FOLDER);
    long started_time = time(NULL);

    while (true){


        long now = time(NULL);
        if((now - started_time) > self->max_wait){
            free(file);
            return DTW_LOCKER_WAIT_ERROR;
        }


         bool write = false;
         int entity_type = dtw_entity_type(file);
         if(entity_type== DTW_NOT_FOUND){
            write = true;
         }

         if(entity_type== DTW_FILE_TYPE){
             long last_modification  = dtw_get_entity_last_motification_in_unix(file);
             if ((now - self->max_lock_time) > last_modification ) {
                 write = true;
             }
         }

         if(entity_type == DTW_FOLDER_TYPE){
             dtw_remove_any(file);
             continue;
         }


         if(!write) {
             continue;
         }
        dtw_write_long_file_content(file,self->process);
        bool break_loop = true;
         for(int i = 0;i < self->total_checks;i++){
            long result = dtw_load_long_file_content(file);
            if(result != self->process && result != -1){
                break_loop = false;
                break;
            }
        }

        if(break_loop){
            break;

        }


    }
    DtwStringArray_append(self->locked_elements,element);
    free(file);
    return DTW_LOCKER_LOCKED;

}

void DtwMultifileLocker_unlock(DtwMultiFileLocker *self, const  char *element){
    bool found = false;
    for(long i = 0; i < self->locked_elements->size;i++){
        if(strcmp(self->locked_elements->strings[i],element)==0){
            found = true;
            break;
        }
    }

    if(!found){
        return;
    }


    const char *LOCK_FOLDER = ".lock";
    const int LOCK_FOLDER_SIZE = (int)strlen(LOCK_FOLDER);
    char *file = (char*)malloc(strlen(element) +  LOCK_FOLDER_SIZE + 10);
    sprintf(file,"%s%s",element,LOCK_FOLDER);
    dtw_remove_any(file);
    free(file);
}


void DtwMultiFileLocker_represemt(DtwMultiFileLocker *self){
    printf("locked:\n");
    for(int i = 0 ; i < self->locked_elements->size;i++){
        char *element = self->locked_elements->strings[i];
        char *unformated = dtw_replace_string(element,".lock","");
        printf("\t%s\n",unformated);
        free(unformated);
    }
}

void DtwMultiFileLocker_free(DtwMultiFileLocker *self){

    for(int i = 0 ; i < self->locked_elements->size;i++){
        char *element = self->locked_elements->strings[i];
        DtwMultifileLocker_unlock(self, element);
    }

    DtwStringArray_free(self->locked_elements);
    free(self);
}