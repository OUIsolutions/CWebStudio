#ifndef PRIVATE_CWEB_HTTP_RESPONSE_TYPES
#define PRIVATE_CWEB_HTTP_RESPONSE_TYPES

typedef struct CwebHttpResponse{
    int status_code;
    struct CwebDict *headers;
    int content_length;
    bool exist_content;
    unsigned char *content;

}CwebHttpResponse;

#endif // PRIVATE_CWEB_HTTP_RESPONSE_TYPES