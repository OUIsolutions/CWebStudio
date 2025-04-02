//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../../imports/imports.types.h"
//silver_chain_scope_end


struct CwebServer  newCwebSever(int port , CwebHttpResponse *(*request_handler)(CwebHttpRequest *request));

int CwebServer_start(CwebServer *self);
