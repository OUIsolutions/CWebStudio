#include "CWebStudio.h"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    struct CTextStack *s  = newCTextStack(CTEXT_LINE_BREAKER,CTEXT_SEPARATOR);
  
    s->$open(s,HTML,"lang=\"%s\"","en");
        s->open(s,HEAD);
        
        s->close(s,HEAD);
        s->open(s,BODY);
            s->open(s,H1);
                s->segment_text(s,"This is a text");
            s->close(s,H1);
            s->open(s,P);
                s->segment_format(s,"This is a formated  text  %s","aaaa");
            s->close(s,P);

        s->close(s,BODY);
    s->close(s,HTML);

    struct CwebHttpResponse * response = cweb_send_var_html(
        s->rendered_text,
        200
    );
    s->free(s);
    return response;
    
}

CWEB_START_MACRO(5001, main_sever);
