#include "CWebStudio.h"
void write_binary_file(char *path, unsigned char *content, int size)
{
    FILE *file = fopen(path, "wb");
    fwrite(content, sizeof(unsigned char), size, file);
    fclose(file);
}


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
   return cweb_send_text("Hello World",200);
    
}

CWEB_START_MACRO(5001, main_sever);