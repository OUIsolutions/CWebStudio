#include "CWebStudioOne.c"

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    char *teste = (char*)malloc(100);
    strcpy(teste, "Hello World");
    return cweb_send_text_cleaning_memory(teste,200);
}


int main(int argc, char *argv[]){
    CwebServer server = newCwebSever(5000, main_sever);
    CwebServer_start(&server);
    return 0;
}