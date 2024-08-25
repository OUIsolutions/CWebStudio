
#include "../uniq.definitions_requirements.h"

char *privateCWebHyDrationBridge_call_by_vaargss(CWebHyDrationBridge *self,const char *func_args,va_list  args){
    if(CWebHyDrationBridge_has_errors(self)){
        return NULL;
    }

    CTextStack *callback= CWebHyDrationBridge_create_empty_stack(self);

    CWebHyDration *hydration = (CWebHyDration*)self->hydration;

    if(func_args == NULL) {
            CTextStack_format(
                callback,
                "private_cweb_bridges['%s']([]);",
                self->name            );
            return callback->rendered_text;
    }

    char *formmated_func_args = private_CWeb_format_vaarg(func_args,args);



    CTextStack_format(
        callback,
        "private_cweb_bridges[`%s`]([%s]);",
        self->name,
        formmated_func_args
    );
    free(formmated_func_args);
    return callback->rendered_text;
}

char *CWebHyDrationBridge_call(CWebHyDrationBridge *self,const char *func_args,...){

    va_list  args;
    va_start(args,func_args);
    char *result =privateCWebHyDrationBridge_call_by_vaargss(self,func_args,args);
    va_end(args);
    return result;

}
char *privateCWebHyDrationBridge_call_trigger_by_vaarg(
    CWebHyDrationBridge *self,
    const char *trigger,
    const char *func_args,
    va_list  args
){

    char *result =privateCWebHyDrationBridge_call_by_vaargss(self,func_args,args);

    if(!result){
        return NULL;
    }

    CTextStack * complete = CWebHyDrationBridge_create_empty_stack(self);
    CTextStack_format(complete, "%s = '%s'", trigger,result);
    return complete->rendered_text;
}



char *CWebHyDrationBridge_call_trigger(
    CWebHyDrationBridge *self,
    const char *trigger,
    const char *func_args,
    ...
){
    va_list  args;
    va_start(args,func_args);
    char *result =privateCWebHyDrationBridge_call_trigger_by_vaarg(self,trigger,func_args,args);
    va_end(args);
    return result;
}


char *CWebHyDrationBridge_onclick(CWebHyDrationBridge *self,const char *func_args,...){
    va_list  args;
    va_start(args,func_args);
    char *result =privateCWebHyDrationBridge_call_trigger_by_vaarg(self,"onclick",func_args,args);
    va_end(args);
    return result;
}


char *CWebHyDrationBridge_onfoccusout(CWebHyDrationBridge *self,const char *func_args,...){
    va_list  args;
    va_start(args,func_args);
    char *result =privateCWebHyDrationBridge_call_trigger_by_vaarg(self,"onfocusout",func_args,args);
    va_end(args);
    return result;

}
