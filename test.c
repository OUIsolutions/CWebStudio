#define CWEB_ONCE
#define OUI_DEBUG

#include "CWebStudio/CwebStudioMain.c"




struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    char *test = (char*)malloc(100);
    sprintf(test, "Hello world");
    
    request->represent(request);
    
    return cweb_send_var_html_cleaning_memory(test, CWEB_OK);
    
}

int main(){
    
    
      cweb_run_server(
        8081,
        main_sever,
        CWEB_DEFAULT_TIMEOUT,
        CWEB_DEFAULT_MAX_BODY,
        CWEB_DANGEROUS_SINGLE_PROCESS
    );
    

}