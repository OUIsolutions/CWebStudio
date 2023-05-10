

/*
MIT License

Copyright (c) 2023 Mateus Moutinho Queiroz

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/
#ifndef __CWEBSTUDIO_H
#define __CWEBSTUDIO_H
#include <sys/wait.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <signal.h>

#include <arpa/inet.h>
#include <unistd.h>
#include "dependencies/CTextEngine.h"

#ifndef cJSON__h

#include "dependencies/cJson/cJSON.h"
#include "dependencies/cJson/cJSON.c"

#endif    
#include "headers/string_array.h"
#include "headers/strings.h"
#include "headers/extras.h"
#include "headers/debug.h"
#include "headers/key_val.h"
#include "headers/dict.h"
#include "headers/response.h"
#include "headers/response_functions.h"
#include "headers/request.h"
#include "headers/static.h"

#include "headers/server.h"
#include "headers/main_macro.h"

#include "strings.c"
#include "extras.c"
#include "structs/request/request.c"
#include "structs/request/request_parser.c"
#include "response_functions.c"
#include "structs/string_array.c"
#include "structs/key_val.c"
#include "structs/dict.c"
#include "structs/response.c"
#include "static.c"
#include "server.c"

#endif