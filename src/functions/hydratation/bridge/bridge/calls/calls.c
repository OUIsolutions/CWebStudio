
#include "../uniq.definitions_requirements.h"



char *CWebHyDrationBridge_call(CWebHyDrationBridge *self,const char *func_args,...){

    CTextStack *callback= newCTextStack_string_empty();
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;

    if(func_args != NULL){
        va_list  args;
        va_start(args,func_args);
        char *formmated_func_args = private_CWeb_format_vaarg(func_args,args);
        va_end(args);
        CTextStack_format(
            callback,
           "private_cweb_bridges[`%s`]([%sc]);",
            self->name,
            formmated_func_args
        );
    }

    if(func_args == NULL) {
        CTextStack_format(
            callback,
            "private_cweb_bridges[`%s`]([]);",
            self->name
        );
    }

    char *stack_str = CTextStack_self_transform_in_string_and_self_clear(callback);
    CwebStringArray_add_getting_ownership(hydration->garbage,stack_str);
    return stack_str;

}


char *private_CWebHyDrationBridge_call_trigger(CWebHyDrationBridge *self,const char *trigger,const char *func_args){


    CTextStack *callback= newCTextStack_string_empty();
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;

    CTextStack_format(
        callback,
        "%s = 'private_cweb_bridges[`%s`]([%s])';",
        self->name,
        func_args
    );
    char *stack_str = CTextStack_self_transform_in_string_and_self_clear(callback);
    CwebStringArray_add_getting_ownership(hydration->garbage,stack_str);
    return stack_str;
}

char *private_CWebHyDrationBridge_onclick(CWebHyDrationBridge *self,const char *func_args,...){
    va_list  args;
    va_start(args,func_args);
    char *formmated_func_args = private_CWeb_format_vaarg(func_args,args);
    va_end(args);

    char *result = private_CWebHyDrationBridge_call_trigger(self,"onclick",func_args);
    free(formmated_func_args);
    return result;
}


char *private_CWebHyDrationBridge_onfoccusout(CWebHyDrationBridge *self,const char *func_args,...){
    va_list  args;
    va_start(args,func_args);
    char *formmated_func_args = private_CWeb_format_vaarg(func_args,args);
    va_end(args);

    char *result = private_CWebHyDrationBridge_call_trigger(self,"onfocusout",func_args);
    free(formmated_func_args);
    return result;
}
