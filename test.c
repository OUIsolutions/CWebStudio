
#include "CWebStudio.h"

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    
    return cweb_send_text("Hello World", 200);

}

CWEB_START_MACRO(5001, main_sever);