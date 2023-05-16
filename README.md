# CWebSudio 
CWebSudio  its a micro framework to deal with web aplications in C/C++ , its an 
single header library and provides a lot of funcionalitys , like readding headders
query paramns, returning files and text.

# Instalation 

## Single File
CWebSudio is made to be as dumb as possible, and adopt the idea of single file lib,
for instalation you can just copy the **CWebStudio.h** into your project, and execute an normal copilation with gcc/g++ or clang 

~~~c

#include "CWebStudio.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    return cweb_send_text("Hello World", 200);
}

CWEB_START_MACRO(5001, main_sever);
~~~
## Full Folder 
or you can download the entier **CWebStudio** folder to your project and run with 
**#include "CWebStudio/CwebStudioMain.h"** header
~~~c

#include "CWebStudio/CwebStudioMain.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    return cweb_send_text("Hello World", 200);
}

CWEB_START_MACRO(5001, main_sever);
~~~
# Runing with Main
if you need to make, main configurations before run the sever, you can run the function **cweb_run_server** without an macro , like these 

~~~c

#include "CWebStudio.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    return cweb_send_text("Hello World", 200);
}

int main(int argc, char *argv[]){

   
     struct CwebSever *sever = newCwebSever(5000, main_sever);
     sever->start(sever);
     sever->free(sever);
}
~~~


# Getting Entrys

## Route an Method

for getting the "url" paramns , its very easy, follow the program above 

~~~c

#include "CWebStudio.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

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
## Iterating over query Paramns 

for iterating over paramns, you can use the object **CwebDict** 
~~~c

#include "CWebStudio.h"


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    struct CwebDict *query_paramns = request->params;
    for(int i = 0; i < query_paramns->size; i++){
        struct CwebKeyVal *key_val = query_paramns->keys_vals[i];
        char *key = key_val->key;
        char *value = key_val->value;
        printf("%s : %s\n", key, value);
    }
    return cweb_send_text("Hello World", 200);
    
}

CWEB_START_MACRO(5000, main_sever);
~~~


## UrlEncode Paramns
Cweb Studio also suport url encode paramns, but you need to call the method 
** request->read_content** for parsing the body 
~~~c

#include "CWebStudio.h"


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    request->read_content(request, 20000);
    struct CwebDict *query_paramns = request->params;
    for(int i = 0; i < query_paramns->size; i++){
        struct CwebKeyVal *key_val = query_paramns->keys_vals[i];
        char *key = key_val->key;
        char *value = key_val->value;
        printf("%s : %s\n", key, value);
    }
    return cweb_send_text("Hello World", 200);
    
}

CWEB_START_MACRO(5001, main_sever);
~~~


## Iterating over Headders

The same way as iterating over paramns, iterate over headers still simple
~~~c



#include "CWebStudio.h"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    struct CwebDict *headers = request->headers;
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

## Reading body Content 
you can acess the body content by calling the function **request->read_content**
after it , it would be acessible by the **request->content** and **request->content_length**

~~~c
#include "CWebStudio.h"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    int one_mega_byte = 1048576;
    request->read_content(request, one_mega_byte);
    unsigned char *body = request->content;
    int size = request->content_length;

    printf("body: %s",body);

    return cweb_send_text("Hello World", 200);
    
}

CWEB_START_MACRO(5001, main_sever);
~~~
## Parsing Body Json 
CwebStudio has cJSON integrated into the lib , for more informations read in 
https://github.com/DaveGamble/cJSON

~~~c
#include "CWebStudio.h"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
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

## Reading binary Content

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
For returning plain text , you can return with the function  
**cweb_send_text** 

~~~c

#include "CWebStudio.h"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){


    return cweb_send_text("Exemple of Return", 200);
    
}

CWEB_START_MACRO(5001, main_sever);
~~~
Or if you have memory alocated in string, dont worry, just call 
**cweb_send_text_cleaning_memory**
~~~c
#include "CWebStudio.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    char *teste = malloc(100);
    strcpy(teste, "Hello World");
    return cweb_send_text_cleaning_memory(teste,200);
}

