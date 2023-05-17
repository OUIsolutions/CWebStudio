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
//
// Created by jurandi on 18-04-2023.
//
#define HTML "html"
#define BODY "body"
#define DIV "div"
#define H1 "h1"
#define H2 "h2"
#define H3 "h3"
#define H4 "h4"
#define H5 "h5"
#define H6 "h6"
#define P "p"
#define SPAN "span"
#define A "a"
#define IMG "img"
#define INPUT "input"
#define BUTTON "button"
#define TABLE "table"
#define TR "tr"
#define TD "td"
#define TH "th"
#define THEAD "thead"
#define TBODY "tbody"
#define TFOOT "tfoot"
#define UL "ul"
#define LI "li"
#define OL "ol"
#define FORM "form"
#define LABEL "label"
#define SELECT "select"
#define OPTION "option"
#define TEXTAREA "textarea"
#define SCRIPT "script"
#define STYLE "style"
#define META "meta"
#define LINK "link"
#define HEAD "head"
#define BASE "base"
#define BR "br"
#define HR "hr"
#define TITLE "title"
#define IFRAME "iframe"
#define NAV "nav"
#define HEADER "header"
#define FOOTER "footer"
#define SECTION "section"
#define ARTICLE "article"
#define ASIDE "aside"
#define DETAILS "details"
#define SUMMARY "summary"
#define DIALOG "dialog"
#define MENU "menu"
#define MENUITEM "menuitem"
#define MAIN "main"
#define CANVAS "canvas"
#define AUDIO "audio"
#define VIDEO "video"
#define SOURCE "source"
#define TRACK "track"
#define EMBED "embed"
#define PARAM "param"
    





#define CTEXT_LINE_BREAKER "\n"
#define CTEXT_SEPARATOR "   "


struct CTextStack{
    char *rendered_text;
    size_t rendered_text_alocation_size;
    size_t rendered_text_size;
    
    char *line_breaker;
    char *separator;
    int ident_level;

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

    void (*free)(struct CTextStack *self);

    void (*restart)(struct CTextStack *self);

};

struct CTextStack *newCTextStack(const char *line_breaker, const char *separator);


void ctext_text(struct CTextStack *self, const char *text);

void private_ctext_text_double_size_if_reachs(struct CTextStack *self);

void ctext_segment_text(struct CTextStack *self, const char *text);

void private_ctext_segment_char(struct CTextStack *self, char t);

void ctext_segment(struct CTextStack *self);

void ctext_$open(struct CTextStack *self, const char *tag, const char *format,...);

void ctext_only$open(struct CTextStack *self, const char *tag, const char *format,...);

void ctext_auto$close(struct CTextStack *self, const char *tag, const char *format,...);


void ctext_format(struct CTextStack *self, const char *format, ...);

void ctext_segment_format(struct CTextStack *self, const char *format, ...);

void ctext_open(struct CTextStack *self, const char *tag);


void ctext_close(struct CTextStack *self, const char *tag);

void ctext_free(struct CTextStack *self);

void ctext_restart(struct CTextStack *self);
void private_ctext_generate_formated_text(
    struct CTextStack *stack,
    const char *format,
    va_list argptr
    );


struct CTextStack * newCTextStack(const char *line_breaker, const char *separator){
    struct CTextStack *self = (struct CTextStack*)malloc(sizeof(struct CTextStack));
    self->rendered_text = (char*)malloc(2);
    strcpy(self->rendered_text,"\0");
    self->rendered_text_alocation_size = 2;
    self->rendered_text_size = 0;
    self->ident_level = 0;
    self->line_breaker = strdup(line_breaker);
    self->separator = strdup(separator);

    self->text = ctext_text;
    self->segment_text = ctext_segment_text;
    self->format = ctext_format;
    self->segment = ctext_segment;
    self->segment_format = ctext_segment_format;
    self->$open = ctext_$open;
    self->only$open =ctext_only$open;
    self->auto$close = ctext_auto$close;
    self->open = ctext_open;
    self->close = ctext_close;
    self->free =  ctext_free;
    self->restart = ctext_restart;
    return self;
}


void ctext_free(struct CTextStack *self){
    free(self->line_breaker);
    free(self->separator);
    free(self->rendered_text);
    free(self);
}

