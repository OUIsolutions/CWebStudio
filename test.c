
#include "CWebStudio.h"

 CwebHttpResponse *main_sever( CwebHttpRequest *request ){

    return cweb_send_text("Hello World", 200);
}

int main(int argc, char *argv[]){

   
     struct CwebSever *sever = newCwebSever(5000, main_sever);
     sever->start(sever);
     sever->free(sever);
}