
#include "../uniq.definitions_requirements.h"

void privateCWebHyDration_create_main_response(CWebHyDrationBridge *self){
    if(self->response == NULL) {
        self->response = cJSON_CreateArray();
    }
}

void CWebHyDration_add_response_callback(CWebHyDrationBridge *self, const char *callback, cJSON *args) {
    privateCWebHyDration_create_main_response(self);
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddItemToArray(self->response,obj);
    cJSON_AddStringToObject(obj,PRIVATE_CWEB_HYDRATION_CALLBACK_KEY,callback);
    cJSON_AddItemToObject(obj,PRIVATE_CWEB_HYDRATION_ARGS_KEY,args);

}

void CWebHyDration_alert(CWebHyDrationBridge *self,const char *msg,...) {
    cJSON *json_args = cJSON_CreateObject();
    va_list  args;
    va_start(args,msg);
    char *result = private_CWebHydration_format_vaarg(msg,args);
    va_end(args);
    cJSON_AddStringToObject(json_args,PRIVATE_CWEB_HYDRATION_MENSSAGE_KEY,result);
    CWebHyDration_add_response_callback(self,PRIVATE_CWEB_HYDRATION_ALERT,json_args);
    free(result);
}

void CWebHyDration_destroy_by_id(CWebHyDrationBridge *self,const char *id) {
    cJSON *json_args = cJSON_CreateObject();
    cJSON_AddStringToObject(json_args,PRIVATE_CWEB_HYDRATION_ID_KEY,id);
    CWebHyDration_add_response_callback(self,PRIVATE_CWEB_HYDRATION_DESTROY_BY_ID,json_args);
}

void CWebHyDration_replace_element_by_id_with_ctext_stack_cleaning_memory(CWebHyDrationBridge *self,const char *id,CTextStack *html) {
    cJSON *json_args = cJSON_CreateObject();
    cJSON_AddStringToObject(json_args,PRIVATE_CWEB_HYDRATION_ID_KEY,id);
    cJSON_AddStringToObject(json_args,PRIVATE_CWEB_HYDRATION_HTML_KEY,html->rendered_text);
    CWebHyDration_add_response_callback(self,PRIVATE_CWEB_HYDRATION_REPLACE_BY_ID,json_args);
    CTextStack_free(html);
}

CwebHttpResponse * CWebHyDration_generate_response(CWebHyDrationBridge *self) {
    return cweb_send_cJSON(self->response,200);
}