#include "../CWebStudio_test.h"

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    char *teste = malloc(100);
    strcpy(teste, "Hello World");
    return cweb_send_text_cleaning_memory(teste,200);
}

CWEB_START_MACRO(5000, main_sever)