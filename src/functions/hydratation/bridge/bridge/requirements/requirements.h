


#include "../uniq.declaration_requirements.h"

void CWebHyDrationBridge_add_required_function(CWebHyDrationBridge *self,const char *function,...);

void private_CWebHyDrationBridge_add_required_elements_by_query_selector(CWebHyDrationBridge *self,const char *key_name,const char *query_selector,bool convert_to_number);

void CWebHyDrationBridge_add_required_elements_by_query_selector(CWebHyDrationBridge *self,const char *key_name,const char *query_selector,...);

void CWebHyDrationBridge_add_required_elements_by_query_selector_converting_to_number(CWebHyDrationBridge *self,const char *key_name,const char *query_selector,...);

void CWebHyDrationBridge_add_required_elements_by_tag_name(CWebHyDrationBridge *self,const char *tag_name,const char*tag_value);

void CWebHyDrationBridge_add_required_elements_by_class_name(CWebHyDrationBridge *self,const char*class_value);

void CWebHyDrationBridge_add_required_elements_by_id(CWebHyDrationBridge *self,const char*id_values);
