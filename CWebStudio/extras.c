


char *cweb_parse_string_to_lower(const char *old_string){
     
        int string_size = strlen(old_string);
        char *new_string = (char*)malloc(string_size + 2);
        for(int i = 0; i < string_size; i++){
            new_string[i] = tolower(old_string[i]);
        }
        new_string[string_size] = '\0';
        return new_string;
}


char *cweb_parse_string_to_upper(const char *old_string){
     
        int string_size = strlen(old_string);
        char *new_string = (char*)malloc(string_size + 2);
        for(int i = 0; i < string_size; i++){
            new_string[i] = toupper(old_string[i]);
        }
        new_string[string_size] = '\0';
        return new_string;
}

char *cweb_normalize_string(const char *old_string,char *invalid_chars){
    
    int string_size = strlen(old_string);
    char *lower_string = cweb_parse_string_to_lower(old_string);
    char *new_string = (char*)malloc(string_size + 2);
    int new_string_size = 0;

    for(int i = 0; i < string_size; i++){
        if(strchr(invalid_chars,lower_string[i]) == NULL){
            new_string[new_string_size] = lower_string[i];
            new_string_size++;
        }        
    }
    new_string[new_string_size] = '\0';
    free(lower_string);
    return new_string;
}

const char *cweb_generate_content_type(const char *file_name){
        
        struct DtwPath *path = dtw_constructor_path(file_name);
        char *extension = path->get_extension(path);

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
        free(extension);
        path->free_path(path);
        return content_type_created;
}