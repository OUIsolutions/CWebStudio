
#include "string_array.h"
#include "request.h"

#ifndef PRIVATE_CWEB_HYDRATATION_BRIDGET_BRIDGET_TYPES
#define PRIVATE_CWEB_HYDRATATION_BRIDGET_BRIDGET_TYPES


typedef struct  CWebHyDrationBridge {
    char *route;
    char *name;
    char *error;
    char *error_key;
    int error_type;
    CwebStringArray *callbacks;
    CwebStringArray *garbage;
    CwebHttpRequest *request;
    cJSON *response;
    int max_body_size;

    cJSON *body;
}CWebHyDrationBridge;

#endif //PRIVATE_CWEB_HYDRATATION_BRIDGET_BRIDGET_TYPES