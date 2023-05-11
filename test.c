

#define CWEB_DEBUG
#include "CWebStudio/CwebStudioMain.h"


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    if(strcmp(request->route,"/a") ==0){
        return cweb_send_text("aaa",200);
    }
    return NULL;
}

int main(){

    cweb_run_server(
            5002,
            main_sever,
            CWEB_DEFAULT_TIMEOUT,
            CWEB_DEFAULT_MAX_BODY,
            CWEB_DANGEROUS_SINGLE_PROCESS
    );

}