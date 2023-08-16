#include "../CWebStudio_test.h"

CwebNamespace cweb;

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    char *teste = malloc(100);
    strcpy(teste, "Hello World");
    return cweb.response.send_text_cleaning_memory(teste,200);
}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    struct CwebServer *sever = newCwebSever(5000, main_sever);
    cweb.server.start(sever);
    cweb.server.free(sever);
    return 0;
}