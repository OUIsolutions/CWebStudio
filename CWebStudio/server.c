

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


void private_cweb_treat_response(int new_socket){
    cweb_print("New request %ld\n", actual_request);
    cweb_print("Waiting for child process\n");
    pid_t wpid;
    int status = 0;
    while (wpid = wait(&status) > 0);

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
        pid_t wpid2;
        int status2 = 0;
        /// Wait for the child process to finish
        while (wpid2 = wait(&status2) > 0);
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
    size_t max_body_size,
    int time_out,
    struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request)
)
{
    cweb_print("Creating a new process\n");
    pid_t pid = fork();
    if (pid == 0){
        // means that the process is the child
        alarm(time_out);
        private_cweb_execute_request(new_socket, max_body_size, request_handler);
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
    
    close(new_socket);
    
    cweb_print("Closed Conection with socket %d\n", new_socket);
}



void cweb_run_server(
    int port,
    struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request),
    int timeout,
    size_t max_body_size,
    bool single_process)
{

    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Faluire to create socket");
        exit(EXIT_FAILURE);
    }

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


        if (single_process)
        {

            private_cweb_execute_request(new_socket, max_body_size, request_handler);
            close(new_socket);
            cweb_print("Closed Conection with socket %d\n", new_socket);
            #ifdef CWEB_ONCE
                        return;
            #endif
        }

        else
        {
            private_cweb_execute_request_in_safty_mode(
                new_socket,
                max_body_size,
                timeout,
                request_handler);
        }
    }
}
