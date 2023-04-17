



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

void private_cweb_set_url(struct CwebHttpRequest *self,const char *url){
    self->url = (char*) malloc(strlen(url)+2);
    strcpy(self->url,url);

    strcpy(self->url, url);

    char route[1000] = {0};
    char params[30000] = {0};

    sscanf(url, "%[^?]%s", route, params);

    self->route = (char*)malloc(strlen(route)+1);
    strcpy(self->route, route);

    self->interpret_query_params(self, params);

}

void private_cweb_interpret_first_line(struct CwebHttpRequest *self, char *first_line){
    
    char method[1000] = {0};
    char url[1000] = {0};

    sscanf(first_line, "%s %s", method, url);

    self->set_method(self,method);

    self->set_url(self,url);

    
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
            self->add_header(self, key, value);
        }
    }

}

int  private_cweb_parse_http_request(struct CwebHttpRequest *self,int socket,size_t max_body_size){
        //splite lines by "\r\n"

    unsigned char raw_entrys[200000];

    struct DtwStringArray *lines = dtw_constructor_string_array();
    char last_string[10000]= {0};
    int line_index = 0;
    int i = 0;

    //parsing the header

    while (true){

        ssize_t res = read(socket,raw_entrys+i,1);

        if(res < 0){
            self->free(self);
            return INVALID_HTTP;
        }

        if(i >= 10000){
            self->free(self);
            return INVALID_HTTP;
        }

        if(

            raw_entrys[i-3]  == '\r' &&
            raw_entrys[i-2] == '\n' &&
            raw_entrys[i-1] == '\r' &&
            raw_entrys[i] == '\n'
        ){
            last_string[line_index] = '\0';
            lines->add_string(lines, last_string);
            break;
        }

        //means its an break line
        if (raw_entrys[i-1] == '\r' && raw_entrys[i] == '\n'){
            last_string[line_index] = '\0';
            lines->add_string(lines, last_string);
            line_index=0;
        }

        else{

            last_string[line_index] = raw_entrys[i];
            line_index++;
        }
        i++;

    }

    self->interpret_first_line(self, lines->strings[0]);
    self->interpret_headders(self, lines);    

    const char *content_lenght_str = self->get_header(self, "Content-Length");



    if(content_lenght_str != NULL){
        self->content_length = atoi(content_lenght_str);
        if(self->content_length > max_body_size){
<<<<<<< HEAD
  
            
=======

>>>>>>> dev-branch
            return MAX_BODY_SIZE;
        }

        //means is the end of \r\n\r\n
   
        self->content =(unsigned char*) malloc(self->content_length+2);
  
        
        for(int j = 0; j<self->content_length;j++){

            ssize_t res = read(socket,self->content+j,1);
            if(res < 0){
              
                return INVALID_HTTP;
            }

            if(j > max_body_size){

                return MAX_BODY_SIZE;
            }       

        }
        self->content[self->content_length]= '\0';

        //extracting url encoded data
        char *content_type = self->headers->get_value(self->headers, "Content-Type");
        if(content_type != NULL){
            if(strcmp(content_type, "application/x-www-form-urlencoded") == 0){
                self->interpret_query_params(self, (char*)self->content);
            }
        }

    }


    lines->free_string_array(lines);
    return 0;
}

