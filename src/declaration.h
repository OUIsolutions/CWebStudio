
#include <sys/wait.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <signal.h>
#include <sys/resource.h>

#include <arpa/inet.h>
#include <unistd.h>

#include "string_array/string_array.h"
#include "strings/strings.h"
#include "extras/extras.h"
#include "debug/debug.h"

#include "dict/declaration.h"
#include "response/declaration.h"
#include "request/request.h"
#include "static/declaration.h"
#include "cors/cors.h"
#include "server/declaration.h"
#include "namespace/declaration.h"