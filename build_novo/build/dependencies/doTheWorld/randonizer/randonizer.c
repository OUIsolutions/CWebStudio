



DtwRandonizer * newDtwRandonizer(){
    DtwRandonizer *self = (DtwRandonizer*) malloc(sizeof (DtwRandonizer));
    *self =(DtwRandonizer){0};
    self->time_seed = dtw_get_time();
    return self;
}

char * DtwRandonizer_generate_token(struct DtwRandonizer*self, int size){
    self->actual_generation+=1;
    static const char chars[] =
            "abcdefghijklmnopqrstuvwxyz"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "0123456789";

    int total_size = sizeof(chars) - 1;
    char *token = (char*)malloc(size +1);

    srand(  self->time_seed + self->actual_generation + self->seed);

    for (int i = 0; i < size; ++i) {
        int index = rand() % total_size;
        token[i] = chars[index];
    }

    token[size] = '\0';
    return token;
}

void DtwRandonizer_free(struct DtwRandonizer *self){
    free(self);
}

