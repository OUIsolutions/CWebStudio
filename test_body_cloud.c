#define CWEB_DEBUG
#include "CWebStudio.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    return cweb_send_text("Hello World", 200);
}

CWEB_START_MACRO(5002, main_sever);