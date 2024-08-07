#include "imports.h"

#ifndef PRIVATE_CWEB_GLOBALS
#define  PRIVATE_CWEB_GLOBALS
static long long  cweb_actual_request = 0;
static long cweb_total_requests = 0;
static bool private_cweb_end_server = false;

static const char* cweb_static_folder;
#endif
