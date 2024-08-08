#ifdef _WIN32
#include <windows.h>
#else
#include <signal.h>
#include <unistd.h>
#endif

#include <setjmp.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include "dependencies/dependencies.h"
#include "constants/all.h"
#include "LuaCEmbedResponse/LuaCEmbedResponse.h"
#include "LuaCEmbed/declaration.h"
#include "LuaCEmbedResponse/LuaCembedResponse_pt2.h"

#include "extra/extra.h"
#include "namespace/declaration.h"