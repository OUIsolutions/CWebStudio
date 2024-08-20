
#include "../uniq.definitions_requirements.h"

CWebHydrationSearchRequirementsNamespace newCWebHydrationSearchRequirementsNamespace(){
    CWebHydrationSearchRequirementsNamespace self = {0};


    self.newSearchRequirements = CWebHyDrationBridge_newSearchRequirements;
    self.add_function = CWebHyDrationSearchRequirements_add_function;
    self.add_elements_by_query_selector = CWebHyDrationSearchRequirements_add_elements_by_query_selector;
    self.add_elements_by_query_selector_not_auto_converting = CWebHyDrationSearchRequirements_add_elements_by_query_selector_not_auto_converting;
    self.add_elements_by_attribute = CWebHyDrationSearchRequirements_add_elements_by_attribute;
    self.add_elements_by_attribute_not_auto_converting = CWebHyDrationSearchRequirements_add_elements_by_attribute_not_auto_converting;
    self.add_elements_by_class_name = CWebHyDrationSearchRequirements_add_elements_by_class_name;
    self.add_elements_by_class_name_not_auto_converting =CWebHyDrationSearchRequirements_add_elements_by_class_name_not_auto_converting;
    self.add_elements_by_id = CWebHyDrationSearchRequirements_add_elements_by_id;
    self.add_elements_by_id_not_auto_converting = CWebHyDrationSearchRequirements_add_elements_by_id_not_auto_converting;
    self.add_session_storage_item_not_converting = CWebHyDrationSearchRequirements_add_elements_by_id_not_auto_converting;
    self.add_session_storage_item = CWebHyDrationSearchRequirements_add_session_storage_item;

    return self;
}
