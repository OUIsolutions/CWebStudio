
#include "../uniq.definitions_requirements.h"

CWebHyDrationBridge *private_newCWebHyDrationBridge(
    const char *name,
    const char *route,
    CwebHttpRequest *request) {
    CWebHyDrationBridge *self = (CWebHyDrationBridge*)malloc(sizeof(CWebHyDrationBridge));
    *self = (CWebHyDrationBridge){0};
    if(name) {
        self->name = strdup(name);
    }
    self->route = strdup(route);
    self->request = request;
	self->callbacks = newCwebStringArray();
    self->garbage = newCwebStringArray();
    self->max_body_size = CWEB_HYDRATION_DEFAULT_BODY_SIZE;
    return  self;
}

bool   CWebHyDrationBridge_is_the_route(CWebHyDrationBridge *self) {
    return strcmp(self->route,self->request->route) == 0;
}

CTextStack *private_CWebHyDrationBridge_create_script(CWebHyDrationBridge *self) {
    CTextStack *function = newCTextStack_string_empty();
    CTextStack_format(function,"\nasync function ");
    if(self->name) {
        CTextStack_format(function,"%s",self->name);
    }
    else {
        CTextStack *formatted_name = newCTextStack_string(self->route);
        CTextStack_self_replace(formatted_name,"/","");
        CTextStack_format(function,"%tc(args)",formatted_name);
    }
    CTextStack_format(function,"{\n");
    CTextStack_format(function,"\tlet body = {}\n");
    CTextStack_format(function,"\t%s(body,args);\n",PRIVATE_CWEB_REPLACE_ARGS_IN_BODY);

    for(int i= 0; i < self->callbacks->size;i++) {
        CTextStack_format(function,"\t%s\n",self->callbacks->strings[i]);
    }

    CTextStack_format(function,"\tawait private_cweb_send_to_server('%s',body)\n",self->route);
    CTextStack_format(function,"};\n");
    return function;
}

char *CWebHyDrationBridge_call(CWebHyDrationBridge *self,char *func_args,...) {

    CTextStack *callback= newCTextStack_string_empty();

    if(self->name) {
        CTextStack_format(callback,"%s",self->name);
    }
    else {
        CTextStack *formatted_name = newCTextStack_string(self->route);
        CTextStack_self_replace(formatted_name,"/","");
        CTextStack_format(callback,"%tc",formatted_name);
    }

    if(func_args == NULL) {
        CTextStack_format(callback,"([]);");
        CwebStringArray_add(self->garbage,callback->rendered_text);
        CTextStack_free(callback);
        return self->garbage->strings[self->garbage->size-1];
    }

    va_list  args;
    va_start(args,func_args);
    char *result = private_CWebHydration_format_vaarg(func_args,args);
    va_end(args);
    CTextStack_format(callback,"([%sc]);",result);
    CwebStringArray_add(self->garbage,callback->rendered_text);
    CTextStack_free(callback);
    return self->garbage->strings[self->garbage->size-1];

}
void private_CWebHyDrationBridge_free(CWebHyDrationBridge *self) {
    free(self->route);
    if(self->name) {
        free(self->name);
    }

    if(self->error) {
        free(self->error);
    }
    if(self->error_key) {
        free(self->error_key);
    }

    if(self->response) {
        cJSON_Delete(self->response);
    }
    CwebStringArray_free(self->callbacks);
    CwebStringArray_free(self->garbage);
    free(self);
}
