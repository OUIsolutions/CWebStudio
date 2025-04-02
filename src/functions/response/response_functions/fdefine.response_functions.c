


 CwebHttpResponse* cweb_send_any(const char *content_type,size_t content_length,unsigned char *content,int status_code){
    CwebHttpResponse *response = newCwebHttpResponse();
    CwebHttpResponse_add_header(response, "Content-Type", content_type);
    CwebHttpResponse_set_content(response, content, content_length);
    response->status_code = status_code;
    return response;
}

CwebHttpResponse * cweb_send_json_string(const char *content,int status_code){
   return cweb_send_any(   "application/json", strlen(content),(unsigned char*)content,status_code);
}


CwebHttpResponse * cweb_send_json_string_cleaning_memory(char *content,int status_code){
    CwebHttpResponse  *response = cweb_send_json_string(content,status_code);
    free(content);
    return response;
}

CwebHttpResponse * cweb_send_cJSON(cJSON *content,int status_code){
    char *rendered = cJSON_Print(content);
    CwebHttpResponse  *response =cweb_send_any(
            "application/json",
            strlen(rendered),
            (unsigned char*)rendered,
            status_code
            );
    free(rendered);
    return response;
}



CwebHttpResponse * cweb_send_cJSON_cleaning_memory(cJSON *content,int status_code){
    CwebHttpResponse  *response = cweb_send_cJSON(content,status_code);
    cJSON_Delete(content);
    return response;
}


CwebHttpResponse* cweb_send_any_cleaning_memory(const char *content_type,size_t content_length,unsigned char *content,int status_code){
     CwebHttpResponse *response = cweb_send_any(content_type,content_length,content,status_code);
    free(content);
    return response;
}


CwebHttpResponse* cweb_send_rendered_CTextStack(struct CTextStack *stack,int status_code){
    return cweb_send_var_html(stack->rendered_text,status_code);
}


CwebHttpResponse* cweb_send_text(const char *content,int status_code){
    return cweb_send_any("text/plain", strlen(content), (unsigned char*)content, status_code);
}


CwebHttpResponse* cweb_send_text_cleaning_memory(char *content,int status_code){
    CwebHttpResponse*  response = cweb_send_any("text/plain", strlen(content), (unsigned char*)content, status_code);
    free(content);
    return response;
}


CwebHttpResponse* cweb_send_var_html(const char *content,int status_code){
    return cweb_send_any("text/html", strlen(content), (unsigned char*)content, status_code);
}


 CwebHttpResponse* cweb_send_var_html_cleaning_memory(char *content,int status_code){
     CwebHttpResponse*  response = cweb_send_any("text/html", strlen(content), (unsigned char*)content, status_code);
    free(content);
    return response;
}



CwebHttpResponse* cweb_send_file(const char *file_path,const char *content_type,int status_code){

    int size = 0;
    unsigned char *content;
    content = cweb_load_binary_content(file_path, &size);

    #ifndef CWEB_NO_STATIC
        if(content == NULL){
            char *not_found_html_page = cweb_load_string_file_content("static/404.html");
            if(not_found_html_page != NULL){
                return cweb_send_var_html_cleaning_memory(not_found_html_page,404);
            }
        }
    #endif

    cweb_print("Writen size: %i\n",size);
    if(content == NULL){
        char mensage[100];
        sprintf(mensage, "File not found: %s", file_path);
        CwebHttpResponse* response =  cweb_send_text(mensage, CWEB_NOT_FOUND);
        return response;
    }

    const char *content_type_created;
    if(content_type == NULL){
        content_type_created  = cweb_generate_content_type(file_path);
    }
    else{
        content_type_created = content_type;
    }

    CwebHttpResponse *response =  cweb_send_any(content_type_created, size, content, status_code);


    if(content != NULL){
        free(content);
    }

    return response;

}
