

#include "../uniq.definitions_requirements.h"
#include <time.h>



int  CWebHyDrationBridge_get_total_avaialible_searchs(CWebHyDrationBridge *self){
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;
    return cJSON_GetArraySize(hydration->content);
}


CWebHyDrationSearchResult * CWebHyDrationBridge_get_search_by_index(CWebHyDrationBridge *self,int index){

    CWebHyDration *hydration = (CWebHyDration*)self->hydration;
    cJSON *item =  cJSON_GetArrayItem(hydration->content, index);
    if(item == NULL){
        privateCWebHydration_raise_error(
            hydration,
            NULL,
            CWEB_HYDRATION_CONTENT_SEARCH_NOT_EXIST,
            CWEB_HYDRATION_CONTENT_SEARCH_NOT_EXIST_MSG,
            index
        );
        return NULL;
    }

    return item;
}
