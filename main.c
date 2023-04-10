#define CWEB_DEBUG
#include "CWebStudio/CwebStudioMain.c"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
 
     return cweb_send_text("test mensage",200);

}
CWEB_START_MACRO(5000,main_sever);