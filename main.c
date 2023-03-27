
#define CEW_MAX_REQUEST_SIZE 15000
#include "CWebStudio/CwebStudioMain.c"


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
        // Enviando uma resposta HTTP ao cliente
        //dtw_write_string_file_content("saida.txt", raw_entrys);
        //char teste[5];
        //memcpy(teste, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",10);
        return NULL;

}

int main(){

    /*
    char *content = dtw_load_string_file_content("saida.txt");
    struct CwebHttpRequest *request = private_cwe_create_http_request(content);
    request->represent(request);
    request->free(request);
    free(content);
    */

    cweb_run_sever(8080, main_sever);
    return 0;
}