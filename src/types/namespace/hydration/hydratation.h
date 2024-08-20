#include "../../hydration/all.h"
#include "search_result.h"
#include "search_requirements.h"
#include "search.h"
#include "args.h"
#include "actions.h"

#ifndef PRIVATE_CWEB_HYDRATATION_HYDRATATION_NAMESPACE_TYPES
#define PRIVATE_CWEB_HYDRATATION_HYDRATATION_NAMESPACE_TYPES

typedef struct CWebHydrationNamespace{

    char *(*call)(CWebHyDrationBridge *self,const char *func_args,...);

    char *(*call_trigger)(CWebHyDrationBridge *self,const char *trigger,const char *func_args);
    char *(*onclick)(CWebHyDrationBridge *self,const char *func_args,...);
    char *(*onfoccusout)(CWebHyDrationBridge *self,const char *func_args,...);
    CWebHyDrationBridge *(*newCWebHyDrationBridge)(
        const char *name,
        void (*callback)(CWebHyDrationBridge *),
        CWebHyDration *hydration
    );
    bool (*has_errors)(CWebHyDrationBridge *self);
    CWebHyDrationSearchRequirements * (*newSearchRequirements)(CWebHyDrationBridge *self, const char *name,...);
    CWebHyDration * (*newCWebHyDration)(CwebHttpRequest *request);
    CWebHyDrationBridge * (*create_bridge)(CWebHyDration *self,const char *name,void (*callback)(CWebHyDrationBridge *));
    CwebHttpResponse *(*formmat_error_response)(CWebHyDration *self);
    bool (*is_the_trigger)(CWebHyDration *self);
    CwebHttpResponse *(*generate_response)(CWebHyDration *self);
    char *(*create_script)(CWebHyDration *self);

    CWebHydrationActionsNamespace actions;
    CWebHydrationSearchRequirementsNamespace search_requirements;
    CWebHydrationSearchResultNamespace search_result;
}CWebHydrationNamespace;

#endif //PRIVATE_CWEB_HYDRATATION_HYDRATATION_NAMESPACE_TYPES
