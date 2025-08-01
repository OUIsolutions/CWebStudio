//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "imports/imports.dep_define.h"
//silver_chain_scope_end



unsigned char *cweb_load_any_content(const char * path,int *size,bool *is_binary){
    FILE *file = fopen(path,"rb");
    if(file == NULL){
        return NULL;
    }
    fseek(file,0,SEEK_END);
    *size = ftell(file);
    fseek(file,0,SEEK_SET);
    unsigned char *content = (unsigned char*)malloc(*size +1);
    fread(content,1,*size,file);

    *is_binary = false;
    for(int i = 0;i < *size;i++){
        if(content[i] == 0){
            *is_binary = true;
            break;
        }
    }
    if(!*is_binary){
        content[*size] = '\0';
    }

    fclose(file);
    return content;
}


char *cweb_load_string_file_content(const char * path){
    FILE *file = fopen(path,"r");
    if(file == NULL){
        return NULL;
    }
    fseek(file,0,SEEK_END);
    int size = ftell(file);
    fseek(file,0,SEEK_SET);
    char *content = (char*)malloc(size +1);
    fread(content,1,size,file);
    content[size] = '\0';
    fclose(file);
    return content;
}


unsigned char *cweb_load_binary_content(const char * path,int *size){
    FILE *file = fopen(path,"rb");
    if(file == NULL){
        return NULL;
    }
    fseek(file,0,SEEK_END);
    *size = ftell(file);
    fseek(file,0,SEEK_SET);
    unsigned char *content = (unsigned char*)malloc(*size);
    fread(content,1,*size,file);
    fclose(file);
    return content;
}


