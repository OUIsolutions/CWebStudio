
#include "../CWebStudio_test.h"

CwebNamespace cweb;

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    char *url = request->url;
    char *method = request->method;
    char *route = request->route;

    printf("URL: %s\n", url);
    printf("Method: %s\n", method);
    printf("Route: %s\n", route);
    return cweb.response.send_text("Hello World", 200);

}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    struct CwebServer *sever = newCwebSever(5000, main_sever);
    cweb.server.start(sever);
    cweb.server.free(sever);
    return 0;
}