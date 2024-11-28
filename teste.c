#include "src/one.c"
CwebNamespace cweb;

CwebHttpResponse *main_sever(CwebHttpRequest *request ){
    return cweb.response.send_text("Hello World", 200);
}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    struct CwebServer server = newCwebSever(5001, main_sever);
    cweb.server.start(&server);
    return 0;
}
