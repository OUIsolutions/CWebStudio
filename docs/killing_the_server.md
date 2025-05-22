## Killing the Server

If you want to kill the server for any reason, like testing memory leaks or finishing the server, you can just change the var **cweb_end_server** to true.

```c
#include "CWebStudioOne.c"

CwebHttpResponse *main_sever(CwebHttpRequest *request) {
    if (strcmp(request->route, "/kill") == 0) {
        cweb_kill_single_process_server();
    }
    return cweb_send_text("Working", 200);
}

int main(int argc, char *argv[]) {
    CwebServer server = newCwebSever(5000, main_sever);
    server.single_process = true;
    CwebServer_start(&server);
    return 0;
}
```

This example demonstrates how to kill the server using the **cweb_kill_single_process_server** function.