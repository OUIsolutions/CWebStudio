/* MIT License

Copyright (c) 2023 Mateus Moutinho Queiroz

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */ 

#ifndef CWebStudio_macros
#define CWebStudio_macros

#define CWEB_HYDRATION_DEFAULT_BODY_SIZE 5000
#define CWEB_HYDRATION_CALBACK_HANDLER_ROUTE "/private_cweb_hydration_main_callback_handler"


#define PRIVATE_CWEB_HYDRATION_CALLBACK_KEY "callback"
#define PRIVATE_CWEB_HYDRATION_ARGS_KEY "args"
#define PRIVATE_CWEB_HYDRATION_ID_KEY "id"
#define PRIVATE_CWEB_HYDRATION_HTML_KEY "html"
#define PRIVATE_CWEB_HYDRATION_MENSSAGE_KEY "menssage"


#define PRIVATE_CWEB_HYDRATION_ALERT "private_cweb_alert"
#define PRIVATE_CWEB_HYDRATION_DESTROY_BY_ID "private_cweb_destroy_by_id"
#define PRIVATE_CWEB_HYDRATION_REPLACE_BY_ID "private_cweb_hydration_replace_by_id"


#define CWEB_HYDRATION_NOT_BODY_JSON_PROVIDED 1
#define CWEB_HYDRATION_NOT_BODY_JSON_PROVIDED_MSG "json body not provided"

#define CWEB_HYDRATION_NOT_BODY_IS_NOT_OBJECT 2
#define CWEB_HYDRATION_NOT_BODY_IS_NOT_OBJECT_MSG  "json body not not object"


#define CWEB_HYDRATION_NAME_NOT_PROVIDED 3
#define CWEB_HYDRATION_NAME_NOT_PROVIDED_MSG  "body['name'] not provided"

#define CWEB_HYDRATION_NAME_NOT_STRING 4
#define CWEB_HYDRATION_NAME_NOT_STRING_MSG  "body['name'] its not string"


#define CWEB_HYDRATION_ARGS_NOT_PROVIDED 5
#define CWEB_HYDRATION_ARGS_NOT_PROVIDED_MSG  "body['args'] not provided"

#define CWEB_HYDRATION_ARGS_NOT_ARRAY 6
#define CWEB_HYDRATION_ARGS_NOT_ARRAY_MSG  "body['args'] its not array"


#define CWEB_HYDRATION_CONTENT_NOT_PROVIDED 7
#define CWEB_HYDRATION_CONTENT_NOT_PROVIDED_MSG  "body['content'] not provided"

#define CWEB_HYDRATION_CONTENT_NOT_OBJECT 8
#define CWEB_HYDRATION_CONTENT_NOT_OBJECT_MSG  "body['content'] not a object"


#define CWEB_HYDRATION_CONTENT_KEY_NOT_PROVIDED 9
#define CWEB_HYDRATION_CONTENT_KEY_NOT_PROVIDED_MSG  "body['content']['%s'] not provided at content"

#define CWEB_HYDRATION_CONTENT_SEARCH_NOT_ARRAY 10
#define CWEB_HYDRATION_CONTENT_SEARCH_NOT_ARRAY_MSG "body['content']['%s']   is not of array"



#define CWEB_HYDRATION_CONTENT_SEARCH_NOT_EXIST 11
#define CWEB_HYDRATION_CONTENT_SEARCH_NOT_EXIST_MSG "search at index %d  not exist"


#define CWEB_HYDRATION_SEARCH_ITEM_NOT_EXIST 12
#define CWEB_HYDRATION_SEARCH_ITEM_NOT_EXIST_MSG "body['content']['%s'][%d] not exist"


#define CWEB_HYDRATION_SEARCH_ITEM_WRONG_TYPE 13
#define CWEB_HYDRATION_SEARCH_ITEM_WRONG_TYPE_MSG "body['content']['%s'][%d] its not of type %s"


#define CWEB_HYDRATION_INDEX_ARGS_NOT_PROVIDED  14
#define CWEB_HYDRATION_INDEX_ARGS_NOT_PROVIDED_MSG  "body['args'][%d]  not provided"

#define CWEB_HYDRATION_INDEX_ARGS_WRONG_TYPE 15
#define CWEB_HYDRATION_INDEX_ARGS_WRONG_TYPE_MSG  "body['args'][%d] is not of type %s"



#define CWEB_BRIDGE_NOT_FOUND 16
#define CWEB_BRIDGE_NOT_FOUND_MSG  "bridge of name %s not found"

#define CWEB_SEARCH_NOT_EXIST 17
#define CWEB_SEARCH_NOT_EXIST_MSG "search at index %d not exist"

#define CWEB_HYDRATION_STRING "string"
#define CWEB_HYDRATION_BOOL  "bool"
#define CWEB_HYDRATION_NUMBER "number"





#define CWEB_HYDRATION_JSON_ERROR_CODE_KEY "error_code"
#define CWEB_HYDRATION_JSON_ERROR_MENSSAGE "error_menssage"
#define CWEB_HYDRATON_JSON_DATA "data"

