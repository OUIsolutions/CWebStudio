
#include "../uniq.definitions_requirements.h"

int privateCWebHyDration_read_json(CWebHyDrationBridge *self) {
     if(self->error != NULL){
          return -1;
     }
     if(self->body) {
          return 0;
     }
     self->body = CWebHttpRequest_read_cJSON(self->request,self->max_body_size);

     if(self->body == NULL) {
          self->error_type = CWEB_HYDRATION_NOT_BODY_JSON_PROVIDED;
          self->error = strdup(CWEB_HYDRATION_NOT_BODY_JSON_PROVIDED_MSG);
          return -1;
     }
     return 0;
}

#define privateCWebHydration_read(check_type,expected_type,retriver_value,error_return)\
if(privateCWebHyDration_read_json(self)) {\
     return error_return;\
}\
va_list  args;\
va_start(args,name);\
char *name_formmated = private_CWebHydration_format_vaarg(name,args);\
va_end(args);\
cJSON *element = cJSON_GetObjectItem(self->body,name_formmated);\
if(element == NULL) {\
     self->error_type = CWEB_HYDRATION_NOT_BODY_JSON_PROVIDED;\
     self->error = private_CWebHydration_format(CWEB_HYDRATION_KEY_NOT_PROVIDED_MSG,name_formmated);\
     self->error_key = strdup(name_formmated);\
     free(name_formmated);\
     return error_return;\
}\
\
if(!check_type(element)) {\
     self->error_type = CWEB_HYDRATION_KEY_WRONG_TYPE;\
     self->error = private_CWebHydration_format(CWEB_HYDRATION_KEY_NOT_TYPE,expected_type);\
     self->error_key = strdup(name_formmated);\
     free(name_formmated);\
     return error_return;\
}\
free(name_formmated);\
return retriver_value(element);

const char * CWebHyDration_read_string(CWebHyDrationBridge *self,const char *name,...) {
     privateCWebHydration_read(cJSON_IsString,CWEB_HYDRATION_STRING,cJSON_GetStringValue,NULL)
}



long CWebHyDration_read_long(CWebHyDrationBridge *self,const char *name,...) {
    privateCWebHydration_read(cJSON_IsNumber,CWEB_HYDRATION_NUMBER,(long)cJSON_GetNumberValue,-1)
}

double CWebHyDration_read_double(CWebHyDrationBridge *self,const char *name,...) {
     privateCWebHydration_read(cJSON_IsNumber,CWEB_HYDRATION_NUMBER,cJSON_GetNumberValue,-1)
}


bool  CWebHyDration_read_bool(CWebHyDrationBridge *self,const char *name,...) {
     privateCWebHydration_read(cJSON_IsNumber,CWEB_HYDRATION_NUMBER,(bool)cJSON_GetNumberValue,false)

}

bool  CWebHyDration_exist(CWebHyDrationBridge *self,const char *name,...) {
     if(privateCWebHyDration_read_json(self)) {
          return false;
     }
     va_list  args;
     va_start(args,name);
     char *name_formmated = private_CWebHydration_format_vaarg(name,args);
     va_end(args);
     cJSON *element = cJSON_GetObjectItem(self->body,name_formmated);
     if(element == NULL) {
          free(name_formmated);
          return false;
     }
     free(name_formmated);
     return true;
}

