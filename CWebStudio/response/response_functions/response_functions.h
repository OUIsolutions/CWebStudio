

#define CWEB_AUTO_SET_CONTENT NULL 
#define CWEB_OK  200
#define CWEB_NOT_FOUND 404
#define CWEB_BAD_REQUEST 400
#define CWEB_FORBIDDEN 403
#define CWEB_INTERNAL_SERVER_ERROR 500


 CwebHttpResponse * cweb_send_any(
    const char *content_type,
    size_t content_length,
    unsigned char *content,
    int status_code
);

CwebHttpResponse * cweb_send_text(
    const char *content,
    int status_code
);

CwebHttpResponse * cweb_send_json_string(
        const char *content,
        int status_code
);
CwebHttpResponse * cweb_send_json_string_cleaning_memory(
        char *content,
        int status_code
);

CwebHttpResponse * cweb_send_text_cleaning_memory(
    char *content,
    int status_code
);

CwebHttpResponse* cweb_send_rendered_CTextStack_cleaning_memory(struct CTextStack *stack,int status_code);

CwebHttpResponse* cweb_send_var_html(const char *content,int status_code);

CwebHttpResponse* cweb_send_var_html_cleaning_memory(
    char *content,
    int status_code
);

CwebHttpResponse * cweb_send_file(
    const char *file_path,
    const char *content_type,
    int status_code
);
