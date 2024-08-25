

#include "../uniq.definitions_requirements.h"

int  CWebHyDrationBridge_get_total_avaialible_searchs(CWebHyDrationBridge *self){
    if(CWebHyDrationBridge_has_errors(self)){
        return 0;
    }
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;
    return cJSON_GetArraySize(hydration->content);
}


CWebHyDrationSearchResult * CWebHyDrationBridge_get_search_by_index(CWebHyDrationBridge *self,int index){

    if(CWebHyDrationBridge_has_errors(self)){
        return NULL;
    }
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
    UniversalGarbage *garbage = hydration->request->garbage;

    UniversalGarbage_add(garbage,privateCWebHyDrationSearchResult_free,result);
    return result;
}

CWebHyDrationSearchResult * CWebHyDrationBridge_get_search_by_name(CWebHyDrationBridge *self,const char *name,...){

    if(CWebHyDrationBridge_has_errors(self)){
        return NULL;
    }
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

    CWebHyDrationSearchResult *result = private_newCWebHyDrationSearchResult(self, search);
    UniversalGarbage *garbage = hydration->request->garbage;
    UniversalGarbage_add(garbage,privateCWebHyDrationSearchResult_free,result);
    return result;
}

bool CWebHyDrationBridge_search_exist(CWebHyDrationBridge *self,const char *name,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return false;
    }
    va_list  args;
        va_start(args,name);
        char *formmated_name = private_CWeb_format_vaarg(name,args);
        va_end(args);

        CWebHyDration *hydration = (CWebHyDration*)self->hydration;
        cJSON *search = cJSON_GetObjectItem(hydration->content,formmated_name);
        free(formmated_name);
        return search != NULL;
}

double CWebHyDrationBridge_get_double_from_first_element_of_search(CWebHyDrationBridge *self,const char *name,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return -1;
    }
    va_list  args;
    va_start(args,name);
    char *formmated_name = private_CWeb_format_vaarg(name,args);
    va_end(args);
    CWebHyDrationSearchResult *search = CWebHyDrationBridge_get_search_by_name(self,"%s",formmated_name);
    free(formmated_name);
    if(search == NULL){
        return  -1;
    }
    return CWebHyDrationSearchResult_get_double(search,0);
}

long CWebHyDrationBridge_get_long_from_first_element_of_search(CWebHyDrationBridge *self,const char *name,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return -1;
    }
    va_list  args;
    va_start(args,name);
    char *formmated_name = private_CWeb_format_vaarg(name,args);
    va_end(args);
    CWebHyDrationSearchResult *search = CWebHyDrationBridge_get_search_by_name(self,"%s",formmated_name);
    free(formmated_name);
    if(search == NULL){
        return  -1;
    }
    return CWebHyDrationSearchResult_get_long(search,0);
}


bool CWebHyDrationBridge_get_bool_from_first_element_of_search(CWebHyDrationBridge *self,const char *name,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return false;
    }
    va_list  args;
    va_start(args,name);
    char *formmated_name = private_CWeb_format_vaarg(name,args);
    va_end(args);
    CWebHyDrationSearchResult *search = CWebHyDrationBridge_get_search_by_name(self,"%s",formmated_name);
    free(formmated_name);
    if(search == NULL){
        return  false;
    }
    return CWebHyDrationSearchResult_get_bool(search,0);
}


char* CWebHyDrationBridge_get_string_from_first_element_of_search(CWebHyDrationBridge *self,const char *name,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return NULL;
    }
    va_list  args;
    va_start(args,name);
    char *formmated_name = private_CWeb_format_vaarg(name,args);
    va_end(args);
    CWebHyDrationSearchResult *search = CWebHyDrationBridge_get_search_by_name(self,"%s",formmated_name);
    free(formmated_name);
    if(search == NULL){
        return  NULL;
    }
    return CWebHyDrationSearchResult_get_string(search,0);
}

cJSON* CWebHyDrationBridge_get_cJSON_from_first_element_of_search(CWebHyDrationBridge *self,const char *name,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return NULL;
    }
    va_list  args;
    va_start(args,name);
    char *formmated_name = private_CWeb_format_vaarg(name,args);
    va_end(args);
    CWebHyDrationSearchResult *search = CWebHyDrationBridge_get_search_by_name(self,"%s",formmated_name);
    free(formmated_name);
    if(search == NULL){
        return  NULL;
    }
    return CWebHyDrationSearchResult_get_cJSON(search,0);
}
