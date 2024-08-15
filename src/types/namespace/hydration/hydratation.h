#include "../../hydration/all.h"

#include "requirements.h"
#include "content.h"
#include "args.h"
#include "response_namespace.h"

#ifndef PRIVATE_CWEB_HYDRATATION_HYDRATATION_NAMESPACE_TYPES
#define PRIVATE_CWEB_HYDRATATION_HYDRATATION_NAMESPACE_TYPES

typedef struct CWebHydrationNamespace{

    CWebHyDration * (*newCWebHyDration)(CwebHttpRequest *request);
    CWebHyDrationBridge * (*create_bridge)(CWebHyDration *self,const char *name,void (*callback)(CWebHyDrationBridge *));
    bool (*the_trigger)(CWebHyDration *self);
    CwebHttpResponse *(*generate_response)(CWebHyDration *self);
    char *(*create_script)(CWebHyDration *self);
    CWebHydrationRequirementsNamespace requirements;
    CWebHydrationResponseNamespace response;
    CWebHydrationArgsNamespace args;
    CWebHydrationContentNamespace content;

}CWebHydrationNamespace;

#endif //PRIVATE_CWEB_HYDRATATION_HYDRATATION_NAMESPACE_TYPES
