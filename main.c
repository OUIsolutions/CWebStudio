
#include "CWebStudio/CwebStudio.c"
char *main_sever(char *entrys){
        // Enviando uma resposta HTTP ao cliente
        const char *mensagem = dtw_load_string_file_content("saida.html");
        char *response = malloc(strlen(mensagem) + 70);
        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\n\r\n%s", strlen(mensagem), mensagem); // <-- correção aqui
        return response;
}

int main(){
    cweb_run_sever(8082, main_sever);
}