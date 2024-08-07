#include "dict.h"
#include "request.h"
#include "response.h"
#include "server.h"
#include "string.h"

#ifndef PRIVATE_CWEB_HTTP_NAMESPACE_NAMESPACE_TYPES
#define PRIVATE_CWEB_HTTP_NAMESPACE_NAMESPACE_TYPES


typedef struct CwebNamespace{
    CwebDictModule dict;
    CwebHttpRequestModule request;
    CwebHttpResponseModule response;
    CwebServerModule server;
    CwebStringArrayModule  string_array;
}CwebNamespace;

#endif //PRIVATE_CWEB_HTTP_NAMESPACE_NAMESPACE_TYPES