

#include "../uniq.declaration_requirements.h"

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
