# CWebSudio 
CWebSudio is a micro framework to deal with web aplications in C/C++. It's a 
single header library that provides a lot of functionality such as reading headers,
query parameters, returning files, and text.

# Installation 

## Single File
CWebSudio is made to be as dumb as possible and adopt the idea of single file library.
For installation, simply copy the **CWebStudio.h** into your project and compile with gcc/g++ or clang. 

~~~c

#include "CWebStudio.h"

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    return cweb_send_text("Hello World", 200);
}

CWEB_START_MACRO(5001, main_sever);
~~~
## Full Folder 
You can also download the entire **CWebStudio** folder to your project and run with the
**#include "CWebStudio/CwebStudioMain.h"** header:

~~~c

#include "CWebStudio/CwebStudioMain.h"

CwebHttpResponse *main_sever( CwebHttpRequest *request ){

    return cweb_send_text("Hello World", 200);
}

CWEB_START_MACRO(5001, main_sever);
~~~
# Running with Main
If making main configurations before running the server is needed, the function **cweb_run_server** may be ran without a macro: 
<!--codeof:examples/runig_with_main.c-->
~~~c

#include "CWebStudio.h"

 CwebHttpResponse *main_sever( CwebHttpRequest *request ){

    return cweb_send_text("Hello World", 200);
}

int main(int argc, char *argv[]){

   
     struct CwebServer *sever = newCwebSever(5000, main_sever);
     sever->start(sever);
     sever->free(sever);
}
~~~


# Getting Entries

## Route a Method

Working with URL parameters is very easy, as seen in the following example:
<!--codeof:examples/route_and_method.c-->
~~~c

#include "CWebStudio.h"


CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    char *url = request->url;
    char *method = request->method;
    char *route = request->route;

    printf("URL: %s\n", url);
    printf("Method: %s\n", method);
    printf("Route: %s\n", route);
    return cweb_send_text("Hello World", 200);
    
}

CWEB_START_MACRO(50010, main_sever);
~~~
## Iterating Query Parameters

To iterate through parameters, the object **CwebDict** may be used like this:
<!--codeof:examples/iterating_over_query_paramns.c-->
~~~c
#include "CWebStudio.h"

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    CwebDict *query_paramns = request->params;
    for(int i = 0; i < query_paramns->size; i++){
        CwebKeyVal *key_val = query_paramns->keys_vals[i];
        char *key = key_val->key;
        char *value = key_val->value;
        printf("%s : %s\n", key, value);
    }
    return cweb_send_text("Hello World", 200);
    
}

CWEB_START_MACRO(5001, main_sever);
~~~


## UrlEncode Parameters
Cweb Studio also supports url parameter encoding. To do so, call the method 
**request->read_content** to parse the body: 
<!--codeof:examples/url_encoded_paramns.c-->
~~~c

#include "CWebStudio.h"

CwebHttpResponse *main_sever(CwebHttpRequest *request ){
    request->read_content(request, 20000);
    CwebDict *query_paramns = request->params;
    for(int i = 0; i < query_paramns->size; i++){
        CwebKeyVal *key_val = query_paramns->keys_vals[i];
        char *key = key_val->key;
        char *value = key_val->value;
        printf("%s : %s\n", key, value);
    }
    return cweb_send_text("Hello World", 200);
    
}

CWEB_START_MACRO(5001, main_sever);
~~~


## Iterating Headers

Similar to iterating through URL parameters, iterating through headers is equally as simple:
<!--codeof:examples/iterating_over_headers.c-->
~~~c


#include "CWebStudio.h"
 CwebHttpResponse *main_sever( CwebHttpRequest *request ){

     CwebDict *headers = request->headers;
    for(int i = 0; i < headers->size; i++){
        struct CwebKeyVal *key_val = headers->keys_vals[i];
        char *key = key_val->key;
        char *value = key_val->value;
        printf("%s : %s\n", key, value);
    }
    return cweb_send_text("Hello World", 200);
    
}

CWEB_START_MACRO(5001, main_sever);
~~~

## Reading Body Content 
Accessing the body content may be done by calling the function **request->read_content**.
The content will be accessible with **request->content** and **request->content_length**:
<!--codeof:examples/reading_body_content.c-->
~~~c
#include "CWebStudio.h"

 CwebHttpResponse *main_sever( CwebHttpRequest *request ){
    int one_mega_byte = 1048576;
    request->read_content(request, one_mega_byte);
    unsigned char *body = request->content;
    int size = request->content_length;

    printf("body: %s",body);

    return cweb_send_text("Hello World", 200);
    
}

CWEB_START_MACRO(5001, main_sever);
~~~
## Parsing JSON 
CwebStudio has cJSON integrated into the library. For more information, see 
https://github.com/DaveGamble/cJSON.
<!--codeof:examples/parsing_body_json.c-->
~~~c
#include "CWebStudio.h"

