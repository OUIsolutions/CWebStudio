//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.dep_define.h"
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





const char *cweb_generate_content_type(const char *file_name){
        int file_name_size = strlen(file_name);

        if(file_name_size < 2){
            return  "text/plain";
        }

        //iterate in negative
        char *extension;
          for(int i = file_name_size -2; i >= 0;  i--){

           //makes extension to point to i

            extension = (char*)&file_name[i+1];
            //if found a dot, break
            if(file_name[i] =='.'){
                break;
            }
        }
        if(!extension){
            return  "text/plain";
        }

        if(strcmp(extension, "html") == 0){
           return "text/html";
        }
        if(strcmp(extension,"mp4") == 0){
            return "video/mp4";
        }
        if(strcmp(extension,"WebM") == 0){
            return "video/webm";
        }
        if(strcmp(extension,"Ogg") == 0){
            return  "video/ogg";
        }
        if(strcmp(extension,"mp3") == 0){
            return  "audio/mpeg";
        }

        if(strcmp(extension,"pdf") == 0){
            return "application/pdf";
        }

        else if(strcmp(extension, "css") == 0){
            return "text/css";
        }

        else if(strcmp(extension, "js") == 0){
            return  "text/javascript";
        }
        else if(strcmp(extension, "png") == 0){
            return "image/png";
        }
        else if(strcmp(extension, "ico") == 0){
            return "image/x-icon";
        }

        else if(strcmp(extension, "jpg") == 0){
            return  "image/jpeg";
        }
        else if(strcmp(extension, "jpeg") == 0){
            return "image/jpeg";
        }
        else{
            return  "text/plain";
        }

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