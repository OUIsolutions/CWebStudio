
#include "../uniq.definitions_requirements.h"

CWebHyDration *newCWebHyDration(CwebHttpRequest *request) {
    CWebHyDration *self = (CWebHyDration*)malloc(sizeof(CWebHyDration));
    *self = (CWebHyDration){0};
    self->all_bridges = private_new_privateCWebHyDrationBridgeArray();
    self->request =  request;
    request->hydratation = (void *)self;
    return self;
}

CWebHyDrationBridge * CWebHyDration_create_bridge(CWebHyDration *self,const char *name,void (*callback)(CWebHyDrationBridge *)){
    CWebHyDrationBridge *created = private_newCWebHyDrationBridge(name,callback);
    privateCWebHyDrationBridgeArray_append(self->all_bridges,created);
    return created;
}

char *CWebHyDration_create_script(CWebHyDration *self) {

    if(self->script_text) {
        CTextStack_free(self->script_text);
    }

    self->script_text = newCTextStack_string_empty();
    CTextStack_format(self->script_text,"%s", private_cweb_hydration_js_content);

    for(int i =0; i < self->all_bridges->size;i++) {
        CWebHyDrationBridge *current = self->all_bridges->elments[i];
        CTextStack *created_code =private_CWebHyDrationBridge_create_script(current);
        CTextStack_format(self->script_text,"%tc",created_code);
    }
    return self->script_text->rendered_text;

}

void private_CWebHyDration_free(CWebHyDration *self) {
    if(self->script_text) {
        CTextStack_free(self->script_text);
    }
    privateCWebHyDrationBridgeArray_free(self->all_bridges);
    free(self);
}
