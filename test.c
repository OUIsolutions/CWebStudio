#include "CWebStudio.h"




int executions = 0;

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    request->represent(request);
    const char *lang = "en";
    const char *text = "text exemple";
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    return cweb_send_rendered_CTextStack_cleaning_memory(s,200);
    
}

CWEB_START_MACRO(5000, main_sever)