#define CWEB_HYDRATON_JSON_NAME "name"
#define CWEB_HYDRATON_JSON_HTML "html"
#define CWEB_HYDRATON_JSON_MSG "msg"
#define CWEB_HYDRATON_JSON_CODE "code"
#define CWEB_HYDRATON_JSON_KEY "key"
#define CWEB_HYDRATON_JSON_QUERY_SELECTOR "query_selector"

#define CWEB_HYDRATON_JSON_VALUE "value"
#define CWEB_HYDRATION_JSON_URL "url"

#define CWEB_HYDRATON_JSON_ARGS "args"
#define CWEB_HYDRATON_JSON_CONTENT "content"


#define INVALID_HTTP -1
#define MAX_HEADER_SIZE_CODE -2
#define MAX_HEADER_LEN 20000
#define MAX_LINE_LEN MAX_HEADER_LEN /2
#define READ_ERROR -3
#define MAX_CONTENT_SIZE -4
#define UNDEFINED_CONTENT -5
#define INVALID_JSON -6
#define CWEB_UTF_DECREMENTER  64
#define CWEB_C_NON_ASSCI_SIGIN -61



#define CWEB_AUTO_SET_CONTENT NULL
#define CWEB_OK  200
#define CWEB_NOT_FOUND 404
#define CWEB_BAD_REQUEST 400
#define CWEB_FORBIDDEN 403
#define CWEB_INTERNAL_SERVER_ERROR 500


#ifdef CWEB_DEBUG
#define cweb_print(...) printf(__VA_ARGS__);
#else
#define cweb_print(...);
#endif




#endif

#ifndef CWebStudio_types
#define CWebStudio_types


typedef struct CwebKeyVal{
    char *key;
     char *value;

}CwebKeyVal;




typedef struct {
    char  *file;
    char *included;

}privateCwebRecursionElement;




typedef struct CwebStringArray {
  int size;         

  char **strings;       

}CwebStringArray; // End the structure with a semicolon


#endif

#ifndef CWebStudio_typesB
#define CWebStudio_typesB


typedef struct CwebDict {
  int size;
  CwebKeyVal **keys_vals;

}CwebDict;





typedef struct  CWebHyDrationBridge {
    char *name;
    void  *hydration;
    void  (*callback)(struct CWebHyDrationBridge *bridge);

    CwebStringArray *requirements_code;

    void *extra_args;

}CWebHyDrationBridge;





typedef struct{

    privateCwebRecursionElement **elements;
    int size;

}privateCwebRecursionList;

#endif

#ifndef CWebStudio_typesC
#define CWebStudio_typesC


typedef struct privateCWebHyDrationBridgeArray {
    CWebHyDrationBridge **elments;
    int size;

}privateCWebHyDrationBridgeArray;




typedef  struct{
    char *name;
    CWebHyDrationBridge *bridge;
} CWebHyDrationSearchRequirements;



typedef struct{
    CWebHyDrationBridge *bridge;
    cJSON *search;
    const char *name;
} CWebHyDrationSearchResult;




typedef struct CwebHttpRequest{

    char *url;
    int socket;
    char *route;
    char *method;
    char *client_ip;
    int content_error;
    CwebDict *params;
    CwebDict *headers;
    int content_length;
    unsigned char *content;
    cJSON *json;
    void *hydratation;
    void *extra_args;
    UniversalGarbage *garbage;

}CwebHttpRequest;




typedef struct CwebHttpResponse{
    int status_code;
    struct CwebDict *headers;
    int content_length;
    bool exist_content;
    unsigned char *content;

}CwebHttpResponse;


#endif

#ifndef CWebStudio_typesD
#define CWebStudio_typesD


typedef struct CWebHyDration {
    CwebHttpRequest *request;
   const  char *error_bridge_name;
    char *error_msg;
    cJSON *response;
    cJSON *args;
    cJSON *content;

    int error_code;
   // CwebStringArray *stack_elements;
    CTextStack *script_text;
    long max_content_size;
    privateCWebHyDrationBridgeArray *all_bridges;

}CWebHyDration;




 typedef struct CwebServer{
    int port;
    int function_timeout;
    double client_timeout;
    int max_queue;

    #if defined(__linux__)
        bool single_process;
    #endif

    long max_requests;
    bool allow_cors;
    bool use_static;
    const char *static_folder;
    bool use_cache;

    //methods
    CwebHttpResponse *(*request_handler)(CwebHttpRequest *request);

}CwebServer;


#endif

#ifndef CWebStudio_typesG
#define CWebStudio_typesG


typedef struct CwebKeyValModule{
    void (*represent)(CwebKeyVal *key_val);
    void (*free)(CwebKeyVal *key_val);
}CwebKeyValModule;





