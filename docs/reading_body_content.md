## Reading Body Content

Accessing the body content may be done by calling the function **request->read_content**. The content will be accessible with **request->content** and **request->content_length**:

```c
#include "CWebStudioOne.c"

CwebHttpResponse *main_sever(CwebHttpRequest *request ){
    int one_mega_byte = 1048576;

    unsigned char *body =  CwebHttpRequest_read_content(request, one_mega_byte);

    if(body){
        printf("body: %s",(char*)body);
         return cweb_send_text("Body Readed", 200);

    }
    return cweb_send_text("Body Not Readed", 200);


}

int main(int argc, char *argv[]){
    CwebServer server = newCwebSever(5000, main_sever);
    CwebServer_start(&server);
    return 0;
}
```

This example shows how to read the body content of the request.