CwebHttpResponse *main_sever( CwebHttpRequest *request ){
    int one_mega_byte = 1048576;
    request->read_content(request, one_mega_byte);
    unsigned char *body = request->content;
    int size = request->content_length;

    //parse with cJson the body 

    cJSON *json = cJSON_Parse(body);
    cJSON *name = cJSON_GetObjectItemCaseSensitive(json, "name");
    cJSON *age = cJSON_GetObjectItemCaseSensitive(json, "age");


    printf("Name: %s\n", name->valuestring);
    printf("Age: %d\n", age->valueint);


    return cweb_send_text("Hello World", 200);
    
}

CWEB_START_MACRO(5001, main_sever);
~~~

## Reading Binary Content
<!--codeof:examples/reading_binary_content.c-->
~~~c
#include "CWebStudio.h"

void write_binary_file(char *path, unsigned char *content, int size)
{
    FILE *file = fopen(path, "wb");
    fwrite(content, sizeof(unsigned char), size, file);
    fclose(file);
}


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    int two_mega_bytes = 2097152;
    request->read_content(request, two_mega_bytes);
    unsigned char *body = request->content;
    char *name = request->get_param(request, "name");
    int size = request->content_length;

    write_binary_file(name, body, size);

    return cweb_send_text("File Written", 200);
    
}

CWEB_START_MACRO(5001, main_sever);
~~~

# Returning Values
## Plain Text
Returning plain text is simple with **cweb_send_text**:
<!--codeof:examples/returning_plain_text.c-->
~~~c
#include "CWebStudio.h"

CwebHttpResponse *main_sever(CwebHttpRequest *request ){


    return cweb_send_text("Exemple of Return", 200);
    
}

CWEB_START_MACRO(5001, main_sever);
~~~
**cweb_send_text_cleaning_memory** can handle strings:
<!--codeof:examples/returning_text_cleaning_memory.c-->
~~~c
#include "CWebStudio.h"

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    char *teste = malloc(100);
    strcpy(teste, "Hello World");
    return cweb_send_text_cleaning_memory(teste,200);
}

CWEB_START_MACRO(5000, main_sever)
~~~

## Rendered HTML 
To return rendered HTML, the function **cweb_send_rendered_CTextStack_cleaning_memory** may be used. Memory will be automatically cleaned:

see more at https://github.com/OUIsolutions/CTextEngine
<!--codeof:examples/rendering_html.c-->
~~~c
#include "CWebStudio.h"


 CwebHttpResponse *main_sever( CwebHttpRequest *request ){
    const char *lang = "en";
    const char *text = "text exemple";
    CTextStackModule m = newCTextStackModule();
    CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);


    m.$open(s,CTEXT_HTML,"lang=\"%s\"",lang);
        m.open(s,CTEXT_HEAD);

        m.close(s,CTEXT_HEAD);
        m.open(s,CTEXT_BODY);
            m.open(s,CTEXT_H1);
                m.segment_text(s,"This is a text");
            m.close(s,CTEXT_H1);
            m.open(s,CTEXT_P);
                m.segment_format(s,"This is a formated  text  %s",text);
            m.close(s,CTEXT_P);

        m.close(s,CTEXT_BODY);
    m.close(s,CTEXT_HTML);
    return cweb_send_rendered_CTextStack_cleaning_memory(s,200);
}

CWEB_START_MACRO(5000, main_sever)

~~~

## HTML
To generate HTML from a file, the **cweb_send_var_html** function may be used:
<!--codeof:examples/returing_var_html.c-->
~~~c
#include "CWebStudio.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    char *html = "<html><body><h1>Hello World</h1></body></html>";
    return cweb_send_var_html(html,200);
}

CWEB_START_MACRO(5000, main_sever)
~~~
As is done with returning plain text, memory will be automatically cleaned with **cweb_send_var_html_cleaning_memory**: 
<!--codeof:examples/returning_var_html_cleaning_memory.c-->
~~~c
#include "CWebStudio.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    char *html = malloc(1000);
    strcat(html, "<html><body><h1>Hello World</h1></body></html>");
    return cweb_send_var_html_cleaning_memory(html,200);
}

CWEB_START_MACRO(5000, main_sever)

~~~

## Other Formats 
Other formats may be returned like this: 
<!--codeof:examples/sending_json.c-->
~~~c

#include "CWebStudio.h"

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    char *json = "{\"name\":\"CWebStudio\",\"version\":\"1.0.0\"}";
    return cweb_send_any(
        "application/json",
        strlen(json),
        json,
        200
    );
    
}

