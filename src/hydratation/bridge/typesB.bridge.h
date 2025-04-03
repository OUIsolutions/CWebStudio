

typedef struct  CWebHyDrationBridge {
    char *name;
    void  *hydration;
    void  (*callback)(struct CWebHyDrationBridge *bridge);

    CwebStringArray *requirements_code;

    void *extra_args;

}CWebHyDrationBridge;

