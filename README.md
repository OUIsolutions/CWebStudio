# CWebSudio 
CWebSudio  its a micro framework to deal with web aplications in C/C++ , its an 
single header library and provides a lot of funcionalitys , like readding headders
query paramns, returning files and text.

# Instalation 

## Single File
CWebSudio is made to be as dumb as possible, and adopt the idea of single file lib,
for instalation you can just copy the **CWebStudio.c** into your project, and start using 

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