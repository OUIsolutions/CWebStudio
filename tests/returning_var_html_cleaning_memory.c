#include "../CWebStudio.h"
CwebNamespace cweb;

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    char *html = malloc(1000);
    strcat(html, "<html><body><h1>Hello World</h1></body></html>");
    return cweb.response.send_var_html_cleaning_memory(html,200);
}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    CwebServer server = newCwebSever(5000, main_sever);
    cweb.server.start(&server);
    return 0;
}