
#include "CWebStudio/CwebStudio.c"
char *main_sever(char *raw_entrys){
        // Enviando uma resposta HTTP ao cliente
        dtw_write_string_file_content("saida.txt", raw_entrys);
        int size = 0;
        unsigned char *imagem = dtw_load_binary_content(
            "captura1.png",
            &size
        );
        printf("Tamanho: %d\n", size);

        char *response = create_response(
            200,
            "image/png",
            size,
            (char*)imagem
        );
        return response;
}

int main(){


    cweb_run_sever(8084, main_sever);
}