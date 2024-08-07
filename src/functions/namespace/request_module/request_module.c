

CwebHttpRequestModule newCwebRequestModule(){
    CwebHttpRequestModule self = {0};
    self.newCwebHttpRequest = newCwebHttpRequest;
    self.read_content = CwebHttpRequest_read_content;
    self.read_cJSON = CWebHttpRequest_read_cJSON;
    self.set_url = CwebHttpRequest_set_url;
    self.set_route = CwebHttpRequest_set_route;
    self.set_method = CwebHttpRequest_set_method;
    self.add_header =CwebHttpRequest_add_header;
    self.add_param = CwebHttpRequest_add_param;
    self.set_content_string = CwebHttpRequest_set_content_string;
    self.parse_http_request = CwebHttpRequest_parse_http_request;


    self.get_header = CwebHttpRequest_get_header;
    self.get_header_by_normalized_key = CwebHttpRequest_get_header_by_normalized_key;
    self.get_param = CwebHttpRequest_get_param;
    self.represent = CwebHttpRequest_represent;
    self.free =CwebHttpRequest_free;
    return self;
}