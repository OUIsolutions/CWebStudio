

struct CwebKeyVal{
    char *key;
    char *value;
    void (*represent)(struct CwebKeyVal *key_val);
    void (*free)(struct CwebKeyVal *key_val);
};

struct CwebKeyVal* cweb_key_val_constructor(const char *key,const  char *value);
void private_cweb_represent_key_val(struct CwebKeyVal *key_val);
void private_cweb_free_key_val(struct CwebKeyVal *key_val);
