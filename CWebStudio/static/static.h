

char * smart_static_ref(const char *path);

char * private_cweb_change_smart_cache(const char *content);

CwebHttpResponse * private_cweb_treat_five_icon(struct CwebHttpRequest *request);

CwebHttpResponse * private_cweb_generate_static_response(struct CwebHttpRequest *request,bool use_cache);