CWEB_START_MACRO(5000, main_sever)


~~~

## Rendered Html 
If you want to return a rendered html, you can use the function 
**cweb_send_rendered_CTextStack_cleaning_memory**, dont worry about cleaning memory, the function
will do it for you .
see more at : https://github.com/OUIsolutions/CTextEngine
~~~c

#include "CWebStudio/CwebStudioMain.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    const char *lang = "en";
    const char *text = "text exemple";
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);


    s->$open(s,HTML,"lang=\"%s\"",lang);
        s->open(s,HEAD);
     
        s->close(s,HEAD);
        s->open(s,BODY);
            s->open(s,H1);
                s->segment_text(s,"This is a text");
            s->close(s,H1);
            s->open(s,P);
                s->segment_format(s,"This is a formated  text  %s",text);
            s->close(s,P);

        s->close(s,BODY);
    s->close(s,HTML);
    return cweb_send_rendered_CTextStack_cleaning_memory(s,200);
}

CWEB_START_MACRO(5000, main_sever)


~~~

## HTML
if you want to generate html from file from scratch , you can call
**cweb_send_var_html** function
~~~c

#include "CWebStudio.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    char *html = "<html><body><h1>Hello World</h1></body></html>";
    return cweb_send_var_html(html,200);
}

CWEB_START_MACRO(5000, main_sever)

~~~
as the  same as plain text , you can call cleaning memory too 

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
You can return other formats like these 
~~~c

#include "CWebStudio.h"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

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
if you know the path of your file , you can directly send files 

~~~c

#include "CWebStudio.h"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    return cweb_send_file(
        "my_image.png",
        CWEB_AUTO_SET_CONTENT,
        200
    );
    
}

CWEB_START_MACRO(5001, main_sever);
~~~

### Static File
if you want to return an static file (javascript/css/html) you can put everything
on the static file , and will automaticly sended 


~~~html

    <img src="/static/captura2.png">
~~~
#### static error codes
if you put an file called 500.html into the static folder it will return these 
file,when happen an 500 error


#### path 
if you put an query param called path , into the /static route, it will understand these
as the path of the folder
~~~html
    <img src="/static?path=static/captura2.png">
~~~





## An Low level aproach 
if you want to make an custon http response , you can construct the struct buy yourself 
~~~c

#include "CWebStudio.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    int out_size;
    unsigned char *content = dtw_load_binary_content("my_image.png", &out_size);
    struct CwebHttpResponse *response = create_http_response();
    response->add_header(response, "Content-Type", "image/png");
    response->set_content(response, content, out_size);
    return response;
    


}  

CWEB_START_MACRO(5001, main_sever);

~~~


## CWEB_DEBUG FLAG
with cweb debug Flag, it will print stages of aplications , like requests, and each stages 
~~~c 

#define CWEB_DEBUG
#include "CWebStudio.h"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    return cweb_send_text("Hello World", 200);
    
}

CWEB_START_MACRO(5001, main_sever);
~~~

# CWEB_ONCE

use these flag to execute the function only one time, it will be usefull for
valgrind and other memory tools

~~~c
#define CWEB_ONCE
#include "CWebStudio.h"


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    
    return cweb_send_text("Hello World", 200);
    
}

int main(){
    struct CwebSever *sever = newCwebSever(3001, main_sever);
    sever->single_process = CWEB_DANGEROUS_SINGLE_PROCESS;
    sever->start(sever);
    sever->free(sever);
    return 0;
}
~~~

## Sever Paramns 

You can use a lot of paramns into the sever for defining diferent comportaments 

~~~c

#include "CWebStudio.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    
    return cweb_send_text("Hello World", 200);
    
}

int main(){
    struct CwebSever *sever = newCwebSever(3001, main_sever);
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
DoTheWorld includes all self dependecies in the single file, so you dont need to care about it, but if you will use one of these librarys, dont include it in your code to avoid circular imports

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