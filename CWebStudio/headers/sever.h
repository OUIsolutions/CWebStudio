

static long long  actual_request = 0;
static long total_requests = 0;

#define CWEB_DANGEROUS_SINGLE_PROCESS true
#define CWEB_NO_STATIC false;

 struct CwebSever{
    int port;
    int function_timeout;
    double client_timeout;
    int max_queue;
    bool single_process;
    long max_requests;
    
    bool use_static;

    bool use_cache;

    //methods
    struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request);
    void (*start)(struct  CwebSever *self);
    void (*free)(struct  CwebSever *self);
};




struct CwebSever *newCwebSever(int port , struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request));
void private_cweb_run_sever(struct  CwebSever *self);
void private_cweb_free_sever(struct CwebSever *self);



