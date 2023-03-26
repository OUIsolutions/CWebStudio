
#include "CWebStudio/CwebStudio.c"
char *main_sever(char *raw_entrys){
        // Enviando uma resposta HTTP ao cliente
        dtw_write_string_file_content("saida.txt", raw_entrys);
        return send_text(200, "Hello World");
}

int main(){


    cweb_run_sever(8082, main_sever);
}