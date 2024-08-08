
#include "../uniq.declaration_requirements.h"

void privateCWebHyDration_create_main_response(CWebHyDrationBridge *self);

void CWebHyDration_add_response_callback(CWebHyDrationBridge *self,const char *callback,cJSON *args);

void CWebHyDration_alert(CWebHyDrationBridge *self,const char *msg,...);

void CWebHyDration_destroy_by_id(CWebHyDrationBridge *self,const char *id);

void CWebHyDration_replace_element_by_id_with_ctext_stack_cleaning_memory(CWebHyDrationBridge *self,const char *id,CTextStack *stack);

CwebHttpResponse * CWebHyDration_generate_response(CWebHyDrationBridge *self);
