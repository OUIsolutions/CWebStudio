#define CWEB_DEBUG
#include "CWebStudio/CwebStudioMain.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    request->read_content(request,2000);
   return cweb_send_text("Hello World",200);
    
}

int main(){

    for(int i=3000;i< 4000;i++){
            cweb_run_server(i,main_sever,CWEB_DEFAULT_TIMEOUT,CWEB_DANGEROUS_SINGLE_PROCESS);
    }

    return 0;
}