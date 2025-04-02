//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../../imports/imports.globals.h"
//silver_chain_scope_end

CWebHydrationBridgeNamespace newCWebHydrationBridgetNamespace(){
    CWebHydrationBridgeNamespace self = {0};
    self.call = CWebHyDrationBridge_call;
    self.call_trigger = CWebHyDrationBridge_call_trigger;
    self.onclick =CWebHyDrationBridge_onclick;
    self.onfoccusout =CWebHyDrationBridge_onfoccusout;
    self.has_errors = CWebHyDrationBridge_has_errors;
    self.create_bridge = CWebHyDration_create_bridge;
    self.get_child_bridge = CWebHyDration_get_child_bridge;
    self.get_brother_bridge =CWebHyDrationBridge_get_brother_bridge;

    self.create_stack = CWebHyDrationBridge_create_stack;
    self.create_empty_stack = CWebHyDrationBridge_create_empty_stack;

    return self;
}
