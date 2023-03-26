

struct CwebHttpResponse{
    int status_code;
    struct CwebDict *headers;
    int content_length;
    bool is_binary;
    bool exist_content;
    unsigned char *content;
    void (*set_string_content)(struct CwebHttpResponse *response, const char *content, int content_length);
    void (*add_header)(struct CwebHttpResponse *response, char *key, char *value);
    char *(*generate_response)(struct CwebHttpResponse *response);
    void (*free)(struct CwebHttpResponse *response);
};

struct CwebHttpResponse *create_http_response();


char *private_cweb_generate_response(struct CwebHttpResponse*response);



void private_cweb_http_set_string_content(
    struct CwebHttpResponse *response, 
    const char *content,
    int content_length
);


void private_cweb_http_add_header(
    struct CwebHttpResponse *response, 
    char *key, 
    char *value
);

void private_cweb_http_response_free(struct CwebHttpResponse *response);

