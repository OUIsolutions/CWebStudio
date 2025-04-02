
 typedef struct CwebServer{
    int port;
    int function_timeout;
    double client_timeout;
    int max_queue;

    #if defined(__linux__)
        bool single_process;
    #endif

    long max_requests;
    bool allow_cors;
    bool use_static;
    const char *static_folder;
    bool use_cache;

    //methods
    CwebHttpResponse *(*request_handler)(CwebHttpRequest *request);

}CwebServer;

