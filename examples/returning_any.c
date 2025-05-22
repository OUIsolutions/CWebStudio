#include "CWebStudioOne.c"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    const char *html = "<html><body><h1>Hello World</h1></body></html>";
    return cweb_send_any("text/html",strlen(html),(unsigned char*)html,200);
}

int main(int argc, char *argv[]){
    CwebServer server = newCwebSever(5000, main_sever);
    CwebServer_start(&server);
    return 0;
}