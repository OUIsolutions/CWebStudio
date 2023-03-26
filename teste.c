#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "doTheWorld.c"


#define PORT 8080
#define MAX_REQUEST_SIZE 1024

char *formate_resposta(){
        // Enviando uma resposta HTTP ao cliente
        const char *mensagem = dtw_load_string_file_content("saida.html");
        char *response = malloc(strlen(mensagem) + 70);
        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\n\r\n%s", strlen(mensagem), mensagem); // <-- correção aqui
        return response;
}


int main() {


    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[MAX_REQUEST_SIZE] = {0};

    // Criando o socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Falha ao criar o socket");
        exit(EXIT_FAILURE);
    }

    // Configurando a estrutura de endereço do servidor
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Vinculando o socket à porta especificada
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Falha ao vincular o socket");
        exit(EXIT_FAILURE);
    }

    // Esperando por conexões
    if (listen(server_fd, 3) < 0) {
        perror("Falha ao ouvir conexões");
        exit(EXIT_FAILURE);
    }

    // Loop principal
    while(1) {
        // Aceitando uma nova conexão
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("Falha ao aceitar conexão");
            exit(EXIT_FAILURE);
        }

        // Lendo a solicitação HTTP do cliente
        valread = read(new_socket, buffer, MAX_REQUEST_SIZE);
        dtw_write_string_file_content("saida.txt",buffer);

        // Verificando se a solicitação HTTP é válida
        if (strstr(buffer, "HTTP/1.") == NULL) {
            fprintf(stderr, "Solicitação HTTP inválida\n");
            exit(EXIT_FAILURE);
        }

        char *response = formate_resposta();
        send(new_socket, response, strlen(response), 0);
        free(response);
        // Fechando a conexão com o cliente
        close(new_socket);
    }
    

    return 0;
}
