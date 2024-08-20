#include "garbage_element.h"

#ifndef  PRIVATE_UNIVERSAL_GARBAGE_TYPE
#define PRIVATE_UNIVERSAL_GARBAGE_TYPE


typedef  struct UniversalGarbage{

    struct UniversalGarbage *return_values;
    privateUniversalGarbageElement **elements;
    int  elements_size;
    bool is_the_root;

}UniversalGarbage;
#endif
