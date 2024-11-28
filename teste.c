
#include "src/one.c"
CwebNamespace cweb;

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    if(strcmp(request->route, "/termina") == 0){
        private_cweb_end_server = true;
        return cweb.response.send_text(" finalizada", 200);
    }

    return cweb.response.send_file("imagem.png",CWEB_AUTO_SET_CONTENT,200);
}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    struct CwebServer server = newCwebSever(5003, main_sever);
    //server.single_process = true;
    cweb.server.start(&server);
    return 0;
}
