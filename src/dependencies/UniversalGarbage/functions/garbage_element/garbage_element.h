
#include "../unique.declaration_requirements.h"


void private_UniversalGarbageSimpleElement_free_pointed_value(privateUniversalGarbageElement *self);


void private_UniversalGarbageSimpleElement_free(privateUniversalGarbageElement *self);

privateUniversalGarbageElement * private_newUniversalGarbageSimpleElement(void (*dealocator_callback)(void *element), void **pointer);
