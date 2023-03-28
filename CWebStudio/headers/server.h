
#define SAFTY_MODE true
#define DEBUG_MODE false


void cweb_run_sever(
    int port,
    struct CwebHttpResponse*(*request_handle)( struct CwebHttpRequest *request),
    bool safty_mode
);