



unsigned char *cweb_load_any_content(const char * path,int *size,bool *is_binary){
    FILE *file = fopen(path,"rb");
    if(file == NULL){
        free(file);
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

        //iterate in negative
        char *extension;
        for(int i = 0; i < file_name_size-1; i++){

           //makes extension to point to i
            extension = (char*)&file_name[i+1];
            //if found a dot, break
            if(file_name[i] =='.'){
                break;
            }        
        }


        
        char *content_type_created = (char*)malloc(100);
       
        if(strcmp(extension, "html") == 0){
            strcpy(content_type_created, "text/html");
        }
       
        else if(strcmp(extension, "css") == 0){
            strcpy(content_type_created, "text/css");
        }
       
        else if(strcmp(extension, "js") == 0){
            strcpy(content_type_created, "text/javascript");
        }
        else if(strcmp(extension, "png") == 0){
            strcpy(content_type_created, "image/png");
        }
        else if(strcmp(extension, "jpg") == 0){
            strcpy(content_type_created, "image/jpeg");
        }
        else if(strcmp(extension, "jpeg") == 0){
            strcpy(content_type_created, "image/jpeg");
        }
        else{
            strcpy(content_type_created, "text/plain");
        }
     


        return content_type_created;
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
