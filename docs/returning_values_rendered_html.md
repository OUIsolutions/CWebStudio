## Returning Values - Rendered HTML

To return rendered HTML, the function **cweb_send_rendered_CTextStack** may be used. Memory will be automatically cleaned:

See more at https://github.com/OUIsolutions/CTextEngine

```c
#include "CWebStudioOne.c"


CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    CTextStackModule m = newCTextStackModule();

    CTextStack *s = m.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    const char *lang = "en";
    const char *text = "text exemple";
    CTextScope_format(s, CTEXT_HTML,"lang=\"%s\"",lang){
        CTextScope(s,CTEXT_HEAD){}
        CTextScope(s,CTEXT_BODY){
            CTextScope(s,CTEXT_H1){
                m.segment_text(s,"This is a text");
            }
            CTextScope(s,CTEXT_P){
                m.segment_format(s,"This is a formated  text  %s",text);

            }
        }
    }
    return cweb_send_rendered_CTextStack(s,200);
}


int main(int argc, char *argv[]){
    CwebServer server = newCwebSever(5000, main_sever);
    CwebServer_start(&server);
    return 0;
}

```

This example demonstrates how to return rendered HTML using CTextStack.