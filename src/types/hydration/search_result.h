#include "../request.h"
#include "bridge.h"

#ifndef  PRIVATE_CWEB_HYDRATION_SEARCH_RESULT_TYPE
#define PRIVATE_CWEB_HYDRATION_SEARCH_RESULT_TYPE

typedef struct{
    CWebHyDrationBridge *bridge;
    cJSON *elements;
} CWebHyDrationSearchResult;

#endif
