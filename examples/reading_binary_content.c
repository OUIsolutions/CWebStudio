#include "../CWebStudio_test.h"
CwebNamespace cweb;


void write_binary_file(char *path, unsigned char *content, int size)
{
    FILE *file = fopen(path, "wb");
    fwrite(content, sizeof(unsigned char), size, file);
    fclose(file);
}


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    int two_mega_bytes = 2097152;
    cweb.request.read_content(request, two_mega_bytes);
    char *name = cweb.request.get_param(request, "name");
    if(!name){
        return cweb.response.send_text("name not provided\n",404);
    }
    int size = request->content_length;

    write_binary_file(name, request->content, size);

    return cweb_send_text("File Written", 200);

}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    struct CwebServer *sever = newCwebSever(5000, main_sever);
    cweb.server.start(sever);
    cweb.server.free(sever);
    return 0;
}