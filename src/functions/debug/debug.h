

#ifdef CWEB_DEBUG
#define cweb_print(...) printf(__VA_ARGS__);
#else 
#define cweb_print(...);
#endif

#define CWEB_END_ROUTE()\
if(strcmp(request->route,"/end" ) ==0){ \
        cweb_end_server = true;\
}



