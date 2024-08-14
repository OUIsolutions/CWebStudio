
#include "../string_array.h"
#include "../request.h"

#ifndef PRIVATE_CWEB_HYDRATATION_BRIDGET_BRIDGET_TYPES
#define PRIVATE_CWEB_HYDRATATION_BRIDGET_BRIDGET_TYPES


typedef struct  CWebHyDrationBridge {

    const char *name;
    char *error;
    char *error_key;
    int error_type;
    void *extra_args;
    CwebStringArray *callbacks;
    CwebStringArray *garbage;
    CwebHttpRequest *request;
    cJSON *response;
    void  (*callback)(CWebHyDrationBridge *bridge);

    int max_body_size;
    cJSON *args;
    cJSON *body;

}CWebHyDrationBridge;

#endif //PRIVATE_CWEB_HYDRATATION_BRIDGET_BRIDGET_TYPES
