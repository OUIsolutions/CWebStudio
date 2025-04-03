//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.typesD.h"
//silver_chain_scope_end




CWebHyDrationSearchRequirements * private_newCWebHyDrationSearchRequirements_getting_name_ownership(
    CWebHyDrationBridge *bridge, char *name
);


void private_CWebHyDrationSearchRequirements_free(CWebHyDrationSearchRequirements *self);


void CWebHyDrationSearchRequirements_add_function(CWebHyDrationSearchRequirements *self,const char *function,...);


void private_CWebHyDrationSearchRequirements_add_elements_by_query_selector(
    CWebHyDrationSearchRequirements *self,
    const char *query_selector,bool auto_convert
);


void CWebHyDrationSearchRequirements_add_elements_by_query_selector(
    CWebHyDrationSearchRequirements *self,
    const char *query_selector,
    ...
);




void CWebHyDrationSearchRequirements_add_elements_by_query_selector_not_auto_converting(
    CWebHyDrationSearchRequirements *self,const char *query_selector,...);


void CWebHyDrationSearchRequirements_add_elements_by_attribute(
    CWebHyDrationSearchRequirements *self,
   const char *attribute,
   const char*attribute_value,
   ...
);

void CWebHyDrationSearchRequirements_add_elements_by_attribute_not_auto_converting(
    CWebHyDrationSearchRequirements *self,
    const char *attribute,
    const char*attribute_value,
    ...
);

void CWebHyDrationSearchRequirements_add_cookie_item(CWebHyDrationSearchRequirements *self, const char *name);
void CWebHyDrationSearchRequirements_add_confirm(CWebHyDrationSearchRequirements *self, const char*message, ...);


void CWebHyDrationSearchRequirements_add_elements_by_class_name(
    CWebHyDrationSearchRequirements *self,
    const char*class_value,
    ...
);

void CWebHyDrationSearchRequirements_add_elements_by_class_name_not_auto_converting(
    CWebHyDrationSearchRequirements *self,
    const char*class_value,...
);

void CWebHyDrationSearchRequirements_add_elements_by_id(
    CWebHyDrationSearchRequirements *self,
    const char*id_values,
    ...
);

void CWebHyDrationSearchRequirements_add_elements_by_id_not_auto_converting(
    CWebHyDrationSearchRequirements *self,
    const char*id_values,
    ...
);


void CWebHyDrationSearchRequirements_add_session_storage_item_not_converting(
    CWebHyDrationSearchRequirements *self,
    const char *name,
    ...
);


void CWebHyDrationSearchRequirements_add_session_storage_item(
    CWebHyDrationSearchRequirements *self,
    const char *name,
    ...
);

void CWebHyDrationSearchRequirements_add_prompt(CWebHyDrationSearchRequirements *self, const char *message, ...);