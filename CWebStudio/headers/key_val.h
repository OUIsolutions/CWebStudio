

struct Cweb_KeyVal{
    char *key;
    char *value;
    void (*represent)(struct Cweb_KeyVal *key_val);
    void (*free)(struct Cweb_KeyVal *key_val);
};

struct Cweb_KeyVal* cweb_key_val_constructor(char *key, char *value);
void private_cwebrepresent_key_val(struct Cweb_KeyVal *key_val);
void private_cwebfree_key_val(struct Cweb_KeyVal *key_val);
