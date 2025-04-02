

void privateCWebHyDrationBridge_add_response(CWebHyDrationBridge *self,const char *name,cJSON *data){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }

    CWebHyDration *hydraation = (CWebHyDration*)self->hydration;
    cJSON *current_response = cJSON_CreateObject();
    cJSON_AddStringToObject(current_response,CWEB_HYDRATON_JSON_NAME,name);
    cJSON_AddItemToObject(current_response,CWEB_HYDRATON_JSON_DATA,data);
    cJSON_AddItemToArray(hydraation->response,current_response);
}

void CWebHyDrationBridge_set_session_storage_data(

    CWebHyDrationBridge *self,const char*key, const char *value,...){
        if(CWebHyDrationBridge_has_errors(self)){
            return ;
        }
        cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args,value);
    char *value_formmat = private_CWeb_format_vaarg(value,args);
    va_end(args);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_KEY, key);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_VALUE,value_formmat);
    free(value_formmat);
    privateCWebHyDrationBridge_add_response(self,"set_session_storage",obj);
}

void CWebHyDrationBridge_remove_session_storage_data(CWebHyDrationBridge *self,const char*key){
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_KEY, key);
    privateCWebHyDrationBridge_add_response(self,"remove_session_storage_data",obj);
}


void CWebHyDrationBridge_alert(CWebHyDrationBridge *self,const char *menssage,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args,menssage);
    char *msg_format = private_CWeb_format_vaarg(menssage,args);
    va_end(args);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_MSG, msg_format);
    free(msg_format);
    privateCWebHyDrationBridge_add_response(self,"alert",obj);

}

void CWebHydrationBridge_creatCookie_with_time(CWebHyDrationBridge *self, const char *key, long time, const char *value, ...){

    if(CWebHyDrationBridge_has_errors(self)){
        return;
    }
    cJSON *obj = cJSON_CreateObject();

    va_list args;
    va_start(args, value);
    char *value_formated = private_CWeb_format_vaarg(value, args);
    va_end(args);
    cJSON_AddStringToObject(obj, "name", key);
    cJSON_AddStringToObject(obj, "value", value_formated);
    cJSON_AddNumberToObject(obj, "days", time);
    free(value_formated);
    privateCWebHyDrationBridge_add_response(self, "add_cookie_with_time", obj);
}

void CWebHydrationBridge_creatCookie(CWebHyDrationBridge *self, const char *key, const char *value, ...){

    if(CWebHyDrationBridge_has_errors(self)){
        return;
    }
    cJSON *obj = cJSON_CreateObject();

    va_list args;
    va_start(args, value);
    char *value_formated = private_CWeb_format_vaarg(value, args);
    va_end(args);
    cJSON_AddStringToObject(obj, "name", key);
    cJSON_AddStringToObject(obj, "value", value_formated);
    free(value_formated);
    privateCWebHyDrationBridge_add_response(self, "add_cookie", obj);
}

void CWebHyDrationBridge_deletCookie(CWebHyDrationBridge *self, const char *key){
    if(CWebHyDrationBridge_has_errors(self)){
        return;
    }
    cJSON *obj = cJSON_CreateObject();

    cJSON_AddStringToObject(obj, "name", key);
    privateCWebHyDrationBridge_add_response(self, "delet_cookie", obj);
}

void CWebHyDrationBridge_execute_script(CWebHyDrationBridge *self,const char *code,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args,code);
    char *code_format = private_CWeb_format_vaarg(code,args);
    va_end(args);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_CODE, code_format);
    free(code_format);
    privateCWebHyDrationBridge_add_response(self,"execute_script",obj);
}

void CWebHyDrationBridge_replace_element_by_query_selector(
    CWebHyDrationBridge *self,
    const char *query_selector,
    const char *code,
    ...
){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args,code);
    char *html_format = private_CWeb_format_vaarg(code,args);
    va_end(args);

    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_QUERY_SELECTOR, query_selector);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_HTML, html_format);
    free(html_format);
    privateCWebHyDrationBridge_add_response(self,"replace_element_by_query_selector",obj);
}


void CWebHyDrationBridge_append_by_query_selector(
    CWebHyDrationBridge *self,
    const char *query_selector,
    const char *code,
    ...
){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args,code);
    char *html_format = private_CWeb_format_vaarg(code,args);
    va_end(args);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_QUERY_SELECTOR, query_selector);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_HTML, html_format);
    free(html_format);
    privateCWebHyDrationBridge_add_response(self,"append_by_query_selector",obj);
}



void CWebHyDrationBridge_destroy_by_query_selector(
    CWebHyDrationBridge *self,
    const char * query_selecor
){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_QUERY_SELECTOR, query_selecor);
    privateCWebHyDrationBridge_add_response(self,"destroy_by_query_selector",obj);
}


void CWebHyDrationBridge_hide_element_by_query_selector(
CWebHyDrationBridge *self,
const char *query_selecor){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_QUERY_SELECTOR, query_selecor);
    privateCWebHyDrationBridge_add_response(self,"hide_element_by_query_selector",obj);
}

void CWebHyDrationBridge_unhide_element_by_query_selector(
    CWebHyDrationBridge *self,
    const char *query_selector
){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_QUERY_SELECTOR, query_selector);
    privateCWebHyDrationBridge_add_response(self,"unhide_element_by_id",obj);
}




