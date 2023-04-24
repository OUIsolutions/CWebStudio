#define CWEB_ONCE

#include "CWebStudio/CwebStudioMain.c"




struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    
    /*
    char *test = (char*)malloc(100);
    strcpy(test,"Hello World!");
    */
    return cweb_send_text("aaaaa",CWEB_OK);
    
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
   struct CwebHttpRequest *request = cweb_request_constructor();
   request->interpret_first_line(request,"GET /aaa HTTP/1.1");
   request->free(request);
}