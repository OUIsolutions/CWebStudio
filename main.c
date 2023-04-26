#define CWEB_ONCE
#include "CWebStudio/CwebStudioMain.h"
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
    
    return cweb_send_rendered_CTextStack(s,200);
}

int main(int argc, char const *argv[]){
 cweb_run_server(
    8080,
    main_sever,
    CWEB_DEFAULT_TIMEOUT,
    CWEB_DEFAULT_MAX_BODY,
    CWEB_DANGEROUS_SINGLE_PROCESS
    );
}