
#define CWEB_DEBUG
#include "CWebStudio/CwebStudioMain.c"



struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

        return cweb_send_file("captura1.png", CWEB_AUTO_SET_CONTENT, 200);

}

int main(){

    cweb_run_sever(8081, main_sever);
    return 0;
}