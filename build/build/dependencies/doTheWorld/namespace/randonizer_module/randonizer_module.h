
typedef struct  DtwRandonizerModule{
    DtwRandonizer * (*newRandonizer)();

    char * (*generate_token)(DtwRandonizer*self, int size);
    void (*free)(DtwRandonizer *self);
}DtwRandonizerModule;

DtwRandonizerModule newDtwRandonizerModule();