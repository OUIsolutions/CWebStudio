
#define OUI_DEBUG

#include "CWebStudio/CwebStudioMain.c"


int executions = 0;

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    
    if(executions ==3){
        request->free(request);
       exit(0);
    }
    char *test = (char*)malloc(100);
    sprintf(test, "Hello world");
    executions++;

    request->represent(request);
    
    return cweb_send_var_html_cleaning_memory(test, CWEB_OK);
    
}

int main(){
    
    
      cweb_run_server(
        8080,
        main_sever,
        CWEB_DEFAULT_TIMEOUT,
        CWEB_DEFAULT_MAX_BODY,
        CWEB_DANGEROUS_SINGLE_PROCESS
    );
    

}