
#include "../uniq.definitions_requirements.h"

void privateCWebHyDrationBridge_add_response(CWebHyDrationBridge *self,const char *name,cJSON *data){
    CWebHyDration *hydraation = (CWebHyDration*)self->hydration;
    cJSON *current_response = cJSON_CreateObject();
    cJSON_AddStringToObject(current_response,CWEB_HYDRATON_JSON_NAME,name);
    cJSON_AddItemToObject(current_response,CWEB_HYDRATON_JSON_DATA,data);
    cJSON_AddItemToArray(hydraation->response,current_response);
}


void CWebHyDrationBridge_alert(CWebHyDrationBridge *self,const char *menssage,...){
    cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args,menssage);
    char *msg_format = private_CWeb_format_vaarg(menssage,args);
    va_end(args);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_MSG, msg_format);
    free(msg_format);
    privateCWebHyDrationBridge_add_response(self,"alert",obj);

}

void CWebHyDrationBridge_execute_script(CWebHyDrationBridge *self,const char *code,...){
    cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args,code);
    char *code_format = private_CWeb_format_vaarg(code,args);
    va_end(args);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_CODE, code_format);
    free(code_format);
    privateCWebHyDrationBridge_add_response(self,"execute_script",obj);
}

void CWebHyDrationBridge_replace_element_by_id(CWebHyDrationBridge *self,const char *id, const char *code,...){
    cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args,code);
    char *html_format = private_CWeb_format_vaarg(code,args);
    va_end(args);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_ID, id);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_HTML, html_format);
    free(html_format);
    privateCWebHyDrationBridge_add_response(self,"replace_element_by_id",obj);
}

void CWebHyDrationBridge_destroy_by_id(CWebHyDrationBridge *self,const char * id){
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_ID, id);
    privateCWebHyDrationBridge_add_response(self,"destroy_by_id",obj);
}
