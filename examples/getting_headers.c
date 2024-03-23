#include "../CWebStudio.h"

CwebNamespace cweb;

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    char *name = cweb.request.get_header(request,"name");
    if(name){
        printf("%s\n",name);
    }
    else{
        printf("name not provided\n");
    }
    return cweb.response.send_text("Hello World", 200);

}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    struct CwebServer server = newCwebSever(5000, main_sever);
    cweb.server.start(&server);
    return 0;
}