#define CWEB_DEBUG
#include "CWebStudio/CwebStudioMain.h"
#include "trash/doTheWorld.h"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    return cweb_send_text("Hello World", 200);
}

int main(int argc, char *argv[]){
    

    struct CwebSever *sever = newCwebSever(5000, main_sever);
    sever->single_process = CWEB_DANGEROUS_SINGLE_PROCESS;
    sever->max_cache_age = CWEB_ONE_YEAR;
    sever->start(sever);
    sever->free(sever);

}