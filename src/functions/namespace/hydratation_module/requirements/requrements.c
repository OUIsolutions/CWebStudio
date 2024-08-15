
#include "../uniq.definitions_requirements.h"

CWebHydrationRequirementsNamespace newCWebHydrationRequirementsNamespace(){
    CWebHydrationRequirementsNamespace self = {0};
    self.add_required_function = CWebHyDrationBridge_add_required_function;
    self.add_required_text_by_id = CWebHyDrationBridge_add_required_text_by_id;
    self.add_required_text_number_by_id = CWebHyDrationBridge_add_required_text_number_by_id;
    self.add_required_input_by_id = CWebHyDrationBridge_add_required_input_by_id;
    self.add_required_input_number_by_id = CWebHyDrationBridge_add_required_text_number_by_id;
    return self;
}
