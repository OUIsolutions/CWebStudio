
#include "../uniq.definitions_requirements.h"

void CWebHyDrationBridge_add_required_function(CWebHyDrationBridge *self,const char *function,...){
    va_list  args;
    va_start(args,function);
    char *result = private_CWeb_format_vaarg(function,args);
    va_end(args);
    CwebStringArray_add_getting_ownership(self->entries_callbacks, result);
}


void CWebHyDrationBridge_add_required_by_id(CWebHyDrationBridge *self, const char * id){

    CWebHyDrationBridge_add_required_function(self,
        "private_cweb_entrie_clojure_constructors.get_text_by_id('%s')",
        id
    );
}

void CWebHyDrationBridge_add_required_number_by_id(CWebHyDrationBridge *self, const char * id){

    CWebHyDrationBridge_add_required_function(self,
            "private_cweb_entrie_clojure_constructors.get_text_number_by_id('%s')",
            id
        );
}


void CWebHyDrationBridge_add_required_input_by_id(CWebHyDrationBridge *self, const char * id){
    CWebHyDrationBridge_add_required_function(self,
            "private_cweb_entrie_clojure_constructors.get_input_by_id('%s')",
            id
        );
}

void CWebHyDrationBridge_add_required_input_number_by_id(CWebHyDrationBridge *self, const char * id){
    CWebHyDrationBridge_add_required_function(self,
            "private_cweb_entrie_clojure_constructors.get_input_number_by_id('%s')",
            id
        );
}
