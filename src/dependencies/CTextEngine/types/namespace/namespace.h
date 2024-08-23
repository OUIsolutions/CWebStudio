
#include "array.h"
#include "stack.h"

#ifndef PRIVATE_CTEXT_NAMESPACE_TYPE
#define PRIVATE_CTEXT_NAMESPACE_TYPE
typedef struct CTextNamespace{

    CTextArrayModule array;
    CTextStackModule stack;

}CTextNamespace;
#endif
