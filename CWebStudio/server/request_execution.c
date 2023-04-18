
void private_cweb_execute_request(
    int socket,
    size_t max_body_size,
    struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request))
            {
    cweb_print("Parsing Request\n");
    struct CwebHttpRequest *request = cweb_request_constructor();

    int result = request->parse_http_request(
            request,
            socket,
            max_body_size
    );

    if(result == INVALID_HTTP){
        cweb_print("Invalid HTTP Request\n");
        private_cweb_send_error_mensage("Invalid HTTP Request",400,socket);
        return;
    }

    if(result == MAX_BODY_SIZE){
        cweb_print("Max body size \n");
        private_cweb_send_error_mensage("Max Request size Exceded",400,socket);
        return;
    }

    cweb_print("created request\n");
    cweb_print("Request method: %s\n", request->method);
    cweb_print("Request url: %s\n", request->url);

    struct CwebHttpResponse *response;
    response = request_handler(request);
    cweb_print("executed client lambda\n");


    if (response == NULL){
        response = cweb_send_text(
            "Error 404",
            404);
    };

    char *response_str = response->generate_response(response);
    cweb_print("Response created\n");

    send(socket, response_str, strlen(response_str), MSG_NOSIGNAL);

    // Enviando conteúdo byte a byte

    if (response->exist_content)
    {
        size_t sent = 0;
        while (sent < response->content_length)
        {
            size_t chunk_size = response->content_length - sent;
            if (chunk_size > max_body_size)
            {
                chunk_size = max_body_size;
            }
            ssize_t res = send(socket, response->content + sent, chunk_size, MSG_NOSIGNAL);
            if (res < 0)
            {
                break;
            }
            sent += res;
        }
    }

    free(response_str);
    response->free(response);
    request->free(request);
    cweb_print("Cleared memory\n");
    return;
}

void private_cweb_send_error_mensage( const char*mensage,int status_code, int socket)
{
    struct CwebHttpResponse *response = cweb_send_text(mensage,status_code);
    char *response_str = response->generate_response(response);
    send(socket, response_str, strlen(response_str), 0);
    send(socket, response->content, response->content_length, 0);

    free(response_str);

}

