
#include "../../hydration/all.h"
#include "../response.h"

#ifndef PRIVATE_CWEB_HYDRATATION_RESPONSE_NAMESPACE_TYPES
#define PRIVATE_CWEB_HYDRATATION_RESPONSE_NAMESPACE_TYPES


typedef struct CWebHydrationResponseNamespace {
    void (*replace_element_by_query_selector)(
        CWebHyDrationBridge *self,
        const char *query_selector,
        const char *code,
        ...
    );

    void (*append_by_query_selector)(
        CWebHyDrationBridge *self,
        const char *query_selector,
        const char *code,
        ...
    );


    void (*destroy_by_query_selector)(
        CWebHyDrationBridge *self,
        const char * query_selecor
    );



    void (*hide_element_by_query_selector)(
    CWebHyDrationBridge *self,
    const char *query_selecor);

    void (*unhide_element_by_query_selector)(
        CWebHyDrationBridge *self,
        const char *query_selector
    );
    void (*hide_element_by_id)(CWebHyDrationBridge *self,const char *id);
    void (*unhide_element_by_id)(CWebHyDrationBridge *self,const char *id);
    void (*append_by_id)(CWebHyDrationBridge *self,const char *id, const char *code,...);

    void (*set_session_storage_data)(CWebHyDrationBridge *self,const char*key, const char *value,...);
    void (*alert)(CWebHyDrationBridge *self,const char *menssage,...);
    void (*execute_script)(CWebHyDrationBridge *self,const char *code,...);
    void (*replace_element_by_id)(CWebHyDrationBridge *self,const char *id, const char *code,...);
    void (*destroy_by_id)(CWebHyDrationBridge *self,const char * id);
    void (*redirect)(CWebHyDrationBridge *self, const char *url);
    void (*add_cookie_with_time)(CWebHyDrationBridge *self, const char *key, long time, const char *value, ...);
    void (*add_cookie)(CWebHyDrationBridge *self, const char *key, const char *value, ...);
    void (*delet_cookie)(CWebHyDrationBridge *self, const char *key);
    void (*console_log)(CWebHyDrationBridge *self,const char *menssage,...);
    void (*console_warn)(CWebHyDrationBridge *self,const char *menssage,...);
    void (*console_error)(CWebHyDrationBridge *self,const char *menssage,...);
    void (*console_clear)(CWebHyDrationBridge *self);


}CWebHydrationActionsNamespace;

#endif
