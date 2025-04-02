
typedef struct CwebDictModule{


    CwebDict *(*newDict)();
    void  (*set)(CwebDict *dict,const char *key,const char *value);
    char* (*get)(CwebDict *dict,const char *key);
    char* (*get_by_normalized_key)(CwebDict *dict,const char *key,const char *chars_to_remove);
    void  (*free)(CwebDict *dict);
    void  (*represent)(CwebDict *dict);

    CwebKeyValModule keyval;

}CwebDictModule;

