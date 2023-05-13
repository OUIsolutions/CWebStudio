

void cweb_run_server(
    int port,
    struct CwebHttpResponse *(*request_handler)(struct CwebHttpRequest *request),
    int timeout,
    bool single_process
    ){


    if (single_process){

        private_cweb_run_server_in_single_process(
            port,
            request_handler,
            timeout,
            1
        );
    }

    else{
        private_cweb_run_server_in_multiprocess(
            port,
            request_handler,
            timeout,
            1,
            1
        );
    }
}
