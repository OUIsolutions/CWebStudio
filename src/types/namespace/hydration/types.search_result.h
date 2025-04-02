//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.macros.h"
//silver_chain_scope_end


typedef struct CWebHydrationSearchResultNamespace {

    int  (*get_total_avaialible_searchs)(CWebHyDrationBridge *self);
    CWebHyDrationSearchResult * (*get_search_by_index)(CWebHyDrationBridge *self,int index);
    CWebHyDrationSearchResult * (*get_search_by_name)(CWebHyDrationBridge *self,const char *name,...);
    bool (*search_exist)(CWebHyDrationBridge *self,const char *name,...);
    double (*get_double_from_first_element_of_search)(CWebHyDrationBridge *self,const char *name,...);
    long (*get_long_from_first_element_of_search)(CWebHyDrationBridge *self,const char *name,...);
    bool (*get_bool_from_first_element_of_search)(CWebHyDrationBridge *self,const char *name,...);
    char* (*get_string_from_first_element_of_search)(CWebHyDrationBridge *self,const char *name,...);
    cJSON* (*get_cJSON_from_first_element_of_search)(CWebHyDrationBridge *self,const char *name,...);
    int  (*get_total_itens)(CWebHyDrationSearchResult *self);
    bool  (*search_item_exist)(CWebHyDrationSearchResult *self,int index);
    bool  (*is_search_item_number)(CWebHyDrationSearchResult *self,int index);
    bool  (*is_search_item_bool)(CWebHyDrationSearchResult *self,int index);
    bool  (*is_search_item_string)(CWebHyDrationSearchResult *self,int index);
    double (*get_double)(CWebHyDrationSearchResult *self,int  index);
    long (*get_long)(CWebHyDrationSearchResult *self,int  index);
    bool (*get_bool)(CWebHyDrationSearchResult *self,int  index);
    char*  (*get_string)(CWebHyDrationSearchResult *self,int  index);
    cJSON *  (*get_cJSON)(CWebHyDrationSearchResult *self,int  index);

}CWebHydrationSearchResultNamespace;
