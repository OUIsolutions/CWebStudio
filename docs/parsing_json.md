## Parsing JSON

CwebStudio has cJSON integrated into the library. For more information, see https://github.com/DaveGamble/cJSON.

```c
#include "CWebStudioOne.c"

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    int one_mega_byte = 1048576;
    cJSON *json  = CWebHttpRequest_read_cJSON(request,one_mega_byte);
    if(!json){
        return cweb_send_text("not passed or not valid json",404);
    }

    cJSON *name = cJSON_GetObjectItemCaseSensitive(json, "name");
    cJSON *age = cJSON_GetObjectItemCaseSensitive(json, "age");

    if(!name){
        return cweb_send_text("name not provided",404);
    }

    if(name->type != cJSON_String){
        return cweb_send_text("name its not a string",404);
    }
    if(!age){
        return cweb_send_text("age not provided",404);
    }

    if(age->type != cJSON_Number){
        return cweb_send_text("age its not a number",404);
    }

    printf("Name: %s\n", name->valuestring);
    printf("Age: %d\n", age->valueint);


    return cweb_send_text("json parserd", 200);

}

int main(int argc, char *argv[]){
    CwebServer server = newCwebSever(5000, main_sever);
    CwebServer_start(&server);
    return 0;
}
```

This example demonstrates how to parse JSON data from the request body.