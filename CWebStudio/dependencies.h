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
#include "dependencies/CTextEngine.h"
#ifndef cJSON__h
#include "dependencies/cJson/cJSON.h"
#include "dependencies/cJson/cJSON.c"
#endif