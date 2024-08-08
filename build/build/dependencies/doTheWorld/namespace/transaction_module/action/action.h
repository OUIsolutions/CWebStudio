

typedef struct DtwActionTransactionModule{

    DtwActionTransaction *(*newAction)();

    DtwActionTransaction * (*write_any)(const char *source,unsigned  char *content,long size,bool is_binary);

    DtwActionTransaction * (*move_any)(const char *source, const char *dest);
    DtwActionTransaction * (*move_any_merging)(const char *source, const char *dest);
    DtwActionTransaction * (*copy_any_merging)(const char *source, const char *dest);

    DtwActionTransaction * (*copy_any)(const char *source, const char *dest);

    DtwActionTransaction * (*delete_any)(const char *source);

    short (*convert_action_to_integer)(char *action);

    const char * (*convert_action_to_string)(int action);

    void (*commit)(DtwActionTransaction* self,const char *path);

    void (*represent)(DtwActionTransaction* self);

    void (*free)(DtwActionTransaction* self);

}DtwActionTransactionModule;

DtwActionTransactionModule newDtwActionTransactionModule();