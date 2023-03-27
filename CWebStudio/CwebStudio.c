#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "dependencies/doTheWorld/doTheWorldMain.c"
#include "headers/key_val.h"
#include "headers/dict.h"
#include "headers/response.h"
#include "headers/response_functions.h"
#include "headers/request.h"
#include "headers/server.h"


#include "structs/request.c"
#include "response_functions.c"
#include "structs/key_val.c"
#include "structs/dict.c"
#include "structs/response.c"

#include "server.c"