const char *cweb_generate_content_type(const char *file_name, bool is_binary) {
    int file_name_size = strlen(file_name);
    
    if (file_name_size < 2) {
        return is_binary ? "application/octet-stream" : "text/plain";
    }
    
    // Find the extension
    const char *extension = NULL;
    for (int i = file_name_size - 1; i >= 0; i--) {
        if (file_name[i] == '.') {
            extension = &file_name[i + 1];
            break;
        }
    }
    
    if (!extension || strlen(extension) == 0) {
        return is_binary ? "application/octet-stream" : "text/plain";
    }
    
    // Convert extension to lowercase for case-insensitive comparison
    char lower_ext[256];
    int ext_len = strlen(extension);
    if (ext_len >= sizeof(lower_ext)) {
        return is_binary ? "application/octet-stream" : "text/plain";
    }
    
    for (int i = 0; i <= ext_len; i++) {
        lower_ext[i] = tolower(extension[i]);
    }
    
    // Text types
    if (strcmp(lower_ext, "html") == 0 || strcmp(lower_ext, "htm") == 0) return "text/html";
    if (strcmp(lower_ext, "css") == 0) return "text/css";
    if (strcmp(lower_ext, "js") == 0 || strcmp(lower_ext, "mjs") == 0) return "text/javascript";
    if (strcmp(lower_ext, "txt") == 0) return "text/plain";
    if (strcmp(lower_ext, "csv") == 0) return "text/csv";
    if (strcmp(lower_ext, "xml") == 0) return "text/xml";
    if (strcmp(lower_ext, "md") == 0) return "text/markdown";
    
    // Application types
    if (strcmp(lower_ext, "json") == 0) return "application/json";
    if (strcmp(lower_ext, "pdf") == 0) return "application/pdf";
    if (strcmp(lower_ext, "zip") == 0) return "application/zip";
    if (strcmp(lower_ext, "gz") == 0) return "application/gzip";
    if (strcmp(lower_ext, "tar") == 0) return "application/x-tar";
    if (strcmp(lower_ext, "rar") == 0) return "application/vnd.rar";
    if (strcmp(lower_ext, "7z") == 0) return "application/x-7z-compressed";
    
    // WebAssembly
    if (strcmp(lower_ext, "wasm") == 0) return "application/wasm";
    if (strcmp(lower_ext, "wat") == 0) return "text/plain";
    
    // Microsoft Office
    if (strcmp(lower_ext, "doc") == 0) return "application/msword";
    if (strcmp(lower_ext, "docx") == 0) return "application/vnd.openxmlformats-officedocument.wordprocessingml.document";
    if (strcmp(lower_ext, "xls") == 0) return "application/vnd.ms-excel";
    if (strcmp(lower_ext, "xlsx") == 0) return "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet";
    if (strcmp(lower_ext, "ppt") == 0) return "application/vnd.ms-powerpoint";
    if (strcmp(lower_ext, "pptx") == 0) return "application/vnd.openxmlformats-officedocument.presentationml.presentation";
    
    // Images
    if (strcmp(lower_ext, "jpg") == 0 || strcmp(lower_ext, "jpeg") == 0) return "image/jpeg";
    if (strcmp(lower_ext, "png") == 0) return "image/png";
    if (strcmp(lower_ext, "gif") == 0) return "image/gif";
    if (strcmp(lower_ext, "bmp") == 0) return "image/bmp";
    if (strcmp(lower_ext, "ico") == 0) return "image/x-icon";
    if (strcmp(lower_ext, "svg") == 0) return "image/svg+xml";
    if (strcmp(lower_ext, "webp") == 0) return "image/webp";
    if (strcmp(lower_ext, "tiff") == 0 || strcmp(lower_ext, "tif") == 0) return "image/tiff";
    
    // Audio
    if (strcmp(lower_ext, "mp3") == 0) return "audio/mpeg";
    if (strcmp(lower_ext, "wav") == 0) return "audio/wav";
    if (strcmp(lower_ext, "ogg") == 0) return "audio/ogg";
    if (strcmp(lower_ext, "m4a") == 0) return "audio/mp4";
    if (strcmp(lower_ext, "flac") == 0) return "audio/flac";
    if (strcmp(lower_ext, "aac") == 0) return "audio/aac";
    if (strcmp(lower_ext, "wma") == 0) return "audio/x-ms-wma";
    if (strcmp(lower_ext, "opus") == 0) return "audio/opus";
    
    // Video
    if (strcmp(lower_ext, "mp4") == 0) return "video/mp4";
    if (strcmp(lower_ext, "webm") == 0) return "video/webm";
    if (strcmp(lower_ext, "ogg") == 0) return "video/ogg";
    if (strcmp(lower_ext, "avi") == 0) return "video/x-msvideo";
    if (strcmp(lower_ext, "mov") == 0) return "video/quicktime";
    if (strcmp(lower_ext, "wmv") == 0) return "video/x-ms-wmv";
    if (strcmp(lower_ext, "flv") == 0) return "video/x-flv";
    if (strcmp(lower_ext, "mkv") == 0) return "video/x-matroska";
    if (strcmp(lower_ext, "m4v") == 0) return "video/x-m4v";
    if (strcmp(lower_ext, "3gp") == 0) return "video/3gpp";
    
    // Fonts
    if (strcmp(lower_ext, "ttf") == 0) return "font/ttf";
    if (strcmp(lower_ext, "otf") == 0) return "font/otf";
    if (strcmp(lower_ext, "woff") == 0) return "font/woff";
    if (strcmp(lower_ext, "woff2") == 0) return "font/woff2";
    if (strcmp(lower_ext, "eot") == 0) return "application/vnd.ms-fontobject";
    
    // Programming languages and data
    if (strcmp(lower_ext, "c") == 0) return "text/x-c";
    if (strcmp(lower_ext, "cpp") == 0 || strcmp(lower_ext, "cc") == 0) return "text/x-c++";
    if (strcmp(lower_ext, "h") == 0) return "text/x-h";
    if (strcmp(lower_ext, "java") == 0) return "text/x-java-source";
    if (strcmp(lower_ext, "py") == 0) return "text/x-python";
    if (strcmp(lower_ext, "rb") == 0) return "text/x-ruby";
    if (strcmp(lower_ext, "go") == 0) return "text/x-go";
    if (strcmp(lower_ext, "rs") == 0) return "text/x-rust";
    if (strcmp(lower_ext, "php") == 0) return "text/x-php";
    if (strcmp(lower_ext, "sh") == 0) return "text/x-shellscript";
    if (strcmp(lower_ext, "yaml") == 0 || strcmp(lower_ext, "yml") == 0) return "text/yaml";
    if (strcmp(lower_ext, "toml") == 0) return "text/toml";
    if (strcmp(lower_ext, "ini") == 0) return "text/plain";
    
    // Other common types
    if (strcmp(lower_ext, "exe") == 0) return "application/x-msdownload";
    if (strcmp(lower_ext, "dll") == 0) return "application/x-msdownload";
    if (strcmp(lower_ext, "deb") == 0) return "application/x-debian-package";
    if (strcmp(lower_ext, "rpm") == 0) return "application/x-rpm";
    if (strcmp(lower_ext, "dmg") == 0) return "application/x-apple-diskimage";
    if (strcmp(lower_ext, "pkg") == 0) return "application/x-newton-compatible-pkg";
    if (strcmp(lower_ext, "apk") == 0) return "application/vnd.android.package-archive";
    
    // Default fallback
    return is_binary ? "application/octet-stream" : "text/plain";
}


