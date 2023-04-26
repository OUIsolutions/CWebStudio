
#include "CWebStudio/CwebStudioMain.h"


int executions = 0;

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    
  
    return  cweb_send_file("README.md",CWEB_AUTO_SET_CONTENT,200);
    
}

int main(){
    
    /*
      cweb_run_server(
        8080,
        main_sever,
        CWEB_DEFAULT_TIMEOUT,
        CWEB_DEFAULT_MAX_BODY,
        CWEB_DANGEROUS_SINGLE_PROCESS
    );
    */
    const char *teste = cweb_generate_content_type("teste.html");
    printf("%s\n",teste);
    

}