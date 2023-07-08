#include "../CWebStudio_test.h"

CwebHttpResponse *main_sever(CwebHttpRequest *request ){


    return cweb_send_text("Exemple of Return", 200);
    
}

CWEB_START_MACRO(5001, main_sever);