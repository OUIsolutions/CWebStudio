

void private_cweb_run_server_in_single_process(
    int port,
    struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request),
    double client_timeout,
    int max_queue,
    bool use_static,
    bool use_cache
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








    while (1)
    {

        if(cweb_end_server){
                    cweb_print("Break in request %lld\n", cweb_actual_request);
                    break;
        }

        cweb_actual_request++;

        //clear every trash 

        // Accepting a new connection in every socket
        int client_socket = accept(
            port_socket,
            (struct sockaddr *)&address,
            (socklen_t *)&addrlen
        );

        char client_ip[INET_ADDRSTRLEN+2];
        inet_ntop(AF_INET, &(address.sin_addr), client_ip, INET_ADDRSTRLEN);


        cweb_print("----------------------------------------\n");
        cweb_print("Executing request:%lld\n", cweb_actual_request);
        cweb_print("Socket: %d\n", client_socket);


        if ( client_socket< 0){
            perror("Faluire to accept connection");
            exit(EXIT_FAILURE);
        }
        
        struct timeval timer1;
        timer1.tv_sec =  0;
        timer1.tv_usec =  0100000;
        setsockopt(client_socket, SOL_SOCKET, SO_RCVTIMEO, &timer1, sizeof(timer1));


        char buffer[1];
        ssize_t peek_result = recv(client_socket, buffer, 1, MSG_PEEK);

        if (peek_result <= 0) {
            cweb_print("peek: %li\n",peek_result);
            cweb_print("Conection closed By the  Client\n");
            close(client_socket);  // Fechar o socket do cliente
            continue;
        }
        
        
        struct timeval timer2;
        long seconds =  (long)client_timeout;
        timer2.tv_sec =  seconds ;  // tempo em segundos
        timer2.tv_usec =(long)((client_timeout - seconds) * 1000000);
        setsockopt(client_socket, SOL_SOCKET, SO_RCVTIMEO, &timer2, sizeof(timer2));


        private_cweb_execute_request(client_socket,client_ip,request_handler,use_static,use_cache);


        close(client_socket);


        cweb_print("Closed Conection with socket %d\n", client_socket);

        
    }
    return; 
}

