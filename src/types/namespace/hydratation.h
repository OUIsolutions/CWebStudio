
#include "../hydratation.h"
#include "../response.h"

#ifndef PRIVATE_CWEB_HYDRATATION_HYDRATATION_NAMESPACE_TYPES
#define PRIVATE_CWEB_HYDRATATION_HYDRATATION_NAMESPACE_TYPES

typedef struct CWebHydrationNamespace{

    CWebHyDration *(*newHyDration)(CwebHttpRequest *request);
    //base
    CWebHyDrationBridge *(*create_bridge)(CWebHyDration *self,const char *route,char *name);
    char *(*create_script)(CWebHyDration *self);
    void (*free)(CWebHyDration *self);
    //bridge
    //basic
    bool(*is_the_route)(CWebHyDrationBridge *self);
    char *(*call)(CWebHyDrationBridge *self,char *func_args,...);

    //entries
    void (*add_function)(CWebHyDrationBridge *self,const char *function,const char *format, ...);
    void (*add_input_by_id)(CWebHyDrationBridge *self,const char *id);
    void (*add_input_checkbox_by_id)(CWebHyDrationBridge *self, const char *id);
    void (*request_text_content_by_id)(CWebHyDrationBridge *self, const char *id);
    void (*request_number_text_content_by_id)(CWebHyDrationBridge *self, const char *id);
    void (*add_input_by_all_id)(CWebHyDrationBridge *self, const char *id);
    void (*add_input_checkbox_by_all_id)(CWebHyDrationBridge *self, const char *id);
    void (*request_text_content_by_all_id)(CWebHyDrationBridge *self, const char *id);
    //read
    const char *(*read_string)(CWebHyDrationBridge *self,const char *name,...);
    long (*read_long)(CWebHyDrationBridge *self,const char *name,...);
    double (*read_double)(CWebHyDrationBridge *self,const char *name,...);
    bool (*read_bool)(CWebHyDrationBridge *self,const char *name,...);
    bool (*exist)(CWebHyDrationBridge *self,const char *name,...);
    //response
    void (*add_response_callback)(CWebHyDrationBridge *self,const char *callback,cJSON *args);
    void (*alert)(CWebHyDrationBridge *self,const char *msg,...);
    void (*destroy_by_id)(CWebHyDrationBridge *self,const char *id);
    void (*replace_element_by_id_with_ctext_stack_cleaning_memory)(CWebHyDrationBridge *self,const char *id,CTextStack *stack);
    CwebHttpResponse * (*generate_response)(CWebHyDrationBridge *self);


    bool (*error)(CWebHyDrationBridge *self);
    const char * (*get_error_menssage)(CWebHyDrationBridge *self);
    const char * (*get_error_key)(CWebHyDrationBridge *self);
    int (*get_error_code)(CWebHyDrationBridge *self);
    CwebHttpResponse * (*generate_error_response)(CWebHyDrationBridge *self);

}CWebHydrationNamespace;

#endif //PRIVATE_CWEB_HYDRATATION_HYDRATATION_NAMESPACE_TYPES