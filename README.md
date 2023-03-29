# CWebSudio 
CWebSudio  its a micro framework to deal with web aplications in C/C++ , its an 
single header library and provides a lot of funcionalitys , like readding headders
query paramns, returning files and text.

# Instalation 

## Single File
CWebSudio is made to be as dumb as possible, and adopt the idea of single file lib,
for instalation you can just copy the **CWebStudio.c** into your project, and execute an normal copilation with gcc/g++ or clang 

~~~c

#include "CWebStudio.c"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    return cweb_send_text("Hello World", 200);
}

int main(){

   cweb_run_server(5000, main_sever); 

   return 0;
}
~~~
## Full Folder 
or you can download the entier **CWebStudio** folder to your project and run with 
**#include "CWebStudio/CwebStudioMain.c"** header
~~~c

#include "CWebStudio/CwebStudioMain.c"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    return cweb_send_text("Hello World", 200);
}

int main(){

   cweb_run_server(5000, main_sever); 

   return 0;
}
~~~

# Getting Entrys

## Route an Method

for getting the "url" paramns , its very easy, follow the program above 

~~~c

#include "CWebStudio.c"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    char *url = request->url;
    char *method = request->method;
    char *route = request->route;

    printf("URL: %s\n", url);
    printf("Method: %s\n", method);
    printf("Route: %s\n", route);
    return cweb_send_text("Hello World", 200);
    
}

int main(){

   cweb_run_server(5000, main_sever); 

   return 0;
}
~~~
## Iterating over query Paramns 

for iterating over paramns, you can use the object **CwebDict** , note that
even urlencoded is consider as paramn, so you dont need to care about it 

~~~c



#include "CWebStudio.c"


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

int main(){

   cweb_run_server(5000, main_sever); 

   return 0;
}
~~~

## Iterating over Headders

The same way as iterating over paramns, iterate over headers still simple
~~~c



#include "CWebStudio.c"
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

int main(){

   cweb_run_server(5000, main_sever); 

   return 0;
}
~~~

## Reading body Content 
you can acess the body content in these way 

~~~c
#include "CWebStudio.c"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    unsigned char *body = request->content;
    int size = request->content_length;

    printf("body: %s",body);

    return cweb_send_text("Hello World", 200);
    
}

int main(){

   cweb_run_server(5000, main_sever); 

   return 0;
}
~~~

or even wth binary files 

~~~c

#include "CWebStudio.c"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    unsigned char *body = request->content;
    int size = request->content_length;

    dtw_write_any_content("test.png", body, size);

    return cweb_send_text("Hello World", 200);
    
}

int main(){

   cweb_run_server(5000, main_sever); 

   return 0;
}
~~~

# Returning Values