
#include "../uniq.definitions_requirements.h"


int  CWebHyDrationBridge_get_content_key_size(CWebHyDrationBridge *self,const char *key,...){

    va_list  args;
    va_start(args,key);
    char *key_formmated = private_CWeb_format_vaarg(key,args);
    va_end(args);

    cJSON *itens = cJSON_GetObjectItem(self->content,key_formmated);
    free(key_formmated);
    if(itens == NULL){
        return  0;
    }

    if(!cJSON_IsArray(itens)){
        return 0;
    }

    return cJSON_GetArraySize(itens);
}

cJSON * private_CWebHyDrationBridge_get_content_at_index(CWebHyDrationBridge *self,int index,const char *key){

    cJSON *itens = cJSON_GetObjectItem(self->content,key);
    if(itens == NULL){
        return NULL;
    }

    if(!cJSON_IsArray(itens)){
        return NULL;
    }

    cJSON *item = cJSON_GetArrayItem(itens,index);
    return item;
}

bool  CWebHyDrationBridge_content_exist_at_index(CWebHyDrationBridge *self,int index,const char *key,...){
    va_list  args;
    va_start(args,key);
    char *key_formmated = private_CWeb_format_vaarg(key,args);
    va_end(args);
   cJSON *item = private_CWebHyDrationBridge_get_content_at_index(self,index, key_formmated);
   free(key_formmated);
   if(item){
       return true;
   }
   return false;
}



bool  CWebHyDrationBridge_content_is_number_at_index(CWebHyDrationBridge *self,int index,const char *key,...){
    va_list  args;
    va_start(args,key);
    char *key_formmated = private_CWeb_format_vaarg(key,args);
    va_end(args);
   cJSON *item = private_CWebHyDrationBridge_get_content_at_index(self,index, key_formmated);
   free(key_formmated);
   if(item == NULL){
       return false;
   }
   return cJSON_IsNumber(item);
}


bool  CWebHyDrationBridge_content_is_bool_at_index(CWebHyDrationBridge *self,int index,const char *key,...){
    va_list  args;
    va_start(args,key);
    char *key_formmated = private_CWeb_format_vaarg(key,args);
    va_end(args);
   cJSON *item = private_CWebHyDrationBridge_get_content_at_index(self,index, key_formmated);
   free(key_formmated);
   if(item == NULL){
       return false;
   }
   return cJSON_IsBool(item);
}




bool  CWebHyDrationBridge_content_is_string_at_index(CWebHyDrationBridge *self,int index,const char *key,...){
    va_list  args;
    va_start(args,key);
    char *key_formmated = private_CWeb_format_vaarg(key,args);
    va_end(args);
   cJSON *item = private_CWebHyDrationBridge_get_content_at_index(self,index, key_formmated);
   free(key_formmated);
   if(item == NULL){
       return false;
   }
   return cJSON_IsString(item);
}



cJSON *   private_CWebHyDrationBridge_get_cJSON_element(
    CWebHyDrationBridge *self,
    int index,
    const char *key,
    cJSON_bool (*callback_verifier)(const cJSON * const item),
    const char *expected_type
){

    CWebHyDration *hydration = (CWebHyDration*)self->hydration;
    cJSON *itens = cJSON_GetObjectItem(self->content,key);

    if(itens == NULL){
            privateCWebHydration_raise_error(
                hydration,
                self,
                CWEB_HYDRATION_CONTENT_KEY_NOT_PROVIDED,
                CWEB_HYDRATION_KEY_NOT_PROVIDED_MSG,
                key);
            return NULL;
    }

    if(!cJSON_IsArray(itens)){
        privateCWebHydration_raise_error(
            hydration,
            self,
            CWEB_HYDRATION_CONTENT_KEY_NOT_ARRAY,
            CWEB_HYDRATION_CONTENT_KEY_NOT_ARRAY_MSG,
            key);
        return NULL;
    }

    cJSON *item  = cJSON_GetArrayItem(itens,index);
    if(item == NULL){
        privateCWebHydration_raise_error(
            hydration,
            self,
            CWEB_HYDRATION_CONTENT_NOT_EXIST_AT_INDEX,
            CWEB_HYDRATION_CONTENT_NOT_EXIST_AT_INDEX_MSG,
            key,
            index
        );
        return NULL;
    }

    if(!callback_verifier(item)){
        privateCWebHydration_raise_error(
            hydration,
            self,
            CWEB_HYDRATION_CONTENT_WRONG_TYPE,
            CWEB_HYDRATION_CONTENT_WRONG_TYPE_MSG,
            key,
            index,
            expected_type
        );
        return NULL;
    }

    return item;
}

double CWebHyDrationBridge_get_double_content(CWebHyDrationBridge *self,int  index, const char *key,...){

    va_list  args;
    va_start(args,key);
    char *key_formmated = private_CWeb_format_vaarg(key,args);
    va_end(args);
    cJSON *item = private_CWebHyDrationBridge_get_cJSON_element(self,index,key_formmated,cJSON_IsNumber,CWEB_HYDRATION_NUMBER);
    free(key_formmated);
    if(item == NULL){
        return -1;
    }
    return cJSON_GetNumberValue(item);
}


long  CWebHyDrationBridge_get_long_content(CWebHyDrationBridge *self,int index,const char *key,...){
    va_list  args;
    va_start(args,key);
    char *key_formmated = private_CWeb_format_vaarg(key,args);
    va_end(args);
    cJSON *item = private_CWebHyDrationBridge_get_cJSON_element(self,index,key_formmated,cJSON_IsNumber,CWEB_HYDRATION_NUMBER);
    free(key_formmated);
    if(item == NULL){
        return -1;
    }
    return (long)cJSON_GetNumberValue(item);
}

bool  CWebHyDrationBridge_get_bool_content(CWebHyDrationBridge *self,int index,const char *key,...){
    va_list  args;
    va_start(args,key);
    char *key_formmated = private_CWeb_format_vaarg(key,args);
    va_end(args);
    cJSON *item = private_CWebHyDrationBridge_get_cJSON_element(self,index,key_formmated,cJSON_IsBool,CWEB_HYDRATION_NUMBER);
    free(key_formmated);
    if(item == NULL){
        return false;
    }
    return (bool)item->valueint;
}


char*  CWebHyDrationBridge_get_str_content(CWebHyDrationBridge *self,int index, const char *key,...){
    va_list  args;
    va_start(args,key);
    char *key_formmated = private_CWeb_format_vaarg(key,args);
    va_end(args);
    cJSON *item = private_CWebHyDrationBridge_get_cJSON_element(self,index,key_formmated,cJSON_IsString,CWEB_HYDRATION_NUMBER);
    free(key_formmated);
    if(item == NULL){
        return NULL;
    }
    return cJSON_GetStringValue(item);
}
