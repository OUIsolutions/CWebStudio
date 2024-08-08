


typedef struct DtwRandonizer{
    long internal_seed;
    long seed;
    long actual_generation;

}DtwRandonizer;


DtwRandonizer * newDtwRandonizer();

int DtwRandonizer_generate_num(DtwRandonizer *self,int max);

char * DtwRandonizer_generate_token(struct DtwRandonizer*self, int size);
void DtwRandonizer_free(struct DtwRandonizer *self);


