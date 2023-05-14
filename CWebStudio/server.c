

void private_cweb_execute_request(
    int socket,
    struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request)
    ){
    cweb_print("Parsing Request\n");
    struct CwebHttpRequest *request = cweb_request_constructor(socket);

    int result = request->parse_http_request(request);
    
    if(result == INVALID_HTTP){
        cweb_print("Invalid HTTP Request\n");
        request->free(request);
        return;
    }

    if(result == READ_ERROR){
        cweb_print("Read Error \n");
        request->free(request);
        return;
    }
    if(result == MAX_HEADER_SIZE){
        cweb_print("Max Header Size\n");
        request->free(request);
        return;
    }

    cweb_print("created request\n");
    cweb_print("Request method: %s\n", request->method);
    cweb_print("Request url: %s\n", request->url);



    struct CwebHttpResponse *response;
    #ifndef CWEB_NO_STATIC
        response = private_cweb_generate_static_response(request);
        if(response == NULL){
            response = request_handler(request);
        }
    #else
        response = request_handler(request);
    #endif

    cweb_print("executed client lambda\n");
    //clear buffer of the socket

    //means that the main function respond nothing
    if (response == NULL){

        #ifndef CWEB_NO_STATIC

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

        #else

            response = cweb_send_text(
                    "Error 404",
                    404
            );

        #endif


    }

    char *response_str = response->generate_response(response);
    cweb_print("Response created\n");

    send(socket, response_str, strlen(response_str), MSG_NOSIGNAL);


    //envia todo o content de uma vez 

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
    response->free(response);
    request->free(request);
    cweb_print("Cleared memory\n");
}


void private_cweb_send_error_mensage( const char*mensage,int status_code, int socket)
{
    struct CwebHttpResponse *response;
    #ifndef CWEB_NO_STATIC
        char code_file[30];
        sprintf(code_file,"static/%d.html",status_code);
        char *error_html = cweb_load_string_file_content(code_file);
        if(error_html != NULL){
                response = cweb_send_var_html_cleaning_memory(error_html,status_code);
        }
        else{
            response = cweb_send_text(mensage,status_code);
        }
    #else
        response = cweb_send_text(mensage,status_code);
    #endif

    char *response_str = response->generate_response(response);
    send(socket, response_str, strlen(response_str), 0);
    send(socket, response->content, response->content_length, 0);


    response->free(response);
    free(response_str);

}


void private_cweb_treat_response(int new_socket){
    cweb_print("New request %lld\n", actual_request);
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
    int time_out,
    struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request)
)
{
    cweb_print("Creating a new process\n");
    pid_t pid = fork();
    if (pid == 0){
        // means that the process is the child
        alarm(time_out);
        private_cweb_execute_request(new_socket,request_handler);
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
    bool single_process){


    //limpando lixo de memoria
    actual_request = 0;


    int server_fd, new_socket;
    struct sockaddr_in address = {0};
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
        printf("Faluire to bind socket to port %d\n", port);
        return;
    }

    
    // Waiting for connections
    if (listen(server_fd, 1000) < 0)
    {
        perror("Faluire to listen connections");
        exit(EXIT_FAILURE);
    }

    //creating the static file
    #ifndef CWEB_NO_STATIC
        #ifdef __linux__
             mkdir("static",0777);
        #elif _WIN32
            _mkdir("static");
        #endif
    #endif

    
    struct timeval timer;
    timer.tv_sec = timeout;  // tempo em segundos
    timer.tv_usec = 100;  //


    printf("Sever is running on port:%d\n", port);

    while (1)
    {
        actual_request++;

      
        // Accepting a new connection in every socket
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0){
            perror("Faluire to accept connection");
            exit(EXIT_FAILURE);
        }
        

        setsockopt(new_socket, SOL_SOCKET, SO_RCVTIMEO, &timer, sizeof(timer));

        
        cweb_print("----------------------------------------\n");
        cweb_print("Executing request:%lld\n", actual_request);
        cweb_print("Socket: %d\n", new_socket);


        if (single_process){
          
            private_cweb_execute_request(new_socket, request_handler);
            close(new_socket);
      

         
            cweb_print("Closed Conection with socket %d\n", new_socket);
            #ifdef CWEB_ONCE
                        return;
            #endif
        }

        else{
            private_cweb_execute_request_in_safty_mode(
                new_socket,
                timeout,
                request_handler
                );
        }

    }
   
}
