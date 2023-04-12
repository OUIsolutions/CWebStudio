#define CWEB_DEBUG
#include "CWebStudio.c"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
     sleep(10);
     return cweb_send_text("test mensage",200);

}
int main(){
    cweb_run_server(
            5000,
            main_sever,
            CWEB_DEFAULT_TIMEOUT,
            CWEB_DEFAULT_MAX_REQUEST,
            CWEB_DANGEROUS_SINGLE_PROCESS
            );
}