void ctext_restart(struct CTextStack *self){
    free(self->rendered_text);
    self->rendered_text = (char*)malloc(2);
    strcpy(self->rendered_text,"\0");
    self->rendered_text_alocation_size = 2;
    self->rendered_text_size = 0;
    self->ident_level = 0;
}
void private_ctext_text_double_size_if_reachs(struct CTextStack *self){
    

    while(self->rendered_text_size >= (self->rendered_text_alocation_size-2)){
      
        self->rendered_text_alocation_size  =  (self->rendered_text_alocation_size  * 2)+2;
        self->rendered_text = (char*)(realloc(
            self->rendered_text,self->rendered_text_alocation_size
        ));

    }
}
void ctext_text(struct CTextStack *self, const char *text){

    if (!text || !text[0]) {
        // Tratar caso de ponteiro nulo ou string vazia
        return;
    }

    size_t text_size = strlen(text);
    
    self->rendered_text_size += text_size;
    private_ctext_text_double_size_if_reachs(self);
    
    memcpy(
        self->rendered_text + self->rendered_text_size - text_size,
        text,
        text_size 
    );
    self->rendered_text[self->rendered_text_size] = '\0';
}

void private_ctext_segment_char(struct CTextStack *self, char t){
    self->rendered_text_size += 1;
    private_ctext_text_double_size_if_reachs(self);
    self->rendered_text[self->rendered_text_size-1] = t;
    self->rendered_text[self->rendered_text_size] = '\0';
}

void ctext_segment_text(struct CTextStack *self, const char *text){
    self->segment(self);
    self->text(self,text);
}


void ctext_format(struct CTextStack *self, const char *format, ...){
    va_list  argptr;
    va_start(argptr, format);
    private_ctext_generate_formated_text(self,format,argptr);
}

void ctext_segment_format(struct CTextStack *self, const char *format, ...){
    self->segment(self);
    va_list  argptr;
    va_start(argptr, format);
    private_ctext_generate_formated_text(self,format,argptr);
}


void ctext_segment(struct CTextStack *self){

    self->text(self,self->line_breaker);

    for(int i=0;i<self->ident_level;i++){
        self->text(self,self->separator);

    }


}

void ctext_$open(struct CTextStack *self, const char *tag, const char *format,...){
    self->segment(self);    
    private_ctext_segment_char(self,'<');
    self->text(self,tag);


    if(format!=NULL){
        private_ctext_segment_char(self,' ');
        va_list  argptr;
        va_start(argptr, format);
        private_ctext_generate_formated_text(self,format,argptr);
    }
    private_ctext_segment_char(self,'>');

    self->ident_level += 1;
}

void ctext_only$open(struct CTextStack *self, const char *tag, const char *format, ...){
    self->segment(self);
    private_ctext_segment_char(self,'<');
    self->text(self,tag);


    if(format!=NULL){
        private_ctext_segment_char(self,' ');
        va_list  argptr;
        va_start(argptr, format);
        private_ctext_generate_formated_text(self,format,argptr);
    }
    private_ctext_segment_char(self,'>');


}
void ctext_auto$close(struct CTextStack *self, const char *tag, const char *format,...){
    self->segment(self);
    private_ctext_segment_char(self,'<');
    self->text(self,tag);


    if(format!=NULL){
        private_ctext_segment_char(self,' ');
        va_list  argptr;
        va_start(argptr, format);
        private_ctext_generate_formated_text(self,format,argptr);
    }
    self->text(self,"/>");

}
void ctext_open(struct CTextStack *self, const char *tag){
    if(tag ==  NULL){

        self->ident_level += 1;
        return;
    }

    self->$open(self, tag, NULL);
}




void ctext_close(struct CTextStack *self, const char *tag){

    if(tag==NULL){
        self->ident_level -= 1;

        return;
    }
    self->ident_level -= 1;
    self->segment(self);


    self->text(self,"</");
    self->text(self,tag);
    private_ctext_segment_char(self,'>');
}



void private_ctext_generate_formated_text(
        struct CTextStack *stack,const char *format,va_list argptr){
    int text_size = strlen(format);


    if(format[0] != '%'){
        char element[2] = {format[0],'\0'};
        stack->text(stack,element);
    }

    for(int i =1;i < text_size ;i++){
        char last_char =  format[i-1];
        char current_char =  format[i];

        if(last_char =='%'){

            if(current_char == 'd' || current_char == 'i'){
                char result[10];
                sprintf(result,"%d", va_arg(argptr,int));
                stack->text(stack,result);
            }

            else if(current_char == 'c'){
                char result = va_arg(argptr,int);
                private_ctext_segment_char(stack,result);
            }
            

            else if(current_char == 'b'){
                bool value = va_arg(argptr,int);
                if(value){
                    stack->text(stack,"true");
                }else{
                    stack->text(stack,"false");
                }
            }
            else if(current_char == 's'){
                const char *value = va_arg(argptr,const char*);
                stack->text(stack,value);
            }
            else{
                
                private_ctext_segment_char(stack,current_char);
            }



            continue;
        }

        if(current_char == '%'){
            continue;
        }

        char element[2] = {current_char,'\0'};
        stack->text(stack,element);
    }

    va_end(argptr);
}
#endif // CTEXTENGINE_H