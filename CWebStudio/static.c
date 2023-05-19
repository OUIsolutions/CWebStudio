


char * private_cweb_change_smart_cache(const char *content){

    struct CTextStack *code = newCTextStack("","");
    struct CTextStack *buffer_pattern = newCTextStack("","");
    struct CTextStack *src = newCTextStack("","");

    unsigned long content_size = strlen(content);
    const char *entry_pattern = "smart-cache='";
    unsigned long entry_pattern_len = strlen(entry_pattern);

    int entry_founds = 0;
    bool found_entry = false;

    for(int i = 0; i < content_size; i++){

        char current = content[i];
        buffer_pattern->format(buffer_pattern,"%c",current);

        if(found_entry){

            //means its cancel the operation
            if( current == '\n' || current =='"'){
                code->text(code,buffer_pattern->rendered_text);
                buffer_pattern->restart(buffer_pattern);
                src->restart(src);
                found_entry = false;
                entry_founds = 0;
                continue;
            }

            //means its getts the src
            if(current != '\''){
                src->format(src,"%c",current);
                continue;
            }


            struct stat file_stat;
            long last_mofication = 0;

            if (stat(src->rendered_text, &file_stat) == 0) {
                last_mofication = file_stat.st_mtime;
            }
            code->format(code,"/static?path=%s&unix-cache=%i",src->rendered_text, last_mofication);

            buffer_pattern->restart(buffer_pattern);
            src->restart(src);
            found_entry = false;
            entry_founds = 0;
            continue;


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

struct CwebHttpResponse * private_cweb_generate_static_response(struct CwebHttpRequest *request,bool use_cache){

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
        long size;
        bool is_binary;
        unsigned char *content = cweb_load_any_content(securyt_path,&size,&is_binary);

        if(content == NULL){


            char *not_found_html_page = cweb_load_string_file_content("static/404.html");
            if(not_found_html_page != NULL){
                return cweb_send_var_html_cleaning_memory(not_found_html_page,404);

            }

            char mensage[100];
            sprintf(mensage, "File not found: %s", securyt_path);
            struct CwebHttpResponse* response =  cweb_send_text(mensage, CWEB_NOT_FOUND);
            return response;
        }

        if(!is_binary){
            char *new_content = private_cweb_change_smart_cache((char*)content);
            free(content);
            size = strlen(new_content);
            content = (unsigned char*)new_content;
        }

        char *content_type  = (char*)cweb_generate_content_type(securyt_path);

        struct CwebHttpResponse * response = cweb_send_any_cleaning_memory(content_type,size,content,200);


        if(use_cache){
            char *unix_cache = request->get_param(request,"unix-cache");
            if(unix_cache){
                char response_code[50] = "";
                sprintf(response_code, "public, max-age=31536000, immutable");
                response->add_header(response,"cache-control", response_code);
            }
        }

        free(securyt_path);
        return response;

    }
    return NULL;

}