typedef struct CWebHydrationResponseNamespace {
    void (*replace_element_by_query_selector)(
        CWebHyDrationBridge *self,
        const char *query_selector,
        const char *code,
        ...
    );
    void (*remove_session_storage_data)(CWebHyDrationBridge *self,const char*key);

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
    void (*add_class_by_query_selector)(CWebHyDrationBridge *self, const char *element, const char *class_name, ...);
    void (*remove_class_by_query_selector)(CWebHyDrationBridge *self, const char *element, const char *class_name, ...);
    void (*remove_class_by_id)(CWebHyDrationBridge *self, const char *id, const char *class_name, ...);
    void (*add_class_by_id)(CWebHyDrationBridge *self, const char *id, const char *class_name, ...);



}CWebHydrationActionsNamespace;




typedef struct CWebHydrationArgsNamespace {

    bool   (*is_arg_null)(CWebHyDrationBridge *self,int index);
    int   (*get_args_size)(CWebHyDrationBridge *self);
    bool   (*is_arg_number)(CWebHyDrationBridge *self,int index);
    bool   (*is_arg_bool)(CWebHyDrationBridge *self,int index);
    bool   (*is_arg_string)(CWebHyDrationBridge *self,int index);
    double  (*get_double_arg)(CWebHyDrationBridge *self,int index);
    long  (*get_long_arg)(CWebHyDrationBridge *self,int index);
    bool  (*get_bool_arg)(CWebHyDrationBridge *self,int index);
    char* (*get_str_arg)(CWebHyDrationBridge *self,int index);
    cJSON * (*get_cJSON_arg)(CWebHyDrationBridge *self,int index);

}CWebHydrationArgsNamespace;



typedef struct CWebHydrationBridgeNamespace{

    CWebHyDrationBridge * (*create_bridge)(CWebHyDration *self,const char *name,void (*callback)(CWebHyDrationBridge *));
    char *(*call_trigger)(
        CWebHyDrationBridge *self,
        const char *trigger,
        const char *func_args,
        ...
    );

    char *(*call)(CWebHyDrationBridge *self,const char *func_args,...);
    char *(*onclick)(CWebHyDrationBridge *self,const char *func_args,...);
    char *(*onfoccusout)(CWebHyDrationBridge *self,const char *func_args,...);

    CTextStack * (*create_stack)(CWebHyDrationBridge *self);
    CTextStack * (*create_empty_stack)(CWebHyDrationBridge *self);

    bool (*has_errors)(CWebHyDrationBridge *self);
    CWebHyDrationBridge * (*get_child_bridge)(CWebHyDration *self,const char *name);
    CWebHyDrationBridge * (*get_brother_bridge)(CWebHyDrationBridge *self,const char *name);

}CWebHydrationBridgeNamespace;





typedef struct CWebHydrationSearchRequirementsNamespace {




    CWebHyDrationSearchRequirements * (*newSearchRequirements)(CWebHyDrationBridge *self, const char *name,...);

    void (*add_function)(CWebHyDrationSearchRequirements *self,const char *function,...);
    void (*add_elements_by_query_selector)(
        CWebHyDrationSearchRequirements *self,
        const char *query_selector,
        ...
    );
    void (*add_elements_by_query_selector_not_auto_converting)(
        CWebHyDrationSearchRequirements *self,
        const char *query_selector,
        ...
    );
    void (*add_elements_by_attribute)(
        CWebHyDrationSearchRequirements *self,
       const char *attribute,
       const char*attribute_value,
       ...
    );
    void (*add_elements_by_attribute_not_auto_converting)(
        CWebHyDrationSearchRequirements *self,
        const char *attribute,
        const char*attribute_value,
        ...
    );

    void (*add_elements_by_class_name)(
        CWebHyDrationSearchRequirements *self,
        const char*class_value,
        ...
    );

    void (*add_elements_by_class_name_not_auto_converting)(
        CWebHyDrationSearchRequirements *self,
        const char*class_value,...
    );

    void (*add_elements_by_id)(
        CWebHyDrationSearchRequirements *self,
        const char*id_values,
        ...
    );

    void (*add_elements_by_id_not_auto_converting)(
        CWebHyDrationSearchRequirements *self,
        const char*id_values,
        ...
    );

    void (*add_session_storage_item_not_converting)(
        CWebHyDrationSearchRequirements *self,
        const char *name,
        ...
    );

    void (*add_elements_by_id_setting_search_as_same_name)(
        CWebHyDrationBridge *self, const char *id
    );


    void (*add_elements_by_id_setting_search_as_same_name_not_auto_converting)(
        CWebHyDrationBridge *self, const char *id
    );


    void (*add_elements_by_class_name_setting_search_as_same_name)(
        CWebHyDrationBridge *self, const char *class_name
    );

    void (*add_elements_by_class_name_setting_search_as_same_name_not_auto_converting)(
        CWebHyDrationBridge *self, const char *class_name
    );

    void (*add_session_storage_item)(
        CWebHyDrationSearchRequirements *self,
        const char *name,
        ...
    );

    void (*add_value_cookie_by_key)(CWebHyDrationSearchRequirements *self, const char *key);
    void (*add_confirm)(CWebHyDrationSearchRequirements *self, const char*message, ...);
    void (*add_prompt)(CWebHyDrationSearchRequirements *self, const char *message, ...);

}CWebHydrationSearchRequirementsNamespace;




