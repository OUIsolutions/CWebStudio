#define CWEB_START_MACRO(port, caller)\
int main() {\
cweb_run_server((port), (caller),CWEB_DEFAULT_TIMEOUT,CWEB_DEFAULT_MAX_REQUEST,CWEB_SAFTY_MODE);\
return 0;\
}

