#include "../CWebStudio_test.h"

CwebHttpResponse *main_sever( CwebHttpRequest *request ){
    int one_mega_byte = 1048576;
    request->read_content(request, one_mega_byte);
    unsigned char *body = request->content;
    int size = request->content_length;

    //parse with cJson the body 

    cJSON *json = cJSON_Parse(body);
    cJSON *name = cJSON_GetObjectItemCaseSensitive(json, "name");
    cJSON *age = cJSON_GetObjectItemCaseSensitive(json, "age");


    printf("Name: %s\n", name->valuestring);
    printf("Age: %d\n", age->valueint);


    return cweb_send_text("Hello World", 200);
    
}

CWEB_START_MACRO(5001, main_sever);