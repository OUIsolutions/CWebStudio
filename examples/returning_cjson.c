#include "CWebStudioOne.c"

CwebHttpResponse *main_sever(CwebHttpRequest *request ){


    cJSON * custom = cJSON_CreateObject();
    cJSON_AddStringToObject(custom,"a","value of a");
    cJSON_AddStringToObject(custom,"b","value of b");
    CwebHttpResponse *response = cweb_send_cJSON_cleaning_memory(custom,200);
    return response;
}


int main(int argc, char *argv[]){
    CwebServer server = newCwebSever(5000, main_sever);
    CwebServer_start(&server);
    return 0;
}