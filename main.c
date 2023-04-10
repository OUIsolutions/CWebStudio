#define CWEB_DEBUG
#include "CWebStudio/CwebStudioMain.c"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    sleep(10);
    return cweb_send_file("my_image.png",CWEB_AUTO_SET_CONTENT,200);

}

int main(){
    cweb_run_server(
            5001,
            main_sever,
            CWEB_DEFAULT_TIMEOUT,
            CWEB_MAX_REQUEST_SIZE,
            CWEB_DANGEROUS_SINGLE_PROCESS,
            1
    );
}