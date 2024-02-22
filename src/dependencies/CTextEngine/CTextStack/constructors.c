//
// Created by jurandi on 14-06-2023.
//
struct CTextStack * newCTextStack(const char *line_breaker, const char *separator){
    struct CTextStack *self = (struct CTextStack*)malloc(sizeof(struct CTextStack));
    *self = (CTextStack){0};
    self->rendered_text = (char*)malloc(2);
    strcpy(self->rendered_text,"\0");
    self->rendered_text_alocation_size = 2;

    self->line_breaker = strdup(line_breaker);
    self->separator = strdup(separator);


    return self;
}

struct CTextStack *newCTextStack_string(const char *starter){
    CTextStack *self = newCTextStack("","");
    if(starter){
        CTextStack_format(self,"%s", starter);
    }
    return self;
}

struct CTextStack *newCTextStack_string_format(const char *format, ...){
    CTextStack *self = newCTextStack("","");
    va_list  argptr;
    va_start(argptr, format);
    private_ctext_generate_formated_text(self,format,argptr);
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