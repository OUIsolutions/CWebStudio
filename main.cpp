
#include "CWebStudio/CwebStudioMain.c"


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request){
    request->represent(request);
    return cweb_send_text("aaaaaaaa",200);
}


int main(){

    cweb_run_server(
            8080,
            main_sever,
            5,
            5,
            CWEB_DANGEROUS_SINGLE_PROCESS
            );
}