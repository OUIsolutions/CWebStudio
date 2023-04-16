
#include "CWebStudio/CwebStudioMain.c"


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    return cweb_send_text("Hello World",200);
    
}

int main(){
    cweb_run_server(
        80,
        main_sever,
        10,
        50000,
        CWEB_DANGEROUS_SINGLE_PROCESS
    );
    return 0;
}

