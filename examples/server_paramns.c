
#include "../CWebStudio.h"
CwebNamespace cweb;

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    return cweb.response.send_text("Hello World", 200);

}

int main(){
    cweb = newCwebNamespace();

    CwebServer server = newCwebSever(5000, main_sever);
    //the higher time of the request handler
    //after that , the sever will return 500
    // these is useful to prevent the server infinite loop
    server.function_timeout = 30;
    //the higher time of the client
    //after that , the sever will return 408
    //these is useful to prevent invalid requests
    server.client_timeout = 5;

    //these atributes define to allow cros origins domains
    server.allow_cors = true;
    
    //the max queue of the server
    server.max_queue = 100;
    //if true , the server will run in single process
    server.single_process = false;
    //the max simultaneous requests
    server.max_requests = 1000;
    //if true , the server will use the static files located into the folder "static"
    server.use_static = true;

    cweb.server.start(&server);
    return 0;
}