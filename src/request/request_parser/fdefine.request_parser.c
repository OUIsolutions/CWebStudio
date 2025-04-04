

void private_CwebHttpRequest_interpret_query_params(struct CwebHttpRequest *self, const char *query_params){
    if(!query_params){
        return;
    }
    int paramns_size = strlen(query_params);
    char key[5000] = {0};
    char value[5000] = {0};
    bool key_found = false;

    for(int i =0; i<paramns_size; i++){



        if(query_params[i] == '='&& key_found == false){
            key_found = true;
            continue;
        }

        if(query_params[i] == '&'){
            key_found = false;
            char *sanitized_key = private_cweb_convert_url_encoded_text(key);
            char *sanitized_value = private_cweb_convert_url_encoded_text(value);

            CwebDict_set(self->params, sanitized_key, sanitized_value);
            free(sanitized_key);
            free(sanitized_value);

            memset(key, 0, 5000);
            memset(value, 0, 5000);
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

        char *sanitized_key = private_cweb_convert_url_encoded_text(key);
        char *sanitized_value = private_cweb_convert_url_encoded_text(value);
        CwebDict_set(self->params, sanitized_key, sanitized_value);
        free(sanitized_key);
        free(sanitized_value);

    }

}

void CwebHttpRequest_set_url(struct CwebHttpRequest *self, const char *url){
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
        private_CwebHttpRequest_interpret_query_params(self, params);
    }


}

int private_CwebHttpRequest_interpret_first_line(struct CwebHttpRequest *self, char *first_line){

    #define CWEB_METHOD_MAX_SIZE 300
    #define CWEB_URL_MAX_SIZE 5000
    char method[CWEB_METHOD_MAX_SIZE] = {0};
    char url[CWEB_URL_MAX_SIZE] = {0};


    int line_len = strlen(first_line);
    int method_end = 0;
    //getting the method

    for (int i = 0; i < line_len; i++){

        if(i >= CWEB_METHOD_MAX_SIZE){
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

    CwebHttpRequest_set_method(self,method);


    //getting the url
    int url_start_position = 0;
    bool url_found = false;

    for (int i = method_end; i < line_len; i++){


        if((i - url_start_position) >= CWEB_URL_MAX_SIZE){
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
    CwebHttpRequest_set_url(self,url);

    return 0;

}


int private_CwebHttpRequest_interpret_headders(struct CwebHttpRequest *self, struct CwebStringArray *line_headers){

    for(int i = 1;i< line_headers->size;i++){
        char *current_line = line_headers->strings[i];
        int line_size = strlen(current_line);
        char key[1100] = {0};
        char value[11000] = {0};
        bool key_found = false;
        int value_start_point = 0;

        for(int j = 0; j<line_size;j++){

            if(key_found == false && j >= 1000){
                return MAX_HEADER_SIZE_CODE;
            }


            if(key_found == true && j > 10000){
                return MAX_HEADER_SIZE_CODE;
            }



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
            CwebHttpRequest_add_header(self, key, value);
        }
        else{
            return INVALID_HTTP;
        }
    }
    return 0;

}


bool private_cweb_is_valid_utf8(const unsigned char *data, size_t length) {
    size_t i = 0;
    while (i < length) {
        if (data[i] <= 127) {
            // ASCII (1 byte): 0xxxxxxx
            i++;
        } else if ((data[i] & 224) == 192) {
            // 2 bytes: 110xxxxx 10xxxxxx
            if (i + 1 >= length || (data[i + 1] & 192) != 128) return false;
            i += 2;
        } else if ((data[i] & 240) == 224) {
            // 3 bytes: 1110xxxx 10xxxxxx 10xxxxxx
            if (i + 2 >= length || (data[i + 1] & 192) != 128 || (data[i + 2] & 192) != 128) return false;
            i += 3;
        } else if ((data[i] & 248) == 240) {
            // 4 bytes: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
            if (i + 3 >= length || (data[i + 1] & 192) != 128 || (data[i + 2] & 192) != 128 || (data[i + 3] & 192) != 128) return false;
            i += 4;
        } else {
            return false; // Byte inicial inválido
        }
    }
    return true;
}

int  CwebHttpRequest_parse_http_request(struct CwebHttpRequest *self){
        //splite lines by "\r\n"


    unsigned char raw_entries[MAX_HEADER_LEN] ={0};

    int i = 0;
    while (true) {

        if (i >= MAX_HEADER_LEN -10) {
            return MAX_HEADER_SIZE_CODE;
        }
        int flag = 0;
        #if defined(__linux__)
            flag = UNI_MSG_WAITALL;
        #endif
        ssize_t res = Universal_recv(self->socket, &raw_entries[i], sizeof(unsigned char), flag);
        //ssize_t res = read(self->socket, &raw_entries[i],1);
        //printf("v:%d|char:%c\n",raw_entries[i],raw_entries[i]);
        if (res <= 0) {
            return READ_ERROR;
        }


        //line break is \r\n\r\n
        if (i >= 3 &&
            raw_entries[i - 3] == '\r' &&
            raw_entries[i - 2] == '\n' &&
            raw_entries[i - 1] == '\r' &&
                raw_entries[i] == '\n'
           ){

            break;
        }
        i++;

    }



    if(i <= 4){return READ_ERROR;}
   // printf("%s\n",raw_entries);

    bool its_valid_utf8 = private_cweb_is_valid_utf8(raw_entries, i);

    unsigned char last_string[MAX_LINE_LEN]= {0};
    struct CwebStringArray *lines = newCwebStringArray();
    int line_index = 0;

    for(int l =0 ; l < i-1;l++){

        if(line_index >= MAX_LINE_LEN){
            CwebStringArray_free(lines);
            return MAX_HEADER_SIZE_CODE;
        }

        if(raw_entries[l] == '\r' && raw_entries[l+1] == '\n'){
            CwebStringArray_add(lines, (const char*)last_string);
            memset(last_string, 0, 10000);
            line_index = 0;
            l++;
            continue;
        }
        if(!its_valid_utf8){
            // if raw_entries its higher than 127 (max char), it means its uniocde
            // 64 its the dif we have to subtract to apply the conversion
            if (raw_entries[l] > 127 ){
                last_string[line_index+1] = (unsigned char)(raw_entries[l] - 64) ;
                last_string[line_index] = 195;
                line_index+=2;
                continue;
            }
        }

        last_string[line_index] = raw_entries[l];
        line_index++;

    }

    if(lines->size == 0){
        CwebStringArray_free(lines);
        return READ_ERROR;
    }



    int line_error = private_CwebHttpRequest_interpret_first_line(self, lines->strings[0]);

    if(line_error){

        CwebStringArray_free(lines);
        return line_error;
    }

    int headers_error = private_CwebHttpRequest_interpret_headders(self, lines);
    CwebStringArray_free(lines);


    if(headers_error){
        return headers_error;
    }
    //const char *content_lenght_str = self->get_header(self, "Content-Length");
    const char *content_lenght_str = CwebHttpRequest_get_header_by_normalized_key(
            self, "contentlength", "- "
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
