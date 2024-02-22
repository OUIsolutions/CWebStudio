


void private_cweb_send_error_mensage( CwebHttpResponse *response, int socket);

void cweb_kill_single_process_server( );

void cweb_set_static_folder(const char *folder);

const char * cweb_get_static_folder();

long cweb_get_total_requests();
void private_cweb_treat_response(bool use_static,int new_socket);


void private_cweb_handle_child_termination(int signal);