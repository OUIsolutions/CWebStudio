

#include "CWebStudio.h"

int executions = 0;

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    request->represent(request);
    return  cweb_send_file("a.out",CWEB_AUTO_SET_CONTENT,200);
    
}

int main(){
    
    
      cweb_run_server(
        8080,
        main_sever,
        CWEB_DEFAULT_TIMEOUT,
        CWEB_DEFAULT_MAX_BODY,
        CWEB_DANGEROUS_SINGLE_PROCESS
    );
    

    

}