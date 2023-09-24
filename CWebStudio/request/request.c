



struct CwebHttpRequest *newCwebHttpRequest(int socket){
    struct CwebHttpRequest *self = (struct CwebHttpRequest*)malloc(sizeof(struct CwebHttpRequest));
    
    self->socket = socket;
    self->url = NULL;
    self->method = NULL;
    self->route = NULL;
    self->content = NULL;
    self->json = NULL;
    self->content_error = 0;
    self->content_length = 0;



    self->params = newCwebDict();
    self->headers = newCwebDict();

    
    return self;
    
}



unsigned char * CwebHttpRequest_read_content(struct CwebHttpRequest *self, long max_content_size) {

    if (self->content != NULL) {
        return self->content;
    }

   
    if (self->content_length == 0) {
        cweb_print("no content lenght provided\n");
        self->content_error = UNDEFINED_CONTENT;
        return NULL;
    }

    if (self->content_length > max_content_size) {
        cweb_print("content size is too big\n");
        self->content_error = MAX_CONTENT_SIZE;
        return NULL;
    }


    struct timeval timer;
    timer.tv_sec = 5;  // tempo em segundos
    timer.tv_usec = 0;  //

    setsockopt(self->socket, SOL_SOCKET, SO_RCVTIMEO, &timer, sizeof(timer));

    self->content = (unsigned char*) malloc(self->content_length + 2);
    
    int total_bytes_received = 0;
    int bytes_remaining = self->content_length;

    while (bytes_remaining > 0) {
        int bytes_received = recv(self->socket, self->content + total_bytes_received, bytes_remaining, 0);
        if (bytes_received <= 0) {
            self->content_error =READ_ERROR;
            return NULL;
        }

        total_bytes_received += bytes_received;
        bytes_remaining -= bytes_received;
    }

    self->content[total_bytes_received] = '\0';

    //extracting url encoded data
    char *content_type = CwebHttpRequest_get_header_by_normalized_key(self, "contenttype", "- ");

    if (content_type != NULL) {
        if (strcmp(content_type, "application/x-www-form-urlencoded") == 0) {
            char *decoded = private_cweb_convert_url_encoded_text((char*) self->content);
            private_CwebHttpRequest_interpret_query_params(self, decoded);
            free(decoded);
        }
    }

    return self->content;
}


cJSON * CWebHttpRequest_read_cJSON(CwebHttpRequest *self, long max_content_size){
    unsigned  char *content =CwebHttpRequest_read_content(self,max_content_size);
    if(!content){
        return NULL;
    }

    self->json = cJSON_Parse((char*)self->content);
    if(!self->json){
        self->content_error= INVALID_JSON;
        return NULL;
    }
    return self->json;
}



char * CwebHttpRequest_get_header(struct CwebHttpRequest *self, const char *key){
    return CwebDict_get(self->headers,key);
}

char * CwebHttpRequest_get_param_by_sanitized_key(struct CwebHttpRequest *self, const char *key, const char *chars_to_remove){
    return CwebDict_get_by_normalized_key(self->params,key,chars_to_remove);
}

char * CwebHttpRequest_get_param(struct CwebHttpRequest *self, const char *key){
    return CwebDict_get(self->params,key);
}
char * CwebHttpRequest_get_header_by_normalized_key(struct CwebHttpRequest *self, const char *key, const char *chars_to_remove){
    return CwebDict_get_by_normalized_key(self->headers,key,chars_to_remove);
}



void CwebHttpRequest_set_route(struct CwebHttpRequest *self, const char *route){
    self->route = (char*) malloc(strlen(route) +2);
    strcpy(self->route,route);
}

void CwebHttpRequest_add_header(struct CwebHttpRequest *self, const char *key, const char *value){
    CwebDict_set(self->headers,key,value);
}
void CwebHttpRequest_add_param(struct CwebHttpRequest *self, const char *key, const char *value){
    CwebDict_set(self->params,key,value);
}

void CwebHttpRequest_set_method(struct CwebHttpRequest *self, const char *method){
    self->method = (char*) malloc(strlen(method)+2);
    strcpy(self->method,method);
}


void CwebHttpRequest_set_content_string(struct CwebHttpRequest *self, const char *content){
    self->content_length = strlen(content);
    self->content = (unsigned char*) malloc(strlen(content) +2);
    for(int i =0;i<strlen(content);i++){
        self->content[i] = content[i];
    }
}


void CwebHttpRequest_represent(struct CwebHttpRequest *self){
    
    printf("url: %s\n", self->url);
    printf("route: %s\n", self->route);
    printf("method: %s\n", self->method);
    printf("params:-----------------------------\n");
    CwebDict_represent(self->params);
    printf("headers:----------------------------\n");
    CwebDict_represent(self->headers);
    if(self->content){
        printf("content: %s\n", self->content);
    }

}


void CwebHttpRequest_free(struct CwebHttpRequest *self){



    if(self->url){
        free(self->url);
    }
    if(self->route){
        free(self->route);
    }
    if(self->content){
        free(self->content);
    }
    if(self->client_ip){
        free(self->client_ip);
    }
    if(self->json){
        cJSON_Delete(self->json);
    }

    if(self->method){
        free(self->method);
    }

    CwebDict_free(self->params);

    CwebDict_free(self->headers);
    free(self);

}