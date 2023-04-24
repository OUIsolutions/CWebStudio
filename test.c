#define CWEB_ONCE
#define OUI_DEBUG
#define CWEB_DEBUG
#include "CWebStudio/CwebStudioMain.c"




struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    
    
    char *test = (char*)malloc(100);
    strcpy(test,"Hello World!");
    
    return cweb_send_text_cleaning_memory("aaaaa",CWEB_OK);
    
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