
# CWebSudio
CWebSudio is a micro framework to deal with web aplications in C/C++. It's a
single header library that provides a lot of functionality such as reading headers,
query parameters, returning files, and text.

# Installation

## Single File
CWebSudio is made to be as dumb as possible and adopt the idea of single file library.
For installation, simply copy the **CWebStudio.h** into your project and compile with gcc/g++ or clang.

[Download Link](https://github.com/OUIsolutions/CWebStudio/releases/download/v123/CWebStudio.h)

~~~c
#include "CWebStudio.h"
CwebNamespace cweb;

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    return cweb.response.send_text("Hello World", 200);

}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    struct CwebServer server = newCwebSever(5000, main_sever);
    cweb.server.start(&server);
    return 0;
}
~~~

The Source Code its available here:
[Source](https://github.com/OUIsolutions/CWebStudio)
## Full Folder
You can also download the entire **CwebStudio** folder to your project and run with the

**#include "src/one.c"** header:

~~~c
#include "src/one.c"
CwebNamespace cweb;

CwebHttpResponse *main_sever(CwebHttpRequest *request ){


    return cweb.response.send_text("Hello World", 200);

}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    struct CwebServer server = newCwebSever(5000, main_sever);
    cweb.server.start(&server);
    return 0;
}
~~~



# Getting Entries

## Route a Method

Working with URL parameters is very easy, as seen in the following example:
codeof:  examples/route_and_method.c


## Getting Query param

for getting query params its super easy, just use the **cweb.request.get_param** function
codeof:  examples/getting_parrams.c



## Iterating over Query Parameters

To iterate through parameters, the object **CwebDict** may be used like this:
codeof:  examples/iterating_over_query_paramns.c

## UrlEncode Parameters
Cweb Studio also supports url parameter encoding. To do so, call the method
**request->read_content** to parse the body:

codeof: examples/url_encoded_paramns.c


## Getting Headders
for retriving headers use the **cweb.request.get_header** function

codeof: examples/getting_headers.c

## Iterating over Headers

Similar to iterating through URL parameters, iterating through headers is equally as simple:
codeof: examples/iterating_over_headers.c


## Reading Body Content
Accessing the body content may be done by calling the function **request->read_content**.
The content will be accessible with **request->content** and **request->content_length**:
codeof: examples/reading_body_content.c

## Parsing JSON
CwebStudio has cJSON integrated into the library. For more information, see
https://github.com/DaveGamble/cJSON.

codeof: examples/parsing_body_json.c

## Returning Json from cJSON
if you want to return values from cJSON, you can call the **cweb.response.send_cJSON_cleaning_memory** or
**cweb.response.send_cJSON** to return cjson values
codeof: examples/returning_cjson.c

codeof: examples/sending_json.c


## Reading Binary Content
codeof: examples/reading_binary_content.c

# Returning Values
## Plain Text
Returning plain text is simple with **cweb_send_text**:
codeof: examples/returning_plain_text.c

**cweb_send_text_cleaning_memory** can handle strings:
codeof: examples/returning_text_cleaning_memory.c

## Rendered HTML
To return rendered HTML, the function **cweb_send_rendered_CTextStack_cleaning_memory** may be used. Memory will be automatically cleaned:

see more at https://github.com/OUIsolutions/CTextEngine
codeof: examples/rendering_html.c

## HTML
To generate HTML from a file, the **cweb_send_var_html** function may be used:
codeof: examples/returing_var_html.c

As is done with returning plain text, memory will be automatically cleaned with **cweb_send_var_html_cleaning_memory**:

codeof: examples/returning_var_html_cleaning_memory.c

## Returning Files
Files can be directly returned by referencing the path:
codeof: examples/returning_files.c

## Returning Other Formats
Other formats may be returned like this:
codeof: examples/returning_any.c



### Static Files
Static files (javascript/css/html) can be referenced and returned in the static directory:

~~~html

    <img src="/static/captura2.png">
~~~
### Especial Static Files

#### static/favicon.(jpg|png|ico)
if you put a  **static/favico.jpg** or   **static/favico.png** or   **static/favico.ico**
into yur static folder, it will automatic became the favicon
#### static/404.html
if you put an **static/400.html** into your static file, it will be used when an 404 error happen

#### static/500.html
if you put an **static/400.html** into your static file, it will be used when an internal error happen


#### Custom Error Pages
To return a custom error page, place the <error_code>.html in the static directory. Creating a 500.html into the static directory, for example, will return this page when a 500 error occurs.

#### Smart Cache
Dynamic caching may be used inside HTML by using smart_cache:
~~~html
    <img src="smart-cache='file.png'">
~~~

#### Inline inclusion
Its also possible to generate inline inclusion with:
~~~html
    <div>
        inline-include='static/teste3.html'
    </div>

~~~

#### Smart Cache in Rendered Text
Smart caching with rendered text can be done with **private_cweb_smart_static_ref**:
codeof: examples/smart_cache_inside_rendered_text.c


## CWEB_DEBUG FLAG
**CWEB_DEBUG** will provide useful debugging information:
codeof: examples/cweb_debug.c

# KIlling the server

if you want to kill the server for any reason, like testing memory leaks or finish the server
you can just change the var **cweb_end_server** to true
codeof: examples/kill.c

# Configuring The Server
Several server configuration parameters may be set:
codeof:  examples/server_paramns.c


# HyDration
The HyDration mechanic it's a mecanic to generate front end code in C, its based on the ideia
of controling the browser by creating javascript

codeof:  examples/hydration_helloworld.c

# HyDration Explanation
The HyDration its divided in 3 steps , first , you create the bridges, which its
the functions to be called when some event get dispached, than you need to specify which elements
the requirements the browser must return to thatfunction, it can be a html element, a session element
etc, than the the bridge callback handler its called, and the server returns to the browser, what actions
must be made

![Hydration](graphics/images/hydration.jpg)


# Search Requirements
Search Requirements, its where you specify which elements the browser must return to the bridge lambda

```c

CWebHyDrationBridge * alert_bridge = bridge_module.create_bridge(
    hydration,
    ALERT_BRIDGE,
    alert_bridge_callback
);

CWebHyDrationSearchRequirements *name =
requirements.newSearchRequirements(alert_bridge,"name");
requirements.add_elements_by_id(name,"name");

```
# Search Result
SearchResult are  the objects  used to retrive the informations sended by the
browser, defined in the search requirements

```c
CWebHyDrationSearchResult * name = result_module.get_search_by_name(bridge,"name");
char *first_result_of_name = result_module.get_string(name,0);
```

# Actions
The Actions its the actions that you want to be executed in the browser, it can be a alert
a javascript execution, a  element to add/replace/destroy

```c
actions.alert(bridge,"hello %s",first_result_of_name);
```

## Full Runalble exemplo
codeof:  examples/hydration_getting_a_entrie.c


## ShortCuts
you also can use shortcuts, to set the search requirements as the same name of the
id/class that you want to find

codeof:  examples/hydration_getting_a_entrie_shor.c

where you can use **get_string_from_first_element_of_search** to retrive the first element of the search

```c
char *first_result_of_name = result_module.get_string_from_first_element_of_search(bridge,"name");
```
or **add_elements_by_id_setting_search_as_same_name** to create a requirements with same name of the id/class
element

```c
requirements.add_elements_by_id_setting_search_as_same_name(alert_bridge,"name");
```

## Handling Numbers
you also can handle numbers, because the system will autoconvert all elements , unless you specify with the **not_auto_convert**
sulfix in functions requirements


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
