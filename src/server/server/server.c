

struct CwebServer  newCwebSever(int port , CwebHttpResponse *(*request_handler)(CwebHttpRequest *request)){
    struct CwebServer self = {0};
    self.port = port;
    self.function_timeout = 30;
    self.client_timeout = 5;
    self.max_queue = 100;
    self.single_process = false;
    self.allow_cors = true;
    self.max_requests = 1000;
    self.static_folder = "static";
    self.use_static = true;
    self.use_cache = true;
    
    self.request_handler = request_handler;

    return self;
}


int CwebServer_start(CwebServer *self){
    cweb_static_folder = self->static_folder;

    if (self->single_process){
       return  private_CWebServer_run_server_in_single_process(self);
    }

      return  private_CWebServer_run_server_in_multiprocess(self);


}

