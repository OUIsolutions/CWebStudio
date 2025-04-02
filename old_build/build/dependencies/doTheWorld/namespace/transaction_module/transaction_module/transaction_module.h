
typedef struct DtwTransactionModule{
    DtwTransaction *(*newTransaction)();
    DtwTransaction * (*newTransaction_from_json)(cJSON *json_entry);
    DtwTransaction * (*newTransaction_from_json_file)(const char *filename);
    DtwJsonTransactionError * (*validate_json_transaction_file)(const char *filename);

    void (*remove_from_index)(DtwTransaction *self,long index);
    void (*remove_from_source)(DtwTransaction *self,const char *source);
    void (*filter)(DtwTransaction *self,bool (*callback)(DtwActionTransaction *action));

    void (*append_action)(struct DtwTransaction *self,struct DtwActionTransaction  *action);
    void (*write_any)(struct DtwTransaction *self,const char *path,unsigned char *content, long size,bool is_binary);
    void (*write_string)(struct DtwTransaction *self,const char *path,const char *content);

    void (*write_long)(struct DtwTransaction *self,const char *path,long value);
    void (*write_bool)(struct DtwTransaction *self,const char *path,bool value);
    void (*write_double)(struct DtwTransaction *self,const char *path,double value);

    void (*move_any_merging)(struct DtwTransaction *self,const char *source,const char *dest);
    void (*copy_any_merging)(struct DtwTransaction *self,const char *source,const char *dest);


    void (*move_any)(struct DtwTransaction *self,const char *source,const char *dest);
    void (*copy_any)(struct DtwTransaction *self,const char *source,const char *dest);
    void (*delete_any)(struct DtwTransaction *self,const char *source);

    cJSON *(*dumps_transaction_to_json)(struct DtwTransaction *self);
    void (*dumps_transaction_to_json_file)(struct DtwTransaction *self,const char *filename);

    void (*commit)(struct DtwTransaction *self,const char *source);
    void (*represent)(struct DtwTransaction *self);
    void (*free)(struct DtwTransaction *self);

    DtwActionTransactionModule action;
    DtwJsonTransactionErrorModule json_error;


}DtwTransactionModule;

DtwTransactionModule newDtwTransactionModule();
