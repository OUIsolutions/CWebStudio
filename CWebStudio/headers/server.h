
static size_t actual_request = 0;



#define CWEB_DEFAULT_TIMEOUT 30
#define CWEB_MAX_REQUEST_SIZE 5000
#define CWEB_DANGEROUS_SINGLE_PROCESS true
#define CWEB_SAFTY_MODE false

void  private_cweb_execute_request(
    int new_socket,
    size_t max_request_size,
    int time_limit,
    struct CwebHttpResponse*(*request_handle)( struct CwebHttpRequest *request)
);

void private_cweb_send_error_mensage(int new_socket);

void cweb_run_server(
    int port,
    struct CwebHttpResponse*(*request_handle)( struct CwebHttpRequest *request),
            int timeout,
            size_t max_request_size,
            bool single_process,
            int total_process
);
