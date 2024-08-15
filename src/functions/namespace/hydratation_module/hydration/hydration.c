
#include "../uniq.definitions_requirements.h"

CWebHydrationNamespace newCWebHydrationNamespace() {
    CWebHydrationNamespace self = {0};
    self.has_errors = CWebHyDrationBridge_has_errors;
    self.call = CWebHyDrationBridge_call;
    self.newCWebHyDration = newCWebHyDration;

    self.create_bridge = CWebHyDration_create_bridge;
    self.is_the_trigger = CWebHyDration_is_the_trigger;
    self.generate_response = CWebHydration_generate_response;
    self.create_script = CWebHyDration_create_script;
    self.requirements = newCWebHydrationRequirementsNamespace();
    self.response = newCWebHydrationResponseNamespace();
    self.args = newCWebHydrationArgsNamespace();
    self.content = newCWebHydrationContentNamespace();

    return self;
}
