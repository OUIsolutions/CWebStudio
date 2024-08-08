
#include "../unique.definition_requirements.h"

void parse_code(CTextStack *final,const char *content){
    int content_size = strlen(content);
    for(int i = 0; i < content_size; i++){
        char buffer[10] = {0};
        sprintf(buffer,"\\x%x",content[i]);
        stack.format(final,"%s",buffer);
    }
}

void parse_bin(CTextStack *final,unsigned char *content,long size) {
    for(int i = 0; i < size; i++){
        char buffer[10] ={0};
        sprintf(buffer,"\\x%x",content[i]);
        stack.format(final,"%s",buffer);
    }
}
