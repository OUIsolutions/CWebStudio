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

CWEB_START_MACRO(5001, main_sever);
~~~
## Full Folder 
or you can download the entier **CWebStudio** folder to your project and run with 
**#include "CWebStudio/CwebStudioMain.c"** header
~~~c

#include "CWebStudio/CwebStudioMain.c"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    return cweb_send_text("Hello World", 200);
}

CWEB_START_MACRO(5001, main_sever);
~~~
# Runing with Main
if you need to make, main configurations before run the sever, you can run the function **cweb_run_server** without an macro , like these 




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

CWEB_START_MACRO(5001, main_sever);
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

CWEB_START_MACRO(5001, main_sever);
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

CWEB_START_MACRO(5001, main_sever);
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

CWEB_START_MACRO(5001, main_sever);
~~~
## Parsing Body Json 
~~~c
#include "CWebStudio.c"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

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

#include "CWebStudio.c"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    unsigned char *body = request->content;
    int size = request->content_length;

    dtw_write_any_content("test.png", body, size);

    return cweb_send_text("Hello World", 200);
    
}

CWEB_START_MACRO(5001, main_sever);
~~~

# Returning Values
## Plain Text
For returning plain text , you can return with the function  
**cweb_send_text** 

~~~c

#include "CWebStudio.c"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){


    return cweb_send_text("Exemple of Return", 200);
    
}

CWEB_START_MACRO(5001, main_sever);
~~~

## Other Formats 
You can return other formats like these 
~~~c

#include "CWebStudio.c"
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

#include "CWebStudio.c"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    return cweb_send_file(
        "my_image.png",
        CWEB_AUTO_SET_CONTENT,
        200
    );
    
}

CWEB_START_MACRO(5001, main_sever);
~~~

## An Low level aproach 
if you want to make an custon http response , you can construct the struct buy yourself 
~~~c

#include "CWebStudio.c"

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
#include "CWebStudio.c"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    return cweb_send_text("Hello World", 200);
    
}

CWEB_START_MACRO(5001, main_sever);
~~~
# Paramns 
With Paramns Flags you can define comportaments of the sever, each flags define one atributes<br>


### Single Processo
<b style="color:red;">DONT USE THESE FLAG IF YOU DONT NEED </b><br>
the single process param will execute your code in an single process, and if happen some 
error, your aplicantion will crash, so, if you will use these flag, ensure that there is no error on your aplication, and use only if you are on an embed system that dont allow multprocess

~~~c
#define CWEB_DEBUG
#include "CWebStudio.c"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    if(strcmp(request->route, "/test") == 0){
        ///making an error
        int x = 1/0;
        //Your application will crash here if you are using single process
        //because the error is not handled
    }
    return cweb_send_text("Hello World", 200);

}

int main(){
    cweb_run_server(
            5000,
            main_sever,
            CWEB_DEFAULT_TIMEOUT,
            CWEB_DEFAULT_MAX_BODY,
            CWEB_DANGEROUS_SINGLE_PROCESS
            );
}
~~~

If you dont need , is higly recomended you use the safify mode 

~~~c 
#define CWEB_DEBUG
#include "CWebStudio.c"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    if(strcmp(request->route, "/test") == 0){
        ///making an error
        int x = 1/0;
        //Your application wont crash here if you are using safity mode
    }
    return cweb_send_text("Hello World", 200);

}

int main(){
    cweb_run_server(
            5000,
            main_sever,
            CWEB_DEFAULT_TIMEOUT,
            CWEB_DEFAULT_MAX_BODY,
            CWEB_SAFTY_MODE
    );
}
~~~
### Timeout 
you can set the max timeout your aplication will deal, if is the function takes more 
than that time , the sever will return 500, the default time its 30 seconds
~~~c 
#define CWEB_DEBUG
#include "CWebStudio.c"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    return cweb_send_text("Hello World", 200);

}

int main(){
    int timeout = 2;
    cweb_run_server(
            5000,
            main_sever,
            timeout,
            CWEB_DEFAULT_MAX_BODY,
            CWEB_SAFTY_MODE
    );
}
~~~

### max body size
You can set the max body size, the defaults is 10485760 bytes ,witch is equivalent 
to 10mb if an request were more than that value, the aplication will return 400 error

~~~c


#define CWEB_DEBUG
#include "CWebStudio.c"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

return cweb_send_text("Hello World", 200);

}

int main(){
    size_t max_size = 2000;
    cweb_run_server(
        5000,
        main_sever,
        CWEB_DEFAULT_TIMEOUT,
        max_size,
        CWEB_SAFTY_MODE
    );
}
~~~