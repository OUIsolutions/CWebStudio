#include "CWebStudioOne.c"

CwebNamespace cweb;

CwebHttpResponse *main_sever( CwebHttpRequest *request ){
    int one_mega_byte = 1048576;

    unsigned char *body =  cweb.request.read_content(request, one_mega_byte);

    if(body){
        printf("body: %s",(char*)body);
         return cweb_send_text("Body Readed", 200);

    }
    return cweb_send_text("Body Not Readed", 200);


}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    CwebServer server = newCwebSever(5000, main_sever);
    cweb.server.start(&server);
    return 0;
}