


#include "CWebStudio.c"



struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    return cweb_send_text("Hello World", 200);
}

int main(){

   cweb_run_sever(5002, main_sever); 

   return 0;
}