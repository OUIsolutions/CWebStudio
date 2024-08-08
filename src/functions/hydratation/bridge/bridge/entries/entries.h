
#include "../uniq.declaration_requirements.h"

void CWebHyDration_add_function(CWebHyDrationBridge *self,const char *function,const char *format, ...);

void CWebHyDration_add_input_by_id(CWebHyDrationBridge *self,const char *id);

void CWebHyDration_add_input_checkbox_by_id(CWebHyDrationBridge *self, const char *id);

void CWebHyDration_request_text_content_by_id(CWebHyDrationBridge *self, const char *id);

void CWebHyDration_request_number_text_content_by_id(CWebHyDrationBridge *self, const char *id);

void CWebHyDration_add_input_by_all_id(CWebHyDrationBridge *self, const char *id);

void CWebHyDration_add_input_checkbox_by_all_id(CWebHyDrationBridge *self, const char *id);

void CWebHyDration_request_text_content_by_all_id(CWebHyDrationBridge *self, const char *id);