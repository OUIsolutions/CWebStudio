
typedef struct CwebRequestModule{
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
}CwebRequestModule;