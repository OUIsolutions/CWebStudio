
#include "../uniq.definitions_requirements.h"

CWebHydrationNamespace newCWebHydrationNamespace() {
    CWebHydrationNamespace self = {0};
    self.newCWebHyDration = newCWebHyDration;
    self.is_the_trigger = CWebHyDration_is_the_trigger;
    self.create_script = CWebHyDration_create_script;
    self.bridge = newCWebHydrationBridgetNamespace();
    self.actions =newCWebHydrationActionsNamespace();
    self.search_requirements =newCWebHydrationSearchRequirementsNamespace();
    self.search_result = newCWebHydrationSearchResultNamespace();
    self.args = newCWebHydrationArgsNamespace();
    return self;
}
