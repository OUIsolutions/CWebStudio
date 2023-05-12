

#define CWEB_DEBUG
#include "CWebStudio/CwebStudioMain.h"


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    if(strcmp(request->route,"/a") ==0){
        return cweb_send_text("aaa",200);
    }
    return NULL;
}

int main(){
    for(int i =5000; i < 6000; i++){
            cweb_run_server(
                    i,
                    main_sever,
                    30,
                    CWEB_DEFAULT_MAX_BODY,
                    CWEB_DANGEROUS_SINGLE_PROCESS
            );
    }


}