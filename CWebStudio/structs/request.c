



struct CwebHttpRequest *private_cwe_request_constructor(){
    struct CwebHttpRequest *self = (struct CwebHttpRequest*)malloc(sizeof(struct CwebHttpRequest));
    self->url = NULL;
    self->method = NULL;
    self->route = NULL;
    self->params = cweb_create_dict();
    self->headers = cweb_create_dict();
    self->content_length = 0;
    self->content = NULL;
    self->interpret_first_line = private_cweb_interpret_first_line;
    self->interpret_headders = private_cweb_interpret_headders;
    self->free = private_cweb_free_http_request;
    self->represent = private_cweb_represent_http_request;
    
    return self;
    
}   

void private_cweb_interpret_first_line(struct CwebHttpRequest *self, char *first_line){
    char method[1000] = {0};
    char url[1000] = {0};

    sscanf(first_line, "%s %s", method, url);
    
    self->method = (char*)malloc(strlen(method)+1);
    strcpy(self->method, method);

    
    self->url = (char*)malloc(strlen(url)+1);
    strcpy(self->url, url);
    
    char route[1000] = {0};
    char params[30000] = {0};

    sscanf(url, "%[^?]%s", route, params);

    self->route = (char*)malloc(strlen(route)+1);
    strcpy(self->route, route);


    int paramns_size = strlen(params);
    char key[1000] = {0};
    char value[1000] = {0};
    bool key_found = false;

    for(int i=1; i<paramns_size; i++){

        if(params[i] == '='){
            key_found = true;
            continue;
        }

        if(params[i] == '&'){
            key_found = false;
            self->params->set(self->params, key, value);
            memset(key, 0, 1000);
            memset(value, 0, 1000);
            continue;
        }
        
        if(key_found){
            value[strlen(value)] = params[i];
        }
        
        else{
            key[strlen(key)] = params[i];
        }
    }
    if(key_found){
        self->params->set(self->params, key, value);
    }

    
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

struct CwebHttpRequest *private_cwe_create_http_request(char *raw_entrys){
        //splite lines by "\r\n"

    struct CwebHttpRequest *self = private_cwe_request_constructor();
    self->raw_entrys = raw_entrys;
    
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
    self->interpret_first_line(self, lines->strings[0]);
    self->interpret_headders(self, lines);
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
    if(self->content != NULL){
        free(self->content);
    }
    self->params->free(self->params);

    self->headers->free(self->headers);
    free(self);

}