//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.dep_define.h"
//silver_chain_scope_end
CwebKeyVal* newCwebKeyVal(const char *key, const  char *value){
     CwebKeyVal *self = (struct CwebKeyVal*)malloc(sizeof(struct CwebKeyVal));
    self->key = (char*)malloc(strlen(key)+1);
    strcpy(self->key,key);
    self->value = (char*)malloc(strlen(value)+1);
    strcpy(self->value,value);
    return self;
}

void CwebKeyVal_represent( CwebKeyVal *self){
    printf("%s : %s\n",self->key,self->value);
}

void CwebKeyVal_free( CwebKeyVal *self){
    free(self->key);
    free(self->value);
    free(self);
}