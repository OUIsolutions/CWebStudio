#include "CWebStudioOne.c"

CwebHttpResponse *main_sever(CwebHttpRequest *request) {
    CwebDict *headers = request->headers;
    for(int i = 0; i < headers->size; i++) {
        struct CwebKeyVal *key_val = headers->keys_vals[i];
        char *key = key_val->key;
        char *value = key_val->value;
        printf("%s : %s\n", key, value);
    }
    printf("-------------------------------\n");
    return cweb_send_text("Headers Iterated", 200);
}

int main(int argc, char *argv[]) {
    CwebServer server = newCwebSever(5000, main_sever);
    CwebServer_start(&server);
    return 0;
}