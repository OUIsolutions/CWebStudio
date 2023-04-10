#define CWEB_START_MACRO(port, caller)\
int main() {\
cweb_run_server((port), (caller),CWEB_DEFAULT_TIMEOUT,CWEB_MAX_REQUEST_SIZE,CWEB_SAFTY_MODE,1);\
return 0;\
}

