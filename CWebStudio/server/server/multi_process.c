


void private_cweb_execute_request_in_safty_mode(CwebServer  *self,int new_socket, const char *client_ip){

    cweb_print("Creating a new process\n")
    pid_t pid = fork();
    if (pid == 0){
        // means that the process is the child
      
        alarm(self->function_timeout);
        private_CWebServer_execute_request(self,new_socket, client_ip);
        cweb_print("Request executed\n")
        alarm(0);
        exit(0);
    }

    else if (pid < 0){
        perror("Faluire to create a new process");
        exit(EXIT_FAILURE);
    }

    else{
        //means its the current process
        private_cweb_treat_response(self->use_static,new_socket);
    
    }
    
}

void private_CWebServer_run_server_in_multiprocess(CwebServer *self){
    int port_socket;

    // Creating socket file descriptor
    if ((port_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Faluire to create socket");
        exit(EXIT_FAILURE);
    }
    
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Configurando a estrutura de endereço do servidor
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(self->port);


    // Vinculando o socket à porta especificada
    if (bind(port_socket, (struct sockaddr *)&address, sizeof(address)) < 0){
        perror("Faluire to bind socket");
        return;
    }
    


    // Waiting for connections
    if (listen(port_socket, self->max_queue) < 0)
    {
        perror("Faluire to listen connections");
        exit(EXIT_FAILURE);
    }
    

    // Main loop
    printf("Sever is running on port:%d\n", self->port);



    bool informed_mensage= false;
    while (true)
    {

        if(cweb_total_requests >= self->max_requests){

            if(!informed_mensage){
                printf("max requests reached\n");
                informed_mensage = true;
            }

            continue;
        }

        cweb_print("total request  runing %li\n", cweb_total_requests)

        informed_mensage = false;
        cweb_actual_request++;
        cweb_total_requests++;

        // Accepting a new connection in every socket
        int client_socket = accept(
            port_socket,
            (struct sockaddr *)&address, 
            (socklen_t *)&addrlen
        );

        char client_ip[INET_ADDRSTRLEN] ={0};
        inet_ntop(AF_INET, &(address.sin_addr), client_ip, INET_ADDRSTRLEN);

        cweb_print("----------------------------------------\n")
        cweb_print("Executing request:%lld\n", cweb_actual_request)
        cweb_print("Socket: %d\n", client_socket);


        if (client_socket <  0){
            perror("Faluire to accept connection");
            exit(EXIT_FAILURE);
        }

        pid_t pid = fork();
        if (pid == 0){
            
            // creates an new socket and parse the request to the new socket
            int new_socket = dup(client_socket);

            struct timeval timer1;
            timer1.tv_sec =  0;
            timer1.tv_usec =  0100000;
            setsockopt(new_socket, SOL_SOCKET, SO_RCVTIMEO, &timer1, sizeof(timer1));


            char buffer[1];
            ssize_t peek_result = recv(new_socket, buffer, 1, MSG_PEEK);

            if (peek_result <= 0) {
                cweb_print("peek: %li\n",peek_result);
                cweb_print("Conection closed By the  Client\n");
                close(new_socket);  // Fechar o socket do cliente
                exit(0);
            }

            struct timeval timer2;
            long seconds =  (long)self->client_timeout;
            timer2.tv_sec =  seconds ;  // tempo em segundos
            timer2.tv_usec =(long)((self->client_timeout - (double)seconds) * 1000000);
            setsockopt(new_socket, SOL_SOCKET, SO_RCVTIMEO, &timer2, sizeof(timer2));



            private_cweb_execute_request_in_safty_mode(self,new_socket,client_ip);


            close(new_socket);
            cweb_print("Closed Conection with socket %d\n", new_socket);

            exit(0);
        }


        else if (pid < 0){

            perror("Faluire to create a new process");
            exit(EXIT_FAILURE);
        }

        else{
            close(client_socket);
            cweb_print("Closed Conection with socket %d\n", client_socket);
            //make the parent process ignore the SIGCHLD signal
            signal(SIGCHLD, private_cweb_handle_child_termination);
            continue;
        }
        
  
    }
}
