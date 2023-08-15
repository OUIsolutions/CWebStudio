

static long long  actual_request = 0;
static long total_requests = 0;

#define CWEB_DANGEROUS_SINGLE_PROCESS true
#define CWEB_NO_STATIC false;

 typedef struct CwebSever{
    int port;
    int function_timeout;
    double client_timeout;
    int max_queue;
    bool single_process;
    long max_requests;
    
    bool use_static;

    bool use_cache;

    //methods
    CwebHttpResponse *(*request_handler)(CwebHttpRequest *request);

}CwebSever;




CwebSever *newCwebSever(int port ,CwebHttpResponse *(*request_handler)(CwebHttpRequest *request));
void CwebSever_start(CwebSever *self);
void CwebSever_free(CwebSever *self);



