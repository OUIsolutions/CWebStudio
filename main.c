
#include "CWebStudio/CwebStudio.c"
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

int main(){

    struct CwebKeyVal *key_val = cweb_key_val_constructor("key3", "value3");
    key_val->represent(key_val);
    key_val->free(key_val);
}