
typedef struct CwebDictModule{

    void  (*set)(CwebDict *dict,const char *key,const char *value);
    char* (*get_value)(CwebDict *dict,const char *key);
    char* (*find_value_by_normalized_key)(CwebDict *dict,const char *key,const char *chars_to_remove);
    void  (*free)(CwebDict *dict);
    void  (*represent)(CwebDict *dict);

}CwebDictModule;