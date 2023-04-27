#include "CWebStudio.h"


#include "CWebStudio.h"

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
