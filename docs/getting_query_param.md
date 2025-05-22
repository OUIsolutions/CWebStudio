## Getting Query Param

For getting query params, it's super easy, just use the **CwebHttpRequest_get_param** function.

```c
#include "CWebStudioOne.c"

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    char *name = CwebHttpRequest_get_param(request, "name");
    if(name){
        printf("%s\n", name);
    }
    else{
        printf("name not provided\n");
    }
    return cweb_send_text("Hello World", 200);

}

int main(int argc, char *argv[]){
    struct CwebServer server = newCwebSever(5000, main_sever);
    CwebServer_start(&server);
    return 0;
}
```

This example shows how to retrieve a query parameter named 'name' from the request.