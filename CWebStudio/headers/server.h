
static size_t actual_request = 0;



#ifndef CWEB_TIMEOUT
#define CWEB_TIMEOUT 30
#endif 

void  private_cweb_execute_request(
    int new_socket,
    struct CwebHttpResponse*(*request_handle)( struct CwebHttpRequest *request)
);

void private_cweb_send_error_mensage(int new_socket);

void cweb_run_server(
    int port,
    struct CwebHttpResponse*(*request_handle)( struct CwebHttpRequest *request)
);
