//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.dep_define.h"
//silver_chain_scope_end



void private_CWebServer_execute_request(CwebServer *self,int socket,const char *client_ip){

    cweb_print("Parsing Request\n");
    CwebHttpRequest *request = newCwebHttpRequest(socket);
    request->client_ip = strdup(client_ip);


    int result = CwebHttpRequest_parse_http_request(request);

    if(result == INVALID_HTTP){
        cweb_print("Invalid HTTP Request\n");
        CwebHttpRequest_free(request);
        return;
    }

    if(result == READ_ERROR){
        cweb_print("Read Error \n");
        CwebHttpRequest_free(request);
        return;
    }
    if(result == MAX_HEADER_SIZE_CODE){
        cweb_print("Max Header Size\n");
        CwebHttpRequest_free(request);
        return;
    }

    cweb_print("created request\n");
    cweb_print("Request method: %s\n", request->method);
    cweb_print("Request url: %s\n", request->url);



    CwebHttpResponse *response = NULL;

    if(self->use_static){
        response = private_cweb_generate_static_response(request,self->use_cache);
    }


    if(!response){
        //lambda que o usuario passa
        response = self->request_handler(request);
    }

    if(response && self->allow_cors){
        private_cweb_generate_cors_response(response);
    }
    cweb_print("executed client lambda\n");


    //means that the main function respond nothing
    if (response == NULL){

        if(self->use_static){
            char formated_404_path[1000]={0};
            sprintf(formated_404_path,"%s/404.html", cweb_static_folder);
            char *formated_html = cweb_load_string_file_content(formated_404_path);

            if(formated_html != NULL){
                response = cweb_send_var_html_cleaning_memory(
                        formated_html,
                        404);
            }

            else{
                response = cweb_send_var_html((const char*)private_cweb_404, 404);
            }
        }
        else{
            response = cweb_send_var_html((const char*)private_cweb_404, 404);

        }


    }

    char *response_str = CwebHttpResponse_generate_response(response);
    cweb_print("Response created\n");

    int flag = 0;
    #if defined(__linux__)
        flag = MSG_NOSIGNAL;
    #endif



    Universal_send(socket, response_str, strlen(response_str), flag);

    // Enviando conteúdo byte a byte
    if (response->exist_content)
    {
        size_t sent = 0;
        while (sent < response->content_length)
        {
            size_t chunk_size = response->content_length - sent;

            ssize_t res = Universal_send(socket, response->content + sent, chunk_size, flag);
            if (res < 0)
            {
                break;
            }
            sent += res;
        }
    }


    free(response_str);
    CwebHttpResponse_free(response);
    CwebHttpRequest_free(request);
    cweb_print("Cleared memory\n");
}