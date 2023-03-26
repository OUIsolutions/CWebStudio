
#include "CWebStudio/CwebStudio.c"

struct CwebHttpResponse *main_sever(char *raw_entrys){
        // Enviando uma resposta HTTP ao cliente
        dtw_write_string_file_content("saida.txt", raw_entrys);
        struct CwebHttpResponse *response = create_http_response();

        int size = 0;
        char *content = dtw_load_binary_content("captura1.png", &size);
        response->set_content(response, content, size);
        response->add_header(response, "Content-Type", "image/png");

        return response;
}

int main(){
    

    cweb_run_sever(8084, main_sever);
    return 0;
}