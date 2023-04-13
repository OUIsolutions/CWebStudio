#define CWEB_DEBUG
#include "CWebStudio.c"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    unsigned char *body = request->content;
    int size = request->content_length;

    //dtw_write_any_content("test.png", body, size);

    return cweb_send_file("test.png",CWEB_AUTO_SET_CONTENT, 200);

}

CWEB_START_MACRO(8081, main_sever);