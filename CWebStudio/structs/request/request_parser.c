



void private_cweb_interpret_query_params(struct CwebHttpRequest *self,const char *query_params){
    if(!query_params){
        return;
    }
    int paramns_size = strlen(query_params);
    char key[1000] = {0};
    char value[1000] = {0};
    bool key_found = false;

    for(int i =0; i<paramns_size; i++){

        if(query_params[i] == '='&& key_found == false){
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

void private_cweb_set_url(struct CwebHttpRequest *self,const char *url){
    int size_url = strlen(url);
    self->url = (char*) malloc(size_url+2);
    strcpy(self->url,url);

    char route[5000] = {0};
    char params[5000] = {0};

    bool route_end = false;
    int route_end_position =0;
    int i = 0;
    for(;i < size_url;i++){
        char current_char = url[i];

        if(current_char == '?'){
            route_end = true;
            route_end_position = i+1;
            route[i] = '\0';
            continue;
        }

        if(route_end == false){
            route[i] = current_char;
        }
        if(route_end == true){
            params[i-route_end_position] = current_char;
        }
    }


    self->route = (char*)malloc(strlen(route)+1);
    strcpy(self->route, route);

    if(route_end_position){
        params[i-route_end_position] = '\0';
        self->interpret_query_params(self, params);
    }


}

int private_cweb_interpret_first_line(struct CwebHttpRequest *self, char *first_line){
    #define METHOD_MAX_SIZE 300
    #define URL_MAX_SIZE 5000
    char method[METHOD_MAX_SIZE] = {0};
    char url[URL_MAX_SIZE] = {0};


    int line_len = strlen(first_line);
    int method_end = 0;
    //getting the method

    for (int i = 0; i < line_len; i++){
        if(i >= METHOD_MAX_SIZE){
            return INVALID_HTTP;
        }

        char current_char = first_line[i];
        if(current_char == ' '){
            method_end = i;
            method[i] = '\0';
            break;
        }
        method[i] = current_char;

    }
    
    if(!method_end){
        return INVALID_HTTP;
    }
    
    self->set_method(self,method);

    
    //getting the url
    int url_start_position = 0;
    bool url_found = false;
    
    for (int i = method_end; i < line_len; i++){

        
        if((i - url_start_position) >= URL_MAX_SIZE ){
            return INVALID_HTTP;
        }
        
        char current_char = first_line[i];
        
        if(current_char == ' ' && url_found == true){
            break;
        }

        if(current_char != ' ' && url_found == false){
           url_found = true;
           url_start_position = i;
        }


        if(url_found){
            url[i - url_start_position] = current_char;
        }
         
    }
    
    if(!url_found){
        return INVALID_HTTP;
    }
    self->set_url(self,url);
    
    return 0;

}


int private_cweb_interpret_headders(struct CwebHttpRequest *self,struct CwebStringArray *line_headers){
    
    for(int i = 1;i< line_headers->size;i++){
        char *current_line = line_headers->strings[i];
        int line_size = strlen(current_line);
        char key[1000] = {0};
        char value[10000] = {0};
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
            self->add_header(self, key, value);
        }
        else{
            return INVALID_HTTP;
        }
    }
    return 0;

}

int  private_cweb_parse_http_request(struct CwebHttpRequest *self){
        //splite lines by "\r\n"

        char raw_entries[20000] ={0};

    int i = 0;
    for(i =0;i<=20000;i++){

        //ssize_t res = recv(self->socket, &raw_entries[i], 1, MSG_WAITALL);
        ssize_t  res = read(self->socket, &raw_entries[i],1);

        if (res <= 0) {
            perror("webserver (read)");
            break;
        }

        //line break is \r\n\r\n
        if(i > 3){
            char *aux = &raw_entries[i-3];

            if(strcmp(aux,"\r\n\r\n") == 0){
                printf("terminou em %i\n",i);


                break;
            }
        }
    }
    if(i == 0){    
        return READ_ERROR;
        
    }

    if (i >= 20000) {
        return MAX_HEADER_SIZE;
    }

    char last_string[10000]= {0};
    struct CwebStringArray *lines = cweb_constructor_string_array();
    int line_index = 0;

    for(int l =0 ; l < i;l++){
        char *endline = &raw_entries[l];
        if(strcmp(endline,"\r\n") ==0){
            lines->add_string(lines, last_string);
            memset(last_string, 0, 10000);
            line_index = 0;
            l++;
            continue;
        }
        last_string[line_index] = raw_entries[l];
        line_index++;
    }



    int line_error = self->interpret_first_line(self, lines->strings[0]);

    if(line_error){

        lines->free_string_array(lines);
        return line_error;
    }

    int headers_error = self->interpret_headders(self, lines);
    lines->free_string_array(lines);
    
    
    if(headers_error){
        return headers_error;
    }
    //const char *content_lenght_str = self->get_header(self, "Content-Length");
    const char *content_lenght_str = self->get_header_by_sanitized_key(
        self, "contentlength","- "
    );

    if(content_lenght_str != NULL){

            for(int i = 0; i<strlen(content_lenght_str);i++){
            if(content_lenght_str[i] < '0' || content_lenght_str[i] > '9'){
                return INVALID_HTTP;
            }
        }

        self->content_length = atoi(content_lenght_str);

    }

    return 0;
}

