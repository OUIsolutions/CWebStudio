
#include "CWebStudio/CwebStudio.c"

struct CwebHttpResponse *main_sever(char *raw_entrys){
        // Enviando uma resposta HTTP ao cliente
        dtw_write_string_file_content("saida.txt", raw_entrys);
        struct CwebHttpResponse *response = create_http_response();
        response->set_string_content(response, "Hello World", 11);
        response->add_header(response, "Content-Type", "text/html");

        return response;
}

int main(){
    cweb_run_sever(8080, main_sever);
    return 0;
}