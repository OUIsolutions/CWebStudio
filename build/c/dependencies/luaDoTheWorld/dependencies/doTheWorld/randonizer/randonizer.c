



DtwRandonizer * newDtwRandonizer(){
    DtwRandonizer *self = (DtwRandonizer*) malloc(sizeof (DtwRandonizer));
    *self =(DtwRandonizer){0};

    #ifndef DTW_DEBUG_TIME

            #ifdef _WIN32
                FILETIME ft;
                LARGE_INTEGER li;

                GetSystemTimeAsFileTime(&ft);
                li.LowPart = ft.dwLowDateTime;
                li.HighPart = ft.dwHighDateTime;

                self->internal_seed = li.QuadPart;
                self->internal_seed ^= GetCurrentProcessId();
            #else
                struct timespec ts;
                clock_gettime(CLOCK_REALTIME, &ts);

                self->internal_seed = (uint64_t)ts.tv_sec + (uint64_t)ts.tv_nsec;
                self->internal_seed += getpid();
            #endif
    #endif
    return self;
}

int DtwRandonizer_generate_num(DtwRandonizer *self,int max) {
    self->actual_generation+=1;
    srand(  self->internal_seed + self->actual_generation + self->seed);
    int value = rand() % max;
    return value;
}
char * DtwRandonizer_generate_token(struct DtwRandonizer*self, int size){
    static const char chars[] =
            "abcdefghijklmnopqrstuvwxyz"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "0123456789";

    int total_size = sizeof(chars) - 1;
    char *token = (char*)malloc(size +1);

    for (int i = 0; i < size; ++i) {
        int index = DtwRandonizer_generate_num(self,total_size);
        token[i] = chars[index];
    }

    token[size] = '\0';
    return token;
}

void DtwRandonizer_free(struct DtwRandonizer *self){
    free(self);
}

