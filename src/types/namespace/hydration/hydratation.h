#include "../../hydration/all.h"

#include "requirements.h"
#include "search.h"
#include "args.h"
#include "response_namespace.h"

#ifndef PRIVATE_CWEB_HYDRATATION_HYDRATATION_NAMESPACE_TYPES
#define PRIVATE_CWEB_HYDRATATION_HYDRATATION_NAMESPACE_TYPES

typedef struct CWebHydrationNamespace{

    bool (*has_errors)(CWebHyDrationBridge *self);
    char *(*call)(CWebHyDrationBridge *self,const char *trigger,const char *func_args,...);

    CWebHyDration * (*newCWebHyDration)(CwebHttpRequest *request);
    CWebHyDrationBridge * (*create_bridge)(CWebHyDration *self,const char *name,void (*callback)(CWebHyDrationBridge *));
    bool (*is_the_trigger)(CWebHyDration *self);
    CwebHttpResponse *(*generate_response)(CWebHyDration *self);
    char *(*create_script)(CWebHyDration *self);
    CWebHydrationRequirementsNamespace requirements;
    CWebHydrationResponseNamespace response;
    CWebHydrationArgsNamespace args;
    CWebHydrationContentNamespace search;

}CWebHydrationNamespace;

#endif //PRIVATE_CWEB_HYDRATATION_HYDRATATION_NAMESPACE_TYPES
