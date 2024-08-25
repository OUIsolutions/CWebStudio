
#include "../uniq.definitions_requirements.h"

char *privateCWebHyDrationBridge_call_by_vaargss(CWebHyDrationBridge *self,const char *func_args,va_list  args){
    if(CWebHyDrationBridge_has_errors(self)){
        return NULL;
    }

    CTextStack *callback= CWebHyDrationBridge_create_empty_stack(self);

    CWebHyDration *hydration = (CWebHyDration*)self->hydration;
    int name_index = private_cweb_add_stack_item(hydration,self->name);


    if(func_args == NULL) {
            CTextStack_format(
                callback,
                "private_cweb_bridges[%d]([]);",
                name_index
            );
            return callback->rendered_text;
    }

    char *formmated_func_args = private_CWeb_format_vaarg(func_args,args);
    char *formmated_func_array = private_CWeb_format("[%s]",formmated_func_args);
    free(formmated_func_args);

    int args_index = private_cweb_add_stack_item_getting_ownership(hydration,formmated_func_array);


    CTextStack_format(
        callback,
        "private_cweb_bridges[%d](%d);",
        name_index,
        args_index
    );

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
