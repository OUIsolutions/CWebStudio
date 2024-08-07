


#define CWEB_DANGEROUS_SINGLE_PROCESS true
#define CWEB_NO_STATIC false;




CwebServer newCwebSever(int port , CwebHttpResponse *(*request_handler)(CwebHttpRequest *request));

int CwebServer_start(CwebServer *self);


int private_CWebServer_run_server_in_single_process(CwebServer *self);

int private_CWebServer_run_server_in_multiprocess(CwebServer *self);


void private_CWebServer_execute_request(
        CwebServer *self,
        int socket,
        const char *client_ip
);




void private_cweb_execute_request_in_safty_mode(CwebServer  *self,int new_socket, const char *client_ip);











