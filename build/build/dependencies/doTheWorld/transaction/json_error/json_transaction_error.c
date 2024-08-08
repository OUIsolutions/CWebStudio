




DtwJsonTransactionError * private_new_DtwJsonTransactionError( int code,const char *mensage,const  char *path){
    DtwJsonTransactionError *self = (DtwJsonTransactionError*) malloc(sizeof(DtwJsonTransactionError));
    self->code  = code;
    self->mensage = strdup(mensage);
    self->path = NULL;
    if(path){
        self->path = strdup(path);
    }

    return self;
}

void DtwJsonTransactionError_represent(struct DtwJsonTransactionError *self){
    printf("code: %d\n",self->code);
    printf("mensage:%s\n",self->mensage);
    if(self->path){
        printf("path: %s",self->path);
    }
}

void DtwJsonTransactionError_prepend_path(struct DtwJsonTransactionError *self,char *path){
    if(self->path){

        char *new_path = (char*)calloc(sizeof (char), strlen(self->path) + strlen(path) + 2);

        sprintf(new_path,"%s%s",path,self->path);

        free(self->path);
        self->path = new_path;
        return;
    }
    self->path = strdup(path);
}


void DtwJsonTransactionError_free(struct DtwJsonTransactionError *self){
    free(self->mensage);
    if(self->path){
        free(self->path);
    }
    free(self);

}

