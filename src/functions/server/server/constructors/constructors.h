

struct CwebServer  newCwebSever(int port , CwebHttpResponse *(*request_handler)(CwebHttpRequest *request));

int CwebServer_start(CwebServer *self);
