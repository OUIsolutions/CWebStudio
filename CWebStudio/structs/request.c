



struct CwebHttpRequest *private_cwe_request_constructor(){
    struct CwebHttpRequest *self = (struct CwebHttpRequest*)malloc(sizeof(struct CwebHttpRequest));
    self->route = NULL;
    self->method = NULL;
    self->params = cweb_create_dict();
    self->headers = cweb_create_dict();
    self->content_length = 0;
    self->content = NULL;
    self->free = private_cwe_free_http_request;
    self->represent = private_cwe_represent_http_request;
    
    return self;
    
}   


struct CwebHttpRequest *private_cwe_create_http_request(char *raw_entrys){
        //splite lines by "\r\n"

    struct CwebHttpRequest *self = private_cwe_request_constructor();
    
    
    struct DtwStringArray *lines = dtw_constructor_string_array();

    char last_string[10000]= {0};
    int line_index = 0;
    int i = 0;
    
    while (true){

        //means its the last line
        if(i > CEW_MAX_REQUEST_SIZE){
            break;
        }

        if(
            raw_entrys[i]  == '\r' &&
            raw_entrys[i+1] == '\n' &&
            raw_entrys[i+2] == '\r' &&
            raw_entrys[i+3] == '\n'
        ){
            last_string[line_index] = '\0';
            lines->add_string(lines, last_string);
            break;
        }
        //means its an break line        
        if (raw_entrys[i] == '\r' && raw_entrys[i+1] == '\n'){
            last_string[line_index] = '\0';
            lines->add_string(lines, last_string);
            line_index=0;
            i++;
        }

        else{
            last_string[line_index] = raw_entrys[i];
            line_index++;
        }    
        i++;

    }

    lines->free_string_array(lines);
    return self;
}


void private_cwe_represent_http_request(struct CwebHttpRequest *self){
    printf("route: %s\n", self->route);
    printf("method: %s\n", self->method);
    printf("params:\n");
    self->params->represent(self->params);
    printf("headers:\n");
    self->headers->represent(self->headers);
    printf("content_length: %d\n", self->content_length);
    printf("content: %s\n", self->content);
}

void private_cwe_free_http_request(struct CwebHttpRequest *self){
    if(self->route != NULL){
        free(self->route);
    }
    if(self->method != NULL){
        free(self->method);
    }
    if(self->content != NULL){
        free(self->content);
    }
    self->params->free(self->params);
    self->headers->free(self->headers);
    free(self);

}