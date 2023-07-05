#define CWEB_ONCE
#include "../CWebStudio_test.h"


CwebHttpResponse *main_sever(CwebHttpRequest *request ){
    
    return cweb_send_text("Hello World", 200);
    
}

int main(){
    struct CwebSever *sever = newCwebSever(3001, main_sever);
    sever->single_process = CWEB_DANGEROUS_SINGLE_PROCESS;
    sever->start(sever);
    sever->free(sever);
    return 0;
}