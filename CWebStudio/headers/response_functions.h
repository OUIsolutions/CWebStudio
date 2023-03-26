

struct CwebHttpResponse * cweb_send_any(
    const char *content_type,
    size_t content_length,
    unsigned char *content,
    int status_code
);

struct CwebHttpResponse * cew_send_text(
    const char *content,
    int status_code
);

struct CwebHttpResponse * cew_send_file(
    const char *file_path,
    const char *content_type,
    int status_code
);
