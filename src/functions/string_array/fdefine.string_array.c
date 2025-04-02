//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.globals.h"
//silver_chain_scope_end


struct CwebStringArray * newCwebStringArray(){
    struct CwebStringArray *self = (struct CwebStringArray*)malloc(sizeof(struct CwebStringArray));
    self->size = 0;

    self->strings = (char**)malloc(1);

    return self;
}

int CwebStringArray_find(struct CwebStringArray *self, const char *string){
    for(int i = 0; i < self->size; i++){
        if(strcmp(self->strings[i], string) == 0){
            return i;
        }
    }
    return -1;
}
void CwebStringArray_set(struct CwebStringArray *self, int index, const char *value){
    if(index < self->size && index >= 0){
        int size = strlen(value);
        self->strings[index] = (char*)realloc(self->strings[index], size + 1);
        self->strings[index][size] = '\0';
        strcpy(self->strings[index], value);
    }
}

// Function prototypes
void CwebStringArray_add(struct CwebStringArray *self, const char *string){
    self->strings =  (char**)realloc(self->strings, (self->size +1) * sizeof(char *));
    self->strings[self->size] = strdup(string);
    self->size+=1;
}

void CwebStringArray_add_getting_ownership(struct CwebStringArray *self,  char *string){
    self->strings =  (char**)realloc(self->strings, (self->size +1) * sizeof(char *));
    self->strings[self->size] = string;
    self->size+=1;
}


void CwebStringArray_merge(struct CwebStringArray *self, struct CwebStringArray *other){
    for(int i = 0; i < other->size; i++){
        CwebStringArray_add(self, other->strings[i]);
    }
}


void CwebStringArray_represent(struct CwebStringArray *self){
    for(int i = 0; i < self->size; i++){
        printf("%s\n", self->strings[i]);
    }
}
void CwebStringArray_free(struct CwebStringArray *self){
    for(int i = 0; i < self->size; i++){
        free(self->strings[i]);
    }
    free(self->strings);
    free(self);
}
