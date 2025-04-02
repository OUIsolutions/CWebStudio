enum {

    JSON_TRANSACTION_WRONG_TYPE,
    JSON_TRANSACTION_NOT_PRESENT_VALUE,
    JSON_TRANSACTION_INVALID_ACTION
};
typedef struct DtwJsonTransactionError{
    int code;
    char *mensage;
    char *path;


}DtwJsonTransactionError;

DtwJsonTransactionError * private_new_DtwJsonTransactionError( int code,const char *mensage,const  char *path);

void DtwJsonTransactionError_represent(struct DtwJsonTransactionError *self);

void DtwJsonTransactionError_prepend_path(struct DtwJsonTransactionError *self,char *path);

void DtwJsonTransactionError_free(struct DtwJsonTransactionError *self);
