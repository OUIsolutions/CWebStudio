
#include "../../hydration/all.h"
#include "../response.h"

#ifndef PRIVATE_CWEB_HYDRATATION_REQUIREMENTS_NAMESPACE_TYPES
#define PRIVATE_CWEB_HYDRATATION_REQUIREMENTS_NAMESPACE_TYPES


typedef struct CWebHydrationSearchRequirementsNamespace {





    void (*add_function)(CWebHyDrationSearchRequirements *self,const char *function,...);
    void (*add_elements_by_query_selector)(
        CWebHyDrationSearchRequirements *self,
        const char *query_selector,
        ...
    );
    void (*add_elements_by_query_selector_not_auto_converting)(
        CWebHyDrationSearchRequirements *self,
        const char *query_selector,
        ...
    );
    void (*add_elements_by_attribute)(
        CWebHyDrationSearchRequirements *self,
       const char *attribute,
       const char*attribute_value,
       ...
    );
    void (*add_elements_by_attribute_not_auto_converting)(
        CWebHyDrationSearchRequirements *self,
        const char *attribute,
        const char*attribute_value,
        ...
    );

    void (*add_elements_by_class_name)(
        CWebHyDrationSearchRequirements *self,
        const char*class_value,
        ...
    );

    void (*add_elements_by_class_name_not_auto_converting)(
        CWebHyDrationSearchRequirements *self,
        const char*class_value,...
    );

    void (*add_elements_by_id)(
        CWebHyDrationSearchRequirements *self,
        const char*id_values,
        ...
    );

    void (*add_elements_by_id_not_auto_converting)(
        CWebHyDrationSearchRequirements *self,
        const char*id_values,
        ...
    );

    void (*add_session_storage_item_not_converting)(
        CWebHyDrationSearchRequirements *self,
        const char *name,
        ...
    );


    void (*add_session_storage_item)(
        CWebHyDrationSearchRequirements *self,
        const char *name,
        ...
    );


}CWebHydrationSearchRequirementsNamespace;
#endif
