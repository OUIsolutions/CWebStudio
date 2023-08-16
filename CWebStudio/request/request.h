
#define INVALID_HTTP -1
#define MAX_HEADER_SIZE -2
#define READ_ERROR -3
#define MAX_CONTENT_SIZE -4
#define UNDEFINED_CONTENT -5
#define INVALID_JSON -6

typedef struct CwebHttpRequest{

    char *url;
    int socket;
    char *route;
    char *method;
    CwebDict *params;
    CwebDict *headers;
    int content_length;
    unsigned char *content;
    cJSON *json;

}CwebHttpRequest;
//algorithm functions
 CwebHttpRequest *newCwebHttpRequest(int socket);

int CwebHttpRequest_read_content(CwebHttpRequest *self, long max_content_size);

int CWebHttpRequest_read_cJSON(CwebHttpRequest *self, long max_content_size);

char * CwebHttpRequest_get_header(CwebHttpRequest *self, const char *key);

char * CwebHttpRequest_get_header_by_normalized_key(
        struct CwebHttpRequest *self,
        const char *key,
        const char *chars_to_remove
);
char * CwebHttpRequest_get_param(CwebHttpRequest *self, const char *key);

char * CwebHttpRequest_get_param_by_sanitized_key(
    CwebHttpRequest *self,
    const char *key,
    const char *chars_to_remove
);

void CwebHttpRequest_set_url(CwebHttpRequest *self, const char *url);

void CwebHttpRequest_set_route(CwebHttpRequest *self, const char *route);

void CwebHttpRequest_add_header(CwebHttpRequest *self, const char *key, const char *value);

void CwebHttpRequest_add_param(CwebHttpRequest *self, const char *key, const char *value);

void CwebHttpRequest_set_method(CwebHttpRequest *self, const char *method);

void CwebHttpRequest_set_content_string(CwebHttpRequest *self, const char *content);

int  CwebHttpRequest_parse_http_request(CwebHttpRequest *self);

void private_CwebHttpRequest_interpret_query_params(CwebHttpRequest *self, const char *query_params);

int private_CwebHttpRequest_interpret_first_line(CwebHttpRequest *self, char *first_line);


int private_CwebHttpRequest_interpret_headders(
    CwebHttpRequest *self,
    CwebStringArray *line_headers
);

void CwebHttpRequest_free(CwebHttpRequest *self);


void CwebHttpRequest_represent(struct CwebHttpRequest *self);

