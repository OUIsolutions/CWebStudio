
#include "../uniq.definitions_requirements.h"




CWebHyDrationSearchResult * private_newCWebHyDrationSearchResult(CWebHyDrationBridge *bridge,cJSON *search){
    CWebHyDrationSearchResult *self = (CWebHyDrationSearchResult*)malloc(sizeof(CWebHyDrationSearchResult));
    self->bridge = bridge;
    self->search = search;
    self->name = search->string;
}

void privateCWebHyDrationSearchResult_free(CWebHyDrationSearchResult *self){
    free(self);
}

int  CWebHyDrationSearchResult_get_total_itens(CWebHyDrationSearchResult *self){
    return cJSON_GetArraySize(self->search);
}



bool  CWebHyDrationSearchResult_search_item_exist(CWebHyDrationSearchResult *self,int index){
   cJSON *item = cJSON_GetArrayItem(self->search, index);
   return item != NULL;
}



bool  CWebHyDrationSearchResult_is_search_item_number(CWebHyDrationSearchResult *self,int index){
    cJSON *item = cJSON_GetArrayItem(self->search, index);
    if(item == NULL){
        return false;
    }
   return cJSON_IsNumber(item);
}

bool  CWebHyDrationSearchResult_is_search_item_bool(CWebHyDrationSearchResult *self,int index){
    cJSON *item = cJSON_GetArrayItem(self->search, index);
    if(item == NULL){
        return false;
    }
   return cJSON_IsBool(item);
}




bool  CWebHyDrationSearchResult_is_search_item_string(CWebHyDrationSearchResult *self,int index){
    cJSON *item = cJSON_GetArrayItem(self->search, index);
    if(item == NULL){
        return false;
    }
   return cJSON_IsString(item);
}


cJSON * private_CWebHyDrationSearchResult_get_cJSON_item_verifying_type(
    CWebHyDrationSearchResult *self,
    int index,
    cJSON_bool (*callback_verifier)(const cJSON * const item),
    const char *expected_type
){

    cJSON *item  = cJSON_GetArrayItem(self->search,index);
    CWebHyDrationBridge *bridge = (CWebHyDrationBridge*)self->bridge;
    CWebHyDration *hydration = (CWebHyDration*)bridge->hydration;
    if(item == NULL){
        privateCWebHydration_raise_error(
            hydration,
            bridge,
            CWEB_HYDRATION_SEARCH_ITEM_NOT_EXIST,
            CWEB_HYDRATION_SEARCH_ITEM_NOT_EXIST_MSG,
            self->name,
            index
        );
        return NULL;
    }

    if(!callback_verifier(item)){
        privateCWebHydration_raise_error(
            hydration,
            bridge,
            CWEB_HYDRATION_SEARCH_ITEM_WRONG_TYPE,
            CWEB_HYDRATION_SEARCH_ITEM_WRONG_TYPE_MSG,
            self->name,
            index,
            expected_type
        );
        return NULL;
    }

    return item;
}

double CWebHyDrationSearchResult_get_double(CWebHyDrationSearchResult *self,int  index){

    cJSON *item = private_CWebHyDrationSearchResult_get_cJSON_item_verifying_type(self,index,cJSON_IsNumber,CWEB_HYDRATION_NUMBER);
    if(item == NULL){
        return -1;
    }
    return cJSON_GetNumberValue(item);
}

long CWebHyDrationSearchResult_get_long(CWebHyDrationSearchResult *self,int  index){

    cJSON *item = private_CWebHyDrationSearchResult_get_cJSON_item_verifying_type(self,index,cJSON_IsNumber,CWEB_HYDRATION_NUMBER);
    if(item == NULL){
        return -1;
    }
    return (long)cJSON_GetNumberValue(item);
}

long CWebHyDrationSearchResult_get_bool(CWebHyDrationSearchResult *self,int  index){

    cJSON *item = private_CWebHyDrationSearchResult_get_cJSON_item_verifying_type(self,index,cJSON_IsNumber,CWEB_HYDRATION_NUMBER);
    if(item == NULL){
        return -1;
    }
    return (bool)item->valueint;
}


char*  CWebHyDrationSearchResult_get_string(CWebHyDrationSearchResult *self,int  index){

    cJSON *item = private_CWebHyDrationSearchResult_get_cJSON_item_verifying_type(self,index,cJSON_IsNumber,CWEB_HYDRATION_NUMBER);
    if(item == NULL){
        return NULL;
    }
    return cJSON_GetStringValue(item);
}

cJSON *  CWebHyDrationSearchResult_get_cJSON(CWebHyDrationSearchResult *self,int  index){

    cJSON *item = private_CWebHyDrationSearchResult_get_cJSON_item_verifying_type(self,index,cJSON_IsNumber,CWEB_HYDRATION_NUMBER);
    return item;
}
