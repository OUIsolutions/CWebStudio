#define CWEB_ONCE
#include "CWebStudio/CwebStudioMain.c"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    request->represent(request);

    return cweb_send_text("Hello World", 200);
    
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
     int result = request->interpret_first_line(request,"GET /teste2");
     printf("Result:%d",result);


     return 0;
}