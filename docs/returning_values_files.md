## Returning Values - Files

Files can be directly returned by referencing the path:

```c
#include "CWebStudioOne.c"

CwebNamespace cweb;

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    return cweb_send_file(
            "my_image.png",
            CWEB_AUTO_SET_CONTENT,
            200
    );

}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    CwebServer server = newCwebSever(5000, main_sever);
    cweb.server.start(&server);
    return 0;
}
```

This example demonstrates how to return a file directly from the server.