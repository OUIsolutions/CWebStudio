#define CWEB_ONE_MINUTE 60
#define CWEB_ONE_HOUR 3600
#define CWEB_ONE_DAY 86400
#define CWEB_ONE_WEEK 604800
#define CWEB_ONE_MONTH 2592000
#define CWEB_ONE_YEAR 31536000

struct CwebHttpResponse * private_cweb_treat_five_icon(struct CwebHttpRequest *request);

struct CwebHttpResponse * private_cweb_generate_static_response(struct CwebHttpRequest *request,long max_cache_age);

char * private_cweb_change_smart_cache(const char *content);