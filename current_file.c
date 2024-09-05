#include "src/declaration.h"

extern CwebNamespace cweb;

CwebHttpResponse *main_sever(CwebHttpRequest *request );


int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    struct CwebServer server = newCwebSever(5000, main_sever);
    cweb.server.start(&server);
    return 0;
}
