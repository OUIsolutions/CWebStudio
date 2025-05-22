#include "CWebStudioOne.c"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    char *html = (char*)malloc(1000);
    strcat(html, "<html><body><h1>Hello World</h1></body></html>");
    return cweb_send_var_html_cleaning_memory(html,200);
}

int main(int argc, char *argv[]){
    CwebServer server = newCwebSever(5000, main_sever);
    CwebServer_start(&server);
    return 0;
}