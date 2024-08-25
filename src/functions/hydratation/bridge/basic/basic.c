
#include "../uniq.definitions_requirements.h"



CWebHyDrationBridge * CWebHyDrationBridge_get_brother_bridge(CWebHyDrationBridge *self,const char *name){
    CWebHyDration *hydration = (CWebHyDration *)self->hydration;
    return CWebHyDration_get_child_bridge(hydration,name);
}

CWebHyDrationBridge *private_newCWebHyDrationBridge(
    const char *name,
    void (*callback)(CWebHyDrationBridge *),CWebHyDration *hydration
) {
    CWebHyDrationBridge *self = (CWebHyDrationBridge*)malloc(sizeof(CWebHyDrationBridge));
    *self = (CWebHyDrationBridge){0};
    self->name = strdup(name);
    self->callback = callback;
    self->hydration = (void*)hydration;
    self->requirements_code =newCwebStringArray();
    return  self;
}



CTextStack * CWebHyDrationBridge_create_stack(CWebHyDrationBridge *self){
    return CWebHyDration_create_stack((CWebHyDration*)self->hydration);
}

CTextStack * CWebHyDrationBridge_create_empty_stack(CWebHyDrationBridge *self){
    return CWebHyDration_create_empty_stack((CWebHyDration*)self->hydration);
}

CWebHyDrationSearchRequirements * CWebHyDrationBridge_newSearchRequirements(
    CWebHyDrationBridge *self, const char *name,...)
{
    va_list  args;
    va_start(args,name);
    char *formmated_name = private_CWeb_format_vaarg(name,args);
    va_end(args);

    CWebHyDrationSearchRequirements *created_search =
    private_newCWebHyDrationSearchRequirements_getting_name_ownership(
        self,
        formmated_name
    );

    CWebHyDration *hydration =(CWebHyDration*)self->hydration;
    UniversalGarbage *garbage = hydration->request->garbage;

   UniversalGarbage_add(
       garbage,
        private_CWebHyDrationSearchRequirements_free,
        created_search
    );
    return created_search;
}

void CWebHyDrationBridge_add_element_by_id_setting_search_as_same_name(
    CWebHyDrationBridge *self, const char *id
){
    CWebHyDrationSearchRequirements * search =
    CWebHyDrationBridge_newSearchRequirements(self,id);
    CWebHyDrationSearchRequirements_add_elements_by_id(search, id);

}

void CWebHyDrationBridge_add_element_by_id_setting_search_as_same_name_not_format(
    CWebHyDrationBridge *self, const char *id
){
    CWebHyDrationSearchRequirements * search =
    CWebHyDrationBridge_newSearchRequirements(self,id);
    CWebHyDrationSearchRequirements_add_elements_by_id_not_auto_converting(search, id);
}


CTextStack*  private_CWebHyDrationBridge_create_script(CWebHyDrationBridge *self) {

    CTextStack *function = newCTextStack_string_empty();

    CTextStack_format(
        function,
        "private_cweb_bridges['%s'] = async function (args){ \n",
        self->name
    );

    CTextStack_format(function,"\tlet content = {}\n");

    for(int i= 0; i < self->requirements_code->size;i++) {
        CTextStack_format(
            function,
            "%s\n",
            self->requirements_code->strings[i]
        );
    }

    CTextStack_format(
        function,
        "\tawait private_cweb_send_to_server('%s',args,content)\n",
        self->name
    );
    CTextStack_format(function,"};\n");

    return function;
}
bool CWebHyDrationBridge_has_errors(CWebHyDrationBridge *self){
    if(self == NULL){
        return  true;
    }
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;
    if(hydration->error_code == 0){
        return false;
    }
    return true;
}



void private_CWebHyDrationBridge_free(CWebHyDrationBridge *self) {
free(self->name);
    CwebStringArray_free(self->requirements_code);
    free(self);
}
