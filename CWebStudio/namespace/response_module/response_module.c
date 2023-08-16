


CwebHttpResponseModule newCwebHttpResponseModule(){
    CwebHttpResponseModule self = {0};

    self.newHttpResponse  = newCwebHttpResponse;
    self.send_any = cweb_send_any;
    self.send_text = cweb_send_text;
    self.send_text_cleaning_memory = cweb_send_text_cleaning_memory;
    self.send_rendered_CTextStack_cleaning_memory = cweb_send_rendered_CTextStack_cleaning_memory;
    self.send_var_html = cweb_send_var_html;
    self.send_var_html_cleaning_memory = cweb_send_var_html_cleaning_memory;
    self.send_file = cweb_send_file;

    self.set_content = CwebHttpResponse_set_content;
    self.add_header = CwebHttpResponse_add_header;
    self.generate_response = CwebHttpResponse_generate_response;
    self.free = CwebHttpResponse_free;
    return self;

}