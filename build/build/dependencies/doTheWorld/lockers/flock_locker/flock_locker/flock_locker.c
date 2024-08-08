
DtwFlockLocker * newFlockLocker(){

    DtwFlockLocker *self = (DtwFlockLocker*) malloc(sizeof (DtwFlockLocker));
    *self  = (DtwFlockLocker){0};
    self->locked_files = private_new_privateFlockArray();
    self->temp_folder = "/tmp/";

    return self;
}
int  DtwFlockLocker_lock(DtwFlockLocker *self, const char *filename) {
    if (privateDtwFlockArray_index_of(self->locked_files, filename) != -1) {
        return DTW_LOCKER_LOCKED;
    }

    char *file_sha = dtw_generate_sha_from_string(filename);
    const char *EXTENSION = "lock";
    char *formatted = (char *) malloc(
            strlen(file_sha) +
            strlen(self->temp_folder) +
            strlen(EXTENSION) +
            3
    );
    sprintf(formatted, "%s/%s.%s", self->temp_folder, file_sha, EXTENSION);

    free(file_sha);
    int fd = open(formatted, O_RDWR | O_CREAT, 0644);
    free(formatted);
    if (fd == -1) {
        return DTW_LOCKER_IMPOSSIBLE_TO_CREATE_FILE_DESCRIPTOR;
    }
    if (flock(fd, LOCK_EX) == -1) {
        close(fd);
        return DTW_LOCKER_FLCTL_FAIL;
    }
    privateDtwFlockArray_append(self->locked_files, filename, fd);
    return  DTW_LOCKER_LOCKED;
}

void private_FlockLocker_unlock_by_index(DtwFlockLocker *self, int index){
    privateDtwFlockLockedElement  *element = self->locked_files->elements[index];
    flock(element->file_descriptor, LOCK_UN);
    close(element->file_descriptor);
}
void DtwFlockLocker_unlock(DtwFlockLocker *self, const char *filename){
    int index = privateDtwFlockArray_index_of(self->locked_files, filename);
    if(index == -1){
        return;
    }
    private_FlockLocker_unlock_by_index(self,index);
}
void  DtwFlockLocker_represent(DtwFlockLocker *self){
    privateDtwFlockArray_represent(self->locked_files);
}
void  DtwFlockLocker_free(DtwFlockLocker *self){
    for(int i = 0 ; i < self->locked_files->size; i++){
        private_FlockLocker_unlock_by_index(self,i);
    }
    privateDtwFlockArray_free(self->locked_files);
    free(self);
}