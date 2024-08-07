#include "../server.h"

#ifndef PRIVATE_CWEB_HTTP_NAMESPACE_SERVER_TYPES
#define PRIVATE_CWEB_HTTP_NAMESPACE_SERVER_TYPES


typedef struct CwebServerModule{
    CwebServer (*newServer)(int port , CwebHttpResponse *(*request_handler)(CwebHttpRequest *request));
    int (*start)(struct  CwebServer *self);
}CwebServerModule;

#endif //PRIVATE_CWEB_HTTP_NAMESPACE_SERVER_TYPES