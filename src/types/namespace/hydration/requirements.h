
#include "../../hydration/all.h"
#include "../response.h"

#ifndef PRIVATE_CWEB_HYDRATATION_REQUIREMENTS_NAMESPACE_TYPES
#define PRIVATE_CWEB_HYDRATATION_REQUIREMENTS_NAMESPACE_TYPES


typedef struct CWebHydrationRequirementsNamespace {



    void (*add_function)(CWebHyDrationBridge *self,const char *function,...);
    void (*add_elements_by_query_selector)(CWebHyDrationBridge *self,const char *search_name,const char *query_selector,...);
    void (*add_elements_by_query_selector_not_auto_converting)(CWebHyDrationBridge *self,const char *search_name,const char *query_selector,...);
    void (*add_elements_by_attribute)(CWebHyDrationBridge *self,const char *search_name,const char *attribute,const char*attribute_value,...);
    void (*add_elements_by_attribute_not_auto_converting)(CWebHyDrationBridge *self,const char *search_name,const char *attribute,const char*attribute_value,...);
    void (*add_elements_by_class_name)(CWebHyDrationBridge *self,const char *search_name,const char*class_value,...);
    void (*add_elements_by_class_name_not_auto_converting)(CWebHyDrationBridge *self,const char *search_name,const char*class_value,...);;
    void (*add_elements_by_id)(CWebHyDrationBridge *self,const char *search_name,const char*id_values,...);
    void (*add_elements_by_id_not_auto_converting)(CWebHyDrationBridge *self,const char *search_name,const char*id_values,...);
    void (*add_session_storage_item_not_converting)(CWebHyDrationBridge *self,const char *search_name,const char *name,...);
    void (*add_session_storage_item)(CWebHyDrationBridge *self,const char *search_name,const char *name,...);


}CWebHydrationRequirementsNamespace;
#endif
