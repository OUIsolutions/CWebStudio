

typedef struct DtwJsonTransactionErrorModule{
    void (*represent)(struct DtwJsonTransactionError *self);
    void (*free)(struct DtwJsonTransactionError *self);

}DtwJsonTransactionErrorModule;

DtwJsonTransactionErrorModule newDtwJsonTransactionErrorModule();