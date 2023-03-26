

struct CwebKeyVal* cweb_key_val_constructor(const char *key,const  char *value){
    struct CwebKeyVal *self = (struct CwebKeyVal*)malloc(sizeof(struct CwebKeyVal));
    self->key = (char*)malloc(strlen(key)+1);
    strcpy(self->key,key);
    self->value = (char*)malloc(strlen(value)+1);
    strcpy(self->value,value);
    self->represent = private_cweb_represent_key_val;
    self->free = private_cweb_free_key_val;
    return self;
}

void private_cweb_represent_key_val(struct CwebKeyVal *self){
    printf("%s : %s\n",self->key,self->value);
}

void private_cweb_free_key_val(struct CwebKeyVal *self){
    free(self->key);
    free(self->value);
    free(self);
}