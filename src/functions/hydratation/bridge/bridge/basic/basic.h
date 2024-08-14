
#include "../uniq.declaration_requirements.h"


CWebHyDrationBridge *private_newCWebHyDrationBridge(const char *name,void (*callback)(CWebHyDrationBridge *), CwebHttpRequest *request);

bool CWebHyDrationBridge_is_the_route(CWebHyDrationBridge *self);

char *CWebHyDrationBridge_call(CWebHyDrationBridge *self,char *func_args,...);

CTextStack *private_CWebHyDrationBridge_create_script(CWebHyDrationBridge *self);

void private_CWebHyDrationBridge_free(CWebHyDrationBridge *self);
