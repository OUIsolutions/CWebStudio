#include "dict.h"
#include "uniq.tipes_requirements.h"

#ifndef PRIVATE_CWEB_HTTP_REQUEST_TYPES
#define PRIVATE_CWEB_HTTP_REQUEST_TYPES

typedef struct CwebHttpRequest{

    char *url;
    int socket;
    char *route;
    char *method;
    char *client_ip;
    int content_error;
    CwebDict *params;
    CwebDict *headers;
    int content_length;
    unsigned char *content;
    cJSON *json;

}CwebHttpRequest;

#endif //PRIVATE_CWEB_HTTP_REQUEST_TYPES