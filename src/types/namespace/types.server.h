

typedef struct CwebServerModule{
    CwebServer (*newServer)(int port , CwebHttpResponse *(*request_handler)(CwebHttpRequest *request));
    int (*start)(struct  CwebServer *self);
}CwebServerModule;

