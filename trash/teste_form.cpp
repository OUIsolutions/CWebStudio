

#include "CWebStudio/CwebStudioMain.c"

#include <iostream>
#include <string>

using namespace std;




struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    unsigned char *body = request->content;
    int size = request->content_length;

    std::string rota = request->route;
    
    if(rota == "/get"){
       return cweb_send_file("teste.html",CWEB_AUTO_SET_CONTENT,200);
    }
    
    if(rota == "/set"){
       request->represent(request);
       dtw_write_any_content("teste.txt", body, size);
       return cweb_send_text("uploaded",200);
    }
    

    else{
        return cweb_send_text("rota invalda",200);
    }
    
    
}

int main(){
    cweb_run_server(
        8081,
        main_sever,
        100,
        7860480,
        CWEB_DANGEROUS_SINGLE_PROCESS
    );
    return 0;
}

