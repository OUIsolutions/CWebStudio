
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
