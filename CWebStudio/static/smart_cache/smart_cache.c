
char * cweb_smart_static_ref(const char *path){


    CTextStack * filename = NULL;
    bool full_path = cweb_starts_with(path,cweb_static_folder);

    if(full_path){
        filename = newCTextStack_string(path);
    }
    else{
        filename = newCTextStack_string_format("%s/%s",cweb_static_folder,path);
    }


    struct stat file_stat;
    long last_mofication = 0;
    if (stat(filename->rendered_text, &file_stat) == 0) {
        last_mofication = file_stat.st_mtime;
    }

    CTextStack_self_substr(filename,(long)strlen(cweb_static_folder),-1);

    CTextStack *src_ref = newCTextStack_string_format(
            "/static?path=%tc&unix-cache=%d",
            filename,
            last_mofication
    );
    return CTextStack_self_transform_in_string_and_self_clear(src_ref);
}

char * private_cweb_change_smart_cache(const char *content){

    CTextStack *code = newCTextStack_string_empty();
    CTextStack *buffer_pattern = newCTextStack_string_empty();
    CTextStack *src = newCTextStack_string_empty();

    unsigned long content_size = strlen(content);
    const char *ENTRY_PATTERN = "smart-cache='";
    unsigned long ENTRY_PATTERN_LEN = strlen(ENTRY_PATTERN);

    int entry_founds = 0;
    bool found_entry = false;

    for(int i = 0; i < content_size; i++){

        char current = content[i];
        CTextStack_format(buffer_pattern,"%c",current);

        if(found_entry){

            //means its cancel the operation
            if( current == '\n' || current =='"'){
                CTextStack_text(code,buffer_pattern->rendered_text);
                CTextStack_restart(buffer_pattern);
                CTextStack_restart(src);
                found_entry = false;
                entry_founds = 0;
                continue;
            }

            //means its getts the src
            if(current != '\''){
                CTextStack_format(src,"%c",current);
                continue;
            }

            char *create_content = cweb_smart_static_ref(src->rendered_text);
            CTextStack_text(code,create_content);
            free(create_content);


            CTextStack_restart(buffer_pattern);
            CTextStack_restart(src);
            found_entry = false;
            entry_founds = 0;
            continue;


        }

        if(entry_founds +1 == ENTRY_PATTERN_LEN){
            found_entry = true;
            continue;
        }

        if(current == ENTRY_PATTERN[entry_founds]){
            entry_founds+=1;
            continue;
        }

        //means didnt get the  pattern
        CTextStack_text(code,buffer_pattern->rendered_text);
        CTextStack_restart(buffer_pattern);
        entry_founds = 0;

    }
    CTextStack_free(buffer_pattern);
    CTextStack_free(src);
    return CTextStack_self_transform_in_string_and_self_clear(code);
}
