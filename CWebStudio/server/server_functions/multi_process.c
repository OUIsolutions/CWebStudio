

void private_cweb_treat_response(int new_socket){
    cweb_print("New request %lld\n", cweb_actual_request);
    cweb_print("Waiting for child process\n");

    int status = 0;
    while (wait(&status) > 0);

    if (WIFEXITED(status)){
        cweb_print("Sucess\n");
        return;
    }

    pid_t pid_error = fork();
    if (pid_error == 0){
        cweb_print("Sending error mensage\n");
        alarm(2);
        private_cweb_send_error_mensage("Internal Sever Error",500,new_socket);
        alarm(0);
        exit(0);
    }

    else if (pid_error < 0){
                perror("Faluire to create a new process");
                exit(EXIT_FAILURE);
    }
    else{
        int status2 = 0;
        /// Wait for the child process to finish
        while (wait(&status2) > 0);
        if (WIFEXITED(status2)){
            cweb_print("Mensage sent\n");
        }

        else{
            cweb_print("Error sending mensage\n");
        }
    }
}



void private_cweb_execute_request_in_safty_mode(
    int new_socket,
    int function_timeout,
    struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request),
    bool use_static,
    bool use_cache){
    cweb_print("Creating a new process\n");
    pid_t pid = fork();
    if (pid == 0){
        // means that the process is the child
      
        alarm(function_timeout);
        private_cweb_execute_request(new_socket,request_handler,use_static,use_cache);
        cweb_print("Request executed\n");
        alarm(0);
        exit(0);
    }

    else if (pid < 0){
        perror("Faluire to create a new process");
        exit(EXIT_FAILURE);
    }

    else{
        private_cweb_treat_response(new_socket);
    
    }
    
}
void private_cweb_handle_child_termination(int signal) {
    pid_t terminated_child;
    int status;
    while ((terminated_child = waitpid(-1, &status, WNOHANG)) > 0) {
        cweb_total_requests--;
    }
}

void private_cweb_run_server_in_multiprocess(
    int port,
    struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request),
    int function_timeout,
    double client_timeout,
    int max_queue,
    long max_requests,
    bool use_static,
    bool use_cache
){

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
    address.sin_port = htons(port);

    // Vinculando o socket à porta especificada
    if (bind(port_socket, (struct sockaddr *)&address, sizeof(address)) < 0){
        perror("Faluire to bind socket");
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



    bool informed_mensage= false;
    while (true)
    {

        if(cweb_total_requests >= max_requests){

            if(!informed_mensage){
                printf("max requests reached\n");
                informed_mensage = true;
            }

            continue;
        }

        cweb_print("total request  runing %li\n", cweb_total_requests);

        informed_mensage = false;
        cweb_actual_request++;
        cweb_total_requests++;

        // Accepting a new connection in every socket
        int client_socket = accept(
            port_socket,
            (struct sockaddr *)&address, 
            (socklen_t *)&addrlen
        );


        cweb_print("----------------------------------------\n");
        cweb_print("Executing request:%lld\n", cweb_actual_request);
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
                continue;
            }

            struct timeval timer2;
            long seconds =  (long)client_timeout;
            timer2.tv_sec =  seconds ;  // tempo em segundos
            timer2.tv_usec =(long)((client_timeout - seconds) * 1000000);
            setsockopt(new_socket, SOL_SOCKET, SO_RCVTIMEO, &timer2, sizeof(timer2));


            private_cweb_execute_request_in_safty_mode(
                new_socket,
                function_timeout,
                request_handler,
                use_static,
                use_cache
            );

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
