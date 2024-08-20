

#include "../uniq.definitions_requirements.h"
#include <time.h>



int  CWebHyDrationBridge_get_total_avaialible_searchs(CWebHyDrationBridge *self){
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;
    return cJSON_GetArraySize(hydration->content);
}


CWebHyDrationSearchResult * CWebHyDrationBridge_get_search_by_index(CWebHyDrationBridge *self,int index){

    CWebHyDration *hydration = (CWebHyDration*)self->hydration;
    cJSON *search =  cJSON_GetArrayItem(hydration->content, index);
    if(search == NULL){
        privateCWebHydration_raise_error(
            hydration,
            self,
            CWEB_HYDRATION_CONTENT_SEARCH_NOT_EXIST,
            CWEB_HYDRATION_CONTENT_SEARCH_NOT_EXIST_MSG,
            index
        );
        return NULL;
    }
    CWebHyDrationSearchResult *result = private_newCWebHyDrationSearchResult(self, search);
    UniversalGarbage_add(hydration->garbage,privateCWebHyDrationSearchResult_free,result);
    return result;
}

CWebHyDrationSearchResult * CWebHyDrationBridge_get_search_by_name(CWebHyDrationBridge *self,const char *name,...){


    va_list  args;
    va_start(args,name);
    char *formmated_name = private_CWeb_format_vaarg(name,args);
    va_end(args);

    CWebHyDration *hydration = (CWebHyDration*)self->hydration;
    cJSON *search = cJSON_GetObjectItem(hydration->content,formmated_name);
    if(search == NULL){
        privateCWebHydration_raise_error(
            hydration,
            self,
            CWEB_HYDRATION_CONTENT_KEY_NOT_PROVIDED,
            CWEB_HYDRATION_CONTENT_KEY_NOT_PROVIDED_MSG,
            formmated_name
        );
        free(formmated_name);
        return NULL;
    }
    free(formmated_name);

    CWebHyDrationSearchResult *result = private_newCWebHyDrationSearchResult(self, item);
    UniversalGarbage_add(hydration->garbage,privateCWebHyDrationSearchResult_free,result);
    return result;
}

bool CWebHyDrationBridge_search_exist(CWebHyDrationBridge *self,const char *name,...){

    va_list  args;
        va_start(args,name);
        char *formmated_name = private_CWeb_format_vaarg(name,args);
        va_end(args);

        CWebHyDration *hydration = (CWebHyDration*)self->hydration;
        cJSON *search = cJSON_GetObjectItem(hydration->content,formmated_name);
        free(formmated_name);
        return search != NULL;
}
