

unsigned char *cweb_load_any_content(const char * path,int *size,bool *is_binary);


void cweb_write_string_file_content(const char *path,const char *value);

char *cweb_load_string_file_content(const char * path);

unsigned char *cweb_load_binary_content(const char * path,int *size);


const char *cweb_generate_content_type(const char *file_name);

char *private_cweb_convert_url_encoded_text(const char *text);


