//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.typesD.h"
//silver_chain_scope_end


typedef struct CWebHydrationSearchRequirementsNamespace {




    CWebHyDrationSearchRequirements * (*newSearchRequirements)(CWebHyDrationBridge *self, const char *name,...);

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

    void (*add_elements_by_id_setting_search_as_same_name)(
        CWebHyDrationBridge *self, const char *id
    );


    void (*add_elements_by_id_setting_search_as_same_name_not_auto_converting)(
        CWebHyDrationBridge *self, const char *id
    );


    void (*add_elements_by_class_name_setting_search_as_same_name)(
        CWebHyDrationBridge *self, const char *class_name
    );

    void (*add_elements_by_class_name_setting_search_as_same_name_not_auto_converting)(
        CWebHyDrationBridge *self, const char *class_name
    );

    void (*add_session_storage_item)(
        CWebHyDrationSearchRequirements *self,
        const char *name,
        ...
    );

    void (*add_value_cookie_by_key)(CWebHyDrationSearchRequirements *self, const char *key);
    void (*add_confirm)(CWebHyDrationSearchRequirements *self, const char*message, ...);
    void (*add_prompt)(CWebHyDrationSearchRequirements *self, const char *message, ...);

}CWebHydrationSearchRequirementsNamespace;
