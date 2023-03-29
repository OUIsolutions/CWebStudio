
#define CWEB_DEBUG
//set the time to 10 seconds
#define CEW_MAX_REQUEST_SIZE 100
#include "CWebStudio.c"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
   //it will return 500 on these aplication

   return cweb_send_text("Hello World", 200);
}

int main(){

   cweb_run_server(5000, main_sever); 

   return 0;
}