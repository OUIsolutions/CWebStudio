//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../../imports/imports.globals.h"
//silver_chain_scope_end

CWebHydrationSearchResultNamespace newCWebHydrationSearchResultNamespace(){
    CWebHydrationSearchResultNamespace self = {0};
    self.get_total_avaialible_searchs = CWebHyDrationBridge_get_total_avaialible_searchs;
    self.get_search_by_index = CWebHyDrationBridge_get_search_by_index;
    self.get_search_by_name =  CWebHyDrationBridge_get_search_by_name;
    self.search_exist = CWebHyDrationBridge_search_exist;
    self.get_double_from_first_element_of_search = CWebHyDrationBridge_get_double_from_first_element_of_search;
    self.get_long_from_first_element_of_search = CWebHyDrationBridge_get_long_from_first_element_of_search;
    self.get_bool_from_first_element_of_search = CWebHyDrationBridge_get_bool_from_first_element_of_search;
    self.get_string_from_first_element_of_search = CWebHyDrationBridge_get_string_from_first_element_of_search;
    self.get_cJSON_from_first_element_of_search = CWebHyDrationBridge_get_cJSON_from_first_element_of_search;
    self.get_total_itens = CWebHyDrationSearchResult_get_total_itens;
    self.search_item_exist = CWebHyDrationSearchResult_search_item_exist;
    self.is_search_item_number = CWebHyDrationSearchResult_is_search_item_number;
    self.is_search_item_bool =  CWebHyDrationSearchResult_is_search_item_bool;
    self.is_search_item_string = CWebHyDrationSearchResult_is_search_item_string;
    self.get_double = CWebHyDrationSearchResult_get_double;
    self.get_long = CWebHyDrationSearchResult_get_long;
    self.get_bool = CWebHyDrationSearchResult_get_bool;
    self.get_string = CWebHyDrationSearchResult_get_string;
    self.get_cJSON = CWebHyDrationSearchResult_get_cJSON;

    return self;
}
