#include "CWebStudio/CwebStudioMain.h"
CwebNamespace cweb;
#include <fcntl.h>
#include <stdio.h>

void escreva(const char *teste ){
    // Nome do arquivo onde você deseja adicionar \r
    const char *nome_arquivo = "teste.txt";

    // Abre o arquivo para gravação (ou cria se não existir)
    FILE *arquivo = fopen(nome_arquivo, "w");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
    }

    // Escreve uma linha com \r no arquivo
    fprintf(arquivo,teste);

    // Fecha o arquivo quando terminar de usá-lo
    fclose(arquivo);

}

int main(){
    escreva(
        "GET /sss HTTP/1.1 "
    
    );

    int fd = open("teste.txt", O_RDONLY);
   

    CwebHttpRequest *r = newCwebHttpRequest(fd);
    int result = CwebHttpRequest_parse_http_request(r);
    printf("%d\n",result);
    if(result ==0){
        CwebHttpRequest_represent(r);
    }
    CwebHttpRequest_free(r);

}