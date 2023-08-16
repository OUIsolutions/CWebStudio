#include "../CWebStudio_test.h"

 CwebHttpResponse *main_sever( CwebHttpRequest *request ){
    int one_mega_byte = 1048576;
    request->read_content(request, one_mega_byte);
    unsigned char *body = request->content;
    int size = request->content_length;

    printf("body: %s",body);

    return cweb_send_text("Hello World", 200);
    
}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    struct CwebServer *sever = newCwebSever(5000, main_sever);
    cweb.server.start(sever);
    cweb.server.free(sever);
    return 0;
}