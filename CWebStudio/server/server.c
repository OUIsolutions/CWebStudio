


void cweb_run_server(
        int port,
        struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request),
        int function_timeout,
        double client_timeout,
        int max_queue,
        bool single_process,
        long max_requests
){
    if (single_process){

        private_cweb_run_server_in_single_process(
            port,
            request_handler,
            client_timeout,
            max_queue
        );
    }

    else{
        private_cweb_run_server_in_multiprocess(
            port,
            request_handler,
            function_timeout,
            client_timeout,
            max_queue,
            max_requests
        );
    }
}
