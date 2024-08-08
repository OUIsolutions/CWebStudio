#include "dict.h"
#include "request.h"
#include "response.h"
#include "server.h"
#include "string.h"
#include "hydratation.h"

#ifndef PRIVATE_CWEB_HTTP_NAMESPACE_NAMESPACE_TYPES
#define PRIVATE_CWEB_HTTP_NAMESPACE_NAMESPACE_TYPES


typedef struct CwebNamespace{
    CwebDictModule dict;
    CwebHttpRequestModule request;
    CwebHttpResponseModule response;
    CwebServerModule server;
    CwebStringArrayModule  string_array;
    CWebHydrationNamespace hydration;
}CwebNamespace;

#endif //PRIVATE_CWEB_HTTP_NAMESPACE_NAMESPACE_TYPES