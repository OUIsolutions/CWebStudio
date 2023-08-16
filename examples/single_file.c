
#include "../CWebStudio_test.h"

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    return cweb_send_text("Hello World", 200);
}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    struct CwebServer *sever = newCwebSever(5000, main_sever);
    cweb.server.start(sever);
    cweb.server.free(sever);
    return 0;
}