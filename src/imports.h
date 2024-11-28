#ifndef PRIVATE_CWEB_HTTP_IMPORTS_H
#define PRIVATE_CWEB_HTTP_IMPORTS_H
#if defined(__linux__)
#include <sys/wait.h>
#endif

#if defined(_WIN32)
    #pragma comment(lib, "ws2_32.lib") // Linka a biblioteca Winsock
    #include <winsock2.h>
    #include <ws2tcpip.h>

#endif

#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

#endif //PRIVATE_CWEB_HTTP_IMPORTS_H
