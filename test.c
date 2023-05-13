#define CWEB_DEBUG
#include "CWebStudio/CwebStudioMain.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    return cweb_send_text("Hello World", 200);
}

int main(){
    for(int i =3000;i< 4000;i++){
     cweb_run_server(i,main_sever,10,CWEB_DEFAULT_MAX_QUEUE, CWEB_DANGEROUS_SINGLE_PROCESS);

    }

}