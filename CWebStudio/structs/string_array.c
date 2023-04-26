
struct CwebStringArray * cweb_constructor_string_array(){
    struct CwebStringArray *self = (struct CwebStringArray*)malloc(sizeof(struct CwebStringArray));
    self->size = 0;

    self->strings = (char**)malloc(1);
    self->add_string = private_cweb_add_string;
    self->set_value = private_cweb_set_value;
    self->merge_string_array = private_cweb_merge_string_array;
    self->represent= private_cweb_represent_string_array;
    self->free_string_array = private_cweb_free_string_array;
    self->find_position = private_cweb_find_position;
    return self;
}

int private_cweb_find_position(struct CwebStringArray *self,const char *string){
    for(int i = 0; i < self->size; i++){
        if(strcmp(self->strings[i], string) == 0){
            return i;
        }
    }
    return -1;
}
void private_cweb_set_value(struct CwebStringArray *self,int index,const char *value){
    if(index < self->size && index >= 0){
        int size = strlen(value);
        self->strings[index] = (char*)realloc(self->strings[index], size + 1);
        self->strings[index][size] = '\0';
        strcpy(self->strings[index], value);
    }
}
// Function prototypes
void private_cweb_add_string(struct CwebStringArray *self,const char *string){
    self->size++;
    self->strings =  (char**)realloc(self->strings, self->size * sizeof(char *));
    self->strings[self->size - 1] = (char*)malloc(strlen(string) + 1);
    self->strings[self->size - 1][strlen(string)] = '\0';
    strcpy(self->strings[self->size - 1], string);
}


void private_cweb_merge_string_array(struct CwebStringArray *self, struct CwebStringArray *other){
    for(int i = 0; i < other->size; i++){
        self->add_string(self, other->strings[i]);
    }
}


void private_cweb_represent_string_array(struct CwebStringArray *self){
    for(int i = 0; i < self->size; i++){
        printf("%s\n", self->strings[i]);
    }
}
void private_cweb_free_string_array(struct CwebStringArray *self){
    for(int i = 0; i < self->size; i++){
        free(self->strings[i]);
    }
    free(self->strings);
    free(self);
}
