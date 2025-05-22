#include "CWebStudioOne.c"

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    CwebDict *query_paramns = request->params;
    for(int i = 0; i < query_paramns->size; i++){
        CwebKeyVal *key_val = query_paramns->keys_vals[i];
        char *key = key_val->key;
        char *value = key_val->value;
        printf("%s : %s\n", key, value);
    }
    printf("------------------------------------------\n");
    return cweb_send_text("Hello World", 200);

}

int main(int argc, char *argv[]){
    CwebServer server = newCwebSever(5000, main_sever);
    CwebServer_start(&server);
    return 0;
}