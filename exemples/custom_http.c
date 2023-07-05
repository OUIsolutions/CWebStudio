#include "../CWebStudio_test.h"

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    int out_size;
    unsigned char *content = dtw_load_binary_content("my_image.png", &out_size);
    CwebHttpResponse *response = create_http_response();
    response->add_header(response, "Content-Type", "image/png");
    response->set_content(response, content, out_size);
    return response;
    


}  

CWEB_START_MACRO(5001, main_sever);
