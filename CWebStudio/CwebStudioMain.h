

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
#include "string_array/string_array.h"
#include "strings/strings.h"
#include "extras/extras.h"
#include "debug/debug.h"
#include "keyval/key_val.h"
#include "dict/dict.h"
#include "response/response/response.h"
#include "response/response_functions/response_functions.h"
#include "request/request.h"
#include "static/static.h"

#include "server/server_functions/sever_functions.h"
#include "server/server/sever.h"
#include "main_macro.h"

#include "strings/strings.c"
#include "extras/extras.c"
#include "request/request.c"
#include "request/request_parser.c"
#include "response/response_functions/response_functions.c"
#include "string_array/string_array.c"
#include "keyval/key_val.c"
#include "dict/dict.c"
#include "response/response/response.c"
#include "static/static.c"
#include "server/server_functions/request_execution.c"
#include "server/server_functions/single_process.c"
#include "server/server_functions/multi_process.c"
#include "server/server/server.c"

#endif