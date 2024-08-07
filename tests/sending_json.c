
#include "../CWebStudio.h"

CwebNamespace cweb;

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    const char *json = "{\"name\":\"CWebStudio\",\"version\":\"1.0.0\"}";
    return cweb.response.send_json_string(json,200);

}



int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    CwebServer server = newCwebSever(5000, main_sever);
    cweb.server.start(&server);
    return 0;
}