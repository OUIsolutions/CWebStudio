#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    // Endereço e porta do servidor web
    char *server_ip = "localhost"; // Substitua pelo endereço IP ou nome de domínio do servidor
    int server_port = 5004; // Porta HTTP padrão

    // Construindo a solicitação HTTP GET
    char *request = "GET /sss53ssse \r\n"
                    "\r\n";

    // Criação do socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Erro ao criar o socket");
        exit(1);
    }

    // Configuração da estrutura de endereço do servidor
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port);

    // Resolução do nome de domínio para endereço IP
    
    


    // Conexão ao servidor web
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Erro ao conectar-se ao servidor");
        close(client_socket);
        exit(1);
    }

    // Envio da solicitação HTTP
    if (send(client_socket, request, strlen(request), 0) == -1) {
        perror("Erro ao enviar a solicitação");
        close(client_socket);
        exit(1);
    }

    // Recebimento e impressão da resposta do servidor
    char buffer[MAX_BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(client_socket, buffer,1, MSG_WAITALL)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    // Fechamento do socket e encerramento do programa
    close(client_socket);
    return 0;
}