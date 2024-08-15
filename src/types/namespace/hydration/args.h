
#include "../../hydration/all.h"
#include "../response.h"

#ifndef PRIVATE_CWEB_HYDRATATION_ARGS_NAMESPACE_TYPES
#define PRIVATE_CWEB_HYDRATATION_ARGS_NAMESPACE_TYPES


typedef struct CWebHydrationArgsNamespace {

    double  (*read_double)(CWebHyDrationBridge *self,int index);
    long  (*read_long)(CWebHyDrationBridge *self,int index);
    bool  (*read_bool)(CWebHyDrationBridge *self,int index);
    char* (*read_str)(CWebHyDrationBridge *self,int index);

}CWebHydrationArgsNamespace;
#endif
