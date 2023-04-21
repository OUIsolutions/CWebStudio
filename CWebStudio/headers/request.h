
#define INVALID_HTTP -1
#define MAX_BODY_SIZE -2

struct CwebHttpRequest{

    char *url;
    char *route;
    char *method;
    struct CwebDict *params;
    struct CwebDict *headers;
    int content_length;
    unsigned char *content;

    void (*set_url)(struct CwebHttpRequest *self,const char *url);
    void (*set_route)(struct CwebHttpRequest *self,const char *route);
    void (*set_method)(struct CwebHttpRequest *self,const char *method);


    char *(*get_header)(struct CwebHttpRequest *self,const char *key);
    char *(*get_header_by_sanitized_key)(struct CwebHttpRequest *self,const char *key);

    char *(*get_param)(struct CwebHttpRequest *self,const char *key);
    char *(*get_param_by_sanitized_key)(struct CwebHttpRequest *self,const char *key);

    void (*add_header)(struct CwebHttpRequest *self,const char *key,const char *value);
    void (*add_param)(struct CwebHttpRequest *self,const char *key,const char *value);

    void (*set_content_string)(struct CwebHttpRequest *self,const char *content);

    int (*parse_http_request)(struct CwebHttpRequest *self,int socket,size_t max_body_size);
    void (*interpret_query_params)(struct CwebHttpRequest *self,const char *query_params);
    int (*interpret_first_line)(struct CwebHttpRequest *self, char *first_line);
    int (*interpret_headders)(struct CwebHttpRequest *self, struct DtwStringArray *line_headers);
    void (*free)(struct CwebHttpRequest *request);
    void (*represent)(struct CwebHttpRequest *request);
};
//algorithm functions

char * private_cweb_get_header(struct CwebHttpRequest *self,const char *key);
char * private_cweb_get_header_by_sanitized_key(
    struct CwebHttpRequest *self,
    const char *key
);
char * private_cweb_get_param(struct CwebHttpRequest *self,const char *key);
char * private_cweb_get_param_by_sanitized_key(
    struct CwebHttpRequest *self,
    const char *key
);

void private_cweb_set_url(struct CwebHttpRequest *self,const char *url);
void private_cweb_set_route(struct CwebHttpRequest *self,const char *route);

void private_cweb_add_header(struct CwebHttpRequest *self,const char *key,const char *value);
void private_cweb_add_param(struct CwebHttpRequest *self,const char *key,const char *value);

void private_cweb_set_method(struct CwebHttpRequest *self,const char *method);
void private_cweb_set_content_string(struct CwebHttpRequest *self,const char *content);

struct CwebHttpRequest *cweb_request_constructor();


int  private_cweb_parse_http_request(struct CwebHttpRequest *self,int socket,size_t max_body_size);

void private_cweb_interpret_query_params(struct CwebHttpRequest *self,const char *query_params);

int private_cweb_interpret_first_line(struct CwebHttpRequest *self, char *first_line);


int private_cweb_interpret_headders(
    struct CwebHttpRequest *self,
    struct DtwStringArray *line_headers
);

void private_cweb_free_http_request(struct CwebHttpRequest *self);


void private_cweb_represent_http_request(struct CwebHttpRequest *self);

