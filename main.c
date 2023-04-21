#include "CWebStudio/CwebStudioMain.c"


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    
    
    request->represent(request);
    return cweb_send_text("Hello World", 200);
    
}

int main(){

      cweb_run_server(
        8080,
        main_sever,
        CWEB_DEFAULT_TIMEOUT,
        CWEB_DEFAULT_MAX_BODY,
        CWEB_SAFTY_MODE
    );
}