#define CWEB_DEBUG
#include "CWebStudio/CwebStudioMain.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    return cweb_send_text("Hello World", 200);
}

int main(int argc, char *argv[]){


    struct CwebSever *sever = newCwebSever(5002, main_sever);
    sever->single_process = true;
    sever->start(sever);
    sever->free(sever);
}