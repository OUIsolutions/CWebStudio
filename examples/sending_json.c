#include "CWebStudioOne.c"

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    const char *json = "{"name":"CWebStudio","version":"1.0.0"}";
    return cweb_send_json_string(json,200);

}



int main(int argc, char *argv[]){
    CwebServer server = newCwebSever(5000, main_sever);
    CwebServer_start(&server);
    return 0;
}