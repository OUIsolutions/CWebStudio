



struct CwebHttpRequest *private_cweb_request_constructor(){
    struct CwebHttpRequest *self = (struct CwebHttpRequest*)malloc(sizeof(struct CwebHttpRequest));
    
    self->url = NULL;
    self->method = NULL;
    self->route = NULL;
    self->content = NULL;
    self->content_length = 0;

    self->set_url = private_cweb_set_url;
    self->set_method = private_cweb_set_method;
    self->set_route = private_cweb_set_route;
    self->set_content_string = private_cweb_set_content_string;

    self->params = cweb_create_dict();
    self->headers = cweb_create_dict();
    self->interpret_query_params = private_cweb_interpret_query_params;
    self->interpret_first_line = private_cweb_interpret_first_line;
    self->interpret_headders = private_cweb_interpret_headders;
    self->free = private_cweb_free_http_request;
    self->represent = private_cweb_represent_http_request;
    
    return self;
    
}

void private_cweb_set_url(struct CwebHttpRequest *self,const char *url){
    self->url = (char*) malloc(strlen(url)+2);
    strcpy(self->url,url);
}

void private_cweb_set_route(struct CwebHttpRequest *self,const char *route){
    self->route = (char*) malloc(strlen(route) +2);
    strcpy(self->route,route);
}

void private_cweb_set_method(struct CwebHttpRequest *self,const char *method){
    self->method = (char*) malloc(strlen(method));
    strcpy(self->method,method);
}

void private_cweb_set_content_string(struct CwebHttpRequest *self,const char *content){
    self->content_length = strlen(content);
    self->content = (unsigned char*) malloc(strlen(content) +2);
    for(int i =0;i<strlen(content);i++){
        self->content[i] = content[i];
    }
}




void private_cweb_interpret_query_params(struct CwebHttpRequest *self,const char *query_params){
    int paramns_size = strlen(query_params);
    char key[1000] = {0};
    char value[1000] = {0};
    bool key_found = false;

    for(int i=1; i<paramns_size; i++){

        if(query_params[i] == '='){
            key_found = true;
            continue;
        }

        if(query_params[i] == '&'){
            key_found = false;
            self->params->set(self->params, key, value);
            memset(key, 0, 1000);
            memset(value, 0, 1000);
            continue;
        }
        
        if(key_found){
            value[strlen(value)] = query_params[i];
        }
        
        else{
            key[strlen(key)] = query_params[i];
        }
    }
    if(key_found){
        self->params->set(self->params, key, value);
    }

}
void private_cweb_interpret_first_line(struct CwebHttpRequest *self, char *first_line){
    
    char method[1000] = {0};
    char url[1000] = {0};

    sscanf(first_line, "%s %s", method, url);
    
    
    self->method = (char*)malloc(strlen(method)+2);
    strcpy(self->method, method);

    
    self->url = (char*)malloc(strlen(url)+2);
    strcpy(self->url, url);
    
    char route[1000] = {0};
    char params[30000] = {0};

    sscanf(url, "%[^?]%s", route, params);

    self->route = (char*)malloc(strlen(route)+1);
    strcpy(self->route, route);

    self->interpret_query_params(self, params);
    

    
}


void private_cweb_interpret_headders(struct CwebHttpRequest *self,struct DtwStringArray *line_headers){
    
    for(int i = 1;i< line_headers->size;i++){
        char *current_line = line_headers->strings[i];
        int line_size = strlen(current_line);
        char key[1000] = {0};
        char value[3000] = {0};
        bool key_found = false;
        int value_start_point = 0;
        for(int j = 0; j<line_size;j++){
            
            if(current_line[j] == ':' && key_found == false){
                key_found = true;
                j+=1;
                value_start_point = j;
                continue;
            }

            if(key_found == false){
                key[j] = current_line[j];
            }

            if(key_found == true){
                int size_point = j - value_start_point -1;
               value[size_point] = current_line[j];
            }
        }

        if(key_found){
            self->headers->set(self->headers, key, value);

        }
    }

}

struct CwebHttpRequest *private_cweb_create_http_request(char *raw_entrys){
        //splite lines by "\r\n"

    struct CwebHttpRequest *self = private_cweb_request_constructor();
    self->raw_entrys = raw_entrys;
    
    struct DtwStringArray *lines = dtw_constructor_string_array();

    char last_string[10000]= {0};
    int line_index = 0;
    int i = 0;
    int point = 0;
    
    while (true){


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
    self->interpret_first_line(self, lines->strings[0]);
    self->interpret_headders(self, lines);

    

    char *content_lenght_str = self->headers->get_value(self->headers, "Content-Length");
    
    if(content_lenght_str != NULL){
        self->content_length = atoi(content_lenght_str);

        //means is the end of \r\n\r\n
   
        
        self->content =(unsigned char*)malloc(self->content_length);
        int content_start = i+4;
        int bytes_read = 0;
        //parse from the i to content length to content 
        for(int j = 0; j<self->content_length;j++){
            //jump if is 0 
            if(raw_entrys[content_start+j] == 0){
                break;
            }
            
            self->content[bytes_read] = raw_entrys[content_start+j];
            bytes_read++;
        }
    

        //extracting url encoded data
        char *content_type = self->headers->get_value(self->headers, "Content-Type");
        if(content_type != NULL){
            if(strcmp(content_type, "application/x-www-form-urlencoded") == 0){
                self->interpret_query_params(self, (char*)self->content);
            }
        }
    }


    lines->free_string_array(lines);
    return self;
}


void private_cweb_represent_http_request(struct CwebHttpRequest *self){
    
    printf("url: %s\n", self->url);
    printf("route: %s\n", self->route);
    printf("method: %s\n", self->method);
    printf("params:-----------------------------\n");
    self->params->represent(self->params);
    printf("headers:----------------------------\n");
    self->headers->represent(self->headers);
    printf("content_length: %d\n", self->content_length);
    printf("content: %s\n", self->content);

}

void private_cweb_free_http_request(struct CwebHttpRequest *self){
    if(self->url != NULL){
        free(self->url);
    }
    if(self->route != NULL){
        free(self->route);
    }
    if(self->method != NULL){
        free(self->method);
    }

    self->params->free(self->params);

    self->headers->free(self->headers);
    free(self);

}