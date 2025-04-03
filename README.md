# CWebSudio
CWebSudio is a micro framework to deal with web aplications in C/C++. It's a
single file library that provides a lot of functionality such as reading headers,
query parameters, returning files, and text.

# Releases
| Item | Description |
|------|-------------|
|[CWebStudioOne.c](https://github.com/OUIsolutions/CWebStudio/releases/download/4.0.0/CWebStudioOne.c)| CWebStudio One file |
|[CWebStudio.c](https://github.com/OUIsolutions/CWebStudio/releases/download/4.0.0/CWebStudio.c)| Definition|
|[CWebStudio.h](https://github.com/OUIsolutions/CWebStudio/releases/download/4.0.0/CWebStudio.h)| Header|
|[CWebStudio.zip](https://github.com/OUIsolutions/CWebStudio/releases/download/4.0.0/CWebStudio.zip)| Full Folder|

## Most Simple Example

~~~c

#include "CWebStudioOne.c"
CwebNamespace cweb;

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    return cweb_send_text("Hello World", 200);
}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    CwebServer server = newCwebSever(5000, main_sever);
    cweb.server.start(&server);
    return 0;
}
~~~
