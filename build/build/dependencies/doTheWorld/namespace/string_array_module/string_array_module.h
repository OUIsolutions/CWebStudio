
typedef struct DtwStringArrayModule{
    DtwStringArray *(*newStringArray)();

    void (*set_value)(struct DtwStringArray *self,int index,const char *value);

    void (*append)(struct DtwStringArray *self,const char *string);

    void (*pop)(struct DtwStringArray *self, int position);

    void (*merge)(struct DtwStringArray *self, struct DtwStringArray *other);

    void (*represent)(struct DtwStringArray *self);

    int (*find_position)(struct DtwStringArray *self,const char *string);

    void (*sort)(struct DtwStringArray *self);

    void (*free)(struct DtwStringArray *self);


}DtwStringArrayModule;

DtwStringArrayModule newDtwStringArrayModule();