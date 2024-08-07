#include "../string_array.h"

#ifndef PRIVATE_CWEB_HTTP_NAMESPACE_STRING_TYPES
#define PRIVATE_CWEB_HTTP_NAMESPACE_STRING_TYPES

typedef struct CwebStringArrayModule{
    CwebStringArray *(*newStringArray)();
    void (*set)( CwebStringArray *self,int index,const char *value);
    void (*add)( CwebStringArray *self,const char *string);
    void (*merge)(CwebStringArray *self, CwebStringArray *other);
    void (*represent)(CwebStringArray *self);
    int (*find)(CwebStringArray *self,const char *string);

    void (*free)(CwebStringArray *self);
}CwebStringArrayModule;

#endif //PRIVATE_CWEB_HTTP_NAMESPACE_STRING_TYPES