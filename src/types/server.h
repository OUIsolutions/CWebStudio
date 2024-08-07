#include "response.h"
#include "request.h"

#ifndef PRIVATE_CWEB_HTTP_SERVER_TYPES
#define PRIVATE_CWEB_HTTP_SERVER_TYPES

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

#endif //PRIVATE_CWEB_HTTP_SERVER_TYPES