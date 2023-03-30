

#include "CWebStudio.c"


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
   //it will return 500 on these aplication

   return cweb_send_text("Hello World", 200);

}

cweb_start(5001, main_sever);