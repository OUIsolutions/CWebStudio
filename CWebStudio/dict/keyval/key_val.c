

struct CwebKeyVal* newCwebKeyVal(const char *key, const  char *value){
    struct CwebKeyVal *self = (struct CwebKeyVal*)malloc(sizeof(struct CwebKeyVal));
    self->key = (char*)malloc(strlen(key)+1);
    strcpy(self->key,key);
    self->value = (char*)malloc(strlen(value)+1);
    strcpy(self->value,value);
    return self;
}

void CwebKeyVal_represent(struct CwebKeyVal *self){
    printf("%s : %s\n",self->key,self->value);
}

void CwebKeyVal_free(struct CwebKeyVal *self){
    free(self->key);
    free(self->value);
    free(self);
}