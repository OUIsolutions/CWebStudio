

struct Cweb_KeyVal* cweb_key_val_constructor(char *key, char *value){
    struct Cweb_KeyVal *key_val = (struct Cweb_KeyVal*)malloc(sizeof(struct Cweb_KeyVal));
    key_val->key = (char*)malloc(strlen(key)+1);
    strcpy(key_val->key,key);
    key_val->value = (char*)malloc(strlen(value)+1);
    strcpy(key_val->value,value);
    key_val->represent = private_cweb_represent_key_val;
    key_val->free = private_cweb_free_key_val;
    return key_val;
}

void private_cweb_represent_key_val(struct Cweb_KeyVal *key_val){
    printf("Key: %s\n",key_val->key);
    printf("Value: %s\n",key_val->value);
}

void private_cweb_free_key_val(struct Cweb_KeyVal *key_val){
    free(key_val->key);
    free(key_val->value);
    free(key_val);
}