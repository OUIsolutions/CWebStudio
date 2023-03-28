
static size_t actual_request = 0;

#ifndef CWEB_TIMEOUT
#define CWEB_TIMEOUT 30
#endif 



void cweb_run_sever(
    int port,
    struct CwebHttpResponse*(*request_handle)( struct CwebHttpRequest *request)
);
