

unsigned char *cweb_load_any_content(const char * path,int *size,bool *is_binary);

char *cweb_load_string_file_content(const char * path);

unsigned char *cweb_load_binary_content(const char * path,int *size);


const char *cweb_generate_content_type(const char *file_name);

char *private_cweb_convert_url_encoded_text(const char *text);


bool private_cweb_is_string_from_point(const char *content, long content_size, const char *test_string, long test_string_size, long point);
