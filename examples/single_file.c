#include "CWebStudioOne.c"

CwebHttpResponse *main_sever(CwebHttpRequest *request ){
    return cweb_send_text("Hello World", 200);
}

int main(int argc, char *argv[]){
    CwebServer server = newCwebSever(5000, main_sever);
    CwebServer_start(&server);
    return 0;
}