
#define CWEB_DEBUG 
#define CWEB_TIMEOUT 1
#define CWEB_SINGLE_PROCESS
#include "CWebStudio/CwebStudioMain.c"


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
   char *a = request->params->get_value(request->params, "a");
   char *b = request->params->get_value(request->params, "b");
   if(a == NULL || b == NULL){
       return cweb_send_text("Error: a and b are required", 400);
   }
   int a_int = atoi(a);
   int b_int = atoi(b);
   char *result = malloc(100);
   sprintf(result, "value is %d", a_int + b_int);
   return cweb_send_text(result, 200);


}

CWEB_START_MACRO(5000, main_sever);