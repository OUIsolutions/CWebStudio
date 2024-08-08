

typedef struct DtwJsonTreeErrorModule{
    void (*free)(struct DtwJsonTreeError *self);
    void (*represent)(struct DtwJsonTreeError *self);

}DtwJsonTreeErrorModule;

DtwJsonTreeErrorModule newDtwJsonTreeErrorModule();