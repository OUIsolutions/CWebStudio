## Install

To install the lib just copy the [Amalgamation](https://github.com/OUIsolutions/CWebStudio/releases/download/4.0.0/CWebStudioOne.c) into your project and include it in your code:
```c
#include "CWebStudioOne.c"
```


If you are on Linux, you can download the lib with:
```bash
curl -L https://github.com/OUIsolutions/CWebStudio/releases/download/4.0.0/CWebStudioOne.c -o CWebStudioOne.c
```

## Compile on Linux

To compile the lib in **Linux** you can use the following command:
```bash
gcc main.c -o your_output.out
```

## Compile on Windows

To compile the lib in **Windows** you can use the following commands

With Microsoft Visual C:
```cmd
cl.exe examples\example_simple.c /Fe:bin\example_simple.exe
```

With mingw64:
```bash
i686-w64-mingw32-gcc examples\example_simple.c -o bin\example_simple.exe -lws2_32
```

## Build from scratch

For building from scratch you need to have [darwin](https://github.com/OUIsolutions/Darwin/) installed on your machine. To install darwin:
```bash
curl -L https://github.com/OUIsolutions/Darwin/releases/download/0.11.0/darwin.out -o darwin.out && chmod +x darwin.out && sudo mv darwin.out /usr/bin/darwin
```

Then you can build the project with in the root dir of the project:
```bash
darwin run_blueprint --target all
```
of if you are building in dir mode , you can just perform the silverchain organization and macro builds with:

It will generate all the **releases** in the **/release** dir.

```bash
darwin run_blueprint --target dir_project
```


### Mocking dependencies or dependencies implementations

The following defines toggle dependencies or just the definitions.
It is useful for working with dynamic compilation or mocking dependencies.
```c
// unallow universal socket definition
#define CWEB_MOCK_UNIVERSAL_SOCKET_DEFINE

// unallow universal socket at all
#define CWEB_MOCK_UNIVERSAL_SOCKET

// unallow cjson at all
// NOTE: Hiding CJSON will force the lib to use **get_addrinfo** which
// can leak memory in some cases.
#define CWEB_MOCK_CJSON

// unallow cjson definition
#define CWEB_MOCK_CJSON_DEFINE

// unallow universal garbage collector
#define CWEB_MOCK_UNIVERSAL_GARBAGE

// unallow universal garbage collector definition
#define CWEB_MOCK_UNIVERSAL_GARBAGE_DEFINE

// import the lib only after the flags
#include "CWebStudioOne.c"
```