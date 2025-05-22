#include "CWebStudioOne.c"

CwebHttpResponse *main_sever(CwebHttpRequest *request){
    int one_mega_byte = 1048576;

    unsigned char *body = CwebHttpRequest_read_content(request, one_mega_byte);

    if(body){
        printf("body: %s",(char*)body);
        return cweb_send_text("Body Readed", 200);
    }
    return cweb_send_text("Body Not Readed", 200);
}

int main(int argc, char *argv[]){
    CwebServer server = newCwebSever(5000, main_sever);
    CwebServer_start(&server);
    return 0;
}