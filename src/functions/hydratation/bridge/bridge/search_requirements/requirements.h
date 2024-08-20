


#include "../uniq.declaration_requirements.h"

void CWebHyDrationBridge_add_function(CWebHyDrationBridge *self,const char *function,...);

void private_CWebHyDrationBridge_add_elements_by_query_selector(CWebHyDrationBridge *self,const char *search_name,const char *query_selector,bool auto_convert);

void CWebHyDrationBridge_add_elements_by_query_selector(CWebHyDrationBridge *self,const char *search_name,const char *query_selector,...);

void CWebHyDrationBridge_add_elements_by_query_selector_not_auto_converting(CWebHyDrationBridge *self,const char *search_name,const char *query_selector,...);

void CWebHyDrationBridge_add_elements_by_attribute(CWebHyDrationBridge *self,const char *search_name,const char *attribute,const char*attribute_value,...);

void CWebHyDrationBridge_add_elements_by_attribute_not_auto_converting(CWebHyDrationBridge *self,const char *search_name,const char *attribute,const char*attribute_value,...);

void CWebHyDrationBridge_add_elements_by_class_name(CWebHyDrationBridge *self,const char *search_name,const char*class_value,...);

void CWebHyDrationBridge_add_elements_by_class_name_not_auto_converting(CWebHyDrationBridge *self,const char *search_name,const char*class_value,...);;

void CWebHyDrationBridge_add_elements_by_id(CWebHyDrationBridge *self,const char *search_name,const char*id_values,...);

void CWebHyDrationBridge_add_elements_by_id_not_auto_converting(CWebHyDrationBridge *self,const char *search_name,const char*id_values,...);

void CWebHyDrationBridge_add_session_storage_item_not_converting(CWebHyDrationBridge *self,const char *search_name,const char *name,...);

void CWebHyDrationBridge_add_session_storage_item(CWebHyDrationBridge *self,const char *search_name,const char *name,...);