char *private_cweb_convert_url_encoded_text(const char *text){

    int text_size = strlen(text);
    char *new_text = (char*)malloc(text_size + 1);
    int new_text_size = 0;

    for(int i = 0; i < text_size; i++){
        if(text[i] == '%'){
            char hex[3];
            hex[0] = text[i+1];
            hex[1] = text[i+2];
            hex[2] = '\0';
            new_text[new_text_size] = (char)strtol(hex, NULL, 16);
            new_text_size++;
            i += 2;
        }
        else{
            new_text[new_text_size] = text[i];
            new_text_size++;
        }
    }
    new_text[new_text_size] = '\0';
    return new_text;
}
/*
bool private_cweb_is_string_from_point(const char *content, long content_size, const char *test_string, long test_string_size, long point){

    long  end_point = point + test_string_size;

    if(content_size < end_point){
        return  false;
    }

    for(long i = 0; i < test_string_size; i++){
        char current_char = test_string[i];
        char test_char = content[i+point];
        if(current_char != test_char){
            return  false;
        }
    }
    return true;
}
 */

 char * private_CWeb_format_vaarg(const char *expresion, va_list args){

     va_list args_copy;
     va_copy(args_copy, args);
     long required_size = vsnprintf(NULL, 0,expresion,args_copy);
     va_end(args_copy);
     char *buffer = (char*)malloc(sizeof(char) * required_size + 2);
     vsnprintf(buffer,sizeof (char) * required_size+1,expresion,args);
     return buffer;
 }

 char * private_CWeb_format(const char *expresion, ...){
     va_list  args;
     va_start(args,expresion);
     char *result = private_CWeb_format_vaarg(expresion,args);
     va_end(args);
     return  result;
 }

 char *private_cweb_convert_to_hexa(const char *data){
     CTextStack *hexa_format = newCTextStack_string_empty();
     int content_size = strlen(data);
     for(int i = 0; i < content_size; i++){
         char buffer[10] = {0};
         sprintf(buffer,"\\x%x",data[i]);
         CTextStack_format(hexa_format,"%s",buffer);
     };
     return CTextStack_self_transform_in_string_and_self_clear(hexa_format);
 }


 CTextStack  *private_cweb_create_assci_code(const char *msg){
     CTextStack *data = newCTextStack_string("[");
     long size = strlen(msg);
     for(int i =0; i < size;i++){
         CTextStack_format(data, "%d,", msg[i]);
     }
     CTextStack_text(data,"]");
     return data;
 }