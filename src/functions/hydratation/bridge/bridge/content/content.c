
#include "../uniq.definitions_requirements.h"
#include <cstddef>


cJSON *   private_CWebHyDrationBridge_get_cJSON_elements_list(CWebHyDrationBridge *self, long index, const char *key){

    CWebHyDration *hydration = (CWebHyDration*)self->hydration;
    cJSON *itens = cJSON_GetObjectItem(self->content,key);

    if(itens == NULL){
            privateCWebHydration_raise_error(
                hydration,
                self,
                CWEB_HYDRATION_KEY_NOT_PROVIDED,
                CWEB_HYDRATION_KEY_NOT_PROVIDED_MSG,
                key);
            return NULL;
    }

    if(!cJSON_IsArray(itens)){
        privateCWebHydration_raise_error(
            hydration,
            self,
            CWEB_HYDRATION_KEY_IS_NOT_ARRAY,
            CWEB_HYDRATION_KEY_IS_NOT_ARRAY_MSG,
            key);
        return NULL;
    }

    cJSON *item  = cJSON_GetArrayItem(itens,index);


    return itens;

}
double CWebHyDrationBridge_read_double_content(CWebHyDrationBridge *self,long index, const char *key,...){


    va_list  args;
    va_start(args,key);
    char *key_formmated = private_CWeb_format_vaarg(key,args);
    va_end(args);
    cJSON *itens = private_CWebHyDrationBridge_get_cJSON_elements_list(self,key_formmated);
    free(key_formmated);
    if(itens == NULL){
        return -1;
    }
    if(!cJSON_IsNumber(item)){
        privateCWebHydration_raise_error(
            hydration,
            self,
            CWEB_HYDRATION_KEY_WRONG_TYPE,
            CWEB_HYDRATION_KEY_WRONG_TYPE_MSG,
            key_formmated,
            CWEB_HYDRATION_NUMBER
        );
        free(key_formmated);
        return -1;
    }
    return cJSON_GetNumberValue(item);
}


long  CWebHyDrationBridge_read_long_content(CWebHyDrationBridge *self,const char *key,...){

    va_list  args;
    va_start(args,key);
    char *key_formmated = private_CWeb_format_vaarg(key,args);
    va_end(args);

    cJSON *item = cJSON_GetObjectItem(self->content,key_formmated);
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;

    if(item == NULL){
            privateCWebHydration_raise_error(
                hydration,
                self,
                CWEB_HYDRATION_KEY_NOT_PROVIDED,
                CWEB_HYDRATION_KEY_NOT_PROVIDED_MSG,
                key_formmated);
            free(key_formmated);
            return -1;
    }
    if(!cJSON_IsNumber(item)){
        privateCWebHydration_raise_error(
            hydration,
            self,
            CWEB_HYDRATION_KEY_WRONG_TYPE,
            CWEB_HYDRATION_KEY_WRONG_TYPE_MSG,
            key_formmated,
            CWEB_HYDRATION_NUMBER
        );
        free(key_formmated);
        return -1;
    }
    free(key_formmated);
    return (long)cJSON_GetNumberValue(item);
}
bool  CWebHyDrationBridge_read_bool_content(CWebHyDrationBridge *self,const char *key,...){

    va_list  args;
    va_start(args,key);
    char *key_formmated = private_CWeb_format_vaarg(key,args);
    va_end(args);

    cJSON *item = cJSON_GetObjectItem(self->content,key_formmated);
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;

    if(item == NULL){
            privateCWebHydration_raise_error(
                hydration,
                self,
                CWEB_HYDRATION_KEY_NOT_PROVIDED,
                CWEB_HYDRATION_KEY_NOT_PROVIDED_MSG,
                key_formmated);
            free(key_formmated);
            return -1;
    }
    if(!cJSON_IsBool(item)){
        privateCWebHydration_raise_error(
            hydration,
            self,
            CWEB_HYDRATION_KEY_WRONG_TYPE,
            CWEB_HYDRATION_KEY_WRONG_TYPE_MSG,
            key_formmated,
            CWEB_HYDRATION_BOOL
        );
        free(key_formmated);
        return -1;
    }
    free(key_formmated);
    return (bool)item->valueint;
}

char*  CWebHyDrationBridge_read_str_content(CWebHyDrationBridge *self,const char *key,...){

    va_list  args;
    va_start(args,key);
    char *key_formmated = private_CWeb_format_vaarg(key,args);
    va_end(args);

    cJSON *item = cJSON_GetObjectItem(self->content,key_formmated);
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;

    if(item == NULL){
            privateCWebHydration_raise_error(
                hydration,
                self,
                CWEB_HYDRATION_KEY_NOT_PROVIDED,
                CWEB_HYDRATION_KEY_NOT_PROVIDED_MSG,
                key_formmated);
            free(key_formmated);
            return NULL;
    }
    if(!cJSON_IsString(item)){
        privateCWebHydration_raise_error(
            hydration,
            self,
            CWEB_HYDRATION_KEY_WRONG_TYPE,
            CWEB_HYDRATION_KEY_WRONG_TYPE_MSG,
            key_formmated,
            CWEB_HYDRATION_STRING
        );
        free(key_formmated);
        return NULL;
    }
    free(key_formmated);
    return  cJSON_GetStringValue(item);
}
