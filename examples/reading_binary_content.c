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
    request->read_content(request, two_mega_bytes);
    unsigned char *body = request->content;
    char *name = request->get_param(request, "name");
    int size = request->content_length;

    write_binary_file(name, body, size);

    return cweb_send_text("File Written", 200);
    
}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    struct CwebServer *sever = newCwebSever(5000, main_sever);
    cweb.server.start(sever);
    cweb.server.free(sever);
    return 0;
}