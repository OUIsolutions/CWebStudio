
#include "../uniq.declaration_requirements.h"


CWebHyDrationBridge *private_newCWebHyDrationBridge(
    const char *name,
    void (*callback)(CWebHyDrationBridge *),

    CWebHyDration *hydration
);

bool CWebHyDrationBridge_has_errors(CWebHyDrationBridge *self);

char *CWebHyDrationBridge_call(CWebHyDrationBridge *self,const char *func_args,...);

CTextStack *private_CWebHyDrationBridge_create_script(CWebHyDrationBridge *self);

void private_CWebHyDrationBridge_free(CWebHyDrationBridge *self);
