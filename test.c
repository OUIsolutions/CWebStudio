#include "CWebStudio.h"
#include "trash/doTheWorld.h"


char * change_smart_cache(const char *content){

    struct CTextStack *code = newCTextStack("","");
    struct CTextStack *buffer_pattern = newCTextStack("","");
    struct CTextStack *src = newCTextStack("","");


    unsigned long content_size = strlen(content);

    const char *entry_pattern = "smart_cache:/)";

    unsigned long entry_pattern_len = strlen(entry_pattern);
    const char *out_pattern  = "\"";
    unsigned long out_pattern_size = strlen(out_pattern);

    int entry_founds = 0;
    bool found_entry = false;

    for(int i = 0; i < content_size; i++){

        char current = content[i];
        buffer_pattern->format(buffer_pattern,"%c",current);

        if(found_entry && current != '"'){
            //means its getting the src
            src->format(src,"%c",current);
            continue;
        }


        if(found_entry){
            //means its gthe end of src
           // printf("src=%s\n",src->rendered_text);

            buffer_pattern->free(buffer_pattern);
            buffer_pattern = newCTextStack("","");
            src->free(src);
            src = newCTextStack("","");
            found_entry = false;
            entry_founds = 0;
            continue;
        }


        if(entry_founds +1  == entry_pattern_len){
            found_entry = true;
            src->format(src,"%c",current);
            continue;
        }

        if(current == entry_pattern[entry_founds]){
            entry_founds+=1;
            continue;
        }



        //means didnt get the  pattern
        code->text(code,buffer_pattern->rendered_text);
        buffer_pattern->free(buffer_pattern);
        buffer_pattern = newCTextStack("","");
        entry_founds = 0;

    }
    printf("%s",code->rendered_text);

}
int main(){
    char *teste = dtw_load_string_file_content("static/teste.html");
    char *result = change_smart_cache(teste);
    printf("%s\n",result);
}