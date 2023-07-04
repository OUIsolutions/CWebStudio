
#define INVALID_HTTP -1
#define MAX_HEADER_SIZE -2
#define READ_ERROR -3
#define MAX_CONTENT_SIZE -4
#define UNDEFINED_CONTENT -5

typedef struct CwebHttpRequest{

    char *url;
    int socket;
    char *route;
    char *method;
    struct CwebDict *params;
    struct CwebDict *headers;
    int content_length;
    unsigned char *content;


    int (*read_content)(struct CwebHttpRequest *self,long max_content_size);

    void (*set_url)(struct CwebHttpRequest *self,const char *url);
    void (*set_route)(struct CwebHttpRequest *self,const char *route);
    void (*set_method)(struct CwebHttpRequest *self,const char *method);


    char *(*get_header)(struct CwebHttpRequest *self,const char *key);
    char *(*get_header_by_sanitized_key)(
        struct CwebHttpRequest *self,
        const char *key,
        const char *chars_to_remove
        );

    char *(*get_param)(struct CwebHttpRequest *self,const char *key);
    char *(*get_param_by_sanitized_key)(struct CwebHttpRequest *self,const char *key,
        const char *chars_to_remove);

    void (*add_header)(struct CwebHttpRequest *self,const char *key,const char *value);
    void (*add_param)(struct CwebHttpRequest *self,const char *key,const char *value);

    void (*set_content_string)(struct CwebHttpRequest *self,const char *content);

    int (*parse_http_request)(struct CwebHttpRequest *self);
    void (*interpret_query_params)(struct CwebHttpRequest *self,const char *query_params);
    int (*interpret_first_line)(struct CwebHttpRequest *self, char *first_line);
    int (*interpret_headders)(struct CwebHttpRequest *self, struct CwebStringArray *line_headers);
    void (*free)(struct CwebHttpRequest *request);
    void (*represent)(struct CwebHttpRequest *request);
}CwebHttpRequest;
//algorithm functions

int private_cweb_read_content(struct CwebHttpRequest *self,long max_content_size);


char * private_cweb_get_header(struct CwebHttpRequest *self,const char *key);
char * private_cweb_get_header_by_sanitized_key(
    struct CwebHttpRequest *self,
    const char *key,
    const char *chars_to_remove
);
char * private_cweb_get_param(struct CwebHttpRequest *self,const char *key);
char * private_cweb_get_param_by_sanitized_key(
    struct CwebHttpRequest *self,
    const char *key,
    const char *chars_to_remove
);

void private_cweb_set_url(struct CwebHttpRequest *self,const char *url);

void private_cweb_set_route(struct CwebHttpRequest *self,const char *route);

void private_cweb_add_header(struct CwebHttpRequest *self,const char *key,const char *value);

void private_cweb_add_param(struct CwebHttpRequest *self,const char *key,const char *value);

void private_cweb_set_method(struct CwebHttpRequest *self,const char *method);

void private_cweb_set_content_string(struct CwebHttpRequest *self,const char *content);

struct CwebHttpRequest *cweb_request_constructor(int socket);


int  private_cweb_parse_http_request(struct CwebHttpRequest *self);


void private_cweb_interpret_query_params(struct CwebHttpRequest *self,const char *query_params);

int private_cweb_interpret_first_line(struct CwebHttpRequest *self, char *first_line);


int private_cweb_interpret_headders(
    struct CwebHttpRequest *self,
    struct CwebStringArray *line_headers
);

void private_cweb_free_http_request(struct CwebHttpRequest *self);


void private_cweb_represent_http_request(struct CwebHttpRequest *self);

