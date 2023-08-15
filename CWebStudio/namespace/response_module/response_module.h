

typedef struct CwebHttpResponseModule{
    void (*set_content)(CwebHttpResponse *response, unsigned char *content, int content_length);
    void (*add_header)(CwebHttpResponse *response,const char *key,const  char *value);
    char *(*generate_response)(CwebHttpResponse *response);
    void (*free)(CwebHttpResponse *response);

}CwebHttpResponseModule;

CwebHttpResponseModule newCwebHttpResponseModule();