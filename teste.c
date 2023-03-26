#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "CWebStudio/dependencies/doTheWorld.c"

#define MAX_REQUEST_SIZE 15000
#define port 8080

void send_file_response(int socket_fd, unsigned char *file_content, int file_size) {
    char *response = (char *) malloc(MAX_REQUEST_SIZE * sizeof(char));
    memset(response, 0, MAX_REQUEST_SIZE);
    sprintf(response, 
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: image/png\r\n"
    "Content-Length: %d\r\n"
    "\r\n",
     file_size
     );

    send(socket_fd, response, strlen(response), 0);
    send(socket_fd, file_content, file_size, 0);
    free(response);
}

int main (){

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[MAX_REQUEST_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Faluire to create socket");
        exit(EXIT_FAILURE);
    }

    // Configurando a estrutura de endereço do servidor
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    // Vinculando o socket à porta especificada
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Faluire to bind socket");
        exit(EXIT_FAILURE);
    }

    // Waiting for connections
    if (listen(server_fd, 3) < 0) {
        perror("Faluire to listen connections");
        exit(EXIT_FAILURE);
    }

    // Main loop
    while(1) {
        // Accepting a new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("Faluire to accept connection");
            exit(EXIT_FAILURE);
        }

        // Lendo a solicitação HTTP do cliente
        valread = read(new_socket, buffer, MAX_REQUEST_SIZE);
        dtw_write_string_file_content("saida.txt", buffer);

        // Verificando se a solicitação HTTP é válida
        if (strstr(buffer, "HTTP/1.") == NULL) {
            fprintf(stderr, "Solicitation HTTP invalid\n");
            exit(EXIT_FAILURE);
        }
        
        // Abre a imagem "captura1.png" e envia como resposta HTTP
        int file_size = 0;
        unsigned char *file_content = dtw_load_binary_content("captura1.png", &file_size);
        send_file_response(new_socket, file_content, file_size);
        free(file_content);

        //Closing the connection with the client
        close(new_socket);
    }
    
}