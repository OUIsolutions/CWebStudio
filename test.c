#define CWEB_DEBUG
#include "CWebStudio/CwebStudioMain.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    
    char *route = request->route;

    char mensage[30];
    sprintf(mensage, "Hello World: %s", route);
    sleep(10);

    
    return cweb_send_text(mensage, 200);
}

int main(int argc, char *argv[]){


    struct CwebSever *sever = newCwebSever(5000, main_sever);
    sever->single_process= true;
    sever->start(sever);
    sever->free(sever);
}