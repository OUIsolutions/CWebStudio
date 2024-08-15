
#include "../../hydration/all.h"
#include "../response.h"

#ifndef PRIVATE_CWEB_HYDRATATION_RESPONSE_NAMESPACE_TYPES
#define PRIVATE_CWEB_HYDRATATION_RESPONSE_NAMESPACE_TYPES


typedef struct CWebHydrationResponseNamespace {
    void (*alert)(CWebHyDrationBridge *self,const char *menssage,...);

    void (*execute_script)(CWebHyDrationBridge *self,const char *code,...);

    void (*replace_element_by_id)(CWebHyDrationBridge *self,const char *id,const char *code,...);

    void (*destroy_by_id)(CWebHyDrationBridge *self,const char * id);

}CWebHydrationResponseNamespace;

#endif
