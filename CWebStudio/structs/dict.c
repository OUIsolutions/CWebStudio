




struct CwebDict *cweb_create_dict(){
    struct CwebDict *dict = (struct CwebDict *)malloc(sizeof(struct CwebDict));
    dict->keys_vals = (struct CwebKeyVal**)malloc(1);
    dict->size = 0;
    dict->set = private_cweb_dict_set;
    dict->get_value = private_cweb_dict_get;
    dict->free = private_cweb_free_dict;
    dict->represent = private_cweb_dict_represent;
    return dict;
}

void private_cweb_dict_set(struct CwebDict *dict, char *key, char *value){
    struct CwebKeyVal *key_val = cweb_key_val_constructor(key, value);
    dict->keys_vals[dict->size] = key_val;
    dict->size++;
}

char * private_cweb_dict_get(struct CwebDict *dict, char *key){
    for(int i = 0; i < dict->size; i++){
        if(strcmp(dict->keys_vals[i]->key, key) == 0){
            return dict->keys_vals[i]->value;
        }
    }
    return NULL;
}

void private_cweb_dict_represent(struct CwebDict *dict){
    for(int i = 0; i < dict->size; i++){
        dict->keys_vals[i]->represent(dict->keys_vals[i]);
    }
}

void private_cweb_free_dict(struct CwebDict *dict){
    for(int i = 0; i < dict->size; i++){
        struct CwebKeyVal *key_val = dict->keys_vals[i];
         key_val->free(key_val);
    }
    free(dict->keys_vals);
    free(dict);
}
