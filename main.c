
#include "CWebStudio/CwebStudio.c"

struct CwebHttpResponse *main_sever(char *raw_entrys){
        // Enviando uma resposta HTTP ao cliente

        return cew_send_file("saida.html",CWEB_AUTO_SET_CONTENT,CWEB_OK);
}

int main(){
    

    cweb_run_sever(8084, main_sever);
    return 0;
}