# <img src="https://raw.githubusercontent.com/OUIsolutions/CWebStudio/main/graphics/images/logo.png" alt="CWebStudio" height="40"> CWebStudio

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![Version: 4.0.0](https://img.shields.io/badge/Version-4.0.0-brightgreen.svg)](https://github.com/OUIsolutions/CWebStudio/releases/tag/4.0.0)
[![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20macOS%20%7C%20Windows-lightgrey.svg)](https://github.com/OUIsolutions/CWebStudio)

## 📋 Overview

CWebStudio is a high-performance framework for building web applications in C/C++. Designed to be lightweight and efficient, it provides a single-file library that simplifies common web development tasks. With CWebStudio, you can:

- ✅ Handle HTTP requests and responses with ease
- ✅ Parse and generate JSON data
- ✅ Manage static files with smart caching
- ✅ Generate dynamic front-end code with the innovative HyDration mechanic

Whether you're building a simple API or a complex web application, CWebStudio offers the tools you need to get started quickly and efficiently.

## 📦 Downloads

| Component | Description |
|-----------|-------------|
| [![Single File](https://img.shields.io/badge/Single%20File-CWebStudioOne.c-orange.svg)](https://github.com/OUIsolutions/CWebStudio/releases/download/4.0.0/CWebStudioOne.c) | Complete library in a single file |
| [![Source](https://img.shields.io/badge/Source-CWebStudio.c-blue.svg)](https://github.com/OUIsolutions/CWebStudio/releases/download/4.0.0/CWebStudio.c) | Implementation file |
| [![Header](https://img.shields.io/badge/Header-CWebStudio.h-blue.svg)](https://github.com/OUIsolutions/CWebStudio/releases/download/4.0.0/CWebStudio.h) | Header file |
| [![Full Package](https://img.shields.io/badge/Full%20Package-CWebStudio.zip-green.svg)](https://github.com/OUIsolutions/CWebStudio/releases/download/4.0.0/CWebStudio.zip) | Complete package (includes **src/one.c**) |

## 🚀 Quick Start

```c
#include "CWebStudioOne.c"

CwebHttpResponse *main_sever(CwebHttpRequest *request){
    return cweb_send_text("Hello World", 200);
}

int main(int argc, char *argv[]){
    CwebServer server = newCwebSever(5000, main_sever);
    CwebServer_start(&server);
    return 0;
}
```

## 📚 Documentation

### 🔧 Setup & Configuration
| Topic | Description |
|-------|-------------|
| [📄 Build & Install](docs/build_and_install.md) | How to build and install CWebStudio |
| [📄 Server Configuration](docs/configuring_the_server.md) | Configure server parameters |
| [📄 Debug Mode](docs/cweb_debug_flag.md) | Enable debugging with CWEB_DEBUG |
| [📄 Server Management](docs/killing_the_server.md) | Managing server processes |
| [📄 Dependencies](docs/dependencies.md) | Required dependencies |

### 🌐 Request Handling
| Topic | Description |
|-------|-------------|
| [📄 Routes & Methods](docs/route_method.md) | Work with URL parameters |
| [📄 Query Parameters](docs/getting_query_param.md) | Retrieve query parameters |
| [📄 Iterating Query Parameters](docs/iterating_query_params.md) | Iterate through query parameters |
| [📄 URL Encoding](docs/url_encode_params.md) | Parse URL encoded parameters |
| [📄 Headers](docs/getting_headers.md) | Retrieve headers |
| [📄 Iterating Headers](docs/iterating_headers.md) | Iterate through headers |
| [📄 Request Body](docs/reading_body_content.md) | Read request body content |
| [📄 JSON Parsing](docs/parsing_json.md) | Parse JSON from requests |
| [📄 Binary Content](docs/reading_binary_content.md) | Handle binary content |

### 🖥️ Response Generation
| Topic | Description |
|-------|-------------|
| [📄 Plain Text Responses](docs/returning_values_plain_text.md) | Return plain text |
| [📄 HTML Responses](docs/returning_values_html.md) | Return HTML content |
| [📄 Rendered HTML](docs/returning_values_rendered_html.md) | Dynamic HTML with CTextStack |
| [📄 File Responses](docs/returning_values_files.md) | Serve files directly |
| [📄 JSON Responses](docs/returning_json_from_cjson.md) | Return JSON objects |
| [📄 Other Formats](docs/returning_values_other_formats.md) | Return other content types |
| [📄 Static Files](docs/static_files.md) | Handle static files with caching |

### 💧 HyDration Feature
| Topic | Description |
|-------|-------------|
| [📄 Introduction](docs/hydration.md) | Intro to the HyDration mechanic |
| [📄 Detailed Explanation](docs/hydration_explanation.md) | The three steps of HyDration |
| [📄 Complete Example](docs/hydration_full_runnable_example.md) | Full runnable example |
| [📄 Search Results](docs/hydration_search_result.md) | Retrieve search results |
| [📄 Search Requirements](docs/hydration_search_requirements.md) | Set up search requirements |
| [📄 Browser Actions](docs/hydration_actions.md) | Execute browser actions |
| [📄 Shortcuts](docs/hydration_shortcuts.md) | Use shortcuts in HyDration |
| [📄 Arguments](docs/hydration_handling_args.md) | Pass arguments between bridges |
| [📄 Numeric Handling](docs/hydration_handling_numbers.md) | Handle numbers in HyDration |

## 📊 Performance

CWebStudio is designed for maximum performance with minimal overhead. The single-file library model makes integration simple while maintaining high efficiency.

## 📜 License

CWebStudio is available under the [MIT License](LICENSE).

## 👥 Contributing

Contributions are welcome! Please feel free to submit a Pull Request or open issues to improve the library.

## 🔗 Links

- [GitHub Repository](https://github.com/OUIsolutions/CWebStudio)
- [Issue Tracker](https://github.com/OUIsolutions/CWebStudio/issues)
- [Release Notes](https://github.com/OUIsolutions/CWebStudio/releases)