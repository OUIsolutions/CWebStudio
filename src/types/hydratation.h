
#include "request.h"
#include "bridget_array.h"

#ifndef PRIVATE_CWEB_HYDRATATION_HYDRATATION_TYPES
#define PRIVATE_CWEB_HYDRATATION_HYDRATATION_TYPES

typedef struct CWebHyDration {
    CwebHttpRequest *request;
    CTextStack *script_text;
    privateCWebHyDrationBridgeArray *all_bridges;

}CWebHyDration;

#endif //PRIVATE_CWEB_HYDRATATION_HYDRATATION_TYPES