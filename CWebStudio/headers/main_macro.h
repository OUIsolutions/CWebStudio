#define CWEB_START_MACRO(port, caller)\
int main() {\
     struct CwebSever *sever = newCwebSever(port, caller);\
     sever->start(sever);\
     sever->free(sever);\
return 0;\
}

