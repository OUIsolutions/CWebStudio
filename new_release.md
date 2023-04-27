## Cweb Studio Report
https://github.com/OUIsolutions/CWebStudio

Report About Cweb Studio Status
We listen to everyone's suggestions and follow up on everything that's been done.

## Bug fixes:
  - parsing problems in headers and body detected by skeeto have been resolved (Thanks Dude)
- Performance failures, also detected by seekto also resolved
## Settings
   - Reduction of dependencies, the final header dropped from 8200k lines to 5277
  - We changed the extension from .c to dot h, as almost everyone asked
## New Features:
- Full url encoded support added
- Added the **CTextEngine** engine in the project
link: https://github.com/OUIsolutions/CTextEngine

Below is an example of html rendering with the new engine
~~~c


#include "CWebStudio.h"

int executions = 0;

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    request->represent(request);
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
~~~