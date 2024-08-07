#include "../uniq.definitions_requirements.h"

void private_cweb_treat_response(bool use_static,int new_socket){
    cweb_print("New request %lld\n", cweb_actual_request)
    cweb_print("Waiting for child process\n")

    int status = 0;
    while (wait(&status) > 0);

    if (WIFEXITED(status)){
        cweb_print("Sucess\n")
        return;
    }


    pid_t pid_error = fork();
    if (pid_error == 0){
        cweb_print("Sending error mensage\n");
        alarm(2);
        bool send_text_menssage = true;

        if(use_static){

            char possible_500_html_path[1000] = {0};
            sprintf(possible_500_html_path,"%s/500.html",cweb_static_folder);
            FILE *possible_500_html = fopen(possible_500_html_path,"r");
            if(possible_500_html){

                fclose(possible_500_html);
                CwebHttpResponse  *response = cweb_send_file(possible_500_html_path,CWEB_AUTO_SET_CONTENT,500);
                private_cweb_send_error_mensage(response,new_socket);
                send_text_menssage = false;
            }

        }

        if(send_text_menssage){
            CwebHttpResponse  *response = cweb_send_text("Internal Sever Error",500);
            private_cweb_send_error_mensage(response,new_socket);
        }

        alarm(0);
        exit(0);
    }

    else if (pid_error < 0){
        perror("Faluire to create a new process");
        exit(EXIT_FAILURE);
    }
    else{
        int status2 = 0;
        /// Wait for the child process to finish
        while (wait(&status2) > 0);
        if (WIFEXITED(status2)){
            cweb_print("Mensage sent\n")
        }

        else{
            cweb_print("Error sending mensage\n")
        }
    }
}


void private_cweb_handle_child_termination(int signal) {
    pid_t terminated_child;
    int status;
    while ((terminated_child = waitpid(-1, &status, WNOHANG)) > 0) {
        cweb_total_requests--;
    }
}

void private_cweb_send_error_mensage( CwebHttpResponse *response, int socket){

    char *response_str = CwebHttpResponse_generate_response(response);
    send(socket, response_str, strlen(response_str), 0);
    send(socket, response->content, response->content_length, 0);
    free(response_str);
    CwebHttpResponse_free(response);

}
void cweb_kill_single_process_server( ){
    private_cweb_end_server = true;
}

void cweb_set_static_folder(const char *folder){
    cweb_static_folder = folder;
}
const char * cweb_get_static_folder(){
    return cweb_static_folder;
}

long cweb_get_total_requests(){
    return cweb_total_requests;
}
