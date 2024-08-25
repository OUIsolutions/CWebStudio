
#include "../uniq.declaration_requirements.h"

void privateCWebHyDrationBridge_add_response(CWebHyDrationBridge *self,const char *name,cJSON *data);

void CWebHyDrationBridge_set_session_storage_data(CWebHyDrationBridge *self,const char*key, const char *value,...);

void CWebHyDrationBridge_alert(CWebHyDrationBridge *self,const char *menssage,...);

void CWebHyDrationBridge_execute_script(CWebHyDrationBridge *self,const char *code,...);

void CWebHyDrationBridge_replace_element_by_query_selector(
    CWebHyDrationBridge *self,
    const char *query_selector,
    const char *code,
    ...
);


void CWebHyDrationBridge_append_by_query_selector(
    CWebHyDrationBridge *self,
    const char *query_selector,
    const char *code,
    ...
);




void CWebHyDrationBridge_destroy_by_query_selector(
    CWebHyDrationBridge *self,
    const char * query_selecor
);



void CWebHyDrationBridge_hide_element_by_query_selector(
CWebHyDrationBridge *self,
const char *query_selecor);


void CWebHyDrationBridge_unhide_element_by_query_selector(
    CWebHyDrationBridge *self,
    const char *query_selector
);



void CWebHyDrationBridge_replace_element_by_id(CWebHyDrationBridge *self,const char *id, const char *code,...);


void CWebHyDrationBridge_append_by_id(CWebHyDrationBridge *self,const char *id, const char *code,...);


void CWebHyDrationBridge_hide_element_by_id(CWebHyDrationBridge *self,const char *id);


void CWebHyDrationBridge_unhide_element_by_id(CWebHyDrationBridge *self,const char *id);


void CWebHyDrationBridge_destroy_by_id(CWebHyDrationBridge *self,const char * id);


void CWebHydration_redirect(CWebHyDrationBridge *self, const char *url);

void CWebHydrationBridge_creatCookie(CWebHyDrationBridge *self, const char *key, const char *value, ...);

void CWebHydrationBridge_creatCookie_with_time(CWebHyDrationBridge *self, const char *key, long time, const char *value, ...);

void CWebHyDrationBridge_deletCookie(CWebHyDrationBridge *self, const char *key);

void CWebHyDration_console_log(CWebHyDrationBridge *self, const char *menssage, ...);
void CWebHyDration_console_warn(CWebHyDrationBridge *self, const char *menssage, ...);
void CWebHyDration_console_error(CWebHyDrationBridge *self, const char *menssage, ...);
void CWebHyDration_console_clear(CWebHyDrationBridge *self);

void CWebHyDrationBridge_remove_class_by_id(CWebHyDrationBridge *self, const char *id, const char *class_name, ...);
void CWebHyDrationBridge_add_class_by_id(CWebHyDrationBridge *self, const char *id, const char *class_name, ...);
void CWebHyDrationBridge_remove_class_by_query_selector(CWebHyDrationBridge *self, const char *element, const char *class_name, ...);
void CWebHyDrationBridge_add_class_by_query_selector(CWebHyDrationBridge *self, const char *element, const char *class_name, ...);




