
#include "../uniq.definitions_requirements.h"
int private_CWebServer_run_server_in_single_process(CwebServer *self) {

    if(Universal_start_all() != 0){
      fprintf(stderr, "Failed to initialize Winsock.\n");
      return 1;
    }
    Universal_socket_int port_socket;

    // Creating socket file descriptor
    if ((port_socket = Universal_socket(UNI_AF_INET, UNI_SOCK_STREAM, 0)) == 0){
        perror("Faluire to create socket");
        Universal_end();
        return 1;
    }

    Universal_sockaddr_in address;
    int addrlen = sizeof(address);

    // Configurando a estrutura de endereço do servidor
    address.sin_family = UNI_AF_INET;
    address.sin_addr.s_addr = UNI_INADDR_ANY;
    address.sin_port = htons(self->port);


    // Vinculando o socket à porta especificada
    if (Universal_bind(port_socket,&address, sizeof(address)) < 0)
    {
        printf("Faluire to bind socket to port %d\n", self->port);
        Universal_end();
        return 1;
    }

    // Waiting for connections
    if (Universal_listen(port_socket, self->max_queue) < 0)
    {
        perror("Faluire to listen connections");
        Universal_end();
        return 1;
    }

    // Main loop
    printf("Sever is running on port:%d\n", self->port);


    while (1)
    {

        if(private_cweb_end_server){
                    cweb_print("Break in request %lld\n", cweb_actual_request)
                    break;
        }

        cweb_actual_request++;

        //clear every trash

        // Accepting a new connection in every socket
        int client_socket = Universal_accept(
            port_socket,
            &address,
            (socklen_t *)&addrlen
        );

        char client_ip[INET_ADDRSTRLEN] ={0};
        Universal_inet_ntop(UNI_AF_INET, &(address.sin_addr), client_ip, INET_ADDRSTRLEN);



        cweb_print("----------------------------------------\n")
        cweb_print("Executing request:%lld\n", cweb_actual_request)
        cweb_print("Socket: %d\n", client_socket)


        if ( client_socket< 0){
            perror("Faluire to accept connection");
            exit(EXIT_FAILURE);
        }

        struct timeval timer1;
        timer1.tv_sec =  0;
        timer1.tv_usec =  0100000;
        Universal_setsockopt(client_socket, UNI_SOL_SOCKET, UNI_SO_RCVTIMEO, &timer1, sizeof(timer1));

        char buffer[1]= {0};
        ssize_t peek_result = Universal_recv(client_socket, buffer, 1, UNI_MSG_PEEK);

        if (peek_result <= 0) {
            cweb_print("peek: %li\n",peek_result)
            cweb_print("Conection closed By the  Client\n")
            close(client_socket);  // Fechar o socket do cliente
            continue;
        }


        struct timeval timer2;
        long seconds =  (long)self->client_timeout;
        timer2.tv_sec =  seconds ;  // tempo em segundos
        timer2.tv_usec =(long)((self->client_timeout - (double )seconds) * 1000000);
        Universal_setsockopt(client_socket, UNI_SOL_SOCKET, UNI_SO_RCVTIMEO, &timer2, sizeof(timer2));


        private_CWebServer_execute_request(self,client_socket, client_ip);


        Universal_close(client_socket);


        cweb_print("Closed Conection with socket %d\n", client_socket)


    }
    Universal_end();
    return 0;
}
