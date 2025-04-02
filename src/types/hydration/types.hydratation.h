
typedef struct CWebHyDration {
    CwebHttpRequest *request;
   const  char *error_bridge_name;
    char *error_msg;
    cJSON *response;
    cJSON *args;
    cJSON *content;

    int error_code;
   // CwebStringArray *stack_elements;
    CTextStack *script_text;
    long max_content_size;
    privateCWebHyDrationBridgeArray *all_bridges;

}CWebHyDration;

