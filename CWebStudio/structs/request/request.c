



struct CwebHttpRequest *cweb_request_constructor(int socket){
    struct CwebHttpRequest *self = (struct CwebHttpRequest*)malloc(sizeof(struct CwebHttpRequest));
    
    self->socket = socket;
    self->url = NULL;
    self->method = NULL;
    self->route = NULL;
    self->content = NULL;
    self->content_length = 0;


    self->read_content = private_cweb_read_content;
    self->set_url = private_cweb_set_url;
    self->set_method = private_cweb_set_method;
    self->add_header = private_cweb_add_header;
    self->add_param = private_cweb_add_param;
    self->set_route = private_cweb_set_route;
    self->set_content_string = private_cweb_set_content_string;

    self->get_header = private_cweb_get_header;
    self->get_header_by_sanitized_key = private_cweb_get_header_by_sanitized_key;
    self->get_param = private_cweb_get_param;
    self->get_param_by_sanitized_key = private_cweb_get_param_by_sanitized_key;

    self->params = cweb_create_dict();
    self->headers = cweb_create_dict();
    self->parse_http_request = private_cweb_parse_http_request;
    self->interpret_query_params = private_cweb_interpret_query_params;
    self->interpret_first_line = private_cweb_interpret_first_line;
    self->interpret_headders = private_cweb_interpret_headders;
    self->free = private_cweb_free_http_request;
    self->represent = private_cweb_represent_http_request;
    
    return self;
    
}
int private_cweb_read_content(struct CwebHttpRequest *self,long max_content_size){
            //means is the end of \r\n\r\n
    
    if(self->content_length == 0){
        return UNDEFINED_CONTENT;
    }

    if(self->content_length > max_content_size){
        return MAX_CONTENT_SIZE;
    }   


    if(self->content != NULL){
        return 0;
    }

    struct timeval timer;
    timer.tv_sec = 5;  // tempo em segundos
    timer.tv_usec = 0;  //
    setsockopt(self->socket, SOL_SOCKET, SO_RCVTIMEO, &timer, sizeof(timer));
    
    self->content =(unsigned char*) malloc(self->content_length+2);
    
    

    for(int j = 0; j<self->content_length;j++){

        ssize_t res = read(self->socket,self->content+j,1);
        if(res < 0){
            
            return READ_ERROR;
        }



    }

    self->content[self->content_length]= '\0';

    //extracting url encoded data
    char *content_type = self->get_header_by_sanitized_key(
        self, "contenttype","- "
    );
    if(content_type != NULL){
        if(strcmp(content_type, "application/x-www-form-urlencoded") == 0){
            char *decoded = private_cweb_convert_url_encoded_text((char*)self->content);
            self->interpret_query_params(self, decoded);
            free(decoded);
        }
    }
    return  0;

}

char * private_cweb_get_header(struct CwebHttpRequest *self,const char *key){
    return self->headers->get_value(self->headers,key);
}

char * private_cweb_get_param_by_sanitized_key(struct CwebHttpRequest *self,const char *key,const char *chars_to_remove){
    return self->params->find_value_by_normalized_key(self->params,key,chars_to_remove);
}

char * private_cweb_get_param(struct CwebHttpRequest *self,const char *key){
    return self->params->get_value(self->params,key);
}
char * private_cweb_get_header_by_sanitized_key(struct CwebHttpRequest *self,const char *key,const char *chars_to_remove){
    return self->headers->find_value_by_normalized_key(self->headers,key,chars_to_remove);
}



void private_cweb_set_route(struct CwebHttpRequest *self,const char *route){
    self->route = (char*) malloc(strlen(route) +2);
    strcpy(self->route,route);
}

void private_cweb_add_header(struct CwebHttpRequest *self,const char *key,const char *value){
    self->headers->set(self->headers,key,value);
}
void private_cweb_add_param(struct CwebHttpRequest *self,const char *key,const char *value){
    self->params->set(self->params,key,value);
}

void private_cweb_set_method(struct CwebHttpRequest *self,const char *method){
    self->method = (char*) malloc(strlen(method)+2);
    strcpy(self->method,method);
}


void private_cweb_set_content_string(struct CwebHttpRequest *self,const char *content){
    self->content_length = strlen(content);
    self->content = (unsigned char*) malloc(strlen(content) +2);
    for(int i =0;i<strlen(content);i++){
        self->content[i] = content[i];
    }
}


void private_cweb_represent_http_request(struct CwebHttpRequest *self){
    
    printf("url: %s\n", self->url);
    printf("route: %s\n", self->route);
    printf("method: %s\n", self->method);
    printf("params:-----------------------------\n");
    self->params->represent(self->params);
    printf("headers:----------------------------\n");
    self->headers->represent(self->headers);
    printf("content: %s\n", self->content);

}


void private_cweb_free_http_request(struct CwebHttpRequest *self){



    if(self->url != NULL){
        free(self->url);
    }
    if(self->route != NULL){
        free(self->route);
    }
    if(self->content != NULL){
        free(self->content);
    }
    if(self->method != NULL){
        free(self->method);
    }

    self->params->free(self->params);

    self->headers->free(self->headers);
    free(self);

}