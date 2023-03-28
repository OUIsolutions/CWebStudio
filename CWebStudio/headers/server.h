
static size_t actual_request = 0;

#ifdef __cplusplus
void cweb_run_sever(
    int port,
    struct CwebHttpResponse*(*request_handle)( struct CwebHttpRequest *request),
    int timeout=30
);
#else
void cweb_run_sever(
    int port,
    struct CwebHttpResponse*(*request_handle)( struct CwebHttpRequest *request),
    int timeout
);
#endif