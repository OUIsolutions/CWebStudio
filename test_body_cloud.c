#define CWEB_DEBUG
#include "CWebStudio/CwebStudioMain.h"
#include "doTheWorld.h"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    char *route = request->route;
    char *name = request->get_param(request, "name");

    if(name == NULL){
        return cweb_send_text("name is required",400);
    }

    if(strcmp(route, "/get") == 0){

        return cweb_send_file(name,CWEB_AUTO_SET_CONTENT,200);
    }

    else if(strcmp(route, "/set") == 0){
        int error = request->read_content(request,10000000);
        if(error != 0){
            return cweb_send_text("error reading content",400);
        }
        dtw_write_any_content(name,request->content,request->content_length);
        return cweb_send_text("uploaded",200);
    }
    
    else{
        return cweb_send_text("not route passed",404);
    }

}

int main(int argc, char *argv[]){

    cweb_run_server(
        5000,
        main_sever,
        CWEB_DEFAULT_TIMEOUT,
        CWEB_DANGEROUS_SINGLE_PROCESS
    );
    
}