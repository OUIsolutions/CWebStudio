//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../../imports/imports.dep_define.h"
//silver_chain_scope_end



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
    self.add_value_cookie_by_key = CWebHyDrationSearchRequirements_add_cookie_item;
    self.add_confirm = CWebHyDrationSearchRequirements_add_confirm;
    self.add_prompt = CWebHyDrationSearchRequirements_add_prompt;

    self.add_elements_by_id_setting_search_as_same_name =
        CWebHyDrationBridge_add_elements_by_id_setting_search_as_same_name;

    self.add_elements_by_id_setting_search_as_same_name_not_auto_converting =
        CWebHyDrationBridge_add_elements_by_id_setting_search_as_same_name_not_auto_converting;

    self.add_elements_by_class_name_setting_search_as_same_name =
        CWebHyDrationBridge_add_elements_by_class_name_setting_search_as_same_name;

    self.add_elements_by_class_name_setting_search_as_same_name_not_auto_converting =
        CWebHyDrationBridge_add_elements_by_class_name_setting_search_as_same_name_not_auto_converting;


    return self;
}
