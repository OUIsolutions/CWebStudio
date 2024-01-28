
void private_cweb_load_file_and_include(CTextStack *code,const char *path){

    CTextStack * filename = NULL;
    bool full_path = cweb_starts_with(path,cweb_static_folder);

    if(full_path){
        filename = newCTextStack_string(path);
    }
    else{
        filename = newCTextStack_string_format("%s/%s",cweb_static_folder,path);
    }




    bool new_content_is_binary;
    int content_size;
    unsigned char *new_content = cweb_load_any_content(filename->rendered_text, &content_size,&new_content_is_binary);

    if(new_content && !new_content_is_binary){
        private_cweb_generate_inline_inclusion(code,(const char*)new_content,content_size);
    }
    if(new_content){
        free(new_content);
    }
    CTextStack_free(filename);
}

void private_cweb_generate_inline_inclusion(CTextStack *code, const char *content,long content_size){

    CTextStack *buffer_pattern = newCTextStack_string_empty();
    CTextStack *src = newCTextStack_string_empty();

    const char *ENTRY_PATTERN = "inline-include='";
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
            private_cweb_load_file_and_include(code,src->rendered_text);


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
}