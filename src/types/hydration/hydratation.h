
#include "../request.h"
#include "bridge_array.h"

#ifndef PRIVATE_CWEB_HYDRATATION_HYDRATATION_TYPES
#define PRIVATE_CWEB_HYDRATATION_HYDRATATION_TYPES

typedef struct CWebHyDration {
    CwebHttpRequest *request;
   const  char *error_bridge_name;
    char *error_msg;
    cJSON *response;
    cJSON *args;
    cJSON *content;

    int error_code;
    CTextStack *script_text;
    long max_content_size;
    privateCWebHyDrationBridgeArray *all_bridges;

}CWebHyDration;

#endif //PRIVATE_CWEB_HYDRATATION_HYDRATATION_TYPES
