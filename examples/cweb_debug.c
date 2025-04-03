
#define CWEB_DEBUG
#include "CWebStudioOne.c"
CwebNamespace cweb;
CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    return cweb.response.send_text("Hello World", 200);
    
}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    CwebServer server = newCwebSever(5000, main_sever);
    cweb.server.start(&server);
    return 0;
}