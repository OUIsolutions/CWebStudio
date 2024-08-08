
#include "../uniq.definitions_requirements.h"

void CWebHyDration_add_function(CWebHyDrationBridge *self,const char *function,const char *format, ...) {

    if(format == NULL) {
        CTextStack *code = newCTextStack_string_format("%s(body);",function);
        CwebStringArray_add(self->callbacks,code->rendered_text);
        CTextStack_free(code);
        return;
    }

    va_list  args;
    va_start(args,format);
    char *result = private_CWebHydration_format_vaarg(format,args);
    va_end(args);
    CTextStack *code = newCTextStack_string_format("%s(body,args,%s);",function,result);
    CwebStringArray_add(self->callbacks,code->rendered_text);
    CTextStack_free(code);
    free(result);
}

void CWebHyDration_add_input_by_id(CWebHyDrationBridge *self, const char *id) {

    CWebHyDration_add_function(self, PRIVATE_CWEB_HYDRATION_GET_INPUT_BY_ID, "'%s'", id);
}

void CWebHyDration_add_input_checkbox_by_id(CWebHyDrationBridge *self, const char *id){

    CWebHyDration_add_function(self, PRIVATE_CWEB_HYDRATION_GET_INPUT_CHECBOX_BY_ID ,"'%s'", id);
}

void CWebHyDration_request_text_content_by_id(CWebHyDrationBridge *self, const char *id){

    CWebHyDration_add_function(self, PRIVATE_CWEB_HYDRATION_GET_TEXT_CONTENT_BY_ID ,"'%s'", id);
}
void CWebHyDration_request_number_text_content_by_id(CWebHyDrationBridge *self, const char *id) {
    CWebHyDration_add_function(self, PRIVATE_CWEB_HYDRATION_GET_NUMBER_TEXT_CONTENT_BY_ID ,"'%s'", id);

}
void CWebHyDration_add_input_by_all_id(CWebHyDrationBridge *self, const char *id) {

    CWebHyDration_add_function(self, PRIVATE_CWEB_HYDRATION_GET_INPUT_BY_ALL_ID, "'%s'", id);
}

void CWebHyDration_add_input_checkbox_by_all_id(CWebHyDrationBridge *self, const char *id){

    CWebHyDration_add_function(self, PRIVATE_CWEB_HYDRATION_GET_INPUT_CHECKBOX_BY_ALL_ID, "'%s'", id);
}

void CWebHyDration_request_text_content_by_all_id(CWebHyDrationBridge *self, const char *id){

    CWebHyDration_add_function(self, PRIVATE_CWEB_HYDRATION_GET_TEXT_CONTENT_BY_ALL_ID ,"'%s'", id);
}
