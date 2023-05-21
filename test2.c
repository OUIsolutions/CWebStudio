// Server side C program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 5001
int main(int argc, char const *argv[])
{
    int server_fd, new_socket; long valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char *mensagem = "<html>hello, world</html>";
    int tamanho = strlen(mensagem);
    char hello[3000] =  "HTTP/1.0 200 OK\r\n"
                        "Server: webserver-c\r\n"
                        "Content-type: text/html\r\n";

    char content_length[100];

    sprintf(content_length,"Content-Length: %i\r\n\r\n",tamanho);
    strcat(hello,content_length);


    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("In socket");
        exit(EXIT_FAILURE);
    }


    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    memset(address.sin_zero, '\0', sizeof address.sin_zero);


    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("In bind");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 1) < 0)
    {
        perror("In listen");
        exit(EXIT_FAILURE);
    }
    int total = 0;
    while(1)
    {
        total++;
        printf("\n+++++++ Conection %i ++++++++\n\n",total);

        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
        {
            perror("In accept");
            exit(EXIT_FAILURE);
        }

        char  *buffer  = malloc(30000);
        printf("starting the loop read\n");
        for(int x =0;x < 30000;x++){

            valread = recv( new_socket , &buffer[x], 1,0);
  
            if (valread < 0) {
                printf("leu até o %i\n",x);
                ///perror("webserver (read)");
                break;
            }

            if(x > 3){
                char *aux = &buffer[x-3];
                buffer[x+1] = '\0';
                if(strcmp(aux,"\r\n\r\n") == 0){
                    printf("terminou em %i\n",x);
                    break;
                }
            }

        }

        printf("pegou aqui\n");



        send(new_socket , hello , strlen(hello) , MSG_NOSIGNAL );
        send(new_socket , mensagem , strlen(mensagem) , MSG_NOSIGNAL );

   
        close(new_socket);
        free(buffer);
        printf("Fechou a conexão\n");

    }
    return 0;
}