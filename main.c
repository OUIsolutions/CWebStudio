
#include "CWebStudio.c"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){


    return cweb_send_file(
        "my_image.png",
        CWEB_AUTO_SET_CONTENT,
        200
    );
    
}

int main(){

   cweb_run_server(5000, main_sever); 

   return 0;
}