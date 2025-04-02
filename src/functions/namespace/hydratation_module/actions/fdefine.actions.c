
CWebHydrationActionsNamespace newCWebHydrationActionsNamespace(){
    CWebHydrationActionsNamespace self ={0};


    self.replace_element_by_query_selector = CWebHyDrationBridge_replace_element_by_query_selector;
    self.append_by_query_selector = CWebHyDrationBridge_append_by_query_selector;
    self.destroy_by_query_selector =  CWebHyDrationBridge_destroy_by_query_selector;
    self.remove_session_storage_data =  CWebHyDrationBridge_remove_session_storage_data;
    self.hide_element_by_query_selector = CWebHyDrationBridge_hide_element_by_query_selector;
    self.unhide_element_by_query_selector=  CWebHyDrationBridge_unhide_element_by_query_selector;
    self.hide_element_by_id = CWebHyDrationBridge_hide_element_by_id;
    self.unhide_element_by_id= CWebHyDrationBridge_unhide_element_by_id;
    self.append_by_id = CWebHyDrationBridge_append_by_id;
    self.set_session_storage_data = CWebHyDrationBridge_set_session_storage_data;
    self.alert = CWebHyDrationBridge_alert;
    self.execute_script = CWebHyDrationBridge_execute_script;
    self.replace_element_by_id = CWebHyDrationBridge_replace_element_by_id;
    self.destroy_by_id = CWebHyDrationBridge_destroy_by_id;
    self.redirect = CWebHydration_redirect;
    self.add_cookie_with_time = CWebHydrationBridge_creatCookie_with_time;
    self.add_cookie = CWebHydrationBridge_creatCookie;
    self.delet_cookie = CWebHyDrationBridge_deletCookie;
    self.console_log = CWebHyDration_console_log;
    self.console_warn = CWebHyDration_console_warn;
    self.console_clear = CWebHyDration_console_clear;
    self.console_error = CWebHyDration_console_error;
    self.add_class_by_id = CWebHyDrationBridge_add_class_by_id;
    self.remove_class_by_id = CWebHyDrationBridge_remove_class_by_id;
    self.remove_class_by_query_selector = CWebHyDrationBridge_remove_class_by_query_selector;

    return self;
}