typedef struct CWebHydrationSearchResultNamespace {

    int  (*get_total_avaialible_searchs)(CWebHyDrationBridge *self);
    CWebHyDrationSearchResult * (*get_search_by_index)(CWebHyDrationBridge *self,int index);
    CWebHyDrationSearchResult * (*get_search_by_name)(CWebHyDrationBridge *self,const char *name,...);
    bool (*search_exist)(CWebHyDrationBridge *self,const char *name,...);
    double (*get_double_from_first_element_of_search)(CWebHyDrationBridge *self,const char *name,...);
    long (*get_long_from_first_element_of_search)(CWebHyDrationBridge *self,const char *name,...);
    bool (*get_bool_from_first_element_of_search)(CWebHyDrationBridge *self,const char *name,...);
    char* (*get_string_from_first_element_of_search)(CWebHyDrationBridge *self,const char *name,...);
    cJSON* (*get_cJSON_from_first_element_of_search)(CWebHyDrationBridge *self,const char *name,...);
    int  (*get_total_itens)(CWebHyDrationSearchResult *self);
    bool  (*search_item_exist)(CWebHyDrationSearchResult *self,int index);
    bool  (*is_search_item_number)(CWebHyDrationSearchResult *self,int index);
    bool  (*is_search_item_bool)(CWebHyDrationSearchResult *self,int index);
    bool  (*is_search_item_string)(CWebHyDrationSearchResult *self,int index);
    double (*get_double)(CWebHyDrationSearchResult *self,int  index);
    long (*get_long)(CWebHyDrationSearchResult *self,int  index);
    bool (*get_bool)(CWebHyDrationSearchResult *self,int  index);
    char*  (*get_string)(CWebHyDrationSearchResult *self,int  index);
    cJSON *  (*get_cJSON)(CWebHyDrationSearchResult *self,int  index);

}CWebHydrationSearchResultNamespace;



typedef struct CwebHttpRequestModule{
    CwebHttpRequest *(*newCwebHttpRequest)(int socket);
    unsigned char*(*read_content)(struct CwebHttpRequest *self,long max_content_size);
    cJSON * (*read_cJSON)(CwebHttpRequest *self, long max_content_size);

    void (*set_url)(struct CwebHttpRequest *self,const char *url);
    void (*set_route)(struct CwebHttpRequest *self,const char *route);
    void (*set_method)(struct CwebHttpRequest *self,const char *method);

    void (*add_header)(struct CwebHttpRequest *self,const char *key,const char *value);
    void (*add_param)(struct CwebHttpRequest *self,const char *key,const char *value);
    void (*set_content_string)(struct CwebHttpRequest *self,const char *content);


    char *(*get_header)(struct CwebHttpRequest *self,const char *key);
    char *(*get_header_by_normalized_key)(
            struct CwebHttpRequest *self,
            const char *key,
            const char *chars_to_remove
    );

    char *(*get_param)(struct CwebHttpRequest *self,const char *key);
    char *(*get_param_by_sanitized_key)(struct CwebHttpRequest *self,const char *key,
                                        const char *chars_to_remove);


    int (*parse_http_request)(struct CwebHttpRequest *self);

    CTextStack *(*create_empty_stack)(CwebHttpRequest *self);
    CTextStack *(*create_stack)(CwebHttpRequest *self);


    void (*free)(struct CwebHttpRequest *request);
    void (*represent)(struct CwebHttpRequest *request);
}CwebHttpRequestModule;



typedef struct CwebHttpResponseModule{

    CwebHttpResponse  * (*newHttpResponse)();

    CwebHttpResponse * (*send_any)(
            const char *content_type,
            size_t content_length,
            unsigned char *content,
            int status_code
    );
    CwebHttpResponse * (*send_json_string)(
            const char *content,
            int status_code
    );
    CwebHttpResponse * (*send_json_string_cleaning_memory)(
            char *content,
            int status_code
    );
    CwebHttpResponse * (*send_cJSON)(
            cJSON *content,
            int status_code
    );


    CwebHttpResponse * (*send_cJSON_cleaning_memory)(
            cJSON *content,
            int status_code
    );


    CwebHttpResponse * (*send_text)(
            const char *content,
            int status_code
    );

    CwebHttpResponse * (*send_text_cleaning_memory)(
            char *content,
            int status_code
    );

    CwebHttpResponse* (*send_rendered_CTextStack)(struct CTextStack *stack,int status_code);

    CwebHttpResponse* (*send_var_html)(const char *content,int status_code);

    CwebHttpResponse* (*send_var_html_cleaning_memory)(
            char *content,
            int status_code
    );

    CwebHttpResponse * (*send_file)(
            const char *file_path,
            const char *content_type,
            int status_code
    );



    void (*set_content)(CwebHttpResponse *response, unsigned char *content, int content_length);
    void (*add_header)(CwebHttpResponse *response,const char *key,const  char *value);
    char *(*generate_response)(CwebHttpResponse *response);
    void (*free)(CwebHttpResponse *response);

}CwebHttpResponseModule;





