#include "release/CWebStudioOne.c"

CwebHttpResponse *main_server(CwebHttpRequest *request) {
    return cweb_send_text("Hello World", 200);
}

int main(int argc, char *argv[]) {
    CwebServer server = newCwebSever(3000, main_server);
    CwebServer_start(&server);
    return 0;
}