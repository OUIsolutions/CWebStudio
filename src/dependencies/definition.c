

#ifdef CTEXTENGINE_DEFINED_IN_CWEB_STUDIO
#include "CTextEngine/definition.c"
#endif


#ifdef cJSON_DEFINED_IN_CWEB_STUDIO
#include "cJson/cJSON.c"
#undef false 
#undef true
#define false 0
#define true 1
#endif


#ifdef  UNIVERSAL_GARBAGE_DEFINED_IN_CWEB_STUDIO
#include "UniversalGarbage/definition.c"
#endif
