

#include "CWebStudio/CwebStudioMain.h"

int executions = 0;

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    char *content = request->content;
    int content_size = request->content_length;

   
    return cweb_send_text("aaa",200);
}

int main(){
    
    /*
      cweb_run_server(
        8080,
        main_sever,
        CWEB_DEFAULT_TIMEOUT,
        CWEB_DEFAULT_MAX_BODY,
        CWEB_DANGEROUS_SINGLE_PROCESS
    );
    */

    char *decoded = private_cweb_convert_url_encoded_text("ddd=abcd%25%24%23ssss");
    printf("%s\n",decoded);   
    

    

}