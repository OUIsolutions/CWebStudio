


char *cweb_parse_string_to_lower(char *old_string){
     
        int string_size = strlen(old_string);
        char *new_string = (char*)malloc(string_size);
        for(int i = 0; i < string_size; i++){
            new_string[i] = tolower(old_string[i]);
        }
        return new_string;
}

char *cweb_normalize_string(char *old_string){
    
    char *new_string = (char*)malloc(strlen(old_string) + 2);


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