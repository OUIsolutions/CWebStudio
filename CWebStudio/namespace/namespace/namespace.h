
typedef struct CwebNamespace{
    CwebDictModule dict;
    CwebHttpRequestModule request;
    CwebHttpResponseModule response;
    CwebServerModule server;
}CwebNamespace;

CwebNamespace newCwebNamespace();