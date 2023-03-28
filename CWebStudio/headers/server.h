
#define CWEB_ERROR_PAGE "#error#"
#define CWEB_ERROR_PAGE_SIZE 7


void cweb_run_sever(
    int port,
    struct CwebHttpResponse*(*request_handle)( struct CwebHttpRequest *request));