#include "../../hydration/all.h"
#include "search_result.h"
#include "search_requirements.h"
#include "args.h"
#include "actions.h"

#ifndef PRIVATE_CWEB_HYDRATATION_BRIDGE_NAMESPACE_TYPES
#define PRIVATE_CWEB_HYDRATATION_BRIDGE_NAMESPACE_TYPES

typedef struct CWebHydrationBridgeNamespace{

    CWebHyDrationBridge * (*create_bridge)(CWebHyDration *self,const char *name,void (*callback)(CWebHyDrationBridge *));
    char *(*call)(CWebHyDrationBridge *self,const char *func_args,...);
    char *(*onclick)(CWebHyDrationBridge *self,const char *func_args,...);
    char *(*onfoccusout)(CWebHyDrationBridge *self,const char *func_args,...);
    bool (*has_errors)(CWebHyDrationBridge *self);
    CWebHyDrationBridge * (*get_child_bridge)(CWebHyDration *self,const char *name);
    CWebHyDrationBridge * (*get_brother_bridge)(CWebHyDrationBridge *self,const char *name);

}CWebHydrationBridgeNamespace;

#endif //PRIVATE_CWEB_HYDRATATION_HYDRATATION_NAMESPACE_TYPES
