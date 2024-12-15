#include "src/one.c"
CwebNamespace cweb;

CwebHttpResponse *main_sever( CwebHttpRequest *request ){

    CwebDict *headers = request->headers;
    for(int i = 0; i < headers->size; i++){
        struct CwebKeyVal *key_val = headers->keys_vals[i];
        char *key = key_val->key;
        char *value = key_val->value;
        printf("%s : %s\n", key, value);
    }
    printf("-------------------------------\n");
    printf("body:%s\n",cweb.request.read_content(request,2000));

    return cweb.response.send_text("Headers Iterated", 200);
}


int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    CwebServer server = newCwebSever(5001, main_sever);
    server.single_process= true;
    cweb.server.start(&server);
    return 0;
}
