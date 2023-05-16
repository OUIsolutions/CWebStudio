#define CWEB_DEBUG
#include "CWebStudio/CwebStudioMain.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    sleep(10);
    char *route = request->route;
    char mensage[1000];
    sprintf(mensage,"Route Passed: %s",route);
    struct CwebHttpResponse *response = cweb_send_text(mensage,200);
    return response;
}

int main(){
    for(int i =3000;i< 4000;i++){

     cweb_run_server(
             i,
             main_sever,
             20,
             CWEB_DEFAULT_MAX_QUEUE,
             CWEB_SAFTY_MODE,
             CWEB_DEAFAULT_MAX_REQUESTS
             );

    }

}