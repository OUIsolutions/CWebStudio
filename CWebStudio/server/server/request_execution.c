

void private_CWebServer_execute_request(
    int socket,
    const char *client_ip,
    struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request),
    bool use_static,
    bool use_cache,
    bool allow_cors
    ){
    cweb_print("Parsing Request\n");
    struct CwebHttpRequest *request = newCwebHttpRequest(socket);
    request->client_ip = strdup(client_ip);


    int result = CwebHttpRequest_parse_http_request(request);
    
    if(result == INVALID_HTTP){
        cweb_print("Invalid HTTP Request\n");
        CwebHttpRequest_free(request);
        return;
    }

    if(result == READ_ERROR){
        cweb_print("Read Error \n");
        CwebHttpRequest_free(request);
        return;
    }
    if(result == MAX_HEADER_SIZE){
        cweb_print("Max Header Size\n");
        CwebHttpRequest_free(request);
        return;
    }

    cweb_print("created request\n");
    cweb_print("Request method: %s\n", request->method);
    cweb_print("Request url: %s\n", request->url);



    CwebHttpResponse *response = NULL;

    if(use_static){
        response = private_cweb_generate_static_response(request,use_cache);
    }




    if(!response){
        response = request_handler(request);

    }

    if(response && allow_cors){
        private_cweb_generate_cors_response(response);
    }
    cweb_print("executed client lambda\n");


    //means that the main function respond nothing
    if (response == NULL){

        if(use_static){
            char *formated_html = cweb_load_string_file_content("static/404.html");
            if(formated_html != NULL){
                response = cweb_send_var_html_cleaning_memory(
                        formated_html,
                        404);
            }
            else{
                response = cweb_send_text(
                        "Error 404",
                        404
                );
            }
        }
        else{
            response = cweb_send_text(
                    "Error 404",
                    404
            );

        }


    }

    char *response_str = CwebHttpResponse_generate_response(response);
    cweb_print("Response created\n");


    
    

    send(socket, response_str, strlen(response_str), MSG_NOSIGNAL);




    // Enviando conteúdo byte a byte
    if (response->exist_content)
    {
        size_t sent = 0;
        while (sent < response->content_length)
        {
            size_t chunk_size = response->content_length - sent;
          
            ssize_t res = send(socket, response->content + sent, chunk_size, MSG_NOSIGNAL);
            if (res < 0)
            {
                break;
            }
            sent += res;
        }
    }

    
    free(response_str);
    CwebHttpResponse_free(response);
    CwebHttpRequest_free(request);
    cweb_print("Cleared memory\n");
}



