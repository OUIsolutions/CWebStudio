
#define CEW_MAX_REQUEST_SIZE 15000
#define CWEB_DEBUG
#include "CWebStudio/CwebStudioMain.c"



struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
        // Enviando uma resposta HTTP ao cliente
        //dtw_write_string_file_content("saida.txt", raw_entrys);


        if(strcmp(request->route, "/teste") == 0){
            char teste[5];
            memcpy(teste, "aaaaaaaaaaaaaaaaaaaaaaaa",200);
            return cweb_send_text("Hello World", 200);
        }

        if(strcmp(request->route, "/teste2") == 0){
            sleep(15);
            return cweb_send_text("ffff", 200);
        }
        
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