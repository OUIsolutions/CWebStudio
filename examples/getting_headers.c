#include "CWebStudioOne.c"

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    char *name = CwebHttpRequest_get_header(request,"name");
    if(name){
        printf("%s\n",name);
    }
    else{
        printf("name not provided\n");
    }
    return cweb_send_text("Hello World", 200);

}

int main(int argc, char *argv[]){
    struct CwebServer server = newCwebSever(5000, main_sever);
    CwebServer_start(&server);
    return 0;
}