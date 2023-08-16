
typedef struct CwebNamespace{
    CwebDictModule dict;
    CwebHttpRequestModule request;
    CwebHttpResponseModule response;
}CwebNamespace;

CwebNamespace newCwebNamespace();