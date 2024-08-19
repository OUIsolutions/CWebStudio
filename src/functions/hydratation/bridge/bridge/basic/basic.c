
#include "../uniq.definitions_requirements.h"




CWebHyDrationBridge *private_newCWebHyDrationBridge(
    const char *name,
    void (*callback)(CWebHyDrationBridge *),CWebHyDration *hydration
) {

    CWebHyDrationBridge *self = (CWebHyDrationBridge*)malloc(sizeof(CWebHyDrationBridge));
    *self = (CWebHyDrationBridge){0};
    self->name = strdup(name);
    self->callback = callback;
    self->hydration = (void*)hydration;
    self->entries_callbacks =newCwebStringArray();
    self->calls = newCwebStringArray();
    return  self;
}


CTextStack*  private_CWebHyDrationBridge_create_script(CWebHyDrationBridge *self) {

    CTextStack *function = newCTextStack_string_empty();

    CTextStack_format(
        function,
        "private_cweb_bridges['%s'] = async function (args){ \n",
        self->name
    );

    CTextStack_format(function,"\tlet content = {}\n");

    for(int i= 0; i < self->entries_callbacks->size;i++) {
        CTextStack_format(
            function,
            "\tprivate_cweb_handle_required_data(%s, args, content);\n",
            self->entries_callbacks->strings[i]
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
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;
    if(hydration->error_code == 0){
        return false;
    }
    return true;
}



void private_CWebHyDrationBridge_free(CWebHyDrationBridge *self) {
free(self->name);
    CwebStringArray_free(self->entries_callbacks);
    CwebStringArray_free(self->calls);
    free(self);
}