typedef struct CwebServerModule{
    CwebServer (*newServer)(int port , CwebHttpResponse *(*request_handler)(CwebHttpRequest *request));
    int (*start)(struct  CwebServer *self);
}CwebServerModule;




typedef struct CwebStringArrayModule{
    CwebStringArray *(*newStringArray)();
    void (*set)( CwebStringArray *self,int index,const char *value);
    void (*add)( CwebStringArray *self,const char *string);
    void (*merge)(CwebStringArray *self, CwebStringArray *other);
    void (*represent)(CwebStringArray *self);
    int (*find)(CwebStringArray *self,const char *string);

    void (*free)(CwebStringArray *self);
}CwebStringArrayModule;


#endif

#ifndef CWebStudio_typesH
#define CWebStudio_typesH


typedef struct CwebDictModule{


    CwebDict *(*newDict)();
    void  (*set)(CwebDict *dict,const char *key,const char *value);
    char* (*get)(CwebDict *dict,const char *key);
    char* (*get_by_normalized_key)(CwebDict *dict,const char *key,const char *chars_to_remove);
    void  (*free)(CwebDict *dict);
    void  (*represent)(CwebDict *dict);

    CwebKeyValModule keyval;

}CwebDictModule;




typedef struct CWebHydrationNamespace{
    CWebHyDration *(*newCWebHyDration)(CwebHttpRequest *request);
    bool (*is_the_trigger)(CWebHyDration *self);
    char *(*create_script)(CWebHyDration *self);
    CwebHttpResponse *(*generate_response)(CWebHyDration *self);
    CTextStack  * (*create_stack)(CWebHyDration *self);
    CTextStack  * (*create_empty_stack)(CWebHyDration *self);
    CWebHydrationBridgeNamespace bridge;
    CWebHydrationActionsNamespace actions;
    CWebHydrationSearchRequirementsNamespace search_requirements;
    CWebHydrationSearchResultNamespace search_result;
    CWebHydrationArgsNamespace args;
}CWebHydrationNamespace;


#endif

#ifndef CWebStudio_typesO
#define CWebStudio_typesO



typedef struct CwebNamespace{
    CwebDictModule dict;
    CwebHttpRequestModule request;
    CwebHttpResponseModule response;
    CwebServerModule server;
    CwebStringArrayModule  string_array;
    CWebHydrationNamespace hydration;
}CwebNamespace;


#endif

#ifndef CWebStudio_fdeclare
#define CWebStudio_fdeclare



void  private_cweb_generate_cors_response(struct CwebHttpResponse *response);

CwebDict *newCwebDict();
void CwebDict_set(CwebDict *self, const  char *key, const char *value);
char *CwebDict_get(CwebDict *self, const char *key);

char *CwebDict_get_by_normalized_key(
  CwebDict *self,
  const char *key,
  const char *chars_to_remove
);

void CwebDict_represent(CwebDict *dict);
void CwebDict_free(CwebDict *self);



unsigned char *cweb_load_any_content(const char * path,int *size,bool *is_binary);

char *cweb_load_string_file_content(const char * path);

unsigned char *cweb_load_binary_content(const char * path,int *size);


const char *cweb_generate_content_type(const char *file_name);

char *private_cweb_convert_url_encoded_text(const char *text);



char * private_CWeb_format_vaarg(const char *expresion, va_list args);

char * private_CWeb_format(const char *expresion, ...);
//bool private_cweb_is_string_from_point(const char *content, long content_size, const char *test_string, long test_string_size, long point);
char *private_cweb_convert_to_hexa(const char *data);


CTextStack  *private_cweb_create_assci_code(const char *msg);



void privateCWebHyDrationBridge_add_response(CWebHyDrationBridge *self,const char *name,cJSON *data);

void CWebHyDrationBridge_set_session_storage_data(CWebHyDrationBridge *self,const char*key, const char *value,...);

void CWebHyDrationBridge_remove_session_storage_data(CWebHyDrationBridge *self,const char*key);

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




int   CWebHyDrationBridge_get_args_size(CWebHyDrationBridge *self);

bool private_cweb_hydration_type_verifier(CWebHyDrationBridge *self,int index,cJSON_bool (*callback_verifier)( cJSON * item));

bool   CWebHyDrationBridge_is_arg_number(CWebHyDrationBridge *self,int index);

bool   CWebHyDrationBridge_is_arg_bool(CWebHyDrationBridge *self,int index);

bool   CWebHyDrationBridge_is_arg_null(CWebHyDrationBridge *self,int index);

bool   CWebHyDrationBridge_is_arg_string(CWebHyDrationBridge *self,int index);

cJSON *privateCWebHyDration_get_arg_index(CWebHyDrationBridge *self,int index,cJSON_bool (*callback_verifier)( cJSON * item),const char *expected_type);

