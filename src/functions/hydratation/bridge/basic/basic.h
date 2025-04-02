


CWebHyDrationBridge *private_newCWebHyDrationBridge(
    const char *name,
    void (*callback)(CWebHyDrationBridge *),

    CWebHyDration *hydration
);



CWebHyDrationBridge * CWebHyDrationBridge_get_brother_bridge(CWebHyDrationBridge *self,const char *name);

bool CWebHyDrationBridge_has_errors(CWebHyDrationBridge *self);

CTextStack * CWebHyDrationBridge_create_stack(CWebHyDrationBridge *self);

CTextStack * CWebHyDrationBridge_create_empty_stack(CWebHyDrationBridge *self);

CWebHyDrationSearchRequirements * CWebHyDrationBridge_newSearchRequirements(CWebHyDrationBridge *self, const char *name,...);


char *CWebHyDrationBridge_call(CWebHyDrationBridge *self,const char *func_args,...);



CTextStack* private_CWebHyDrationBridge_create_script(CWebHyDrationBridge *self);


void private_CWebHyDrationBridge_free(CWebHyDrationBridge *self);
