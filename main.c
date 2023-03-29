
#include "CWebStudio.c"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    int out_size;
    unsigned char *content = dtw_load_binary_content("my_image.png", &out_size);
    struct CwebHttpResponse *response = create_http_response();
    response->add_header(response, "Content-Type", "image/png");
    response->set_content(response, content, out_size);
    return response;

}  

int main(){

   cweb_run_server(5000, main_sever); 

   return 0;
}