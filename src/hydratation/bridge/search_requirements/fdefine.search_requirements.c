
void CWebHyDrationBridge_add_elements_by_id_setting_search_as_same_name(
    CWebHyDrationBridge *self, const char *id
){
    CWebHyDrationSearchRequirements * search =
    CWebHyDrationBridge_newSearchRequirements(self,id);
    CWebHyDrationSearchRequirements_add_elements_by_id(search, id);

}


void CWebHyDrationBridge_add_elements_by_id_setting_search_as_same_name_not_auto_converting(
    CWebHyDrationBridge *self, const char *id
){
    CWebHyDrationSearchRequirements * search =
    CWebHyDrationBridge_newSearchRequirements(self,id);
    CWebHyDrationSearchRequirements_add_elements_by_id_not_auto_converting(search, id);
}

void CWebHyDrationBridge_add_elements_by_class_name_setting_search_as_same_name(
    CWebHyDrationBridge *self, const char *class_name
){
    CWebHyDrationSearchRequirements * search =
    CWebHyDrationBridge_newSearchRequirements(self,class_name);
    CWebHyDrationSearchRequirements_add_elements_by_class_name(search, class_name);

}


void CWebHyDrationBridge_add_elements_by_class_name_setting_search_as_same_name_not_auto_converting(
    CWebHyDrationBridge *self, const char *class_name
){
    CWebHyDrationSearchRequirements * search =
    CWebHyDrationBridge_newSearchRequirements(self,class_name);
    CWebHyDrationSearchRequirements_add_elements_by_class_name_not_auto_converting(search, class_name);
}
