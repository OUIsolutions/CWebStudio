#define CWEB_DEBUG
#include "CWebStudio/CwebStudioMain.h"
#include "trash/doTheWorld.h"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    return cweb_send_text("Hello World", 200);
}

int main(int argc, char *argv[]){

    for(int x = 3000;x < 40000;x++){
        struct CwebSever *sever = newCwebSever(x, main_sever);
        sever->single_process = CWEB_DANGEROUS_SINGLE_PROCESS;
        sever->max_cache_age = CWEB_ONE_YEAR;
        sever->start(sever);
        sever->free(sever);
    }


}