
#include "../uniq.definitions_requirements.h"

void CWebHyDrationBridge_add_required_function(CWebHyDrationBridge *self,const char *function,...){
    va_list  args;
    va_start(args,function);
    char *result = private_CWeb_format_vaarg(function,args);
    va_end(args);
    CwebStringArray_add_getting_ownership(self->entries_callbacks, result);
}

void private_CWebHyDrationBridge_add_required_elements_by_query_selector(
    CWebHyDrationBridge *self,
    const char *key_name,
    const char *query_selector,
    bool convert_to_number
){

    const char *convert_to_number_str = "false";
    if(convert_to_number){
        convert_to_number = "true";
    }
    CWebHyDrationBridge_add_required_function(self,
        "function (args,content){\
            private_cweb_get_elements_and_set_to_content({\
            content:content,\
            query_selector:`%s`,\
            key_name:`%s`,\
            convert_to_number:%s\
            })\
        }",
        key_name,
        query_selector,
        convert_to_number
    );
}

void CWebHyDrationBridge_add_required_elements_by_query_selector(
    CWebHyDrationBridge *self,
    const char *key_name,
    const char *query_selector
){
    private_CWebHyDrationBridge_add_required_elements_by_query_selector(
        self,
        key_name,
        query_selector,
        false
    );
}
