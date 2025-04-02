//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.globals.h"
//silver_chain_scope_end



CwebHttpResponseModule newCwebHttpResponseModule(){
    CwebHttpResponseModule self = {0};

    self.newHttpResponse  = newCwebHttpResponse;
    self.send_any = cweb_send_any;
    self.send_json_string = cweb_send_json_string;
    self.send_cJSON = cweb_send_cJSON;
    self.send_cJSON_cleaning_memory = cweb_send_cJSON_cleaning_memory;
    self.send_var_html_cleaning_memory = cweb_send_json_string_cleaning_memory;
    self.send_text = cweb_send_text;
    self.send_text_cleaning_memory = cweb_send_text_cleaning_memory;
    self.send_rendered_CTextStack = cweb_send_rendered_CTextStack;
    self.send_var_html = cweb_send_var_html;
    self.send_var_html_cleaning_memory = cweb_send_var_html_cleaning_memory;
    self.send_file = cweb_send_file;

    self.set_content = CwebHttpResponse_set_content;
    self.add_header = CwebHttpResponse_add_header;
    self.generate_response = CwebHttpResponse_generate_response;
    self.free = CwebHttpResponse_free;
    return self;

}
