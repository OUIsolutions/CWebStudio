//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.types.h"
//silver_chain_scope_end




void private_CwebHttpRequest_interpret_query_params(struct CwebHttpRequest *self, const char *query_params);


void CwebHttpRequest_set_url(struct CwebHttpRequest *self, const char *url);

int private_CwebHttpRequest_interpret_first_line(struct CwebHttpRequest *self, char *first_line);


int private_CwebHttpRequest_interpret_headders(struct CwebHttpRequest *self, struct CwebStringArray *line_headers);




int  CwebHttpRequest_parse_http_request(struct CwebHttpRequest *self);
