
#include "../uniq.declaration_requirements.h"

CWebHyDration * newCWebHyDration(CwebHttpRequest *request);


CWebHyDrationBridge * CWebHyDration_create_bridge(CWebHyDration *self,void (*callback)(CWebHyDrationBridge *),const char *name);


char *CWebHyDration_create_script(CWebHyDration *self);

void private_CWebHyDration_free(CWebHyDration *self);
