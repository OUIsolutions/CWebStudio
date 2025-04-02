//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.macros.h"
//silver_chain_scope_end

typedef struct CwebStringArrayModule{
    CwebStringArray *(*newStringArray)();
    void (*set)( CwebStringArray *self,int index,const char *value);
    void (*add)( CwebStringArray *self,const char *string);
    void (*merge)(CwebStringArray *self, CwebStringArray *other);
    void (*represent)(CwebStringArray *self);
    int (*find)(CwebStringArray *self,const char *string);

    void (*free)(CwebStringArray *self);
}CwebStringArrayModule;

