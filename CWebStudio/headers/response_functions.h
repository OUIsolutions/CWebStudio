

struct CwebHttpResponse * cweb_send_any(
    const char *content_type,
    size_t content_length,
    unsigned char *content
);

struct CwebHttpResponse * cew_send_text(
    const char *content
);

struct CwebHttpResponse * cew_send_file(
    const char *file_path,
    const char *content_type,
    const char *content
);
