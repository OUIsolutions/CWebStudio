
#include "../uniq.definitions_requirements.h"

char * private_CWebHydration_format_vaarg(const char *expresion, va_list args){

    va_list args_copy;
    va_copy(args_copy, args);
    long required_size = vsnprintf(NULL, 0,expresion,args_copy);
    va_end(args_copy);
    char *buffer = (char*)malloc(sizeof(char) * required_size + 2);
    vsnprintf(buffer,sizeof (char) * required_size+1,expresion,args);
    return buffer;
}
char * private_CWebHydration_format(const char *expresion, ...){
    va_list  args;
    va_start(args,expresion);
    char *result = private_CWebHydration_format_vaarg(expresion,args);
    va_end(args);
    return  result;
}