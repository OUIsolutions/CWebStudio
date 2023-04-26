
#include "CWebStudio.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    s->$open(s,HTML,"lang=\"en\"");
        s->open(s,HEAD);
            s->open(s,TITLE);
                s->text(s,"Basic Calculator");
            s->close(s,TITLE);
        s->close(s,HEAD);
        s->open(s,BODY);
            s->auto$close(s,INPUT,"type=\"text\" name=\"visor\" value=\"0\"");
            s->auto$close(s,BR,"");
            s->auto$close(s,INPUT,"type=\"button\" value=\"1\" ");
            s->auto$close(s,INPUT,"type=\"button\" value=\"2\" ");
            s->auto$close(s,INPUT,"type=\"button\" value=\"3\" ");
            s->auto$close(s,INPUT,"type=\"button\" value=\"+\"");
            s->auto$close(s,BR,"");

        s->close(s,BODY);
    s->close(s,HTML);


    return cweb_send_rendered_CTextStack_cleaning_memory(s,200);
}

CWEB_START_MACRO(5000, main_sever)

