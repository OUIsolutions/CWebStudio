

DtwLocker *newDtwLocker(){

    DtwLocker *self = (DtwLocker*)malloc(sizeof(DtwLocker));
#ifdef __linux__
    self->locker = newFlockLocker();
#endif
#ifdef _WIN32
    self->locker = newDtwMultiFileLocker();
#endif
    return self;
}

int DtwLocker_lock(DtwLocker *self, const  char *element){

#ifdef __linux__
    return DtwFlockLocker_lock(self->locker,element);
#endif
#ifdef _WIN32
    return DtwMultiFIleLocker_lock(self->locker,element);
#endif
    return  DTW_LOCKER_OS_NOT_PREDICTIBLE;
}

void DtwLocker_unlock(DtwLocker *self, const  char *element){

#ifdef __linux__
    DtwFlockLocker_unlock(self->locker,element);
#endif
    #ifdef _WIN32
         DtwMultifileLocker_unlock(self->locker,element);
    #endif
}

void DtwLocker_represemt(DtwLocker *self){

#ifdef __linux__
    DtwFlockLocker_represent(self->locker);
#endif
#ifdef _WIN32
     DtwMultiFileLocker_represemt(self->locker);
#endif
}

void DtwLocker_free(DtwLocker *self){

#ifdef __linux__
    DtwFlockLocker_free(self->locker);
#endif

#ifdef _WIN32
     DtwMultiFileLocker_free(self->locker);
#endif
    free(self);
}
