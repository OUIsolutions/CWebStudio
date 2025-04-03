## Returning Values - Plain Text

Returning plain text is simple with **cweb_send_text**:

```c
#include "CWebStudioOne.c"
CwebNamespace cweb;

CwebHttpResponse *main_sever(CwebHttpRequest *request ){


    return cweb.response.send_text("Exemple of Return", 200);
    
}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    CwebServer server = newCwebSever(5000, main_sever);
    cweb.server.start(&server);
    return 0;
}
```

**cweb_send_text_cleaning_memory** can handle strings:

```c
#include "CWebStudioOne.c"

CwebNamespace cweb;

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    char *teste = (char*)malloc(100);
    strcpy(teste, "Hello World");
    return cweb.response.send_text_cleaning_memory(teste,200);
}


int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    CwebServer server = newCwebSever(5000, main_sever);
    cweb.server.start(&server);
    return 0;
}

```

These examples show how to return plain text responses.