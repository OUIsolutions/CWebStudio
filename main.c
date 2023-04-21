#include "CWebStudio/CwebStudioMain.c"


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    
    
    request->represent(request);
    return cweb_send_text("Hello World", 200);
    
}

int main(){

    struct CwebHttpRequest *request = cweb_request_constructor();
    request->set_url(request,"/teste  ?a=30&b=c");
    request->represent(request);
}