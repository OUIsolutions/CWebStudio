
#include "../uniq.definitions_requirements.h"


char *CWebHyDrationBridge_call(CWebHyDrationBridge *self,const char *func_args,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return NULL;
    }

    CTextStack *callback= newCTextStack_string_empty();
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;

    if(func_args != NULL){
        va_list  args;
        va_start(args,func_args);
        char *formmated_func_args = private_CWeb_format_vaarg(func_args,args);
        va_end(args);
        CTextStack_format(
            callback,
           "private_cweb_bridges['%s']([%s]);",
            self->name,
            formmated_func_args
        );
        free(formmated_func_args);
    }

    if(func_args == NULL) {
        CTextStack_format(
            callback,
            "private_cweb_bridges[`%s`]([]);",
            self->name
        );
    }
    UniversalGarbage *garbage = hydration->request->garbage;

    UniversalGarbage_add(garbage,CTextStack_free, callback);
    return callback->rendered_text;

}


char *private_CWebHyDrationBridge_call_trigger(
    CWebHyDrationBridge *self,
    const char *trigger,
    const char *func_args
){
    if(CWebHyDrationBridge_has_errors(self)){
        return NULL;
    }


    CTextStack *callback= newCTextStack_string_empty();
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;

    CTextStack_format(
        callback,
        "%s = private_cweb_bridges['%s']([%s]);",
        trigger,
        self->name,
        func_args
    );
    UniversalGarbage *garbage = hydration->request->garbage;
    UniversalGarbage_add(garbage,CTextStack_free, callback);
    return callback->rendered_text;
}

char *CWebHyDrationBridge_onclick(CWebHyDrationBridge *self,const char *func_args,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return NULL;
    }

    if(func_args==NULL){
        return private_CWebHyDrationBridge_call_trigger(self,"onclick","");
    }

    va_list  args;
    va_start(args,func_args);
    char *formmated_func_args = private_CWeb_format_vaarg(func_args,args);
    va_end(args);

    char *result = private_CWebHyDrationBridge_call_trigger(self,"onclick",formmated_func_args);
    free(formmated_func_args);
    return result;
}


char *CWebHyDrationBridge_onfoccusout(CWebHyDrationBridge *self,const char *func_args,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return NULL;
    }

    if(func_args==NULL){
        return private_CWebHyDrationBridge_call_trigger(self,"onfocusout","");
    }

    va_list  args;
    va_start(args,func_args);
    char *formmated_func_args = private_CWeb_format_vaarg(func_args,args);
    va_end(args);

    char *result = private_CWebHyDrationBridge_call_trigger(self,"onfocusout",formmated_func_args);
    free(formmated_func_args);
    return result;
}
