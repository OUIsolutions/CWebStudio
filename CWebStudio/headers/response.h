
char *create_response(
    int status_code,
    const char *content_type,
    size_t content_length,
    const char *content
    );

char *send_text(int status_code,const char *content);