## Iterating over Headers

Similar to iterating through URL parameters, iterating through headers is equally as simple:

```c
#include "CWebStudioOne.c"
CwebNamespace cweb;

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    CwebDict *headers = request->headers;
    for(int i = 0; i < headers->size; i++){
        struct CwebKeyVal *key_val = headers->keys_vals[i];
        char *key = key_val->key;
        char *value = key_val->value;
        printf("%s : %s\n", key, value);
    }
    printf("-------------------------------\n");
    return cweb.response.send_text("Headers Iterated", 200);

}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    CwebServer server = newCwebSever(5000, main_sever);
    cweb.server.start(&server);
    return 0;
}
```

This example demonstrates how to iterate through all headers in the request.