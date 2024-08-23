#include "../uniq.definitions_requirements.h"

CWebHydrationActionsNamespace newCWebHydrationActionsNamespace(){
    CWebHydrationActionsNamespace self ={0};
    self.hide_element_by_id = CWebHyDrationBridge_hide_element_by_id;
    self.unhide_element_by_id= CWebHyDrationBridge_unhide_element_by_id;
    self.set_session_storage_data = CWebHyDrationBridge_set_session_storage_data;
    self.alert = CWebHyDrationBridge_alert;
    self.execute_script = CWebHyDrationBridge_execute_script;
    self.replace_element_by_id = CWebHyDrationBridge_replace_element_by_id;
    self.destroy_by_id = CWebHyDrationBridge_destroy_by_id;
    self.redirect = CWebHydration_redirect;
    return self;
}
