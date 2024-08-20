
#include "../uniq.declaration_requirements.h"



CWebHyDrationSearchResult * private_newCWebHyDrationSearchResult(CWebHyDrationBridge *bridge,cJSON *search);

void privateCWebHyDrationSearchResult_free(CWebHyDrationSearchResult *self);


int  CWebHyDrationSearchResult_get_total_itens(CWebHyDrationSearchResult *self);


bool  CWebHyDrationSearchResult_search_item_exist(CWebHyDrationSearchResult *self,int index);


bool  CWebHyDrationSearchResult_is_search_item_number(CWebHyDrationSearchResult *self,int index);

bool  CWebHyDrationSearchResult_is_search_item_bool(CWebHyDrationSearchResult *self,int index);


bool  CWebHyDrationSearchResult_is_search_item_string(CWebHyDrationSearchResult *self,int index);
cJSON * private_CWebHyDrationSearchResult_get_cJSON_item_verifying_type(
    CWebHyDrationSearchResult *self,
    int index,
    cJSON_bool (*callback_verifier)(const cJSON * const item),
    const char *expected_type
);


double CWebHyDrationSearchResult_get_double(CWebHyDrationSearchResult *self,int  index);


long CWebHyDrationSearchResult_get_long(CWebHyDrationSearchResult *self,int  index);


long CWebHyDrationSearchResult_get_bool(CWebHyDrationSearchResult *self,int  index);



char*  CWebHyDrationSearchResult_get_string(CWebHyDrationSearchResult *self,int  index);


cJSON *  CWebHyDrationSearchResult_get_cJSON(CWebHyDrationSearchResult *self,int  index);
