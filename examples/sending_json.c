
#include "../CWebStudio_test.h"

CwebNamespace cweb;

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    const char *json = "{\"name\":\"CWebStudio\",\"version\":\"1.0.0\"}";
    return cweb.response.send_json_string(json,200);

}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    struct CwebServer *sever = newCwebSever(5000, main_sever);
    cweb.server.start(sever);
    cweb.server.free(sever);
    return 0;
}