
#include "../../hydration/all.h"
#include "../response.h"

#ifndef PRIVATE_CWEB_HYDRATATION_CONTENT_NAMESPACE_TYPES
#define PRIVATE_CWEB_HYDRATATION_CONTENT_NAMESPACE_TYPES


typedef struct CWebHydrationContentNamespace {

    int  (*get_total_avaialible_searchs)(CWebHyDrationBridge *self);
    const char * (*get_search_name_by_index)(CWebHyDrationBridge *self,int index);
    int  (*get_total_itens_of_search)(CWebHyDrationBridge *self,const char *search_name,...);
    cJSON * (*get_search_item_at_index)(CWebHyDrationBridge *self,int index,const char *key);
    bool  (*search_item_exist)(CWebHyDrationBridge *self,int index,const char *search_name,...);
    bool  (*is_search_item_number)(CWebHyDrationBridge *self,int index,const char *search_name,...);
    bool  (*is_search_item_bool)(CWebHyDrationBridge *self,int index,const char *search_name,...);
    bool  (*is_search_item_string)( CWebHyDrationBridge *self,int index, const char *search_name,...);
    double (*get_double_from_search_item)(CWebHyDrationBridge *self,int  index, const char *search_name,...);
    long  (*get_long_from_search_item)(CWebHyDrationBridge *self,int index,const char *search_name,...);
    bool  (*get_bool_from_search_item)(CWebHyDrationBridge *self,int index,const char *search_name,...);
    char*  (*get_str_from_search_item)(CWebHyDrationBridge *self,int index, const char *search_name,...);

}CWebHydrationContentNamespace;
#endif
