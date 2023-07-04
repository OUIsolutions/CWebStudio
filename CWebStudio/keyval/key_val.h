

typedef struct CwebKeyVal{
    char *key;
    char *value;
    void (*represent)(struct CwebKeyVal *key_val);
    void (*free)(struct CwebKeyVal *key_val);
}CwebKeyVal;

struct CwebKeyVal* cweb_key_val_constructor(const char *key,const  char *value);
void private_cweb_represent_key_val(struct CwebKeyVal *self);
void private_cweb_free_key_val(struct CwebKeyVal *self);
