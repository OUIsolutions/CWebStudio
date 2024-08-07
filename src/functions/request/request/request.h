

#include "../uniq.declaration_requirements.h"

struct CwebHttpRequest *newCwebHttpRequest(int socket);


unsigned char * CwebHttpRequest_read_content(struct CwebHttpRequest *self, long max_content_size);


cJSON * CWebHttpRequest_read_cJSON(CwebHttpRequest *self, long max_content_size);




char * CwebHttpRequest_get_header(struct CwebHttpRequest *self, const char *key);

char * CwebHttpRequest_get_param_by_sanitized_key(struct CwebHttpRequest *self, const char *key, const char *chars_to_remove);


char * CwebHttpRequest_get_param(struct CwebHttpRequest *self, const char *key);

char * CwebHttpRequest_get_header_by_normalized_key(struct CwebHttpRequest *self, const char *key, const char *chars_to_remove);


void CwebHttpRequest_set_route(struct CwebHttpRequest *self, const char *route);


void CwebHttpRequest_add_header(struct CwebHttpRequest *self, const char *key, const char *value);

void CwebHttpRequest_add_param(struct CwebHttpRequest *self, const char *key, const char *value);


void CwebHttpRequest_set_method(struct CwebHttpRequest *self, const char *method);

void CwebHttpRequest_set_content_string(struct CwebHttpRequest *self, const char *content);

void CwebHttpRequest_represent(struct CwebHttpRequest *self);


void CwebHttpRequest_free(struct CwebHttpRequest *self);
