## Reading Binary Content

```c
#include "CWebStudioOne.c"

void write_binary_file(char *path, unsigned char *content, int size)
{
    FILE *file = fopen(path, "wb");
    fwrite(content, sizeof(unsigned char), size, file);
    fclose(file);
}


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request )
{

    int two_mega_bytes = 2097152;
    char *name = CwebHttpRequest_get_param(request, "name");
    if(!name){
        return cweb_send_text("name not provided\n",404);
    }
    unsigned char *content = CwebHttpRequest_read_content(request, two_mega_bytes);
    if(content){
        write_binary_file(name,content, request->content_length);
        return cweb_send_text("File Written", 200);
    }
    return cweb_send_text("No Content Provided", 200);


}

int main(int argc, char *argv[])
{
    CwebServer server = newCwebSever(5000, main_sever);
    CwebServer_start(&server);
    return 0;
}
```

This example demonstrates how to read binary content from the request and save it to a file.