

int  CWebHyDrationBridge_get_total_avaialible_searchs(CWebHyDrationBridge *self);

CWebHyDrationSearchResult * CWebHyDrationBridge_get_search_by_index(CWebHyDrationBridge *self,int index);

CWebHyDrationSearchResult * CWebHyDrationBridge_get_search_by_name(CWebHyDrationBridge *self,const char *name,...);

bool CWebHyDrationBridge_search_exist(CWebHyDrationBridge *self,const char *name,...);

double CWebHyDrationBridge_get_double_from_first_element_of_search(CWebHyDrationBridge *self,const char *name,...);

long CWebHyDrationBridge_get_long_from_first_element_of_search(CWebHyDrationBridge *self,const char *name,...);

bool CWebHyDrationBridge_get_bool_from_first_element_of_search(CWebHyDrationBridge *self,const char *name,...);

char* CWebHyDrationBridge_get_string_from_first_element_of_search(CWebHyDrationBridge *self,const char *name,...);

cJSON* CWebHyDrationBridge_get_cJSON_from_first_element_of_search(CWebHyDrationBridge *self,const char *name,...);
