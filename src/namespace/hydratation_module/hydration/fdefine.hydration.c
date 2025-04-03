//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../../imports/imports.dep_define.h"
//silver_chain_scope_end


CWebHydrationNamespace newCWebHydrationNamespace() {
    CWebHydrationNamespace self = {0};
    self.newCWebHyDration = newCWebHyDration;
    self.is_the_trigger = CWebHyDration_is_the_trigger;
    self.create_script = CWebHyDration_create_script;
    self.create_stack = CWebHyDration_create_stack;
    self.create_empty_stack = CWebHyDration_create_empty_stack;
    self.generate_response = CWebHydration_generate_response;

    self.bridge = newCWebHydrationBridgetNamespace();
    self.actions =newCWebHydrationActionsNamespace();
    self.search_requirements =newCWebHydrationSearchRequirementsNamespace();
    self.search_result = newCWebHydrationSearchResultNamespace();
    self.args = newCWebHydrationArgsNamespace();
    return self;
}
