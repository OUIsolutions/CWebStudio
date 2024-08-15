
#include "../../hydration/all.h"
#include "../response.h"

#ifndef PRIVATE_CWEB_HYDRATATION_REQUIREMENTS_NAMESPACE_TYPES
#define PRIVATE_CWEB_HYDRATATION_REQUIREMENTS_NAMESPACE_TYPES


typedef struct CWebHydrationRequirementsNamespace {


    void (*add_required_function)(CWebHyDrationBridge *self,const char *function,...);
    void (*add_required_text_by_id)(CWebHyDrationBridge *self, const char * id);
    void (*add_required_text_number_by_id)(CWebHyDrationBridge *self, const char * id);
    void (*add_required_input_by_id)(CWebHyDrationBridge *self, const char * id);
    void (*add_required_input_number_by_id)(CWebHyDrationBridge *self, const char * id);


}CWebHydrationRequirementsNamespace;
#endif
