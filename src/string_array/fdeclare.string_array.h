//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.typesD.h"
//silver_chain_scope_end

CwebStringArray * newCwebStringArray();

int  CwebStringArray_find(struct CwebStringArray *self, const char *string);
void CwebStringArray_add(struct CwebStringArray *self, const char *string);

void CwebStringArray_add_getting_ownership(struct CwebStringArray *self, char *string);

void CwebStringArray_merge(struct CwebStringArray *self, struct CwebStringArray *other);
void CwebStringArray_represent(struct CwebStringArray *self);
void CwebStringArray_free(struct CwebStringArray *self);
void CwebStringArray_set(struct CwebStringArray *self, int index, const char *value);
