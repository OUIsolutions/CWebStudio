

struct CwebHttpResponse *create_http_response(){
    struct CwebHttpResponse *self = (struct CwebHttpResponse *)malloc(
        sizeof(struct CwebHttpResponse)
    );
    self->status_code = 200;
    self->headers = cweb_create_dict();
    self->content_length = 0;
    self->exist_content = false;
    self->content = NULL;
    self->free = private_cweb_http_response_free;
    self->set_content = private_cweb_http_set_content;
    self->generate_response = private_cweb_generate_response;
    self->add_header = private_cweb_http_add_header;
    return self;
}

char *private_cweb_generate_response(struct CwebHttpResponse*self){
    char *response_string = (char*)malloc(20000);
    sprintf(response_string, "HTTP/1.1 %d OK\r\n", self->status_code);
    struct CwebDict *headers = self->headers;
    char content_length_str[1000] = {0};
    sprintf(content_length_str, "Content-Length: %d\r\n",self->content_length);
    strcat(response_string, content_length_str);

    for(int i = 0; i < headers->size; i++){
        struct CwebKeyVal *key_val = headers->keys_vals[i];
        char *key = key_val->key;
        char *value = key_val->value;
        char header[1000] = {0};
        sprintf(header, "%s: %s\r\n", key, value);
        strcat(response_string, header);
    }
    if(self->headers->size == 0){
        strcat(response_string, "\r\n");
    }
    strcat(response_string, "\r\n");
        
    return response_string;
}

void private_cweb_http_response_free(struct CwebHttpResponse *self){
    self->headers->free(self->headers);
    free(self->content);
    free(self);
}

void private_cweb_http_set_content(struct CwebHttpResponse *self, unsigned char *content,int content_length){
    self->content = (unsigned char*)malloc(content_length +3);
    memcpy(self->content, content, content_length);
    self->exist_content = true;
    self->content_length = content_length -1;
}

void private_cweb_http_add_header(struct CwebHttpResponse *self,const char *key,const  char *value){
    self->headers->set(self->headers, key, value);
}