#include "CWebStudio/CwebStudioMain.h"
CwebNamespace cweb;
#include <fcntl.h>


int main(){
    int fd = open("teste.txt", O_RDONLY);
    printf("%d\n",fd);
    CwebHttpRequest *r = newCwebHttpRequest(fd);
    int result = CwebHttpRequest_parse_http_request(r);
    printf("%d\n",result);
    if(result ==0){
        CwebHttpRequest_represent(r);
    }

}