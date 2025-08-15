//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dep_define.h"
//silver_chain_scope_end

 CwebServer  newCwebSever(int port , CwebHttpResponse *(*request_handler)(CwebHttpRequest *request)){
    struct CwebServer self = {0};
    self.port = port;
    self.function_timeout = 30;
    self.client_timeout = 5;
    self.max_queue = 100;

    #if defined(__linux__) || defined(__APPLE__)
        self.single_process = false;
    #endif

    self.allow_cors = true;
    self.max_requests = 1000;
    self.static_folder = "static";
    self.use_static = true;
    self.use_cache = true;

    self.request_handler = request_handler;

    return self;
}

#if defined(__linux__) || defined(__APPLE__)

int CwebServer_start(CwebServer *self){
    cweb_static_folder = self->static_folder;
    if (self->single_process){
       return  private_CWebServer_run_server_in_single_process(self);
    }
    return  private_CWebServer_run_server_in_multiprocess(self);
}
#endif


#if defined(_WIN32)
int CwebServer_start(CwebServer *self){
    cweb_static_folder = self->static_folder;
    return  private_CWebServer_run_server_in_single_process(self);
}
#endif
