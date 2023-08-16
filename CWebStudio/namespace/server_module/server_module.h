
typedef struct CwebServerModule{
    CwebServer (*newServer)(int port , CwebHttpResponse *(*request_handler)(CwebHttpRequest *request));
    void (*start)(struct  CwebServer *self);
}CwebServerModule;

CwebServerModule newCwebServerModule();