

static long long  cweb_actual_request = 0;
static long cweb_total_requests = 0;
static bool cweb_end_server = false;

#define CWEB_DANGEROUS_SINGLE_PROCESS true
#define CWEB_NO_STATIC false;

 typedef struct CwebServer{
    int port;
    int function_timeout;
    double client_timeout;
    int max_queue;
    bool single_process;
    long max_requests;
    bool allow_cors;
    bool use_static;

    bool use_cache;

    //methods
    CwebHttpResponse *(*request_handler)(CwebHttpRequest *request);

}CwebServer;




CwebServer newCwebSever(int port , CwebHttpResponse *(*request_handler)(CwebHttpRequest *request));
void CwebServer_start(CwebServer *self);



