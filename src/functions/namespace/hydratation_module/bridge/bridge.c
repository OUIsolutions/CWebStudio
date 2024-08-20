#include "../uniq.definitions_requirements.h"

CWebHydrationBridgeNamespace newCWebHydrationBridgetNamespace(){
    CWebHydrationBridgeNamespace self = {0};
    self.call = CWebHyDrationBridge_call;
    self.onclick =CWebHyDrationBridge_onclick;
    self.onfoccusout =CWebHyDrationBridge_onfoccusout;
    self.has_errors = CWebHyDrationBridge_has_errors;
    self.create_bridge = CWebHyDration_create_bridge;

    return self;
}
