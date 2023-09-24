

void  private_cweb_execute_request(
    int socket,
    const char *ip,
    struct CwebHttpResponse*(*request_handler)( struct CwebHttpRequest *request),
    bool use_static,
    bool use_cache
);

void private_cweb_send_error_mensage( const char*mensage,int status_code, int socket);


void private_cweb_treat_response(int new_socket);




void private_cweb_execute_request_in_safty_mode(
    int new_socket,
    const char *client_ip,
    int function_timeout,
    struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request),
    bool use_static,
    bool use_cache
);



void private_cweb_handle_child_termination(int signal);



void private_cweb_run_server_in_multiprocess(
        int port,
        struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request),
        int function_timeout,
        double client_timeout,
        int max_queue,
        long max_requests,
        bool use_static,
        bool use_cache
);



void private_cweb_run_server_in_single_process(
        int port,
        struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request),
        double client_timeout,
        int  max_queue,
        bool use_static,
        bool use_cache
);



