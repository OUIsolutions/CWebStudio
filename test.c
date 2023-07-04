#include "CWebStudio.h"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    return cweb_send_file(
        "2.png",
        CWEB_AUTO_SET_CONTENT,
        200
    );
    
}

CWEB_START_MACRO(5004, main_sever);