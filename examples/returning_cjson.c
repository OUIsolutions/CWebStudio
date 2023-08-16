#include "../CWebStudio_test.h"

CwebNamespace cweb;

CwebHttpResponse *main_sever(CwebHttpRequest *request ){


    cJSON * custom = cJSON_CreateObject();
    cJSON_AddStringToObject(custom,"a","value of a");
    cJSON_AddStringToObject(custom,"b","value of b");
    CwebHttpResponse *response = cweb.response.send_cJSON_cleaning_memory(custom,200);
    return response;
}


int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    struct CwebServer *server = newCwebSever(5000, main_sever);
    cweb.server.start(server);
    cweb.server.free(server);
    return 0;
}