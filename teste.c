
#include "CWebStudio/CwebStudioMain.c"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    sleep(10);
    char *tag = request->get_param(request,"tag");
    if(tag == NULL){
        return cweb_send_text("not passed tag",200);
    }

    char formated_text [100];
    sprintf(formated_text,"passed tag: %s",tag);
    return cweb_send_text(formated_text,200);


}

int main(int argc, char *argv[]){

    cweb_run_server(
        8080,
        main_sever,
        CWEB_DEFAULT_TIMEOUT,
        CWEB_DEFAULT_MAX_BODY,
        CWEB_SAFTY_MODE
    );
}