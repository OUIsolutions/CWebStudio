
static long long  actual_request = 0;
static long total_requests = 0;

#define CWEB_DEFAULT_TIMEOUT 30

#define CWEB_DEFAULT_MAX_QUEUE 100
#define CWEB_DANGEROUS_SINGLE_PROCESS true
#define CWEB_SAFTY_MODE false
#define CWEB_DEAFAULT_MAX_REQUESTS 1000


void  private_cweb_execute_request(
    int socket,
    struct CwebHttpResponse*(*request_handler)( struct CwebHttpRequest *request)
);

void private_cweb_send_error_mensage( const char*mensage,int status_code, int socket);


void private_cweb_treat_response(int new_socket);






void private_cweb_execute_request_in_safty_mode(
    int new_socket,
    int time_out,
    struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request)
);

void private_cweb_handle_child_termination(int signal);





void private_cweb_run_server_in_multiprocess(
        int port,
        struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request),
        int timeout,
        long max_queue,
        long max_requests
);

void private_cweb_run_server_in_single_process(
        int port,
        struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request),
        int timeout,
        long  max_queue
);

void cweb_run_server(
    int port,
    struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request),
    int timeout,
    long max_queue,
    bool single_process,
    long max_requests
    );
