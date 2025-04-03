//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dep_define.h"
//silver_chain_scope_end

CwebNamespace newCwebNamespace(){
    CwebNamespace self = {0};
    self.dict = newCwebDictModule();
    self.request = newCwebRequestModule();
    self.response = newCwebHttpResponseModule();
    self.server = newCwebServerModule();
    self.string_array = newCwebStringArrayModule();
    self.hydration = newCWebHydrationNamespace();
    return self;
}

