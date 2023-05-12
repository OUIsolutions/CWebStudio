#define CWEB_DEBUG
#include "CWebStudio/CwebStudioMain.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    
    return cweb_send_text("Hello World", 200);
}

int main(){
    for(int i =5000; i< 6000;i++){
         cweb_run_server(i,main_sever,3,true);
    }

}