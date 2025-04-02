

struct DtwStringArray * newDtwStringArray(){
    struct DtwStringArray *self = (struct DtwStringArray*)malloc(sizeof(struct DtwStringArray));
    self->size = 0;

    self->strings = (char**)malloc(1);

    return self;
}

int DtwStringArray_find_position(struct DtwStringArray *self, const char *string){
    for(int i = 0; i < self->size; i++){
        if(strcmp(self->strings[i], string) == 0){
            return i;
        }
    }
    return -1;
}


void DtwStringArray_set_value(struct DtwStringArray *self, int index, const char *value){
    if(index < self->size && index >= 0){
        int size = strlen(value);
        self->strings[index] = (char*)realloc(self->strings[index], size + 1);
        self->strings[index][size] = '\0';
        strcpy(self->strings[index], value);
    }
}
void DtwStringArray_append_getting_ownership(struct DtwStringArray *self, char *string){
    self->strings =  (char**)realloc(self->strings, (self->size+ 1) * sizeof(char*));
    self->strings[self->size] = string;
    self->size+=1;
}

// Function prototypes
void DtwStringArray_append(struct DtwStringArray *self, const  char *string){

    self->strings =  (char**)realloc(self->strings, (self->size+ 1) * sizeof(char*));
    self->strings[self->size] = strdup(string);
    self->size+=1;
}

void DtwStringArray_pop(struct DtwStringArray *self, int position){
    free(self->strings[position]);
    for(int i = position; i < self->size -1; i++){
        self->strings[i] = self->strings[i+1];
    }
    self->size-=1;
}

void DtwStringArray_merge(struct DtwStringArray *self, struct DtwStringArray *other){
    for(int i = 0; i < other->size; i++){
        DtwStringArray_append(self, other->strings[i]);
    }
}


void DtwStringArray_represent(struct DtwStringArray *self){
    for(int i = 0; i < self->size; i++){
        printf("%s\n", self->strings[i]);
    }
}

int private_dtw_string_cmp(const void *a, const void *b){

    bool a_its_number;

    double a_num_value = private_dtw_convert_string_to_number(*(const char **)a, &a_its_number);

    if(a_its_number){
        bool b_its_number;

        double b_num_value = private_dtw_convert_string_to_number(*(const char **)b, &b_its_number);

        if(b_its_number){


            return a_num_value - b_num_value;
        }
    }

    const char *str_a = *(const char **)a;
    const char *str_b = *(const char **)b;
    return strcmp(str_a, str_b);
}

void DtwStringArray_sort(struct DtwStringArray *self) {

    qsort(self->strings, self->size, sizeof(char*), private_dtw_string_cmp);
}

struct DtwStringArray * DtwStringArray_clone(DtwStringArray *self){
    DtwStringArray  *clone = newDtwStringArray();
    for(int i = 0; i< self->size; i++){
        DtwStringArray_append(clone,self->strings[i]);
    }
    return clone;
}

char * privateDtwStringArray_append_if_not_included(DtwStringArray *self,char *value){
    long position=DtwStringArray_find_position(self,value);
    if(position != -1){
        free(value);
        return self->strings[position];
    }
    DtwStringArray_append_getting_ownership(self,value);
    return value;
}
void DtwStringArray_free(struct DtwStringArray *self){
    for(int i = 0; i < self->size; i++){
            free(self->strings[i]);
    }

    free(self->strings);
    free(self);
}
