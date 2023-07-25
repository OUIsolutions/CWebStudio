/*
MIT License

Copyright (c) 2023 OUI

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifndef CTEXTENGINE_H
#define CTEXTENGINE_H


#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>




#define CTEXT_BY_OWNESHIP 1
#define CTEXT_BY_COPY 2
#define CTEXT_BY_REFERENCE 3

//
// Created by jurandi on 18-04-2023.
//
#define CTEXT_HTML "html"
#define CTEXT_BODY "body"
#define CTEXT_DIV "div"
#define CTEXT_H1 "h1"
#define CTEXT_H2 "h2"
#define CTEXT_H3 "h3"
#define CTEXT_H4 "h4"
#define CTEXT_H5 "h5"
#define CTEXT_H6 "h6"
#define CTEXT_P "p"
#define CTEXT_SPAN "span"
#define CTEXT_A "a"
#define CTEXT_IMG "img"
#define CTEXT_INPUT "input"
#define CTEXT_BUTTON "button"
#define CTEXT_TABLE "table"
#define CTEXT_TR "tr"
#define CTEXT_TD "td"
#define TH "th"
#define CTEXT_THEAD "thead"
#define CTEXT_TBODY "tbody"
#define CTEXT_TFOOT "tfoot"
#define CTEXT_UL "ul"
#define CTEXT_LI "li"
#define CTEXT_OL "ol"
#define CTEXT_FORM "form"
#define CTEXT_LABEL "label"
#define CTEXT_SELECT "select"
#define CTEXT_OPTION "option"
#define CTEXT_TEXTAREA "textarea"
#define CTEXT_SCRIPT "script"
#define CTEXT_STYLE "style"
#define CTEXT_META "meta"
#define CTEXT_LINK "link"
#define CTEXT_HEAD "head"
#define CTEXT_BASE "base"
#define CTEXT_BR "br"
#define CTEXT_HR "hr"
#define CTEXT_TITLE "title"
#define CTEXT_IFRAME "iframe"
#define CTEXT_NAV "nav"
#define CTEXT_HEADER "header"
#define CTEXT_FOOTER "footer"
#define CTEXT_SECTION "section"
#define CTEXT_ARTICLE "article"
#define CTEXT_ASIDE "aside"
#define CTEXT_DETAILS "details"
#define CTEXT_SUMMARY "summary"
#define CTEXT_DIALOG "dialog"
#define MENU "menu"
#define MENUITEM "menuitem"
#define CTEXT_MAIN "main"
#define CTEXT_CANVAS "canvas"
#define CTEXT_AUDIO "audio"
#define CTEXT_VIDEO "video"
#define CTEXT_SOURCE "source"
#define CTEXT_TRACK "track"
#define CTEXT_EMBED "embed"
#define CTEXT_PARAM "param"
    








#define CTEXT_LINE_BREAKER "\n"
#define CTEXT_SEPARATOR "   "


typedef struct CTextStack{

    char *rendered_text;
    size_t rendered_text_alocation_size;
    size_t size;
    
    char *line_breaker;
    char *separator;
    int ident_level;

}CTextStack;

struct CTextStack *newCTextStack(const char *line_breaker, const char *separator);


struct CTextStack *newCTextStack_string(const char *starter);

struct CTextStack *newCTextStack_string_getting_ownership(const char *starter);

struct CTextStack *newCTextStack_string_empty();


void CTextStack_text(struct CTextStack *self, const char *text);


void private_ctext_text_double_size_if_reachs(struct CTextStack *self);


void CTextStack_segment_text(struct CTextStack *self, const char *text);


void CTextStack_segment(struct CTextStack *self);


void CTextStack_$open(struct CTextStack *self, const char *tag, const char *format, ...);


void CTextStack_only$open(struct CTextStack *self, const char *tag, const char *format, ...);


void CTextStack_auto$close(struct CTextStack *self, const char *tag, const char *format, ...);


void CTextStack_format(struct CTextStack *self, const char *format, ...);


void CTextStack_segment_format(struct CTextStack *self, const char *format, ...);


void ctext_open(struct CTextStack *self, const char *tag);


void ctext_close(struct CTextStack *self, const char *tag);

void CTextStack_represent(struct CTextStack *self);
void CTextStack_free(struct CTextStack *self);


struct CTextStack * CTextStack_clone(struct CTextStack *self);


char * CTextStack_self_transform_in_string_and_self_clear(struct CTextStack *self);

void private_CTextStack_parse_ownership(struct CTextStack *self, struct CTextStack *new_string);


void CTextStack_restart(struct CTextStack *self);


//algorithm methods

struct CTextStack *CTextStack_substr(struct CTextStack *self, long starter, long end);
void CTextStack_self_substr(struct CTextStack *self, long starter, long end);


struct CTextStack *CTextStack_pop(struct CTextStack *self, long starter, long end);
void  CTextStack_self_pop(struct CTextStack *self, long starter, long end);


struct CTextStack *CTextStack_replace(struct CTextStack *self,const char *element, const char *element_to_replace);
void CTextStack_self_replace(struct CTextStack *self,const char *element, const char *element_to_replace);


struct CTextStack *CTextStack_replace_long(struct CTextStack *self,const char *element, long element_to_replace);
void CTextStack_self_replace_long(struct CTextStack *self,const char *element, long element_to_replace);

struct CTextStack *CTextStack_replace_double(struct CTextStack *self,const char *element, double element_to_replace);
void CTextStack_self_replace_double(struct CTextStack *self,const char *element, double element_to_replace);


struct CTextStack *CTextStack_insert_at(struct CTextStack *self,long point, const char *element);
void CTextStack_self_insert_at(struct CTextStack *self,long point, const char *element);


long CtextStack_index_of_char(struct  CTextStack *self,char element);
long CtextStack_index_of(struct  CTextStack *self,const char *element);

bool CtextStack_starts_with(struct  CTextStack *self,const char *element);
bool CtextStack_ends_with(struct  CTextStack *self,const char *element);


struct CTextStack *CTextStack_trim(struct CTextStack *self);
void CTextStack_self_trim(struct CTextStack *self);

struct CTextStack *CTextStack_lower(struct CTextStack *self);
void CTextStack_self_lower(struct CTextStack *self);

struct CTextStack *CTextStack_upper(struct CTextStack *self);
void CTextStack_self_upper(struct CTextStack *self);



struct CTextStack *CTextStack_reverse(struct CTextStack *self);
void CTextStack_self_reverse(struct CTextStack *self);






typedef struct CTextStackModule{

    //admnistrative methods
    void (*free)(struct CTextStack *self);
    struct CTextStack *(*clone)(struct CTextStack *self);
    void (*represent)(struct CTextStack *self);
    char *(*self_transform_in_string_and_self_clear)(struct CTextStack *self);
    void (*restart)(struct CTextStack *self);

    //render methods
    void (*text)(struct CTextStack *self, const char *element);

    void (*segment_text)(struct CTextStack *self, const char *element);

    void (*format)(struct CTextStack *self, const char *format, ...);

    void (*segment)(struct CTextStack *self);

    void (*segment_format)(struct CTextStack *self, const char *format, ...);

    void (*$open)(struct CTextStack *self, const char *tag, const char *format,...);

    void (*only$open)(struct CTextStack *self, const char *tag, const char *format,...);

    void (*auto$close)(struct CTextStack *self, const char *tag, const char *format,...);

    void (*open)(struct CTextStack *self, const char *tag);

    void (*close)(struct CTextStack *self, const char *tag);


    //algorithm methods
    struct CTextStack * (*substr)(struct CTextStack *self, long starter, long end);
    void  (*self_substr)(struct CTextStack *self, long starter, long end);


    struct CTextStack *(*pop)(struct CTextStack *self, long starter, long end);
    void(*self_pop)(struct CTextStack *self, long starter, long end);



    struct CTextStack *(*insert_at)(struct CTextStack *self,long point, const char *element);
    void (*self_insert_at)(struct CTextStack *self,long point, const char *element);

    struct CTextStack *(*replace)(struct CTextStack *self,const char *element, const char *element_to_replace);
    void (*self_replace)(struct CTextStack *self,const char *element, const char *element_to_replace);


    struct CTextStack *(*replace_long)(struct CTextStack *self,const char *element, long element_to_replace);
    void(*self_replace_long)(struct CTextStack *self,const char *element, long element_to_replace);


    struct CTextStack *(*replace_double)(struct CTextStack *self,const char *element, double element_to_replace);
    void (*self_replace_double)(struct CTextStack *self,const char *element, double element_to_replace);


    struct CTextStack * (*lower)(struct CTextStack *self);
    void(*self_lower)(struct CTextStack *self);

    struct CTextStack * (*upper)(struct CTextStack *self);
    void(*self_upper)(struct CTextStack *self);


    struct CTextStack * (*reverse)(struct CTextStack *self);
    void(*self_reverse)(struct CTextStack *self);

    struct CTextStack * (*trim)(struct CTextStack *self);
    void(*self_trim)(struct CTextStack *self);

    bool (*starts_with)(struct CTextStack *self, const char *element);
    bool (*ends_with)(struct CTextStack *self, const char *element);

    long (*index_of)(struct CTextStack *self, const char *element);
    long (*index_of_char)(struct CTextStack *self, char element);
}CTextStackModule;

CTextStackModule newCTextStackModule();




long private_CText_transform_index(long size, long value);


void private_ctext_generate_formated_text(
    struct CTextStack *stack,
    const char *format,
    va_list argptr
    );



//
// Created by jurandi on 14-06-2023.
//
struct CTextStack * newCTextStack(const char *line_breaker, const char *separator){
    struct CTextStack *self = (struct CTextStack*)malloc(sizeof(struct CTextStack));
    self->rendered_text = (char*)malloc(2);
    strcpy(self->rendered_text,"\0");
    self->rendered_text_alocation_size = 2;
    self->size = 0;
    self->ident_level = 0;
    self->line_breaker = strdup(line_breaker);
    self->separator = strdup(separator);


    return self;
}

struct CTextStack *newCTextStack_string(const char *starter){
    CTextStack *self = newCTextStack("","");
    if(starter){
        CTextStack_format(self,starter);
    }
    return self;
}

struct CTextStack *newCTextStack_string_getting_ownership(const char *starter){
    CTextStack *self = newCTextStack("","");
    free(self->rendered_text);
    self->rendered_text = (char*)starter;
    self->size = strlen(starter);
    self->rendered_text_alocation_size = self->size;
    return self;
}
struct CTextStack *newCTextStack_string_empty(){
    return  newCTextStack("","");
}








char * CTextStack_self_transform_in_string_and_self_clear(struct CTextStack *self){
    free(self->line_breaker);
    free(self->separator);
    char *result = self->rendered_text;
    free(self);
    return result;
}

void private_CTextStack_parse_ownership(struct CTextStack *self, struct CTextStack *new_stack){

    free(self->line_breaker);
    free(self->separator);
    free(self->rendered_text);

    self->rendered_text_alocation_size = new_stack->rendered_text_alocation_size;
    self->size = new_stack->size;
    self->ident_level = new_stack->ident_level;


    self->line_breaker = new_stack->line_breaker;
    self->separator = new_stack->separator;
    self->rendered_text = new_stack->rendered_text;
    free(new_stack);

}
void CTextStack_restart(struct CTextStack *self){
    free(self->rendered_text);
    self->rendered_text = (char*)malloc(2);
    strcpy(self->rendered_text,"\0");
    self->rendered_text_alocation_size = 2;
    self->size = 0;
    self->ident_level = 0;
}

void CTextStack_represent(struct CTextStack *self){
    printf("%s\n",self->rendered_text);
}


void CTextStack_free(struct CTextStack *self){
    free(self->line_breaker);
    free(self->separator);
    free(self->rendered_text);
    free(self);
}

struct CTextStack * CTextStack_clone(struct CTextStack *self){
    CTextStack *new_stack = newCTextStack(self->line_breaker,self->separator);
    new_stack->ident_level = self->ident_level;
    CTextStack_text(new_stack,self->rendered_text);
    return new_stack;
}




struct CTextStack * CTextStack_substr(struct CTextStack *self, long starter, long end){

    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;
    long formated_starter = private_CText_transform_index(self->size, starter);
    long formated_end = private_CText_transform_index(self->size, end);

    if(formated_starter == formated_end){
        CTextStack_format(new_element,"%c",self->rendered_text[formated_starter]);
        return new_element;
    }

    for(long i =formated_starter; i < formated_end; i++){
        CTextStack_format(new_element,"%c",self->rendered_text[i]);
    }

    return new_element;

}

void CTextStack_self_substr(struct CTextStack *self, long starter, long end){
    CTextStack *new_stack = CTextStack_substr(self,starter,end);
    private_CTextStack_parse_ownership(self,new_stack);

}


struct CTextStack *CTextStack_replace(struct CTextStack *self,const char *element, const char *element_to_replace){

    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;

    long element_size = (long)strlen(element);
    for(long i = 0; i < self->size;i++){
        CTextStack  *possible_ocurrence  = CTextStack_substr(self,i,i+element_size);

        if(strcmp(possible_ocurrence->rendered_text,element)== 0){
            CTextStack_text(new_element,element_to_replace);
            i+=element_size -1;
        }

        else{
            CTextStack_format(new_element,"%c",self->rendered_text[i]);
        }

        CTextStack_free(possible_ocurrence);

    }
    return new_element;
}

void CTextStack_self_replace(struct CTextStack *self,const char *element, const char *element_to_replace){
    CTextStack  *new_stack = CTextStack_replace(self,element,element_to_replace);
    private_CTextStack_parse_ownership(self,new_stack);
}


struct CTextStack *CTextStack_replace_long(struct CTextStack *self,const char *element, long element_to_replace){
    char num_conversion[20] = {0};
    sprintf(num_conversion,"%ld",element_to_replace);
    return CTextStack_replace(self,element,num_conversion);
}


void CTextStack_self_replace_long(struct CTextStack *self,const char *element, long element_to_replace){
    CTextStack  *new_stack = CTextStack_replace_long(self,element,element_to_replace);
    private_CTextStack_parse_ownership(self,new_stack);
}


struct CTextStack *CTextStack_replace_double(struct CTextStack *self,const char *element, double element_to_replace){
    CTextStack  *num_formated = newCTextStack_string_empty();
    CTextStack_format(num_formated,"%f",element_to_replace);
    CTextStack  *result = CTextStack_replace(self,element,num_formated->rendered_text);
    CTextStack_free(num_formated);
    return result;
}


void CTextStack_self_replace_double(struct CTextStack *self,const char *element, double element_to_replace){
    CTextStack  *new_stack = CTextStack_replace_double(self,element,element_to_replace);
    private_CTextStack_parse_ownership(self,new_stack);
}



long CtextStack_index_of(struct  CTextStack *self,const char *element){
    long element_size = (long)strlen(element);
    for(int i = 0; i < self->size; i++){
        CTextStack  *possible_element = CTextStack_substr(self,i,i+element_size);
        if(strcmp(possible_element->rendered_text,element) == 0){
            CTextStack_free(possible_element);
            return i;
        }
        CTextStack_free(possible_element);

    }
    return -1;
}


long CtextStack_index_of_char(struct  CTextStack *self,char element){
    for(int i = 0; i < self->size; i++) {
        if(self->rendered_text[i] == element){
            return i;
        }
    }
    return -1;
}
bool CtextStack_starts_with(struct  CTextStack *self,const char *element){
    long element_size = strlen(element);
    CTextStack  *separated = CTextStack_substr(self,0,element_size);
    if(strcmp(separated->rendered_text,element) == 0){
        CTextStack_free(separated);
        return true;
    }
    CTextStack_free(separated);
    return false;
}

bool CtextStack_ends_with(struct  CTextStack *self,const char *element){
    long element_size = strlen(element);
    CTextStack  *separated = CTextStack_substr(self,self->size -element_size,-1);

    if(strcmp(separated->rendered_text,element) == 0){
        CTextStack_free(separated);
        return true;
    }
    CTextStack_free(separated);
    return false;
}



struct CTextStack *CTextStack_lower(struct CTextStack *self){
    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;
    for(long i =0; i < self->size; i++){
        char current = self->rendered_text[i];
        CTextStack_format(new_element,"%c",tolower(current));
    }
    return new_element;
}

void CTextStack_self_lower(struct CTextStack *self){
    CTextStack *new_stack = CTextStack_lower(self);
    private_CTextStack_parse_ownership(self,new_stack);
}

struct CTextStack *CTextStack_upper(struct CTextStack *self){
    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;
    for(long i =0; i < self->size; i++){
        char current = self->rendered_text[i];
        CTextStack_format(new_element,"%c",toupper(current));
    }
    return new_element;
}


void CTextStack_self_upper(struct CTextStack *self){
    CTextStack *new_stack = CTextStack_upper(self);
    private_CTextStack_parse_ownership(self,new_stack);
}


struct CTextStack *CTextStack_reverse(struct CTextStack *self){
    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;
    for(long i = (long)self->size; i >= 0 ; i--){
        CTextStack_format(new_element,"%c",self->rendered_text[i]);
    }
    return new_element;

}

void CTextStack_self_reverse(struct CTextStack *self){
    CTextStack *new_stack = CTextStack_reverse(self);
    private_CTextStack_parse_ownership(self,new_stack);
}



struct CTextStack *CTextStack_pop(struct CTextStack *self, long starter, long end){
    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;
    long formated_starter = private_CText_transform_index(self->size, starter);
    long formated_end = private_CText_transform_index(self->size, end);

    for(int i =0; i < self->size; i ++){
        if(i >= formated_starter && i <= formated_end){
            continue;
        }
        CTextStack_format(new_element,"%c",self->rendered_text[i]);
    }
    return new_element;
}


void  CTextStack_self_pop(struct CTextStack *self, long starter, long end){
    CTextStack  *new_stack = CTextStack_pop(self, starter, end);
    private_CTextStack_parse_ownership(self,new_stack);
}


struct CTextStack *CTextStack_insert_at(struct CTextStack *self,long point, const char *element){

    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;

    long converted_point = private_CText_transform_index(self->size, point);
    for(long i = 0; i < converted_point; i++){
        CTextStack_format(new_element,"%c",self->rendered_text[i]);
    }
    CTextStack_text(new_element,element);
    for(long i = converted_point; i < self->size; i++){
        CTextStack_format(new_element,"%c",self->rendered_text[i]);
    }
    return new_element;
}

void CTextStack_self_insert_at(struct CTextStack *self,long point, const char *element){
    CTextStack  *new_stack = CTextStack_insert_at(self, point,element);
    private_CTextStack_parse_ownership(self,new_stack);
}


struct CTextStack *CTextStack_trim(struct CTextStack *self){

    CTextStack  *invalid_elements = newCTextStack_string("\t\r\n ");
    long start_point = 0;
    for(int i = 0; i < self->size; i ++){
        char current_char =self->rendered_text[i];
        long invalid_point = CtextStack_index_of_char(invalid_elements,current_char);
        bool is_invalid = invalid_point != -1;
        if(!is_invalid){
            start_point = i;
            break;
        }
    }
    long end_point = -1;
    for(long i = (long)self->size -1; i >= 0; i--){

        char current_char =self->rendered_text[i];
        long invalid_point = CtextStack_index_of_char(invalid_elements,current_char);
        bool is_invalid = invalid_point != -1;
        if(!is_invalid){
            end_point = i+1;
            break;
        }
    }
    CTextStack_free(invalid_elements);
    return CTextStack_substr(self,start_point,end_point);

}


void CTextStack_self_trim(struct CTextStack *self){
    CTextStack  *new_stack = CTextStack_trim(self);
    private_CTextStack_parse_ownership(self,new_stack);
}


void private_ctext_text_double_size_if_reachs(struct CTextStack *self){

    while(self->size >= (self->rendered_text_alocation_size - 2)){
        self->rendered_text_alocation_size  =  (self->rendered_text_alocation_size  * 2)+2;
        self->rendered_text = (char*)(realloc(
            self->rendered_text,self->rendered_text_alocation_size
        ));
    }
}

void CTextStack_text(struct CTextStack *self, const char *text){

    if (!text || !text[0]) {
        // Tratar caso de ponteiro nulo ou string vazia
        return;
    }

    size_t text_size = strlen(text);
    
    self->size += text_size;
    private_ctext_text_double_size_if_reachs(self);
    
    memcpy(
            self->rendered_text + self->size - text_size,
        text,
        text_size 
    );
    self->rendered_text[self->size] = '\0';
}



void CTextStack_segment_text(struct CTextStack *self, const char *text){
    CTextStack_segment(self);
    CTextStack_text(self,text);
}


void CTextStack_format(struct CTextStack *self, const char *format, ...){
    va_list  argptr;
    va_start(argptr, format);
    private_ctext_generate_formated_text(self,format,argptr);
}

void CTextStack_segment_format(struct CTextStack *self, const char *format, ...){
    CTextStack_segment(self);
    va_list  argptr;
    va_start(argptr, format);
    private_ctext_generate_formated_text(self,format,argptr);
}


void CTextStack_segment(struct CTextStack *self){

    CTextStack_text(self,self->line_breaker);

    for(int i=0;i<self->ident_level;i++){
        CTextStack_text(self,self->separator);

    }


}

void CTextStack_$open(struct CTextStack *self, const char *tag, const char *format, ...){
    CTextStack_segment(self);
    CTextStack_format(self, "%c",'<');
    CTextStack_text(self,tag);


    if(format!=NULL){
        CTextStack_format(self, "%c",' ');

        va_list  argptr;
        va_start(argptr, format);
        private_ctext_generate_formated_text(self,format,argptr);
    }
    CTextStack_format(self, "%c",'>');


    self->ident_level += 1;
}

void CTextStack_only$open(struct CTextStack *self, const char *tag, const char *format, ...){
    CTextStack_segment(self);
    CTextStack_format(self, "%c",'<');

    CTextStack_text(self,tag);


    if(format!=NULL){
        CTextStack_format(self, "%c",' ');
        va_list  argptr;
        va_start(argptr, format);
        private_ctext_generate_formated_text(self,format,argptr);
    }
    CTextStack_format(self, "%c",'>');


}

void CTextStack_auto$close(struct CTextStack *self, const char *tag, const char *format, ...){
    CTextStack_segment(self);
    CTextStack_format(self, "%c",'<');

    CTextStack_text(self,tag);


    if(format!=NULL){
        CTextStack_format(self, "%c",' ');

        va_list  argptr;
        va_start(argptr, format);
        private_ctext_generate_formated_text(self,format,argptr);
    }
    CTextStack_text(self,"/>");

}

void ctext_open(struct CTextStack *self, const char *tag){
    if(tag ==  NULL){

        self->ident_level += 1;
        return;
    }
    CTextStack_$open(self, tag, NULL);
}




void ctext_close(struct CTextStack *self, const char *tag){

    if(tag==NULL){
        self->ident_level -= 1;

        return;
    }
    self->ident_level -= 1;
    CTextStack_segment(self);


    CTextStack_text(self,"</");
    CTextStack_text(self,tag);
    CTextStack_format(self, "%c",'>');

}





CTextStackModule newCTextStackModule(){
    struct CTextStackModule self = {0};

    self.text = CTextStack_text;
    self.segment_text = CTextStack_segment_text;
    self.format = CTextStack_format;
    self.segment = CTextStack_segment;
    self.segment_format = CTextStack_segment_format;
    self.$open = CTextStack_$open;
    self.only$open =CTextStack_only$open;
    self.auto$close = CTextStack_auto$close;
    self.open = ctext_open;
    self.close = ctext_close;
    self.free =  CTextStack_free;
    self.clone = CTextStack_clone;
    self.represent = CTextStack_represent;
    self.self_transform_in_string_and_self_clear = CTextStack_self_transform_in_string_and_self_clear;
    self.restart = CTextStack_restart;
    self.substr = CTextStack_substr;
    self.self_substr =CTextStack_self_substr;

    self.pop = CTextStack_pop;
    self.self_pop =CTextStack_self_pop;

    self.replace = CTextStack_replace;
    self.self_replace = CTextStack_self_replace;

    self.replace_long = CTextStack_replace_long;
    self.self_replace_long =CTextStack_self_replace_long;


    self.replace_double = CTextStack_replace_double;
    self.self_replace_double =CTextStack_self_replace_double;

    self.insert_at = CTextStack_insert_at;
    self.self_insert_at  = CTextStack_self_insert_at;


    self.index_of = CtextStack_index_of;
    self.index_of_char = CtextStack_index_of_char;

    self.lower = CTextStack_lower;
    self.self_lower = CTextStack_self_lower;

    self.upper = CTextStack_upper;
    self.self_upper = CTextStack_self_upper;

    self.starts_with = CtextStack_starts_with;
    self.ends_with = CtextStack_ends_with;

    self.reverse = CTextStack_reverse;
    self.self_reverse = CTextStack_self_reverse;

    self.trim = CTextStack_trim;
    self.self_trim = CTextStack_self_trim;


    return self;
}




void private_ctext_generate_formated_text(
        struct CTextStack *stack,const char *format,va_list argptr){
    long  text_size = strlen(format);

    int i;
    for(i =0;i < text_size -1 ;i++){

        char single_test[3] = {format[i],format[i+1],'\0'};
        char double_test[4] = {0};


        if(i < text_size -2){
            strcpy(double_test,single_test);
            double_test[2] = format[i+2];
            double_test[3] = '\0';

        }

        if(strcmp(single_test,"%d") == 0) {
            char result[20] ={0};
            sprintf(result,"%ld", va_arg(argptr,long));
            CTextStack_text(stack,result);
            i+=1;
            continue;
        }

        if(strcmp(single_test,"%f") == 0) {
            char result_text[20]= {0};

            sprintf(result_text,"%lf", va_arg(argptr,double ));

            for(int t = 18; t > 0; t--){
                char current_char = result_text[t];
                if(current_char != '0' && current_char != '\0'){

                    if(current_char == '.'){
                        result_text[t+2]  = '\0';
                    }
                    else{
                        result_text[t+1]  = '\0';
                    }

                    break;
                }
            }
            CTextStack_text(stack,result_text);
            i+=1;
            continue;
        }

        else if(strcmp(single_test,"%c") == 0){
            char result = va_arg(argptr,int);
            char element[2] = {result,'\0'};
            CTextStack_text(stack,element);
            i+=1;
            continue;
        }


        else if(strcmp(single_test,"%b") == 0){
            bool value = va_arg(argptr,int);
            if(value){
                CTextStack_text(stack,"true");
            }else{
                CTextStack_text(stack,"false");
            }
            i+=1;
            continue;
        }

        else if(strcmp(double_test,"%sc") == 0){
            char *value = va_arg(argptr,char*);
            CTextStack_text(stack,value);
            free(value);
            i+=2;
            continue;
        }

        else if(strcmp(single_test,"%s") == 0){
            const char *value = va_arg(argptr,const char*);
            CTextStack_text(stack,value);
            i+=1;
            continue;
        }
        else if(strcmp(double_test,"%tc") == 0){
            struct CTextStack *new_stack = (struct  CTextStack*)va_arg(argptr,void *);
            char *result = CTextStack_self_transform_in_string_and_self_clear(new_stack);
            CTextStack_text(stack,result);
            free(result);
            i+=2;
            continue;
        }

        else if(strcmp(single_test,"%t") == 0){
            struct CTextStack *new_stack = (struct  CTextStack*)va_arg(argptr,void *);
            CTextStack_text(stack,new_stack->rendered_text);
            i+=1;
            continue;
        }

        char element[2] = {format[i],'\0'};
        CTextStack_text(stack,element);

        }



    if(text_size > 0 && text_size> i){
        char element[2] = {format[text_size-1],'\0'};
        CTextStack_text(stack,element);
    }

    va_end(argptr);
}


long private_CText_transform_index(long size , long value){
    long formated_value = value;

    if(formated_value >= size){
        formated_value = size;
    }

    if(formated_value  < 0){
        formated_value = size + (formated_value +1);
    }
    if(formated_value <0){
        formated_value = 0;
    }
    return formated_value;
}

#endif // CTEXTENGINE_H