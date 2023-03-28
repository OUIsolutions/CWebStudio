
#define CEW_MAX_REQUEST_SIZE 15000
#include "CWebStudio/CwebStudioMain.c"



struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
        // Enviando uma resposta HTTP ao cliente
        //dtw_write_string_file_content("saida.txt", raw_entrys);


        request->represent(request);
        dtw_write_any_content("saida.png", request->content, request->content_length);
        //char teste[5];
        //memcpy(teste, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
        return cweb_send_file("captura1.png", CWEB_AUTO_SET_CONTENT, 200);

}

int main(){

    /*
    char *content = dtw_load_string_file_content("saida.txt");
    struct CwebHttpRequest *request = private_cwe_create_http_request(content);
    request->represent(request);
    request->free(request);
    free(content);
    */

    cweb_run_sever(8081, main_sever, 10);
    return 0;
}