
#include "../uniq.definitions_requirements.h"
#include <cstdlib>


void CWebHyDrationBridge_add_required_function(CWebHyDrationBridge *self,const char *function,...){
    va_list  args;
    va_start(args,function);
    char *result = private_CWebHydration_format_vaarg(function,args);
    va_end(args);
    CwebStringArray_add_getting_ownership(self->entries_callbacks, result);
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
    return  self;
}


CTextStack *private_CWebHyDrationBridge_create_script(CWebHyDrationBridge *self) {

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

char *CWebHyDrationBridge_call(CWebHyDrationBridge *self,char *func_args,...) {

    CTextStack *callback= newCTextStack_string_empty();


    if(func_args == NULL) {
        CTextStack_format(callback,"private_cweb_bridges['%s']([]);",self->name);
        CwebStringArray_add(self->calls,callback->rendered_text);
        CTextStack_free(callback);
        return self->calls->strings[self->calls->size-1];
    }

    va_list  args;
    va_start(args,func_args);
    char *result = private_CWebHydration_format_vaarg(func_args,args);
    va_end(args);
    CTextStack_format(
        callback,
        "private_cweb_bridges['%s']([%sc]);",
        self->name,
        result);
    CwebStringArray_add(self->calls,callback->rendered_text);
    CTextStack_free(callback);
    return self->calls->strings[self->calls->size-1];

}
void private_CWebHyDrationBridge_free(CWebHyDrationBridge *self) {
free(self->name);
    CwebStringArray_free(self->entries_callbacks);
    CwebStringArray_free(self->calls);
    free(self);
}
