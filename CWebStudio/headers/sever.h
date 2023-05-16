

#define CWEB_DANGEROUS_SINGLE_PROCESS true


typedef struct CwebSever{
    int port;
    int function_timeout;
    double client_timeout;
    int max_queue;
    bool single_process;
    long max_requests;

    //methods
    struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request);
    void (*start)(struct  CwebSever *self);
    void (*free)(struct  CwebSever *self);
};


struct CwebSever *neCwebSever(int port , struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request));
void private_cweb_run_sever(struct  CwebSever *self);
void private_cweb_free_sever(struct CwebSever *self);

