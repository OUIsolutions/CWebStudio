
#include "CWebStudioOne.c"
CwebNamespace cweb;
CwebHttpResponse *main_sever( CwebHttpRequest *request ){

    const char *html = "<html><body><h1>Hello World</h1></body></html>";
    return cweb.response.send_var_html(html,200);
}


int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    CwebServer server = newCwebSever(5000, main_sever);
    cweb.server.start(&server);
    return 0;
}