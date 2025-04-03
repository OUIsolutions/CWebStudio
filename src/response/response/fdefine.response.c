//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dep_define.h"
//silver_chain_scope_end

CwebHttpResponse *newCwebHttpResponse(){
     CwebHttpResponse *self = ( CwebHttpResponse *)malloc(
        sizeof(CwebHttpResponse)
    );
    self->status_code = 200;
    self->headers = newCwebDict();
    self->content_length = 0;
    self->exist_content = false;
    self->content = NULL;
    //self->add_header(self, "connection", "close");

    return self;
}

char *CwebHttpResponse_generate_response(struct CwebHttpResponse*self){

    char *response_string = (char*)malloc(20000);
    sprintf(response_string, "HTTP/1.1 %d OK\r\n", self->status_code);
    CwebDict *headers = self->headers;
    char content_length_str[1000] = {0};
    sprintf(content_length_str, "Content-Length: %d\r\n",self->content_length);
    strcat(response_string, content_length_str);

    for(int i = 0; i < headers->size; i++){
        CwebKeyVal *key_val = headers->keys_vals[i];
        char *key = key_val->key;
        char *value = key_val->value;
        char header[1000] = {0};
        sprintf(header, "%s: %s\r\n", key, value);
        strcat(response_string, header);
    }
    if(self->headers->size == 0){
        strcat(response_string, "\r\n");
    }
    strcat(response_string, "\r\n");

    return response_string;
}

void CwebHttpResponse_free(struct CwebHttpResponse *self){
    CwebDict_free(self->headers);
    free(self->content);
    free(self);
}

void CwebHttpResponse_set_content(struct CwebHttpResponse *self, unsigned char *content, int content_length){
    self->content = (unsigned char*)malloc(content_length+2);
    memcpy(self->content, content, content_length);
    self->exist_content = true;
    self->content_length = content_length;
}

void CwebHttpResponse_add_header(struct CwebHttpResponse *self, const char *key, const  char *value){
    CwebDict_set(self->headers, key, value);
}
