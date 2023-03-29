


#include "CWebStudio.c"


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    struct CwebDict *headers = request->headers;
    for(int i = 0; i < headers->size; i++){
        struct CwebKeyVal *key_val = headers->keys_vals[i];
        char *key = key_val->key;
        char *value = key_val->value;
        printf("%s : %s\n", key, value);
    }
    return cweb_send_text("Hello World", 200);
    
}

int main(){

   cweb_run_server(5000, main_sever); 

   return 0;
}