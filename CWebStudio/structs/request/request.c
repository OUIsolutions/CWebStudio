



struct CwebHttpRequest *cweb_request_constructor(){
    struct CwebHttpRequest *self = (struct CwebHttpRequest*)malloc(sizeof(struct CwebHttpRequest));
    
    self->url = NULL;
    self->method = NULL;
    self->route = NULL;
    self->content = NULL;
    self->content_length = 0;

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


char * private_cweb_get_header(struct CwebHttpRequest *self,const char *key){
    return self->headers->get_value(self->headers,key);
}
char * private_cweb_get_param_by_sanitized_key(struct CwebHttpRequest *self,const char *key){
    return self->headers->find_value_by_normalized_key(self->headers,key);
}
char * private_cweb_get_param(struct CwebHttpRequest *self,const char *key){
    return self->params->get_value(self->params,key);
}
char * private_cweb_get_header_by_sanitized_key(struct CwebHttpRequest *self,const char *key){
    return self->params->find_value_by_normalized_key(self->params,key);
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