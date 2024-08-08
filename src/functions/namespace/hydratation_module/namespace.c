
#include "../uniq.definitions_requirements.h"

CWebHydrationNamespace newCWebHydrationNamespace() {
    CWebHydrationNamespace self = {0};
    //hidratation
    self.create_bridge = CWebHyDration_create_bridge;
    self.create_script = CWebHyDration_create_script;
    self.newHyDration = private_newCWebHyDration;
    //bridge
    //basic
    self.is_the_route = CWebHyDrationBridge_is_the_route;
    self.call = CWebHyDrationBridge_call;
    //entries
    self.add_function = CWebHyDration_add_function;
    self.add_input_by_id = CWebHyDration_add_input_by_id;
    self.add_input_checkbox_by_id = CWebHyDration_add_input_checkbox_by_id;
    self.request_text_content_by_id = CWebHyDration_request_text_content_by_id;
    self.request_number_text_content_by_id = CWebHyDration_request_number_text_content_by_id;

    self.add_input_by_all_id = CWebHyDration_add_input_by_all_id;
    self.add_input_checkbox_by_all_id = CWebHyDration_add_input_checkbox_by_all_id;
    self.request_text_content_by_all_id = CWebHyDration_request_text_content_by_all_id;
    //read
    self.read_string = CWebHyDration_read_string;
    self.read_long = CWebHyDration_read_long;
    self.read_double = CWebHyDration_read_double;
    self.read_bool = CWebHyDration_read_bool;
    self.exist = CWebHyDration_exist;
    //response
    self.add_response_callback = CWebHyDration_add_response_callback;
    self.alert = CWebHyDration_alert;
    self.destroy_by_id = CWebHyDration_destroy_by_id;
    self.replace_element_by_id_with_ctext_stack_cleaning_memory = CWebHyDration_replace_element_by_id_with_ctext_stack_cleaning_memory;
    self.generate_response = CWebHyDration_generate_response;
    //error
    self.error = CWebHyDration_error;
    self.get_error_menssage= CWebHyDration_get_error_menssage;
    self.get_error_key = CWebHyDration_get_error_key;
    self.get_error_code =CWebHyDration_get_error_code;
    self.generate_error_response = CWebHyDration_generate_error_response;

    return self;
}

