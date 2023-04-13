
static size_t actual_request = 0;

#define CWEB_DEFAULT_TIMEOUT 30
#define CWEB_DEFAULT_MAX_REQUEST 50000
#define CWEB_DANGEROUS_SINGLE_PROCESS true
#define CWEB_SAFTY_MODE false

void  private_cweb_execute_request(
    int new_socket,
    size_t max_request_size,
    struct CwebHttpResponse*(*request_handler)( struct CwebHttpRequest *request)
);

void private_cweb_send_error_mensage(int new_socket);

void cweb_run_server(
    int port,
    struct CwebHttpResponse*(*request_handler)( struct CwebHttpRequest *request),
            int timeout,
            size_t max_request_size,
            bool single_process
);
