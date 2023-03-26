

struct CwebHttpResponse{
    int status_code;
    struct CwebDict *headers;
    int content_length;
    bool exist_content;
    unsigned char *content;
    void (*set_content)(struct CwebHttpResponse *response, unsigned char *content, int content_length);
    void (*add_header)(struct CwebHttpResponse *response,const char *key,const  char *value);
    char *(*generate_response)(struct CwebHttpResponse *response);
    void (*free)(struct CwebHttpResponse *response);
};

struct CwebHttpResponse *create_http_response();


char *private_cweb_generate_response(struct CwebHttpResponse*self);



void private_cweb_http_set_content(
    struct CwebHttpResponse *self, 
    unsigned char *content,
    int content_length
);


void private_cweb_http_add_header(
    struct CwebHttpResponse *self, 
    const char *key, 
    const char *value
);

void private_cweb_http_response_free(struct CwebHttpResponse *self);

