#define OUI_DEBUG
#include "CWebStudio/CwebStudioMain.c"




struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
       struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    s->text(s,"<!DOCTYPE html>");
    s->$open(s,HTML,"lang=\"en\"");
        s->open(s,HEAD);
     
        s->close(s,HEAD);
        s->open(s,BODY);
            s->open(s,H1);
                s->segment_text(s,"Hello World!");
            s->close(s,H1);
        s->close(s,BODY);
    s->close(s,HTML);

    struct CwebHttpResponse *response = cweb_send_var_html(s->rendered_text,CWEB_OK);
    s->free(s);
    return response;
    
}

int main(){

      cweb_run_server(
        8080,
        main_sever,
        CWEB_DEFAULT_TIMEOUT,
        CWEB_DEFAULT_MAX_BODY,
        CWEB_SAFTY_MODE
    );
}