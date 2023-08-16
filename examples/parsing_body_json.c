#include "../CWebStudio_test.h"
CwebNamespace cweb;
CwebHttpResponse *main_sever( CwebHttpRequest *request ){
    int one_mega_byte = 1048576;
    cweb.request.read_content(request, one_mega_byte);

    cJSON *json = cJSON_Parse((char*)request->content);
    if(!json){
        return cweb.response.send_text("json its not readble",404);
    }

    cJSON *name = cJSON_GetObjectItemCaseSensitive(json, "name");
    cJSON *age = cJSON_GetObjectItemCaseSensitive(json, "age");

    if(!name){
        cJSON_free(json);
        return cweb.response.send_text("name not provided",404);
    }

    if(name->type != cJSON_String){
        cJSON_free(json);
        return cweb.response.send_text("name its not a string",404);
    }
    if(!age){
        cJSON_free(json);
        return cweb.response.send_text("age not provided",404);
    }

    if(age->type != cJSON_Number){
        cJSON_free(json);
        return cweb.response.send_text("age its not a number",404);
    }

    printf("Name: %s\n", name->valuestring);
    printf("Age: %d\n", age->valueint);



    cJSON_free(json);



    return cweb_send_text("json parserd", 200);

}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    struct CwebServer *sever = newCwebSever(5000, main_sever);
    cweb.server.start(sever);
    cweb.server.free(sever);
    return 0;
}