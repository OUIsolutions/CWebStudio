## Route a Method

Working with URL parameters is very easy, as seen in the following example:

```c
#include "CWebStudioOne.c"

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    char *url = request->url;
    char *method = request->method;
    char *route = request->route;

    printf("URL: %s\n", url);
    printf("Method: %s\n", method);
    printf("Route: %s\n", route);
    return cweb_send_text("Hello World", 200);

}

int main(int argc, char *argv[]){
    CwebServer server = newCwebSever(5000, main_sever);
    CwebServer_start(&server);
    return 0;
}
```

This example demonstrates how to access the URL, method, and route of an incoming request.