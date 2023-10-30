

void private_cweb_execute_request(
        int socket,
        const char *client_ip,
        struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request),
        bool use_static,
        bool use_cache,
        bool allow_cors
);

void private_cweb_send_error_mensage( const char*mensage,int status_code, int socket);


void private_cweb_treat_response(int new_socket);




void private_cweb_execute_request_in_safty_mode(int new_socket, const char *client_ip, int function_timeout,
                                                CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *),
                                                bool use_static, bool use_cache, bool allow_cors);



void private_cweb_handle_child_termination(int signal);



void private_cweb_run_server_in_multiprocess(int port, CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *),
                                             int function_timeout, double client_timeout, int max_queue,
                                             long max_requests, bool use_static, bool use_cache, bool allow_cors);



void private_cweb_run_server_in_single_process(int port, CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *),
                                               double client_timeout, int max_queue, bool use_static, bool use_cache,
                                               bool allow_cors);



