<<<<<<< HEAD
#define CWEB_DEBUG

#include "CWebStudio/CwebStudioMain.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
   // request->read_content(request,2000);
   return cweb_send_text("Hello World",200);
    
}

int main(){

    for(int i=3000;i< 4000;i++){
            cweb_run_server(i,main_sever,CWEB_DEFAULT_TIMEOUT,CWEB_SAFTY_MODE);
    }

=======
#include "CWebStudio.h"


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    
    sleep(20);
    char resultado[50];
    sprintf(resultado, "Hello World %s", request->route);
    return cweb_send_text(resultado, 200);
    
}


int main(){

    struct CwebSever *sever = newCwebSever(3001, main_sever);
    //the higher time of the request handler 
    //after that , the sever will return 500 
    // these is useful to prevent the server infinite loop
    sever->function_timeout = 30;
    //the higher time of the client
    //after that , the sever will return 408
    //these is useful to prevent invalid requests
    sever->client_timeout = 5;

    //the max queue of the server
    sever->max_queue = 100;
    //if true , the server will run in single process
    sever->single_process =true;
    //the max simultaneous requests
    sever->max_requests = 1;
    //if true , the server will use the static files located into the folder "static"
    sever->use_static = true;
    sever->start(sever);
    sever->free(sever);
>>>>>>> origin/mult_process_new
    return 0;
}