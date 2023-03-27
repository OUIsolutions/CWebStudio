

struct CwebHttpRequest{
    char *route;
    struct CwebDict *params;
    struct CwebDict *headers;
    char *method;
    unsigned char *content;
    void (*free)(struct CwebHttpRequest *request);
    void (*represent)(struct CwebHttpRequest *request);
};


struct CwebHttpRequest *private_cwe_create_http_request(char *raw_entrys);
void private_cwe_free_http_request(struct CwebHttpRequest *request);
void private_cwe_represent_http_request(struct CwebHttpRequest *request);
