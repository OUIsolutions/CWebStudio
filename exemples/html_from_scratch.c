
#include "../CWebStudio_test.h"

 CwebHttpResponse *main_sever( CwebHttpRequest *request ){

    char *html = "<html><body><h1>Hello World</h1></body></html>";
    return cweb_send_var_html(html,200);
}

CWEB_START_MACRO(5000, main_sever)
