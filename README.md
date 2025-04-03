
# CWebSudio
CWebSudio is a micro framework to deal with web aplications in C/C++. It's a
single file library that provides a lot of functionality such as reading headers,
query parameters, returning files, and text.

# Releases
| Item | Description |
|------|-------------|
|[CWebStudioOne.c](https://github.com/OUIsolutions/CWebStudio/releases/download/4.0.0/CWebStudioOne.c)| CWebStudio One file |
|[CWebStudio.c](https://github.com/OUIsolutions/CWebStudio/releases/download/4.0.0/CWebStudio.c)| Definition|
|[CWebStudio.h](https://github.com/OUIsolutions/CWebStudio/releases/download/4.0.0/CWebStudio.h)| Header|
|[CWebStudio.zip](https://github.com/OUIsolutions/CWebStudio/releases/download/4.0.0/CWebStudio.zip)| Full Folder that can be included with **src/one.c**|

## Most Simple Example

~~~c

#include "CWebStudioOne.c"
CwebNamespace cweb;

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    return cweb_send_text("Hello World", 200);
}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    CwebServer server = newCwebSever(5000, main_sever);
    cweb.server.start(&server);
    return 0;
}
~~~
# Documentation

| File | Description |
|------|-------------|
|[build_and_install.md](docs/build_and_install.md)| Explains how to build and install CWebStudio |
| [route_method.md](docs/route_method.md) | Explains how to work with URL parameters |
| [getting_query_param.md](docs/getting_query_param.md) | Shows how to retrieve query parameters |
| [iterating_query_params.md](docs/iterating_query_params.md) | Demonstrates iterating through query parameters |
| [url_encode_params.md](docs/url_encode_params.md) | Explains how to parse URL encoded parameters |
| [getting_headers.md](docs/getting_headers.md) | Shows how to retrieve headers |
| [iterating_headers.md](docs/iterating_headers.md) | Demonstrates iterating through headers |
| [reading_body_content.md](docs/reading_body_content.md) | Explains how to read the body content of a request |
| [parsing_json.md](docs/parsing_json.md) | Shows how to parse JSON data from the request body |
| [returning_json_from_cjson.md](docs/returning_json_from_cjson.md) | Demonstrates returning JSON objects created with cJSON |
| [reading_binary_content.md](docs/reading_binary_content.md) | Explains how to read binary content from the request |
| [returning_values_plain_text.md](docs/returning_values_plain_text.md) | Shows how to return plain text responses |
| [returning_values_rendered_html.md](docs/returning_values_rendered_html.md) | Demonstrates returning rendered HTML using CTextStack |
| [returning_values_html.md](docs/returning_values_html.md) | Shows how to return HTML responses |
| [returning_values_files.md](docs/returning_values_files.md) | Explains how to return files directly from the server |
| [returning_values_other_formats.md](docs/returning_values_other_formats.md) | Demonstrates returning content in other formats |
| [static_files.md](docs/static_files.md) | Explains how to handle static files and use smart caching |
| [cweb_debug_flag.md](docs/cweb_debug_flag.md) | Shows how to enable debugging with the CWEB_DEBUG flag |
| [killing_the_server.md](docs/killing_the_server.md) | Explains how to kill the server using the cweb_kill_single_process_server function |
| [configuring_the_server.md](docs/configuring_the_server.md) | Demonstrates how to configure various server parameters |
| [hydration.md](docs/hydration.md) | Introduces the HyDration mechanic for generating front-end code in C |
| [hydration_explanation.md](docs/hydration_explanation.md) | Explains the three steps of HyDration |
| [hydration_full_runnable_example.md](docs/hydration_full_runnable_example.md) | Provides a full runnable example of using HyDration |
| [hydration_search_result.md](docs/hydration_search_result.md) | Shows how to retrieve search results from the browser |
| [hydration_search_requirements.md](docs/hydration_search_requirements.md) | Explains how to set up search requirements for a bridge |
| [hydration_actions.md](docs/hydration_actions.md) | Demonstrates how to execute actions in the browser |
| [hydration_shortcuts.md](docs/hydration_shortcuts.md) | Shows how to use shortcuts in HyDration |
| [hydration_handling_args.md](docs/hydration_handling_args.md) | Explains how to pass arguments between bridges |
| [hydration_handling_numbers.md](docs/hydration_handling_numbers.md) | Demonstrates how to handle numbers in HyDration |
|[dependencies.md](docs/dependencies.md)| Lists the dependencies required for CWebStudio |

