

#define CWEB_DEBUG


#include "CWebStudio/CwebStudioMain.c"

#include <iostream>
#include <string>

using namespace std;




struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    unsigned char *body = request->content;
    int size = request->content_length;
    
         cout << "size: " << size << endl;
    const char  *element_c = request->params->get_value(request->params,"name");
    if(element_c == nullptr){
        return cweb_send_text("name not found",200);
    }
    std::string element = element_c;
    std::string rota = request->route;
    
    if(rota == "/get"){
       return cweb_send_file(element.c_str(),CWEB_AUTO_SET_CONTENT,200);
    }
    
    if(rota == "/set"){
            
            dtw_write_any_content(element.c_str(), body, size);
            return cweb_send_text("uploaded",200);
    }

    else{
        return cweb_send_text("rota invalda",200);
    }
    
    
}

int main(){
    cweb_run_server(
        8080,
        main_sever,
        100,
        7860480,
     
        CWEB_DANGEROUS_SINGLE_PROCESS
    );
    return 0;
}

