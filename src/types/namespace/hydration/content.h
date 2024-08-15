
#include "../../hydration/all.h"
#include "../response.h"

#ifndef PRIVATE_CWEB_HYDRATATION_RESPONSE_NAMESPACE_TYPES
#define PRIVATE_CWEB_HYDRATATION_RESPONSE_NAMESPACE_TYPES


typedef struct CWebHydrationContentNamespace {

    double (*read_double)(CWebHyDrationBridge *self,const char *key,...);
    long  (*read_long)(CWebHyDrationBridge *self,const char *key,...);
    bool  (*read_bool)(CWebHyDrationBridge *self,const char *key,...);
    char*  (*read_str)(CWebHyDrationBridge *self,const char *key,...);

}CWebHydrationContentNamespace;
#endif
