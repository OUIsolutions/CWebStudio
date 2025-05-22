#include "CWebStudioOne.c"

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    if(strcmp(request->route,"/kill") == 0){
            cweb_kill_single_process_server();
    }
    return cweb_send_text("Working", 200);

}

int main(int argc, char *argv[]){
    CwebServer server = newCwebSever(5000, main_sever);
    server.single_process = true;
    CwebServer_start(&server);
    return 0;
}