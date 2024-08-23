#include "../imports.h"

#ifndef PRIVATE_CTEXT_STACK_TYPE_H
#define PRIVATE_CTEXT_STACK_TYPE_H
typedef struct CTextStack{

    char *rendered_text;
    size_t rendered_text_alocation_size;
    size_t size;

    char *line_breaker;
    char *separator;
    int ident_level;

}CTextStack;
#endif
