




struct CwebDict *cweb_create_dict(){
    struct CwebDict *self = (struct CwebDict *)malloc(sizeof(struct CwebDict));
    self->keys_vals = (struct CwebKeyVal**)malloc(1);
    self->size = 0;
    self->set = private_cweb_dict_set;
    self->get_value = private_cweb_dict_get;
    self->free = private_cweb_free_dict;
    self->represent = private_cweb_dict_represent;
    return self;
}

void private_cweb_dict_set(struct CwebDict *self,const char *key,const char *value){
    struct CwebKeyVal *key_val = cweb_key_val_constructor(key, value);
    self->keys_vals[self->size] = key_val;
    self->size++;
}

char * private_cweb_dict_get(struct CwebDict *self, char *key){
    for(int i = 0; i < self->size; i++){
        if(strcmp(self->keys_vals[i]->key, key) == 0){
            return self->keys_vals[i]->value;
        }
    }
    return NULL;
}

void private_cweb_dict_represent(struct CwebDict *self){
    for(int i = 0; i < self->size; i++){
        self->keys_vals[i]->represent(self->keys_vals[i]);
    }
}

void private_cweb_free_dict(struct CwebDict *self){
    
    for(int i = 0; i < self->size; i++){
        struct CwebKeyVal *key_val = self->keys_vals[i];
         key_val->free(key_val);
    }
    free(self->keys_vals);
    free(self);
}
