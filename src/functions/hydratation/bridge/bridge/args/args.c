#include "../uniq.definitions_requirements.h"
#include <time.h>


long  CWebHyDrationBridge_read_long_arg(CWebHyDrationBridge *self,int index){

    cJSON *item = cJSON_GetArrayItem(self->args,index);
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;

    if(item == NULL){
        privateCWebHydration_raise_error(
            hydration,
            self,
            CWEB_HYDRATION_INDEX_NOT_PROVIDED,
            CWEB_HYDRATION_INDEX_NOT_PROVIDED_MSG,
            index);
        return -1;
    }
    if(!cJSON_IsNumber(item)){
        privateCWebHydration_raise_error(
            hydration,
            self,
            CWEB_HYDRATION_INDEX_WRONG_TYPE,
            CWEB_HYDRATION_INDEX_WRONG_TYPE_MSG,
            index,
            CWEB_HYDRATION_NUMBER
        );
        return -1;
    }

    return (long)cJSON_GetNumberValue(item);
}

double  CWebHyDrationBridge_read_double_arg(CWebHyDrationBridge *self,int index){

    cJSON *item = cJSON_GetArrayItem(self->args,index);
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;

    if(item == NULL){
        privateCWebHydration_raise_error(
            hydration,
            self,
            CWEB_HYDRATION_INDEX_NOT_PROVIDED,
            CWEB_HYDRATION_INDEX_NOT_PROVIDED_MSG,
            index);
        return -1;
    }
    if(!cJSON_IsNumber(item)){
        privateCWebHydration_raise_error(
            hydration,
            self,
            CWEB_HYDRATION_INDEX_WRONG_TYPE,
            CWEB_HYDRATION_INDEX_WRONG_TYPE_MSG,
            index,
            CWEB_HYDRATION_NUMBER
        );
        return -1;
    }

    return cJSON_GetNumberValue(item);
}


bool  CWebHyDrationBridge_read_bool_arg(CWebHyDrationBridge *self,int index){

    cJSON *item = cJSON_GetArrayItem(self->args,index);
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;

    if(item == NULL){
        privateCWebHydration_raise_error(
            hydration,
            self,
            CWEB_HYDRATION_INDEX_NOT_PROVIDED,
            CWEB_HYDRATION_INDEX_NOT_PROVIDED_MSG,
            index);
        return -1;
    }
    if(!cJSON_IsBool(item)){
        privateCWebHydration_raise_error(
            hydration,
            self,
            CWEB_HYDRATION_INDEX_WRONG_TYPE,
            CWEB_HYDRATION_INDEX_WRONG_TYPE_MSG,
            index,
            CWEB_HYDRATION_BOOL
        );
        return -1;
    }

    return (bool)item->valueint;
}

char* CWebHyDrationBridge_read_str_arg(CWebHyDrationBridge *self,int index){

    cJSON *item = cJSON_GetArrayItem(self->args,index);
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;

    if(item == NULL){
        privateCWebHydration_raise_error(
            hydration,
            self,
            CWEB_HYDRATION_INDEX_NOT_PROVIDED,
            CWEB_HYDRATION_INDEX_NOT_PROVIDED_MSG,
            index);
        return NULL;
    }
    if(!cJSON_IsString(item)){
        privateCWebHydration_raise_error(
            hydration,
            self,
            CWEB_HYDRATION_INDEX_WRONG_TYPE,
            CWEB_HYDRATION_INDEX_WRONG_TYPE_MSG,
            index,
            CWEB_HYDRATION_STRING
        );
        return NULL;
    }
    return cJSON_GetStringValue(item);
}
