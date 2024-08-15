
#include "../uniq.definitions_requirements.h"

void CWebHyDrationBridge_add_required_function(CWebHyDrationBridge *self,const char *function,...){
    va_list  args;
    va_start(args,function);
    char *result = private_CWebHydration_format_vaarg(function,args);
    va_end(args);
    CwebStringArray_add_getting_ownership(self->entries_callbacks, result);
}

void CWebHyDrationBridge_get_element_by_id(CWebHyDrationBridge *self, const char * id){

}
