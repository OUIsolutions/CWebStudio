#include <stdio.h>

#define CWEB_DEBUG
#include "CWebStudio/CwebStudioMain.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    char *route = request->route;
    char mensage[1000];
    sprintf(mensage,"Route Passed: %s",route);
    struct CwebHttpResponse *response = cweb_send_text(mensage,200);
    return response;
}

int main(){

    for(int i =3000;i< 4000;i++){

     struct CwebSever *sever = newCwebSever(i, main_sever);
     sever->start(sever);
     sever->free(sever);
    }




}