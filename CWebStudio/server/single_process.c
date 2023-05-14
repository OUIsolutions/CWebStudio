

void private_cweb_run_server_in_single_process(
    int port,
    struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request),
    int timeout,
    int max_queue
){


    int port_socket;

    // Creating socket file descriptor
    if ((port_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
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
    if (bind(port_socket, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        printf("Faluire to bind socket to port %d\n", port);
        return;
      
    }

    // Waiting for connections
    if (listen(port_socket, max_queue) < 0)
    {
        perror("Faluire to listen connections");
        exit(EXIT_FAILURE);
    }

    // Main loop
    printf("Sever is running on port:%d\n", port);

    struct timeval timer;
    timer.tv_sec = timeout;  // tempo em segundos
    timer.tv_usec = 0;  //


    while (1)
    {
        actual_request++;

        // Accepting a new connection in every socket
        int client_socket = accept(
            port_socket,
            (struct sockaddr *)&address,
            (socklen_t *)&addrlen
        );
        
        if ( client_socket< 0){
            perror("Faluire to accept connection");
            exit(EXIT_FAILURE);
        }

      
        setsockopt(client_socket, SOL_SOCKET, SO_RCVTIMEO, &timer, sizeof(timer));


        cweb_print("----------------------------------------\n");
        cweb_print("Executing request:%lld\n", actual_request);
        cweb_print("Socket: %d\n", client_socket);


    
        private_cweb_execute_request(client_socket,request_handler);
        close(client_socket);
        cweb_print("Closed Conection with socket %d\n", client_socket);
        #ifdef CWEB_ONCE
                    return;
        #endif
        

    }
}

