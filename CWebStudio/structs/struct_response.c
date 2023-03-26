

struct CwebHttpResponse *create_http_response(){
    struct CwebHttpResponse *response = (struct CwebHttpResponse *)malloc(
        sizeof(struct CwebHttpResponse)
    );
    response->status_code = 200;
    response->headers = cweb_create_dict();
    response->content_length = 0;
    response->content = NULL;
    response->free = private_cweb_http_response_free;
    response->set_content = private_cweb_http_set_content;
    response->add_header = private_cweb_http_add_header;
    return response;
}

void private_cweb_http_response_free(struct CwebHttpResponse *response){
    response->headers->free(response->headers);
    free(response->content);
    free(response);
}

void private_cweb_http_set_content(struct CwebHttpResponse *response, unsigned char *content,int content_length){
    response->content = (unsigned char*)malloc(content_length);
    memcpy(response->content, content, content_length);
    response->content_length = content_length;
}

void private_cweb_http_add_header(struct CwebHttpResponse *response, char *key, char *value){
    response->headers->set(response->headers, key, value);
}