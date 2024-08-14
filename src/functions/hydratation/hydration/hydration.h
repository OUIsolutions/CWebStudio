
#include "../uniq.declaration_requirements.h"

CWebHyDration * newCWebHyDration(CwebHttpRequest *request);

CWebHyDrationBridge * CWebHyDration_create_bridge(CWebHyDration *self,const char *name,void (*callback)(CWebHyDrationBridge *));

void privateCWebHydration_raise_error(CWebHyDration *self,CWebHyDrationBridge *bridge, int error_code, const char *format,...);

bool CWebHyDration_is_the_trigger(CWebHyDration *self);

CwebHttpResponse *CWebHydration_generate_response(CWebHyDration *self);

char *CWebHyDration_create_script(CWebHyDration *self);

void private_CWebHyDration_free(CWebHyDration *self);