double  CWebHyDrationBridge_get_double_arg(CWebHyDrationBridge *self,int index);

long  CWebHyDrationBridge_get_long_arg(CWebHyDrationBridge *self,int index);

bool  CWebHyDrationBridge_get_bool_arg(CWebHyDrationBridge *self,int index);

char* CWebHyDrationBridge_get_str_arg(CWebHyDrationBridge *self,int index);

cJSON * CWebHyDrationBridge_get_cJSON_arg(CWebHyDrationBridge *self,int index);





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





void CWebHyDrationBridge_add_elements_by_id_setting_search_as_same_name(
    CWebHyDrationBridge *self, const char *id
);


void CWebHyDrationBridge_add_elements_by_id_setting_search_as_same_name_not_auto_converting(
    CWebHyDrationBridge *self, const char *id
);


void CWebHyDrationBridge_add_elements_by_class_name_setting_search_as_same_name(
    CWebHyDrationBridge *self, const char *class_name
);

void CWebHyDrationBridge_add_elements_by_class_name_setting_search_as_same_name_not_auto_converting(
    CWebHyDrationBridge *self, const char *class_name
);




int  CWebHyDrationBridge_get_total_avaialible_searchs(CWebHyDrationBridge *self);

CWebHyDrationSearchResult * CWebHyDrationBridge_get_search_by_index(CWebHyDrationBridge *self,int index);

CWebHyDrationSearchResult * CWebHyDrationBridge_get_search_by_name(CWebHyDrationBridge *self,const char *name,...);

bool CWebHyDrationBridge_search_exist(CWebHyDrationBridge *self,const char *name,...);

double CWebHyDrationBridge_get_double_from_first_element_of_search(CWebHyDrationBridge *self,const char *name,...);

long CWebHyDrationBridge_get_long_from_first_element_of_search(CWebHyDrationBridge *self,const char *name,...);

bool CWebHyDrationBridge_get_bool_from_first_element_of_search(CWebHyDrationBridge *self,const char *name,...);

char* CWebHyDrationBridge_get_string_from_first_element_of_search(CWebHyDrationBridge *self,const char *name,...);

cJSON* CWebHyDrationBridge_get_cJSON_from_first_element_of_search(CWebHyDrationBridge *self,const char *name,...);



privateCWebHyDrationBridgeArray * private_new_privateCWebHyDrationBridgeArray();

void privateCWebHyDrationBridgeArray_append(privateCWebHyDrationBridgeArray *self,CWebHyDrationBridge *element);

void privateCWebHyDrationBridgeArray_free(privateCWebHyDrationBridgeArray *self);



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





CWebHyDrationSearchRequirements * private_newCWebHyDrationSearchRequirements_getting_name_ownership(
    CWebHyDrationBridge *bridge, char *name
);


void private_CWebHyDrationSearchRequirements_free(CWebHyDrationSearchRequirements *self);


void CWebHyDrationSearchRequirements_add_function(CWebHyDrationSearchRequirements *self,const char *function,...);


void private_CWebHyDrationSearchRequirements_add_elements_by_query_selector(
    CWebHyDrationSearchRequirements *self,
    const char *query_selector,bool auto_convert
);


void CWebHyDrationSearchRequirements_add_elements_by_query_selector(
    CWebHyDrationSearchRequirements *self,
    const char *query_selector,
    ...
);




void CWebHyDrationSearchRequirements_add_elements_by_query_selector_not_auto_converting(
    CWebHyDrationSearchRequirements *self,const char *query_selector,...);


void CWebHyDrationSearchRequirements_add_elements_by_attribute(
    CWebHyDrationSearchRequirements *self,
   const char *attribute,
   const char*attribute_value,
   ...
);

void CWebHyDrationSearchRequirements_add_elements_by_attribute_not_auto_converting(
    CWebHyDrationSearchRequirements *self,
    const char *attribute,
    const char*attribute_value,
    ...
);

void CWebHyDrationSearchRequirements_add_cookie_item(CWebHyDrationSearchRequirements *self, const char *name);
void CWebHyDrationSearchRequirements_add_confirm(CWebHyDrationSearchRequirements *self, const char*message, ...);


void CWebHyDrationSearchRequirements_add_elements_by_class_name(
    CWebHyDrationSearchRequirements *self,
    const char*class_value,
    ...
);

void CWebHyDrationSearchRequirements_add_elements_by_class_name_not_auto_converting(
    CWebHyDrationSearchRequirements *self,
    const char*class_value,...
);

void CWebHyDrationSearchRequirements_add_elements_by_id(
    CWebHyDrationSearchRequirements *self,
    const char*id_values,
    ...
);

void CWebHyDrationSearchRequirements_add_elements_by_id_not_auto_converting(
    CWebHyDrationSearchRequirements *self,
    const char*id_values,
    ...
);


void CWebHyDrationSearchRequirements_add_session_storage_item_not_converting(
    CWebHyDrationSearchRequirements *self,
    const char *name,
    ...
);


