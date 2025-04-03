//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.typesD.h"
//silver_chain_scope_end



struct CwebHttpResponse *newCwebHttpResponse();

char *CwebHttpResponse_generate_response(struct CwebHttpResponse*self);


void CwebHttpResponse_free(struct CwebHttpResponse *self);

void CwebHttpResponse_set_content(CwebHttpResponse *self, unsigned char *content, int content_length);
void CwebHttpResponse_add_header(CwebHttpResponse *self, const char *key, const  char *value);
