
#define CEW_MAX_REQUEST_SIZE 15000
#include "CWebStudio.c"


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
        // Enviando uma resposta HTTP ao cliente
        request->represent(request);
        dtw_write_string_file_content("saida.txt", request->raw_entrys);
        //dtw_write_string_file_content("saida.txt", raw_entrys);
        return cew_send_file("captura1.png", CWEB_AUTO_SET_CONTENT, CWEB_OK);
}

int main(){

    cweb_run_sever(8082, main_sever);
    return 0;
}