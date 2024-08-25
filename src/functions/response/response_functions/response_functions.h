
#include "../uniq.declaration_requirements.h"


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
