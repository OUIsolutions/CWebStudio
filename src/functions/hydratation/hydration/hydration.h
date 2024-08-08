
#include "../uniq.declaration_requirements.h"

CWebHyDration * newCWebHyDration(CwebHttpRequest *request);

CWebHyDrationBridge * CWebHyDration_create_bridge(CWebHyDration *self,const char *route,char *name);

char *CWebHyDration_create_script(CWebHyDration *self);

void CWebHyDration_free(CWebHyDration *self);
