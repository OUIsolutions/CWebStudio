

#include "../uniq.declaration_requirements.h"

char *privateCWebHyDrationBridge_call_by_vaargss(CWebHyDrationBridge *self,const char *func_args,va_list  args);


char *CWebHyDrationBridge_call(CWebHyDrationBridge *self,const char *func_args,...);

char *privateCWebHyDrationBridge_call_trigger_by_vaarg(
    CWebHyDrationBridge *self,
    const char *trigger,
    const char *func_args,
    va_list  args
);


char *CWebHyDrationBridge_call_trigger(
    CWebHyDrationBridge *self,
    const char *trigger,
    const char *func_args,
    ...
);


char *CWebHyDrationBridge_onclick(CWebHyDrationBridge *self,const char *func_args,...);

char *CWebHyDrationBridge_onfoccusout(CWebHyDrationBridge *self,const char *func_args,...);
