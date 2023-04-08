
#define CWEB_DEBUG 

#define CWEB_SINGLE_PROCESS
#include "CWebStudio/CwebStudioMain.c"


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
   char teste[5];
   return cweb_send_text("Hello World", 200);

}

CWEB_START_MACRO(5005, main_sever);