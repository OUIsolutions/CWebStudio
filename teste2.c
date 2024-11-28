#include <winsock2.h>
#include <stdio.h>

//#pragma comment(lib, "ws2_32.lib") // Linka a biblioteca Winsock

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    int addrLen, recvLen;
    char buffer[BUFFER_SIZE];

    // Inicializa o Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("Erro ao inicializar Winsock: %d\n", WSAGetLastError());
        return 1;
    }

    // Cria o socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Erro ao criar socket: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    // Configura o endereço do servidor
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY; // Aceita conexões de qualquer IP
    serverAddr.sin_port = htons(PORT);       // Porta

    // Associa o socket à porta especificada
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        printf("Erro no bind: %d\n", WSAGetLastError());
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Configura o socket para ouvir conexões
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        printf("Erro no listen: %d\n", WSAGetLastError());
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    printf("Servidor iniciado e aguardando conexões na porta %d...\n", PORT);

    addrLen = sizeof(clientAddr);
    while (1) {
        // Aceita uma conexão de um cliente
        clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &addrLen);
        if (clientSocket == INVALID_SOCKET) {
            printf("Erro no accept: %d\n", WSAGetLastError());
            continue;
        }

        printf("Conexão aceita de %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));

        // Recebe dados do cliente
        recvLen = recv(clientSocket, buffer, BUFFER_SIZE - 1, 0);
        if (recvLen > 0) {
            buffer[recvLen] = '\0'; // Adiciona um terminador de string
            printf("Mensagem recebida: %s\n", buffer);

            // Envia uma resposta ao cliente
            send(clientSocket, "Mensagem recebida!\n", 19, 0);
        } else if (recvLen == 0) {
            printf("Conexão encerrada pelo cliente.\n");
        } else {
            printf("Erro no recv: %d\n", WSAGetLastError());
        }

        // Fecha o socket do cliente
        closesocket(clientSocket);
    }

    // Fecha o socket do servidor
    closesocket(serverSocket);

    // Finaliza o Winsock
    WSACleanup();

    return 0;
}
