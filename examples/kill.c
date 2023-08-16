#include "../CWebStudio_test.h"

CwebNamespace cweb;

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    if(strcmp(request->route,"/kill") == 0){
        cweb_end_server = true;
    }
    return cweb.response.send_text("Working", 200);

}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    struct CwebServer *server = newCwebSever(5000, main_sever);
    server->single_process = true;
    cweb.server.start(server);
    cweb.server.free(server);
    return 0;
}