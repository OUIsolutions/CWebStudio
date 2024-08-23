
#include "../../hydration/all.h"
#include "../response.h"

#ifndef PRIVATE_CWEB_HYDRATATION_RESPONSE_NAMESPACE_TYPES
#define PRIVATE_CWEB_HYDRATATION_RESPONSE_NAMESPACE_TYPES


typedef struct CWebHydrationResponseNamespace {

    void (*hide_element_by_id)(CWebHyDrationBridge *self,const char *id);
    void (*unhide_element_by_id)(CWebHyDrationBridge *self,const char *id);

    void (*set_session_storage_data)(CWebHyDrationBridge *self,const char*key, const char *value,...);
    void (*alert)(CWebHyDrationBridge *self,const char *menssage,...);
    void (*execute_script)(CWebHyDrationBridge *self,const char *code,...);
    void (*replace_element_by_id)(CWebHyDrationBridge *self,const char *id, const char *code,...);
    void (*destroy_by_id)(CWebHyDrationBridge *self,const char * id);
    void (*redirect)(CWebHyDrationBridge *self, const char *url);

}CWebHydrationActionsNamespace;

#endif
