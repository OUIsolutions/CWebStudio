

#include "../uniq.definitions_requirements.h"



int  CWebHyDrationBridge_get_total_avaialible_searchs(CWebHyDrationBridge *self){
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;
    return cJSON_GetArraySize(hydration->content);
}


CWebHyDrationSearchResult * CWebHyDrationBridge_get_search_by_index(CWebHyDrationBridge *self,int index){

    CWebHyDration *hydration = (CWebHyDration*)self->hydration;



    return item->string;
}
