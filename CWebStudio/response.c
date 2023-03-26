

char *create_response(int status_code,const char *content_type,const char *content){
    char *response = (char*)malloc(strlen(content) + 70);
    sprintf(response, "HTTP/1.1 %d OK\r\nContent-Type: %s\r\nContent-Length: %ld\r\n\r\n%s", status_code, content_type, strlen(content), content);
    return response;
}

char *send_text(int status_code,const char *content){
    return create_response(status_code, "text/plain", content);
}

