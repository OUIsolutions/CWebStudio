#define CWEB_DEBUG
#include "CWebStudio.c"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    return cweb_send_text("Hello World", 200);

}

int main(){
    size_t max_size = 2000;
    cweb_run_server(
            5000,
            main_sever,
            CWEB_DEFAULT_TIMEOUT,
            max_size,
            CWEB_DANGEROUS_SINGLE_PROCESS,
            1
            );
}