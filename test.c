

#define CWEB_DEBUG
#include "CWebStudio/CwebStudioMain.h"
int total_request = 0;

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    total_request++;
    if(total_request > 30){
        request->free(request);
        exit(0);
    }
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
                    CWEB_DEFAULT_TIMEOUT,
                    CWEB_DEFAULT_MAX_BODY,
                    CWEB_DANGEROUS_SINGLE_PROCESS
            );
    }


}