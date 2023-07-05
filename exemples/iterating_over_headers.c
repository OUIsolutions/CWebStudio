

#include "../CWebStudio_test.h"
 CwebHttpResponse *main_sever( CwebHttpRequest *request ){

     CwebDict *headers = request->headers;
    for(int i = 0; i < headers->size; i++){
        struct CwebKeyVal *key_val = headers->keys_vals[i];
        char *key = key_val->key;
        char *value = key_val->value;
        printf("%s : %s\n", key, value);
    }
    return cweb_send_text("Hello World", 200);
    
}

CWEB_START_MACRO(5001, main_sever);