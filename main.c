#define CWEB_DEBUG
#include "CWebStudio.c"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    if(strcmp(request->route, "/test") == 0){
        ///making an error
        int x = 1/0;
        //Your application wont crash here if you are using safity mode
    }
    return cweb_send_text("Hello World", 200);

}

int main(){
    cweb_run_server(
            5000,
            main_sever,
            CWEB_DEFAULT_TIMEOUT,
            CWEB_MAX_REQUEST_SIZE,
            CWEB_SAFTY_MODE,
            1
    );
}