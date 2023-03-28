
#define SAFE_MODE true
#define NOT_SAFE_SINGLE_PROCESS_MODE false


void cweb_run_sever(
    int port,
    struct CwebHttpResponse*(*request_handle)( struct CwebHttpRequest *request),
    bool safe_mode
);