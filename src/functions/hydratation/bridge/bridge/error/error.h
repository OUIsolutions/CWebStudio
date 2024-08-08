
#include "../uniq.declaration_requirements.h"

bool CWebHyDration_error(CWebHyDrationBridge *self);

const char * CWebHyDration_get_error_menssage(CWebHyDrationBridge *self);

const char * CWebHyDration_get_error_key(CWebHyDrationBridge *self);

int CWebHyDration_get_error_code(CWebHyDrationBridge *self);

CwebHttpResponse * CWebHyDration_generate_error_response(CWebHyDrationBridge *self);