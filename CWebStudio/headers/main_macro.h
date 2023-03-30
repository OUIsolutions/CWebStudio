#define cweb_start(port, caller)\
int main() {\
cweb_run_server((port), (caller));\
return 0;\
}

