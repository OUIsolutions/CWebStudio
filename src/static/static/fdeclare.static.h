


CTextStack * private_cweb_format_filename(CTextStack *src);


CwebHttpResponse * private_cweb_treat_five_icon();

char * private_cweb_aply_macro_modifiers_in_content(const char *content, long content_size);

char * cweb_aply_macro_modifiers_in_content(const char *content);

char * cweb_aply_macro_modifiers_in_file(const char *filename);

CwebHttpResponse * private_cweb_generate_static_response(struct CwebHttpRequest *request,bool use_cache);
