

struct CwebHttpResponse{
    int status_code;
    struct CwebDict *headers;
    int content_size;
    unsigned char *content;
};

struct CwebHttpResponse *cweb_http_response_new();

void private_cweb_http_response_free(struct CwebHttpResponse *response);


void private_cweb_http_set_content(
    struct CwebHttpResponse *response, 
    unsigned char *content,
    int content_size
);

void private_cweb_http_add_header(
    struct CwebHttpResponse *response, 
    char *key, 
    char *value
);

