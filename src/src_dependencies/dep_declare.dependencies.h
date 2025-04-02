
#if defined(__linux__)
#include <sys/wait.h>
#endif



#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>


#if !defined(UniversalSocket_dep)
#include "../../dependencies/UniversalSocket.h"
#define CWEB_UNIVERSAL_SOCKET_DECLARATED
#endif 

#if !defined(cJSON__h) && !defined(CWEB_MOCK_CJSON) 
#include "../../dependencies/cJSON.h"
#define CWEB_CJSON_DECLARATED
#endif

#if !defined(UniversalGarbage_fdeclare) && !defined(CWEB_MOCK_UNIVERSAL_GARBAGE)
#include "../../dependencies/UniversalGarbage.h"
#define CWEB_UNIVERSAL_GARBAGE_DECLARATED
#endif