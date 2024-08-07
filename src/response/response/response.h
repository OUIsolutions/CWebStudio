


CwebHttpResponse *newCwebHttpResponse();


char *CwebHttpResponse_generate_response(CwebHttpResponse*self);



void CwebHttpResponse_set_content(
        CwebHttpResponse *self,
    unsigned char *content,
    int content_length
);


void CwebHttpResponse_add_header(
     CwebHttpResponse *self,
    const char *key, 
    const char *value
);

void CwebHttpResponse_free(struct CwebHttpResponse *self);

