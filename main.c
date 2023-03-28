
#define CEW_MAX_REQUEST_SIZE 15000
static int actual_request = 0;

#include "CWebStudio/CwebStudioMain.c"



struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
        // Enviando uma resposta HTTP ao cliente
        //dtw_write_string_file_content("saida.txt", raw_entrys);
        actual_request+=1;
        char atual[50] = {0};   
        sprintf(atual, "solicitacao/%d.txt", actual_request);
        dtw_write_string_file_content(atual, request->raw_entrys);
        if(strcmp(request->route, "/teste") == 0){
            char teste[5];
            memcpy(teste, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",100);
            return cweb_send_text("Hello World", 200);
        }
        if(strcmp(request->route, "/teste2") == 0){
            return cweb_send_text("ffff", 200);
        }
        //char teste[5];
        //memcpy(teste, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
        return cweb_send_file("saida.html", CWEB_AUTO_SET_CONTENT, 200);

}

int main(){

    /*
    char *content = dtw_load_string_file_content("saida.txt");
    struct CwebHttpRequest *request = private_cwe_create_http_request(content);
    request->represent(request);
    request->free(request);
    free(content);
    */


    cweb_run_sever(8083, main_sever);
    return 0;
}