



void  private_cweb_generate_cors_response(struct CwebHttpResponse *response) {
#ifndef CWEB_USE_CORS
    return ;
#endif
    CwebHttpResponse_add_header(response,"Access-Control-Allow-Origin","*");
    CwebHttpResponse_add_header(response,"Access-Control-Allow-Method","*");

}