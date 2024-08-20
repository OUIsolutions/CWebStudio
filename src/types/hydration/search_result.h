#include "../request.h"
#include "bridget.h"

#ifdef  PRIVATE_CWEB_HYDRATION_SEARCH_RESULT_TYPE
#define PRIVATE_CWEB_HYDRATION_SEARCH_RESULT_TYPE

typedef struct{
    CWebCWebHyDrationBridge *bridge;
    cJSON *elements;
} CWebCWebHyDrationSearchResult;

#endif
