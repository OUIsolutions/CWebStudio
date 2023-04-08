
#define CWEB_DEBUG 
#define BUFFER_IN_HEAP
#define CWEB_SINGLE_PROCESS
#include "CWebStudio/CwebStudioMain.c"


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
   
   return cweb_send_text("Hello World", 200);

}

CWEB_START_MACRO(5000, main_sever);