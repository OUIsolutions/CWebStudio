

void private_cweb_run_server_in_single_process(
    int port,
    struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request),
    int timeout,
    size_t max_body_size
){

    int server_fd, new_socket;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Faluire to create socket");
        exit(EXIT_FAILURE);
    }
    
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Configurando a estrutura de endereço do servidor
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    // Vinculando o socket à porta especificada
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("Faluire to bind socket");
        exit(EXIT_FAILURE);
    }

    // Waiting for connections
    if (listen(server_fd, 3) < 0)
    {
        perror("Faluire to listen connections");
        exit(EXIT_FAILURE);
    }

    // Main loop
    printf("Sever is running on port:%d\n", port);

    while (1)
    {
        actual_request++;

        // Accepting a new connection in every socket
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
        {
            perror("Faluire to accept connection");
            exit(EXIT_FAILURE);
        }

        struct timeval timer;
        timer.tv_sec = timeout;  // tempo em segundos
        timer.tv_usec = 0;  //

        setsockopt(new_socket, SOL_SOCKET, SO_RCVTIMEO, &timer, sizeof(timer));


        cweb_print("----------------------------------------\n");
        cweb_print("Executing request:%ld\n", actual_request);
        cweb_print("Socket: %d\n", new_socket);


    
        private_cweb_execute_request(new_socket, max_body_size, request_handler);
        close(new_socket);
        cweb_print("Closed Conection with socket %d\n", new_socket);
        #ifdef CWEB_ONCE
                    return;
        #endif
        

    }
}

