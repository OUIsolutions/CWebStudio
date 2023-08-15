typedef struct CwebStringArrayModule{
    void (*set)(struct CwebStringArray *self,int index,const char *value);
    void (*add)(struct CwebStringArray *self,const char *string);
    void (*merge)(struct CwebStringArray *self, struct CwebStringArray *other);
    void (*represent)(struct CwebStringArray *self);
    void (*free)(struct CwebStringArray *self);
    int (*find)(struct CwebStringArray *self,const char *string);
}CwebStringArrayModule;

CwebStringArrayModule newCwebStringArrayModule();