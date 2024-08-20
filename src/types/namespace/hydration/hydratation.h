#include "../../hydration/all.h"
#include "bridge.h"

#ifndef PRIVATE_CWEB_HYDRATATION_HYDRATATION_NAMESPACE_TYPES
#define PRIVATE_CWEB_HYDRATATION_HYDRATATION_NAMESPACE_TYPES

typedef struct CWebHydrationNamespace{

    CWebHyDrationBridge * (*create_bridge)(CWebHyDration *self,const char *name,void (*callback)(CWebHyDrationBridge *));
    CwebHttpResponse *(*formmat_error_response)(CWebHyDration *self);
    bool (*is_the_trigger)(CWebHyDration *self);
    CwebHttpResponse *(*generate_response)(CWebHyDration *self);
    char *(*create_script)(CWebHyDration *self);
    CWebHydrationBridgeNamespace bridge;
    CWebHydrationActionsNamespace actions;
    CWebHydrationSearchRequirementsNamespace search_requirements;
    CWebHydrationSearchResultNamespace search_result;
}CWebHydrationNamespace;

#endif //PRIVATE_CWEB_HYDRATATION_HYDRATATION_NAMESPACE_TYPES
