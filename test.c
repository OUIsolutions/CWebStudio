#include "CWebStudio/CwebStudioMain.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    const char *lang = "en";
    const char *text = "text exemple";
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);


    s->$open(s,HTML,"lang=\"%s\"",lang);
        s->open(s,HEAD);
     
        s->close(s,HEAD);
        s->open(s,BODY);
            s->open(s,H1);
                s->segment_text(s,"This is a text");
            s->close(s,H1);
            s->open(s,P);
                s->segment_format(s,"This is a formated  text  %s",text);
            s->close(s,P);

        s->close(s,BODY);
    s->close(s,HTML);
    return cweb_send_rendered_CTextStack_cleaning_memory(s,200);
}

CWEB_START_MACRO(5000, main_sever)