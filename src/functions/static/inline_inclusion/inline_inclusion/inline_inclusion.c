#include "../uniq.definitions_requirements.h"

void private_cweb_load_file_and_include(
        CTextStack *code,
        CTextStack *src,
        privateCwebRecursionList * recursion_listage){



    CTextStack_self_trim(src);
    CTextStack * filename =private_cweb_format_filename(src);

    bool new_content_is_binary;
    int content_size;
    unsigned char *new_content = cweb_load_any_content(filename->rendered_text, &content_size,&new_content_is_binary);

    if(new_content && !new_content_is_binary){
        private_cweb_generate_inline_inclusion(
                code, (const char *) new_content,
                content_size,
                recursion_listage,
                src->rendered_text
        );
    }
    if(new_content){
        free(new_content);
    }
    CTextStack_free(filename);
}

void private_cweb_generate_inline_inclusion(
        CTextStack *code,
        const char *content,
        long content_size,
        privateCwebRecursionList *recursion_listage,
        const char *filename) {

    CTextStack *buffer_pattern = newCTextStack_string_empty();
    CTextStack *src = newCTextStack_string_empty();
    const char *ENTRY_START = "inline-include";
    int ENTRY_START_LEN = (int)strlen(ENTRY_START);

    const char *ENTRY_PATTERN = "inline-include='";
    int  ENTRY_PATTERN_LEN = (int)strlen(ENTRY_PATTERN);

    int entry_founds = 0;
    bool found_entry = false;

    for(int i = 0; i < content_size; i++){

        char current = content[i];
        CTextStack_format(buffer_pattern,"%c",current);

        if(found_entry){
            //printf("current :%c\n",current);
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
            privateCwebRecursionElement *colision = NULL;
            if(filename){
                colision =privateCwebRecursionList_add_if_not_colide(
                        recursion_listage,
                        filename,
                        src->rendered_text
                        );
            }
            if(!colision){
                //printf("incluiu a %s\n",src->rendered_text);
                private_cweb_load_file_and_include(code,src,recursion_listage);
            }

            if(colision){
                printf(
                        "recursive colision on file:%s with %s\n",
                        src->rendered_text,
                        colision->included

                        );
            }


            CTextStack_restart(buffer_pattern);
            CTextStack_restart(src);
            found_entry = false;
            entry_founds = 0;
            continue;


        }

        if(current == ' ' && entry_founds >= ENTRY_START_LEN) {
            continue;
        }

        if(entry_founds+1 == ENTRY_PATTERN_LEN){
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
