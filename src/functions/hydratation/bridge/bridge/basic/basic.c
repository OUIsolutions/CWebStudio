
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

char *CWebHyDrationBridge_call(CWebHyDrationBridge *self,const char *trigger,const char *func_args,...){
    CTextStack *callback= newCTextStack_string_empty();
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;

    if(func_args == NULL) {
        CTextStack_format(callback,"%s = 'private_cweb_bridges[\"%s\"]([]);'",trigger,self->name);
        CwebStringArray_add(self->calls,callback->rendered_text);
        CTextStack_free(callback);
        return self->calls->strings[self->calls->size-1];
    }

    va_list  args;
    va_start(args,func_args);
    char *result = private_CWeb_format_vaarg(func_args,args);
    va_end(args);
    CTextStack_format(
        callback,
       "%s = 'private_cweb_bridges[\"%s\"]([%sc]);'",
        trigger,
        self->name,
        result);
    CTextStack_self_replace(callback, "\'","'");

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
