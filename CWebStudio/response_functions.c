


struct CwebHttpResponse* cweb_send_any(const char *content_type,size_t content_length,unsigned char *content,int status_code){
    struct CwebHttpResponse *response = create_http_response();
    response->add_header(response, "Content-Type", content_type);
    response->set_content(response, content, content_length);
    response->status_code = status_code;
    return response;
}


struct CwebHttpResponse* cweb_send_text(const char *content,int status_code){
    return cweb_send_any("text/plain", strlen(content), (unsigned char*)content, status_code);
}


struct CwebHttpResponse* cweb_send_file(const char *file_path,const char *content_type,int status_code){
    
    int size = 0;
    unsigned char *content = dtw_load_binary_content(file_path, &size);
    cweb_print("Writen size: %i\n",size);
    if(content == NULL){
        char *mensage = (char*)malloc(100);
        sprintf(mensage, "File not found: %s", file_path);
        struct CwebHttpResponse* response =  cweb_send_text(mensage, CWEB_NOT_FOUND);
        free(mensage);
        return response;
    }


    struct DtwPath *path = dtw_constructor_path(file_path);
    char *content_type_created = (char*)malloc(100);
    if(content_type == NULL){
        char *extension = path->get_extension(path);
        if(strcmp(extension, "html") == 0){
            strcpy(content_type_created, "text/html");
        }
        else if(strcmp(extension, "css") == 0){
            strcpy(content_type_created, "text/css");
        }
        else if(strcmp(extension, "js") == 0){
            strcpy(content_type_created, "text/javascript");
        }
        else if(strcmp(extension, "png") == 0){
            strcpy(content_type_created, "image/png");
        }
        else if(strcmp(extension, "jpg") == 0){
            strcpy(content_type_created, "image/jpeg");
        }
        else if(strcmp(extension, "jpeg") == 0){
            strcpy(content_type_created, "image/jpeg");
        }
        else{
            strcpy(content_type_created, "text/plain");
        }
        free(extension);
    }
    else{
        strcpy(content_type_created, content_type);
    }

    return cweb_send_any(content_type_created, size, content, status_code);
    
}