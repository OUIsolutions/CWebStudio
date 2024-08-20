
#include "../../hydration/all.h"
#include "../response.h"

#ifndef PRIVATE_CWEB_HYDRATATION_ARGS_NAMESPACE_TYPES
#define PRIVATE_CWEB_HYDRATATION_ARGS_NAMESPACE_TYPES


typedef struct CWebHydrationArgsNamespace {


    int   (*get_args_size)(CWebHyDrationBridge *self,int index);
    bool   (*is_arg_number)(CWebHyDrationBridge *self,int index);
    bool   (*is_arg_bool)(CWebHyDrationBridge *self,int index);
    bool   (*is_arg_string)(CWebHyDrationBridge *self,int index);
    cJSON *(*get_arg_index)(CWebHyDrationBridge *self,int index,cJSON_bool (*callback_verifier)(const cJSON * const item),const char *expected_type);
    double  (*get_double_arg)(CWebHyDrationBridge *self,int index);
    long  (*get_long_arg)(CWebHyDrationBridge *self,int index);
    bool  (*get_bool_arg)(CWebHyDrationBridge *self,int index);
    char* (*get_str_arg)(CWebHyDrationBridge *self,int index);

}CWebHydrationArgsNamespace;
#endif
