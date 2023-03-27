



void cweb_run_sever(
    int port,
    struct CwebHttpResponse*(*request_handle)( struct CwebHttpRequest *request)
){

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[CEW_MAX_REQUEST_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Faluire to create socket");
        exit(EXIT_FAILURE);
    }

    // Configurando a estrutura de endereço do servidor
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    // Vinculando o socket à porta especificada
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Faluire to bind socket");
        exit(EXIT_FAILURE);
    }

    // Waiting for connections
    if (listen(server_fd, 3) < 0) {
        perror("Faluire to listen connections");
        exit(EXIT_FAILURE);
    }

    // Main loop
    while(1) {
        // Accepting a new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("Faluire to accept connection");
            exit(EXIT_FAILURE);
        }

        // Lendo a solicitação HTTP do cliente
        valread = read(new_socket, buffer, CEW_MAX_REQUEST_SIZE);


        // Verificando se a solicitação HTTP é válida
        if (strstr(buffer, "HTTP/1.") == NULL) {
            fprintf(stderr, "Solicitation HTTP invalid\n");
            exit(EXIT_FAILURE);
        }

        struct CwebHttpRequest *request  = private_cweb_create_http_request(
                buffer
        );
        struct CwebHttpResponse *response = request_handle(request);
        char *response_str = response->generate_response(response);
        
        send(new_socket, response_str,strlen(response_str) , 0);
        if(response->exist_content){
            send(new_socket, response->content, response->content_length, 0);
        }
        free(response_str);
        
        response->free(response);
        request->free(request);
        //Closing the connection with the client
        close(new_socket);
    }
    
}
