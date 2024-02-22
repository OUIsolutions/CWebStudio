typedef struct CwebKeyValModule{
    void (*represent)(CwebKeyVal *key_val);
    void (*free)(CwebKeyVal *key_val);
}CwebKeyValModule;

CwebKeyValModule newCwebKeyValModule();