CWEB_START_MACRO(5001, main_sever);
~~~
## Returning Files 
Files can be directly returned by referencing the path:
<!--codeof:examples/returning_files.c-->
~~~c
#include "CWebStudio.h"

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    return cweb_send_file(
        "my_image.png",
        CWEB_AUTO_SET_CONTENT,
        200
    );
    
}

CWEB_START_MACRO(5001, main_sever);
~~~

### Static Files
Static files (javascript/css/html) can be referenced and returned in the static directory:


~~~html

    <img src="/static/captura2.png">
~~~
#### Custom Error Pages
To return a custom error page, place the <error_code>.html in the static directory. Creating a 500.html into the static directory, for example, will return this page when a 500 error occurs.

#### Smart Cache
Dynamic caching may be used inside HTML by using smart_cache:
~~~html
    <img src="smart-cache='file.png'">
~~~
#### Smart Cache in Rendered Text
Smart caching with rendered text can be done with **smart_static_ref**:
<!--codeof:examples/smart_cache_inside_rendered_text.c-->
~~~c
#include "CWebStudio.h"

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    const char *lang = "en";
    const char *text = "text exemple";
    CTextStackModule  m = newCTextStackModule();
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    m.$open(s,CTEXT_HTML,"lang=\"%s\"",lang);
        m.open(s,CTEXT_HEAD);
            
            char *fav_icon_link = smart_static_ref("favicon.ico");
            m.auto$close(s,CTEXT_LINK,"rel=\"shortcut icon\" href=\"%s\"",fav_icon_link);
            free(fav_icon_link);

        m.close(s,CTEXT_HEAD);
        m.open(s,CTEXT_BODY);
            
            char *img_link = smart_static_ref("my_image.png");
            m.auto$close(s,CTEXT_IMG,"src=\"%s\" width=\"200px\"",img_link);
            free(img_link);

        m.close(s,CTEXT_BODY);
    m.close(s,CTEXT_HTML);
    return cweb_send_rendered_CTextStack_cleaning_memory(s,200);
    
}
CWEB_START_MACRO(5000,main_sever)
~~~



## CWEB_NO_CACHE
When the **CWEB_NO_CACHE** flag is passed to the browser, static data will not be cached.

## CWEB_DEBUG FLAG
**CWEB_DEBUG** will provide useful debugging information:
<!--codeof:examples/cweb_debug.c-->
~~~c

#define CWEB_DEBUG
#include "CWebStudio.h"
CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    return cweb_send_text("Hello World", 200);
    
}

CWEB_START_MACRO(5001, main_sever);
~~~

# CWEB_ONCE

This flag will execute only one function call at a time. It is useful for debugging with valgrind and other memory tools:
<!--codeof:examples/cweb_once.c-->
~~~c
#define CWEB_ONCE
#include "CWebStudio.h"


CwebHttpResponse *main_sever(CwebHttpRequest *request ){
    
    return cweb_send_text("Hello World", 200);
    
}

int main(){
    struct CwebServer *sever = newCwebSever(3001, main_sever);
    sever->single_process = CWEB_DANGEROUS_SINGLE_PROCESS;
    sever->start(sever);
    sever->free(sever);
    return 0;
}
~~~

## Sever Configuration Parameters 

Several server configuration parameters may be set:
<!--codeof:examples/server_paramns.c-->
~~~c

#include "CWebStudio.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    
    return cweb_send_text("Hello World", 200);
    
}

int main(){
    struct CwebServer *sever = newCwebSever(3001, main_sever);
    //the higher time of the request handler 
    //after that , the sever will return 500 
    // these is useful to prevent the server infinite loop
    sever->function_timeout = 30;
    //the higher time of the client
    //after that , the sever will return 408
    //these is useful to prevent invalid requests
    sever->client_timeout = 5;

    //the max queue of the server
    sever->max_queue = 100;
    //if true , the server will run in single process
    sever->single_process = false;
    //the max simultaneous requests
    sever->max_requests = 1000;
    //if true , the server will use the static files located into the folder "static"
    sever->use_static = true;

    sever->start(sever);
    sever->free(sever);
    return 0;
}
~~~


# Used Dependencies And Atributions
DoTheWorld includes all self dependecies in the single file. If one of these libraries is used in your code, be mindful of circular imports.

## CJson<br><br>
**CJson**: from https://github.com/DaveGamble/cJSON <br>
Copyright (c) 2009-2017 Dave Gamble and cJSON contributors

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

## sha-256 <br>
**sha-256**: from https://github.com/amosnier/sha-2 <br>

Zero Clause BSD License
© 2021 Alain Mosnier

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.


## CTextEngine 
**CtextEngine**: from https://github.com/OUIsolutions/CTextEngine <br>

MIT License

Copyright (c) 2023 OUI

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