void CWebHyDrationBridge_replace_element_by_id(CWebHyDrationBridge *self,const char *id, const char *code,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args,code);
    char *html_format = private_CWeb_format_vaarg(code,args);
    va_end(args);
    char *formatted_query_selecor = private_CWeb_format("[id='%s']",id);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_QUERY_SELECTOR, formatted_query_selecor);
    free(formatted_query_selecor);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_HTML, html_format);
    free(html_format);
    privateCWebHyDrationBridge_add_response(self,"replace_element_by_query_selector",obj);
}

void CWebHyDrationBridge_append_by_id(CWebHyDrationBridge *self,const char *id, const char *code,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args,code);
    char *html_format = private_CWeb_format_vaarg(code,args);
    va_end(args);
    char *formatted_query_selecor = private_CWeb_format("[id='%s']",id);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_QUERY_SELECTOR, formatted_query_selecor);
    free(formatted_query_selecor);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_HTML, html_format);
    free(html_format);
    privateCWebHyDrationBridge_add_response(self,"append_by_query_selector",obj);
}


void CWebHyDrationBridge_hide_element_by_id(CWebHyDrationBridge *self,const char *id){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();

    char *formatted_query_selecor = private_CWeb_format("[id='%s']",id);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_QUERY_SELECTOR, formatted_query_selecor);
    free(formatted_query_selecor);

    privateCWebHyDrationBridge_add_response(self,"hide_element_by_query_selector",obj);
}

void CWebHyDrationBridge_unhide_element_by_id(CWebHyDrationBridge *self,const char *id){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();

    char *formatted_query_selecor = private_CWeb_format("[id='%s']",id);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_QUERY_SELECTOR, formatted_query_selecor);
    free(formatted_query_selecor);

    privateCWebHyDrationBridge_add_response(self,"unhide_element_by_query_selector",obj);
}


void CWebHyDrationBridge_destroy_by_id(CWebHyDrationBridge *self,const char * id){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();

    char *formatted_query_selecor = private_CWeb_format("[id='%s']",id);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_QUERY_SELECTOR, formatted_query_selecor);
    free(formatted_query_selecor);

    privateCWebHyDrationBridge_add_response(self,"destroy_by_query_selector",obj);
}

void CWebHydration_redirect(CWebHyDrationBridge *self, const char *url){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj, CWEB_HYDRATION_JSON_URL, url);
    privateCWebHyDrationBridge_add_response(self,"redirect",obj);
}

void CWebHyDration_console_log(CWebHyDrationBridge *self, const char *menssage, ...){

    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args, menssage);
    char *menssage_formated = private_CWeb_format_vaarg(menssage, args);
    va_end(args);

    cJSON_AddStringToObject(obj, "message", menssage_formated);
    privateCWebHyDrationBridge_add_response(self, "log", obj);
}
void CWebHyDration_console_warn(CWebHyDrationBridge *self, const char *menssage, ...){

    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args, menssage);
    char *menssage_formated = private_CWeb_format_vaarg(menssage, args);
    va_end(args);

    cJSON_AddStringToObject(obj, "message", menssage_formated);
    privateCWebHyDrationBridge_add_response(self, "warn", obj);
    free(menssage_formated);
}
void CWebHyDration_console_error(CWebHyDrationBridge *self, const char *menssage, ...){

    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args, menssage);
    char *menssage_formated = private_CWeb_format_vaarg(menssage, args);
    va_end(args);

    cJSON_AddStringToObject(obj, "message", menssage_formated);
    privateCWebHyDrationBridge_add_response(self, "error", obj);
    free(menssage_formated);
}
void CWebHyDration_console_clear(CWebHyDrationBridge *self){

    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    privateCWebHyDrationBridge_add_response(self, "clear", obj);
}

void CWebHyDrationBridge_remove_class_by_id(CWebHyDrationBridge *self, const char *id, const char *class_name, ...){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args, class_name);
    char *menssage_formated = private_CWeb_format_vaarg(class_name, args);
    va_end(args);

    cJSON_AddStringToObject(obj, "class_name", menssage_formated);
    cJSON_AddStringToObject(obj, "id", id);
    privateCWebHyDrationBridge_add_response(self, "remove_class_by_id", obj);
    free(menssage_formated);
}

void CWebHyDrationBridge_add_class_by_id(CWebHyDrationBridge *self, const char *id, const char *class_name, ...){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args, class_name);
    char *menssage_formated = private_CWeb_format_vaarg(class_name, args);
    va_end(args);

    cJSON_AddStringToObject(obj, "class_name", menssage_formated);
    cJSON_AddStringToObject(obj, "id", id);
    privateCWebHyDrationBridge_add_response(self, "add_class_by_id", obj);
    free(menssage_formated);
}

void CWebHyDrationBridge_remove_class_by_query_selector(CWebHyDrationBridge *self, const char *element, const char *class_name, ...){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args, class_name);
    char *menssage_formated = private_CWeb_format_vaarg(class_name, args);
    va_end(args);

    cJSON_AddStringToObject(obj, "class_name", menssage_formated);
    cJSON_AddStringToObject(obj, "query_selector", element);
    privateCWebHyDrationBridge_add_response(self, "remove_class_by_id", obj);
    free(menssage_formated);
}

void CWebHyDrationBridge_add_class_by_query_selector(CWebHyDrationBridge *self, const char *element, const char *class_name, ...){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args, class_name);
    char *menssage_formated = private_CWeb_format_vaarg(class_name, args);
    va_end(args);

    cJSON_AddStringToObject(obj, "class_name", menssage_formated);
    cJSON_AddStringToObject(obj, "query_selector", element);
    privateCWebHyDrationBridge_add_response(self, "add_class_by_id", obj);
    free(menssage_formated);
}
