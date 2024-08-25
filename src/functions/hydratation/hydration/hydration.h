
#include "../uniq.declaration_requirements.h"

CWebHyDration * newCWebHyDration(CwebHttpRequest *request);

CWebHyDrationBridge * CWebHyDration_create_bridge(CWebHyDration *self,const char *name,void (*callback)(CWebHyDrationBridge *));


CTextStack  * CWebHyDration_create_stack(CWebHyDration *self);

CTextStack  * CWebHyDration_create_empty_stack(CWebHyDration *self);


CWebHyDrationBridge * CWebHyDration_get_child_bridge(CWebHyDration *self,const char *name);


void privateCWebHydration_raise_error(CWebHyDration *self,CWebHyDrationBridge *bridge, int error_code, const char *format,...);

CwebHttpResponse *private_CWebHydration_formmat_error_response(CWebHyDration *self);


bool CWebHyDration_is_the_trigger(CWebHyDration *self);

CwebHttpResponse *CWebHydration_generate_response(CWebHyDration *self);

char *CWebHyDration_create_script(CWebHyDration *self);

void private_CWebHyDration_free(CWebHyDration *self);
