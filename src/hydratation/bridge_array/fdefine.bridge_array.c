//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dep_define.h"
//silver_chain_scope_end

privateCWebHyDrationBridgeArray * private_new_privateCWebHyDrationBridgeArray() {
    privateCWebHyDrationBridgeArray *self = (privateCWebHyDrationBridgeArray*)malloc(sizeof(privateCWebHyDrationBridgeArray));
    *self = (privateCWebHyDrationBridgeArray){0};
    self->elments = (CWebHyDrationBridge**)malloc(0);
    return  self;
}

void privateCWebHyDrationBridgeArray_append(privateCWebHyDrationBridgeArray *self,CWebHyDrationBridge *element) {
    self->elments = (CWebHyDrationBridge**)realloc(self->elments, (self->size +1 )* sizeof(CWebHyDrationBridge*));
    self->elments[self->size] = element;
    self->size+=1;
}

void privateCWebHyDrationBridgeArray_free(privateCWebHyDrationBridgeArray *self) {
    for(int i = 0; i  < self->size;i++) {
        private_CWebHyDrationBridge_free(self->elments[i]);
    }
    free(self->elments);
    free(self);
}
