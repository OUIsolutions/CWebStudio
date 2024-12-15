#include "src/one.c"
CwebNamespace cweb;

CwebHttpResponse *main_sever( CwebHttpRequest *request ){

    unsigned char*testage = (unsigned char *)cweb.request.get_header(request,"Custom-Header");
    printf("%s\n",testage);

    unsigned char real[] = "ÂÒ i ÔÕÃÁ í %$ ";
    printf("testage size: %ld\n",strlen(testage));
    printf("real size: %ld\n",sizeof(real)/sizeof(char));
    printf("real:    ");

    for(int i = 0; i < strlen(real);i++){
        printf("%c  %d|",real[i],real[i]);
    }
    printf("\n");
    printf("testage: ");

    for(int i = 0; i < strlen(testage);i++){
        printf("%c  %d|",testage[i],testage[i]);
    }
    printf("\n");

    return cweb.response.send_text("Headers Iterated", 200);
}


int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    CwebServer server = newCwebSever(5001, main_sever);
    server.single_process= true;
    cweb.server.start(&server);
    return 0;
}
