//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../../../imports/imports.globals.h"
//silver_chain_scope_end



privateCwebRecursionElement * newPrivateCwebRecursionElement(const char *file, const char *included){
    privateCwebRecursionElement *self = (privateCwebRecursionElement*) malloc(sizeof (privateCwebRecursionElement));
    self->file = strdup(file);
    self->included = strdup(included);
    return self;
}
void PrivateCwebRecursionElement_represent(privateCwebRecursionElement *self){
    printf("file: (%s) | included: (%s)\n",self->file,self->included);
}

void PrivateCwebRecursionElement_free(privateCwebRecursionElement *self){
    free(self->file);
    free(self->included);
    free(self);
}
