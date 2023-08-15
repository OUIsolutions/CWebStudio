




CwebDict *newCwebDict(){
    CwebDict *self = (CwebDict *)malloc(sizeof(struct CwebDict));
    self->keys_vals = (CwebKeyVal**)malloc(1);
    self->size = 0;
    return self;
}

char *CwebDict_get_by_normalized_key(CwebDict *self, const char *key, const char *chars_to_remove){

    for(int i = 0;i < self->size;i++){
        char *current_key = self->keys_vals[i]->key;
        char *normalized_key = cweb_normalize_string(current_key, chars_to_remove);

        if(strcmp(normalized_key, key) == 0){
            free(normalized_key);
            return self->keys_vals[i]->value;
        }

        free(normalized_key);

    }
    return NULL;

}
void CwebDict_set(CwebDict *self, const char *key, const char *value){
    CwebKeyVal *key_val = cweb_key_val_constructor(key, value);
    self->keys_vals = (CwebKeyVal**)realloc(self->keys_vals, (self->size+1)*sizeof(CwebKeyVal*));
    self->keys_vals[self->size] = key_val;
    self->size++;
}

char * CwebDict_get(CwebDict *self, const  char *key){
    for(int i = 0; i < self->size; i++){
        if(strcmp(self->keys_vals[i]->key, key) == 0){
            return self->keys_vals[i]->value;
        }
    }
    return NULL;
}

void CwebDict_represent(CwebDict *dict){
    for(int i = 0; i < dict->size; i++){
        dict->keys_vals[i]->represent(dict->keys_vals[i]);
    }
}

void CwebDict_free(CwebDict *self){
    
    for(int i = 0; i < self->size; i++){
        CwebKeyVal *key_val = self->keys_vals[i];
         key_val->free(key_val);
    }
    free(self->keys_vals);
    free(self);
}
