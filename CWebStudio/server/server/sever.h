

static long long  cweb_actual_request = 0;
static long cweb_total_requests = 0;
static bool cweb_end_server = false;

#define CWEB_DANGEROUS_SINGLE_PROCESS true
#define CWEB_NO_STATIC false;

 typedef struct CwebServer{
    int port;
    int function_timeout;
    double client_timeout;
    int max_queue;
    bool single_process;
    long max_requests;
    bool allow_cors;
    bool use_static;
    const char *static_folder;
    bool use_cache;

    //methods
    CwebHttpResponse *(*request_handler)(CwebHttpRequest *request);

}CwebServer;




CwebServer newCwebSever(int port , CwebHttpResponse *(*request_handler)(CwebHttpRequest *request));
void CwebServer_start(CwebServer *self);


void private_CWebServer_run_server_in_single_process(CwebServer *self);

void private_CWebServer_run_server_in_multiprocess(CwebServer *self);


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








