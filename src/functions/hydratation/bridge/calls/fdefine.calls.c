

char *privateCWebHyDrationBridge_call_by_vaargss(CWebHyDrationBridge *self,const char *func_args,va_list  args){
    if(CWebHyDrationBridge_has_errors(self)){
        return NULL;
    }

    CTextStack *callback= CWebHyDrationBridge_create_empty_stack(self);
    UniversalGarbage *garbage = newUniversalGarbage();

    CTextStack *name_assci = private_cweb_create_assci_code(self->name);
    UniversalGarbage_add(garbage, CTextStack_free, name_assci);


    if(func_args == NULL) {
            CTextStack_format(
                callback,
                "private_cweb_call_bridge_with_assic(%t,[]);",
                name_assci);
            UniversalGarbage_free(garbage);
            return callback->rendered_text;
    }

    char *formmated_func_args = private_CWeb_format_vaarg(func_args,args);
    UniversalGarbage_add_simple(garbage, formmated_func_args);
    CTextStack * args_assci = private_cweb_create_assci_code(formmated_func_args);
    UniversalGarbage_add(garbage, CTextStack_free, args_assci);


    CTextStack_format(
        callback,
        "private_cweb_call_bridge_with_assic(%t,%t);",
        name_assci,
        args_assci
    );

    UniversalGarbage_free(garbage);

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
