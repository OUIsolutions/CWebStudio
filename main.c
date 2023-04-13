#define CWEB_DEBUG
#include "CWebStudio/CwebStudioMain.c"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    unsigned char *body = request->content;
    int size = request->content_length;

    //dtw_write_any_content("test.png", body, size);

    return cweb_send_file("teste2.png",CWEB_AUTO_SET_CONTENT, 200);

}

int main(){

    cweb_run_server(
            8081,
            main_sever,
            CWEB_DEFAULT_TIMEOUT,
            1000000,
            CWEB_SAFTY_MODE
            );
}