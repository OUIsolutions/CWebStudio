

struct CwebHttpResponse* cweb_send_any(const char *content_type,size_t content_length,unsigned char *content){
    struct CwebHttpResponse *response = create_http_response();
    response->add_header(response, "Content-Type", content_type);
    response->set_content(response, content, content_length);
}

struct CwebHttpResponse* cew_send_text(const char *content){
    return cweb_send_any("text/plain", strlen(content), (unsigned char*)content);
}


struct CwebHttpResponse* cew_send_file(const char *file_path,const char *content_type,const char *content){
    
    
}