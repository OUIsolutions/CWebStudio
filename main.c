
#include "CWebStudio.c"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    unsigned char *body = request->content;
    int size = request->content_length;

    dtw_write_any_content("test.png", body, size);

    return cweb_send_text("Hello World", 200);
    
}

int main(){

   cweb_run_server(5000, main_sever); 

   return 0;
}