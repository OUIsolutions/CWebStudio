
static size_t actual_request = 0;

#define CWEB_DEFAULT_TIMEOUT 3
#define CWEB_DEFAULT_MAX_BODY 10485760
#define CWEB_DANGEROUS_SINGLE_PROCESS true
#define CWEB_SAFTY_MODE false

void  private_cweb_execute_request(
    int socket,
    size_t max_body_size,
    struct CwebHttpResponse*(*request_handler)( struct CwebHttpRequest *request)
);



void private_cweb_send_error_mensage( const char*mensage,int status_code, int socket);

void private_cweb_treat_response(int new_socket);


void private_cweb_execute_request_in_safty_mode(
    int new_socket,
    size_t max_body_size,
    int time_out,
    struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request)

);
void cweb_run_server(
    int port,
    struct CwebHttpResponse*(*request_handler)( struct CwebHttpRequest *request),
            int timeout,
            size_t max_body_size,
            bool single_process
);
