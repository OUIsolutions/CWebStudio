
#include "../uniq.definitions_requirements.h"



CWebHyDration *newCWebHyDration(CwebHttpRequest *request) {

    if(request->hydratation){
        return (CWebHyDration*)request->hydratation;
    }

    CWebHyDration *self = (CWebHyDration*)malloc(sizeof(CWebHyDration));
    *self = (CWebHyDration){0};
    self->all_bridges = private_new_privateCWebHyDrationBridgeArray();
    self->request =  request;
    self->response = cJSON_CreateArray();
    self->garbage = newUniversalGarbage();
    self->max_content_size = CWEB_HYDRATION_DEFAULT_BODY_SIZE;
    request->hydratation = (void *)self;

    return self;
}

CWebHyDrationBridge * CWebHyDration_create_bridge(CWebHyDration *self,const char *name,void (*callback)(CWebHyDrationBridge *)){
    CWebHyDrationBridge *created = private_newCWebHyDrationBridge(name,callback,self);
    privateCWebHyDrationBridgeArray_append(self->all_bridges,created);
    return created;
}

bool CWebHyDration_is_the_trigger(CWebHyDration *self){
    if(strcmp(self->request->route,CWEB_HYDRATION_CALBACK_HANDLER_ROUTE) == 0){
        return true;
    }
    return false;
}

void privateCWebHydration_raise_error(CWebHyDration *self,CWebHyDrationBridge *bridge, int error_code, const char *format,...){
    va_list  args;
    va_start(args,format);
    self->error_msg = private_CWeb_format_vaarg(format,args);
    va_end(args);
    self->error_code = error_code;
    if(bridge){
        self->error_bridge_name = bridge->name;
    }
}


