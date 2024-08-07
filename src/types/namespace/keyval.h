#include "../keyval.h"

#ifndef PRIVATE_CWEB_HTTP_NAMESPACE_KEYVAL_TYPES
#define PRIVATE_CWEB_HTTP_NAMESPACE_KEYVAL_TYPES


typedef struct CwebKeyValModule{
    void (*represent)(CwebKeyVal *key_val);
    void (*free)(CwebKeyVal *key_val);
}CwebKeyValModule;

#endif //PRIVATE_CWEB_HTTP_NAMESPACE_KEYVAL_TYPES