
#include "../uniq.declaration_requirements.h"

int  CWebHyDrationBridge_get_total_avaialible_searchs(CWebHyDrationBridge *self);

const char * CWebHyDrationBridge_get_search_name_by_index(CWebHyDrationBridge *self,int index);


int  CWebHyDrationBridge_get_total_itens_of_search(CWebHyDrationBridge *self,const char *search_name,...);

cJSON * private_CWebHyDrationBridge_get_search_item_at_index(CWebHyDrationBridge *self,int index,const char *key);

bool  CWebHyDrationBridge_search_item_exist(CWebHyDrationBridge *self,int index,const char *search_name,...);

bool  CWebHyDrationBridge_is_search_item_number(CWebHyDrationBridge *self,int index,const char *search_name,...);

bool  CWebHyDrationBridge_content_is_search_item_bool(CWebHyDrationBridge *self,int index,const char *search_name,...);

bool  CWebHyDrationBridge_is_search_item_string( CWebHyDrationBridge *self,int index, const char *search_name,...);

cJSON *   private_CWebHyDrationBridge_get_cJSON_element(CWebHyDrationBridge *self, int index,const char *key,cJSON_bool (*callback_verifier)(const cJSON * const item),const char *expected_type);

double CWebHyDrationBridge_get_double_from_search_item(CWebHyDrationBridge *self,int  index, const char *search_name,...);

long  CWebHyDrationBridge_get_long_from_search_item(CWebHyDrationBridge *self,int index,const char *search_name,...);

bool  CWebHyDrationBridge_get_bool_from_search_item(CWebHyDrationBridge *self,int index,const char *search_name,...);


char*  CWebHyDrationBridge_get_str_from_search_item(CWebHyDrationBridge *self,int index, const char *search_name,...);
