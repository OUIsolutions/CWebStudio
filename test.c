#include "CWebStudio.h"

#define SO(s,t) s->open(s, t)
#define SOA(s,t,...) s->$open(s, t, __VA_ARGS__)
#define SC(s,t) s->close(s, t)
#define OPEN(s,t) s->open(s, t); for(int i = 0; i < 1; s->close(s, t), ++i)
#define $OPEN(s,t, ...) s->$open(s, t, __VA_ARGS__); for(int i = 0; i < 1; s->close(s, t), ++i)
#define TEXT(s,t) s->segment_text(s,t)
#define SF(s,t, ...) s->segment_format(s, t, __VA__ARGS__)

int executions = 0;

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    request->represent(request);
    const char *lang = "en";
    const char *text = "text exemple";
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);


    $OPEN(s,HTML,"lang=\"%s\"",lang) {
        OPEN(s,HEAD);
        OPEN(s,BODY) {
            OPEN(s,H1) {
                TEXT(s,"This is a text");
            }
            if( 1 == 1){
                OPEN(s, P) {
                        TEXT(s,"This is a text");
                }
            }
 
         }
    }
    return cweb_send_rendered_CTextStack_cleaning_memory(s,200);
    
}

CWEB_START_MACRO(5000, main_sever)
