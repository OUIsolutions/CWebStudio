

typedef struct CwebHttpResponseModule{

    CwebHttpResponse  * (*newHttpResponse)();

    CwebHttpResponse * (*send_any)(
            const char *content_type,
            size_t content_length,
            unsigned char *content,
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

    CwebHttpResponse* (*send_rendered_CTextStack_cleaning_memory)(struct CTextStack *stack,int status_code);

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

CwebHttpResponseModule newCwebHttpResponseModule();