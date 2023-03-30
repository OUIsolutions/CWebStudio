#define CWEB_START_MACRO(port, caller)\
int main() {\
cweb_run_server((port), (caller));\
return 0;\
}

