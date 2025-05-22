#include "CWebStudioOne.c"

CwebHttpResponse *main_sever(CwebHttpRequest *request) {
    const char *html = "<html><body><h1>Hello World</h1></body></html>";
    return cweb_send_var_html(html, 200);
}

int main(int argc, char *argv[]) {
    CwebServer server = newCwebSever(5000, main_sever);
    CwebServer_start(&server);
    return 0;
}