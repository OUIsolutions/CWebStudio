#include "../uniq.definitions_requirements.h"


int   CWebHyDrationBridge_get_args_size(CWebHyDrationBridge *self,int index){
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;
    return cJSON_GetArraySize(hydration->args);
}


bool private_cweb_hydration_type_verifier(CWebHyDrationBridge *self,int index,cJSON_bool (*callback_verifier)(const cJSON * const item)){
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;
    cJSON *item = cJSON_GetArrayItem(hydration->args, index);
    if(item == NULL){
        return false;
    }
    return (bool)callback_verifier(item);
}

bool   CWebHyDrationBridge_is_arg_number(CWebHyDrationBridge *self,int index){
    return private_cweb_hydration_type_verifier(self,index,cJSON_IsNumber);
}

bool   CWebHyDrationBridge_is_arg_bool(CWebHyDrationBridge *self,int index){
    return private_cweb_hydration_type_verifier(self,index,cJSON_IsBool);
}
bool   CWebHyDrationBridge_is_arg_string(CWebHyDrationBridge *self,int index){
    return private_cweb_hydration_type_verifier(self,index,cJSON_IsString);
}


cJSON *privateCWebHyDration_get_arg_index(
    CWebHyDrationBridge *self,
    int index,
    cJSON_bool (*callback_verifier)(const cJSON * const item),
    const char *expected_type
){
        CWebHyDration *hydration = (CWebHyDration*)self->hydration;

    cJSON *item = cJSON_GetArrayItem(hydration->args,index);

    if(item == NULL){
        privateCWebHydration_raise_error(
            hydration,
            self,
            CWEB_HYDRATION_INDEX_ARGS_NOT_PROVIDED,
            CWEB_HYDRATION_INDEX_ARGS_NOT_PROVIDED_MSG,
            index);
        return NULL;
    }
    if(!callback_verifier){
        return  item;
    }

    if(!callback_verifier(item)){
        privateCWebHydration_raise_error(
            hydration,
            self,
            CWEB_HYDRATION_INDEX_ARGS_WRONG_TYPE,
            CWEB_HYDRATION_INDEX_ARGS_WRONG_TYPE_MSG,
            index,
            expected_type
        );
        return NULL;
    }
    return item;
}

double  CWebHyDrationBridge_get_double_arg(CWebHyDrationBridge *self,int index){

    cJSON *item = privateCWebHyDration_get_arg_index(self,index,cJSON_IsNumber,CWEB_HYDRATION_NUMBER);
    if(item == NULL){
        return -1;
    }

    return cJSON_GetNumberValue(item);
}

long  CWebHyDrationBridge_get_long_arg(CWebHyDrationBridge *self,int index){

    cJSON *item = privateCWebHyDration_get_arg_index(self,index,cJSON_IsNumber,CWEB_HYDRATION_NUMBER);
    if(item == NULL){
        return -1;
    }

    return (long)cJSON_GetNumberValue(item);
}



bool  CWebHyDrationBridge_get_bool_arg(CWebHyDrationBridge *self,int index){

    cJSON *item = privateCWebHyDration_get_arg_index(self,index,cJSON_IsNumber,CWEB_HYDRATION_BOOL);
        if(item == NULL){
            return -1;
        }

    return (bool)item->valueint;
}

char* CWebHyDrationBridge_get_str_arg(CWebHyDrationBridge *self,int index){

    cJSON *item = privateCWebHyDration_get_arg_index(self,index,cJSON_IsNumber,CWEB_HYDRATION_STRING);
        if(item == NULL){
            return NULL;
        }

    return cJSON_GetStringValue(item);
}
cJSON * CWebHyDrationBridge_get_cJSON_arg(CWebHyDrationBridge *self,int index){
    return  privateCWebHyDration_get_arg_index(self,index,NULL,NULL);
}
