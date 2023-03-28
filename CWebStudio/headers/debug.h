

#ifdef CWEB_DEBUG
#define cweb_print(...) printf(__VA_ARGS__)
#else 
#define cweb_print(...) NULL;
#endif 