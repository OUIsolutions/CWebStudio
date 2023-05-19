


char * private_cweb_change_smart_cache(const char *content){

    struct CTextStack *code = newCTextStack("","");
    struct CTextStack *buffer_pattern = newCTextStack("","");
    struct CTextStack *src = newCTextStack("","");

    unsigned long content_size = strlen(content);
    const char *entry_pattern = "\"smart_cache:/static/";
    unsigned long entry_pattern_len = strlen(entry_pattern);

    int entry_founds = 0;
    bool found_entry = false;

    for(int i = 0; i < content_size; i++){

        char current = content[i];
        buffer_pattern->format(buffer_pattern,"%c",current);

        if(found_entry){

            //means its cancel the operation
            if( current == '\n'){
                code->text(code,buffer_pattern->rendered_text);
                buffer_pattern->restart(buffer_pattern);
                src->restart(src);
                found_entry = false;
                entry_founds = 0;
                continue;
            }

            //means its getts the src
            if(current != '"'){
                src->format(src,"%c",current);
                continue;
            }

            if(current == '"'){
                //means its gthe end of src
                // printf("src=%s\n",src->rendered_text);
                char filename[2000];
                sprintf(filename,"static/%s",src->rendered_text);
                struct stat file_stat;
                long last_mofication = 0;
                if (stat(filename, &file_stat) == 0) {
                    last_mofication = file_stat.st_mtime;
                }
                code->format(code,"\"/static?path=%s&update=%i\"",filename,last_mofication);

                buffer_pattern->restart(buffer_pattern);
                src->restart(src);
                found_entry = false;
                entry_founds = 0;
                continue;
            }
        }

        if(entry_founds +1  == entry_pattern_len){
            found_entry = true;
            continue;
        }

        if(current == entry_pattern[entry_founds]){
            entry_founds+=1;
            continue;
        }

        //means didnt get the  pattern
        code->text(code,buffer_pattern->rendered_text);
        buffer_pattern->restart(buffer_pattern);
        entry_founds = 0;

    }

    return code->rendered_text;
}

struct CwebHttpResponse * private_cweb_treat_five_icon(struct CwebHttpRequest *request){

    if(strcmp(request->route,"/favicon.ico")== 0){
        /*
        int size = 0;
        unsigned char *content;
        bool content_found = false;
        struct CwebHttpResponse * response;
        
        content = cweb_load_binary_content("static/favicon.ico", &size);
        if(content != NULL){
            response = cweb_send_any_cleaning_memory("image/x-icon",size,content, 200);
            content_found = true;
        }

        content = cweb_load_binary_content("static/favicon.png", &size);
        if(content != NULL){
            response = cweb_send_any_cleaning_memory("image/x-icon",size,content, 200);
            content_found = true;
        }


        content = cweb_load_binary_content("static/favicon.jpg", &size);
        if(content != NULL){
             response =  cweb_send_any_cleaning_memory("image/x-icon",size,content, 200);
            content_found = true;
        }

        if(!content_found){
              return cweb_send_text("",404);
        }
        */
        return  cweb_send_text("",404);
      

    }
    return NULL;
}

struct CwebHttpResponse * private_cweb_generate_static_response(struct CwebHttpRequest *request,long max_cache_age){

    struct CwebHttpResponse * icon_response = private_cweb_treat_five_icon(request);

    if(icon_response !=  NULL){
        return icon_response;
    }

    if(cweb_starts_with(request->route,"/static")){

        char *full_path = request->route;
        full_path+=1;

        char *path = request->get_param(request,"path");
        if(path != NULL){
            full_path = path;
        }

        char *securyt_path = cweb_replace_string(full_path,"../","");
        int size;
        bool is_binary;
        unsigned char *content = cweb_load_any_content(securyt_path,&size,&is_binary);


        if(!is_binary){
            char *new_content = private_cweb_change_smart_cache((char*)content);
            free(content);
            content = (unsigned char*)new_content;
        }

        char *content_type  = (char*)cweb_generate_content_type(securyt_path);

        struct CwebHttpResponse * response = cweb_send_any_cleaning_memory(content_type,size,content,200);
        if(max_cache_age > 0){
            char response_code[50] = "";
            sprintf(response_code, "public, max-age=%ld", max_cache_age);
            response->add_header(response,"cache-control", response_code);
        }
        free(securyt_path);
        return response;
    }
    return NULL;

}