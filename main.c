#include "CWebStudio/CwebStudioMain.c"


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    struct CwebDict *query_paramns = request->params;
    for(int i = 0; i < query_paramns->size; i++){
        struct CwebKeyVal *key_val = query_paramns->keys_vals[i];
        char *key = key_val->key;
        char *value = key_val->value;
        printf("%s : %s\n", key, value);
    }
    return cweb_send_text("Hello World", 200);
    
}

int main(){

    struct CwebHttpRequest *request = cweb_request_constructor();
    request->interpret_first_line(request,"GET    /teste  ");

    return 0;
}