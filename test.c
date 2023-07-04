
#include "CWebStudio/CwebStudioMain.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    char *r = request->get_header(request,"a");
    printf("valor de a = %s\n",r);

    return cweb_send_text("Hello World", 200);
}

int main(int argc, char *argv[]){

   
     struct CwebSever *sever = newCwebSever(5002, main_sever);
     sever->single_process = CWEB_DANGEROUS_SINGLE_PROCESS;
     sever->start(sever);
     sever->free(sever);
}