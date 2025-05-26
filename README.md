# CWebStudio

![CWebStudio Logo](https://img.shields.io/badge/CWebStudio-4.0.0-blue?style=for-the-badge&logo=c)
[![GitHub Release](https://img.shields.io/github/release/OUIsolutions/CWebStudio.svg?style=for-the-badge)](https://github.com/OUIsolutions/CWebStudio/releases)
[![License](https://img.shields.io/badge/License-MIT-green.svg?style=for-the-badge)](https://github.com/OUIsolutions/CWebStudio/blob/main/LICENSE)

**CWebStudio** is a powerful and lightweight framework for building web applications in C/C++. Designed for efficiency and simplicity, it provides a single-file library to streamline common web development tasks. With CWebStudio, you can effortlessly handle HTTP requests, parse JSON, manage static files, and create dynamic front-end code using the innovative **HyDration** mechanic. Whether you're developing a simple API or a complex web application, CWebStudio equips you with the tools to build fast and reliable solutions.

---

## 🚀 Features

- **Lightweight & Efficient**: A minimal footprint with maximum performance.
- **Single-File Library**: Easy to integrate with your projects.
- **HTTP Request Handling**: Simplified management of routes, headers, and query parameters.
- **JSON Parsing**: Built-in support for handling JSON data with ease.
- **Static File Management**: Serve static files with smart caching.
- **HyDration Mechanic**: Generate dynamic front-end code directly from C.
- **Cross-Platform**: Compatible with multiple environments for C/C++ development.

---

## 📦 Releases

| Item | Description |
|------|-------------|
| **[CWebStudioOne.c](https://github.com/OUIsolutions/CWebStudio/releases/download/4.0.0/CWebStudioOne.c)** | CWebStudio One file (All-in-one solution) |
| **[CWebStudio.c](https://github.com/OUIsolutions/CWebStudio/releases/download/4.0.0/CWebStudio.c)** | Core Definitions |
| **[CWebStudio.h](https://github.com/OUIsolutions/CWebStudio/releases/download/4.0.0/CWebStudio.h)** | Header File |
| **[CWebStudio.zip](https://github.com/OUIsolutions/CWebStudio/releases/download/4.0.0/CWebStudio.zip)** | Full Folder (Includes `src/one.c`) |

---

## 💻 Quick Start: Simple Example

Here's a minimal example to get you started with CWebStudio. This code sets up a basic server that responds with "Hello World".

```c
#include "CWebStudioOne.c"

CwebHttpResponse *main_server(CwebHttpRequest *request) {
    return cweb_send_text("Hello World", 200);
}

int main(int argc, char *argv[]) {
    CwebServer server = newCwebSever(5000, main_server);
    CwebServer_start(&server);
    return 0;
}
```

---

## 📚 Documentation

Explore the comprehensive documentation to learn more about CWebStudio's capabilities:

| Topic | Description |
|-------|-------------|
| **[Build & Install](docs/build_and_install.md)** | How to build and install CWebStudio |
| **[Routing & URL Parameters](docs/route_method.md)** | Working with URL parameters |
| **[Query Parameters](docs/getting_query_param.md)** | Retrieving query parameters |
| **[Iterating Query Params](docs/iterating_query_params.md)** | Iterating through query parameters |
| **[URL Encoding](docs/url_encode_params.md)** | Parsing URL-encoded parameters |
| **[Headers](docs/getting_headers.md)** | Retrieving request headers |
| **[Iterating Headers](docs/iterating_headers.md)** | Iterating through headers |
| **[Request Body](docs/reading_body_content.md)** | Reading body content from requests |
| **[JSON Parsing](docs/parsing_json.md)** | Parsing JSON data from requests |
| **[Returning JSON](docs/returning_json_from_cjson.md)** | Returning JSON using cJSON |
| **[Binary Content](docs/reading_binary_content.md)** | Reading binary content from requests |
| **[Plain Text Responses](docs/returning_values_plain_text.md)** | Returning plain text responses |
| **[Rendered HTML](docs/returning_values_rendered_html.md)** | Returning HTML using CTextStack |
| **[HTML Responses](docs/returning_values_html.md)** | Returning raw HTML responses |
| **[Serving Files](docs/returning_values_files.md)** | Returning files directly from the server |
| **[Other Formats](docs/returning_values_other_formats.md)** | Returning content in various formats |
| **[Static Files](docs/static_files.md)** | Handling static files with smart caching |
| **[Debugging](docs/cweb_debug_flag.md)** | Enabling debug mode with CWEB_DEBUG |
| **[Server Control](docs/killing_the_server.md)** | Killing the server process |
| **[Server Configuration](docs/configuring_the_server.md)** | Configuring server parameters |
| **[HyDration Intro](docs/hydration.md)** | Introduction to HyDration for front-end code |
| **[HyDration Steps](docs/hydration_explanation.md)** | Explaining the three steps of HyDration |
| **[HyDration Example](docs/hydration_full_runnable_example.md)** | Full runnable HyDration example |
| **[HyDration Search](docs/hydration_search_result.md)** | Retrieving search results from the browser |
| **[HyDration Requirements](docs/hydration_search_requirements.md)** | Setting up search requirements for bridges |
| **[HyDration Actions](docs/hydration_actions.md)** | Executing actions in the browser |
| **[HyDration Shortcuts](docs/hydration_shortcuts.md)** | Using shortcuts in HyDration |
| **[HyDration Arguments](docs/hydration_handling_args.md)** | Passing arguments between bridges |
| **[HyDration Numbers](docs/hydration_handling_numbers.md)** | Handling numbers in HyDration |
| **[Dependencies](docs/dependencies.md)** | Required dependencies for CWebStudio |

---


## 🤝 Contributing

We welcome contributions to CWebStudio! If you'd like to contribute, please fork the repository, make your changes, and submit a pull request. For major changes, please open an issue first to discuss your ideas.

---

## 📜 License

CWebStudio is licensed under the MIT License. See the **[LICENSE](https://github.com/OUIsolutions/CWebStudio/blob/main/LICENSE)** file for more details.

---

## 🌟 Why CWebStudio?

CWebStudio brings the power of C/C++ to web development, combining performance with simplicity. Whether you're building embedded web servers or high-performance APIs, CWebStudio is the ideal choice for developers who value efficiency and control.

---

![CWebStudio Banner](https://via.placeholder.com/1200x200?text=CWebStudio+-+Web+Development+in+C/C%2B%2B)
