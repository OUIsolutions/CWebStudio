


void private_cweb_send_error_mensage( CwebHttpResponse *response, int socket);

bool private_cweb_verify_if_kill_server();

void cweb_kill_server();

void private_cweb_treat_response(bool use_static,int new_socket);


void private_cweb_handle_child_termination(int signal);