CwebHttpResponse *CWebHydration_generate_response(CWebHyDration *self){
    if(!CWebHyDration_is_the_trigger(self)){
        return NULL;
    }
    cJSON *body = CWebHttpRequest_read_cJSON(self->request, self->max_content_size);


    if(body ==NULL){
        privateCWebHydration_raise_error(
            self,
            NULL,
            CWEB_HYDRATION_NOT_BODY_JSON_PROVIDED,
            CWEB_HYDRATION_NOT_BODY_JSON_PROVIDED_MSG
        );
        return private_CWebHydration_formmat_error_response(self);
    }

    if(!cJSON_IsObject(body)){
        privateCWebHydration_raise_error(
            self,
            NULL,
            CWEB_HYDRATION_NOT_BODY_IS_NOT_OBJECT,
            CWEB_HYDRATION_NOT_BODY_IS_NOT_OBJECT_MSG
        );
        return private_CWebHydration_formmat_error_response(self);
    }

    cJSON *name = cJSON_GetObjectItem(body, CWEB_HYDRATON_JSON_NAME);


    if(name == NULL){
        privateCWebHydration_raise_error(
            self,
            NULL,
            CWEB_HYDRATION_NAME_NOT_PROVIDED,
            CWEB_HYDRATION_NAME_NOT_PROVIDED_MSG
        );
        return private_CWebHydration_formmat_error_response(self);
    }


    if(!cJSON_IsString(name)){
            privateCWebHydration_raise_error(
                self,
                NULL,
                CWEB_HYDRATION_NAME_NOT_STRING,
                CWEB_HYDRATION_NAME_NOT_STRING_MSG
            );
            return private_CWebHydration_formmat_error_response(self);
    }

    cJSON *args = cJSON_GetObjectItem(body, CWEB_HYDRATON_JSON_ARGS);
    if(args == NULL){
        privateCWebHydration_raise_error(
            self,
            NULL,
            CWEB_HYDRATION_ARGS_NOT_PROVIDED,
            CWEB_HYDRATION_ARGS_NOT_PROVIDED_MSG
        );
        return private_CWebHydration_formmat_error_response(self);
    }

    if(!cJSON_IsArray(args)){
        privateCWebHydration_raise_error(
            self,
            NULL,
            CWEB_HYDRATION_ARGS_NOT_ARRAY,
            CWEB_HYDRATION_ARGS_NOT_ARRAY_MSG
        );
        return private_CWebHydration_formmat_error_response(self);
    }

    cJSON *content = cJSON_GetObjectItem(body, CWEB_HYDRATON_JSON_CONTENT);

    if(content == NULL){
        privateCWebHydration_raise_error(
            self,
            NULL,
            CWEB_HYDRATION_CONTENT_NOT_PROVIDED,
            CWEB_HYDRATION_CONTENT_NOT_PROVIDED_MSG
        );
        return private_CWebHydration_formmat_error_response(self);
    }
    if(!cJSON_IsObject(content)){
        privateCWebHydration_raise_error(
            self,
            NULL,
            CWEB_HYDRATION_CONTENT_NOT_OBJECT,
            CWEB_HYDRATION_CONTENT_NOT_OBJECT_MSG
        );
        return private_CWebHydration_formmat_error_response(self);
    }

    int size =cJSON_GetArraySize(content);
    for(int i = 0; i < size;i++){
        cJSON *current_search  = cJSON_GetArrayItem(content, i);
        if(!cJSON_IsArray(current_search)){
            privateCWebHydration_raise_error(
                self,
                NULL,
                CWEB_HYDRATION_CONTENT_SEARCH_NOT_ARRAY,
                CWEB_HYDRATION_CONTENT_SEARCH_NOT_ARRAY_MSG,
                current_search->string
            );
            return private_CWebHydration_formmat_error_response(self);
        }
    }


    char *name_str = cJSON_GetStringValue(name);
    CWebHyDrationBridge *target_bridge = NULL;
    for(int i = 0; i < self->all_bridges->size;i++){
        CWebHyDrationBridge *current = self->all_bridges->elments[i];
        if(strcmp(current->name,name_str)==0){
                target_bridge = current;
                break;
        }
    }
    if(target_bridge == NULL){
        privateCWebHydration_raise_error(
            self,
            NULL,
            CWEB_BRIDGE_NOT_FOUND,
            CWEB_BRIDGE_NOT_FOUND_MSG,
            name_str
        );
        return private_CWebHydration_formmat_error_response(self);
    }

    self->args =args;
    self->content = content;
    target_bridge->callback(target_bridge);
    if(self->error_code){
        return private_CWebHydration_formmat_error_response(self);

    }
    CwebHttpResponse *final_response = cweb_send_cJSON_cleaning_memory(self->response, 200);
    self->response = NULL;
    return final_response;

}
CwebHttpResponse *private_CWebHydration_formmat_error_response(CWebHyDration *self){
    cJSON * response = cJSON_CreateObject();
    cJSON_AddStringToObject(response, CWEB_HYDRATION_JSON_ERROR_MENSSAGE,self->error_msg);
    cJSON_AddNumberToObject(response, CWEB_HYDRATION_JSON_ERROR_CODE_KEY,self->error_code);
    return cweb_send_cJSON_cleaning_memory(response, 404);
}

char *CWebHyDration_create_script(CWebHyDration *self) {

    if(self->script_text) {
        CTextStack_free(self->script_text);
    }

    self->script_text = newCTextStack_string_empty();

    CTextStack_format(self->script_text,"%s", private_cweb_hydration_js_content);

    for(int i =0; i < self->all_bridges->size;i++) {
        CWebHyDrationBridge *current = self->all_bridges->elments[i];
        CTextStack* created_code =private_CWebHyDrationBridge_create_script(current);
        CTextStack_format(self->script_text,"%tc",created_code);
    }
    return self->script_text->rendered_text;

}

void private_CWebHyDration_free(CWebHyDration *self) {
    if(self->script_text) {
        CTextStack_free(self->script_text);
    }
    if(self->error_msg){
        free(self->error_msg);
    }
    if(self->response){
        cJSON_Delete(self->response);
    }
    if(self->garbage){
       UniversalGarbage_free(self->garbage);
    }

    privateCWebHyDrationBridgeArray_free(self->all_bridges);
    free(self);
}