void CWebHyDrationSearchRequirements_add_session_storage_item(
    CWebHyDrationSearchRequirements *self,
    const char *name,
    ...
);

void CWebHyDrationSearchRequirements_add_prompt(CWebHyDrationSearchRequirements *self, const char *message, ...);




CWebHyDrationSearchResult * private_newCWebHyDrationSearchResult(CWebHyDrationBridge *bridge,cJSON *search);

void privateCWebHyDrationSearchResult_free(CWebHyDrationSearchResult *self);

bool  privateCWebHyDrationSearchResult_has_erorrs(CWebHyDrationSearchResult *self);


int  CWebHyDrationSearchResult_get_total_itens(CWebHyDrationSearchResult *self);


bool  CWebHyDrationSearchResult_search_item_exist(CWebHyDrationSearchResult *self,int index);


bool  CWebHyDrationSearchResult_is_search_item_number(CWebHyDrationSearchResult *self,int index);

bool  CWebHyDrationSearchResult_is_search_item_bool(CWebHyDrationSearchResult *self,int index);


bool  CWebHyDrationSearchResult_is_search_item_string(CWebHyDrationSearchResult *self,int index);
cJSON * private_CWebHyDrationSearchResult_get_cJSON_item_verifying_type(
    CWebHyDrationSearchResult *self,
    int index,
    cJSON_bool (*callback_verifier)( cJSON *  item),
    const char *expected_type
);



double CWebHyDrationSearchResult_get_double(CWebHyDrationSearchResult *self,int  index);


long CWebHyDrationSearchResult_get_long(CWebHyDrationSearchResult *self,int  index);


bool CWebHyDrationSearchResult_get_bool(CWebHyDrationSearchResult *self,int  index);



char*  CWebHyDrationSearchResult_get_string(CWebHyDrationSearchResult *self,int  index);


cJSON *  CWebHyDrationSearchResult_get_cJSON(CWebHyDrationSearchResult *self,int  index);

CwebKeyVal* newCwebKeyVal(const char *key, const  char *value);
void CwebKeyVal_represent( CwebKeyVal *self);
void CwebKeyVal_free( CwebKeyVal *self);


CwebDictModule newCwebDictModule();



CwebKeyValModule newCwebKeyValModule();



CWebHydrationActionsNamespace newCWebHydrationActionsNamespace();




CWebHydrationArgsNamespace newCWebHydrationArgsNamespace();



CWebHydrationBridgeNamespace newCWebHydrationBridgetNamespace();




CWebHydrationNamespace newCWebHydrationNamespace();


CWebHydrationSearchRequirementsNamespace newCWebHydrationSearchRequirementsNamespace();




CWebHydrationSearchResultNamespace newCWebHydrationSearchResultNamespace();



CwebNamespace newCwebNamespace();



CwebHttpRequestModule newCwebRequestModule();




CwebHttpResponseModule newCwebHttpResponseModule();



CwebServerModule newCwebServerModule();




CwebStringArrayModule newCwebStringArrayModule();





 CwebHttpRequest *newCwebHttpRequest(int socket);


unsigned char * CwebHttpRequest_read_content( CwebHttpRequest *self, long max_content_size);


cJSON * CWebHttpRequest_read_cJSON(CwebHttpRequest *self, long max_content_size);


CTextStack *CwebHttpRequest_create_empty_stack(CwebHttpRequest *self);

CTextStack *CwebHttpRequest_create_stack(CwebHttpRequest *self);


char * CwebHttpRequest_get_header( CwebHttpRequest *self, const char *key);

char * CwebHttpRequest_get_param_by_sanitized_key( CwebHttpRequest *self, const char *key, const char *chars_to_remove);


char * CwebHttpRequest_get_param( CwebHttpRequest *self, const char *key);

char * CwebHttpRequest_get_header_by_normalized_key( CwebHttpRequest *self, const char *key, const char *chars_to_remove);


void CwebHttpRequest_set_route( CwebHttpRequest *self, const char *route);


void CwebHttpRequest_add_header( CwebHttpRequest *self, const char *key, const char *value);

void CwebHttpRequest_add_param( CwebHttpRequest *self, const char *key, const char *value);


void CwebHttpRequest_set_method( CwebHttpRequest *self, const char *method);

void CwebHttpRequest_set_content_string( CwebHttpRequest *self, const char *content);

void CwebHttpRequest_represent( CwebHttpRequest *self);


void CwebHttpRequest_free( CwebHttpRequest *self);






void private_CwebHttpRequest_interpret_query_params(struct CwebHttpRequest *self, const char *query_params);


void CwebHttpRequest_set_url(struct CwebHttpRequest *self, const char *url);

int private_CwebHttpRequest_interpret_first_line(struct CwebHttpRequest *self, char *first_line);


int private_CwebHttpRequest_interpret_headders(struct CwebHttpRequest *self, struct CwebStringArray *line_headers);




int  CwebHttpRequest_parse_http_request(struct CwebHttpRequest *self);





struct CwebHttpResponse *newCwebHttpResponse();

