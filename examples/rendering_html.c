#include "../CWebStudio_test.h"


 CwebHttpResponse *main_sever( CwebHttpRequest *request ){
    const char *lang = "en";
    const char *text = "text exemple";
    CTextStackModule m = newCTextStackModule();
    CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);


    m.$open(s,CTEXT_HTML,"lang=\"%s\"",lang);
        m.open(s,CTEXT_HEAD);

        m.close(s,CTEXT_HEAD);
        m.open(s,CTEXT_BODY);
            m.open(s,CTEXT_H1);
                m.segment_text(s,"This is a text");
            m.close(s,CTEXT_H1);
            m.open(s,CTEXT_P);
                m.segment_format(s,"This is a formated  text  %s",text);
            m.close(s,CTEXT_P);

        m.close(s,CTEXT_BODY);
    m.close(s,CTEXT_HTML);
    return cweb_send_rendered_CTextStack_cleaning_memory(s,200);
}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    struct CwebServer *sever = newCwebSever(5000, main_sever);
    cweb.server.start(sever);
    cweb.server.free(sever);
    return 0;
}
