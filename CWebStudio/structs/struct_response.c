

struct CwebHttpResponse *create_http_response(){
    struct CwebHttpResponse *response = (struct CwebHttpResponse *)malloc(
        sizeof(struct CwebHttpResponse)
    );
    response->status_code = 200;
    response->headers = cweb_create_dict();
    response->content_length = 0;
    response->content = NULL;
    response->free = private_cweb_http_response_free;
    response->set_content = private_cweb_http_set_content;
    response->generate_response = private_cweb_generate_response;
    response->add_header = private_cweb_http_add_header;
    return response;
}

char *private_cweb_generate_response(struct CwebHttpResponse*response,bool include_content){
    char *response_string = (char*)malloc(1000);
    sprintf(response_string, "HTTP/1.1 %d OK\r", response->status_code);
    struct CwebDict *headers = response->headers;
    for(int i = 0; i < headers->size; i++){
        struct CwebKeyVal *key_val = headers->keys_vals[i];
        char *key = key_val->key;
        char *value = key_val->value;
        sprintf(response_string, "%s\r%s: %s\r\n", response_string, key, value);
    }


    if(include_content){
        sprintf(response_string, "%s\r%s", response_string, response->content);
    }
    return response_string;
}

void private_cweb_http_response_free(struct CwebHttpResponse *response){
    response->headers->free(response->headers);
    free(response->content);
    free(response);
}

void private_cweb_http_set_content(struct CwebHttpResponse *response, unsigned char *content,int content_length){
    response->content = (unsigned char*)malloc(content_length);
    memcpy(response->content, content, content_length);
    response->content_length = content_length;
}

void private_cweb_http_add_header(struct CwebHttpResponse *response, char *key, char *value){
    response->headers->set(response->headers, key, value);
}