char *CwebHttpResponse_generate_response(struct CwebHttpResponse*self);


void CwebHttpResponse_free(struct CwebHttpResponse *self);

void CwebHttpResponse_set_content(CwebHttpResponse *self, unsigned char *content, int content_length);
void CwebHttpResponse_add_header(CwebHttpResponse *self, const char *key, const  char *value);





CwebHttpResponse* cweb_send_any(const char *content_type,size_t content_length,unsigned char *content,int status_code);

CwebHttpResponse * cweb_send_json_string(const char *content,int status_code);


CwebHttpResponse * cweb_send_json_string_cleaning_memory(char *content,int status_code);


CwebHttpResponse * cweb_send_cJSON(cJSON *content,int status_code);

CwebHttpResponse * cweb_send_cJSON_cleaning_memory(cJSON *content, int status_code);

CwebHttpResponse* cweb_send_any_cleaning_memory(const char *content_type,size_t content_length,unsigned char *content,int status_code);


CwebHttpResponse* cweb_send_rendered_CTextStack(struct CTextStack *stack,int status_code);



CwebHttpResponse* cweb_send_text(const char *content,int status_code);

CwebHttpResponse* cweb_send_text_cleaning_memory(char *content,int status_code);



CwebHttpResponse* cweb_send_var_html(const char *content,int status_code);



CwebHttpResponse* cweb_send_var_html_cleaning_memory(char *content,int status_code);


CwebHttpResponse* cweb_send_file(const char *file_path,const char *content_type,int status_code);




struct CwebServer  newCwebSever(int port , CwebHttpResponse *(*request_handler)(CwebHttpRequest *request));

int CwebServer_start(CwebServer *self);



#if defined(__linux__)


void private_cweb_execute_request_in_safty_mode(CwebServer  *self,int new_socket, const char *client_ip);

int  private_CWebServer_run_server_in_multiprocess(CwebServer *self);
#endif







void private_CWebServer_execute_request(CwebServer *self,int socket,const char *client_ip);




int private_CWebServer_run_server_in_single_process(CwebServer *self);




void private_cweb_send_error_mensage( CwebHttpResponse *response, int socket);

void cweb_kill_single_process_server( );

void cweb_set_static_folder(const char *folder);

const char * cweb_get_static_folder();

long cweb_get_total_requests();
#if defined(__linux__)

void private_cweb_treat_response(bool use_static,int new_socket);
void private_cweb_handle_child_termination(int signal);


#endif



void private_cweb_load_file_and_include(
        CTextStack *code,
        CTextStack *src,
        privateCwebRecursionList * recursion_listage
);
void private_cweb_generate_inline_inclusion(CTextStack *code, const char *content, long content_size,
                                            privateCwebRecursionList *recursion_listage, const char *filename);




privateCwebRecursionElement * newPrivateCwebRecursionElement(const char *file, const char *included);

void PrivateCwebRecursionElement_represent(privateCwebRecursionElement *self);

void PrivateCwebRecursionElement_free(privateCwebRecursionElement *self);




privateCwebRecursionList * newprivateCwebRecursionList();


privateCwebRecursionElement * privateCwebRecursionList_add_if_not_colide(privateCwebRecursionList *self,const char *file,const char *included);

void privateCwebRecursionList_represent(privateCwebRecursionList *self);

void privateCwebRecursionList_free(privateCwebRecursionList *self);



char * private_cweb_smart_static_ref(CTextStack *src);

char * cweb_smart_static_ref(const char *src);


CTextStack * private_cweb_change_smart_cache(CTextStack *content);





CTextStack * private_cweb_format_filename(CTextStack *src);


CwebHttpResponse * private_cweb_treat_five_icon();

char * private_cweb_aply_macro_modifiers_in_content(const char *content, long content_size);

char * cweb_aply_macro_modifiers_in_content(const char *content);

char * cweb_aply_macro_modifiers_in_file(const char *filename);

CwebHttpResponse * private_cweb_generate_static_response(struct CwebHttpRequest *request,bool use_cache);



CwebStringArray * newCwebStringArray();

int  CwebStringArray_find(struct CwebStringArray *self, const char *string);
void CwebStringArray_add(struct CwebStringArray *self, const char *string);

void CwebStringArray_add_getting_ownership(struct CwebStringArray *self, char *string);

void CwebStringArray_merge(struct CwebStringArray *self, struct CwebStringArray *other);
void CwebStringArray_represent(struct CwebStringArray *self);
void CwebStringArray_free(struct CwebStringArray *self);
void CwebStringArray_set(struct CwebStringArray *self, int index, const char *value);




char *cweb_parse_string_to_lower(const char *old_string);

char *cweb_parse_string_to_upper(const char *old_string);

char *cweb_normalize_string(const char *old_string,const char *invalid_chars);

bool cweb_starts_with(const char *string, const char *prefix);

char *cweb_replace_string_once(const char *target, const char *old_element, const char *new_element);

char* cweb_replace_string(const char *target, const char *old_element, const char *new_element);

#endif
