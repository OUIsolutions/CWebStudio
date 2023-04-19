
#include "CWebStudio.c"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    printf("-------------------\n");
    printf("size:%d\n",request->content_length);
    request->represent(request);
    
    char *tag = request->get_header(request,"tag");
    if(tag == NULL){
        return cweb_send_text("not passed tag",200);
    }

    if(strcmp(tag,"teste") == 0){
        return cweb_send_text("tag ok",200);
    }
    
    return cweb_send_text("tag not ok",200);
}

int main(int argc, char *argv[]){

    cweb_run_server(
        8080,
        main_sever,
        2,
        CWEB_DEFAULT_MAX_BODY,
        CWEB_SAFTY_MODE
    );
}