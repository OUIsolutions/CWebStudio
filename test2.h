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

typedef struct CwebStringArray {
  int size;         
  char **strings;       
}CwebStringArray;

#endif

#ifndef CWebStudio_typesB
#define CWebStudio_typesB

typedef struct CwebDict {
  int size;
  CwebKeyVal **keys_vals;
}CwebDict;

#endif

#ifndef CWebStudio_typesC
#define CWebStudio_typesC

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

#endif

#ifndef CWebStudio_typesO
#define CWebStudio_typesO

typedef struct CwebNamespace{
    CwebDictModule dict;
    CwebHttpRequestModule request;
    CwebHttpResponseModule response;
    CwebServerModule server;
    CwebStringArrayModule string_array;
}CwebNamespace;

#endif

#ifndef CWebStudio_fdeclare
#define CWebStudio_fdeclare

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

CwebKeyVal* newCwebKeyVal(const char *key, const  char *value);
void CwebKeyVal_represent( CwebKeyVal *self);
void CwebKeyVal_free( CwebKeyVal *self);

CwebDictModule newCwebDictModule();
CwebKeyValModule newCwebKeyValModule();
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

void CwebHttpRequest_set_url(struct CwebHttpRequest *self, const char *url);
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
CwebHttpResponse* cweb_send_rendered_CTextStack(struct CTextStack *stack,int status_code);
CwebHttpResponse* cweb_send_text(const char *content,int status_code);
CwebHttpResponse* cweb_send_text_cleaning_memory(char *content,int status_code);
CwebHttpResponse* cweb_send_var_html(const char *content,int status_code);
CwebHttpResponse* cweb_send_var_html_cleaning_memory(char *content,int status_code);
CwebHttpResponse* cweb_send_file(const char *file_path,const char *content_type,int status_code);

struct CwebServer  newCwebSever(int port , CwebHttpResponse *(*request_handler)(CwebHttpRequest *request));
int CwebServer_start(CwebServer *self);

void cweb_kill_single_process_server( );
void cweb_set_static_folder(const char *folder);
const char * cweb_get_static_folder();
long cweb_get_total_requests();

char * cweb_smart_static_ref(const char *src);
char * cweb_aply_macro_modifiers_in_content(const char *content);
char * cweb_aply_macro_modifiers_in_file(const char *filename);

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
