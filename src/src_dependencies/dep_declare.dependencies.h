
#if defined(__linux__) || defined(__APPLE__)
#include <sys/wait.h>
#endif

#if defined(__APPLE__)
#define CWEB_LINUX_EMULATION
#define __linux__
#define __linux
#endif

#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#if !defined(CTextEngine_fdeclare)
#include "../../dependencies/CTextEngine.h"
#define CWEB_CTEXT_ENGINE_DECLARATED
#endif

#if !defined(UniversalSocket_dep) && !defined(CWEB_MOCK_UNIVERSAL_SOCKET)
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

#if defined (CWEB_LINUX_EMULATION)
#undef __linux__
#undef __linux
#endif
