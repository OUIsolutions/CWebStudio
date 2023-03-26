
#include "CWebStudio/CwebStudio.c"
/*
char *main_sever(char *raw_entrys){
        // Enviando uma resposta HTTP ao cliente
        dtw_write_string_file_content("saida.txt", raw_entrys);
        int size = 0;
        unsigned char *imagem = dtw_load_binary_content(
            "captura1.png",
            &size
        );
        printf("size: %d\n", size);
        char *response = create_response(
            200,
            "image/png",
            size,
            imagem
        );
        printf("response: %s\n", response);
        return response;
}
*/
int main(){
    struct CwebHttpResponse *response = create_http_response();
    response->set_content(response, "Hello World", 11);
    response->add_header(response, "Content-Type", "text/plain");
    response->add_header(response, "Content-Length", "11");
    response->free(response);
}