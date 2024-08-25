//path: src/one.c




#ifndef __CWEBSTUDIO_H
#define __CWEBSTUDIO_H


//path: src/definition.c

//path: src/declaration.h
//path: src/imports.h
#ifndef PRIVATE_CWEB_HTTP_IMPORTS_H
#define PRIVATE_CWEB_HTTP_IMPORTS_H

#include <sys/wait.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <signal.h>
#include <sys/resource.h>

#include <arpa/inet.h>
#include <unistd.h>

#endif //PRIVATE_CWEB_HTTP_IMPORTS_H

//path: src/dependencies/declaration.h
#ifndef PRIVATE_CWEB_HTTP_DEPENDENCIES
#define PRIVATE_CWEB_HTTP_DEPENDENCIES

#ifndef CTEXTENGINE_H
//path: src/dependencies/CTextEngine/declaration.h
//path: src/dependencies/CTextEngine/imports.h
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>



//path: src/dependencies/CTextEngine/constants/all.h
#ifndef PRIVATE_CTEXT_CONST
#define PRIVATE_CTEXT_CONST

//path: src/dependencies/CTextEngine/constants/ownership.h

#define CTEXT_BY_OWNESHIP 1
#define CTEXT_BY_COPY 2
#define CTEXT_BY_REFERENCE 3


//path: src/dependencies/CTextEngine/constants/types.h


#define CTEXT_LINE_BREAKER "\n"
#define CTEXT_SEPARATOR "   "

#define CTEXT_LONG 1
#define CTEXT_DOUBLE 2
#define CTEXT_BOOL 3
#define CTEXT_STRING 4


//path: src/dependencies/CTextEngine/constants/tags.h
////
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
    





#endif


//path: src/dependencies/CTextEngine/macros/all.h

#ifndef PRIVATE_CTEXT_MACROS
#define PRIVATE_CTEXT_MACROS
//path: src/dependencies/CTextEngine/macros/scope.h

#define CTextScope(s,t)\
ctext_open(s, t);\
for(int snaunduwwqwetjsdvda = 0; snaunduwwqwetjsdvda < 1; ctext_close(s, t), ++snaunduwwqwetjsdvda)

#define CTextScope_format(s,t, ...)\
CTextStack_open_format(s,t,__VA_ARGS__);\
for(int snaunduwwqwetjsdvda = 0; snaunduwwqwetjsdvda < 1; ctext_close(s, t), ++snaunduwwqwetjsdvda)


#endif


//path: src/dependencies/CTextEngine/types/all.h
//path: src/dependencies/CTextEngine/types/CTextArray.h

//path: src/dependencies/CTextEngine/types/CTextStack.h



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



#ifndef  PRIVATE_CTEXT_ARRAY_TYPE_H
#define PRIVATE_CTEXT_ARRAY_TYPE_H
typedef struct CTextArray{

    CTextStack **stacks;
    long size;


}CTextArray;

#endif




//path: src/dependencies/CTextEngine/types/namespace/all.h
//path: src/dependencies/CTextEngine/types/namespace/array.h


#ifndef PRIVATE_CTEXT_ARRAY_NAMESPACE_MODULE
#define PRIVATE_CTEXT_ARRAY_NAMESPACE_MODULE
typedef struct CTextArrayModule{
    CTextArray *(*newArray)();
    void (*append)(CTextArray *self,CTextStack *element);
    void (*append_string)(CTextArray *self,const char *element);
    CTextStack * (*join)(CTextArray *self,const char *separator);

    CTextArray * (*map)(CTextArray *self, CTextStack *(caller)(CTextStack* element));
    CTextArray * (*filter)(CTextArray *self, bool (caller)(CTextStack* element));
    void  (*foreach)(CTextArray *self, void (*caller)(CTextStack* element));
    bool (*includes)(CTextArray *self,const char *element);
    void (*represent)(CTextArray *self);
    void (*free)(CTextArray *self);

}CTextArrayModule;
#endif


//path: src/dependencies/CTextEngine/types/namespace/namespace.h



//path: src/dependencies/CTextEngine/types/namespace/stack.h



#ifndef  PRIVATE_CTEXT_STACK_NAMESPACE_MODULE
#define PRIVATE_CTEXT_STACK_NAMESPACE_MODULE

typedef struct CTextStackModule{

    //admnistrative methods
    CTextStack  *(*newStack)(const char *line_breaker, const char *separator);
    CTextStack *(*newStack_string)(const char *starter);
    CTextStack *(*newStack_string_format)(const char *format, ...);

    CTextStack *(*newStack_string_getting_ownership)(const char *starter);
    CTextStack *(*newStack_string_empty)();

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

    void (*open_format)(struct CTextStack *self, const char *tag, const char *format,...);

    void (*only_open_format)(struct CTextStack *self, const char *tag, const char *format,...);

    void (*auto_close_format)(struct CTextStack *self, const char *tag, const char *format,...);

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

    struct CTextStack *(*captalize)(struct CTextStack *self);
    void (*self_captalize)(struct CTextStack *self);

    struct CTextStack * (*reverse)(struct CTextStack *self);
    void(*self_reverse)(struct CTextStack *self);

    struct CTextStack * (*trim)(struct CTextStack *self);
    void(*self_trim)(struct CTextStack *self);

    bool (*starts_with)(struct CTextStack *self, const char *element);
    bool (*ends_with)(struct CTextStack *self, const char *element);

    bool (*equal)(struct  CTextStack *self,const char *element);
    int (*typeof_element)(struct CTextStack *self);
    bool (*is_a_num)(struct CTextStack *self);

    const char * (*typeof_in_str)(struct CTextStack *self);
    bool  (*parse_to_bool)(struct CTextStack *self);
    long  (*parse_to_integer)(struct CTextStack *self);
    double  (*parse_to_double)(struct CTextStack *self);

    long (*index_of)(struct CTextStack *self, const char *element);
    long (*index_of_char)(struct CTextStack *self, char element);
}CTextStackModule;


#endif



#ifndef PRIVATE_CTEXT_NAMESPACE_TYPE
#define PRIVATE_CTEXT_NAMESPACE_TYPE
typedef struct CTextNamespace{

    CTextArrayModule array;
    CTextStackModule stack;

}CTextNamespace;
#endif








//path: src/dependencies/CTextEngine/functions/declaration.h

#ifndef PRIVATE_CTEXT_FUNCTION_DECLARATION
#define PRIVATE_CTEXT_FUNCTION_DECLARATION
//path: src/dependencies/CTextEngine/functions/CTextStack/declaration.h
//path: src/dependencies/CTextEngine/functions/CTextStack/admnistrative_methods/admnistrative_methods.h



//path: src/dependencies/CTextEngine/functions/CTextStack/admnistrative_methods/../unique.declaration_requirements.h
//path: src/dependencies/CTextEngine/functions/CTextStack/admnistrative_methods/../../unique.declaration_requirements.h












char * CTextStack_self_transform_in_string_and_self_clear(struct CTextStack *self);

void private_CTextStack_parse_ownership(struct CTextStack *self, struct CTextStack *new_stack);

void CTextStack_restart(struct CTextStack *self);

void CTextStack_represent(struct CTextStack *self);

void CTextStack_free(struct CTextStack *self);

 CTextStack * CTextStack_clone(struct CTextStack *self);


//path: src/dependencies/CTextEngine/functions/CTextStack/algo_methods/algo_methods.h





 CTextStack * CTextStack_substr(struct CTextStack *self, long starter, long end);


void CTextStack_self_substr(struct CTextStack *self, long starter, long end);

struct CTextStack *CTextStack_replace(struct CTextStack *self,const char *element, const char *element_to_replace);

void CTextStack_self_replace(struct CTextStack *self,const char *element, const char *element_to_replace);


struct CTextStack *CTextStack_replace_long(struct CTextStack *self,const char *element, long element_to_replace);



void CTextStack_self_replace_long(struct CTextStack *self,const char *element, long element_to_replace);


struct CTextStack *CTextStack_replace_double(struct CTextStack *self,const char *element, double element_to_replace);


void CTextStack_self_replace_double(struct CTextStack *self,const char *element, double element_to_replace);


long CTextStack_index_of(struct  CTextStack *self, const char *element);

long CTextStack_index_of_char(struct  CTextStack *self, char element);

bool CTextStack_starts_with(struct  CTextStack *self, const char *element);


bool CTextStack_ends_with(struct  CTextStack *self, const char *element);



struct CTextStack *CTextStack_lower(struct CTextStack *self);

void CTextStack_self_lower(struct CTextStack *self);


struct CTextStack *CTextStack_upper(struct CTextStack *self);


CTextStack *CTextStack_captalize(struct CTextStack *self);

void CTextStack_self_captalize(struct CTextStack *self);


void CTextStack_self_upper(struct CTextStack *self);


 CTextStack *CTextStack_reverse(struct CTextStack *self);

void CTextStack_self_reverse(struct CTextStack *self);


CTextStack *CTextStack_pop(struct CTextStack *self, long starter, long end);


void  CTextStack_self_pop(struct CTextStack *self, long starter, long end);



CTextStack *CTextStack_insert_at(struct CTextStack *self,long point, const char *element);


void CTextStack_self_insert_at(struct CTextStack *self,long point, const char *element);

CTextStack *CTextStack_trim(struct CTextStack *self);

void CTextStack_self_trim(struct CTextStack *self);

bool CTextStack_equal(  CTextStack *self,const char *element);


//path: src/dependencies/CTextEngine/functions/CTextStack/constructors/constructors.h



 CTextStack * newCTextStack(const char *line_breaker, const char *separator);

 CTextStack *newCTextStack_string(const char *starter);


 CTextStack *newCTextStack_string_format(const char *format, ...);


 CTextStack *newCTextStack_string_getting_ownership(const char *starter);

 CTextStack *newCTextStack_string_empty();


//path: src/dependencies/CTextEngine/functions/CTextStack/parsers/parsers.h



int CTextStack_typeof(struct CTextStack *self);

bool CTextStack_is_a_num(struct CTextStack *self);

const char * CTextStack_typeof_in_str(struct CTextStack *self);

bool  CTextStack_parse_to_bool(struct CTextStack *self);

long  CTextStack_parse_to_integer(struct CTextStack *self);

double  CTextStack_parse_to_double(struct CTextStack *self);


//path: src/dependencies/CTextEngine/functions/CTextStack/render_methods/render_methods.h



void private_ctext_text_double_size_if_reachs(struct CTextStack *self);


void CTextStack_text(struct CTextStack *self, const char *text);



void CTextStack_segment_text(struct CTextStack *self, const char *text);


void CTextStack_format(struct CTextStack *self, const char *format, ...);


void CTextStack_segment_format(struct CTextStack *self, const char *format, ...);



void CTextStack_segment(struct CTextStack *self);


void CTextStack_open_format(struct CTextStack *self, const char *tag, const char *format, ...);




void CTextStack_only_open_format(struct CTextStack *self, const char *tag, const char *format, ...);


void CTextStack_auto_close_format(struct CTextStack *self, const char *tag, const char *format, ...);


void ctext_open(struct CTextStack *self, const char *tag);



void ctext_close(struct CTextStack *self, const char *tag);




//path: src/dependencies/CTextEngine/functions/CTextArray/CTextArray.h




CTextArray * newCTextArray();


void CTextArray_append(CTextArray *self,CTextStack *element);


void CTextArray_append_string(CTextArray *self,const char *element);

CTextStack * CTextArray_join(CTextArray *self,const char *separator);

CTextArray * CTextArray_split(const char *element,const char *target);

CTextArray * CTextArray_map(CTextArray *self, CTextStack *(caller)(CTextStack* element));

CTextArray * CTextArray_filter(CTextArray *self, bool (caller)(CTextStack* element));

void  CTextArray_foreach(CTextArray *self, void (*caller)(CTextStack* element));

bool CTextArray_includes(CTextArray *self,const char *element);

void  CTextArray_free(CTextArray *self);

void CTextArray_represent(CTextArray *self);


//path: src/dependencies/CTextEngine/functions/CTextNamespace/declaration.h
//path: src/dependencies/CTextEngine/functions/CTextNamespace/CTexStackModule/CTextStackModule.h



CTextStackModule newCTextStackModule();


//path: src/dependencies/CTextEngine/functions/CTextNamespace/CTextArrayModule/CTextArrayModule.h





CTextArrayModule newCTextArrayModule();


//path: src/dependencies/CTextEngine/functions/CTextNamespace/CTextNamespace/CTextNamespace.h




CTextNamespace newCTextNamespace();



//path: src/dependencies/CTextEngine/functions/extras/extras.h


long private_CText_transform_index(long size, long value);


void private_ctext_generate_formated_text(
    struct CTextStack *stack,
    const char *format,
    va_list argptr
    );

#endif




#endif
#ifndef cJSON__h
//path: src/dependencies/cJson/cJSON.h


#ifndef cJSON__h
#define cJSON__h

#ifdef __cplusplus
extern "C"
{
#endif

#if !defined(__WINDOWS__) && (defined(WIN32) || defined(WIN64) || defined(_MSC_VER) || defined(_WIN32))
#define __WINDOWS__
#endif

#ifdef __WINDOWS__



#define CJSON_CDECL __cdecl
#define CJSON_STDCALL __stdcall


#if !defined(CJSON_HIDE_SYMBOLS) && !defined(CJSON_IMPORT_SYMBOLS) && !defined(CJSON_EXPORT_SYMBOLS)
#define CJSON_EXPORT_SYMBOLS
#endif

#if defined(CJSON_HIDE_SYMBOLS)
#define CJSON_PUBLIC(type)   type CJSON_STDCALL
#elif defined(CJSON_EXPORT_SYMBOLS)
#define CJSON_PUBLIC(type)   __declspec(dllexport) type CJSON_STDCALL
#elif defined(CJSON_IMPORT_SYMBOLS)
#define CJSON_PUBLIC(type)   __declspec(dllimport) type CJSON_STDCALL
#endif
#else 
#define CJSON_CDECL
#define CJSON_STDCALL

#if (defined(__GNUC__) || defined(__SUNPRO_CC) || defined (__SUNPRO_C)) && defined(CJSON_API_VISIBILITY)
#define CJSON_PUBLIC(type)   __attribute__((visibility("default"))) type
#else
#define CJSON_PUBLIC(type) type
#endif
#endif


#define CJSON_VERSION_MAJOR 1
#define CJSON_VERSION_MINOR 7
#define CJSON_VERSION_PATCH 15

#include <stddef.h>


#define cJSON_Invalid (0)
#define cJSON_False  (1 << 0)
#define cJSON_True   (1 << 1)
#define cJSON_NULL   (1 << 2)
#define cJSON_Number (1 << 3)
#define cJSON_String (1 << 4)
#define cJSON_Array  (1 << 5)
#define cJSON_Object (1 << 6)
#define cJSON_Raw    (1 << 7) 

#define cJSON_IsReference 256
#define cJSON_StringIsConst 512


typedef struct cJSON
{
    
    struct cJSON *next;
    struct cJSON *prev;
    
    struct cJSON *child;

    
    int type;

    
    char *valuestring;
    
    int valueint;
    
    double valuedouble;

    
    char *string;
} cJSON;

typedef struct cJSON_Hooks
{
      
      void *(CJSON_CDECL *malloc_fn)(size_t sz);
      void (CJSON_CDECL *free_fn)(void *ptr);
} cJSON_Hooks;

typedef int cJSON_bool;


#ifndef CJSON_NESTING_LIMIT
#define CJSON_NESTING_LIMIT 1000
#endif


CJSON_PUBLIC(const char*) cJSON_Version(void);


CJSON_PUBLIC(void) cJSON_InitHooks(cJSON_Hooks* hooks);



CJSON_PUBLIC(cJSON *) cJSON_Parse(const char *value);
CJSON_PUBLIC(cJSON *) cJSON_ParseWithLength(const char *value, size_t buffer_length);


CJSON_PUBLIC(cJSON *) cJSON_ParseWithOpts(const char *value, const char **return_parse_end, cJSON_bool require_null_terminated);
CJSON_PUBLIC(cJSON *) cJSON_ParseWithLengthOpts(const char *value, size_t buffer_length, const char **return_parse_end, cJSON_bool require_null_terminated);


CJSON_PUBLIC(char *) cJSON_Print(const cJSON *item);

CJSON_PUBLIC(char *) cJSON_PrintUnformatted(const cJSON *item);

CJSON_PUBLIC(char *) cJSON_PrintBuffered(const cJSON *item, int prebuffer, cJSON_bool fmt);


CJSON_PUBLIC(cJSON_bool) cJSON_PrintPreallocated(cJSON *item, char *buffer, const int length, const cJSON_bool format);

CJSON_PUBLIC(void) cJSON_Delete(cJSON *item);


CJSON_PUBLIC(int) cJSON_GetArraySize(const cJSON *array);

CJSON_PUBLIC(cJSON *) cJSON_GetArrayItem(const cJSON *array, int index);

CJSON_PUBLIC(cJSON *) cJSON_GetObjectItem(const cJSON * const object, const char * const string);
CJSON_PUBLIC(cJSON *) cJSON_GetObjectItemCaseSensitive(const cJSON * const object, const char * const string);
CJSON_PUBLIC(cJSON_bool) cJSON_HasObjectItem(const cJSON *object, const char *string);

CJSON_PUBLIC(const char *) cJSON_GetErrorPtr(void);


CJSON_PUBLIC(char *) cJSON_GetStringValue(const cJSON * const item);
CJSON_PUBLIC(double) cJSON_GetNumberValue(const cJSON * const item);


CJSON_PUBLIC(cJSON_bool) cJSON_IsInvalid(const cJSON * const item);
CJSON_PUBLIC(cJSON_bool) cJSON_IsFalse(const cJSON * const item);
CJSON_PUBLIC(cJSON_bool) cJSON_IsTrue(const cJSON * const item);
CJSON_PUBLIC(cJSON_bool) cJSON_IsBool(const cJSON * const item);
CJSON_PUBLIC(cJSON_bool) cJSON_IsNull(const cJSON * const item);
CJSON_PUBLIC(cJSON_bool) cJSON_IsNumber(const cJSON * const item);
CJSON_PUBLIC(cJSON_bool) cJSON_IsString(const cJSON * const item);
CJSON_PUBLIC(cJSON_bool) cJSON_IsArray(const cJSON * const item);
CJSON_PUBLIC(cJSON_bool) cJSON_IsObject(const cJSON * const item);
CJSON_PUBLIC(cJSON_bool) cJSON_IsRaw(const cJSON * const item);


CJSON_PUBLIC(cJSON *) cJSON_CreateNull(void);
CJSON_PUBLIC(cJSON *) cJSON_CreateTrue(void);
CJSON_PUBLIC(cJSON *) cJSON_CreateFalse(void);
CJSON_PUBLIC(cJSON *) cJSON_CreateBool(cJSON_bool boolean);
CJSON_PUBLIC(cJSON *) cJSON_CreateNumber(double num);
CJSON_PUBLIC(cJSON *) cJSON_CreateString(const char *string);

CJSON_PUBLIC(cJSON *) cJSON_CreateRaw(const char *raw);
CJSON_PUBLIC(cJSON *) cJSON_CreateArray(void);
CJSON_PUBLIC(cJSON *) cJSON_CreateObject(void);


CJSON_PUBLIC(cJSON *) cJSON_CreateStringReference(const char *string);

CJSON_PUBLIC(cJSON *) cJSON_CreateObjectReference(const cJSON *child);
CJSON_PUBLIC(cJSON *) cJSON_CreateArrayReference(const cJSON *child);


CJSON_PUBLIC(cJSON *) cJSON_CreateIntArray(const int *numbers, int count);
CJSON_PUBLIC(cJSON *) cJSON_CreateFloatArray(const float *numbers, int count);
CJSON_PUBLIC(cJSON *) cJSON_CreateDoubleArray(const double *numbers, int count);
CJSON_PUBLIC(cJSON *) cJSON_CreateStringArray(const char *const *strings, int count);


CJSON_PUBLIC(cJSON_bool) cJSON_AddItemToArray(cJSON *array, cJSON *item);
CJSON_PUBLIC(cJSON_bool) cJSON_AddItemToObject(cJSON *object, const char *string, cJSON *item);

CJSON_PUBLIC(cJSON_bool) cJSON_AddItemToObjectCS(cJSON *object, const char *string, cJSON *item);

CJSON_PUBLIC(cJSON_bool) cJSON_AddItemReferenceToArray(cJSON *array, cJSON *item);
CJSON_PUBLIC(cJSON_bool) cJSON_AddItemReferenceToObject(cJSON *object, const char *string, cJSON *item);


CJSON_PUBLIC(cJSON *) cJSON_DetachItemViaPointer(cJSON *parent, cJSON * const item);
CJSON_PUBLIC(cJSON *) cJSON_DetachItemFromArray(cJSON *array, int which);
CJSON_PUBLIC(void) cJSON_DeleteItemFromArray(cJSON *array, int which);
CJSON_PUBLIC(cJSON *) cJSON_DetachItemFromObject(cJSON *object, const char *string);
CJSON_PUBLIC(cJSON *) cJSON_DetachItemFromObjectCaseSensitive(cJSON *object, const char *string);
CJSON_PUBLIC(void) cJSON_DeleteItemFromObject(cJSON *object, const char *string);
CJSON_PUBLIC(void) cJSON_DeleteItemFromObjectCaseSensitive(cJSON *object, const char *string);


CJSON_PUBLIC(cJSON_bool) cJSON_InsertItemInArray(cJSON *array, int which, cJSON *newitem); 
CJSON_PUBLIC(cJSON_bool) cJSON_ReplaceItemViaPointer(cJSON * const parent, cJSON * const item, cJSON * replacement);
CJSON_PUBLIC(cJSON_bool) cJSON_ReplaceItemInArray(cJSON *array, int which, cJSON *newitem);
CJSON_PUBLIC(cJSON_bool) cJSON_ReplaceItemInObject(cJSON *object,const char *string,cJSON *newitem);
CJSON_PUBLIC(cJSON_bool) cJSON_ReplaceItemInObjectCaseSensitive(cJSON *object,const char *string,cJSON *newitem);


CJSON_PUBLIC(cJSON *) cJSON_Duplicate(const cJSON *item, cJSON_bool recurse);


CJSON_PUBLIC(cJSON_bool) cJSON_Compare(const cJSON * const a, const cJSON * const b, const cJSON_bool case_sensitive);


CJSON_PUBLIC(void) cJSON_Minify(char *json);


CJSON_PUBLIC(cJSON*) cJSON_AddNullToObject(cJSON * const object, const char * const name);
CJSON_PUBLIC(cJSON*) cJSON_AddTrueToObject(cJSON * const object, const char * const name);
CJSON_PUBLIC(cJSON*) cJSON_AddFalseToObject(cJSON * const object, const char * const name);
CJSON_PUBLIC(cJSON*) cJSON_AddBoolToObject(cJSON * const object, const char * const name, const cJSON_bool boolean);
CJSON_PUBLIC(cJSON*) cJSON_AddNumberToObject(cJSON * const object, const char * const name, const double number);
CJSON_PUBLIC(cJSON*) cJSON_AddStringToObject(cJSON * const object, const char * const name, const char * const string);
CJSON_PUBLIC(cJSON*) cJSON_AddRawToObject(cJSON * const object, const char * const name, const char * const raw);
CJSON_PUBLIC(cJSON*) cJSON_AddObjectToObject(cJSON * const object, const char * const name);
CJSON_PUBLIC(cJSON*) cJSON_AddArrayToObject(cJSON * const object, const char * const name);


#define cJSON_SetIntValue(object, number) ((object) ? (object)->valueint = (object)->valuedouble = (number) : (number))

CJSON_PUBLIC(double) cJSON_SetNumberHelper(cJSON *object, double number);
#define cJSON_SetNumberValue(object, number) ((object != NULL) ? cJSON_SetNumberHelper(object, (double)number) : (number))

CJSON_PUBLIC(char*) cJSON_SetValuestring(cJSON *object, const char *valuestring);


#define cJSON_SetBoolValue(object, boolValue) ( \
    (object != NULL && ((object)->type & (cJSON_False|cJSON_True))) ? \
    (object)->type=((object)->type &(~(cJSON_False|cJSON_True)))|((boolValue)?cJSON_True:cJSON_False) : \
    cJSON_Invalid\
)


#define cJSON_ArrayForEach(element, array) for(element = (array != NULL) ? (array)->child : NULL; element != NULL; element = element->next)


CJSON_PUBLIC(void *) cJSON_malloc(size_t size);
CJSON_PUBLIC(void) cJSON_free(void *object);

#ifdef __cplusplus
}
#endif

#endif

#undef cJSON__h
#endif


#ifndef  UNIVERSAL_GARBAGE_H
//path: src/dependencies/UniversalGarbage/declaration.h

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



//path: src/dependencies/UniversalGarbage/macros.h

#define UniversalGarbage_create_empty_struct(name,element_type) \
(element_type*)malloc(sizeof(element_type));    \
*name = (element_type){0};


#define UniversalGarbage_cast(value) ((void**)&value)


#define UniversalGarbage_add(garbage,deallocator_callback,value) \
    rawUniversalGarbage_add(garbage,(void(*)(void*))deallocator_callback,UniversalGarbage_cast(value))

#define UniversalGarbage_add_simple(garbage,value) \
     UniversalGarbage_add(garbage,free,value)


#define UniversalGarbage_add_return(garbage,deallocator_callback,value) \
        UniversalGarbage_add(garbage->return_values,deallocator_callback,value)


#define UniversalGarbage_add_simple_return(garbage,value) \
    UniversalGarbage_add_simple(garbage->return_values,value)



#define  UniversalGarbage_remove(garbage,value) \
    rawUniversalGarbage_remove(garbage,UniversalGarbage_cast(value));


#define  UniversalGarbage_disconnect(garbage,value) \
    rawUniversalGarbage_disconnect(garbage,UniversalGarbage_cast(value));




#define UniversalGarbage_reallocate(garbage,value) \
    rawUniversalGarbage_reallocate(garbage,UniversalGarbage_cast(value))


#define UniversalGarbage_resset(garbage,value) \
    rawUniversalGarbage_resset(garbage,UniversalGarbage_cast(value))


//path: src/dependencies/UniversalGarbage/types/all.h
//path: src/dependencies/UniversalGarbage/types/garbage.h
//path: src/dependencies/UniversalGarbage/types/garbage_element.h

#ifndef PRIVATE_UNIVERSGAL_GARBAGE_ELEMENT_TYPE
#define PRIVATE_UNIVERSGAL_GARBAGE_ELEMENT_TYPE
typedef struct privateUniversalGarbageElement{
    void **pointer;
    void (*deallocator_callback)(void *element);
    void *pointed_value;
}privateUniversalGarbageElement;
#endif



#ifndef  PRIVATE_UNIVERSAL_GARBAGE_TYPE
#define PRIVATE_UNIVERSAL_GARBAGE_TYPE


typedef  struct UniversalGarbage{

    struct UniversalGarbage *return_values;
    privateUniversalGarbageElement **elements;
    int  elements_size;
    bool is_the_root;

}UniversalGarbage;
#endif






//path: src/dependencies/UniversalGarbage/functions/declaration.h

//path: src/dependencies/UniversalGarbage/functions/garbage_element/garbage_element.h

//path: src/dependencies/UniversalGarbage/functions/garbage_element/../unique.declaration_requirements.h






void private_UniversalGarbageSimpleElement_free_pointed_value(privateUniversalGarbageElement *self);


void private_UniversalGarbageSimpleElement_free(privateUniversalGarbageElement *self);

privateUniversalGarbageElement * private_newUniversalGarbageSimpleElement(void (*dealocator_callback)(void *element), void **pointer);


//path: src/dependencies/UniversalGarbage/functions/garbage/garbage.h





UniversalGarbage * newUniversalGarbage();

UniversalGarbage * private_new_MainUniversalGarbage();



bool  rawUniversalGarbage_resset(UniversalGarbage *self, void **pointer);

bool  rawUniversalGarbage_remove(UniversalGarbage *self, void **pointer);

bool  rawUniversalGarbage_disconnect(UniversalGarbage *self, void **pointer);

bool rawUniversalGarbage_reallocate(UniversalGarbage *self, void **pointer);

bool  rawUniversalGarbage_add(UniversalGarbage *self,  void (*dealocator_callback)(void *element), void **pointer);

void private_UniversalGarbage_free_all_sub_elements(UniversalGarbage *self);

void UniversalGarbage_free_including_return(UniversalGarbage *self);

void UniversalGarbage_free(UniversalGarbage *self);






#endif


#endif


//path: src/consts/all.h
#ifndef PRIVATE_CWEB_HTTP_CONSTS_CONSTS
#define PRIVATE_CWEB_HTTP_CONSTS_CONSTS

//path: src/consts/request.h
#define INVALID_HTTP -1
#define MAX_HEADER_SIZE_CODE -2
#define MAX_HEADER_LEN 20000
#define MAX_LINE_LEN MAX_HEADER_LEN /2
#define READ_ERROR -3
#define MAX_CONTENT_SIZE -4
#define UNDEFINED_CONTENT -5
#define INVALID_JSON -6
#define CWEB_UTF_DECREMENTER  64
#define CWEB_C_NON_ASSCI_SIGIN -61


//path: src/consts/response.h

#define CWEB_AUTO_SET_CONTENT NULL
#define CWEB_OK  200
#define CWEB_NOT_FOUND 404
#define CWEB_BAD_REQUEST 400
#define CWEB_FORBIDDEN 403
#define CWEB_INTERNAL_SERVER_ERROR 500


//path: src/consts/hydratation/all.h
//path: src/consts/hydratation/callbacks.h
#define PRIVATE_CWEB_HYDRATION_CALLBACK_KEY "callback"
#define PRIVATE_CWEB_HYDRATION_ARGS_KEY "args"
#define PRIVATE_CWEB_HYDRATION_ID_KEY "id"
#define PRIVATE_CWEB_HYDRATION_HTML_KEY "html"
#define PRIVATE_CWEB_HYDRATION_MENSSAGE_KEY "menssage"


#define PRIVATE_CWEB_HYDRATION_ALERT "private_cweb_alert"
#define PRIVATE_CWEB_HYDRATION_DESTROY_BY_ID "private_cweb_destroy_by_id"
#define PRIVATE_CWEB_HYDRATION_REPLACE_BY_ID "private_cweb_hydration_replace_by_id"


//path: src/consts/hydratation/app.h
#define CWEB_HYDRATION_DEFAULT_BODY_SIZE 5000
#define CWEB_HYDRATION_CALBACK_HANDLER_ROUTE "/private_cweb_hydration_main_callback_handler"


//path: src/consts/hydratation/errors.h
#define CWEB_HYDRATION_NOT_BODY_JSON_PROVIDED 1
#define CWEB_HYDRATION_NOT_BODY_JSON_PROVIDED_MSG "json body not provided"

#define CWEB_HYDRATION_NOT_BODY_IS_NOT_OBJECT 2
#define CWEB_HYDRATION_NOT_BODY_IS_NOT_OBJECT_MSG  "json body not not object"


#define CWEB_HYDRATION_NAME_NOT_PROVIDED 3
#define CWEB_HYDRATION_NAME_NOT_PROVIDED_MSG  "body['name'] not provided"

#define CWEB_HYDRATION_NAME_NOT_STRING 4
#define CWEB_HYDRATION_NAME_NOT_STRING_MSG  "body['name'] its not string"


#define CWEB_HYDRATION_ARGS_NOT_PROVIDED 5
#define CWEB_HYDRATION_ARGS_NOT_PROVIDED_MSG  "body['args'] not provided"

#define CWEB_HYDRATION_ARGS_NOT_ARRAY 6
#define CWEB_HYDRATION_ARGS_NOT_ARRAY_MSG  "body['args'] its not array"


#define CWEB_HYDRATION_CONTENT_NOT_PROVIDED 7
#define CWEB_HYDRATION_CONTENT_NOT_PROVIDED_MSG  "body['content'] not provided"

#define CWEB_HYDRATION_CONTENT_NOT_OBJECT 8
#define CWEB_HYDRATION_CONTENT_NOT_OBJECT_MSG  "body['content'] not a object"


#define CWEB_HYDRATION_CONTENT_KEY_NOT_PROVIDED 9
#define CWEB_HYDRATION_CONTENT_KEY_NOT_PROVIDED_MSG  "body['content']['%s'] not provided at content"

#define CWEB_HYDRATION_CONTENT_SEARCH_NOT_ARRAY 10
#define CWEB_HYDRATION_CONTENT_SEARCH_NOT_ARRAY_MSG "body['content']['%s']   is not of array"



#define CWEB_HYDRATION_CONTENT_SEARCH_NOT_EXIST 11
#define CWEB_HYDRATION_CONTENT_SEARCH_NOT_EXIST_MSG "search at index %d  not exist"


#define CWEB_HYDRATION_SEARCH_ITEM_NOT_EXIST 12
#define CWEB_HYDRATION_SEARCH_ITEM_NOT_EXIST_MSG "body['content']['%s'][%d] not exist"


#define CWEB_HYDRATION_SEARCH_ITEM_WRONG_TYPE 13
#define CWEB_HYDRATION_SEARCH_ITEM_WRONG_TYPE_MSG "body['content']['%s'][%d] its not of type %s"


#define CWEB_HYDRATION_INDEX_ARGS_NOT_PROVIDED  14
#define CWEB_HYDRATION_INDEX_ARGS_NOT_PROVIDED_MSG  "body['args'][%d]  not provided"

#define CWEB_HYDRATION_INDEX_ARGS_WRONG_TYPE 15
#define CWEB_HYDRATION_INDEX_ARGS_WRONG_TYPE_MSG  "body['args'][%d] is not of type %s"



#define CWEB_BRIDGE_NOT_FOUND 16
#define CWEB_BRIDGE_NOT_FOUND_MSG  "bridge of name %s not found"

#define CWEB_SEARCH_NOT_EXIST 17
#define CWEB_SEARCH_NOT_EXIST_MSG "search at index %d not exist"

#define CWEB_HYDRATION_STRING "string"
#define CWEB_HYDRATION_BOOL  "bool"
#define CWEB_HYDRATION_NUMBER "number"


//path: src/consts/hydratation/keys.h



#define CWEB_HYDRATION_JSON_ERROR_CODE_KEY "error_code"
#define CWEB_HYDRATION_JSON_ERROR_MENSSAGE "error_menssage"
#define CWEB_HYDRATON_JSON_DATA "data"

#define CWEB_HYDRATON_JSON_NAME "name"
#define CWEB_HYDRATON_JSON_HTML "html"
#define CWEB_HYDRATON_JSON_MSG "msg"
#define CWEB_HYDRATON_JSON_CODE "code"
#define CWEB_HYDRATON_JSON_KEY "key"
#define CWEB_HYDRATON_JSON_QUERY_SELECTOR "query_selector"

#define CWEB_HYDRATON_JSON_VALUE "value"
#define CWEB_HYDRATION_JSON_URL "url"

#define CWEB_HYDRATON_JSON_ARGS "args"
#define CWEB_HYDRATON_JSON_CONTENT "content"





#endif //PRIVATE_CWEB_HTTP_CONSTS_CONSTS


//path: src/types/all.h

//path: src/types/namespace/all.h


//path: src/types/namespace/dict.h
//path: src/types/namespace/../dict.h
//path: src/types/namespace/../keyval.h
#ifndef PRIVATE_CWEB_HTTP_KEYVAL_TYPES
#define PRIVATE_CWEB_HTTP_KEYVAL_TYPES

typedef struct CwebKeyVal{
    char *key;
    char *value;

}CwebKeyVal;

#endif //PRIVATE_CWEB_HTTP_KEYVAL_TYPES



#ifndef PRIVATE_CWEB_HTTP_DICT_TYPES
#define PRIVATE_CWEB_HTTP_DICT_TYPES

typedef struct CwebDict {
  int size;
  CwebKeyVal **keys_vals;

}CwebDict;

#endif //PRIVATE_CWEB_HTTP_DICT_TYPES

//path: src/types/namespace/keyval.h



#ifndef PRIVATE_CWEB_HTTP_NAMESPACE_KEYVAL_TYPES
#define PRIVATE_CWEB_HTTP_NAMESPACE_KEYVAL_TYPES


typedef struct CwebKeyValModule{
    void (*represent)(CwebKeyVal *key_val);
    void (*free)(CwebKeyVal *key_val);
}CwebKeyValModule;

#endif //PRIVATE_CWEB_HTTP_NAMESPACE_KEYVAL_TYPES


#ifndef PRIVATE_CWEB_HTTP_NAMESPACE_DICT_TYPES
#define PRIVATE_CWEB_HTTP_NAMESPACE_DICT_TYPES

typedef struct CwebDictModule{


    CwebDict *(*newDict)();
    void  (*set)(CwebDict *dict,const char *key,const char *value);
    char* (*get)(CwebDict *dict,const char *key);
    char* (*get_by_normalized_key)(CwebDict *dict,const char *key,const char *chars_to_remove);
    void  (*free)(CwebDict *dict);
    void  (*represent)(CwebDict *dict);

    CwebKeyValModule keyval;

}CwebDictModule;

#endif //PRIVATE_CWEB_HTTP_NAMESPACE_DICT_TYPES



//path: src/types/namespace/hydration/all.h
//path: src/types/namespace/hydration/args.h

//path: src/types/namespace/hydration/../../hydration/all.h

//path: src/types/namespace/hydration/../../hydration/bridge.h

//path: src/types/namespace/hydration/../../hydration/../string_array.h
#ifndef PRIVATE_CWEB_HTTP_STRINGARRAY_TYPES
#define PRIVATE_CWEB_HTTP_STRINGARRAY_TYPES


typedef struct CwebStringArray {
  int size;         

  char **strings;       

}CwebStringArray; // End the structure with a semicolon

#endif //PRIVATE_CWEB_HTTP_STRINGARRAY_TYPES

//path: src/types/namespace/hydration/../../hydration/../request.h


//path: src/types/namespace/hydration/../../hydration/../uniq.tipes_requirements.h




#ifndef PRIVATE_CWEB_HTTP_REQUEST_TYPES
#define PRIVATE_CWEB_HTTP_REQUEST_TYPES

typedef struct CwebHttpRequest{

    char *url;
    int socket;
    char *route;
    char *method;
    char *client_ip;
    int content_error;
    CwebDict *params;
    CwebDict *headers;
    int content_length;
    unsigned char *content;
    cJSON *json;
    void *hydratation;
    void *extra_args;
    UniversalGarbage *garbage;

}CwebHttpRequest;

#endif //PRIVATE_CWEB_HTTP_REQUEST_TYPES



#ifndef PRIVATE_CWEB_HYDRATATION_BRIDGET_BRIDGET_TYPES
#define PRIVATE_CWEB_HYDRATATION_BRIDGET_BRIDGET_TYPES


typedef struct  CWebHyDrationBridge {
    char *name;
    void  *hydration;
    void  (*callback)(struct CWebHyDrationBridge *bridge);

    CwebStringArray *requirements_code;

    void *extra_args;

}CWebHyDrationBridge;

#endif //PRIVATE_CWEB_HYDRATATION_BRIDGET_BRIDGET_TYPES


//path: src/types/namespace/hydration/../../hydration/bridge_array.h




#ifndef PRIVATE_CWEB_HYDRATATION_BRIDGET_ARRAY_TYPES
#define PRIVATE_CWEB_HYDRATATION_BRIDGET_ARRAY_TYPES

typedef struct privateCWebHyDrationBridgeArray {
    CWebHyDrationBridge **elments;
    int size;

}privateCWebHyDrationBridgeArray;

#endif //PRIVATE_CWEB_HYDRATATION_BRIDGET_ARRAY_TYPES


//path: src/types/namespace/hydration/../../hydration/hydratation.h






#ifndef PRIVATE_CWEB_HYDRATATION_HYDRATATION_TYPES
#define PRIVATE_CWEB_HYDRATATION_HYDRATATION_TYPES

typedef struct CWebHyDration {
    CwebHttpRequest *request;
   const  char *error_bridge_name;
    char *error_msg;
    cJSON *response;
    cJSON *args;
    cJSON *content;

    int error_code;
    CTextStack *script_text;
    long max_content_size;
    privateCWebHyDrationBridgeArray *all_bridges;

}CWebHyDration;

#endif //PRIVATE_CWEB_HYDRATATION_HYDRATATION_TYPES


//path: src/types/namespace/hydration/../../hydration/search_result.h





#ifndef  PRIVATE_CWEB_HYDRATION_SEARCH_RESULT_TYPE
#define PRIVATE_CWEB_HYDRATION_SEARCH_RESULT_TYPE

typedef struct{
    CWebHyDrationBridge *bridge;
    cJSON *search;
    const char *name;
} CWebHyDrationSearchResult;

#endif


//path: src/types/namespace/hydration/../../hydration/search_requirements.h



#ifndef PRIVATE_CWEB_HYDRATION_SEARCH_REQUIREMENTS_TYPE
#define PRIVATE_CWEB_HYDRATION_SEARCH_REQUIREMENTS_TYPE
typedef  struct{
    char *name;
    CWebHyDrationBridge *bridge;
} CWebHyDrationSearchRequirements;
#endif




//path: src/types/namespace/hydration/../response.h


//path: src/types/namespace/hydration/../../response.h
#ifndef PRIVATE_CWEB_HTTP_RESPONSE_TYPES
#define PRIVATE_CWEB_HTTP_RESPONSE_TYPES

typedef struct CwebHttpResponse{
    int status_code;
    struct CwebDict *headers;
    int content_length;
    bool exist_content;
    unsigned char *content;

}CwebHttpResponse;

#endif // PRIVATE_CWEB_HTTP_RESPONSE_TYPES


#ifndef PRIVATE_CWEB_HTTP_NAMESPACE_RESPONSE_TYPES
#define PRIVATE_CWEB_HTTP_NAMESPACE_RESPONSE_TYPES


typedef struct CwebHttpResponseModule{

    CwebHttpResponse  * (*newHttpResponse)();

    CwebHttpResponse * (*send_any)(
            const char *content_type,
            size_t content_length,
            unsigned char *content,
            int status_code
    );
    CwebHttpResponse * (*send_json_string)(
            const char *content,
            int status_code
    );
    CwebHttpResponse * (*send_json_string_cleaning_memory)(
            char *content,
            int status_code
    );
    CwebHttpResponse * (*send_cJSON)(
            cJSON *content,
            int status_code
    );


    CwebHttpResponse * (*send_cJSON_cleaning_memory)(
            cJSON *content,
            int status_code
    );


    CwebHttpResponse * (*send_text)(
            const char *content,
            int status_code
    );

    CwebHttpResponse * (*send_text_cleaning_memory)(
            char *content,
            int status_code
    );

    CwebHttpResponse* (*send_rendered_CTextStack)(struct CTextStack *stack,int status_code);

    CwebHttpResponse* (*send_var_html)(const char *content,int status_code);

    CwebHttpResponse* (*send_var_html_cleaning_memory)(
            char *content,
            int status_code
    );

    CwebHttpResponse * (*send_file)(
            const char *file_path,
            const char *content_type,
            int status_code
    );



    void (*set_content)(CwebHttpResponse *response, unsigned char *content, int content_length);
    void (*add_header)(CwebHttpResponse *response,const char *key,const  char *value);
    char *(*generate_response)(CwebHttpResponse *response);
    void (*free)(CwebHttpResponse *response);

}CwebHttpResponseModule;

#endif //PRIVATE_CWEB_HTTP_NAMESPACE_RESPONSE_TYPES



#ifndef PRIVATE_CWEB_HYDRATATION_ARGS_NAMESPACE_TYPES
#define PRIVATE_CWEB_HYDRATATION_ARGS_NAMESPACE_TYPES


typedef struct CWebHydrationArgsNamespace {


    int   (*get_args_size)(CWebHyDrationBridge *self);
    bool   (*is_arg_number)(CWebHyDrationBridge *self,int index);
    bool   (*is_arg_bool)(CWebHyDrationBridge *self,int index);
    bool   (*is_arg_string)(CWebHyDrationBridge *self,int index);
    double  (*get_double_arg)(CWebHyDrationBridge *self,int index);
    long  (*get_long_arg)(CWebHyDrationBridge *self,int index);
    bool  (*get_bool_arg)(CWebHyDrationBridge *self,int index);
    char* (*get_str_arg)(CWebHyDrationBridge *self,int index);
    cJSON * (*get_cJSON_arg)(CWebHyDrationBridge *self,int index);

}CWebHydrationArgsNamespace;
#endif


//path: src/types/namespace/hydration/search_requirements.h






#ifndef PRIVATE_CWEB_HYDRATATION_REQUIREMENTS_NAMESPACE_TYPES
#define PRIVATE_CWEB_HYDRATATION_REQUIREMENTS_NAMESPACE_TYPES


typedef struct CWebHydrationSearchRequirementsNamespace {




    CWebHyDrationSearchRequirements * (*newSearchRequirements)(CWebHyDrationBridge *self, const char *name,...);

    void (*add_function)(CWebHyDrationSearchRequirements *self,const char *function,...);
    void (*add_elements_by_query_selector)(
        CWebHyDrationSearchRequirements *self,
        const char *query_selector,
        ...
    );
    void (*add_elements_by_query_selector_not_auto_converting)(
        CWebHyDrationSearchRequirements *self,
        const char *query_selector,
        ...
    );
    void (*add_elements_by_attribute)(
        CWebHyDrationSearchRequirements *self,
       const char *attribute,
       const char*attribute_value,
       ...
    );
    void (*add_elements_by_attribute_not_auto_converting)(
        CWebHyDrationSearchRequirements *self,
        const char *attribute,
        const char*attribute_value,
        ...
    );

    void (*add_elements_by_class_name)(
        CWebHyDrationSearchRequirements *self,
        const char*class_value,
        ...
    );

    void (*add_elements_by_class_name_not_auto_converting)(
        CWebHyDrationSearchRequirements *self,
        const char*class_value,...
    );

    void (*add_elements_by_id)(
        CWebHyDrationSearchRequirements *self,
        const char*id_values,
        ...
    );

    void (*add_elements_by_id_not_auto_converting)(
        CWebHyDrationSearchRequirements *self,
        const char*id_values,
        ...
    );

    void (*add_session_storage_item_not_converting)(
        CWebHyDrationSearchRequirements *self,
        const char *name,
        ...
    );


    void (*add_element_by_id_setting_search_as_same_name)(
        CWebHyDrationBridge *self, const char *id
    );

    void (*add_element_by_id_setting_search_as_same_name_not_formmating)(
        CWebHyDrationBridge *self, const char *id
    );
    void (*add_session_storage_item)(
        CWebHyDrationSearchRequirements *self,
        const char *name,
        ...
    );

    void (*add_value_cookie_by_key)(CWebHyDrationSearchRequirements *self, const char *key);
    void (*add_confirm)(CWebHyDrationSearchRequirements *self, const char*message, ...);
    void (*add_prompt)(CWebHyDrationSearchRequirements *self, const char *message, ...);

}CWebHydrationSearchRequirementsNamespace;
#endif


//path: src/types/namespace/hydration/search_result.h






#ifndef PRIVATE_CWEB_HYDRATATION_SEARCH_RESULT_NAMESPACE_TYPE
#define PRIVATE_CWEB_HYDRATATION_SEARCH_RESULT_NAMESPACE_TYPE


typedef struct CWebHydrationSearchResultNamespace {

    int  (*get_total_avaialible_searchs)(CWebHyDrationBridge *self);
    CWebHyDrationSearchResult * (*get_search_by_index)(CWebHyDrationBridge *self,int index);
    CWebHyDrationSearchResult * (*get_search_by_name)(CWebHyDrationBridge *self,const char *name,...);
    bool (*search_exist)(CWebHyDrationBridge *self,const char *name,...);
    double (*get_double_from_first_element_of_search)(CWebHyDrationBridge *self,const char *name,...);
    long (*get_long_from_first_element_of_search)(CWebHyDrationBridge *self,const char *name,...);
    bool (*get_bool_from_first_element_of_search)(CWebHyDrationBridge *self,const char *name,...);
    char* (*get_string_from_first_element_of_search)(CWebHyDrationBridge *self,const char *name,...);
    cJSON* (*get_cJSON_from_first_element_of_search)(CWebHyDrationBridge *self,const char *name,...);
    int  (*get_total_itens)(CWebHyDrationSearchResult *self);
    bool  (*search_item_exist)(CWebHyDrationSearchResult *self,int index);
    bool  (*is_search_item_number)(CWebHyDrationSearchResult *self,int index);
    bool  (*is_search_item_bool)(CWebHyDrationSearchResult *self,int index);
    bool  (*is_search_item_string)(CWebHyDrationSearchResult *self,int index);
    double (*get_double)(CWebHyDrationSearchResult *self,int  index);
    long (*get_long)(CWebHyDrationSearchResult *self,int  index);
    bool (*get_bool)(CWebHyDrationSearchResult *self,int  index);
    char*  (*get_string)(CWebHyDrationSearchResult *self,int  index);
    cJSON *  (*get_cJSON)(CWebHyDrationSearchResult *self,int  index);

}CWebHydrationSearchResultNamespace;
#endif


//path: src/types/namespace/hydration/hydratation.h


//path: src/types/namespace/hydration/bridge.h








//path: src/types/namespace/hydration/actions.h






#ifndef PRIVATE_CWEB_HYDRATATION_RESPONSE_NAMESPACE_TYPES
#define PRIVATE_CWEB_HYDRATATION_RESPONSE_NAMESPACE_TYPES


typedef struct CWebHydrationResponseNamespace {
    void (*replace_element_by_query_selector)(
        CWebHyDrationBridge *self,
        const char *query_selector,
        const char *code,
        ...
    );

    void (*append_by_query_selector)(
        CWebHyDrationBridge *self,
        const char *query_selector,
        const char *code,
        ...
    );


    void (*destroy_by_query_selector)(
        CWebHyDrationBridge *self,
        const char * query_selecor
    );



    void (*hide_element_by_query_selector)(
    CWebHyDrationBridge *self,
    const char *query_selecor);

    void (*unhide_element_by_query_selector)(
        CWebHyDrationBridge *self,
        const char *query_selector
    );
    void (*hide_element_by_id)(CWebHyDrationBridge *self,const char *id);
    void (*unhide_element_by_id)(CWebHyDrationBridge *self,const char *id);
    void (*append_by_id)(CWebHyDrationBridge *self,const char *id, const char *code,...);

    void (*set_session_storage_data)(CWebHyDrationBridge *self,const char*key, const char *value,...);
    void (*alert)(CWebHyDrationBridge *self,const char *menssage,...);
    void (*execute_script)(CWebHyDrationBridge *self,const char *code,...);
    void (*replace_element_by_id)(CWebHyDrationBridge *self,const char *id, const char *code,...);
    void (*destroy_by_id)(CWebHyDrationBridge *self,const char * id);
    void (*redirect)(CWebHyDrationBridge *self, const char *url);
    void (*add_cookie_with_time)(CWebHyDrationBridge *self, const char *key, long time, const char *value, ...);
    void (*add_cookie)(CWebHyDrationBridge *self, const char *key, const char *value, ...);
    void (*delet_cookie)(CWebHyDrationBridge *self, const char *key);
    void (*console_log)(CWebHyDrationBridge *self,const char *menssage,...);
    void (*console_warn)(CWebHyDrationBridge *self,const char *menssage,...);
    void (*console_error)(CWebHyDrationBridge *self,const char *menssage,...);
    void (*console_clear)(CWebHyDrationBridge *self);


}CWebHydrationActionsNamespace;

#endif



#ifndef PRIVATE_CWEB_HYDRATATION_BRIDGE_NAMESPACE_TYPES
#define PRIVATE_CWEB_HYDRATATION_BRIDGE_NAMESPACE_TYPES

typedef struct CWebHydrationBridgeNamespace{

    CWebHyDrationBridge * (*create_bridge)(CWebHyDration *self,const char *name,void (*callback)(CWebHyDrationBridge *));
    char *(*call)(CWebHyDrationBridge *self,const char *func_args,...);
    char *(*onclick)(CWebHyDrationBridge *self,const char *func_args,...);
    char *(*onfoccusout)(CWebHyDrationBridge *self,const char *func_args,...);

    CTextStack * (*create_stack)(CWebHyDrationBridge *self);
    CTextStack * (*create_empty_stack)(CWebHyDrationBridge *self);

    bool (*has_errors)(CWebHyDrationBridge *self);
    CWebHyDrationBridge * (*get_child_bridge)(CWebHyDration *self,const char *name);
    CWebHyDrationBridge * (*get_brother_bridge)(CWebHyDrationBridge *self,const char *name);

}CWebHydrationBridgeNamespace;

#endif //PRIVATE_CWEB_HYDRATATION_HYDRATATION_NAMESPACE_TYPES



#ifndef PRIVATE_CWEB_HYDRATATION_HYDRATATION_NAMESPACE_TYPES
#define PRIVATE_CWEB_HYDRATATION_HYDRATATION_NAMESPACE_TYPES

typedef struct CWebHydrationNamespace{
    CWebHyDration *(*newCWebHyDration)(CwebHttpRequest *request);
    bool (*is_the_trigger)(CWebHyDration *self);
    char *(*create_script)(CWebHyDration *self);
    CwebHttpResponse *(*generate_response)(CWebHyDration *self);
    CTextStack  * (*create_stack)(CWebHyDration *self);
    CTextStack  * (*create_empty_stack)(CWebHyDration *self);
    CWebHydrationBridgeNamespace bridge;
    CWebHydrationActionsNamespace actions;
    CWebHydrationSearchRequirementsNamespace search_requirements;
    CWebHydrationSearchResultNamespace search_result;
    CWebHydrationArgsNamespace args;
}CWebHydrationNamespace;

#endif //PRIVATE_CWEB_HYDRATATION_HYDRATATION_NAMESPACE_TYPES




//path: src/types/namespace/request.h





#ifndef PRIVATE_CWEB_HTTP_NAMESPACE_REQUEST_TYPES
#define PRIVATE_CWEB_HTTP_NAMESPACE_REQUEST_TYPES


typedef struct CwebHttpRequestModule{
    CwebHttpRequest *(*newCwebHttpRequest)(int socket);
    unsigned char*(*read_content)(struct CwebHttpRequest *self,long max_content_size);
    cJSON * (*read_cJSON)(CwebHttpRequest *self, long max_content_size);

    void (*set_url)(struct CwebHttpRequest *self,const char *url);
    void (*set_route)(struct CwebHttpRequest *self,const char *route);
    void (*set_method)(struct CwebHttpRequest *self,const char *method);

    void (*add_header)(struct CwebHttpRequest *self,const char *key,const char *value);
    void (*add_param)(struct CwebHttpRequest *self,const char *key,const char *value);
    void (*set_content_string)(struct CwebHttpRequest *self,const char *content);


    char *(*get_header)(struct CwebHttpRequest *self,const char *key);
    char *(*get_header_by_normalized_key)(
            struct CwebHttpRequest *self,
            const char *key,
            const char *chars_to_remove
    );

    char *(*get_param)(struct CwebHttpRequest *self,const char *key);
    char *(*get_param_by_sanitized_key)(struct CwebHttpRequest *self,const char *key,
                                        const char *chars_to_remove);


    int (*parse_http_request)(struct CwebHttpRequest *self);

    CTextStack *(*create_empty_stack)(CwebHttpRequest *self);
    CTextStack *(*create_stack)(CwebHttpRequest *self);


    void (*free)(struct CwebHttpRequest *request);
    void (*represent)(struct CwebHttpRequest *request);
}CwebHttpRequestModule;

#endif //PRIVATE_CWEB_HTTP_NAMESPACE_REQUEST_TYPES




//path: src/types/namespace/server.h
//path: src/types/namespace/../server.h





#ifndef PRIVATE_CWEB_HTTP_SERVER_TYPES
#define PRIVATE_CWEB_HTTP_SERVER_TYPES

 typedef struct CwebServer{
    int port;
    int function_timeout;
    double client_timeout;
    int max_queue;
    bool single_process;
    long max_requests;
    bool allow_cors;
    bool use_static;
    const char *static_folder;
    bool use_cache;

    //methods
    CwebHttpResponse *(*request_handler)(CwebHttpRequest *request);

}CwebServer;

#endif //PRIVATE_CWEB_HTTP_SERVER_TYPES


#ifndef PRIVATE_CWEB_HTTP_NAMESPACE_SERVER_TYPES
#define PRIVATE_CWEB_HTTP_NAMESPACE_SERVER_TYPES


typedef struct CwebServerModule{
    CwebServer (*newServer)(int port , CwebHttpResponse *(*request_handler)(CwebHttpRequest *request));
    int (*start)(struct  CwebServer *self);
}CwebServerModule;

#endif //PRIVATE_CWEB_HTTP_NAMESPACE_SERVER_TYPES

//path: src/types/namespace/string.h



#ifndef PRIVATE_CWEB_HTTP_NAMESPACE_STRING_TYPES
#define PRIVATE_CWEB_HTTP_NAMESPACE_STRING_TYPES

typedef struct CwebStringArrayModule{
    CwebStringArray *(*newStringArray)();
    void (*set)( CwebStringArray *self,int index,const char *value);
    void (*add)( CwebStringArray *self,const char *string);
    void (*merge)(CwebStringArray *self, CwebStringArray *other);
    void (*represent)(CwebStringArray *self);
    int (*find)(CwebStringArray *self,const char *string);

    void (*free)(CwebStringArray *self);
}CwebStringArrayModule;

#endif //PRIVATE_CWEB_HTTP_NAMESPACE_STRING_TYPES

//path: src/types/namespace/namespace.h













#ifndef PRIVATE_CWEB_HTTP_NAMESPACE_NAMESPACE_TYPES
#define PRIVATE_CWEB_HTTP_NAMESPACE_NAMESPACE_TYPES


typedef struct CwebNamespace{
    CwebDictModule dict;
    CwebHttpRequestModule request;
    CwebHttpResponseModule response;
    CwebServerModule server;
    CwebStringArrayModule  string_array;
    CWebHydrationNamespace hydration;
}CwebNamespace;

#endif //PRIVATE_CWEB_HTTP_NAMESPACE_NAMESPACE_TYPES




//path: src/types/static/all.h
//path: src/types/static/recursion_element.h
#ifndef PRIVATE_CWEB_RECURSION_EEMENT_TYPE
#define PRIVATE_CWEB_RECURSION_EEMENT_TYPE

typedef struct {
    char  *file;
    char *included;

}privateCwebRecursionElement;

#endif


//path: src/types/static/recursion_list.h



#ifndef  PRIVATE_CWEB_RECURSION_LIST
#define PRIVATE_CWEB_RECURSION_LIST

typedef struct{

    privateCwebRecursionElement **elements;
    int size;

}privateCwebRecursionList;
#endif



















//path: src/macros/all.h
#ifndef PRIVATE_CWEB_MACROS
#define  PRIVATE_CWEB_MACROS
//path: src/macros/debug.h
#ifdef CWEB_DEBUG
#define cweb_print(...) printf(__VA_ARGS__);
#else
#define cweb_print(...);
#endif


//path: src/macros/hydration.h



#endif


//path: src/functions/declarations.h
#ifndef PRIVATE_CWEB_FUNCTIONS
#define PRIVATE_CWEB_FUNCTIONS
//path: src/functions/string_array/string_array.h
//path: src/functions/string_array/../uniq.declaration_requirements.h







CwebStringArray * newCwebStringArray();

int  CwebStringArray_find(struct CwebStringArray *self, const char *string);
void CwebStringArray_add(struct CwebStringArray *self, const char *string);

void CwebStringArray_add_getting_ownership(struct CwebStringArray *self, char *string);

void CwebStringArray_merge(struct CwebStringArray *self, struct CwebStringArray *other);
void CwebStringArray_represent(struct CwebStringArray *self);
void CwebStringArray_free(struct CwebStringArray *self);
void CwebStringArray_set(struct CwebStringArray *self, int index, const char *value);


//path: src/functions/strings/strings.h




char *cweb_parse_string_to_lower(const char *old_string);

char *cweb_parse_string_to_upper(const char *old_string);

char *cweb_normalize_string(const char *old_string,const char *invalid_chars);

bool cweb_starts_with(const char *string, const char *prefix);

char *cweb_replace_string_once(const char *target, const char *old_element, const char *new_element);

char* cweb_replace_string(const char *target, const char *old_element, const char *new_element);


//path: src/functions/extras/extras.h




unsigned char *cweb_load_any_content(const char * path,int *size,bool *is_binary);

char *cweb_load_string_file_content(const char * path);

unsigned char *cweb_load_binary_content(const char * path,int *size);


const char *cweb_generate_content_type(const char *file_name);

char *private_cweb_convert_url_encoded_text(const char *text);



char * private_CWeb_format_vaarg(const char *expresion, va_list args);

char * private_CWeb_format(const char *expresion, ...);char *private_cweb_convert_to_hexa(const char *data);



//path: src/functions/dict/declaration.h
//path: src/functions/dict/keyval/key_val.h
//path: src/functions/dict/keyval/../uniq.declaration_requirements.h







 CwebKeyVal* newCwebKeyVal(const char *key, const  char *value);
void CwebKeyVal_represent( CwebKeyVal *self);
void CwebKeyVal_free( CwebKeyVal *self);


//path: src/functions/dict/dict/dict.h



CwebDict *newCwebDict();
void CwebDict_set(CwebDict *self, const  char *key, const char *value);
char *CwebDict_get(CwebDict *self, const char *key);

char *CwebDict_get_by_normalized_key(
  CwebDict *self,
  const char *key,
  const char *chars_to_remove
);

void CwebDict_represent(CwebDict *dict);
void CwebDict_free(CwebDict *self);



//path: src/functions/response/declaration.h
//path: src/functions/response/response/response.h





struct CwebHttpResponse *newCwebHttpResponse();

char *CwebHttpResponse_generate_response(struct CwebHttpResponse*self);


void CwebHttpResponse_free(struct CwebHttpResponse *self);

void CwebHttpResponse_set_content(CwebHttpResponse *self, unsigned char *content, int content_length);
void CwebHttpResponse_add_header(CwebHttpResponse *self, const char *key, const  char *value);


//path: src/functions/response/response_functions/response_functions.h





CwebHttpResponse* cweb_send_any(const char *content_type,size_t content_length,unsigned char *content,int status_code);

CwebHttpResponse * cweb_send_json_string(const char *content,int status_code);


CwebHttpResponse * cweb_send_json_string_cleaning_memory(char *content,int status_code);


CwebHttpResponse * cweb_send_cJSON(cJSON *content,int status_code);

CwebHttpResponse * cweb_send_cJSON_cleaning_memory(cJSON *content, int status_code);

CwebHttpResponse* cweb_send_any_cleaning_memory(const char *content_type,size_t content_length,unsigned char *content,int status_code);


CwebHttpResponse* cweb_send_rendered_CTextStack(struct CTextStack *stack,int status_code);



CwebHttpResponse* cweb_send_text(const char *content,int status_code);

CwebHttpResponse* cweb_send_text_cleaning_memory(char *content,int status_code);



CwebHttpResponse* cweb_send_var_html(const char *content,int status_code);



CwebHttpResponse* cweb_send_var_html_cleaning_memory(char *content,int status_code);


CwebHttpResponse* cweb_send_file(const char *file_path,const char *content_type,int status_code);



//path: src/functions/request/declaration.h
//path: src/functions/request/request/request.h





 CwebHttpRequest *newCwebHttpRequest(int socket);


unsigned char * CwebHttpRequest_read_content( CwebHttpRequest *self, long max_content_size);


cJSON * CWebHttpRequest_read_cJSON(CwebHttpRequest *self, long max_content_size);


CTextStack *CwebHttpRequest_create_empty_stack(CwebHttpRequest *self);

CTextStack *CwebHttpRequest_create_stack(CwebHttpRequest *self);


char * CwebHttpRequest_get_header( CwebHttpRequest *self, const char *key);

char * CwebHttpRequest_get_param_by_sanitized_key( CwebHttpRequest *self, const char *key, const char *chars_to_remove);


char * CwebHttpRequest_get_param( CwebHttpRequest *self, const char *key);

char * CwebHttpRequest_get_header_by_normalized_key( CwebHttpRequest *self, const char *key, const char *chars_to_remove);


void CwebHttpRequest_set_route( CwebHttpRequest *self, const char *route);


void CwebHttpRequest_add_header( CwebHttpRequest *self, const char *key, const char *value);

void CwebHttpRequest_add_param( CwebHttpRequest *self, const char *key, const char *value);


void CwebHttpRequest_set_method( CwebHttpRequest *self, const char *method);

void CwebHttpRequest_set_content_string( CwebHttpRequest *self, const char *content);

void CwebHttpRequest_represent( CwebHttpRequest *self);


void CwebHttpRequest_free( CwebHttpRequest *self);


//path: src/functions/request/request_parser/request_parser.h




void private_CwebHttpRequest_interpret_query_params(struct CwebHttpRequest *self, const char *query_params);


void CwebHttpRequest_set_url(struct CwebHttpRequest *self, const char *url);

int private_CwebHttpRequest_interpret_first_line(struct CwebHttpRequest *self, char *first_line);


int private_CwebHttpRequest_interpret_headders(struct CwebHttpRequest *self, struct CwebStringArray *line_headers);


bool privateCwebHttpRequest_is_correct_encoded(const char *bytes_sec,int size);


int  CwebHttpRequest_parse_http_request(struct CwebHttpRequest *self);




//path: src/functions/static/declaration.h
//path: src/functions/static/smart_cache/smart_cache.h



char * private_cweb_smart_static_ref(CTextStack *src);

char * cweb_smart_static_ref(const char *src);


CTextStack * private_cweb_change_smart_cache(CTextStack *content);


//path: src/functions/static/inline_inclusion/declaration.h
//path: src/functions/static/inline_inclusion/recursion_protection/declaration.h
//path: src/functions/static/inline_inclusion/recursion_protection/recursion_element/recursion_element.h




privateCwebRecursionElement * newPrivateCwebRecursionElement(const char *file, const char *included);

void PrivateCwebRecursionElement_represent(privateCwebRecursionElement *self);

void PrivateCwebRecursionElement_free(privateCwebRecursionElement *self);


//path: src/functions/static/inline_inclusion/recursion_protection/recursion_list/recursion_list.h






privateCwebRecursionList * newprivateCwebRecursionList();


privateCwebRecursionElement * privateCwebRecursionList_add_if_not_colide(privateCwebRecursionList *self,const char *file,const char *included);

void privateCwebRecursionList_represent(privateCwebRecursionList *self);

void privateCwebRecursionList_free(privateCwebRecursionList *self);



//path: src/functions/static/inline_inclusion/inline_inclusion/inline_inclusion.h



void private_cweb_load_file_and_include(
        CTextStack *code,
        CTextStack *src,
        privateCwebRecursionList * recursion_listage
);
void private_cweb_generate_inline_inclusion(CTextStack *code, const char *content, long content_size,
                                            privateCwebRecursionList *recursion_listage, const char *filename);



//path: src/functions/static/static/static.h





CTextStack * private_cweb_format_filename(CTextStack *src);


CwebHttpResponse * private_cweb_treat_five_icon();

char * private_cweb_aply_macro_modifiers_in_content(const char *content, long content_size);

char * cweb_aply_macro_modifiers_in_content(const char *content);

char * cweb_aply_macro_modifiers_in_file(const char *filename);

CwebHttpResponse * private_cweb_generate_static_response(struct CwebHttpRequest *request,bool use_cache);



//path: src/functions/cors/cors.h





void  private_cweb_generate_cors_response(struct CwebHttpResponse *response);


//path: src/functions/server/declaration.h
//path: src/functions/server/server_functions/server_functions.h




void private_cweb_send_error_mensage( CwebHttpResponse *response, int socket);

void cweb_kill_single_process_server( );

void cweb_set_static_folder(const char *folder);

const char * cweb_get_static_folder();

long cweb_get_total_requests();
void private_cweb_treat_response(bool use_static,int new_socket);


void private_cweb_handle_child_termination(int signal);


//path: src/functions/server/server/declaration.h
//path: src/functions/server/server/constructors/constructors.h




struct CwebServer  newCwebSever(int port , CwebHttpResponse *(*request_handler)(CwebHttpRequest *request));

int CwebServer_start(CwebServer *self);


//path: src/functions/server/server/multi_process/multi_process.h





void private_cweb_execute_request_in_safty_mode(CwebServer  *self,int new_socket, const char *client_ip);

int  private_CWebServer_run_server_in_multiprocess(CwebServer *self);


//path: src/functions/server/server/request_execution/request_execution.h







void private_CWebServer_execute_request(CwebServer *self,int socket,const char *client_ip);


//path: src/functions/server/server/single_process/single_process.h




int private_CWebServer_run_server_in_single_process(CwebServer *self);






//path: src/functions/namespace/declaration.h
//path: src/functions/namespace/string_array_module/string_array_module.h




CwebStringArrayModule newCwebStringArrayModule();


//path: src/functions/namespace/dict_module/declaration.h
//path: src/functions/namespace/dict_module/keyval_module/keyval_module.h



CwebKeyValModule newCwebKeyValModule();


//path: src/functions/namespace/dict_module/dict_module/dict_module.h



CwebDictModule newCwebDictModule();



//path: src/functions/namespace/request_module/request_module.h



CwebHttpRequestModule newCwebRequestModule();


//path: src/functions/namespace/response_module/response_module.h



CwebHttpResponseModule newCwebHttpResponseModule();


//path: src/functions/namespace/server_module/server_module.h



CwebServerModule newCwebServerModule();


//path: src/functions/namespace/namespace/namespace.h



CwebNamespace newCwebNamespace();


//path: src/functions/namespace/hydratation_module/declaration.h
//path: src/functions/namespace/hydratation_module/actions/actions.h



CWebHydrationActionsNamespace newCWebHydrationActionsNamespace();


//path: src/functions/namespace/hydratation_module/args/args.h




CWebHydrationArgsNamespace newCWebHydrationArgsNamespace();


//path: src/functions/namespace/hydratation_module/bridge/bridge.h



CWebHydrationBridgeNamespace newCWebHydrationBridgetNamespace();


//path: src/functions/namespace/hydratation_module/search_requirements/search_requirements.h



CWebHydrationSearchRequirementsNamespace newCWebHydrationSearchRequirementsNamespace();


//path: src/functions/namespace/hydratation_module/search_result/search_result.h




CWebHydrationSearchResultNamespace newCWebHydrationSearchResultNamespace();


//path: src/functions/namespace/hydratation_module/hydration/hydration.h




CWebHydrationNamespace newCWebHydrationNamespace();





//path: src/functions/hydratation/declaration.h
//path: src/functions/hydratation/bridge/declaration.h
//path: src/functions/hydratation/bridge/basic/basic.h

//path: src/functions/hydratation/bridge/basic/../uniq.declaration_requirements.h






CWebHyDrationBridge *private_newCWebHyDrationBridge(
    const char *name,
    void (*callback)(CWebHyDrationBridge *),

    CWebHyDration *hydration
);



CWebHyDrationBridge * CWebHyDrationBridge_get_brother_bridge(CWebHyDrationBridge *self,const char *name);

bool CWebHyDrationBridge_has_errors(CWebHyDrationBridge *self);

CTextStack * CWebHyDrationBridge_create_stack(CWebHyDrationBridge *self);

CTextStack * CWebHyDrationBridge_create_empty_stack(CWebHyDrationBridge *self);

CWebHyDrationSearchRequirements * CWebHyDrationBridge_newSearchRequirements(CWebHyDrationBridge *self, const char *name,...);

void CWebHyDrationBridge_add_element_by_id_setting_search_as_same_name(
    CWebHyDrationBridge *self, const char *id
);

void CWebHyDrationBridge_add_element_by_id_setting_search_as_same_name_not_format(
    CWebHyDrationBridge *self, const char *id
);

char *CWebHyDrationBridge_call(CWebHyDrationBridge *self,const char *func_args,...);



CTextStack* private_CWebHyDrationBridge_create_script(CWebHyDrationBridge *self);


void private_CWebHyDrationBridge_free(CWebHyDrationBridge *self);


//path: src/functions/hydratation/bridge/args/args.h




int   CWebHyDrationBridge_get_args_size(CWebHyDrationBridge *self);

bool private_cweb_hydration_type_verifier(CWebHyDrationBridge *self,int index,cJSON_bool (*callback_verifier)(const cJSON * const item));

bool   CWebHyDrationBridge_is_arg_number(CWebHyDrationBridge *self,int index);

bool   CWebHyDrationBridge_is_arg_bool(CWebHyDrationBridge *self,int index);


bool   CWebHyDrationBridge_is_arg_string(CWebHyDrationBridge *self,int index);

cJSON *privateCWebHyDration_get_arg_index(CWebHyDrationBridge *self,int index,cJSON_bool (*callback_verifier)(const cJSON * const item),const char *expected_type);

double  CWebHyDrationBridge_get_double_arg(CWebHyDrationBridge *self,int index);

long  CWebHyDrationBridge_get_long_arg(CWebHyDrationBridge *self,int index);

bool  CWebHyDrationBridge_get_bool_arg(CWebHyDrationBridge *self,int index);

char* CWebHyDrationBridge_get_str_arg(CWebHyDrationBridge *self,int index);

cJSON * CWebHyDrationBridge_get_cJSON_arg(CWebHyDrationBridge *self,int index);


//path: src/functions/hydratation/bridge/calls/calls.h





char *CWebHyDrationBridge_call(CWebHyDrationBridge *self,const char *func_args,...);

char *private_CWebHyDrationBridge_call_trigger(
    CWebHyDrationBridge *self,
    const char *trigger,
    const char *func_args
);

char *CWebHyDrationBridge_onclick(CWebHyDrationBridge *self,const char *func_args,...);

char *CWebHyDrationBridge_onfoccusout(CWebHyDrationBridge *self,const char *func_args,...);


//path: src/functions/hydratation/bridge/search_result/search_result.h




int  CWebHyDrationBridge_get_total_avaialible_searchs(CWebHyDrationBridge *self);

CWebHyDrationSearchResult * CWebHyDrationBridge_get_search_by_index(CWebHyDrationBridge *self,int index);

CWebHyDrationSearchResult * CWebHyDrationBridge_get_search_by_name(CWebHyDrationBridge *self,const char *name,...);

bool CWebHyDrationBridge_search_exist(CWebHyDrationBridge *self,const char *name,...);

double CWebHyDrationBridge_get_double_from_first_element_of_search(CWebHyDrationBridge *self,const char *name,...);

long CWebHyDrationBridge_get_long_from_first_element_of_search(CWebHyDrationBridge *self,const char *name,...);

bool CWebHyDrationBridge_get_bool_from_first_element_of_search(CWebHyDrationBridge *self,const char *name,...);

char* CWebHyDrationBridge_get_string_from_first_element_of_search(CWebHyDrationBridge *self,const char *name,...);

cJSON* CWebHyDrationBridge_get_cJSON_from_first_element_of_search(CWebHyDrationBridge *self,const char *name,...);


//path: src/functions/hydratation/bridge/action/action.h




void privateCWebHyDrationBridge_add_response(CWebHyDrationBridge *self,const char *name,cJSON *data);

void CWebHyDrationBridge_set_session_storage_data(CWebHyDrationBridge *self,const char*key, const char *value,...);

void CWebHyDrationBridge_alert(CWebHyDrationBridge *self,const char *menssage,...);

void CWebHyDrationBridge_execute_script(CWebHyDrationBridge *self,const char *code,...);

void CWebHyDrationBridge_replace_element_by_query_selector(
    CWebHyDrationBridge *self,
    const char *query_selector,
    const char *code,
    ...
);


void CWebHyDrationBridge_append_by_query_selector(
    CWebHyDrationBridge *self,
    const char *query_selector,
    const char *code,
    ...
);




void CWebHyDrationBridge_destroy_by_query_selector(
    CWebHyDrationBridge *self,
    const char * query_selecor
);



void CWebHyDrationBridge_hide_element_by_query_selector(
CWebHyDrationBridge *self,
const char *query_selecor);


void CWebHyDrationBridge_unhide_element_by_query_selector(
    CWebHyDrationBridge *self,
    const char *query_selector
);



void CWebHyDrationBridge_replace_element_by_id(CWebHyDrationBridge *self,const char *id, const char *code,...);


void CWebHyDrationBridge_append_by_id(CWebHyDrationBridge *self,const char *id, const char *code,...);


void CWebHyDrationBridge_hide_element_by_id(CWebHyDrationBridge *self,const char *id);


void CWebHyDrationBridge_unhide_element_by_id(CWebHyDrationBridge *self,const char *id);


void CWebHyDrationBridge_destroy_by_id(CWebHyDrationBridge *self,const char * id);


void CWebHydration_redirect(CWebHyDrationBridge *self, const char *url);

void CWebHydrationBridge_creatCookie(CWebHyDrationBridge *self, const char *key, const char *value, ...);

void CWebHydrationBridge_creatCookie_with_time(CWebHyDrationBridge *self, const char *key, long time, const char *value, ...);

void CWebHyDrationBridge_deletCookie(CWebHyDrationBridge *self, const char *key);

void CWebHyDration_console_log(CWebHyDrationBridge *self, const char *menssage, ...);
void CWebHyDration_console_warn(CWebHyDrationBridge *self, const char *menssage, ...);
void CWebHyDration_console_error(CWebHyDrationBridge *self, const char *menssage, ...);
void CWebHyDration_console_clear(CWebHyDrationBridge *self);













//path: src/functions/hydratation/bridge_array/bridge_array.h




privateCWebHyDrationBridgeArray * private_new_privateCWebHyDrationBridgeArray();

void privateCWebHyDrationBridgeArray_append(privateCWebHyDrationBridgeArray *self,CWebHyDrationBridge *element);

void privateCWebHyDrationBridgeArray_free(privateCWebHyDrationBridgeArray *self);


//path: src/functions/hydratation/search_requirements/search_requirements.h








CWebHyDrationSearchRequirements * private_newCWebHyDrationSearchRequirements_getting_name_ownership(
    CWebHyDrationBridge *bridge, char *name
);


void private_CWebHyDrationSearchRequirements_free(CWebHyDrationSearchRequirements *self);


void CWebHyDrationSearchRequirements_add_function(CWebHyDrationSearchRequirements *self,const char *function,...);


void private_CWebHyDrationSearchRequirements_add_elements_by_query_selector(
    CWebHyDrationSearchRequirements *self,
    const char *query_selector,bool auto_convert
);


void CWebHyDrationSearchRequirements_add_elements_by_query_selector(
    CWebHyDrationSearchRequirements *self,
    const char *query_selector,
    ...
);




void CWebHyDrationSearchRequirements_add_elements_by_query_selector_not_auto_converting(
    CWebHyDrationSearchRequirements *self,const char *query_selector,...);


void CWebHyDrationSearchRequirements_add_elements_by_attribute(
    CWebHyDrationSearchRequirements *self,
   const char *attribute,
   const char*attribute_value,
   ...
);

void CWebHyDrationSearchRequirements_add_elements_by_attribute_not_auto_converting(
    CWebHyDrationSearchRequirements *self,
    const char *attribute,
    const char*attribute_value,
    ...
);

void CWebHyDrationSearchRequirements_add_cookie_item(CWebHyDrationSearchRequirements *self, const char *name);
void CWebHyDrationSearchRequirements_add_confirm(CWebHyDrationSearchRequirements *self, const char*message, ...);


void CWebHyDrationSearchRequirements_add_elements_by_class_name(
    CWebHyDrationSearchRequirements *self,
    const char*class_value,
    ...
);

void CWebHyDrationSearchRequirements_add_elements_by_class_name_not_auto_converting(
    CWebHyDrationSearchRequirements *self,
    const char*class_value,...
);

void CWebHyDrationSearchRequirements_add_elements_by_id(
    CWebHyDrationSearchRequirements *self,
    const char*id_values,
    ...
);

void CWebHyDrationSearchRequirements_add_elements_by_id_not_auto_converting(
    CWebHyDrationSearchRequirements *self,
    const char*id_values,
    ...
);


void CWebHyDrationSearchRequirements_add_session_storage_item_not_converting(
    CWebHyDrationSearchRequirements *self,
    const char *name,
    ...
);


void CWebHyDrationSearchRequirements_add_session_storage_item(
    CWebHyDrationSearchRequirements *self,
    const char *name,
    ...
);

void CWebHyDrationSearchRequirements_add_prompt(CWebHyDrationSearchRequirements *self, const char *message, ...);


//path: src/functions/hydratation/search_result/search_result.h






CWebHyDrationSearchResult * private_newCWebHyDrationSearchResult(CWebHyDrationBridge *bridge,cJSON *search);

void privateCWebHyDrationSearchResult_free(CWebHyDrationSearchResult *self);

bool  privateCWebHyDrationSearchResult_has_erorrs(CWebHyDrationSearchResult *self);


int  CWebHyDrationSearchResult_get_total_itens(CWebHyDrationSearchResult *self);


bool  CWebHyDrationSearchResult_search_item_exist(CWebHyDrationSearchResult *self,int index);


bool  CWebHyDrationSearchResult_is_search_item_number(CWebHyDrationSearchResult *self,int index);

bool  CWebHyDrationSearchResult_is_search_item_bool(CWebHyDrationSearchResult *self,int index);


bool  CWebHyDrationSearchResult_is_search_item_string(CWebHyDrationSearchResult *self,int index);
cJSON * private_CWebHyDrationSearchResult_get_cJSON_item_verifying_type(
    CWebHyDrationSearchResult *self,
    int index,
    cJSON_bool (*callback_verifier)(const cJSON * const item),
    const char *expected_type
);


double CWebHyDrationSearchResult_get_double(CWebHyDrationSearchResult *self,int  index);


long CWebHyDrationSearchResult_get_long(CWebHyDrationSearchResult *self,int  index);


bool CWebHyDrationSearchResult_get_bool(CWebHyDrationSearchResult *self,int  index);



char*  CWebHyDrationSearchResult_get_string(CWebHyDrationSearchResult *self,int  index);


cJSON *  CWebHyDrationSearchResult_get_cJSON(CWebHyDrationSearchResult *self,int  index);


//path: src/functions/hydratation/hydration/hydration.h




CWebHyDration * newCWebHyDration(CwebHttpRequest *request);

CWebHyDrationBridge * CWebHyDration_create_bridge(CWebHyDration *self,const char *name,void (*callback)(CWebHyDrationBridge *));

CTextStack  * CWebHyDration_create_stack(CWebHyDration *self);

CTextStack  * CWebHyDration_create_empty_stack(CWebHyDration *self);

CWebHyDrationBridge * CWebHyDration_get_child_bridge(CWebHyDration *self,const char *name);

void privateCWebHydration_raise_error(CWebHyDration *self,CWebHyDrationBridge *bridge, int error_code, const char *format,...);

CwebHttpResponse *private_CWebHydration_formmat_error_response(CWebHyDration *self);

bool CWebHyDration_is_the_trigger(CWebHyDration *self);

CwebHttpResponse *CWebHydration_generate_response(CWebHyDration *self);

char *CWebHyDration_create_script(CWebHyDration *self);

void private_CWebHyDration_free(CWebHyDration *self);





#endif




//path: src/globals/all.c

#ifndef PRIVATE_CWEB_GLOBALS
#define  PRIVATE_CWEB_GLOBALS

//path: src/globals/server.c




static long long  cweb_actual_request = 0;
static long cweb_total_requests = 0;
static bool private_cweb_end_server = false;

static const char* cweb_static_folder;


//path: src/globals/hydration.c
const char *private_cweb_hydration_js_content = "\xa\x6c\x65\x74\x20\x70\x72\x69\x76\x61\x74\x65\x5f\x63\x77\x65\x62\x5f\x61\x63\x74\x69\x6f\x6e\x73\x5f\x68\x61\x6e\x64\x6c\x65\x72\x73\x20\x3d\x20\x7b\xa\x20\x20\x61\x6c\x65\x72\x74\x3a\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x28\x64\x61\x74\x61\x29\x20\x7b\xa\x20\x20\x20\x20\x61\x6c\x65\x72\x74\x28\x64\x61\x74\x61\x5b\x22\x6d\x73\x67\x22\x5d\x29\x3b\xa\x20\x20\x7d\x2c\xa\xa\x20\x20\x65\x78\x65\x63\x75\x74\x65\x5f\x73\x63\x72\x69\x70\x74\x3a\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x28\x64\x61\x74\x61\x29\x20\x7b\xa\x20\x20\x20\x20\x65\x76\x61\x6c\x28\x64\x61\x74\x61\x5b\x22\x63\x6f\x64\x65\x22\x5d\x29\x3b\xa\x20\x20\x7d\x2c\xa\xa\x20\x20\x72\x65\x64\x69\x72\x65\x63\x74\x3a\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x28\x64\x61\x74\x61\x29\x20\x7b\xa\x20\x20\x20\x20\x77\x69\x6e\x64\x6f\x77\x2e\x6c\x6f\x63\x61\x74\x69\x6f\x6e\x2e\x68\x72\x65\x66\x20\x3d\x20\x64\x61\x74\x61\x5b\x22\x75\x72\x6c\x22\x5d\x3b\xa\x20\x20\x7d\x2c\xa\xa\x20\x20\x73\x65\x74\x5f\x73\x65\x73\x73\x69\x6f\x6e\x5f\x73\x74\x6f\x72\x61\x67\x65\x3a\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x28\x64\x61\x74\x61\x29\x20\x7b\xa\x20\x20\x20\x20\x73\x65\x73\x73\x69\x6f\x6e\x53\x74\x6f\x72\x61\x67\x65\x2e\x73\x65\x74\x49\x74\x65\x6d\x28\x64\x61\x74\x61\x5b\x22\x6b\x65\x79\x22\x5d\x2c\x20\x64\x61\x74\x61\x5b\x22\x76\x61\x6c\x75\x65\x22\x5d\x29\x3b\xa\x20\x20\x7d\x2c\xa\xa\x20\x20\x61\x64\x64\x5f\x63\x6f\x6f\x6b\x69\x65\x5f\x77\x69\x74\x68\x5f\x74\x69\x6d\x65\x3a\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x28\x64\x61\x74\x61\x29\x7b\xa\x20\x20\x20\x20\x6c\x65\x74\x20\x65\x78\x70\x69\x72\x65\x73\x20\x3d\x20\x22\x22\x3b\xa\x20\x20\x20\x20\x69\x66\x20\x28\x64\x61\x74\x61\x2e\x64\x61\x79\x73\x29\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x63\x6f\x6e\x73\x74\x20\x64\x61\x74\x65\x20\x3d\x20\x6e\x65\x77\x20\x44\x61\x74\x65\x28\x29\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x64\x61\x74\x65\x2e\x73\x65\x74\x54\x69\x6d\x65\x28\x64\x61\x74\x65\x2e\x67\x65\x74\x54\x69\x6d\x65\x28\x29\x20\x2b\x20\x28\x64\x61\x74\x61\x2e\x64\x61\x79\x73\x20\x2a\x20\x32\x34\x20\x2a\x20\x36\x30\x20\x2a\x20\x36\x30\x20\x2a\x20\x31\x30\x30\x30\x29\x29\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x65\x78\x70\x69\x72\x65\x73\x20\x3d\x20\x22\x3b\x20\x65\x78\x70\x69\x72\x65\x73\x3d\x22\x20\x2b\x20\x64\x61\x74\x65\x2e\x74\x6f\x55\x54\x43\x53\x74\x72\x69\x6e\x67\x28\x29\x3b\xa\x20\x20\x20\x20\x7d\xa\x20\x20\x20\x20\x64\x6f\x63\x75\x6d\x65\x6e\x74\x2e\x63\x6f\x6f\x6b\x69\x65\x20\x3d\x20\x64\x61\x74\x61\x2e\x6e\x61\x6d\x65\x20\x2b\x20\x22\x3d\x22\x20\x2b\x20\x28\x64\x61\x74\x61\x2e\x76\x61\x6c\x75\x65\x20\x7c\x7c\x20\x22\x22\x29\x20\x2b\x20\x65\x78\x70\x69\x72\x65\x73\x20\x2b\x20\x22\x3b\x20\x70\x61\x74\x68\x3d\x2f\x22\x3b\xa\x20\x20\x7d\x2c\xa\xa\x20\x20\x61\x64\x64\x5f\x63\x6f\x6f\x6b\x69\x65\x3a\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x28\x64\x61\x74\x61\x29\x20\x7b\xa\x20\x20\x20\x20\x64\x6f\x63\x75\x6d\x65\x6e\x74\x2e\x63\x6f\x6f\x6b\x69\x65\x20\x3d\x20\x64\x61\x74\x61\x2e\x6e\x61\x6d\x65\x20\x2b\x20\x22\x3d\x22\x20\x2b\x20\x28\x64\x61\x74\x61\x2e\x76\x61\x6c\x75\x65\x20\x7c\x7c\x20\x22\x22\x29\x20\x2b\x20\x22\x3b\x20\x70\x61\x74\x68\x3d\x2f\x22\x3b\xa\x20\x20\x7d\x2c\xa\xa\x20\x20\x64\x65\x6c\x65\x74\x5f\x63\x6f\x6f\x6b\x69\x65\x3a\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x28\x6e\x61\x6d\x65\x29\x20\x7b\x20\x20\x20\xa\x20\x20\x20\x20\x64\x6f\x63\x75\x6d\x65\x6e\x74\x2e\x63\x6f\x6f\x6b\x69\x65\x20\x3d\x20\x6e\x61\x6d\x65\x20\x2b\x20\x27\x3d\x3b\x20\x4d\x61\x78\x2d\x41\x67\x65\x3d\x2d\x39\x39\x39\x39\x39\x39\x39\x39\x3b\x27\x3b\x20\x20\xa\x20\x20\x7d\x2c\xa\xa\x20\x20\x72\x65\x70\x6c\x61\x63\x65\x5f\x65\x6c\x65\x6d\x65\x6e\x74\x5f\x62\x79\x5f\x71\x75\x65\x72\x79\x5f\x73\x65\x6c\x65\x63\x74\x6f\x72\x3a\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x28\x64\x61\x74\x61\x29\x20\x7b\xa\x20\x20\x20\x20\x6c\x65\x74\x20\x65\x6c\x65\x6d\x65\x6e\x74\x20\x3d\x20\x64\x6f\x63\x75\x6d\x65\x6e\x74\x2e\x71\x75\x65\x72\x79\x53\x65\x6c\x65\x63\x74\x6f\x72\x28\x64\x61\x74\x61\x2e\x71\x75\x65\x72\x79\x5f\x73\x65\x6c\x65\x63\x74\x6f\x72\x29\x3b\xa\x20\x20\x20\x20\x69\x66\x20\x28\x21\x65\x6c\x65\x6d\x65\x6e\x74\x29\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x72\x65\x74\x75\x72\x6e\x3b\xa\x20\x20\x20\x20\x7d\xa\x20\x20\x20\x20\x65\x6c\x65\x6d\x65\x6e\x74\x2e\x69\x6e\x73\x65\x72\x74\x41\x64\x6a\x61\x63\x65\x6e\x74\x48\x54\x4d\x4c\x28\x22\x61\x66\x74\x65\x72\x65\x6e\x64\x22\x2c\x20\x64\x61\x74\x61\x2e\x68\x74\x6d\x6c\x29\x3b\xa\x20\x20\x20\x20\x65\x6c\x65\x6d\x65\x6e\x74\x2e\x72\x65\x6d\x6f\x76\x65\x28\x29\x3b\xa\x20\x20\x7d\x2c\xa\xa\x20\x20\x61\x70\x70\x65\x6e\x64\x5f\x62\x79\x5f\x71\x75\x65\x72\x79\x5f\x73\x65\x6c\x65\x63\x74\x6f\x72\x3a\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x28\x64\x61\x74\x61\x29\x20\x7b\xa\x20\x20\x20\x20\x6c\x65\x74\x20\x65\x6c\x65\x6d\x65\x6e\x74\x20\x3d\x20\x64\x6f\x63\x75\x6d\x65\x6e\x74\x2e\x71\x75\x65\x72\x79\x53\x65\x6c\x65\x63\x74\x6f\x72\x28\x64\x61\x74\x61\x2e\x71\x75\x65\x72\x79\x5f\x73\x65\x6c\x65\x63\x74\x6f\x72\x29\x3b\xa\x20\x20\x20\x20\x69\x66\x20\x28\x21\x65\x6c\x65\x6d\x65\x6e\x74\x29\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x72\x65\x74\x75\x72\x6e\x3b\xa\x20\x20\x20\x20\x7d\xa\x20\x20\x20\x20\x65\x6c\x65\x6d\x65\x6e\x74\x2e\x69\x6e\x6e\x65\x72\x48\x54\x4d\x4c\x20\x2b\x3d\x20\x64\x61\x74\x61\x2e\x68\x74\x6d\x6c\x3b\xa\x20\x20\x7d\x2c\xa\xa\x20\x20\x68\x69\x64\x65\x5f\x65\x6c\x65\x6d\x65\x6e\x74\x5f\x62\x79\x5f\x71\x75\x65\x72\x79\x5f\x73\x65\x6c\x65\x63\x74\x6f\x72\x3a\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x28\x64\x61\x74\x61\x29\x20\x7b\xa\x20\x20\x20\x20\x6c\x65\x74\x20\x65\x6c\x65\x6d\x65\x6e\x74\x20\x3d\x20\x64\x6f\x63\x75\x6d\x65\x6e\x74\x2e\x71\x75\x65\x72\x79\x53\x65\x6c\x65\x63\x74\x6f\x72\x28\x64\x61\x74\x61\x2e\x71\x75\x65\x72\x79\x5f\x73\x65\x6c\x65\x63\x74\x6f\x72\x29\x3b\xa\x20\x20\x20\x20\x69\x66\x20\x28\x21\x65\x6c\x65\x6d\x65\x6e\x74\x29\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x72\x65\x74\x75\x72\x6e\x3b\xa\x20\x20\x20\x20\x7d\xa\x20\x20\x20\x20\x65\x6c\x65\x6d\x65\x6e\x74\x2e\x73\x74\x79\x6c\x65\x2e\x64\x69\x73\x70\x6c\x61\x79\x20\x3d\x20\x22\x6e\x6f\x6e\x65\x22\x3b\xa\x20\x20\x7d\x2c\xa\x20\x20\x75\x6e\x68\x69\x64\x65\x5f\x65\x6c\x65\x6d\x65\x6e\x74\x5f\x62\x79\x5f\x71\x75\x65\x72\x79\x5f\x73\x65\x6c\x65\x63\x74\x6f\x72\x3a\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x28\x64\x61\x74\x61\x29\x20\x7b\xa\x20\x20\x20\x20\x6c\x65\x74\x20\x65\x6c\x65\x6d\x65\x6e\x74\x20\x3d\x20\x64\x6f\x63\x75\x6d\x65\x6e\x74\x2e\x71\x75\x65\x72\x79\x53\x65\x6c\x65\x63\x74\x6f\x72\x28\x64\x61\x74\x61\x2e\x71\x75\x65\x72\x79\x5f\x73\x65\x6c\x65\x63\x74\x6f\x72\x29\x3b\xa\x20\x20\x20\x20\x69\x66\x20\x28\x21\x65\x6c\x65\x6d\x65\x6e\x74\x29\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x72\x65\x74\x75\x72\x6e\x3b\xa\x20\x20\x20\x20\x7d\xa\x20\x20\x20\x20\x65\x6c\x65\x6d\x65\x6e\x74\x2e\x73\x74\x79\x6c\x65\x2e\x64\x69\x73\x70\x6c\x61\x79\x20\x3d\x20\x22\x73\x68\x6f\x77\x22\x3b\xa\x20\x20\x7d\x2c\xa\xa\x20\x20\x64\x65\x73\x74\x72\x6f\x79\x5f\x62\x79\x5f\x71\x75\x65\x72\x79\x5f\x73\x65\x6c\x65\x63\x74\x6f\x72\x3a\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x28\x64\x61\x74\x61\x29\x20\x7b\xa\x20\x20\x20\x20\x6c\x65\x74\x20\x65\x6c\x65\x6d\x65\x6e\x74\x20\x3d\x20\x64\x6f\x63\x75\x6d\x65\x6e\x74\x2e\x71\x75\x65\x72\x79\x53\x65\x6c\x65\x63\x74\x6f\x72\x28\x64\x61\x74\x61\x2e\x71\x75\x65\x72\x79\x5f\x73\x65\x6c\x65\x63\x74\x6f\x72\x29\x3b\xa\x20\x20\x20\x20\x69\x66\x20\x28\x65\x6c\x65\x6d\x65\x6e\x74\x29\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x65\x6c\x65\x6d\x65\x6e\x74\x2e\x72\x65\x6d\x6f\x76\x65\x28\x29\x3b\xa\x20\x20\x20\x20\x7d\xa\x20\x20\x7d\x2c\xa\xa\x20\x20\x6c\x6f\x67\x3a\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x28\x64\x61\x74\x61\x29\x7b\xa\x20\x20\x20\x20\x63\x6f\x6e\x73\x6f\x6c\x65\x2e\x6c\x6f\x67\x28\x64\x61\x74\x61\x2e\x6d\x65\x73\x73\x61\x67\x65\x29\x3b\xa\x20\x20\x7d\x2c\xa\xa\x20\x20\x77\x61\x72\x6e\x3a\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x28\x64\x61\x74\x61\x29\x7b\xa\x20\x20\x20\x20\x63\x6f\x6e\x73\x6f\x6c\x65\x2e\x77\x61\x72\x6e\x28\x64\x61\x74\x61\x2e\x6d\x65\x73\x73\x61\x67\x65\x29\x3b\xa\x20\x20\x7d\x2c\xa\xa\x20\x20\x65\x72\x72\x6f\x72\x3a\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x28\x64\x61\x74\x61\x29\x7b\xa\x20\x20\x20\x20\x63\x6f\x6e\x73\x6f\x6c\x65\x2e\x65\x72\x72\x6f\x72\x28\x64\x61\x74\x61\x2e\x6d\x65\x73\x73\x61\x67\x65\x29\x3b\xa\x20\x20\x7d\x2c\xa\xa\x20\x20\x63\x6c\x65\x61\x72\x3a\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x28\x64\x61\x74\x61\x29\x7b\xa\x20\x20\x20\x20\x63\x6f\x6e\x73\x6f\x6c\x65\x2e\x63\x6c\x65\x61\x72\x28\x29\x3b\xa\x20\x20\x7d\xa\xa\xa\x7d\x3b\xa\x6c\x65\x74\x20\x70\x72\x69\x76\x61\x74\x65\x5f\x63\x77\x65\x62\x5f\x62\x72\x69\x64\x67\x65\x73\x20\x3d\x20\x7b\x7d\x3b\xa\xa\x61\x73\x79\x6e\x63\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x70\x72\x69\x76\x61\x74\x65\x5f\x63\x77\x65\x62\x5f\x73\x65\x6e\x64\x5f\x74\x6f\x5f\x73\x65\x72\x76\x65\x72\x28\x6e\x61\x6d\x65\x2c\x20\x61\x72\x67\x73\x2c\x20\x63\x6f\x6e\x74\x65\x6e\x74\x29\x20\x7b\xa\x20\x20\x6c\x65\x74\x20\x62\x6f\x64\x79\x20\x3d\x20\x7b\x20\x6e\x61\x6d\x65\x3a\x20\x6e\x61\x6d\x65\x2c\x20\x61\x72\x67\x73\x3a\x20\x61\x72\x67\x73\x2c\x20\x63\x6f\x6e\x74\x65\x6e\x74\x3a\x20\x63\x6f\x6e\x74\x65\x6e\x74\x20\x7d\x3b\xa\x20\x20\x6c\x65\x74\x20\x70\x72\x6f\x70\x73\x20\x3d\x20\x7b\xa\x20\x20\x20\x20\x6d\x65\x74\x68\x6f\x64\x3a\x20\x22\x50\x4f\x53\x54\x22\x2c\xa\x20\x20\x20\x20\x62\x6f\x64\x79\x3a\x20\x4a\x53\x4f\x4e\x2e\x73\x74\x72\x69\x6e\x67\x69\x66\x79\x28\x62\x6f\x64\x79\x29\x2c\xa\x20\x20\x7d\x3b\xa\x20\x20\x63\x6f\x6e\x73\x74\x20\x52\x4f\x55\x54\x45\x20\x3d\x20\x22\x2f\x70\x72\x69\x76\x61\x74\x65\x5f\x63\x77\x65\x62\x5f\x68\x79\x64\x72\x61\x74\x69\x6f\x6e\x5f\x6d\x61\x69\x6e\x5f\x63\x61\x6c\x6c\x62\x61\x63\x6b\x5f\x68\x61\x6e\x64\x6c\x65\x72\x22\x3b\xa\x20\x20\x6c\x65\x74\x20\x72\x65\x73\x75\x6c\x74\x20\x3d\x20\x61\x77\x61\x69\x74\x20\x66\x65\x74\x63\x68\x28\x52\x4f\x55\x54\x45\x2c\x20\x70\x72\x6f\x70\x73\x29\x3b\xa\x20\x20\x6c\x65\x74\x20\x61\x63\x74\x69\x6f\x6e\x73\x20\x3d\x20\x61\x77\x61\x69\x74\x20\x72\x65\x73\x75\x6c\x74\x2e\x6a\x73\x6f\x6e\x28\x29\x3b\xa\x20\x20\x69\x66\x20\x28\x21\x72\x65\x73\x75\x6c\x74\x2e\x6f\x6b\x29\x20\x7b\xa\x20\x20\x20\x20\x63\x6f\x6e\x73\x6f\x6c\x65\x2e\x6c\x6f\x67\x28\x61\x63\x74\x69\x6f\x6e\x73\x29\x3b\xa\x20\x20\x20\x20\x72\x65\x74\x75\x72\x6e\x3b\xa\x20\x20\x7d\xa\x20\x20\x61\x63\x74\x69\x6f\x6e\x73\x2e\x66\x6f\x72\x45\x61\x63\x68\x28\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x28\x69\x74\x65\x6d\x29\x20\x7b\xa\x20\x20\x20\x20\x74\x72\x79\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x6c\x65\x74\x20\x72\x65\x73\x70\x6f\x6e\x73\x65\x5f\x61\x63\x74\x69\x6f\x6e\x20\x3d\x20\x70\x72\x69\x76\x61\x74\x65\x5f\x63\x77\x65\x62\x5f\x61\x63\x74\x69\x6f\x6e\x73\x5f\x68\x61\x6e\x64\x6c\x65\x72\x73\x5b\x69\x74\x65\x6d\x2e\x6e\x61\x6d\x65\x5d\x3b\xa\x20\x20\x20\x20\x20\x20\x69\x66\x20\x28\x21\x72\x65\x73\x70\x6f\x6e\x73\x65\x5f\x61\x63\x74\x69\x6f\x6e\x29\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x74\x68\x72\x6f\x77\x20\x45\x72\x72\x6f\x72\x28\x22\x72\x65\x73\x70\x6f\x6e\x73\x65\x20\x22\x20\x2b\x20\x69\x74\x65\x6d\x2e\x6e\x61\x6d\x65\x20\x2b\x20\x22\x69\x74\x73\x20\x6e\x6f\x74\x20\x61\x20\x61\x63\x74\x69\x6f\x6e\x22\x29\x3b\xa\x20\x20\x20\x20\x20\x20\x7d\xa\xa\x20\x20\x20\x20\x20\x20\x72\x65\x73\x70\x6f\x6e\x73\x65\x5f\x61\x63\x74\x69\x6f\x6e\x28\x69\x74\x65\x6d\x2e\x64\x61\x74\x61\x29\x3b\xa\x20\x20\x20\x20\x7d\x20\x63\x61\x74\x63\x68\x20\x28\x65\x72\x72\x6f\x72\x29\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x63\x6f\x6e\x73\x6f\x6c\x65\x2e\x6c\x6f\x67\x28\x65\x72\x72\x6f\x72\x29\x3b\xa\x20\x20\x20\x20\x7d\xa\x20\x20\x7d\x29\x3b\xa\x7d\xa\xa\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x70\x72\x69\x76\x61\x74\x65\x5f\x63\x77\x65\x62\x5f\x68\x61\x6e\x64\x6c\x65\x5f\x72\x65\x71\x75\x69\x72\x65\x64\x5f\x64\x61\x74\x61\x28\x63\x61\x6c\x6c\x62\x61\x63\x6b\x2c\x20\x61\x72\x67\x73\x2c\x20\x63\x6f\x6e\x74\x65\x6e\x74\x2c\x20\x6e\x61\x6d\x65\x29\x20\x7b\xa\x20\x20\x6c\x65\x74\x20\x72\x65\x73\x75\x6c\x74\x20\x3d\x20\x75\x6e\x64\x65\x66\x69\x6e\x65\x64\x3b\xa\x20\x20\x74\x72\x79\x20\x7b\xa\x20\x20\x20\x20\x72\x65\x73\x75\x6c\x74\x20\x3d\x20\x63\x61\x6c\x6c\x62\x61\x63\x6b\x28\x61\x72\x67\x73\x29\x3b\xa\x20\x20\x7d\x20\x63\x61\x74\x63\x68\x20\x28\x65\x72\x72\x6f\x72\x29\x20\x7b\xa\x20\x20\x20\x20\x63\x6f\x6e\x73\x6f\x6c\x65\x2e\x6c\x6f\x67\x28\x65\x72\x72\x6f\x72\x29\x3b\xa\x20\x20\x20\x20\x72\x65\x74\x75\x72\x6e\x3b\xa\x20\x20\x7d\xa\xa\x20\x20\x69\x66\x20\x28\x21\x41\x72\x72\x61\x79\x2e\x69\x73\x41\x72\x72\x61\x79\x28\x72\x65\x73\x75\x6c\x74\x29\x29\x20\x7b\xa\x20\x20\x20\x20\x72\x65\x73\x75\x6c\x74\x20\x3d\x20\x5b\x72\x65\x73\x75\x6c\x74\x5d\x3b\xa\x20\x20\x7d\xa\xa\x20\x20\x69\x66\x20\x28\x21\x63\x6f\x6e\x74\x65\x6e\x74\x5b\x6e\x61\x6d\x65\x5d\x29\x20\x7b\xa\x20\x20\x20\x20\x63\x6f\x6e\x74\x65\x6e\x74\x5b\x6e\x61\x6d\x65\x5d\x20\x3d\x20\x5b\x5d\x3b\xa\x20\x20\x7d\xa\x20\x20\x63\x6f\x6e\x74\x65\x6e\x74\x5b\x6e\x61\x6d\x65\x5d\x20\x3d\x20\x63\x6f\x6e\x74\x65\x6e\x74\x5b\x6e\x61\x6d\x65\x5d\x2e\x63\x6f\x6e\x63\x61\x74\x28\x72\x65\x73\x75\x6c\x74\x29\x3b\xa\x7d\xa\xa\xa\xa\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x70\x72\x69\x76\x61\x74\x65\x5f\x63\x77\x65\x62\x5f\x74\x72\x79\x5f\x74\x6f\x5f\x63\x6f\x6e\x76\x65\x72\x74\x5f\x74\x6f\x5f\x6e\x75\x6d\x62\x65\x72\x28\x70\x6f\x73\x73\x69\x62\x6c\x65\x5f\x6e\x75\x6d\x62\x65\x72\x29\x20\x7b\xa\x20\x20\x6c\x65\x74\x20\x70\x6f\x73\x73\x69\x62\x6c\x65\x5f\x63\x6f\x6e\x76\x65\x72\x73\x69\x6f\x6e\x20\x3d\x20\x70\x61\x72\x73\x65\x46\x6c\x6f\x61\x74\x28\x70\x6f\x73\x73\x69\x62\x6c\x65\x5f\x6e\x75\x6d\x62\x65\x72\x29\x3b\xa\x20\x20\x69\x66\x20\x28\x69\x73\x4e\x61\x4e\x28\x70\x6f\x73\x73\x69\x62\x6c\x65\x5f\x63\x6f\x6e\x76\x65\x72\x73\x69\x6f\x6e\x29\x29\x20\x7b\xa\x20\x20\x20\x20\x72\x65\x74\x75\x72\x6e\x20\x70\x6f\x73\x73\x69\x62\x6c\x65\x5f\x6e\x75\x6d\x62\x65\x72\x3b\xa\x20\x20\x7d\xa\xa\x20\x20\x72\x65\x74\x75\x72\x6e\x20\x70\x6f\x73\x73\x69\x62\x6c\x65\x5f\x63\x6f\x6e\x76\x65\x72\x73\x69\x6f\x6e\x3b\xa\x7d\xa\xa\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x70\x72\x69\x76\x61\x74\x65\x5f\x63\x77\x65\x62\x5f\x67\x65\x74\x5f\x73\x65\x73\x73\x69\x6f\x6e\x5f\x73\x74\x6f\x72\x61\x67\x65\x5f\x69\x74\x65\x6d\x28\x70\x72\x6f\x70\x73\x29\x20\x7b\xa\x20\x20\x6c\x65\x74\x20\x66\x69\x6e\x61\x6c\x76\x61\x6c\x75\x65\x20\x3d\x20\x73\x65\x73\x73\x69\x6f\x6e\x53\x74\x6f\x72\x61\x67\x65\x2e\x67\x65\x74\x49\x74\x65\x6d\x28\x70\x72\x6f\x70\x73\x2e\x6e\x61\x6d\x65\x29\x3b\xa\xa\x20\x20\x69\x66\x20\x28\x21\x66\x69\x6e\x61\x6c\x76\x61\x6c\x75\x65\x29\x20\x7b\xa\x20\x20\x20\x20\x72\x65\x74\x75\x72\x6e\x20\x5b\x5d\x3b\xa\x20\x20\x7d\xa\x20\x20\x69\x66\x20\x28\x70\x72\x6f\x70\x73\x2e\x61\x75\x74\x6f\x5f\x63\x6f\x6e\x76\x65\x72\x74\x29\x20\x7b\xa\x20\x20\x20\x20\x66\x69\x6e\x61\x6c\x76\x61\x6c\x75\x65\x20\x3d\x20\x70\x72\x69\x76\x61\x74\x65\x5f\x63\x77\x65\x62\x5f\x74\x72\x79\x5f\x74\x6f\x5f\x63\x6f\x6e\x76\x65\x72\x74\x5f\x74\x6f\x5f\x6e\x75\x6d\x62\x65\x72\x28\x66\x69\x6e\x61\x6c\x76\x61\x6c\x75\x65\x29\x3b\xa\x20\x20\x7d\xa\xa\x20\x20\x72\x65\x74\x75\x72\x6e\x20\x5b\x66\x69\x6e\x61\x6c\x76\x61\x6c\x75\x65\x5d\x3b\xa\x7d\xa\xa\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x70\x72\x69\x76\x61\x74\x65\x5f\x63\x77\x65\x62\x5f\x67\x65\x74\x5f\x65\x6c\x65\x6d\x65\x6e\x74\x73\x28\x70\x72\x6f\x70\x73\x29\x20\x7b\xa\x20\x20\x6c\x65\x74\x20\x65\x6c\x65\x6d\x65\x6e\x74\x73\x20\x3d\x20\x5b\x2e\x2e\x2e\x64\x6f\x63\x75\x6d\x65\x6e\x74\x2e\x71\x75\x65\x72\x79\x53\x65\x6c\x65\x63\x74\x6f\x72\x41\x6c\x6c\x28\x70\x72\x6f\x70\x73\x2e\x71\x75\x65\x72\x79\x5f\x73\x65\x6c\x65\x63\x74\x6f\x72\x29\x5d\x3b\xa\x20\x20\x72\x65\x74\x75\x72\x6e\x20\x65\x6c\x65\x6d\x65\x6e\x74\x73\x2e\x6d\x61\x70\x28\x28\x65\x6c\x65\x6d\x65\x6e\x74\x29\x20\x3d\x3e\x20\x7b\xa\x20\x20\x20\x20\x6c\x65\x74\x20\x66\x69\x6e\x61\x6c\x76\x61\x6c\x75\x65\x20\x3d\x20\x75\x6e\x64\x65\x66\x69\x6e\x65\x64\x3b\xa\xa\x20\x20\x20\x20\x69\x66\x20\x28\x65\x6c\x65\x6d\x65\x6e\x74\x2e\x74\x79\x70\x65\x20\x3d\x3d\x3d\x20\x22\x63\x68\x65\x63\x6b\x62\x6f\x78\x22\x29\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x72\x65\x74\x75\x72\x6e\x20\x65\x6c\x65\x6d\x65\x6e\x74\x2e\x63\x68\x65\x63\x6b\x65\x64\x3b\xa\x20\x20\x20\x20\x7d\xa\xa\x20\x20\x20\x20\x69\x66\x20\x28\x65\x6c\x65\x6d\x65\x6e\x74\x2e\x74\x61\x67\x4e\x61\x6d\x65\x20\x3d\x3d\x3d\x20\x22\x49\x4e\x50\x55\x54\x22\x20\x7c\x7c\x20\x65\x6c\x65\x6d\x65\x6e\x74\x2e\x74\x61\x67\x4e\x61\x6d\x65\x20\x3d\x3d\x3d\x20\x22\x54\x45\x58\x54\x41\x52\x45\x41\x22\x29\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x66\x69\x6e\x61\x6c\x76\x61\x6c\x75\x65\x20\x3d\x20\x65\x6c\x65\x6d\x65\x6e\x74\x2e\x76\x61\x6c\x75\x65\x3b\xa\x20\x20\x20\x20\x7d\x20\x65\x6c\x73\x65\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x66\x69\x6e\x61\x6c\x76\x61\x6c\x75\x65\x20\x3d\x20\x65\x6c\x65\x6d\x65\x6e\x74\x2e\x74\x65\x78\x74\x43\x6f\x6e\x74\x65\x6e\x74\x3b\xa\x20\x20\x20\x20\x7d\xa\xa\x20\x20\x20\x20\x69\x66\x20\x28\x70\x72\x6f\x70\x73\x2e\x61\x75\x74\x6f\x5f\x63\x6f\x6e\x76\x65\x72\x74\x29\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x66\x69\x6e\x61\x6c\x76\x61\x6c\x75\x65\x20\x3d\x20\x70\x72\x69\x76\x61\x74\x65\x5f\x63\x77\x65\x62\x5f\x74\x72\x79\x5f\x74\x6f\x5f\x63\x6f\x6e\x76\x65\x72\x74\x5f\x74\x6f\x5f\x6e\x75\x6d\x62\x65\x72\x28\x66\x69\x6e\x61\x6c\x76\x61\x6c\x75\x65\x29\x3b\xa\x20\x20\x20\x20\x7d\xa\xa\x20\x20\x20\x20\x72\x65\x74\x75\x72\x6e\x20\x66\x69\x6e\x61\x6c\x76\x61\x6c\x75\x65\x3b\xa\x20\x20\x7d\x29\x3b\xa\x7d\xa\xa\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x70\x72\x69\x76\x61\x74\x65\x5f\x63\x77\x65\x62\x5f\x67\x65\x74\x5f\x76\x61\x6c\x75\x65\x5f\x63\x6f\x6f\x6b\x69\x65\x5f\x62\x79\x5f\x6b\x65\x79\x28\x70\x72\x6f\x70\x73\x29\x7b\xa\x20\x20\x63\x6f\x6e\x73\x74\x20\x6e\x61\x6d\x65\x45\x51\x20\x3d\x20\x70\x72\x6f\x70\x73\x2e\x6e\x61\x6d\x65\x20\x2b\x20\x22\x3d\x22\x3b\xa\x20\x20\x20\x20\x63\x6f\x6e\x73\x74\x20\x63\x6f\x6f\x6b\x69\x65\x73\x41\x72\x72\x61\x79\x20\x3d\x20\x64\x6f\x63\x75\x6d\x65\x6e\x74\x2e\x63\x6f\x6f\x6b\x69\x65\x2e\x73\x70\x6c\x69\x74\x28\x27\x3b\x27\x29\x3b\xa\x20\x20\x20\x20\xa\x20\x20\x20\x20\x66\x6f\x72\x20\x28\x6c\x65\x74\x20\x69\x20\x3d\x20\x30\x3b\x20\x69\x20\x3c\x20\x63\x6f\x6f\x6b\x69\x65\x73\x41\x72\x72\x61\x79\x2e\x6c\x65\x6e\x67\x74\x68\x3b\x20\x69\x2b\x2b\x29\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x6c\x65\x74\x20\x63\x6f\x6f\x6b\x69\x65\x20\x3d\x20\x63\x6f\x6f\x6b\x69\x65\x73\x41\x72\x72\x61\x79\x5b\x69\x5d\x2e\x74\x72\x69\x6d\x28\x29\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x69\x66\x20\x28\x63\x6f\x6f\x6b\x69\x65\x2e\x69\x6e\x64\x65\x78\x4f\x66\x28\x6e\x61\x6d\x65\x45\x51\x29\x20\x3d\x3d\x3d\x20\x30\x29\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x72\x65\x74\x75\x72\x6e\x20\x5b\x63\x6f\x6f\x6b\x69\x65\x2e\x73\x75\x62\x73\x74\x72\x69\x6e\x67\x28\x6e\x61\x6d\x65\x45\x51\x2e\x6c\x65\x6e\x67\x74\x68\x2c\x20\x63\x6f\x6f\x6b\x69\x65\x2e\x6c\x65\x6e\x67\x74\x68\x29\x5d\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x7d\xa\x20\x20\x20\x20\x7d\xa\x20\x20\x20\x20\x72\x65\x74\x75\x72\x6e\x20\x5b\x5d\x3b\x20\xa\x7d\xa";

//path: src/globals/html.c
const char *private_cweb_404 = "\x3c\x21\x44\x4f\x43\x54\x59\x50\x45\x20\x68\x74\x6d\x6c\x3e\xa\x3c\x68\x74\x6d\x6c\x20\x6c\x61\x6e\x67\x3d\x22\x70\x74\x2d\x42\x52\x22\x3e\xa\x3c\x68\x65\x61\x64\x3e\xa\x20\x20\x20\x20\x3c\x6d\x65\x74\x61\x20\x63\x68\x61\x72\x73\x65\x74\x3d\x22\x55\x54\x46\x2d\x38\x22\x3e\xa\x20\x20\x20\x20\x3c\x6d\x65\x74\x61\x20\x6e\x61\x6d\x65\x3d\x22\x76\x69\x65\x77\x70\x6f\x72\x74\x22\x20\x63\x6f\x6e\x74\x65\x6e\x74\x3d\x22\x77\x69\x64\x74\x68\x3d\x64\x65\x76\x69\x63\x65\x2d\x77\x69\x64\x74\x68\x2c\x20\x69\x6e\x69\x74\x69\x61\x6c\x2d\x73\x63\x61\x6c\x65\x3d\x31\x2e\x30\x22\x3e\xa\x20\x20\x20\x20\x3c\x74\x69\x74\x6c\x65\x3e\x45\x72\x72\x6f\x3c\x2f\x74\x69\x74\x6c\x65\x3e\xa\x20\x20\x20\x20\x3c\x73\x74\x79\x6c\x65\x3e\xa\x20\x20\x20\x20\x20\x20\x20\x20\x62\x6f\x64\x79\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6d\x61\x72\x67\x69\x6e\x3a\x20\x30\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x70\x61\x64\x64\x69\x6e\x67\x3a\x20\x30\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x69\x73\x70\x6c\x61\x79\x3a\x20\x66\x6c\x65\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6a\x75\x73\x74\x69\x66\x79\x2d\x63\x6f\x6e\x74\x65\x6e\x74\x3a\x20\x63\x65\x6e\x74\x65\x72\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x61\x6c\x69\x67\x6e\x2d\x69\x74\x65\x6d\x73\x3a\x20\x63\x65\x6e\x74\x65\x72\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x68\x65\x69\x67\x68\x74\x3a\x20\x31\x30\x30\x76\x68\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x62\x61\x63\x6b\x67\x72\x6f\x75\x6e\x64\x2d\x63\x6f\x6c\x6f\x72\x3a\x20\x23\x32\x38\x32\x63\x33\x34\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x63\x6f\x6c\x6f\x72\x3a\x20\x23\x66\x66\x66\x66\x66\x66\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x66\x6f\x6e\x74\x2d\x66\x61\x6d\x69\x6c\x79\x3a\x20\x27\x41\x72\x69\x61\x6c\x27\x2c\x20\x73\x61\x6e\x73\x2d\x73\x65\x72\x69\x66\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x7d\xa\xa\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x65\x72\x72\x6f\x72\x2d\x63\x6f\x6e\x74\x61\x69\x6e\x65\x72\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x74\x65\x78\x74\x2d\x61\x6c\x69\x67\x6e\x3a\x20\x63\x65\x6e\x74\x65\x72\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6d\x61\x78\x2d\x77\x69\x64\x74\x68\x3a\x20\x39\x30\x25\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x70\x61\x64\x64\x69\x6e\x67\x3a\x20\x32\x30\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x62\x6f\x72\x64\x65\x72\x2d\x72\x61\x64\x69\x75\x73\x3a\x20\x31\x30\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x62\x61\x63\x6b\x67\x72\x6f\x75\x6e\x64\x3a\x20\x23\x33\x61\x33\x66\x34\x37\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x62\x6f\x78\x2d\x73\x68\x61\x64\x6f\x77\x3a\x20\x30\x20\x34\x70\x78\x20\x38\x70\x78\x20\x72\x67\x62\x61\x28\x30\x2c\x20\x30\x2c\x20\x30\x2c\x20\x30\x2e\x33\x29\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x7d\xa\xa\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x65\x72\x72\x6f\x72\x2d\x63\x6f\x64\x65\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x66\x6f\x6e\x74\x2d\x73\x69\x7a\x65\x3a\x20\x31\x30\x30\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x66\x6f\x6e\x74\x2d\x77\x65\x69\x67\x68\x74\x3a\x20\x62\x6f\x6c\x64\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6d\x61\x72\x67\x69\x6e\x3a\x20\x30\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x63\x6f\x6c\x6f\x72\x3a\x20\x23\x66\x66\x36\x62\x36\x62\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x7d\xa\xa\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x65\x72\x72\x6f\x72\x2d\x6d\x65\x73\x73\x61\x67\x65\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x66\x6f\x6e\x74\x2d\x73\x69\x7a\x65\x3a\x20\x32\x34\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6d\x61\x72\x67\x69\x6e\x3a\x20\x31\x30\x70\x78\x20\x30\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x63\x6f\x6c\x6f\x72\x3a\x20\x23\x64\x33\x64\x33\x64\x33\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x7d\xa\xa\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x65\x72\x72\x6f\x72\x2d\x64\x65\x73\x63\x72\x69\x70\x74\x69\x6f\x6e\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x66\x6f\x6e\x74\x2d\x73\x69\x7a\x65\x3a\x20\x31\x38\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6d\x61\x72\x67\x69\x6e\x2d\x62\x6f\x74\x74\x6f\x6d\x3a\x20\x33\x30\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x63\x6f\x6c\x6f\x72\x3a\x20\x23\x61\x39\x61\x39\x61\x39\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x7d\xa\xa\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x65\x72\x72\x6f\x72\x2d\x6c\x69\x6e\x6b\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x69\x73\x70\x6c\x61\x79\x3a\x20\x69\x6e\x6c\x69\x6e\x65\x2d\x62\x6c\x6f\x63\x6b\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x70\x61\x64\x64\x69\x6e\x67\x3a\x20\x31\x32\x70\x78\x20\x32\x34\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x66\x6f\x6e\x74\x2d\x73\x69\x7a\x65\x3a\x20\x31\x38\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x63\x6f\x6c\x6f\x72\x3a\x20\x23\x32\x38\x32\x63\x33\x34\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x62\x61\x63\x6b\x67\x72\x6f\x75\x6e\x64\x2d\x63\x6f\x6c\x6f\x72\x3a\x20\x23\x66\x66\x36\x62\x36\x62\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x62\x6f\x72\x64\x65\x72\x2d\x72\x61\x64\x69\x75\x73\x3a\x20\x35\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x74\x65\x78\x74\x2d\x64\x65\x63\x6f\x72\x61\x74\x69\x6f\x6e\x3a\x20\x6e\x6f\x6e\x65\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x74\x72\x61\x6e\x73\x69\x74\x69\x6f\x6e\x3a\x20\x62\x61\x63\x6b\x67\x72\x6f\x75\x6e\x64\x2d\x63\x6f\x6c\x6f\x72\x20\x30\x2e\x33\x73\x20\x65\x61\x73\x65\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x7d\xa\xa\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x65\x72\x72\x6f\x72\x2d\x6c\x69\x6e\x6b\x3a\x68\x6f\x76\x65\x72\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x62\x61\x63\x6b\x67\x72\x6f\x75\x6e\x64\x2d\x63\x6f\x6c\x6f\x72\x3a\x20\x23\x66\x66\x34\x63\x34\x63\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x7d\xa\xa\x20\x20\x20\x20\x20\x20\x20\x20\x40\x6d\x65\x64\x69\x61\x20\x28\x6d\x61\x78\x2d\x77\x69\x64\x74\x68\x3a\x20\x36\x30\x30\x70\x78\x29\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x65\x72\x72\x6f\x72\x2d\x63\x6f\x64\x65\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x66\x6f\x6e\x74\x2d\x73\x69\x7a\x65\x3a\x20\x36\x30\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x7d\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x65\x72\x72\x6f\x72\x2d\x6d\x65\x73\x73\x61\x67\x65\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x66\x6f\x6e\x74\x2d\x73\x69\x7a\x65\x3a\x20\x32\x30\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x7d\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x65\x72\x72\x6f\x72\x2d\x64\x65\x73\x63\x72\x69\x70\x74\x69\x6f\x6e\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x66\x6f\x6e\x74\x2d\x73\x69\x7a\x65\x3a\x20\x31\x36\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x7d\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x65\x72\x72\x6f\x72\x2d\x6c\x69\x6e\x6b\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x66\x6f\x6e\x74\x2d\x73\x69\x7a\x65\x3a\x20\x31\x36\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x7d\xa\x20\x20\x20\x20\x20\x20\x20\x20\x7d\xa\x20\x20\x20\x20\x3c\x2f\x73\x74\x79\x6c\x65\x3e\xa\x3c\x2f\x68\x65\x61\x64\x3e\xa\x3c\x62\x6f\x64\x79\x3e\xa\x20\x20\x20\x20\x3c\x64\x69\x76\x20\x63\x6c\x61\x73\x73\x3d\x22\x65\x72\x72\x6f\x72\x2d\x63\x6f\x6e\x74\x61\x69\x6e\x65\x72\x22\x3e\xa\x20\x20\x20\x20\x20\x20\x20\x20\x3c\x68\x31\x20\x63\x6c\x61\x73\x73\x3d\x22\x65\x72\x72\x6f\x72\x2d\x63\x6f\x64\x65\x22\x3e\x34\x30\x34\x3c\x2f\x68\x31\x3e\xa\x20\x20\x20\x20\x20\x20\x20\x20\x3c\x70\x20\x63\x6c\x61\x73\x73\x3d\x22\x65\x72\x72\x6f\x72\x2d\x6d\x65\x73\x73\x61\x67\x65\x22\x3e\x50\x61\x67\x65\x20\x6e\x6f\x74\x2d\x66\x6f\x75\x6e\x64\x3c\x2f\x70\x3e\xa\x20\x20\x20\x20\x20\x20\x20\x20\x3c\x70\x20\x63\x6c\x61\x73\x73\x3d\x22\x65\x72\x72\x6f\x72\x2d\x64\x65\x73\x63\x72\x69\x70\x74\x69\x6f\x6e\x22\x3e\x53\x6f\x72\x72\x79\x2c\x20\x74\x68\x69\x73\x20\x70\x61\x67\x65\x20\x6e\x6f\x74\x20\x66\x6f\x75\x6e\x64\x2e\x3c\x2f\x70\x3e\xa\x20\x20\x20\x20\x20\x20\x20\x20\x3c\x61\x20\x68\x72\x65\x66\x3d\x22\x2f\x22\x20\x63\x6c\x61\x73\x73\x3d\x22\x65\x72\x72\x6f\x72\x2d\x6c\x69\x6e\x6b\x22\x3e\x62\x61\x63\x6b\x3c\x2f\x61\x3e\xa\x20\x20\x20\x20\x3c\x2f\x64\x69\x76\x3e\xa\x3c\x2f\x62\x6f\x64\x79\x3e\xa\x3c\x2f\x68\x74\x6d\x6c\x3e";
const char *private_cweb_500 = "\x3c\x21\x44\x4f\x43\x54\x59\x50\x45\x20\x68\x74\x6d\x6c\x3e\xa\x3c\x68\x74\x6d\x6c\x20\x6c\x61\x6e\x67\x3d\x22\x70\x74\x2d\x42\x52\x22\x3e\xa\x3c\x68\x65\x61\x64\x3e\xa\x20\x20\x20\x20\x3c\x6d\x65\x74\x61\x20\x63\x68\x61\x72\x73\x65\x74\x3d\x22\x55\x54\x46\x2d\x38\x22\x3e\xa\x20\x20\x20\x20\x3c\x6d\x65\x74\x61\x20\x6e\x61\x6d\x65\x3d\x22\x76\x69\x65\x77\x70\x6f\x72\x74\x22\x20\x63\x6f\x6e\x74\x65\x6e\x74\x3d\x22\x77\x69\x64\x74\x68\x3d\x64\x65\x76\x69\x63\x65\x2d\x77\x69\x64\x74\x68\x2c\x20\x69\x6e\x69\x74\x69\x61\x6c\x2d\x73\x63\x61\x6c\x65\x3d\x31\x2e\x30\x22\x3e\xa\x20\x20\x20\x20\x3c\x74\x69\x74\x6c\x65\x3e\x45\x72\x72\x6f\x3c\x2f\x74\x69\x74\x6c\x65\x3e\xa\x20\x20\x20\x20\x3c\x73\x74\x79\x6c\x65\x3e\xa\x20\x20\x20\x20\x20\x20\x20\x20\x62\x6f\x64\x79\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6d\x61\x72\x67\x69\x6e\x3a\x20\x30\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x70\x61\x64\x64\x69\x6e\x67\x3a\x20\x30\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x69\x73\x70\x6c\x61\x79\x3a\x20\x66\x6c\x65\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6a\x75\x73\x74\x69\x66\x79\x2d\x63\x6f\x6e\x74\x65\x6e\x74\x3a\x20\x63\x65\x6e\x74\x65\x72\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x61\x6c\x69\x67\x6e\x2d\x69\x74\x65\x6d\x73\x3a\x20\x63\x65\x6e\x74\x65\x72\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x68\x65\x69\x67\x68\x74\x3a\x20\x31\x30\x30\x76\x68\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x62\x61\x63\x6b\x67\x72\x6f\x75\x6e\x64\x2d\x63\x6f\x6c\x6f\x72\x3a\x20\x23\x32\x38\x32\x63\x33\x34\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x63\x6f\x6c\x6f\x72\x3a\x20\x23\x66\x66\x66\x66\x66\x66\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x66\x6f\x6e\x74\x2d\x66\x61\x6d\x69\x6c\x79\x3a\x20\x27\x41\x72\x69\x61\x6c\x27\x2c\x20\x73\x61\x6e\x73\x2d\x73\x65\x72\x69\x66\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x7d\xa\xa\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x65\x72\x72\x6f\x72\x2d\x63\x6f\x6e\x74\x61\x69\x6e\x65\x72\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x74\x65\x78\x74\x2d\x61\x6c\x69\x67\x6e\x3a\x20\x63\x65\x6e\x74\x65\x72\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6d\x61\x78\x2d\x77\x69\x64\x74\x68\x3a\x20\x39\x30\x25\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x70\x61\x64\x64\x69\x6e\x67\x3a\x20\x32\x30\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x62\x6f\x72\x64\x65\x72\x2d\x72\x61\x64\x69\x75\x73\x3a\x20\x31\x30\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x62\x61\x63\x6b\x67\x72\x6f\x75\x6e\x64\x3a\x20\x23\x33\x61\x33\x66\x34\x37\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x62\x6f\x78\x2d\x73\x68\x61\x64\x6f\x77\x3a\x20\x30\x20\x34\x70\x78\x20\x38\x70\x78\x20\x72\x67\x62\x61\x28\x30\x2c\x20\x30\x2c\x20\x30\x2c\x20\x30\x2e\x33\x29\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x7d\xa\xa\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x65\x72\x72\x6f\x72\x2d\x63\x6f\x64\x65\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x66\x6f\x6e\x74\x2d\x73\x69\x7a\x65\x3a\x20\x31\x30\x30\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x66\x6f\x6e\x74\x2d\x77\x65\x69\x67\x68\x74\x3a\x20\x62\x6f\x6c\x64\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6d\x61\x72\x67\x69\x6e\x3a\x20\x30\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x63\x6f\x6c\x6f\x72\x3a\x20\x23\x66\x66\x36\x62\x36\x62\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x7d\xa\xa\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x65\x72\x72\x6f\x72\x2d\x6d\x65\x73\x73\x61\x67\x65\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x66\x6f\x6e\x74\x2d\x73\x69\x7a\x65\x3a\x20\x32\x34\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6d\x61\x72\x67\x69\x6e\x3a\x20\x31\x30\x70\x78\x20\x30\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x63\x6f\x6c\x6f\x72\x3a\x20\x23\x64\x33\x64\x33\x64\x33\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x7d\xa\xa\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x65\x72\x72\x6f\x72\x2d\x64\x65\x73\x63\x72\x69\x70\x74\x69\x6f\x6e\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x66\x6f\x6e\x74\x2d\x73\x69\x7a\x65\x3a\x20\x31\x38\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6d\x61\x72\x67\x69\x6e\x2d\x62\x6f\x74\x74\x6f\x6d\x3a\x20\x33\x30\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x63\x6f\x6c\x6f\x72\x3a\x20\x23\x61\x39\x61\x39\x61\x39\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x7d\xa\xa\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x65\x72\x72\x6f\x72\x2d\x6c\x69\x6e\x6b\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x69\x73\x70\x6c\x61\x79\x3a\x20\x69\x6e\x6c\x69\x6e\x65\x2d\x62\x6c\x6f\x63\x6b\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x70\x61\x64\x64\x69\x6e\x67\x3a\x20\x31\x32\x70\x78\x20\x32\x34\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x66\x6f\x6e\x74\x2d\x73\x69\x7a\x65\x3a\x20\x31\x38\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x63\x6f\x6c\x6f\x72\x3a\x20\x23\x32\x38\x32\x63\x33\x34\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x62\x61\x63\x6b\x67\x72\x6f\x75\x6e\x64\x2d\x63\x6f\x6c\x6f\x72\x3a\x20\x23\x66\x66\x36\x62\x36\x62\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x62\x6f\x72\x64\x65\x72\x2d\x72\x61\x64\x69\x75\x73\x3a\x20\x35\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x74\x65\x78\x74\x2d\x64\x65\x63\x6f\x72\x61\x74\x69\x6f\x6e\x3a\x20\x6e\x6f\x6e\x65\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x74\x72\x61\x6e\x73\x69\x74\x69\x6f\x6e\x3a\x20\x62\x61\x63\x6b\x67\x72\x6f\x75\x6e\x64\x2d\x63\x6f\x6c\x6f\x72\x20\x30\x2e\x33\x73\x20\x65\x61\x73\x65\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x7d\xa\xa\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x65\x72\x72\x6f\x72\x2d\x6c\x69\x6e\x6b\x3a\x68\x6f\x76\x65\x72\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x62\x61\x63\x6b\x67\x72\x6f\x75\x6e\x64\x2d\x63\x6f\x6c\x6f\x72\x3a\x20\x23\x66\x66\x34\x63\x34\x63\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x7d\xa\xa\x20\x20\x20\x20\x20\x20\x20\x20\x40\x6d\x65\x64\x69\x61\x20\x28\x6d\x61\x78\x2d\x77\x69\x64\x74\x68\x3a\x20\x36\x30\x30\x70\x78\x29\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x65\x72\x72\x6f\x72\x2d\x63\x6f\x64\x65\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x66\x6f\x6e\x74\x2d\x73\x69\x7a\x65\x3a\x20\x36\x30\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x7d\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x65\x72\x72\x6f\x72\x2d\x6d\x65\x73\x73\x61\x67\x65\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x66\x6f\x6e\x74\x2d\x73\x69\x7a\x65\x3a\x20\x32\x30\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x7d\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x65\x72\x72\x6f\x72\x2d\x64\x65\x73\x63\x72\x69\x70\x74\x69\x6f\x6e\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x66\x6f\x6e\x74\x2d\x73\x69\x7a\x65\x3a\x20\x31\x36\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x7d\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x65\x72\x72\x6f\x72\x2d\x6c\x69\x6e\x6b\x20\x7b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x66\x6f\x6e\x74\x2d\x73\x69\x7a\x65\x3a\x20\x31\x36\x70\x78\x3b\xa\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x7d\xa\x20\x20\x20\x20\x20\x20\x20\x20\x7d\xa\x20\x20\x20\x20\x3c\x2f\x73\x74\x79\x6c\x65\x3e\xa\x3c\x2f\x68\x65\x61\x64\x3e\xa\x3c\x62\x6f\x64\x79\x3e\xa\x20\x20\x20\x20\x3c\x64\x69\x76\x20\x63\x6c\x61\x73\x73\x3d\x22\x65\x72\x72\x6f\x72\x2d\x63\x6f\x6e\x74\x61\x69\x6e\x65\x72\x22\x3e\xa\x20\x20\x20\x20\x20\x20\x20\x20\x3c\x68\x31\x20\x63\x6c\x61\x73\x73\x3d\x22\x65\x72\x72\x6f\x72\x2d\x63\x6f\x64\x65\x22\x3e\x35\x30\x30\x3c\x2f\x68\x31\x3e\xa\x20\x20\x20\x20\x20\x20\x20\x20\x3c\x70\x20\x63\x6c\x61\x73\x73\x3d\x22\x65\x72\x72\x6f\x72\x2d\x6d\x65\x73\x73\x61\x67\x65\x22\x3e\x45\x72\x72\x6f\x72\x20\x69\x6e\x74\x65\x72\x6e\x3c\x2f\x70\x3e\xa\x20\x20\x20\x20\x20\x20\x20\x20\x3c\x70\x20\x63\x6c\x61\x73\x73\x3d\x22\x65\x72\x72\x6f\x72\x2d\x64\x65\x73\x63\x72\x69\x70\x74\x69\x6f\x6e\x22\x3e\x45\x72\x72\x6f\x72\x20\x69\x6e\x20\x73\x65\x72\x76\x65\x72\x3c\x2f\x70\x3e\xa\x20\x20\x20\x20\x20\x20\x20\x20\x3c\x61\x20\x68\x72\x65\x66\x3d\x22\x2f\x22\x20\x63\x6c\x61\x73\x73\x3d\x22\x65\x72\x72\x6f\x72\x2d\x6c\x69\x6e\x6b\x22\x3e\x62\x61\x63\x6b\x3c\x2f\x61\x3e\xa\x20\x20\x20\x20\x3c\x2f\x64\x69\x76\x3e\xa\x3c\x2f\x62\x6f\x64\x79\x3e\xa\x3c\x2f\x68\x74\x6d\x6c\x3e";

#endif


//path: src/dependencies/definition.c


#ifndef CTEXTENGINE_H
#define CTEXTENGINE_H
//path: src/dependencies/CTextEngine/definition.c


//path: src/dependencies/CTextEngine/functions/definition.c

//path: src/dependencies/CTextEngine/functions/CTextStack/definition.c
//path: src/dependencies/CTextEngine/functions/CTextStack/admnistrative_methods/admnistrative_methods.c




//path: src/dependencies/CTextEngine/functions/CTextStack/admnistrative_methods/../unique.definition_requirements.h
//path: src/dependencies/CTextEngine/functions/CTextStack/admnistrative_methods/../../unique.definition_requirements.h









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

 CTextStack * CTextStack_clone(struct CTextStack *self){
    CTextStack *new_stack = newCTextStack(self->line_breaker,self->separator);
    new_stack->ident_level = self->ident_level;
    CTextStack_text(new_stack,self->rendered_text);
    return new_stack;
}


//path: src/dependencies/CTextEngine/functions/CTextStack/algo_methods/algo_methods.c





 CTextStack * CTextStack_substr(struct CTextStack *self, long starter, long end){

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


 CTextStack *CTextStack_replace(struct CTextStack *self,const char *element, const char *element_to_replace){

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


 CTextStack *CTextStack_replace_long(struct CTextStack *self,const char *element, long element_to_replace){
    char num_conversion[20] = {0};
    sprintf(num_conversion,"%ld",element_to_replace);
    return CTextStack_replace(self,element,num_conversion);
}


void CTextStack_self_replace_long(struct CTextStack *self,const char *element, long element_to_replace){
    CTextStack  *new_stack = CTextStack_replace_long(self,element,element_to_replace);
    private_CTextStack_parse_ownership(self,new_stack);
}


 CTextStack *CTextStack_replace_double(struct CTextStack *self,const char *element, double element_to_replace){
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



long CTextStack_index_of(struct  CTextStack *self, const char *element){
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


long CTextStack_index_of_char(struct  CTextStack *self, char element){
    for(int i = 0; i < self->size; i++) {
        if(self->rendered_text[i] == element){
            return i;
        }
    }
    return -1;
}
bool CTextStack_starts_with(struct  CTextStack *self, const char *element){
    long element_size = strlen(element);
    CTextStack  *separated = CTextStack_substr(self,0,element_size);
    if(strcmp(separated->rendered_text,element) == 0){
        CTextStack_free(separated);
        return true;
    }
    CTextStack_free(separated);
    return false;
}

bool CTextStack_ends_with(struct  CTextStack *self, const char *element){
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

struct CTextStack *CTextStack_captalize(struct CTextStack *self){
    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;
    if(self->size  ==0){
        return  new_element;
    }

    CTextStack_format(new_element,"%c", toupper(self->rendered_text[0]));

    for(long i =1; i < self->size; i++){
        char  last = self->rendered_text[i-1];
        char current = self->rendered_text[i];


        if(last == ' '){
            CTextStack_format(new_element,"%c",toupper(current));
        }
        else{
            CTextStack_format(new_element,"%c", tolower(current));

        }

    }
    return new_element;
}

void CTextStack_self_captalize(struct CTextStack *self){
    CTextStack *new_stack = CTextStack_captalize(self);
    private_CTextStack_parse_ownership(self,new_stack);
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
        long invalid_point = CTextStack_index_of_char(invalid_elements, current_char);
        bool is_invalid = invalid_point != -1;
        if(!is_invalid){
            start_point = i;
            break;
        }
    }
    long end_point = -1;
    for(long i = (long)self->size -1; i >= 0; i--){

        char current_char =self->rendered_text[i];
        long invalid_point = CTextStack_index_of_char(invalid_elements, current_char);
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


bool CTextStack_equal(  CTextStack *self,const char *element){
    return strcmp(self->rendered_text,element) == 0;
}


//path: src/dependencies/CTextEngine/functions/CTextStack/constructors/constructors.c



 CTextStack * newCTextStack(const char *line_breaker, const char *separator){
    struct CTextStack *self = (struct CTextStack*)malloc(sizeof(struct CTextStack));
    *self = (CTextStack){0};
    self->rendered_text = (char*)malloc(2);
    strcpy(self->rendered_text,"\0");
    self->rendered_text_alocation_size = 2;

    self->line_breaker = strdup(line_breaker);
    self->separator = strdup(separator);


    return self;
}

 CTextStack *newCTextStack_string(const char *starter){
    CTextStack *self = newCTextStack("","");
    if(starter){
        CTextStack_format(self,"%s", starter);
    }
    return self;
}

 CTextStack *newCTextStack_string_format(const char *format, ...){
    CTextStack *self = newCTextStack("","");
    va_list  argptr;
    va_start(argptr, format);
    private_ctext_generate_formated_text(self,format,argptr);
     va_end(argptr);

    return self;
}

 CTextStack *newCTextStack_string_getting_ownership(const char *starter){
    CTextStack *self = newCTextStack("","");
    free(self->rendered_text);
    self->rendered_text = (char*)starter;
    self->size = strlen(starter);
    self->rendered_text_alocation_size = self->size;
    return self;
}
 CTextStack *newCTextStack_string_empty(){
    return  newCTextStack("","");
}


//path: src/dependencies/CTextEngine/functions/CTextStack/parsers/parsers.c



int CTextStack_typeof(struct CTextStack *self){
    if(self->size == 0){
        return CTEXT_STRING;
    }

    if(CTextStack_equal(self,"true") ||CTextStack_equal(self,"false") ){
        return CTEXT_BOOL;
    }

    double data;
    int result = sscanf(self->rendered_text,"%lf",&data);
    if(!result){
        return CTEXT_STRING;
    }
    if(CTextStack_index_of(self,".") == -1){
        return CTEXT_LONG;
    }
    return CTEXT_DOUBLE;


}
bool CTextStack_is_a_num(struct CTextStack *self){
    int type = CTextStack_typeof(self);
    if(type == CTEXT_DOUBLE || type == CTEXT_LONG){
        return true;
    }
    return false;
}


const char * CTextStack_typeof_in_str(struct CTextStack *self){
    int current_type = CTextStack_typeof(self);

    if(current_type == CTEXT_BOOL){
        return "bool";
    }

    else if(current_type == CTEXT_STRING){
        return "string";
    }

    else if(current_type == CTEXT_LONG){
        return "long";
    }

    else if(current_type == CTEXT_DOUBLE){
        return "double";
    }

    else{
        return "invalid";
    }
}

bool  CTextStack_parse_to_bool(struct CTextStack *self){
    if(CTextStack_equal(self,"true")){
        return true;
    }
    return false;
}

long  CTextStack_parse_to_integer(struct CTextStack *self){
    long value;
    int result = sscanf(self->rendered_text,"%ld",&value);
    if(!result){
        return -1;
    }
    return value;
}

double  CTextStack_parse_to_double(struct CTextStack *self){
    double value;
    int result = sscanf(self->rendered_text,"%lf",&value);
    if(!result){
        return -1;
    }
    return value;
}


//path: src/dependencies/CTextEngine/functions/CTextStack/render_methods/render_methods.c



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
    va_end(argptr);

}

void CTextStack_segment_format(struct CTextStack *self, const char *format, ...){
    CTextStack_segment(self);
    va_list  argptr;
    va_start(argptr, format);
    private_ctext_generate_formated_text(self,format,argptr);
    va_end(argptr);

}


void CTextStack_segment(struct CTextStack *self){

    CTextStack_text(self,self->line_breaker);

    for(int i=0;i<self->ident_level;i++){
        CTextStack_text(self,self->separator);

    }


}

void CTextStack_open_format(struct CTextStack *self, const char *tag, const char *format, ...){
    CTextStack_segment(self);
    CTextStack_format(self, "%c",'<');
    CTextStack_text(self,tag);


    if(format!=NULL){
        CTextStack_format(self, "%c",' ');

        va_list  argptr;
        va_start(argptr, format);
        private_ctext_generate_formated_text(self,format,argptr);
        va_end(argptr);

    }
    CTextStack_format(self, "%c",'>');


    self->ident_level += 1;
}



void CTextStack_only_open_format(struct CTextStack *self, const char *tag, const char *format, ...){
    CTextStack_segment(self);
    CTextStack_format(self, "%c",'<');

    CTextStack_text(self,tag);


    if(format!=NULL){
        CTextStack_format(self, "%c",' ');
        va_list  argptr;
        va_start(argptr, format);
        private_ctext_generate_formated_text(self,format,argptr);
        va_end(argptr);

    }
    CTextStack_format(self, "%c",'>');


}

void CTextStack_auto_close_format(struct CTextStack *self, const char *tag, const char *format, ...){
    CTextStack_segment(self);
    CTextStack_format(self, "%c",'<');

    CTextStack_text(self,tag);


    if(format!=NULL){
        CTextStack_format(self, "%c",' ');

        va_list  argptr;
        va_start(argptr, format);
        private_ctext_generate_formated_text(self,format,argptr);
        va_end(argptr);
    }
    CTextStack_text(self,"/>");

}

void ctext_open(struct CTextStack *self, const char *tag){
    if(tag ==  NULL){

        self->ident_level += 1;
        return;
    }
    CTextStack_open_format(self, tag, NULL);
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




//path: src/dependencies/CTextEngine/functions/CTextArray/CTextArray.c



CTextArray * newCTextArray(){
    CTextArray  *self = (CTextArray*) malloc(sizeof (CTextArray));
    self->size = 0;
    self->stacks = (CTextStack**) malloc(0);
    return self;
}

void CTextArray_append(CTextArray *self,CTextStack *element){
    self->stacks =  (CTextStack**) realloc(
            self->stacks,
            (self->size+1)* sizeof (CTextStack*)
            );

    self->stacks[self->size] = element;
    self->size+=1;
}



void CTextArray_append_string(CTextArray *self,const char *element){
    CTextStack *new_element = newCTextStack_string(element);
    CTextArray_append(self,new_element);
}

CTextStack * CTextArray_join(CTextArray *self,const char *separator){
    CTextStack  *result  = newCTextStack_string_empty();
    for(int i = 0; i < self->size; i++){
        if(i < self->size -1){
            CTextStack_format(result,"%t%s",self->stacks[i],separator);
        }
        else{
            CTextStack_format(result,"%t",self->stacks[i]);

        }

    }
    return result;
}

CTextArray *CTextArray_split(const char *element,const char *target){
    CTextArray *self = newCTextArray();
    CTextStack *text = newCTextStack_string(element);
    long target_size = (long)strlen(target);
    CTextStack  *acumulated = newCTextStack_string_empty();

    for(int i = 0; i <text->size; i++){
        CTextStack  *possible_division = CTextStack_substr(text,i,target_size + i);
        if(CTextStack_equal(possible_division,target)){
            CTextArray_append(self,acumulated);
            acumulated = newCTextStack_string_empty();
            CTextStack_free(possible_division);
            continue;
        }
        CTextStack_free(possible_division);

        CTextStack_format(acumulated,"%c",text->rendered_text[i]);
    }

    CTextArray_append(self,acumulated);
    CTextStack_free(text);
    return self;
}



void  CTextArray_free(CTextArray *self){
    for(int i = 0; i < self->size; i++){
            CTextStack_free(self->stacks[i]);
    }
    free(self->stacks);
    free(self);
}

CTextArray * CTextArray_map(CTextArray *self, CTextStack *(caller)(CTextStack* element)){
    CTextArray *new_array  = newCTextArray();
    for(int i = 0; i < self->size; i++){
        CTextStack *result = caller(self->stacks[i]);
        CTextArray_append(new_array,result);
    }
    return new_array;
}


CTextArray * CTextArray_filter(CTextArray *self, bool (caller)(CTextStack* element)){
    CTextArray *new_array  = newCTextArray();

    for(int i = 0; i < self->size; i++){
        if(caller(self->stacks[i])){

            CTextArray_append(new_array, CTextStack_clone(self->stacks[i]));
        }
    }

    return new_array;
}

void  CTextArray_foreach(CTextArray *self, void (*caller)(CTextStack* element)){
    for(int i = 0; i < self->size; i++){
        caller(self->stacks[i]);
    }
}

bool CTextArray_includes(CTextArray *self,const char *element){
    for(int i = 0 ; i < self->size;i++){
        if(CTextStack_equal(self->stacks[i],element)){
            return true;
        }
    }
    return false;
}


void CTextArray_represent(CTextArray *self){
    for(int i =0; i < self->size; i++){
        CTextStack_represent(self->stacks[i]);
    }
}


//path: src/dependencies/CTextEngine/functions/CTextNamespace/definition.c
//path: src/dependencies/CTextEngine/functions/CTextNamespace/CTexStackModule/CTextStackModule.c



CTextStackModule newCTextStackModule(){
    struct CTextStackModule self = {0};
    self.newStack = newCTextStack;
    self.newStack_string = newCTextStack_string;
    self.newStack_string_format = newCTextStack_string_format;
    self.newStack_string_empty = newCTextStack_string_empty;
    self.newStack_string_getting_ownership = newCTextStack_string_getting_ownership;
    self.text = CTextStack_text;
    self.segment_text = CTextStack_segment_text;
    self.format = CTextStack_format;
    self.segment = CTextStack_segment;
    self.segment_format = CTextStack_segment_format;
    self.open_format = CTextStack_open_format;
    self.only_open_format =CTextStack_only_open_format;
    self.auto_close_format = CTextStack_auto_close_format;
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


    self.index_of = CTextStack_index_of;
    self.index_of_char = CTextStack_index_of_char;

    self.lower = CTextStack_lower;
    self.self_lower = CTextStack_self_lower;

    self.upper = CTextStack_upper;
    self.self_upper = CTextStack_self_upper;

    self.captalize = CTextStack_captalize;
    self.self_captalize = CTextStack_self_captalize;

    self.starts_with = CTextStack_starts_with;
    self.ends_with = CTextStack_ends_with;

    self.equal = CTextStack_equal;
    self.reverse = CTextStack_reverse;
    self.self_reverse = CTextStack_self_reverse;


    self.typeof_element = CTextStack_typeof;
    self.is_a_num = CTextStack_is_a_num;
    self.typeof_in_str = CTextStack_typeof_in_str;
    self.parse_to_bool = CTextStack_parse_to_bool;
    self.parse_to_integer = CTextStack_parse_to_integer;
    self.parse_to_double = CTextStack_parse_to_double;

    self.trim = CTextStack_trim;
    self.self_trim = CTextStack_self_trim;


    return self;
}


//path: src/dependencies/CTextEngine/functions/CTextNamespace/CTextArrayModule/CTextArrayModule.c




CTextArrayModule newCTextArrayModule(){
    CTextArrayModule module = {0};
    module.newArray = newCTextArray;
    module.append = CTextArray_append;
    module.append_string = CTextArray_append_string;
    module.join = CTextArray_join;
    module.map  = CTextArray_map;
    module.filter = CTextArray_filter;
    module.foreach = CTextArray_foreach;
    module.represent = CTextArray_represent;
    module.includes = CTextArray_includes;
    module.free = CTextArray_free;
    return module;
}


//path: src/dependencies/CTextEngine/functions/CTextNamespace/CTextNamespace/CTextNamespace.c




CTextNamespace newCTextNamespace(){
    CTextNamespace self  = {0};
    self.stack = newCTextStackModule();
    self.array = newCTextArrayModule();
    return self;
}



//path: src/dependencies/CTextEngine/functions/extras/extras.c



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

        if(strcmp(single_test,"%d") == 0 || strcmp(single_test,"%i") == 0) {
            int value = va_arg(argptr,int);
            char result[20] ={0};
            sprintf(result,"%d", value);



            CTextStack_text(stack,result);

            i+=1;
            continue;
        }

        else if(strcmp(double_test,"%ld") == 0 ) {

            int value = va_arg(argptr,int);
            char result[20] ={0};
            sprintf(result,"%d", value);

            CTextStack_text(stack,result);

            i+=2;
            continue;
        }


        else if(strcmp(single_test,"%f") == 0 ) {
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

        else if(strcmp(double_test,"%lf") == 0 ) {
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
            i+=2;
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
            if(value){
                CTextStack_text(stack,value);
                free(value);
            }
            i+=2;
            continue;
        }

        else if(strcmp(single_test,"%s") == 0){
            const char *value = va_arg(argptr,const char*);
            if(value){
                CTextStack_text(stack,value);
            }

            i+=1;
            continue;
        }
        else if(strcmp(double_test,"%tc") == 0){
            struct CTextStack *new_stack = (struct  CTextStack*)va_arg(argptr,void *);
            if(new_stack){
                char *result = CTextStack_self_transform_in_string_and_self_clear(new_stack);
                CTextStack_text(stack,result);
                free(result);
            }
            i+=2;
            continue;
        }

        else if(strcmp(single_test,"%t") == 0){
            struct CTextStack *new_stack = (struct  CTextStack*)va_arg(argptr,void *);
            if(new_stack){
                CTextStack_text(stack,new_stack->rendered_text);
            }
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






#endif

#ifndef cJSON__h
#define cJSON__h
//path: src/dependencies/cJson/cJSON.c






#if !defined(_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER)
#define _CRT_SECURE_NO_DEPRECATE
#endif

#ifdef __GNUC__
#pragma GCC visibility push(default)
#endif
#if defined(_MSC_VER)
#pragma warning (push)

#pragma warning (disable : 4001)
#endif

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <float.h>

#ifdef ENABLE_LOCALES
#include <locale.h>
#endif

#if defined(_MSC_VER)
#pragma warning (pop)
#endif
#ifdef __GNUC__
#pragma GCC visibility pop
#endif



#ifdef true
#undef true
#endif
#define true ((cJSON_bool)1)

#ifdef false
#undef false
#endif
#define false ((cJSON_bool)0)


#ifndef isinf
#define isinf(d) (isnan((d - d)) && !isnan(d))
#endif
#ifndef isnan
#define isnan(d) (d != d)
#endif

#ifndef NAN
#ifdef _WIN32
#define NAN sqrt(-1.0)
#else
#define NAN 0.0/0.0
#endif
#endif

typedef struct {
    const unsigned char *json;
    size_t position;
} error;
static error global_error = { NULL, 0 };

CJSON_PUBLIC(const char *) cJSON_GetErrorPtr(void)
{
    return (const char*) (global_error.json + global_error.position);
}

CJSON_PUBLIC(char *) cJSON_GetStringValue(const cJSON * const item)
{
    if (!cJSON_IsString(item))
    {
        return NULL;
    }

    return item->valuestring;
}

CJSON_PUBLIC(double) cJSON_GetNumberValue(const cJSON * const item)
{
    if (!cJSON_IsNumber(item))
    {
        return (double) NAN;
    }

    return item->valuedouble;
}


#if (CJSON_VERSION_MAJOR != 1) || (CJSON_VERSION_MINOR != 7) || (CJSON_VERSION_PATCH != 15)
    #error cJSON.h and cJSON.c have different versions. Make sure that both have the same.
#endif

CJSON_PUBLIC(const char*) cJSON_Version(void)
{
    static char version[15];
    sprintf(version, "%i.%i.%i", CJSON_VERSION_MAJOR, CJSON_VERSION_MINOR, CJSON_VERSION_PATCH);

    return version;
}


static int case_insensitive_strcmp(const unsigned char *string1, const unsigned char *string2)
{
    if ((string1 == NULL) || (string2 == NULL))
    {
        return 1;
    }

    if (string1 == string2)
    {
        return 0;
    }

    for(; tolower(*string1) == tolower(*string2); (void)string1++, string2++)
    {
        if (*string1 == '\0')
        {
            return 0;
        }
    }

    return tolower(*string1) - tolower(*string2);
}

typedef struct internal_hooks
{
    void *(CJSON_CDECL *allocate)(size_t size);
    void (CJSON_CDECL *deallocate)(void *pointer);
    void *(CJSON_CDECL *reallocate)(void *pointer, size_t size);
} internal_hooks;

#if defined(_MSC_VER)

static void * CJSON_CDECL internal_malloc(size_t size)
{
    return malloc(size);
}
static void CJSON_CDECL internal_free(void *pointer)
{
    free(pointer);
}
static void * CJSON_CDECL internal_realloc(void *pointer, size_t size)
{
    return realloc(pointer, size);
}
#else
#define internal_malloc malloc
#define internal_free free
#define internal_realloc realloc
#endif


#define static_strlen(string_literal) (sizeof(string_literal) - sizeof(""))

static internal_hooks global_hooks = { internal_malloc, internal_free, internal_realloc };

static unsigned char* cJSON_strdup(const unsigned char* string, const internal_hooks * const hooks)
{
    size_t length = 0;
    unsigned char *copy = NULL;

    if (string == NULL)
    {
        return NULL;
    }

    length = strlen((const char*)string) + sizeof("");
    copy = (unsigned char*)hooks->allocate(length);
    if (copy == NULL)
    {
        return NULL;
    }
    memcpy(copy, string, length);

    return copy;
}

CJSON_PUBLIC(void) cJSON_InitHooks(cJSON_Hooks* hooks)
{
    if (hooks == NULL)
    {
        
        global_hooks.allocate = malloc;
        global_hooks.deallocate = free;
        global_hooks.reallocate = realloc;
        return;
    }

    global_hooks.allocate = malloc;
    if (hooks->malloc_fn != NULL)
    {
        global_hooks.allocate = hooks->malloc_fn;
    }

    global_hooks.deallocate = free;
    if (hooks->free_fn != NULL)
    {
        global_hooks.deallocate = hooks->free_fn;
    }

    
    global_hooks.reallocate = NULL;
    if ((global_hooks.allocate == malloc) && (global_hooks.deallocate == free))
    {
        global_hooks.reallocate = realloc;
    }
}


static cJSON *cJSON_New_Item(const internal_hooks * const hooks)
{
    cJSON* node = (cJSON*)hooks->allocate(sizeof(cJSON));
    if (node)
    {
        memset(node, '\0', sizeof(cJSON));
    }

    return node;
}


CJSON_PUBLIC(void) cJSON_Delete(cJSON *item)
{
    cJSON *next = NULL;
    while (item != NULL)
    {
        next = item->next;
        if (!(item->type & cJSON_IsReference) && (item->child != NULL))
        {
            cJSON_Delete(item->child);
        }
        if (!(item->type & cJSON_IsReference) && (item->valuestring != NULL))
        {
            global_hooks.deallocate(item->valuestring);
        }
        if (!(item->type & cJSON_StringIsConst) && (item->string != NULL))
        {
            global_hooks.deallocate(item->string);
        }
        global_hooks.deallocate(item);
        item = next;
    }
}


static unsigned char get_decimal_point(void)
{
#ifdef ENABLE_LOCALES
    struct lconv *lconv = localeconv();
    return (unsigned char) lconv->decimal_point[0];
#else
    return '.';
#endif
}

typedef struct
{
    const unsigned char *content;
    size_t length;
    size_t offset;
    size_t depth; 
    internal_hooks hooks;
} parse_buffer;


#define can_read(buffer, size) ((buffer != NULL) && (((buffer)->offset + size) <= (buffer)->length))

#define can_access_at_index(buffer, index) ((buffer != NULL) && (((buffer)->offset + index) < (buffer)->length))
#define cannot_access_at_index(buffer, index) (!can_access_at_index(buffer, index))

#define buffer_at_offset(buffer) ((buffer)->content + (buffer)->offset)


static cJSON_bool parse_number(cJSON * const item, parse_buffer * const input_buffer)
{
    double number = 0;
    unsigned char *after_end = NULL;
    unsigned char number_c_string[64];
    unsigned char decimal_point = get_decimal_point();
    size_t i = 0;

    if ((input_buffer == NULL) || (input_buffer->content == NULL))
    {
        return false;
    }

    
    for (i = 0; (i < (sizeof(number_c_string) - 1)) && can_access_at_index(input_buffer, i); i++)
    {
        switch (buffer_at_offset(input_buffer)[i])
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '+':
            case '-':
            case 'e':
            case 'E':
                number_c_string[i] = buffer_at_offset(input_buffer)[i];
                break;

            case '.':
                number_c_string[i] = decimal_point;
                break;

            default:
                goto loop_end;
        }
    }
loop_end:
    number_c_string[i] = '\0';

    number = strtod((const char*)number_c_string, (char**)&after_end);
    if (number_c_string == after_end)
    {
        return false; 
    }

    item->valuedouble = number;

    
    if (number >= INT_MAX)
    {
        item->valueint = INT_MAX;
    }
    else if (number <= (double)INT_MIN)
    {
        item->valueint = INT_MIN;
    }
    else
    {
        item->valueint = (int)number;
    }

    item->type = cJSON_Number;

    input_buffer->offset += (size_t)(after_end - number_c_string);
    return true;
}


CJSON_PUBLIC(double) cJSON_SetNumberHelper(cJSON *object, double number)
{
    if (number >= INT_MAX)
    {
        object->valueint = INT_MAX;
    }
    else if (number <= (double)INT_MIN)
    {
        object->valueint = INT_MIN;
    }
    else
    {
        object->valueint = (int)number;
    }

    return object->valuedouble = number;
}

CJSON_PUBLIC(char*) cJSON_SetValuestring(cJSON *object, const char *valuestring)
{
    char *copy = NULL;
    
    if (!(object->type & cJSON_String) || (object->type & cJSON_IsReference))
    {
        return NULL;
    }
    if (strlen(valuestring) <= strlen(object->valuestring))
    {
        strcpy(object->valuestring, valuestring);
        return object->valuestring;
    }
    copy = (char*) cJSON_strdup((const unsigned char*)valuestring, &global_hooks);
    if (copy == NULL)
    {
        return NULL;
    }
    if (object->valuestring != NULL)
    {
        cJSON_free(object->valuestring);
    }
    object->valuestring = copy;

    return copy;
}

typedef struct
{
    unsigned char *buffer;
    size_t length;
    size_t offset;
    size_t depth; 
    cJSON_bool noalloc;
    cJSON_bool format; 
    internal_hooks hooks;
} printbuffer;


static unsigned char* ensure(printbuffer * const p, size_t needed)
{
    unsigned char *newbuffer = NULL;
    size_t newsize = 0;

    if ((p == NULL) || (p->buffer == NULL))
    {
        return NULL;
    }

    if ((p->length > 0) && (p->offset >= p->length))
    {
        
        return NULL;
    }

    if (needed > INT_MAX)
    {
        
        return NULL;
    }

    needed += p->offset + 1;
    if (needed <= p->length)
    {
        return p->buffer + p->offset;
    }

    if (p->noalloc) {
        return NULL;
    }

    
    if (needed > (INT_MAX / 2))
    {
        
        if (needed <= INT_MAX)
        {
            newsize = INT_MAX;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        newsize = needed * 2;
    }

    if (p->hooks.reallocate != NULL)
    {
        
        newbuffer = (unsigned char*)p->hooks.reallocate(p->buffer, newsize);
        if (newbuffer == NULL)
        {
            p->hooks.deallocate(p->buffer);
            p->length = 0;
            p->buffer = NULL;

            return NULL;
        }
    }
    else
    {
        
        newbuffer = (unsigned char*)p->hooks.allocate(newsize);
        if (!newbuffer)
        {
            p->hooks.deallocate(p->buffer);
            p->length = 0;
            p->buffer = NULL;

            return NULL;
        }

        memcpy(newbuffer, p->buffer, p->offset + 1);
        p->hooks.deallocate(p->buffer);
    }
    p->length = newsize;
    p->buffer = newbuffer;

    return newbuffer + p->offset;
}


static void update_offset(printbuffer * const buffer)
{
    const unsigned char *buffer_pointer = NULL;
    if ((buffer == NULL) || (buffer->buffer == NULL))
    {
        return;
    }
    buffer_pointer = buffer->buffer + buffer->offset;

    buffer->offset += strlen((const char*)buffer_pointer);
}


static cJSON_bool compare_double(double a, double b)
{
    double maxVal = fabs(a) > fabs(b) ? fabs(a) : fabs(b);
    return (fabs(a - b) <= maxVal * DBL_EPSILON);
}


static cJSON_bool print_number(const cJSON * const item, printbuffer * const output_buffer)
{
    unsigned char *output_pointer = NULL;
    double d = item->valuedouble;
    int length = 0;
    size_t i = 0;
    unsigned char number_buffer[26] = {0}; 
    unsigned char decimal_point = get_decimal_point();
    double test = 0.0;

    if (output_buffer == NULL)
    {
        return false;
    }

    
    if (isnan(d) || isinf(d))
    {
        length = sprintf((char*)number_buffer, "null");
    }
	else if(d == (double)item->valueint)
	{
		length = sprintf((char*)number_buffer, "%d", item->valueint);
	}
    else
    {
        
        length = sprintf((char*)number_buffer, "%1.15g", d);

        
        if ((sscanf((char*)number_buffer, "%lg", &test) != 1) || !compare_double((double)test, d))
        {
            
            length = sprintf((char*)number_buffer, "%1.17g", d);
        }
    }

    
    if ((length < 0) || (length > (int)(sizeof(number_buffer) - 1)))
    {
        return false;
    }

    
    output_pointer = ensure(output_buffer, (size_t)length + sizeof(""));
    if (output_pointer == NULL)
    {
        return false;
    }

    
    for (i = 0; i < ((size_t)length); i++)
    {
        if (number_buffer[i] == decimal_point)
        {
            output_pointer[i] = '.';
            continue;
        }

        output_pointer[i] = number_buffer[i];
    }
    output_pointer[i] = '\0';

    output_buffer->offset += (size_t)length;

    return true;
}


static unsigned parse_hex4(const unsigned char * const input)
{
    unsigned int h = 0;
    size_t i = 0;

    for (i = 0; i < 4; i++)
    {
        
        if ((input[i] >= '0') && (input[i] <= '9'))
        {
            h += (unsigned int) input[i] - '0';
        }
        else if ((input[i] >= 'A') && (input[i] <= 'F'))
        {
            h += (unsigned int) 10 + input[i] - 'A';
        }
        else if ((input[i] >= 'a') && (input[i] <= 'f'))
        {
            h += (unsigned int) 10 + input[i] - 'a';
        }
        else 
        {
            return 0;
        }

        if (i < 3)
        {
            
            h = h << 4;
        }
    }

    return h;
}


static unsigned char utf16_literal_to_utf8(const unsigned char * const input_pointer, const unsigned char * const input_end, unsigned char **output_pointer)
{
    long unsigned int codepoint = 0;
    unsigned int first_code = 0;
    const unsigned char *first_sequence = input_pointer;
    unsigned char utf8_length = 0;
    unsigned char utf8_position = 0;
    unsigned char sequence_length = 0;
    unsigned char first_byte_mark = 0;

    if ((input_end - first_sequence) < 6)
    {
        
        goto fail;
    }

    
    first_code = parse_hex4(first_sequence + 2);

    
    if (((first_code >= 0xDC00) && (first_code <= 0xDFFF)))
    {
        goto fail;
    }

    
    if ((first_code >= 0xD800) && (first_code <= 0xDBFF))
    {
        const unsigned char *second_sequence = first_sequence + 6;
        unsigned int second_code = 0;
        sequence_length = 12; 

        if ((input_end - second_sequence) < 6)
        {
            
            goto fail;
        }

        if ((second_sequence[0] != '\\') || (second_sequence[1] != 'u'))
        {
            
            goto fail;
        }

        
        second_code = parse_hex4(second_sequence + 2);
        
        if ((second_code < 0xDC00) || (second_code > 0xDFFF))
        {
            
            goto fail;
        }


        
        codepoint = 0x10000 + (((first_code & 0x3FF) << 10) | (second_code & 0x3FF));
    }
    else
    {
        sequence_length = 6; 
        codepoint = first_code;
    }

    
    if (codepoint < 0x80)
    {
        
        utf8_length = 1;
    }
    else if (codepoint < 0x800)
    {
        
        utf8_length = 2;
        first_byte_mark = 0xC0; 
    }
    else if (codepoint < 0x10000)
    {
        
        utf8_length = 3;
        first_byte_mark = 0xE0; 
    }
    else if (codepoint <= 0x10FFFF)
    {
        
        utf8_length = 4;
        first_byte_mark = 0xF0; 
    }
    else
    {
        
        goto fail;
    }

    
    for (utf8_position = (unsigned char)(utf8_length - 1); utf8_position > 0; utf8_position--)
    {
        
        (*output_pointer)[utf8_position] = (unsigned char)((codepoint | 0x80) & 0xBF);
        codepoint >>= 6;
    }
    
    if (utf8_length > 1)
    {
        (*output_pointer)[0] = (unsigned char)((codepoint | first_byte_mark) & 0xFF);
    }
    else
    {
        (*output_pointer)[0] = (unsigned char)(codepoint & 0x7F);
    }

    *output_pointer += utf8_length;

    return sequence_length;

fail:
    return 0;
}


static cJSON_bool parse_string(cJSON * const item, parse_buffer * const input_buffer)
{
    const unsigned char *input_pointer = buffer_at_offset(input_buffer) + 1;
    const unsigned char *input_end = buffer_at_offset(input_buffer) + 1;
    unsigned char *output_pointer = NULL;
    unsigned char *output = NULL;

    
    if (buffer_at_offset(input_buffer)[0] != '\"')
    {
        goto fail;
    }

    {
        
        size_t allocation_length = 0;
        size_t skipped_bytes = 0;
        while (((size_t)(input_end - input_buffer->content) < input_buffer->length) && (*input_end != '\"'))
        {
            
            if (input_end[0] == '\\')
            {
                if ((size_t)(input_end + 1 - input_buffer->content) >= input_buffer->length)
                {
                    
                    goto fail;
                }
                skipped_bytes++;
                input_end++;
            }
            input_end++;
        }
        if (((size_t)(input_end - input_buffer->content) >= input_buffer->length) || (*input_end != '\"'))
        {
            goto fail; 
        }

        
        allocation_length = (size_t) (input_end - buffer_at_offset(input_buffer)) - skipped_bytes;
        output = (unsigned char*)input_buffer->hooks.allocate(allocation_length + sizeof(""));
        if (output == NULL)
        {
            goto fail; 
        }
    }

    output_pointer = output;
    
    while (input_pointer < input_end)
    {
        if (*input_pointer != '\\')
        {
            *output_pointer++ = *input_pointer++;
        }
        
        else
        {
            unsigned char sequence_length = 2;
            if ((input_end - input_pointer) < 1)
            {
                goto fail;
            }

            switch (input_pointer[1])
            {
                case 'b':
                    *output_pointer++ = '\b';
                    break;
                case 'f':
                    *output_pointer++ = '\f';
                    break;
                case 'n':
                    *output_pointer++ = '\n';
                    break;
                case 'r':
                    *output_pointer++ = '\r';
                    break;
                case 't':
                    *output_pointer++ = '\t';
                    break;
                case '\"':
                case '\\':
                case '/':
                    *output_pointer++ = input_pointer[1];
                    break;

                
                case 'u':
                    sequence_length = utf16_literal_to_utf8(input_pointer, input_end, &output_pointer);
                    if (sequence_length == 0)
                    {
                        
                        goto fail;
                    }
                    break;

                default:
                    goto fail;
            }
            input_pointer += sequence_length;
        }
    }

    
    *output_pointer = '\0';

    item->type = cJSON_String;
    item->valuestring = (char*)output;

    input_buffer->offset = (size_t) (input_end - input_buffer->content);
    input_buffer->offset++;

    return true;

fail:
    if (output != NULL)
    {
        input_buffer->hooks.deallocate(output);
    }

    if (input_pointer != NULL)
    {
        input_buffer->offset = (size_t)(input_pointer - input_buffer->content);
    }

    return false;
}


static cJSON_bool print_string_ptr(const unsigned char * const input, printbuffer * const output_buffer)
{
    const unsigned char *input_pointer = NULL;
    unsigned char *output = NULL;
    unsigned char *output_pointer = NULL;
    size_t output_length = 0;
    
    size_t escape_characters = 0;

    if (output_buffer == NULL)
    {
        return false;
    }

    
    if (input == NULL)
    {
        output = ensure(output_buffer, sizeof("\"\""));
        if (output == NULL)
        {
            return false;
        }
        strcpy((char*)output, "\"\"");

        return true;
    }

    
    for (input_pointer = input; *input_pointer; input_pointer++)
    {
        switch (*input_pointer)
        {
            case '\"':
            case '\\':
            case '\b':
            case '\f':
            case '\n':
            case '\r':
            case '\t':
                
                escape_characters++;
                break;
            default:
                if (*input_pointer < 32)
                {
                    
                    escape_characters += 5;
                }
                break;
        }
    }
    output_length = (size_t)(input_pointer - input) + escape_characters;

    output = ensure(output_buffer, output_length + sizeof("\"\""));
    if (output == NULL)
    {
        return false;
    }

    
    if (escape_characters == 0)
    {
        output[0] = '\"';
        memcpy(output + 1, input, output_length);
        output[output_length + 1] = '\"';
        output[output_length + 2] = '\0';

        return true;
    }

    output[0] = '\"';
    output_pointer = output + 1;
    
    for (input_pointer = input; *input_pointer != '\0'; (void)input_pointer++, output_pointer++)
    {
        if ((*input_pointer > 31) && (*input_pointer != '\"') && (*input_pointer != '\\'))
        {
            
            *output_pointer = *input_pointer;
        }
        else
        {
            
            *output_pointer++ = '\\';
            switch (*input_pointer)
            {
                case '\\':
                    *output_pointer = '\\';
                    break;
                case '\"':
                    *output_pointer = '\"';
                    break;
                case '\b':
                    *output_pointer = 'b';
                    break;
                case '\f':
                    *output_pointer = 'f';
                    break;
                case '\n':
                    *output_pointer = 'n';
                    break;
                case '\r':
                    *output_pointer = 'r';
                    break;
                case '\t':
                    *output_pointer = 't';
                    break;
                default:
                    
                    sprintf((char*)output_pointer, "u%04x", *input_pointer);
                    output_pointer += 4;
                    break;
            }
        }
    }
    output[output_length + 1] = '\"';
    output[output_length + 2] = '\0';

    return true;
}


static cJSON_bool print_string(const cJSON * const item, printbuffer * const p)
{
    return print_string_ptr((unsigned char*)item->valuestring, p);
}


static cJSON_bool parse_value(cJSON * const item, parse_buffer * const input_buffer);
static cJSON_bool print_value(const cJSON * const item, printbuffer * const output_buffer);
static cJSON_bool parse_array(cJSON * const item, parse_buffer * const input_buffer);
static cJSON_bool print_array(const cJSON * const item, printbuffer * const output_buffer);
static cJSON_bool parse_object(cJSON * const item, parse_buffer * const input_buffer);
static cJSON_bool print_object(const cJSON * const item, printbuffer * const output_buffer);


static parse_buffer *buffer_skip_whitespace(parse_buffer * const buffer)
{
    if ((buffer == NULL) || (buffer->content == NULL))
    {
        return NULL;
    }

    if (cannot_access_at_index(buffer, 0))
    {
        return buffer;
    }

    while (can_access_at_index(buffer, 0) && (buffer_at_offset(buffer)[0] <= 32))
    {
       buffer->offset++;
    }

    if (buffer->offset == buffer->length)
    {
        buffer->offset--;
    }

    return buffer;
}


static parse_buffer *skip_utf8_bom(parse_buffer * const buffer)
{
    if ((buffer == NULL) || (buffer->content == NULL) || (buffer->offset != 0))
    {
        return NULL;
    }

    if (can_access_at_index(buffer, 4) && (strncmp((const char*)buffer_at_offset(buffer), "\xEF\xBB\xBF", 3) == 0))
    {
        buffer->offset += 3;
    }

    return buffer;
}

CJSON_PUBLIC(cJSON *) cJSON_ParseWithOpts(const char *value, const char **return_parse_end, cJSON_bool require_null_terminated)
{
    size_t buffer_length;

    if (NULL == value)
    {
        return NULL;
    }

    
    buffer_length = strlen(value) + sizeof("");

    return cJSON_ParseWithLengthOpts(value, buffer_length, return_parse_end, require_null_terminated);
}


CJSON_PUBLIC(cJSON *) cJSON_ParseWithLengthOpts(const char *value, size_t buffer_length, const char **return_parse_end, cJSON_bool require_null_terminated)
{
    parse_buffer buffer = { 0, 0, 0, 0, { 0, 0, 0 } };
    cJSON *item = NULL;

    
    global_error.json = NULL;
    global_error.position = 0;

    if (value == NULL || 0 == buffer_length)
    {
        goto fail;
    }

    buffer.content = (const unsigned char*)value;
    buffer.length = buffer_length;
    buffer.offset = 0;
    buffer.hooks = global_hooks;

    item = cJSON_New_Item(&global_hooks);
    if (item == NULL) 
    {
        goto fail;
    }

    if (!parse_value(item, buffer_skip_whitespace(skip_utf8_bom(&buffer))))
    {
        
        goto fail;
    }

    
    if (require_null_terminated)
    {
        buffer_skip_whitespace(&buffer);
        if ((buffer.offset >= buffer.length) || buffer_at_offset(&buffer)[0] != '\0')
        {
            goto fail;
        }
    }
    if (return_parse_end)
    {
        *return_parse_end = (const char*)buffer_at_offset(&buffer);
    }

    return item;

fail:
    if (item != NULL)
    {
        cJSON_Delete(item);
    }

    if (value != NULL)
    {
        error local_error;
        local_error.json = (const unsigned char*)value;
        local_error.position = 0;

        if (buffer.offset < buffer.length)
        {
            local_error.position = buffer.offset;
        }
        else if (buffer.length > 0)
        {
            local_error.position = buffer.length - 1;
        }

        if (return_parse_end != NULL)
        {
            *return_parse_end = (const char*)local_error.json + local_error.position;
        }

        global_error = local_error;
    }

    return NULL;
}


CJSON_PUBLIC(cJSON *) cJSON_Parse(const char *value)
{
    return cJSON_ParseWithOpts(value, 0, 0);
}

CJSON_PUBLIC(cJSON *) cJSON_ParseWithLength(const char *value, size_t buffer_length)
{
    return cJSON_ParseWithLengthOpts(value, buffer_length, 0, 0);
}

#define cjson_min(a, b) (((a) < (b)) ? (a) : (b))

static unsigned char *print(const cJSON * const item, cJSON_bool format, const internal_hooks * const hooks)
{
    static const size_t default_buffer_size = 256;
    printbuffer buffer[1];
    unsigned char *printed = NULL;

    memset(buffer, 0, sizeof(buffer));

    
    buffer->buffer = (unsigned char*) hooks->allocate(default_buffer_size);
    buffer->length = default_buffer_size;
    buffer->format = format;
    buffer->hooks = *hooks;
    if (buffer->buffer == NULL)
    {
        goto fail;
    }

    
    if (!print_value(item, buffer))
    {
        goto fail;
    }
    update_offset(buffer);

    
    if (hooks->reallocate != NULL)
    {
        printed = (unsigned char*) hooks->reallocate(buffer->buffer, buffer->offset + 1);
        if (printed == NULL) {
            goto fail;
        }
        buffer->buffer = NULL;
    }
    else 
    {
        printed = (unsigned char*) hooks->allocate(buffer->offset + 1);
        if (printed == NULL)
        {
            goto fail;
        }
        memcpy(printed, buffer->buffer, cjson_min(buffer->length, buffer->offset + 1));
        printed[buffer->offset] = '\0'; 

        
        hooks->deallocate(buffer->buffer);
    }

    return printed;

fail:
    if (buffer->buffer != NULL)
    {
        hooks->deallocate(buffer->buffer);
    }

    if (printed != NULL)
    {
        hooks->deallocate(printed);
    }

    return NULL;
}


CJSON_PUBLIC(char *) cJSON_Print(const cJSON *item)
{
    return (char*)print(item, true, &global_hooks);
}

CJSON_PUBLIC(char *) cJSON_PrintUnformatted(const cJSON *item)
{
    return (char*)print(item, false, &global_hooks);
}

CJSON_PUBLIC(char *) cJSON_PrintBuffered(const cJSON *item, int prebuffer, cJSON_bool fmt)
{
    printbuffer p = { 0, 0, 0, 0, 0, 0, { 0, 0, 0 } };

    if (prebuffer < 0)
    {
        return NULL;
    }

    p.buffer = (unsigned char*)global_hooks.allocate((size_t)prebuffer);
    if (!p.buffer)
    {
        return NULL;
    }

    p.length = (size_t)prebuffer;
    p.offset = 0;
    p.noalloc = false;
    p.format = fmt;
    p.hooks = global_hooks;

    if (!print_value(item, &p))
    {
        global_hooks.deallocate(p.buffer);
        return NULL;
    }

    return (char*)p.buffer;
}

CJSON_PUBLIC(cJSON_bool) cJSON_PrintPreallocated(cJSON *item, char *buffer, const int length, const cJSON_bool format)
{
    printbuffer p = { 0, 0, 0, 0, 0, 0, { 0, 0, 0 } };

    if ((length < 0) || (buffer == NULL))
    {
        return false;
    }

    p.buffer = (unsigned char*)buffer;
    p.length = (size_t)length;
    p.offset = 0;
    p.noalloc = true;
    p.format = format;
    p.hooks = global_hooks;

    return print_value(item, &p);
}


static cJSON_bool parse_value(cJSON * const item, parse_buffer * const input_buffer)
{
    if ((input_buffer == NULL) || (input_buffer->content == NULL))
    {
        return false; 
    }

    
    
    if (can_read(input_buffer, 4) && (strncmp((const char*)buffer_at_offset(input_buffer), "null", 4) == 0))
    {
        item->type = cJSON_NULL;
        input_buffer->offset += 4;
        return true;
    }
    
    if (can_read(input_buffer, 5) && (strncmp((const char*)buffer_at_offset(input_buffer), "false", 5) == 0))
    {
        item->type = cJSON_False;
        input_buffer->offset += 5;
        return true;
    }
    
    if (can_read(input_buffer, 4) && (strncmp((const char*)buffer_at_offset(input_buffer), "true", 4) == 0))
    {
        item->type = cJSON_True;
        item->valueint = 1;
        input_buffer->offset += 4;
        return true;
    }
    
    if (can_access_at_index(input_buffer, 0) && (buffer_at_offset(input_buffer)[0] == '\"'))
    {
        return parse_string(item, input_buffer);
    }
    
    if (can_access_at_index(input_buffer, 0) && ((buffer_at_offset(input_buffer)[0] == '-') || ((buffer_at_offset(input_buffer)[0] >= '0') && (buffer_at_offset(input_buffer)[0] <= '9'))))
    {
        return parse_number(item, input_buffer);
    }
    
    if (can_access_at_index(input_buffer, 0) && (buffer_at_offset(input_buffer)[0] == '['))
    {
        return parse_array(item, input_buffer);
    }
    
    if (can_access_at_index(input_buffer, 0) && (buffer_at_offset(input_buffer)[0] == '{'))
    {
        return parse_object(item, input_buffer);
    }

    return false;
}


static cJSON_bool print_value(const cJSON * const item, printbuffer * const output_buffer)
{
    unsigned char *output = NULL;

    if ((item == NULL) || (output_buffer == NULL))
    {
        return false;
    }

    switch ((item->type) & 0xFF)
    {
        case cJSON_NULL:
            output = ensure(output_buffer, 5);
            if (output == NULL)
            {
                return false;
            }
            strcpy((char*)output, "null");
            return true;

        case cJSON_False:
            output = ensure(output_buffer, 6);
            if (output == NULL)
            {
                return false;
            }
            strcpy((char*)output, "false");
            return true;

        case cJSON_True:
            output = ensure(output_buffer, 5);
            if (output == NULL)
            {
                return false;
            }
            strcpy((char*)output, "true");
            return true;

        case cJSON_Number:
            return print_number(item, output_buffer);

        case cJSON_Raw:
        {
            size_t raw_length = 0;
            if (item->valuestring == NULL)
            {
                return false;
            }

            raw_length = strlen(item->valuestring) + sizeof("");
            output = ensure(output_buffer, raw_length);
            if (output == NULL)
            {
                return false;
            }
            memcpy(output, item->valuestring, raw_length);
            return true;
        }

        case cJSON_String:
            return print_string(item, output_buffer);

        case cJSON_Array:
            return print_array(item, output_buffer);

        case cJSON_Object:
            return print_object(item, output_buffer);

        default:
            return false;
    }
}


static cJSON_bool parse_array(cJSON * const item, parse_buffer * const input_buffer)
{
    cJSON *head = NULL; 
    cJSON *current_item = NULL;

    if (input_buffer->depth >= CJSON_NESTING_LIMIT)
    {
        return false; 
    }
    input_buffer->depth++;

    if (buffer_at_offset(input_buffer)[0] != '[')
    {
        
        goto fail;
    }

    input_buffer->offset++;
    buffer_skip_whitespace(input_buffer);
    if (can_access_at_index(input_buffer, 0) && (buffer_at_offset(input_buffer)[0] == ']'))
    {
        
        goto success;
    }

    
    if (cannot_access_at_index(input_buffer, 0))
    {
        input_buffer->offset--;
        goto fail;
    }

    
    input_buffer->offset--;
    
    do
    {
        
        cJSON *new_item = cJSON_New_Item(&(input_buffer->hooks));
        if (new_item == NULL)
        {
            goto fail; 
        }

        
        if (head == NULL)
        {
            
            current_item = head = new_item;
        }
        else
        {
            
            current_item->next = new_item;
            new_item->prev = current_item;
            current_item = new_item;
        }

        
        input_buffer->offset++;
        buffer_skip_whitespace(input_buffer);
        if (!parse_value(current_item, input_buffer))
        {
            goto fail; 
        }
        buffer_skip_whitespace(input_buffer);
    }
    while (can_access_at_index(input_buffer, 0) && (buffer_at_offset(input_buffer)[0] == ','));

    if (cannot_access_at_index(input_buffer, 0) || buffer_at_offset(input_buffer)[0] != ']')
    {
        goto fail; 
    }

success:
    input_buffer->depth--;

    if (head != NULL) {
        head->prev = current_item;
    }

    item->type = cJSON_Array;
    item->child = head;

    input_buffer->offset++;

    return true;

fail:
    if (head != NULL)
    {
        cJSON_Delete(head);
    }

    return false;
}


static cJSON_bool print_array(const cJSON * const item, printbuffer * const output_buffer)
{
    unsigned char *output_pointer = NULL;
    size_t length = 0;
    cJSON *current_element = item->child;

    if (output_buffer == NULL)
    {
        return false;
    }

    
    
    output_pointer = ensure(output_buffer, 1);
    if (output_pointer == NULL)
    {
        return false;
    }

    *output_pointer = '[';
    output_buffer->offset++;
    output_buffer->depth++;

    while (current_element != NULL)
    {
        if (!print_value(current_element, output_buffer))
        {
            return false;
        }
        update_offset(output_buffer);
        if (current_element->next)
        {
            length = (size_t) (output_buffer->format ? 2 : 1);
            output_pointer = ensure(output_buffer, length + 1);
            if (output_pointer == NULL)
            {
                return false;
            }
            *output_pointer++ = ',';
            if(output_buffer->format)
            {
                *output_pointer++ = ' ';
            }
            *output_pointer = '\0';
            output_buffer->offset += length;
        }
        current_element = current_element->next;
    }

    output_pointer = ensure(output_buffer, 2);
    if (output_pointer == NULL)
    {
        return false;
    }
    *output_pointer++ = ']';
    *output_pointer = '\0';
    output_buffer->depth--;

    return true;
}


static cJSON_bool parse_object(cJSON * const item, parse_buffer * const input_buffer)
{
    cJSON *head = NULL; 
    cJSON *current_item = NULL;

    if (input_buffer->depth >= CJSON_NESTING_LIMIT)
    {
        return false; 
    }
    input_buffer->depth++;

    if (cannot_access_at_index(input_buffer, 0) || (buffer_at_offset(input_buffer)[0] != '{'))
    {
        goto fail; 
    }

    input_buffer->offset++;
    buffer_skip_whitespace(input_buffer);
    if (can_access_at_index(input_buffer, 0) && (buffer_at_offset(input_buffer)[0] == '}'))
    {
        goto success; 
    }

    
    if (cannot_access_at_index(input_buffer, 0))
    {
        input_buffer->offset--;
        goto fail;
    }

    
    input_buffer->offset--;
    
    do
    {
        
        cJSON *new_item = cJSON_New_Item(&(input_buffer->hooks));
        if (new_item == NULL)
        {
            goto fail; 
        }

        
        if (head == NULL)
        {
            
            current_item = head = new_item;
        }
        else
        {
            
            current_item->next = new_item;
            new_item->prev = current_item;
            current_item = new_item;
        }

        
        input_buffer->offset++;
        buffer_skip_whitespace(input_buffer);
        if (!parse_string(current_item, input_buffer))
        {
            goto fail; 
        }
        buffer_skip_whitespace(input_buffer);

        
        current_item->string = current_item->valuestring;
        current_item->valuestring = NULL;

        if (cannot_access_at_index(input_buffer, 0) || (buffer_at_offset(input_buffer)[0] != ':'))
        {
            goto fail; 
        }

        
        input_buffer->offset++;
        buffer_skip_whitespace(input_buffer);
        if (!parse_value(current_item, input_buffer))
        {
            goto fail; 
        }
        buffer_skip_whitespace(input_buffer);
    }
    while (can_access_at_index(input_buffer, 0) && (buffer_at_offset(input_buffer)[0] == ','));

    if (cannot_access_at_index(input_buffer, 0) || (buffer_at_offset(input_buffer)[0] != '}'))
    {
        goto fail; 
    }

success:
    input_buffer->depth--;

    if (head != NULL) {
        head->prev = current_item;
    }

    item->type = cJSON_Object;
    item->child = head;

    input_buffer->offset++;
    return true;

fail:
    if (head != NULL)
    {
        cJSON_Delete(head);
    }

    return false;
}


static cJSON_bool print_object(const cJSON * const item, printbuffer * const output_buffer)
{
    unsigned char *output_pointer = NULL;
    size_t length = 0;
    cJSON *current_item = item->child;

    if (output_buffer == NULL)
    {
        return false;
    }

    
    length = (size_t) (output_buffer->format ? 2 : 1); 
    output_pointer = ensure(output_buffer, length + 1);
    if (output_pointer == NULL)
    {
        return false;
    }

    *output_pointer++ = '{';
    output_buffer->depth++;
    if (output_buffer->format)
    {
        *output_pointer++ = '\n';
    }
    output_buffer->offset += length;

    while (current_item)
    {
        if (output_buffer->format)
        {
            size_t i;
            output_pointer = ensure(output_buffer, output_buffer->depth);
            if (output_pointer == NULL)
            {
                return false;
            }
            for (i = 0; i < output_buffer->depth; i++)
            {
                *output_pointer++ = '\t';
            }
            output_buffer->offset += output_buffer->depth;
        }

        
        if (!print_string_ptr((unsigned char*)current_item->string, output_buffer))
        {
            return false;
        }
        update_offset(output_buffer);

        length = (size_t) (output_buffer->format ? 2 : 1);
        output_pointer = ensure(output_buffer, length);
        if (output_pointer == NULL)
        {
            return false;
        }
        *output_pointer++ = ':';
        if (output_buffer->format)
        {
            *output_pointer++ = '\t';
        }
        output_buffer->offset += length;

        
        if (!print_value(current_item, output_buffer))
        {
            return false;
        }
        update_offset(output_buffer);

        
        length = ((size_t)(output_buffer->format ? 1 : 0) + (size_t)(current_item->next ? 1 : 0));
        output_pointer = ensure(output_buffer, length + 1);
        if (output_pointer == NULL)
        {
            return false;
        }
        if (current_item->next)
        {
            *output_pointer++ = ',';
        }

        if (output_buffer->format)
        {
            *output_pointer++ = '\n';
        }
        *output_pointer = '\0';
        output_buffer->offset += length;

        current_item = current_item->next;
    }

    output_pointer = ensure(output_buffer, output_buffer->format ? (output_buffer->depth + 1) : 2);
    if (output_pointer == NULL)
    {
        return false;
    }
    if (output_buffer->format)
    {
        size_t i;
        for (i = 0; i < (output_buffer->depth - 1); i++)
        {
            *output_pointer++ = '\t';
        }
    }
    *output_pointer++ = '}';
    *output_pointer = '\0';
    output_buffer->depth--;

    return true;
}


CJSON_PUBLIC(int) cJSON_GetArraySize(const cJSON *array)
{
    cJSON *child = NULL;
    size_t size = 0;

    if (array == NULL)
    {
        return 0;
    }

    child = array->child;

    while(child != NULL)
    {
        size++;
        child = child->next;
    }

    

    return (int)size;
}

static cJSON* get_array_item(const cJSON *array, size_t index)
{
    cJSON *current_child = NULL;

    if (array == NULL)
    {
        return NULL;
    }

    current_child = array->child;
    while ((current_child != NULL) && (index > 0))
    {
        index--;
        current_child = current_child->next;
    }

    return current_child;
}

CJSON_PUBLIC(cJSON *) cJSON_GetArrayItem(const cJSON *array, int index)
{
    if (index < 0)
    {
        return NULL;
    }

    return get_array_item(array, (size_t)index);
}

static cJSON *get_object_item(const cJSON * const object, const char * const name, const cJSON_bool case_sensitive)
{
    cJSON *current_element = NULL;

    if ((object == NULL) || (name == NULL))
    {
        return NULL;
    }

    current_element = object->child;
    if (case_sensitive)
    {
        while ((current_element != NULL) && (current_element->string != NULL) && (strcmp(name, current_element->string) != 0))
        {
            current_element = current_element->next;
        }
    }
    else
    {
        while ((current_element != NULL) && (case_insensitive_strcmp((const unsigned char*)name, (const unsigned char*)(current_element->string)) != 0))
        {
            current_element = current_element->next;
        }
    }

    if ((current_element == NULL) || (current_element->string == NULL)) {
        return NULL;
    }

    return current_element;
}

CJSON_PUBLIC(cJSON *) cJSON_GetObjectItem(const cJSON * const object, const char * const string)
{
    return get_object_item(object, string, false);
}

CJSON_PUBLIC(cJSON *) cJSON_GetObjectItemCaseSensitive(const cJSON * const object, const char * const string)
{
    return get_object_item(object, string, true);
}

CJSON_PUBLIC(cJSON_bool) cJSON_HasObjectItem(const cJSON *object, const char *string)
{
    return cJSON_GetObjectItem(object, string) ? 1 : 0;
}


static void suffix_object(cJSON *prev, cJSON *item)
{
    prev->next = item;
    item->prev = prev;
}


static cJSON *create_reference(const cJSON *item, const internal_hooks * const hooks)
{
    cJSON *reference = NULL;
    if (item == NULL)
    {
        return NULL;
    }

    reference = cJSON_New_Item(hooks);
    if (reference == NULL)
    {
        return NULL;
    }

    memcpy(reference, item, sizeof(cJSON));
    reference->string = NULL;
    reference->type |= cJSON_IsReference;
    reference->next = reference->prev = NULL;
    return reference;
}

static cJSON_bool add_item_to_array(cJSON *array, cJSON *item)
{
    cJSON *child = NULL;

    if ((item == NULL) || (array == NULL) || (array == item))
    {
        return false;
    }

    child = array->child;
    
    if (child == NULL)
    {
        
        array->child = item;
        item->prev = item;
        item->next = NULL;
    }
    else
    {
        
        if (child->prev)
        {
            suffix_object(child->prev, item);
            array->child->prev = item;
        }
    }

    return true;
}


CJSON_PUBLIC(cJSON_bool) cJSON_AddItemToArray(cJSON *array, cJSON *item)
{
    return add_item_to_array(array, item);
}

#if defined(__clang__) || (defined(__GNUC__)  && ((__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ > 5))))
    #pragma GCC diagnostic push
#endif
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wcast-qual"
#endif

static void* cast_away_const(const void* string)
{
    return (void*)string;
}
#if defined(__clang__) || (defined(__GNUC__)  && ((__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ > 5))))
    #pragma GCC diagnostic pop
#endif


static cJSON_bool add_item_to_object(cJSON * const object, const char * const string, cJSON * const item, const internal_hooks * const hooks, const cJSON_bool constant_key)
{
    char *new_key = NULL;
    int new_type = cJSON_Invalid;

    if ((object == NULL) || (string == NULL) || (item == NULL) || (object == item))
    {
        return false;
    }

    if (constant_key)
    {
        new_key = (char*)cast_away_const(string);
        new_type = item->type | cJSON_StringIsConst;
    }
    else
    {
        new_key = (char*)cJSON_strdup((const unsigned char*)string, hooks);
        if (new_key == NULL)
        {
            return false;
        }

        new_type = item->type & ~cJSON_StringIsConst;
    }

    if (!(item->type & cJSON_StringIsConst) && (item->string != NULL))
    {
        hooks->deallocate(item->string);
    }

    item->string = new_key;
    item->type = new_type;

    return add_item_to_array(object, item);
}

CJSON_PUBLIC(cJSON_bool) cJSON_AddItemToObject(cJSON *object, const char *string, cJSON *item)
{
    return add_item_to_object(object, string, item, &global_hooks, false);
}


CJSON_PUBLIC(cJSON_bool) cJSON_AddItemToObjectCS(cJSON *object, const char *string, cJSON *item)
{
    return add_item_to_object(object, string, item, &global_hooks, true);
}

CJSON_PUBLIC(cJSON_bool) cJSON_AddItemReferenceToArray(cJSON *array, cJSON *item)
{
    if (array == NULL)
    {
        return false;
    }

    return add_item_to_array(array, create_reference(item, &global_hooks));
}

CJSON_PUBLIC(cJSON_bool) cJSON_AddItemReferenceToObject(cJSON *object, const char *string, cJSON *item)
{
    if ((object == NULL) || (string == NULL))
    {
        return false;
    }

    return add_item_to_object(object, string, create_reference(item, &global_hooks), &global_hooks, false);
}

CJSON_PUBLIC(cJSON*) cJSON_AddNullToObject(cJSON * const object, const char * const name)
{
    cJSON *null = cJSON_CreateNull();
    if (add_item_to_object(object, name, null, &global_hooks, false))
    {
        return null;
    }

    cJSON_Delete(null);
    return NULL;
}

CJSON_PUBLIC(cJSON*) cJSON_AddTrueToObject(cJSON * const object, const char * const name)
{
    cJSON *true_item = cJSON_CreateTrue();
    if (add_item_to_object(object, name, true_item, &global_hooks, false))
    {
        return true_item;
    }

    cJSON_Delete(true_item);
    return NULL;
}

CJSON_PUBLIC(cJSON*) cJSON_AddFalseToObject(cJSON * const object, const char * const name)
{
    cJSON *false_item = cJSON_CreateFalse();
    if (add_item_to_object(object, name, false_item, &global_hooks, false))
    {
        return false_item;
    }

    cJSON_Delete(false_item);
    return NULL;
}

CJSON_PUBLIC(cJSON*) cJSON_AddBoolToObject(cJSON * const object, const char * const name, const cJSON_bool boolean)
{
    cJSON *bool_item = cJSON_CreateBool(boolean);
    if (add_item_to_object(object, name, bool_item, &global_hooks, false))
    {
        return bool_item;
    }

    cJSON_Delete(bool_item);
    return NULL;
}

CJSON_PUBLIC(cJSON*) cJSON_AddNumberToObject(cJSON * const object, const char * const name, const double number)
{
    cJSON *number_item = cJSON_CreateNumber(number);
    if (add_item_to_object(object, name, number_item, &global_hooks, false))
    {
        return number_item;
    }

    cJSON_Delete(number_item);
    return NULL;
}

CJSON_PUBLIC(cJSON*) cJSON_AddStringToObject(cJSON * const object, const char * const name, const char * const string)
{
    cJSON *string_item = cJSON_CreateString(string);
    if (add_item_to_object(object, name, string_item, &global_hooks, false))
    {
        return string_item;
    }

    cJSON_Delete(string_item);
    return NULL;
}

CJSON_PUBLIC(cJSON*) cJSON_AddRawToObject(cJSON * const object, const char * const name, const char * const raw)
{
    cJSON *raw_item = cJSON_CreateRaw(raw);
    if (add_item_to_object(object, name, raw_item, &global_hooks, false))
    {
        return raw_item;
    }

    cJSON_Delete(raw_item);
    return NULL;
}

CJSON_PUBLIC(cJSON*) cJSON_AddObjectToObject(cJSON * const object, const char * const name)
{
    cJSON *object_item = cJSON_CreateObject();
    if (add_item_to_object(object, name, object_item, &global_hooks, false))
    {
        return object_item;
    }

    cJSON_Delete(object_item);
    return NULL;
}

CJSON_PUBLIC(cJSON*) cJSON_AddArrayToObject(cJSON * const object, const char * const name)
{
    cJSON *array = cJSON_CreateArray();
    if (add_item_to_object(object, name, array, &global_hooks, false))
    {
        return array;
    }

    cJSON_Delete(array);
    return NULL;
}

CJSON_PUBLIC(cJSON *) cJSON_DetachItemViaPointer(cJSON *parent, cJSON * const item)
{
    if ((parent == NULL) || (item == NULL))
    {
        return NULL;
    }

    if (item != parent->child)
    {
        
        item->prev->next = item->next;
    }
    if (item->next != NULL)
    {
        
        item->next->prev = item->prev;
    }

    if (item == parent->child)
    {
        
        parent->child = item->next;
    }
    else if (item->next == NULL)
    {
        
        parent->child->prev = item->prev;
    }

    
    item->prev = NULL;
    item->next = NULL;

    return item;
}

CJSON_PUBLIC(cJSON *) cJSON_DetachItemFromArray(cJSON *array, int which)
{
    if (which < 0)
    {
        return NULL;
    }

    return cJSON_DetachItemViaPointer(array, get_array_item(array, (size_t)which));
}

CJSON_PUBLIC(void) cJSON_DeleteItemFromArray(cJSON *array, int which)
{
    cJSON_Delete(cJSON_DetachItemFromArray(array, which));
}

CJSON_PUBLIC(cJSON *) cJSON_DetachItemFromObject(cJSON *object, const char *string)
{
    cJSON *to_detach = cJSON_GetObjectItem(object, string);

    return cJSON_DetachItemViaPointer(object, to_detach);
}

CJSON_PUBLIC(cJSON *) cJSON_DetachItemFromObjectCaseSensitive(cJSON *object, const char *string)
{
    cJSON *to_detach = cJSON_GetObjectItemCaseSensitive(object, string);

    return cJSON_DetachItemViaPointer(object, to_detach);
}

CJSON_PUBLIC(void) cJSON_DeleteItemFromObject(cJSON *object, const char *string)
{
    cJSON_Delete(cJSON_DetachItemFromObject(object, string));
}

CJSON_PUBLIC(void) cJSON_DeleteItemFromObjectCaseSensitive(cJSON *object, const char *string)
{
    cJSON_Delete(cJSON_DetachItemFromObjectCaseSensitive(object, string));
}


CJSON_PUBLIC(cJSON_bool) cJSON_InsertItemInArray(cJSON *array, int which, cJSON *newitem)
{
    cJSON *after_inserted = NULL;

    if (which < 0)
    {
        return false;
    }

    after_inserted = get_array_item(array, (size_t)which);
    if (after_inserted == NULL)
    {
        return add_item_to_array(array, newitem);
    }

    newitem->next = after_inserted;
    newitem->prev = after_inserted->prev;
    after_inserted->prev = newitem;
    if (after_inserted == array->child)
    {
        array->child = newitem;
    }
    else
    {
        newitem->prev->next = newitem;
    }
    return true;
}

CJSON_PUBLIC(cJSON_bool) cJSON_ReplaceItemViaPointer(cJSON * const parent, cJSON * const item, cJSON * replacement)
{
    if ((parent == NULL) || (replacement == NULL) || (item == NULL))
    {
        return false;
    }

    if (replacement == item)
    {
        return true;
    }

    replacement->next = item->next;
    replacement->prev = item->prev;

    if (replacement->next != NULL)
    {
        replacement->next->prev = replacement;
    }
    if (parent->child == item)
    {
        if (parent->child->prev == parent->child)
        {
            replacement->prev = replacement;
        }
        parent->child = replacement;
    }
    else
    {   
        if (replacement->prev != NULL)
        {
            replacement->prev->next = replacement;
        }
        if (replacement->next == NULL)
        {
            parent->child->prev = replacement;
        }
    }

    item->next = NULL;
    item->prev = NULL;
    cJSON_Delete(item);

    return true;
}

CJSON_PUBLIC(cJSON_bool) cJSON_ReplaceItemInArray(cJSON *array, int which, cJSON *newitem)
{
    if (which < 0)
    {
        return false;
    }

    return cJSON_ReplaceItemViaPointer(array, get_array_item(array, (size_t)which), newitem);
}

static cJSON_bool replace_item_in_object(cJSON *object, const char *string, cJSON *replacement, cJSON_bool case_sensitive)
{
    if ((replacement == NULL) || (string == NULL))
    {
        return false;
    }

    
    if (!(replacement->type & cJSON_StringIsConst) && (replacement->string != NULL))
    {
        cJSON_free(replacement->string);
    }
    replacement->string = (char*)cJSON_strdup((const unsigned char*)string, &global_hooks);
    if (replacement->string == NULL)
    {
        return false;
    }

    replacement->type &= ~cJSON_StringIsConst;

    return cJSON_ReplaceItemViaPointer(object, get_object_item(object, string, case_sensitive), replacement);
}

CJSON_PUBLIC(cJSON_bool) cJSON_ReplaceItemInObject(cJSON *object, const char *string, cJSON *newitem)
{
    return replace_item_in_object(object, string, newitem, false);
}

CJSON_PUBLIC(cJSON_bool) cJSON_ReplaceItemInObjectCaseSensitive(cJSON *object, const char *string, cJSON *newitem)
{
    return replace_item_in_object(object, string, newitem, true);
}


CJSON_PUBLIC(cJSON *) cJSON_CreateNull(void)
{
    cJSON *item = cJSON_New_Item(&global_hooks);
    if(item)
    {
        item->type = cJSON_NULL;
    }

    return item;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateTrue(void)
{
    cJSON *item = cJSON_New_Item(&global_hooks);
    if(item)
    {
        item->type = cJSON_True;
    }

    return item;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateFalse(void)
{
    cJSON *item = cJSON_New_Item(&global_hooks);
    if(item)
    {
        item->type = cJSON_False;
    }

    return item;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateBool(cJSON_bool boolean)
{
    cJSON *item = cJSON_New_Item(&global_hooks);
    if(item)
    {
        item->type = boolean ? cJSON_True : cJSON_False;
    }

    return item;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateNumber(double num)
{
    cJSON *item = cJSON_New_Item(&global_hooks);
    if(item)
    {
        item->type = cJSON_Number;
        item->valuedouble = num;

        
        if (num >= INT_MAX)
        {
            item->valueint = INT_MAX;
        }
        else if (num <= (double)INT_MIN)
        {
            item->valueint = INT_MIN;
        }
        else
        {
            item->valueint = (int)num;
        }
    }

    return item;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateString(const char *string)
{
    cJSON *item = cJSON_New_Item(&global_hooks);
    if(item)
    {
        item->type = cJSON_String;
        item->valuestring = (char*)cJSON_strdup((const unsigned char*)string, &global_hooks);
        if(!item->valuestring)
        {
            cJSON_Delete(item);
            return NULL;
        }
    }

    return item;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateStringReference(const char *string)
{
    cJSON *item = cJSON_New_Item(&global_hooks);
    if (item != NULL)
    {
        item->type = cJSON_String | cJSON_IsReference;
        item->valuestring = (char*)cast_away_const(string);
    }

    return item;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateObjectReference(const cJSON *child)
{
    cJSON *item = cJSON_New_Item(&global_hooks);
    if (item != NULL) {
        item->type = cJSON_Object | cJSON_IsReference;
        item->child = (cJSON*)cast_away_const(child);
    }

    return item;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateArrayReference(const cJSON *child) {
    cJSON *item = cJSON_New_Item(&global_hooks);
    if (item != NULL) {
        item->type = cJSON_Array | cJSON_IsReference;
        item->child = (cJSON*)cast_away_const(child);
    }

    return item;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateRaw(const char *raw)
{
    cJSON *item = cJSON_New_Item(&global_hooks);
    if(item)
    {
        item->type = cJSON_Raw;
        item->valuestring = (char*)cJSON_strdup((const unsigned char*)raw, &global_hooks);
        if(!item->valuestring)
        {
            cJSON_Delete(item);
            return NULL;
        }
    }

    return item;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateArray(void)
{
    cJSON *item = cJSON_New_Item(&global_hooks);
    if(item)
    {
        item->type=cJSON_Array;
    }

    return item;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateObject(void)
{
    cJSON *item = cJSON_New_Item(&global_hooks);
    if (item)
    {
        item->type = cJSON_Object;
    }

    return item;
}


CJSON_PUBLIC(cJSON *) cJSON_CreateIntArray(const int *numbers, int count)
{
    size_t i = 0;
    cJSON *n = NULL;
    cJSON *p = NULL;
    cJSON *a = NULL;

    if ((count < 0) || (numbers == NULL))
    {
        return NULL;
    }

    a = cJSON_CreateArray();

    for(i = 0; a && (i < (size_t)count); i++)
    {
        n = cJSON_CreateNumber(numbers[i]);
        if (!n)
        {
            cJSON_Delete(a);
            return NULL;
        }
        if(!i)
        {
            a->child = n;
        }
        else
        {
            suffix_object(p, n);
        }
        p = n;
    }

    if (a && a->child) {
        a->child->prev = n;
    }

    return a;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateFloatArray(const float *numbers, int count)
{
    size_t i = 0;
    cJSON *n = NULL;
    cJSON *p = NULL;
    cJSON *a = NULL;

    if ((count < 0) || (numbers == NULL))
    {
        return NULL;
    }

    a = cJSON_CreateArray();

    for(i = 0; a && (i < (size_t)count); i++)
    {
        n = cJSON_CreateNumber((double)numbers[i]);
        if(!n)
        {
            cJSON_Delete(a);
            return NULL;
        }
        if(!i)
        {
            a->child = n;
        }
        else
        {
            suffix_object(p, n);
        }
        p = n;
    }

    if (a && a->child) {
        a->child->prev = n;
    }

    return a;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateDoubleArray(const double *numbers, int count)
{
    size_t i = 0;
    cJSON *n = NULL;
    cJSON *p = NULL;
    cJSON *a = NULL;

    if ((count < 0) || (numbers == NULL))
    {
        return NULL;
    }

    a = cJSON_CreateArray();

    for(i = 0; a && (i < (size_t)count); i++)
    {
        n = cJSON_CreateNumber(numbers[i]);
        if(!n)
        {
            cJSON_Delete(a);
            return NULL;
        }
        if(!i)
        {
            a->child = n;
        }
        else
        {
            suffix_object(p, n);
        }
        p = n;
    }

    if (a && a->child) {
        a->child->prev = n;
    }

    return a;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateStringArray(const char *const *strings, int count)
{
    size_t i = 0;
    cJSON *n = NULL;
    cJSON *p = NULL;
    cJSON *a = NULL;

    if ((count < 0) || (strings == NULL))
    {
        return NULL;
    }

    a = cJSON_CreateArray();

    for (i = 0; a && (i < (size_t)count); i++)
    {
        n = cJSON_CreateString(strings[i]);
        if(!n)
        {
            cJSON_Delete(a);
            return NULL;
        }
        if(!i)
        {
            a->child = n;
        }
        else
        {
            suffix_object(p,n);
        }
        p = n;
    }

    if (a && a->child) {
        a->child->prev = n;
    }

    return a;
}


CJSON_PUBLIC(cJSON *) cJSON_Duplicate(const cJSON *item, cJSON_bool recurse)
{
    cJSON *newitem = NULL;
    cJSON *child = NULL;
    cJSON *next = NULL;
    cJSON *newchild = NULL;

    
    if (!item)
    {
        goto fail;
    }
    
    newitem = cJSON_New_Item(&global_hooks);
    if (!newitem)
    {
        goto fail;
    }
    
    newitem->type = item->type & (~cJSON_IsReference);
    newitem->valueint = item->valueint;
    newitem->valuedouble = item->valuedouble;
    if (item->valuestring)
    {
        newitem->valuestring = (char*)cJSON_strdup((unsigned char*)item->valuestring, &global_hooks);
        if (!newitem->valuestring)
        {
            goto fail;
        }
    }
    if (item->string)
    {
        newitem->string = (item->type&cJSON_StringIsConst) ? item->string : (char*)cJSON_strdup((unsigned char*)item->string, &global_hooks);
        if (!newitem->string)
        {
            goto fail;
        }
    }
    
    if (!recurse)
    {
        return newitem;
    }
    
    child = item->child;
    while (child != NULL)
    {
        newchild = cJSON_Duplicate(child, true); 
        if (!newchild)
        {
            goto fail;
        }
        if (next != NULL)
        {
            
            next->next = newchild;
            newchild->prev = next;
            next = newchild;
        }
        else
        {
            
            newitem->child = newchild;
            next = newchild;
        }
        child = child->next;
    }
    if (newitem && newitem->child)
    {
        newitem->child->prev = newchild;
    }

    return newitem;

fail:
    if (newitem != NULL)
    {
        cJSON_Delete(newitem);
    }

    return NULL;
}

static void skip_oneline_comment(char **input)
{
    *input += static_strlen("//");

    for (; (*input)[0] != '\0'; ++(*input))
    {
        if ((*input)[0] == '\n') {
            *input += static_strlen("\n");
            return;
        }
    }
}

static void skip_multiline_comment(char **input)
{
    *input += static_strlen("/*");

    for (; (*input)[0] != '\0'; ++(*input))
    {
        if (((*input)[0] == '*') && ((*input)[1] == '/'))
        {
            *input += static_strlen("*/");
            return;
        }
    }
}

static void minify_string(char **input, char **output) {
    (*output)[0] = (*input)[0];
    *input += static_strlen("\"");
    *output += static_strlen("\"");


    for (; (*input)[0] != '\0'; (void)++(*input), ++(*output)) {
        (*output)[0] = (*input)[0];

        if ((*input)[0] == '\"') {
            (*output)[0] = '\"';
            *input += static_strlen("\"");
            *output += static_strlen("\"");
            return;
        } else if (((*input)[0] == '\\') && ((*input)[1] == '\"')) {
            (*output)[1] = (*input)[1];
            *input += static_strlen("\"");
            *output += static_strlen("\"");
        }
    }
}

CJSON_PUBLIC(void) cJSON_Minify(char *json)
{
    char *into = json;

    if (json == NULL)
    {
        return;
    }

    while (json[0] != '\0')
    {
        switch (json[0])
        {
            case ' ':
            case '\t':
            case '\r':
            case '\n':
                json++;
                break;

            case '/':
                if (json[1] == '/')
                {
                    skip_oneline_comment(&json);
                }
                else if (json[1] == '*')
                {
                    skip_multiline_comment(&json);
                } else {
                    json++;
                }
                break;

            case '\"':
                minify_string(&json, (char**)&into);
                break;

            default:
                into[0] = json[0];
                json++;
                into++;
        }
    }

    
    *into = '\0';
}

CJSON_PUBLIC(cJSON_bool) cJSON_IsInvalid(const cJSON * const item)
{
    if (item == NULL)
    {
        return false;
    }

    return (item->type & 0xFF) == cJSON_Invalid;
}

CJSON_PUBLIC(cJSON_bool) cJSON_IsFalse(const cJSON * const item)
{
    if (item == NULL)
    {
        return false;
    }

    return (item->type & 0xFF) == cJSON_False;
}

CJSON_PUBLIC(cJSON_bool) cJSON_IsTrue(const cJSON * const item)
{
    if (item == NULL)
    {
        return false;
    }

    return (item->type & 0xff) == cJSON_True;
}


CJSON_PUBLIC(cJSON_bool) cJSON_IsBool(const cJSON * const item)
{
    if (item == NULL)
    {
        return false;
    }

    return (item->type & (cJSON_True | cJSON_False)) != 0;
}
CJSON_PUBLIC(cJSON_bool) cJSON_IsNull(const cJSON * const item)
{
    if (item == NULL)
    {
        return false;
    }

    return (item->type & 0xFF) == cJSON_NULL;
}

CJSON_PUBLIC(cJSON_bool) cJSON_IsNumber(const cJSON * const item)
{
    if (item == NULL)
    {
        return false;
    }

    return (item->type & 0xFF) == cJSON_Number;
}

CJSON_PUBLIC(cJSON_bool) cJSON_IsString(const cJSON * const item)
{
    if (item == NULL)
    {
        return false;
    }

    return (item->type & 0xFF) == cJSON_String;
}

CJSON_PUBLIC(cJSON_bool) cJSON_IsArray(const cJSON * const item)
{
    if (item == NULL)
    {
        return false;
    }

    return (item->type & 0xFF) == cJSON_Array;
}

CJSON_PUBLIC(cJSON_bool) cJSON_IsObject(const cJSON * const item)
{
    if (item == NULL)
    {
        return false;
    }

    return (item->type & 0xFF) == cJSON_Object;
}

CJSON_PUBLIC(cJSON_bool) cJSON_IsRaw(const cJSON * const item)
{
    if (item == NULL)
    {
        return false;
    }

    return (item->type & 0xFF) == cJSON_Raw;
}

CJSON_PUBLIC(cJSON_bool) cJSON_Compare(const cJSON * const a, const cJSON * const b, const cJSON_bool case_sensitive)
{
    if ((a == NULL) || (b == NULL) || ((a->type & 0xFF) != (b->type & 0xFF)))
    {
        return false;
    }

    
    switch (a->type & 0xFF)
    {
        case cJSON_False:
        case cJSON_True:
        case cJSON_NULL:
        case cJSON_Number:
        case cJSON_String:
        case cJSON_Raw:
        case cJSON_Array:
        case cJSON_Object:
            break;

        default:
            return false;
    }

    
    if (a == b)
    {
        return true;
    }

    switch (a->type & 0xFF)
    {
        
        case cJSON_False:
        case cJSON_True:
        case cJSON_NULL:
            return true;

        case cJSON_Number:
            if (compare_double(a->valuedouble, b->valuedouble))
            {
                return true;
            }
            return false;

        case cJSON_String:
        case cJSON_Raw:
            if ((a->valuestring == NULL) || (b->valuestring == NULL))
            {
                return false;
            }
            if (strcmp(a->valuestring, b->valuestring) == 0)
            {
                return true;
            }

            return false;

        case cJSON_Array:
        {
            cJSON *a_element = a->child;
            cJSON *b_element = b->child;

            for (; (a_element != NULL) && (b_element != NULL);)
            {
                if (!cJSON_Compare(a_element, b_element, case_sensitive))
                {
                    return false;
                }

                a_element = a_element->next;
                b_element = b_element->next;
            }

            
            if (a_element != b_element) {
                return false;
            }

            return true;
        }

        case cJSON_Object:
        {
            cJSON *a_element = NULL;
            cJSON *b_element = NULL;
            cJSON_ArrayForEach(a_element, a)
            {
                
                b_element = get_object_item(b, a_element->string, case_sensitive);
                if (b_element == NULL)
                {
                    return false;
                }

                if (!cJSON_Compare(a_element, b_element, case_sensitive))
                {
                    return false;
                }
            }

            
            cJSON_ArrayForEach(b_element, b)
            {
                a_element = get_object_item(a, b_element->string, case_sensitive);
                if (a_element == NULL)
                {
                    return false;
                }

                if (!cJSON_Compare(b_element, a_element, case_sensitive))
                {
                    return false;
                }
            }

            return true;
        }

        default:
            return false;
    }
}

CJSON_PUBLIC(void *) cJSON_malloc(size_t size)
{
    return global_hooks.allocate(size);
}

CJSON_PUBLIC(void) cJSON_free(void *object)
{
    global_hooks.deallocate(object);
}






#endif


#ifndef UNIVERSAL_GARBAGE_H
#define UNIVERSAL_GARBAGE_H


#endif


//path: src/functions/definitions.c


//path: src/functions/strings/strings.c

//path: src/functions/strings/../uniq.definitions_requirements.h







char *cweb_parse_string_to_lower(const char *old_string){

    int string_size = strlen(old_string);
    char *new_string = (char*)malloc(string_size + 2);
    for(int i = 0; i < string_size; i++){
        new_string[i] = tolower(old_string[i]);
    }
    new_string[string_size] = '\0';
    return new_string;
}


char *cweb_parse_string_to_upper(const char *old_string){

    int string_size = strlen(old_string);
    char *new_string = (char*)malloc(string_size + 2);
    for(int i = 0; i < string_size; i++){
        new_string[i] = toupper(old_string[i]);
    }
    new_string[string_size] = '\0';
    return new_string;
}

char *cweb_normalize_string(const char *old_string,const char *invalid_chars){

    int string_size = strlen(old_string);
    char *lower_string = cweb_parse_string_to_lower(old_string);
    char *new_string = (char*)malloc(string_size + 2);
    int new_string_size = 0;

    for(int i = 0; i < string_size; i++){
        if(strchr(invalid_chars,lower_string[i]) == NULL){
            new_string[new_string_size] = lower_string[i];
            new_string_size++;
        }
    }
    new_string[new_string_size] = '\0';
    free(lower_string);
    return new_string;
}



bool cweb_starts_with(const char *string, const char *prefix){
    if(strncmp(string, prefix, strlen(prefix)) == 0){
        return true;
    }
    return false;
}


char *private_cweb_replace_string_once(const char *target, const char *old_element, const char *new_element) {

    const char *pos = strstr(target, old_element);

    int size_of_old_element = strlen(old_element);
    int size_of_new_element = strlen(new_element);
    // Allocate memory for the new string
    char *result = (char *)malloc(strlen(target) + size_of_new_element - size_of_old_element + 1);

    // Copy the part of the original string before the old substring
    strncpy(result, target, pos - target);

    // Copy the new substring to the result string
    strcpy(result + (pos - target), new_element);

    // Copy the rest of the original string after the old substring
    strcpy(result + (pos - target) + size_of_new_element, pos + size_of_old_element);

    return result;

}


char* cweb_replace_string(const char *target, const char *old_element, const char *new_element) {
    char *result = (char *)malloc(strlen(target) + 1);
    strcpy(result, target);
    char *temp = NULL;
    while (strstr(result, old_element) != NULL) {
        temp = private_cweb_replace_string_once(result, old_element, new_element);
        free(result);
        result = temp;
    }
    return result;
}


//path: src/functions/extras/extras.c






unsigned char *cweb_load_any_content(const char * path,int *size,bool *is_binary){
    FILE *file = fopen(path,"rb");
    if(file == NULL){
        return NULL;
    }
    fseek(file,0,SEEK_END);
    *size = ftell(file);
    fseek(file,0,SEEK_SET);
    unsigned char *content = (unsigned char*)malloc(*size +1);
    fread(content,1,*size,file);

    *is_binary = false;
    for(int i = 0;i < *size;i++){
        if(content[i] == 0){
            *is_binary = true;
            break;
        }
    }
    if(!*is_binary){
        content[*size] = '\0';
    }

    fclose(file);
    return content;
}


char *cweb_load_string_file_content(const char * path){
    FILE *file = fopen(path,"r");
    if(file == NULL){
        return NULL;
    }
    fseek(file,0,SEEK_END);
    int size = ftell(file);
    fseek(file,0,SEEK_SET);
    char *content = (char*)malloc(size +1);
    fread(content,1,size,file);
    content[size] = '\0';
    fclose(file);
    return content;
}


unsigned char *cweb_load_binary_content(const char * path,int *size){
    FILE *file = fopen(path,"rb");
    if(file == NULL){
        return NULL;
    }
    fseek(file,0,SEEK_END);
    *size = ftell(file);
    fseek(file,0,SEEK_SET);
    unsigned char *content = (unsigned char*)malloc(*size);
    fread(content,1,*size,file);
    fclose(file);
    return content;
}






const char *cweb_generate_content_type(const char *file_name){
        int file_name_size = strlen(file_name);

        if(file_name_size < 2){
            return  "text/plain";
        }

        //iterate in negative
        char *extension;
          for(int i = file_name_size -2; i >= 0;  i--){

           //makes extension to point to i

            extension = (char*)&file_name[i+1];
            //if found a dot, break
            if(file_name[i] =='.'){
                break;
            }
        }
        if(!extension){
            return  "text/plain";
        }

        if(strcmp(extension, "html") == 0){
           return "text/html";
        }
        if(strcmp(extension,"mp4") == 0){
            return "video/mp4";
        }
        if(strcmp(extension,"WebM") == 0){
            return "video/webm";
        }
        if(strcmp(extension,"Ogg") == 0){
            return  "video/ogg";
        }
        if(strcmp(extension,"mp3") == 0){
            return  "audio/mpeg";
        }

        if(strcmp(extension,"pdf") == 0){
            return "application/pdf";
        }

        else if(strcmp(extension, "css") == 0){
            return "text/css";
        }

        else if(strcmp(extension, "js") == 0){
            return  "text/javascript";
        }
        else if(strcmp(extension, "png") == 0){
            return "image/png";
        }
        else if(strcmp(extension, "ico") == 0){
            return "image/x-icon";
        }

        else if(strcmp(extension, "jpg") == 0){
            return  "image/jpeg";
        }
        else if(strcmp(extension, "jpeg") == 0){
            return "image/jpeg";
        }
        else{
            return  "text/plain";
        }

}


char *private_cweb_convert_url_encoded_text(const char *text){

    int text_size = strlen(text);
    char *new_text = (char*)malloc(text_size + 1);
    int new_text_size = 0;

    for(int i = 0; i < text_size; i++){
        if(text[i] == '%'){
            char hex[3];
            hex[0] = text[i+1];
            hex[1] = text[i+2];
            hex[2] = '\0';
            new_text[new_text_size] = (char)strtol(hex, NULL, 16);
            new_text_size++;
            i += 2;
        }
        else{
            new_text[new_text_size] = text[i];
            new_text_size++;
        }
    }
    new_text[new_text_size] = '\0';
    return new_text;
}


 char * private_CWeb_format_vaarg(const char *expresion, va_list args){

     va_list args_copy;
     va_copy(args_copy, args);
     long required_size = vsnprintf(NULL, 0,expresion,args_copy);
     va_end(args_copy);
     char *buffer = (char*)malloc(sizeof(char) * required_size + 2);
     vsnprintf(buffer,sizeof (char) * required_size+1,expresion,args);
     return buffer;
 }

 char * private_CWeb_format(const char *expresion, ...){
     va_list  args;
     va_start(args,expresion);
     char *result = private_CWeb_format_vaarg(expresion,args);
     va_end(args);
     return  result;
 }

 char *private_cweb_convert_to_hexa(const char *data){
     CTextStack *hexa_format = newCTextStack_string_empty();
     int content_size = strlen(data);
     for(int i = 0; i < content_size; i++){
         char buffer[10] = {0};
         sprintf(buffer,"\\x%x",data[i]);
         CTextStack_format(hexa_format,"%s",buffer);
     };
     return CTextStack_self_transform_in_string_and_self_clear(hexa_format);
 }


//path: src/functions/request/definitions.c
//path: src/functions/request/request/request.c
//path: src/functions/request/request/../uniq.definitions_requirements.h






 CwebHttpRequest *newCwebHttpRequest(int socket){
     CwebHttpRequest *self = ( CwebHttpRequest*)malloc(sizeof( CwebHttpRequest));
    *self = (CwebHttpRequest){0};
    self->socket = socket;
    self->params = newCwebDict();
    self->headers = newCwebDict();
    self->garbage = newUniversalGarbage();
    return self;
}



unsigned char * CwebHttpRequest_read_content( CwebHttpRequest *self, long max_content_size) {

    if (self->content != NULL) {
        return self->content;
    }


    if (self->content_length == 0) {
        cweb_print("no content lenght provided\n");
        self->content_error = UNDEFINED_CONTENT;
        return NULL;
    }

    if (self->content_length > max_content_size) {
        cweb_print("content size is too big\n");
        self->content_error = MAX_CONTENT_SIZE;
        return NULL;
    }


    struct timeval timer;
    timer.tv_sec = 5;  // tempo em segundos
    timer.tv_usec = 0;  //

    setsockopt(self->socket, SOL_SOCKET, SO_RCVTIMEO, &timer, sizeof(timer));

    self->content = (unsigned char*) malloc(self->content_length + 2);

    int total_bytes_received = 0;
    int bytes_remaining = self->content_length;

    while (bytes_remaining > 0) {
        int bytes_received = recv(self->socket, self->content + total_bytes_received, bytes_remaining, 0);
        if (bytes_received <= 0) {
            self->content_error =READ_ERROR;
            return NULL;
        }

        total_bytes_received += bytes_received;
        bytes_remaining -= bytes_received;
    }

    self->content[total_bytes_received] = '\0';

    //extracting url encoded data
    char *content_type = CwebHttpRequest_get_header_by_normalized_key(self, "contenttype", "- ");

    if (content_type != NULL) {
        if (strcmp(content_type, "application/x-www-form-urlencoded") == 0) {
            char *decoded = private_cweb_convert_url_encoded_text((char*) self->content);
            private_CwebHttpRequest_interpret_query_params(self, decoded);
            free(decoded);
        }
    }

    return self->content;
}


cJSON * CWebHttpRequest_read_cJSON(CwebHttpRequest *self, long max_content_size){
    unsigned  char *content =CwebHttpRequest_read_content(self,max_content_size);
    if(!content){
        return NULL;
    }

    self->json = cJSON_Parse((char*)self->content);
    if(!self->json){
        self->content_error= INVALID_JSON;
        return NULL;
    }
    return self->json;
}



char * CwebHttpRequest_get_header( CwebHttpRequest *self, const char *key){
    return CwebDict_get(self->headers,key);
}

char * CwebHttpRequest_get_param_by_sanitized_key( CwebHttpRequest *self, const char *key, const char *chars_to_remove){
    return CwebDict_get_by_normalized_key(self->params,key,chars_to_remove);
}

char * CwebHttpRequest_get_param( CwebHttpRequest *self, const char *key){
    return CwebDict_get(self->params,key);
}
char * CwebHttpRequest_get_header_by_normalized_key( CwebHttpRequest *self, const char *key, const char *chars_to_remove){
    return CwebDict_get_by_normalized_key(self->headers,key,chars_to_remove);
}



void CwebHttpRequest_set_route( CwebHttpRequest *self, const char *route){
    self->route = (char*) malloc(strlen(route) +2);
    strcpy(self->route,route);
}

void CwebHttpRequest_add_header( CwebHttpRequest *self, const char *key, const char *value){
    CwebDict_set(self->headers,key,value);
}
void CwebHttpRequest_add_param( CwebHttpRequest *self, const char *key, const char *value){
    CwebDict_set(self->params,key,value);
}

void CwebHttpRequest_set_method( CwebHttpRequest *self, const char *method){
    self->method = (char*) malloc(strlen(method)+2);
    strcpy(self->method,method);
}


void CwebHttpRequest_set_content_string( CwebHttpRequest *self, const char *content){
    self->content_length = strlen(content);
    self->content = (unsigned char*) malloc(strlen(content) +2);
    for(int i =0;i<strlen(content);i++){
        self->content[i] = content[i];
    }
}


void CwebHttpRequest_represent( CwebHttpRequest *self){

    printf("url: %s\n", self->url);
    printf("route: %s\n", self->route);
    printf("method: %s\n", self->method);
    printf("client-ip: %s\n",self->client_ip);
    printf("params:-----------------------------\n");
    CwebDict_represent(self->params);
    printf("headers:----------------------------\n");
    CwebDict_represent(self->headers);
    if(self->content){
        printf("content: %s\n", self->content);
    }

}
CTextStack *CwebHttpRequest_create_empty_stack(CwebHttpRequest *self){
    CTextStack *created = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    UniversalGarbage_add(self->garbage, CTextStack_free, created);
    return created;
}

CTextStack *CwebHttpRequest_create_stack(CwebHttpRequest *self){
    CTextStack *created = newCTextStack_string_empty();
    UniversalGarbage_add(self->garbage, CTextStack_free, created);
    return created;
}


void CwebHttpRequest_free( CwebHttpRequest *self){



    if(self->url){
        free(self->url);
    }
    if(self->route){
        free(self->route);
    }
    if(self->content){
        free(self->content);
    }
    if(self->client_ip){
        free(self->client_ip);
    }
    if(self->json){
        cJSON_Delete(self->json);
    }

    if(self->method){
        free(self->method);
    }

    if(self->hydratation){
        private_CWebHyDration_free((CWebHyDration *)self->hydratation);
    }
    UniversalGarbage_free(self->garbage);

    CwebDict_free(self->params);

    CwebDict_free(self->headers);
    free(self);

}


//path: src/functions/request/request_parser/request_parser.c





void private_CwebHttpRequest_interpret_query_params(struct CwebHttpRequest *self, const char *query_params){
    if(!query_params){
        return;
    }
    int paramns_size = strlen(query_params);
    char key[5000] = {0};
    char value[5000] = {0};
    bool key_found = false;

    for(int i =0; i<paramns_size; i++){



        if(query_params[i] == '='&& key_found == false){
            key_found = true;
            continue;
        }

        if(query_params[i] == '&'){
            key_found = false;
            char *sanitized_key = private_cweb_convert_url_encoded_text(key);
            char *sanitized_value = private_cweb_convert_url_encoded_text(value);

            CwebDict_set(self->params, sanitized_key, sanitized_value);
            free(sanitized_key);
            free(sanitized_value);

            memset(key, 0, 5000);
            memset(value, 0, 5000);
            continue;
        }

        if(key_found){
            value[strlen(value)] = query_params[i];
        }

        else{
            key[strlen(key)] = query_params[i];
        }
    }
    if(key_found){

        char *sanitized_key = private_cweb_convert_url_encoded_text(key);
        char *sanitized_value = private_cweb_convert_url_encoded_text(value);
        CwebDict_set(self->params, sanitized_key, sanitized_value);
        free(sanitized_key);
        free(sanitized_value);

    }

}

void CwebHttpRequest_set_url(struct CwebHttpRequest *self, const char *url){
    int size_url = strlen(url);
    self->url = (char*) malloc(size_url+2);
    strcpy(self->url,url);

    char route[5000] = {0};
    char params[5000] = {0};

    bool route_end = false;
    int route_end_position =0;
    int i = 0;
    for(;i < size_url;i++){
        char current_char = url[i];

        if(current_char == '?'){
            route_end = true;
            route_end_position = i+1;
            route[i] = '\0';
            continue;
        }

        if(route_end == false){
            route[i] = current_char;
        }
        if(route_end == true){
            params[i-route_end_position] = current_char;
        }
    }


    self->route = (char*)malloc(strlen(route)+1);
    strcpy(self->route, route);

    if(route_end_position){
        params[i-route_end_position] = '\0';
        private_CwebHttpRequest_interpret_query_params(self, params);
    }


}

int private_CwebHttpRequest_interpret_first_line(struct CwebHttpRequest *self, char *first_line){

    #define CWEB_METHOD_MAX_SIZE 300
    #define CWEB_URL_MAX_SIZE 5000
    char method[CWEB_METHOD_MAX_SIZE] = {0};
    char url[CWEB_URL_MAX_SIZE] = {0};


    int line_len = strlen(first_line);
    int method_end = 0;
    //getting the method

    for (int i = 0; i < line_len; i++){

        if(i >= CWEB_METHOD_MAX_SIZE){
            return INVALID_HTTP;
        }

        char current_char = first_line[i];
        if(current_char == ' '){
            method_end = i;
            method[i] = '\0';
            break;
        }
        method[i] = current_char;

    }

    if(!method_end){
        return INVALID_HTTP;
    }

    CwebHttpRequest_set_method(self,method);


    //getting the url
    int url_start_position = 0;
    bool url_found = false;

    for (int i = method_end; i < line_len; i++){


        if((i - url_start_position) >= CWEB_URL_MAX_SIZE){
            return INVALID_HTTP;
        }

        char current_char = first_line[i];

        if(current_char == ' ' && url_found == true){
            break;
        }

        if(current_char != ' ' && url_found == false){
           url_found = true;
           url_start_position = i;
        }


        if(url_found){
            url[i - url_start_position] = current_char;
        }

    }

    if(!url_found){
        return INVALID_HTTP;
    }
    CwebHttpRequest_set_url(self,url);

    return 0;

}


int private_CwebHttpRequest_interpret_headders(struct CwebHttpRequest *self, struct CwebStringArray *line_headers){

    for(int i = 1;i< line_headers->size;i++){
        char *current_line = line_headers->strings[i];
        int line_size = strlen(current_line);
        char key[1100] = {0};
        char value[11000] = {0};
        bool key_found = false;
        int value_start_point = 0;

        for(int j = 0; j<line_size;j++){

            if(key_found == false && j >= 1000){
                return MAX_HEADER_SIZE_CODE;
            }


            if(key_found == true && j > 10000){
                return MAX_HEADER_SIZE_CODE;
            }



            if(current_line[j] == ':' && key_found == false){

                key_found = true;
                j+=1;
                value_start_point = j;
                continue;

            }


            if(key_found == false){
                key[j] = current_line[j];
            }


            if(key_found == true){
                int size_point = j - value_start_point -1;
               value[size_point] = current_line[j];
            }

        }

        if(key_found){
            CwebHttpRequest_add_header(self, key, value);
        }
        else{
            return INVALID_HTTP;
        }
    }
    return 0;

}
bool privateCwebHttpRequest_is_correct_encoded(const char *bytes_sec,int size){

    for(int i = 1; i < size; i++){
        char current_char = bytes_sec[i];
        char last_char = bytes_sec[i-1];

        if(current_char < 0 && current_char != CWEB_C_NON_ASSCI_SIGIN  && last_char != CWEB_C_NON_ASSCI_SIGIN ){
            return  false;
        }
    }
    return  true;
}


int  CwebHttpRequest_parse_http_request(struct CwebHttpRequest *self){
        //splite lines by "\r\n"


    char raw_entries[MAX_HEADER_LEN] ={0};

    int i = 0;
    while (true) {

        if (i >= MAX_HEADER_LEN) {
            return MAX_HEADER_SIZE_CODE;
        }

        ssize_t res = recv(self->socket, &raw_entries[i], 1, MSG_WAITALL);
        //ssize_t res = read(self->socket, &raw_entries[i],1);
        //printf("v:%d|char:%c\n",raw_entries[i],raw_entries[i]);

        if (res <= 0) {
            return READ_ERROR;
        }
        //line break is \r\n\r\n
        if (i >= 3 &&
            raw_entries[i - 3] == '\r' &&
            raw_entries[i - 2] == '\n' &&
            raw_entries[i - 1] == '\r' &&
                raw_entries[i] == '\n'
           ){

            break;
        }
        i++;

    }
    if(i <= 4){return READ_ERROR;}


    bool its_utf_formated = privateCwebHttpRequest_is_correct_encoded(raw_entries,i);


    char last_string[MAX_LINE_LEN]= {0};
    struct CwebStringArray *lines = newCwebStringArray();
    int line_index = 0;

    for(int l =0 ; l < i-1;l++){

        if(line_index >= MAX_LINE_LEN){
            CwebStringArray_free(lines);
            return MAX_HEADER_SIZE_CODE;
        }

        if(raw_entries[l] == '\r' && raw_entries[l+1] == '\n'){
            CwebStringArray_add(lines, last_string);
            memset(last_string, 0, 10000);
            line_index = 0;
            l++;
            continue;
        }
        #ifndef CWEB_NOT_MANIPULATE_UTF

                if(!its_utf_formated && l > 0){
                    if(raw_entries[l] < 0){
                        last_string[line_index] = CWEB_C_NON_ASSCI_SIGIN;
                        last_string[line_index+1] = raw_entries[l] - CWEB_UTF_DECREMENTER;
                        line_index+=2;
                        continue;
                    }
                }
        #endif

        last_string[line_index] = raw_entries[l];
        line_index++;

    }

    if(lines->size == 0){
        CwebStringArray_free(lines);
        return READ_ERROR;
    }



    int line_error = private_CwebHttpRequest_interpret_first_line(self, lines->strings[0]);

    if(line_error){

        CwebStringArray_free(lines);
        return line_error;
    }

    int headers_error = private_CwebHttpRequest_interpret_headders(self, lines);
    CwebStringArray_free(lines);


    if(headers_error){
        return headers_error;
    }
    //const char *content_lenght_str = self->get_header(self, "Content-Length");
    const char *content_lenght_str = CwebHttpRequest_get_header_by_normalized_key(
            self, "contentlength", "- "
    );

    if(content_lenght_str != NULL){

            for(int i = 0; i<strlen(content_lenght_str);i++){
            if(content_lenght_str[i] < '0' || content_lenght_str[i] > '9'){
                return INVALID_HTTP;
            }
        }

        self->content_length = atoi(content_lenght_str);

    }

    return 0;
}




//path: src/functions/string_array/string_array.c


#include <string.h>

struct CwebStringArray * newCwebStringArray(){
    struct CwebStringArray *self = (struct CwebStringArray*)malloc(sizeof(struct CwebStringArray));
    self->size = 0;

    self->strings = (char**)malloc(1);

    return self;
}

int CwebStringArray_find(struct CwebStringArray *self, const char *string){
    for(int i = 0; i < self->size; i++){
        if(strcmp(self->strings[i], string) == 0){
            return i;
        }
    }
    return -1;
}
void CwebStringArray_set(struct CwebStringArray *self, int index, const char *value){
    if(index < self->size && index >= 0){
        int size = strlen(value);
        self->strings[index] = (char*)realloc(self->strings[index], size + 1);
        self->strings[index][size] = '\0';
        strcpy(self->strings[index], value);
    }
}
void CwebStringArray_add(struct CwebStringArray *self, const char *string){
    self->strings =  (char**)realloc(self->strings, (self->size +1) * sizeof(char *));
    self->strings[self->size] = strdup(string);
    self->size+=1;
}

void CwebStringArray_add_getting_ownership(struct CwebStringArray *self,  char *string){
    self->strings =  (char**)realloc(self->strings, (self->size +1) * sizeof(char *));
    self->strings[self->size] = string;
    self->size+=1;
}


void CwebStringArray_merge(struct CwebStringArray *self, struct CwebStringArray *other){
    for(int i = 0; i < other->size; i++){
        CwebStringArray_add(self, other->strings[i]);
    }
}


void CwebStringArray_represent(struct CwebStringArray *self){
    for(int i = 0; i < self->size; i++){
        printf("%s\n", self->strings[i]);
    }
}
void CwebStringArray_free(struct CwebStringArray *self){
    for(int i = 0; i < self->size; i++){
        free(self->strings[i]);
    }
    free(self->strings);
    free(self);
}


//path: src/functions/dict/definition.h
//path: src/functions/dict/keyval/key_val.c




 CwebKeyVal* newCwebKeyVal(const char *key, const  char *value){
     CwebKeyVal *self = (struct CwebKeyVal*)malloc(sizeof(struct CwebKeyVal));
    self->key = (char*)malloc(strlen(key)+1);
    strcpy(self->key,key);
    self->value = (char*)malloc(strlen(value)+1);
    strcpy(self->value,value);
    return self;
}

void CwebKeyVal_represent( CwebKeyVal *self){
    printf("%s : %s\n",self->key,self->value);
}

void CwebKeyVal_free( CwebKeyVal *self){
    free(self->key);
    free(self->value);
    free(self);
}


//path: src/functions/dict/dict/dict.c





CwebDict *newCwebDict(){
    CwebDict *self = (CwebDict *)malloc(sizeof(struct CwebDict));
    self->keys_vals = (CwebKeyVal**)malloc(1);
    self->size = 0;
    return self;
}

char *CwebDict_get_by_normalized_key(CwebDict *self, const char *key, const char *chars_to_remove){

    for(int i = 0;i < self->size;i++){
        char *current_key = self->keys_vals[i]->key;
        char *normalized_key = cweb_normalize_string(current_key, chars_to_remove);

        if(strcmp(normalized_key, key) == 0){
            free(normalized_key);
            return self->keys_vals[i]->value;
        }

        free(normalized_key);

    }
    return NULL;

}
void CwebDict_set(CwebDict *self, const char *key, const char *value){
    CwebKeyVal *key_val = newCwebKeyVal(key, value);
    self->keys_vals = (CwebKeyVal**)realloc(self->keys_vals, (self->size+1)*sizeof(CwebKeyVal*));
    self->keys_vals[self->size] = key_val;
    self->size++;
}

char * CwebDict_get(CwebDict *self, const  char *key){
    for(int i = 0; i < self->size; i++){
        if(strcmp(self->keys_vals[i]->key, key) == 0){
            return self->keys_vals[i]->value;
        }
    }
    return NULL;
}

void CwebDict_represent(CwebDict *dict){
    for(int i = 0; i < dict->size; i++){
        CwebKeyVal_represent(dict->keys_vals[i]);
    }
}

void CwebDict_free(CwebDict *self){
    
    for(int i = 0; i < self->size; i++){
        CwebKeyVal *key_val = self->keys_vals[i];
         CwebKeyVal_free(key_val);
    }
    free(self->keys_vals);
    free(self);
}



//path: src/functions/response/definition.h
//path: src/functions/response/response/response.c



CwebHttpResponse *newCwebHttpResponse(){
     CwebHttpResponse *self = ( CwebHttpResponse *)malloc(
        sizeof(CwebHttpResponse)
    );
    self->status_code = 200;
    self->headers = newCwebDict();
    self->content_length = 0;
    self->exist_content = false;
    self->content = NULL;
    //self->add_header(self, "connection", "close");

    return self;
}

char *CwebHttpResponse_generate_response(struct CwebHttpResponse*self){

    char *response_string = (char*)malloc(20000);
    sprintf(response_string, "HTTP/1.1 %d OK\r\n", self->status_code);
    CwebDict *headers = self->headers;
    char content_length_str[1000] = {0};
    sprintf(content_length_str, "Content-Length: %d\r\n",self->content_length);
    strcat(response_string, content_length_str);

    for(int i = 0; i < headers->size; i++){
        CwebKeyVal *key_val = headers->keys_vals[i];
        char *key = key_val->key;
        char *value = key_val->value;
        char header[1000] = {0};
        sprintf(header, "%s: %s\r\n", key, value);
        strcat(response_string, header);
    }
    if(self->headers->size == 0){
        strcat(response_string, "\r\n");
    }
    strcat(response_string, "\r\n");

    return response_string;
}

void CwebHttpResponse_free(struct CwebHttpResponse *self){
    CwebDict_free(self->headers);
    free(self->content);
    free(self);
}

void CwebHttpResponse_set_content(struct CwebHttpResponse *self, unsigned char *content, int content_length){
    self->content = (unsigned char*)malloc(content_length+2);
    memcpy(self->content, content, content_length);
    self->exist_content = true;
    self->content_length = content_length;
}

void CwebHttpResponse_add_header(struct CwebHttpResponse *self, const char *key, const  char *value){
    CwebDict_set(self->headers, key, value);
}


//path: src/functions/response/response_functions/response_functions.c





 CwebHttpResponse* cweb_send_any(const char *content_type,size_t content_length,unsigned char *content,int status_code){
    CwebHttpResponse *response = newCwebHttpResponse();
    CwebHttpResponse_add_header(response, "Content-Type", content_type);
    CwebHttpResponse_set_content(response, content, content_length);
    response->status_code = status_code;
    return response;
}

CwebHttpResponse * cweb_send_json_string(const char *content,int status_code){
   return cweb_send_any(   "application/json", strlen(content),(unsigned char*)content,status_code);
}


CwebHttpResponse * cweb_send_json_string_cleaning_memory(char *content,int status_code){
    CwebHttpResponse  *response = cweb_send_json_string(content,status_code);
    free(content);
    return response;
}

CwebHttpResponse * cweb_send_cJSON(cJSON *content,int status_code){
    char *rendered = cJSON_Print(content);
    CwebHttpResponse  *response =cweb_send_any(
            "application/json",
            strlen(rendered),
            (unsigned char*)rendered,
            status_code
            );
    free(rendered);
    return response;
}



CwebHttpResponse * cweb_send_cJSON_cleaning_memory(cJSON *content,int status_code){
    CwebHttpResponse  *response = cweb_send_cJSON(content,status_code);
    cJSON_Delete(content);
    return response;
}


CwebHttpResponse* cweb_send_any_cleaning_memory(const char *content_type,size_t content_length,unsigned char *content,int status_code){
     CwebHttpResponse *response = cweb_send_any(content_type,content_length,content,status_code);
    free(content);
    return response;
}


CwebHttpResponse* cweb_send_rendered_CTextStack(struct CTextStack *stack,int status_code){
    return cweb_send_var_html(stack->rendered_text,status_code);
}


CwebHttpResponse* cweb_send_text(const char *content,int status_code){
    return cweb_send_any("text/plain", strlen(content), (unsigned char*)content, status_code);
}


CwebHttpResponse* cweb_send_text_cleaning_memory(char *content,int status_code){
    CwebHttpResponse*  response = cweb_send_any("text/plain", strlen(content), (unsigned char*)content, status_code);
    free(content);
    return response;
}


CwebHttpResponse* cweb_send_var_html(const char *content,int status_code){
    return cweb_send_any("text/html", strlen(content), (unsigned char*)content, status_code);
}


 CwebHttpResponse* cweb_send_var_html_cleaning_memory(char *content,int status_code){
     CwebHttpResponse*  response = cweb_send_any("text/html", strlen(content), (unsigned char*)content, status_code);
    free(content);
    return response;
}



CwebHttpResponse* cweb_send_file(const char *file_path,const char *content_type,int status_code){

    int size = 0;
    unsigned char *content;
    content = cweb_load_binary_content(file_path, &size);

    #ifndef CWEB_NO_STATIC
        if(content == NULL){
            char *not_found_html_page = cweb_load_string_file_content("static/404.html");
            if(not_found_html_page != NULL){
                return cweb_send_var_html_cleaning_memory(not_found_html_page,404);
            }
        }
    #endif

    cweb_print("Writen size: %i\n",size);
    if(content == NULL){
        char mensage[100];
        sprintf(mensage, "File not found: %s", file_path);
        CwebHttpResponse* response =  cweb_send_text(mensage, CWEB_NOT_FOUND);
        return response;
    }

    const char *content_type_created;
    if(content_type == NULL){
        content_type_created  = cweb_generate_content_type(file_path);
    }
    else{
        content_type_created = content_type;
    }

    CwebHttpResponse *response =  cweb_send_any(content_type_created, size, content, status_code);


    if(content != NULL){
        free(content);
    }

    return response;

}



//path: src/functions/static/definition.h
//path: src/functions/static/smart_cache/smart_cache.c



char * private_cweb_smart_static_ref(CTextStack *src){


    CTextStack * filename = private_cweb_format_filename(src);


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

char * cweb_smart_static_ref(const char *src){
    CTextStack  *converted = newCTextStack_string(src);
    char *result  = private_cweb_smart_static_ref(converted);
    CTextStack_free(converted);
    return result;
}

CTextStack * private_cweb_change_smart_cache(CTextStack *content){

    CTextStack *code = newCTextStack_string_empty();
    CTextStack *buffer_pattern = newCTextStack_string_empty();
    CTextStack *src = newCTextStack_string_empty();

    unsigned long content_size = content->size;

    const char *ENTRY_START = "smart-cache";
    int ENTRY_START_LEN = (int)strlen(ENTRY_START);

    const char *ENTRY_PATTERN = "smart-cache='";
    unsigned long ENTRY_PATTERN_LEN = strlen(ENTRY_PATTERN);

    int entry_founds = 0;
    bool found_entry = false;

    for(int i = 0; i < content_size; i++){

        char current = content->rendered_text[i];
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

            char *create_content = private_cweb_smart_static_ref(src);
            CTextStack_text(code,create_content);
            free(create_content);


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
    return code;
}


//path: src/functions/static/inline_inclusion/definition.h
//path: src/functions/static/inline_inclusion/recursion_protection/definition.h
//path: src/functions/static/inline_inclusion/recursion_protection/recursion_element/recursion_element.c





privateCwebRecursionElement * newPrivateCwebRecursionElement(const char *file, const char *included){
    privateCwebRecursionElement *self = (privateCwebRecursionElement*) malloc(sizeof (privateCwebRecursionElement));
    self->file = strdup(file);
    self->included = strdup(included);
    return self;
}
void PrivateCwebRecursionElement_represent(privateCwebRecursionElement *self){
    printf("file: (%s) | included: (%s)\n",self->file,self->included);
}

void PrivateCwebRecursionElement_free(privateCwebRecursionElement *self){
    free(self->file);
    free(self->included);
    free(self);
}


//path: src/functions/static/inline_inclusion/recursion_protection/recursion_list/recursion_list.c




privateCwebRecursionList * newprivateCwebRecursionList(){
    privateCwebRecursionList *self = (privateCwebRecursionList*)malloc(sizeof(privateCwebRecursionList));
    *self = (privateCwebRecursionList){0};
    self->elements = (privateCwebRecursionElement **)malloc(0);
    return self;
}


privateCwebRecursionElement *
privateCwebRecursionList_add_if_not_colide(privateCwebRecursionList *self,const char *file,const char *included){
    for(int i = 0; i < self->size;i++){

        privateCwebRecursionElement *possible_colision = self->elements[i];
        bool not_included = strcmp(file,possible_colision->included) != 0;

        if(not_included){
            continue;
        }
        bool including = strcmp(included,possible_colision->file) == 0;
        if(including){
            return possible_colision;
        }
    }

    self->elements = (privateCwebRecursionElement **) realloc(
            self->elements,
            (self->size +1) * sizeof(privateCwebRecursionList*)
     );
    self->elements[self->size] = newPrivateCwebRecursionElement(file,included);
    self->size+=1;
    return NULL;
}
void privateCwebRecursionList_represent(privateCwebRecursionList *self){
       for(int i =0; i < self->size; i++){
        PrivateCwebRecursionElement_represent(self->elements[i]);
    }
}
void privateCwebRecursionList_free(privateCwebRecursionList *self){
    for(int i =0; i < self->size; i++){
        PrivateCwebRecursionElement_free(self->elements[i]);
    }
    free(self->elements);
    free(self);
}




//path: src/functions/static/inline_inclusion/inline_inclusion/inline_inclusion.c



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



//path: src/functions/static/static/static.c



CTextStack * private_cweb_format_filename(CTextStack *src){
    bool full_path = CTextStack_starts_with(src,cweb_static_folder);

    if(full_path){
        return  newCTextStack_string(src->rendered_text);
    }
    else{
        return  newCTextStack_string_format("%s/%t",cweb_static_folder,src);
    }

}

CwebHttpResponse * private_cweb_treat_five_icon(){


    char possible_ico_path[1000] = {0};
    sprintf(possible_ico_path,"%s/favicon.ico",cweb_static_folder);
    FILE  *possible_ico_file = fopen(possible_ico_path,"rb");
    if(possible_ico_file){
        fclose(possible_ico_file);
        return cweb_send_file(possible_ico_path,CWEB_AUTO_SET_CONTENT,200);
    }


    char possible_png_path[1000] = {0};
    sprintf(possible_png_path,"%s/favicon.png",cweb_static_folder);
    FILE  *possible_png_file = fopen(possible_png_path,"rb");
    if(possible_png_file){
        fclose(possible_png_file);
        return cweb_send_file(possible_png_path,CWEB_AUTO_SET_CONTENT,200);
    }

    char possible_jpg_path[1000] = {0};
    sprintf(possible_jpg_path,"%s/favicon.png",cweb_static_folder);
    FILE  *possible_jpg_file = fopen(possible_jpg_path,"rb");
    if(possible_jpg_file){
        fclose(possible_jpg_file);
        return cweb_send_file(possible_jpg_path,CWEB_AUTO_SET_CONTENT,200);
    }
    return NULL;


}
char * private_cweb_aply_macro_modifiers_in_content(const char *content, long content_size){
    CTextStack *code = newCTextStack_string_empty();
    privateCwebRecursionList *re_list = newprivateCwebRecursionList();
    private_cweb_generate_inline_inclusion(code, content, content_size, re_list, NULL);
    CTextStack  *result = private_cweb_change_smart_cache(code);
    CTextStack_free(code);
    privateCwebRecursionList_free(re_list);
    return CTextStack_self_transform_in_string_and_self_clear(result);
}

char * cweb_aply_macro_modifiers_in_content(const char *content){
    return private_cweb_aply_macro_modifiers_in_content(content, (long)strlen(content));
}

char * cweb_aply_macro_modifiers_in_file(const char *filename){
    bool is_binary;
    int size;
    char *content = (char*)cweb_load_any_content(filename,&size,&is_binary);
    char *result = NULL;
    if(!is_binary){
        result = private_cweb_aply_macro_modifiers_in_content(content,size);
    }
    free(content);
    return result;
}



CwebHttpResponse * private_cweb_generate_static_response(struct CwebHttpRequest *request,bool use_cache){


    bool is_faviocon_route = strcmp(request->route,"/favicon.ico")== 0;
    if(is_faviocon_route){
        return private_cweb_treat_five_icon();
    }


    if(!cweb_starts_with(request->route,"/static")){
        return  NULL;
    }

    char *full_path = NULL;


    char *param_path = CwebHttpRequest_get_param(request,"path");


    if(param_path){
        full_path = param_path;
    }


    if(!param_path){
        full_path = request->route;
        int  base_route_size = (int)strlen("/static");
        int min_size = base_route_size +2;


        if(strlen(full_path) < min_size){
            return NULL;
        }
        full_path+= base_route_size;
    }

    const int MAX_PATH = 900;
    if(strlen(full_path) > MAX_PATH){
        return NULL;
    }

    char formated_full_path[2000] = {0};
    sprintf(formated_full_path,"%s/%s",cweb_static_folder,full_path);

    char *security_path = cweb_replace_string(formated_full_path,"../","");
    int size;
    bool is_binary;
    unsigned char *content = cweb_load_any_content(security_path,&size,&is_binary);

    if(content == NULL){

        char not_found_html_page_path[1100] ={0};
        sprintf(not_found_html_page_path,"%s/404.html",cweb_static_folder);
        char *not_found_html_page = cweb_load_string_file_content(not_found_html_page_path);
        if(not_found_html_page != NULL){
            free(security_path);
            return cweb_send_var_html_cleaning_memory(not_found_html_page,404);

        }

        char menssage[1100] = {0};
        sprintf(menssage,"File %s not found",security_path);
        struct CwebHttpResponse* response =  cweb_send_text(menssage, CWEB_NOT_FOUND);
        free(security_path);

        return response;
    }

    if(!is_binary){
        char *new_content = private_cweb_aply_macro_modifiers_in_content((const char *) content, size);
        free(content);
        size = strlen(new_content);
        content = (unsigned char*)new_content;
    }

    char *content_type  = (char*)cweb_generate_content_type(security_path);

    struct CwebHttpResponse * response = cweb_send_any_cleaning_memory(content_type,size,content,200);


    if(use_cache){
        char *unix_cache = CwebHttpRequest_get_param(request,"unix-cache");
        if(unix_cache){
            char response_code[50] = "";
            sprintf(response_code, "public, max-age=31536000, immutable");
            CwebHttpResponse_add_header(response,"cache-control", response_code);
        }
    }

    free(security_path);
    return response;



}



//path: src/functions/server/definitions.c
//path: src/functions/server/server_functions/server_functions.c



void private_cweb_treat_response(bool use_static,int new_socket){
    cweb_print("New request %lld\n", cweb_actual_request)
    cweb_print("Waiting for child process\n")

    int status = 0;
    while (wait(&status) > 0);

    if (WIFEXITED(status)){
        cweb_print("Sucess\n")
        return;
    }


    pid_t pid_error = fork();
    if (pid_error == 0){
        cweb_print("Sending error mensage\n");
        alarm(2);
        bool send_text_menssage = true;

        if(use_static){

            char possible_500_html_path[1000] = {0};
            sprintf(possible_500_html_path,"%s/500.html",cweb_static_folder);
            FILE *possible_500_html = fopen(possible_500_html_path,"r");
            if(possible_500_html){

                fclose(possible_500_html);
                CwebHttpResponse  *response = cweb_send_file(possible_500_html_path,CWEB_AUTO_SET_CONTENT,500);
                private_cweb_send_error_mensage(response,new_socket);
                send_text_menssage = false;
            }

        }

        if(send_text_menssage){
            CwebHttpResponse  *response = cweb_send_var_html( private_cweb_500,500);
            private_cweb_send_error_mensage(response,new_socket);
        }

        alarm(0);
        exit(0);
    }

    else if (pid_error < 0){
        perror("Faluire to create a new process");
        exit(EXIT_FAILURE);
    }
    else{
        int status2 = 0;
        /// Wait for the child process to finish
        while (wait(&status2) > 0);
        if (WIFEXITED(status2)){
            cweb_print("Mensage sent\n")
        }

        else{
            cweb_print("Error sending mensage\n")
        }
    }
}


void private_cweb_handle_child_termination(int signal) {
    pid_t terminated_child;
    int status;
    while ((terminated_child = waitpid(-1, &status, WNOHANG)) > 0) {
        cweb_total_requests--;
    }
}

void private_cweb_send_error_mensage( CwebHttpResponse *response, int socket){

    char *response_str = CwebHttpResponse_generate_response(response);
    send(socket, response_str, strlen(response_str), 0);
    send(socket, response->content, response->content_length, 0);
    free(response_str);
    CwebHttpResponse_free(response);

}
void cweb_kill_single_process_server( ){
    private_cweb_end_server = true;
}

void cweb_set_static_folder(const char *folder){
    cweb_static_folder = folder;
}
const char * cweb_get_static_folder(){
    return cweb_static_folder;
}

long cweb_get_total_requests(){
    return cweb_total_requests;
}


//path: src/functions/server/server/definitions.c
//path: src/functions/server/server/constructors/constructors.c



 CwebServer  newCwebSever(int port , CwebHttpResponse *(*request_handler)(CwebHttpRequest *request)){
    struct CwebServer self = {0};
    self.port = port;
    self.function_timeout = 30;
    self.client_timeout = 5;
    self.max_queue = 100;
    self.single_process = false;
    self.allow_cors = true;
    self.max_requests = 1000;
    self.static_folder = "static";
    self.use_static = true;
    self.use_cache = true;

    self.request_handler = request_handler;

    return self;
}


int CwebServer_start(CwebServer *self){
    cweb_static_folder = self->static_folder;

    if (self->single_process){
       return  private_CWebServer_run_server_in_single_process(self);
    }

      return  private_CWebServer_run_server_in_multiprocess(self);


}


//path: src/functions/server/server/multi_process/multi_process.c




void private_cweb_execute_request_in_safty_mode(CwebServer  *self,int new_socket, const char *client_ip){

    cweb_print("Creating a new process\n")
    pid_t pid = fork();
    if (pid == 0){
        // means that the process is the child

        alarm(self->function_timeout);
        private_CWebServer_execute_request(self,new_socket, client_ip);
        cweb_print("Request executed\n")
        alarm(0);
        exit(0);
    }

    else if (pid < 0){
        perror("Faluire to create a new process");
        exit(EXIT_FAILURE);
    }

    else{
        //means its the current process
        private_cweb_treat_response(self->use_static,new_socket);

    }

}

int  private_CWebServer_run_server_in_multiprocess(CwebServer *self){
    int port_socket;

    // Creating socket file descriptor
    if ((port_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Faluire to create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Configurando a estrutura de endereço do servidor
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(self->port);


    // Vinculando o socket à porta especificada
    if (bind(port_socket, (struct sockaddr *)&address, sizeof(address)) < 0){
        perror("Faluire to bind socket");
        return 1;
    }



    // Waiting for connections
    if (listen(port_socket, self->max_queue) < 0)
    {
        perror("Faluire to listen connections");
        exit(EXIT_FAILURE);
    }


    // Main loop
    printf("Sever is running on port:%d\n", self->port);



    bool informed_mensage= false;
    while (true)
    {

        if(cweb_total_requests >= self->max_requests){

            if(!informed_mensage){
                printf("max requests reached\n");
                informed_mensage = true;
            }

            continue;
        }

        cweb_print("total request  runing %li\n", cweb_total_requests)

        informed_mensage = false;
        cweb_actual_request++;
        cweb_total_requests++;

        // Accepting a new connection in every socket
        int client_socket = accept(
            port_socket,
            (struct sockaddr *)&address,
            (socklen_t *)&addrlen
        );

        char client_ip[INET_ADDRSTRLEN] ={0};
        inet_ntop(AF_INET, &(address.sin_addr), client_ip, INET_ADDRSTRLEN);

        cweb_print("----------------------------------------\n")
        cweb_print("Executing request:%lld\n", cweb_actual_request)
        cweb_print("Socket: %d\n", client_socket);


        if (client_socket <  0){
            perror("Faluire to accept connection");
            exit(EXIT_FAILURE);
        }

        pid_t pid = fork();
        if (pid == 0){

            // creates an new socket and parse the request to the new socket
            int new_socket = dup(client_socket);

            struct timeval timer1;
            timer1.tv_sec =  0;
            timer1.tv_usec =  0100000;
            setsockopt(new_socket, SOL_SOCKET, SO_RCVTIMEO, &timer1, sizeof(timer1));


            char buffer[1];
            ssize_t peek_result = recv(new_socket, buffer, 1, MSG_PEEK);

            if (peek_result <= 0) {
                cweb_print("peek: %li\n",peek_result);
                cweb_print("Conection closed By the  Client\n");
                close(new_socket);  // Fechar o socket do cliente
                exit(0);
            }

            struct timeval timer2;
            long seconds =  (long)self->client_timeout;
            timer2.tv_sec =  seconds;  // tempo em segundos
            timer2.tv_usec =(long)((self->client_timeout - (double)seconds) * 1000000);
            setsockopt(new_socket, SOL_SOCKET, SO_RCVTIMEO, &timer2, sizeof(timer2));



            private_cweb_execute_request_in_safty_mode(self,new_socket,client_ip);


            close(new_socket);
            cweb_print("Closed Conection with socket %d\n", new_socket);

            exit(0);
        }


        else if (pid < 0){
            perror("Faluire to create a new process");
            exit(EXIT_FAILURE);
        }

        else{
            close(client_socket);
            cweb_print("Closed Conection with socket %d\n", client_socket);
            //make the parent process ignore the SIGCHLD signal
            signal(SIGCHLD, private_cweb_handle_child_termination);
            continue;
        }


    }
    return 0;
}


//path: src/functions/server/server/request_execution/request_execution.c






void private_CWebServer_execute_request(CwebServer *self,int socket,const char *client_ip){

    cweb_print("Parsing Request\n");
    CwebHttpRequest *request = newCwebHttpRequest(socket);
    request->client_ip = strdup(client_ip);


    int result = CwebHttpRequest_parse_http_request(request);

    if(result == INVALID_HTTP){
        cweb_print("Invalid HTTP Request\n");
        CwebHttpRequest_free(request);
        return;
    }

    if(result == READ_ERROR){
        cweb_print("Read Error \n");
        CwebHttpRequest_free(request);
        return;
    }
    if(result == MAX_HEADER_SIZE_CODE){
        cweb_print("Max Header Size\n");
        CwebHttpRequest_free(request);
        return;
    }

    cweb_print("created request\n");
    cweb_print("Request method: %s\n", request->method);
    cweb_print("Request url: %s\n", request->url);



    CwebHttpResponse *response = NULL;

    if(self->use_static){
        response = private_cweb_generate_static_response(request,self->use_cache);
    }


    if(!response){
        //lambda que o usuario passa
        response = self->request_handler(request);
    }

    if(response && self->allow_cors){
        private_cweb_generate_cors_response(response);
    }
    cweb_print("executed client lambda\n");


    //means that the main function respond nothing
    if (response == NULL){

        if(self->use_static){
            char formated_404_path[1000]={0};
            sprintf(formated_404_path,"%s/404.html", cweb_static_folder);
            char *formated_html = cweb_load_string_file_content(formated_404_path);

            if(formated_html != NULL){
                response = cweb_send_var_html_cleaning_memory(
                        formated_html,
                        404);
            }

            else{
                response = cweb_send_var_html(private_cweb_404, 404);
            }
        }
        else{
            response = cweb_send_var_html(private_cweb_404, 404);

        }


    }

    char *response_str = CwebHttpResponse_generate_response(response);
    cweb_print("Response created\n");





    send(socket, response_str, strlen(response_str), MSG_NOSIGNAL);

    // Enviando conteúdo byte a byte
    if (response->exist_content)
    {
        size_t sent = 0;
        while (sent < response->content_length)
        {
            size_t chunk_size = response->content_length - sent;

            ssize_t res = send(socket, response->content + sent, chunk_size, MSG_NOSIGNAL);
            if (res < 0)
            {
                break;
            }
            sent += res;
        }
    }


    free(response_str);
    CwebHttpResponse_free(response);
    CwebHttpRequest_free(request);
    cweb_print("Cleared memory\n");
}


//path: src/functions/server/server/single_process/single_process.c



int private_CWebServer_run_server_in_single_process(CwebServer *self) {

    int port_socket;

    // Creating socket file descriptor
    if ((port_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Faluire to create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Configurando a estrutura de endereço do servidor
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(self->port);


    // Vinculando o socket à porta especificada
    if (bind(port_socket, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        printf("Faluire to bind socket to port %d\n", self->port);
        return 1;

    }

    // Waiting for connections
    if (listen(port_socket, self->max_queue) < 0)
    {
        perror("Faluire to listen connections");
        exit(EXIT_FAILURE);
    }

    // Main loop
    printf("Sever is running on port:%d\n", self->port);


    while (1)
    {

        if(private_cweb_end_server){
                    cweb_print("Break in request %lld\n", cweb_actual_request)
                    break;
        }

        cweb_actual_request++;

        //clear every trash

        // Accepting a new connection in every socket
        int client_socket = accept(
            port_socket,
            (struct sockaddr *)&address,
            (socklen_t *)&addrlen
        );

        char client_ip[INET_ADDRSTRLEN] ={0};
        inet_ntop(AF_INET, &(address.sin_addr), client_ip, INET_ADDRSTRLEN);


        cweb_print("----------------------------------------\n")
        cweb_print("Executing request:%lld\n", cweb_actual_request)
        cweb_print("Socket: %d\n", client_socket)


        if ( client_socket< 0){
            perror("Faluire to accept connection");
            exit(EXIT_FAILURE);
        }

        struct timeval timer1;
        timer1.tv_sec =  0;
        timer1.tv_usec =  0100000;
        setsockopt(client_socket, SOL_SOCKET, SO_RCVTIMEO, &timer1, sizeof(timer1));


        char buffer[1];
        ssize_t peek_result = recv(client_socket, buffer, 1, MSG_PEEK);

        if (peek_result <= 0) {
            cweb_print("peek: %li\n",peek_result)
            cweb_print("Conection closed By the  Client\n")
            close(client_socket);  // Fechar o socket do cliente
            continue;
        }


        struct timeval timer2;
        long seconds =  (long)self->client_timeout;
        timer2.tv_sec =  seconds ;  // tempo em segundos
        timer2.tv_usec =(long)((self->client_timeout - (double )seconds) * 1000000);
        setsockopt(client_socket, SOL_SOCKET, SO_RCVTIMEO, &timer2, sizeof(timer2));


        private_CWebServer_execute_request(self,client_socket, client_ip);


        close(client_socket);


        cweb_print("Closed Conection with socket %d\n", client_socket)


    }
    return 0;
}






//path: src/functions/cors/cors.c





void  private_cweb_generate_cors_response(struct CwebHttpResponse *response) {

    CwebHttpResponse_add_header(response,"Access-Control-Allow-Origin","*");
    CwebHttpResponse_add_header(response,"Access-Control-Allow-Method","*");

}

//path: src/functions/namespace/definition.c
//path: src/functions/namespace/string_array_module/string_array_module.c




CwebStringArrayModule newCwebStringArrayModule(){
    CwebStringArrayModule self ={0};
    self.newStringArray = newCwebStringArray;
    self.set = CwebStringArray_set;
    self.add = CwebStringArray_add;
    self.merge = CwebStringArray_merge;
    self.represent = CwebStringArray_represent;
    self.find = CwebStringArray_find;
    self.free = CwebStringArray_free;
    return  self;
}


//path: src/functions/namespace/dict_module/definition.h
//path: src/functions/namespace/dict_module/keyval_module/keyval_module.c





CwebKeyValModule newCwebKeyValModule(){
    CwebKeyValModule self = {0};
    self.represent = CwebKeyVal_represent;
    self.free = CwebKeyVal_free;

    return self;
}


//path: src/functions/namespace/dict_module/dict_module/dict_module.c



CwebDictModule newCwebDictModule(){
    CwebDictModule self = {0};
    self.newDict = newCwebDict;
    self.set = CwebDict_set;
    self.get = CwebDict_get;
    self.get_by_normalized_key = CwebDict_get_by_normalized_key;
    self.free = CwebDict_free;
    self.represent = CwebDict_represent;

    self.keyval = newCwebKeyValModule();
    return  self;
}



//path: src/functions/namespace/request_module/request_module.c




CwebHttpRequestModule newCwebRequestModule(){
    CwebHttpRequestModule self = {0};
    self.newCwebHttpRequest = newCwebHttpRequest;
    self.read_content = CwebHttpRequest_read_content;
    self.read_cJSON = CWebHttpRequest_read_cJSON;
    self.set_url = CwebHttpRequest_set_url;
    self.set_route = CwebHttpRequest_set_route;
    self.set_method = CwebHttpRequest_set_method;
    self.add_header =CwebHttpRequest_add_header;
    self.add_param = CwebHttpRequest_add_param;
    self.set_content_string = CwebHttpRequest_set_content_string;
    self.parse_http_request = CwebHttpRequest_parse_http_request;


    self.get_header = CwebHttpRequest_get_header;
    self.get_header_by_normalized_key = CwebHttpRequest_get_header_by_normalized_key;
    self.get_param = CwebHttpRequest_get_param;
    self.represent = CwebHttpRequest_represent;
    self.create_stack = CwebHttpRequest_create_empty_stack;
    self.create_empty_stack =CwebHttpRequest_create_stack;


    self.free =CwebHttpRequest_free;
    return self;
}


//path: src/functions/namespace/response_module/response_module.c





CwebHttpResponseModule newCwebHttpResponseModule(){
    CwebHttpResponseModule self = {0};

    self.newHttpResponse  = newCwebHttpResponse;
    self.send_any = cweb_send_any;
    self.send_json_string = cweb_send_json_string;
    self.send_cJSON = cweb_send_cJSON;
    self.send_cJSON_cleaning_memory = cweb_send_cJSON_cleaning_memory;
    self.send_var_html_cleaning_memory = cweb_send_json_string_cleaning_memory;
    self.send_text = cweb_send_text;
    self.send_text_cleaning_memory = cweb_send_text_cleaning_memory;
    self.send_rendered_CTextStack = cweb_send_rendered_CTextStack;
    self.send_var_html = cweb_send_var_html;
    self.send_var_html_cleaning_memory = cweb_send_var_html_cleaning_memory;
    self.send_file = cweb_send_file;

    self.set_content = CwebHttpResponse_set_content;
    self.add_header = CwebHttpResponse_add_header;
    self.generate_response = CwebHttpResponse_generate_response;
    self.free = CwebHttpResponse_free;
    return self;

}


//path: src/functions/namespace/server_module/server_module.c



CwebServerModule newCwebServerModule(){
    CwebServerModule self = {0};
    self.newServer = newCwebSever;
    self.start = CwebServer_start;
    return self;
}


//path: src/functions/namespace/namespace/namespace.c



CwebNamespace newCwebNamespace(){
    CwebNamespace self = {0};
    self.dict = newCwebDictModule();
    self.request = newCwebRequestModule();
    self.response = newCwebHttpResponseModule();
    self.server = newCwebServerModule();
    self.string_array = newCwebStringArrayModule();
    self.hydration = newCWebHydrationNamespace();
    return self;
}



//path: src/functions/namespace/hydratation_module/definition.c
//path: src/functions/namespace/hydratation_module/actions/actions.c



CWebHydrationActionsNamespace newCWebHydrationActionsNamespace(){
    CWebHydrationActionsNamespace self ={0};

    self.replace_element_by_query_selector = CWebHyDrationBridge_replace_element_by_query_selector;
    self.append_by_query_selector = CWebHyDrationBridge_append_by_query_selector;
    self.destroy_by_query_selector =  CWebHyDrationBridge_destroy_by_query_selector;
    self.hide_element_by_query_selector = CWebHyDrationBridge_hide_element_by_query_selector;
    self.unhide_element_by_query_selector=  CWebHyDrationBridge_unhide_element_by_query_selector;
    self.hide_element_by_id = CWebHyDrationBridge_hide_element_by_id;
    self.unhide_element_by_id= CWebHyDrationBridge_unhide_element_by_id;
    self.append_by_id = CWebHyDrationBridge_append_by_id;
    self.set_session_storage_data = CWebHyDrationBridge_set_session_storage_data;
    self.alert = CWebHyDrationBridge_alert;
    self.execute_script = CWebHyDrationBridge_execute_script;
    self.replace_element_by_id = CWebHyDrationBridge_replace_element_by_id;
    self.destroy_by_id = CWebHyDrationBridge_destroy_by_id;
    self.redirect = CWebHydration_redirect;
    self.add_cookie_with_time = CWebHydrationBridge_creatCookie_with_time;
    self.add_cookie = CWebHydrationBridge_creatCookie;
    self.delet_cookie = CWebHyDrationBridge_deletCookie;
    self.console_log = CWebHyDration_console_log;
    self.console_warn = CWebHyDration_console_warn;
    self.console_clear = CWebHyDration_console_clear;
    self.console_error = CWebHyDration_console_error;

    return self;
}


//path: src/functions/namespace/hydratation_module/args/args.c



CWebHydrationArgsNamespace newCWebHydrationArgsNamespace(){
    CWebHydrationArgsNamespace self = {0};
    self.get_args_size  = CWebHyDrationBridge_get_args_size;
    self.is_arg_number = CWebHyDrationBridge_is_arg_number;
    self.is_arg_bool = CWebHyDrationBridge_is_arg_bool;
    self.is_arg_string  = CWebHyDrationBridge_is_arg_string;
    self.get_double_arg = CWebHyDrationBridge_get_double_arg;
    self.get_long_arg = CWebHyDrationBridge_get_long_arg;
    self.get_bool_arg = CWebHyDrationBridge_get_bool_arg;
    self.get_str_arg = CWebHyDrationBridge_get_str_arg;
    self.get_cJSON_arg  = CWebHyDrationBridge_get_cJSON_arg;
    return self;
}


//path: src/functions/namespace/hydratation_module/bridge/bridge.c



CWebHydrationBridgeNamespace newCWebHydrationBridgetNamespace(){
    CWebHydrationBridgeNamespace self = {0};
    self.call = CWebHyDrationBridge_call;
    self.onclick =CWebHyDrationBridge_onclick;
    self.onfoccusout =CWebHyDrationBridge_onfoccusout;
    self.has_errors = CWebHyDrationBridge_has_errors;
    self.create_bridge = CWebHyDration_create_bridge;
    self.get_child_bridge = CWebHyDration_get_child_bridge;
    self.get_brother_bridge =CWebHyDrationBridge_get_brother_bridge;

    self.create_stack = CWebHyDrationBridge_create_stack;
    self.create_empty_stack = CWebHyDrationBridge_create_empty_stack;

    return self;
}


//path: src/functions/namespace/hydratation_module/search_requirements/search_requirements.c




CWebHydrationSearchRequirementsNamespace newCWebHydrationSearchRequirementsNamespace(){
    CWebHydrationSearchRequirementsNamespace self = {0};


    self.newSearchRequirements = CWebHyDrationBridge_newSearchRequirements;
    self.add_function = CWebHyDrationSearchRequirements_add_function;
    self.add_elements_by_query_selector = CWebHyDrationSearchRequirements_add_elements_by_query_selector;
    self.add_elements_by_query_selector_not_auto_converting = CWebHyDrationSearchRequirements_add_elements_by_query_selector_not_auto_converting;
    self.add_elements_by_attribute = CWebHyDrationSearchRequirements_add_elements_by_attribute;
    self.add_elements_by_attribute_not_auto_converting = CWebHyDrationSearchRequirements_add_elements_by_attribute_not_auto_converting;
    self.add_elements_by_class_name = CWebHyDrationSearchRequirements_add_elements_by_class_name;
    self.add_elements_by_class_name_not_auto_converting =CWebHyDrationSearchRequirements_add_elements_by_class_name_not_auto_converting;
    self.add_elements_by_id = CWebHyDrationSearchRequirements_add_elements_by_id;
    self.add_elements_by_id_not_auto_converting = CWebHyDrationSearchRequirements_add_elements_by_id_not_auto_converting;
    self.add_session_storage_item_not_converting = CWebHyDrationSearchRequirements_add_elements_by_id_not_auto_converting;
    self.add_session_storage_item = CWebHyDrationSearchRequirements_add_session_storage_item;
    self.add_value_cookie_by_key = CWebHyDrationSearchRequirements_add_cookie_item;
    self.add_confirm = CWebHyDrationSearchRequirements_add_confirm;
    self.add_prompt = CWebHyDrationSearchRequirements_add_prompt;


    self.add_element_by_id_setting_search_as_same_name =
        CWebHyDrationBridge_add_element_by_id_setting_search_as_same_name;
    self.add_element_by_id_setting_search_as_same_name_not_formmating =
        CWebHyDrationBridge_add_element_by_id_setting_search_as_same_name_not_format;



    return self;
}


//path: src/functions/namespace/hydratation_module/search_result/search_result.c



CWebHydrationSearchResultNamespace newCWebHydrationSearchResultNamespace(){
    CWebHydrationSearchResultNamespace self = {0};
    self.get_total_avaialible_searchs = CWebHyDrationBridge_get_total_avaialible_searchs;
    self.get_search_by_index = CWebHyDrationBridge_get_search_by_index;
    self.get_search_by_name =  CWebHyDrationBridge_get_search_by_name;
    self.search_exist = CWebHyDrationBridge_search_exist;
    self.get_double_from_first_element_of_search = CWebHyDrationBridge_get_double_from_first_element_of_search;
    self.get_long_from_first_element_of_search = CWebHyDrationBridge_get_long_from_first_element_of_search;
    self.get_bool_from_first_element_of_search = CWebHyDrationBridge_get_bool_from_first_element_of_search;
    self.get_string_from_first_element_of_search = CWebHyDrationBridge_get_string_from_first_element_of_search;
    self.get_cJSON_from_first_element_of_search = CWebHyDrationBridge_get_cJSON_from_first_element_of_search;
    self.get_total_itens = CWebHyDrationSearchResult_get_total_itens;
    self.search_item_exist = CWebHyDrationSearchResult_search_item_exist;
    self.is_search_item_number = CWebHyDrationSearchResult_is_search_item_number;
    self.is_search_item_bool =  CWebHyDrationSearchResult_is_search_item_bool;
    self.is_search_item_string = CWebHyDrationSearchResult_is_search_item_string;
    self.get_double = CWebHyDrationSearchResult_get_double;
    self.get_long = CWebHyDrationSearchResult_get_long;
    self.get_bool = CWebHyDrationSearchResult_get_bool;
    self.get_string = CWebHyDrationSearchResult_get_string;
    self.get_cJSON = CWebHyDrationSearchResult_get_cJSON;

    return self;
}


//path: src/functions/namespace/hydratation_module/hydration/hydration.c




CWebHydrationNamespace newCWebHydrationNamespace() {
    CWebHydrationNamespace self = {0};
    self.newCWebHyDration = newCWebHyDration;
    self.is_the_trigger = CWebHyDration_is_the_trigger;
    self.create_script = CWebHyDration_create_script;
    self.create_stack = CWebHyDration_create_stack;
    self.create_empty_stack = CWebHyDration_create_empty_stack;
    self.generate_response = CWebHydration_generate_response;

    self.bridge = newCWebHydrationBridgetNamespace();
    self.actions =newCWebHydrationActionsNamespace();
    self.search_requirements =newCWebHydrationSearchRequirementsNamespace();
    self.search_result = newCWebHydrationSearchResultNamespace();
    self.args = newCWebHydrationArgsNamespace();
    return self;
}






//path: src/functions/hydratation/definition.c
//path: src/functions/hydratation/bridge/definition.c
//path: src/functions/hydratation/bridge/basic/basic.c






CWebHyDrationBridge * CWebHyDrationBridge_get_brother_bridge(CWebHyDrationBridge *self,const char *name){
    CWebHyDration *hydration = (CWebHyDration *)self->hydration;
    return CWebHyDration_get_child_bridge(hydration,name);
}

CWebHyDrationBridge *private_newCWebHyDrationBridge(
    const char *name,
    void (*callback)(CWebHyDrationBridge *),CWebHyDration *hydration
) {
    CWebHyDrationBridge *self = (CWebHyDrationBridge*)malloc(sizeof(CWebHyDrationBridge));
    *self = (CWebHyDrationBridge){0};
    self->name = strdup(name);
    self->callback = callback;
    self->hydration = (void*)hydration;
    self->requirements_code =newCwebStringArray();
    return  self;
}



CTextStack * CWebHyDrationBridge_create_stack(CWebHyDrationBridge *self){
    return CWebHyDration_create_stack((CWebHyDration*)self->hydration);
}

CTextStack * CWebHyDrationBridge_create_empty_stack(CWebHyDrationBridge *self){
    return CWebHyDration_create_empty_stack((CWebHyDration*)self->hydration);
}

CWebHyDrationSearchRequirements * CWebHyDrationBridge_newSearchRequirements(
    CWebHyDrationBridge *self, const char *name,...)
{
    va_list  args;
    va_start(args,name);
    char *formmated_name = private_CWeb_format_vaarg(name,args);
    va_end(args);

    CWebHyDrationSearchRequirements *created_search =
    private_newCWebHyDrationSearchRequirements_getting_name_ownership(
        self,
        formmated_name
    );

    CWebHyDration *hydration =(CWebHyDration*)self->hydration;
    UniversalGarbage *garbage = hydration->request->garbage;

   UniversalGarbage_add(
       garbage,
        private_CWebHyDrationSearchRequirements_free,
        created_search
    );
    return created_search;
}

void CWebHyDrationBridge_add_element_by_id_setting_search_as_same_name(
    CWebHyDrationBridge *self, const char *id
){
    CWebHyDrationSearchRequirements * search =
    CWebHyDrationBridge_newSearchRequirements(self,id);
    CWebHyDrationSearchRequirements_add_elements_by_id(search, id);

}

void CWebHyDrationBridge_add_element_by_id_setting_search_as_same_name_not_format(
    CWebHyDrationBridge *self, const char *id
){
    CWebHyDrationSearchRequirements * search =
    CWebHyDrationBridge_newSearchRequirements(self,id);
    CWebHyDrationSearchRequirements_add_elements_by_id_not_auto_converting(search, id);
}


CTextStack*  private_CWebHyDrationBridge_create_script(CWebHyDrationBridge *self) {

    CTextStack *function = newCTextStack_string_empty();

    CTextStack_format(
        function,
        "private_cweb_bridges['%s'] = async function (args){ \n",
        self->name
    );

    CTextStack_format(function,"\tlet content = {}\n");

    for(int i= 0; i < self->requirements_code->size;i++) {
        CTextStack_format(
            function,
            "%s\n",
            self->requirements_code->strings[i]
        );
    }

    CTextStack_format(
        function,
        "\tawait private_cweb_send_to_server('%s',args,content)\n",
        self->name
    );
    CTextStack_format(function,"};\n");

    return function;
}
bool CWebHyDrationBridge_has_errors(CWebHyDrationBridge *self){
    if(self == NULL){
        return  true;
    }
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;
    if(hydration->error_code == 0){
        return false;
    }
    return true;
}



void private_CWebHyDrationBridge_free(CWebHyDrationBridge *self) {
free(self->name);
    CwebStringArray_free(self->requirements_code);
    free(self);
}


//path: src/functions/hydratation/bridge/args/args.c




int   CWebHyDrationBridge_get_args_size(CWebHyDrationBridge *self){
    if(CWebHyDrationBridge_has_errors(self)){
        return 0;
    }
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;
    return cJSON_GetArraySize(hydration->args);
}


bool private_cweb_hydration_type_verifier(CWebHyDrationBridge *self,int index,cJSON_bool (*callback_verifier)(const cJSON * const item)){
    if(CWebHyDrationBridge_has_errors(self)){
        return false;
    }
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;
    cJSON *item = cJSON_GetArrayItem(hydration->args, index);
    if(item == NULL){
        return false;
    }
    return (bool)callback_verifier(item);
}

bool   CWebHyDrationBridge_is_arg_number(CWebHyDrationBridge *self,int index){
    if(CWebHyDrationBridge_has_errors(self)){
        return false;
    }
    return private_cweb_hydration_type_verifier(self,index,cJSON_IsNumber);
}

bool   CWebHyDrationBridge_is_arg_bool(CWebHyDrationBridge *self,int index){
    if(CWebHyDrationBridge_has_errors(self)){
        return false;
    }
    return private_cweb_hydration_type_verifier(self,index,cJSON_IsBool);
}
bool   CWebHyDrationBridge_is_arg_string(CWebHyDrationBridge *self,int index){
    if(CWebHyDrationBridge_has_errors(self)){
        return false;
    }
    return private_cweb_hydration_type_verifier(self,index,cJSON_IsString);
}


cJSON *privateCWebHyDration_get_arg_index(
    CWebHyDrationBridge *self,
    int index,
    cJSON_bool (*callback_verifier)(const cJSON * const item),
    const char *expected_type
){

    if(CWebHyDrationBridge_has_errors(self)){
        return NULL;
    }
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;

    cJSON *item = cJSON_GetArrayItem(hydration->args,index);

    if(item == NULL){
        privateCWebHydration_raise_error(
            hydration,
            self,
            CWEB_HYDRATION_INDEX_ARGS_NOT_PROVIDED,
            CWEB_HYDRATION_INDEX_ARGS_NOT_PROVIDED_MSG,
            index);
        return NULL;
    }
    if(!callback_verifier){
        return  item;
    }

    if(!callback_verifier(item)){
        privateCWebHydration_raise_error(
            hydration,
            self,
            CWEB_HYDRATION_INDEX_ARGS_WRONG_TYPE,
            CWEB_HYDRATION_INDEX_ARGS_WRONG_TYPE_MSG,
            index,
            expected_type
        );
        return NULL;
    }
    return item;
}

double  CWebHyDrationBridge_get_double_arg(CWebHyDrationBridge *self,int index){
    if(CWebHyDrationBridge_has_errors(self)){
        return -1;
    }
    cJSON *item = privateCWebHyDration_get_arg_index(self,index,cJSON_IsNumber,CWEB_HYDRATION_NUMBER);
    if(item == NULL){
        return -1;
    }

    return cJSON_GetNumberValue(item);
}

long  CWebHyDrationBridge_get_long_arg(CWebHyDrationBridge *self,int index){
    if(CWebHyDrationBridge_has_errors(self)){
        return -1;
    }
    cJSON *item = privateCWebHyDration_get_arg_index(self,index,cJSON_IsNumber,CWEB_HYDRATION_NUMBER);
    if(item == NULL){
        return -1;
    }

    return (long)cJSON_GetNumberValue(item);
}



bool  CWebHyDrationBridge_get_bool_arg(CWebHyDrationBridge *self,int index){
    if(CWebHyDrationBridge_has_errors(self)){
        return false;
    }
    cJSON *item = privateCWebHyDration_get_arg_index(self,index,cJSON_IsNumber,CWEB_HYDRATION_BOOL);
        if(item == NULL){
            return -1;
        }

    return (bool)item->valueint;
}

char* CWebHyDrationBridge_get_str_arg(CWebHyDrationBridge *self,int index){
    if(CWebHyDrationBridge_has_errors(self)){
        return NULL;
    }
    cJSON *item = privateCWebHyDration_get_arg_index(self,index,cJSON_IsString,CWEB_HYDRATION_STRING);
        if(item == NULL){
            return NULL;
        }

    return cJSON_GetStringValue(item);
}
cJSON * CWebHyDrationBridge_get_cJSON_arg(CWebHyDrationBridge *self,int index){
    if(CWebHyDrationBridge_has_errors(self)){
        return NULL;
    }
    return  privateCWebHyDration_get_arg_index(self,index,NULL,NULL);
}


//path: src/functions/hydratation/bridge/calls/calls.c





char *CWebHyDrationBridge_call(CWebHyDrationBridge *self,const char *func_args,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return NULL;
    }

    CTextStack *callback= newCTextStack_string_empty();
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;

    if(func_args != NULL){
        va_list  args;
        va_start(args,func_args);
        char *formmated_func_args = private_CWeb_format_vaarg(func_args,args);
        va_end(args);
        CTextStack_format(
            callback,
           "private_cweb_bridges[`%s`]([%s]);",
            self->name,
            formmated_func_args
        );
        free(formmated_func_args);
    }

    if(func_args == NULL) {
        CTextStack_format(
            callback,
            "private_cweb_bridges[`%s`]([]);",
            self->name
        );
    }
    UniversalGarbage *garbage = hydration->request->garbage;

    UniversalGarbage_add(garbage,CTextStack_free, callback);
    return callback->rendered_text;

}


char *private_CWebHyDrationBridge_call_trigger(
    CWebHyDrationBridge *self,
    const char *trigger,
    const char *func_args
){
    if(CWebHyDrationBridge_has_errors(self)){
        return NULL;
    }


    CTextStack *callback= newCTextStack_string_empty();
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;

    CTextStack_format(
        callback,
        "%s = private_cweb_bridges['%s']([%s]);",
        trigger,
        self->name,
        func_args
    );
    UniversalGarbage *garbage = hydration->request->garbage;
    UniversalGarbage_add(garbage,CTextStack_free, callback);
    return callback->rendered_text;
}

char *CWebHyDrationBridge_onclick(CWebHyDrationBridge *self,const char *func_args,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return NULL;
    }

    if(func_args==NULL){
        return private_CWebHyDrationBridge_call_trigger(self,"onclick","");
    }

    va_list  args;
    va_start(args,func_args);
    char *formmated_func_args = private_CWeb_format_vaarg(func_args,args);
    va_end(args);

    char *result = private_CWebHyDrationBridge_call_trigger(self,"onclick",formmated_func_args);
    free(formmated_func_args);
    return result;
}


char *CWebHyDrationBridge_onfoccusout(CWebHyDrationBridge *self,const char *func_args,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return NULL;
    }

    if(func_args==NULL){
        return private_CWebHyDrationBridge_call_trigger(self,"onfocusout","");
    }

    va_list  args;
    va_start(args,func_args);
    char *formmated_func_args = private_CWeb_format_vaarg(func_args,args);
    va_end(args);

    char *result = private_CWebHyDrationBridge_call_trigger(self,"onfocusout",formmated_func_args);
    free(formmated_func_args);
    return result;
}


//path: src/functions/hydratation/bridge/search_result/search_result.c





int  CWebHyDrationBridge_get_total_avaialible_searchs(CWebHyDrationBridge *self){
    if(CWebHyDrationBridge_has_errors(self)){
        return 0;
    }
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;
    return cJSON_GetArraySize(hydration->content);
}


CWebHyDrationSearchResult * CWebHyDrationBridge_get_search_by_index(CWebHyDrationBridge *self,int index){

    if(CWebHyDrationBridge_has_errors(self)){
        return NULL;
    }
    CWebHyDration *hydration = (CWebHyDration*)self->hydration;
    cJSON *search =  cJSON_GetArrayItem(hydration->content, index);
    if(search == NULL){
        privateCWebHydration_raise_error(
            hydration,
            self,
            CWEB_HYDRATION_CONTENT_SEARCH_NOT_EXIST,
            CWEB_HYDRATION_CONTENT_SEARCH_NOT_EXIST_MSG,
            index
        );
        return NULL;
    }
    CWebHyDrationSearchResult *result = private_newCWebHyDrationSearchResult(self, search);
    UniversalGarbage *garbage = hydration->request->garbage;

    UniversalGarbage_add(garbage,privateCWebHyDrationSearchResult_free,result);
    return result;
}

CWebHyDrationSearchResult * CWebHyDrationBridge_get_search_by_name(CWebHyDrationBridge *self,const char *name,...){

    if(CWebHyDrationBridge_has_errors(self)){
        return NULL;
    }
    va_list  args;
    va_start(args,name);
    char *formmated_name = private_CWeb_format_vaarg(name,args);
    va_end(args);

    CWebHyDration *hydration = (CWebHyDration*)self->hydration;
    cJSON *search = cJSON_GetObjectItem(hydration->content,formmated_name);
    if(search == NULL){
        privateCWebHydration_raise_error(
            hydration,
            self,
            CWEB_HYDRATION_CONTENT_KEY_NOT_PROVIDED,
            CWEB_HYDRATION_CONTENT_KEY_NOT_PROVIDED_MSG,
            formmated_name
        );
        free(formmated_name);
        return NULL;
    }
    free(formmated_name);

    CWebHyDrationSearchResult *result = private_newCWebHyDrationSearchResult(self, search);
    UniversalGarbage *garbage = hydration->request->garbage;
    UniversalGarbage_add(garbage,privateCWebHyDrationSearchResult_free,result);
    return result;
}

bool CWebHyDrationBridge_search_exist(CWebHyDrationBridge *self,const char *name,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return false;
    }
    va_list  args;
        va_start(args,name);
        char *formmated_name = private_CWeb_format_vaarg(name,args);
        va_end(args);

        CWebHyDration *hydration = (CWebHyDration*)self->hydration;
        cJSON *search = cJSON_GetObjectItem(hydration->content,formmated_name);
        free(formmated_name);
        return search != NULL;
}

double CWebHyDrationBridge_get_double_from_first_element_of_search(CWebHyDrationBridge *self,const char *name,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return -1;
    }
    va_list  args;
    va_start(args,name);
    char *formmated_name = private_CWeb_format_vaarg(name,args);
    va_end(args);
    CWebHyDrationSearchResult *search = CWebHyDrationBridge_get_search_by_name(self,"%s",formmated_name);
    free(formmated_name);
    if(search == NULL){
        return  -1;
    }
    return CWebHyDrationSearchResult_get_double(search,0);
}

long CWebHyDrationBridge_get_long_from_first_element_of_search(CWebHyDrationBridge *self,const char *name,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return -1;
    }
    va_list  args;
    va_start(args,name);
    char *formmated_name = private_CWeb_format_vaarg(name,args);
    va_end(args);
    CWebHyDrationSearchResult *search = CWebHyDrationBridge_get_search_by_name(self,"%s",formmated_name);
    free(formmated_name);
    if(search == NULL){
        return  -1;
    }
    return CWebHyDrationSearchResult_get_long(search,0);
}


bool CWebHyDrationBridge_get_bool_from_first_element_of_search(CWebHyDrationBridge *self,const char *name,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return false;
    }
    va_list  args;
    va_start(args,name);
    char *formmated_name = private_CWeb_format_vaarg(name,args);
    va_end(args);
    CWebHyDrationSearchResult *search = CWebHyDrationBridge_get_search_by_name(self,"%s",formmated_name);
    free(formmated_name);
    if(search == NULL){
        return  false;
    }
    return CWebHyDrationSearchResult_get_bool(search,0);
}


char* CWebHyDrationBridge_get_string_from_first_element_of_search(CWebHyDrationBridge *self,const char *name,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return NULL;
    }
    va_list  args;
    va_start(args,name);
    char *formmated_name = private_CWeb_format_vaarg(name,args);
    va_end(args);
    CWebHyDrationSearchResult *search = CWebHyDrationBridge_get_search_by_name(self,"%s",formmated_name);
    free(formmated_name);
    if(search == NULL){
        return  NULL;
    }
    return CWebHyDrationSearchResult_get_string(search,0);
}

cJSON* CWebHyDrationBridge_get_cJSON_from_first_element_of_search(CWebHyDrationBridge *self,const char *name,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return NULL;
    }
    va_list  args;
    va_start(args,name);
    char *formmated_name = private_CWeb_format_vaarg(name,args);
    va_end(args);
    CWebHyDrationSearchResult *search = CWebHyDrationBridge_get_search_by_name(self,"%s",formmated_name);
    free(formmated_name);
    if(search == NULL){
        return  NULL;
    }
    return CWebHyDrationSearchResult_get_cJSON(search,0);
}


//path: src/functions/hydratation/bridge/action/action.c




void privateCWebHyDrationBridge_add_response(CWebHyDrationBridge *self,const char *name,cJSON *data){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }

    CWebHyDration *hydraation = (CWebHyDration*)self->hydration;
    cJSON *current_response = cJSON_CreateObject();
    cJSON_AddStringToObject(current_response,CWEB_HYDRATON_JSON_NAME,name);
    cJSON_AddItemToObject(current_response,CWEB_HYDRATON_JSON_DATA,data);
    cJSON_AddItemToArray(hydraation->response,current_response);
}

void CWebHyDrationBridge_set_session_storage_data(

    CWebHyDrationBridge *self,const char*key, const char *value,...){
        if(CWebHyDrationBridge_has_errors(self)){
            return ;
        }
        cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args,value);
    char *value_formmat = private_CWeb_format_vaarg(value,args);
    va_end(args);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_KEY, key);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_VALUE,value_formmat);
    free(value_formmat);
    privateCWebHyDrationBridge_add_response(self,"set_session_storage",obj);
}

void CWebHyDrationBridge_alert(CWebHyDrationBridge *self,const char *menssage,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args,menssage);
    char *msg_format = private_CWeb_format_vaarg(menssage,args);
    va_end(args);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_MSG, msg_format);
    free(msg_format);
    privateCWebHyDrationBridge_add_response(self,"alert",obj);

}

void CWebHydrationBridge_creatCookie_with_time(CWebHyDrationBridge *self, const char *key, long time, const char *value, ...){

    if(CWebHyDrationBridge_has_errors(self)){
        return;
    }
    cJSON *obj = cJSON_CreateObject();

    va_list args;
    va_start(args, value);
    char *value_formated = private_CWeb_format_vaarg(value, args);
    va_end(args);
    cJSON_AddStringToObject(obj, "name", key);
    cJSON_AddStringToObject(obj, "value", value_formated);
    cJSON_AddNumberToObject(obj, "days", time);
    free(value_formated);
    privateCWebHyDrationBridge_add_response(self, "add_cookie_with_time", obj);
}

void CWebHydrationBridge_creatCookie(CWebHyDrationBridge *self, const char *key, const char *value, ...){

    if(CWebHyDrationBridge_has_errors(self)){
        return;
    }
    cJSON *obj = cJSON_CreateObject();

    va_list args;
    va_start(args, value);
    char *value_formated = private_CWeb_format_vaarg(value, args);
    va_end(args);
    cJSON_AddStringToObject(obj, "name", key);
    cJSON_AddStringToObject(obj, "value", value_formated);
    free(value_formated);
    privateCWebHyDrationBridge_add_response(self, "add_cookie", obj);
}

void CWebHyDrationBridge_deletCookie(CWebHyDrationBridge *self, const char *key){
    if(CWebHyDrationBridge_has_errors(self)){
        return;
    }
    cJSON *obj = cJSON_CreateObject();

    cJSON_AddStringToObject(obj, "name", key);
    privateCWebHyDrationBridge_add_response(self, "delet_cookie", obj);
}

void CWebHyDrationBridge_execute_script(CWebHyDrationBridge *self,const char *code,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args,code);
    char *code_format = private_CWeb_format_vaarg(code,args);
    va_end(args);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_CODE, code_format);
    free(code_format);
    privateCWebHyDrationBridge_add_response(self,"execute_script",obj);
}

void CWebHyDrationBridge_replace_element_by_query_selector(
    CWebHyDrationBridge *self,
    const char *query_selector,
    const char *code,
    ...
){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args,code);
    char *html_format = private_CWeb_format_vaarg(code,args);
    va_end(args);

    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_QUERY_SELECTOR, query_selector);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_HTML, html_format);
    free(html_format);
    privateCWebHyDrationBridge_add_response(self,"replace_element_by_query_selector",obj);
}


void CWebHyDrationBridge_append_by_query_selector(
    CWebHyDrationBridge *self,
    const char *query_selector,
    const char *code,
    ...
){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args,code);
    char *html_format = private_CWeb_format_vaarg(code,args);
    va_end(args);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_QUERY_SELECTOR, query_selector);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_HTML, html_format);
    free(html_format);
    privateCWebHyDrationBridge_add_response(self,"append_by_query_selector",obj);
}



void CWebHyDrationBridge_destroy_by_query_selector(
    CWebHyDrationBridge *self,
    const char * query_selecor
){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_QUERY_SELECTOR, query_selecor);
    privateCWebHyDrationBridge_add_response(self,"destroy_by_query_selector",obj);
}


void CWebHyDrationBridge_hide_element_by_query_selector(
CWebHyDrationBridge *self,
const char *query_selecor){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_QUERY_SELECTOR, query_selecor);
    privateCWebHyDrationBridge_add_response(self,"hide_element_by_query_selector",obj);
}

void CWebHyDrationBridge_unhide_element_by_query_selector(
    CWebHyDrationBridge *self,
    const char *query_selector
){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_QUERY_SELECTOR, query_selector);
    privateCWebHyDrationBridge_add_response(self,"unhide_element_by_id",obj);
}




void CWebHyDrationBridge_replace_element_by_id(CWebHyDrationBridge *self,const char *id, const char *code,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args,code);
    char *html_format = private_CWeb_format_vaarg(code,args);
    va_end(args);
    char *formatted_query_selecor = private_CWeb_format("[id='%s']",id);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_QUERY_SELECTOR, formatted_query_selecor);
    free(formatted_query_selecor);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_HTML, html_format);
    free(html_format);
    privateCWebHyDrationBridge_add_response(self,"replace_element_by_query_selector",obj);
}

void CWebHyDrationBridge_append_by_id(CWebHyDrationBridge *self,const char *id, const char *code,...){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args,code);
    char *html_format = private_CWeb_format_vaarg(code,args);
    va_end(args);
    char *formatted_query_selecor = private_CWeb_format("[id='%s']",id);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_QUERY_SELECTOR, formatted_query_selecor);
    free(formatted_query_selecor);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_HTML, html_format);
    free(html_format);
    privateCWebHyDrationBridge_add_response(self,"append_by_query_selector",obj);
}


void CWebHyDrationBridge_hide_element_by_id(CWebHyDrationBridge *self,const char *id){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();

    char *formatted_query_selecor = private_CWeb_format("[id='%s']",id);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_QUERY_SELECTOR, formatted_query_selecor);
    free(formatted_query_selecor);

    privateCWebHyDrationBridge_add_response(self,"hide_element_by_query_selector",obj);
}

void CWebHyDrationBridge_unhide_element_by_id(CWebHyDrationBridge *self,const char *id){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();

    char *formatted_query_selecor = private_CWeb_format("[id='%s']",id);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_QUERY_SELECTOR, formatted_query_selecor);
    free(formatted_query_selecor);

    privateCWebHyDrationBridge_add_response(self,"unhide_element_by_query_selector",obj);
}


void CWebHyDrationBridge_destroy_by_id(CWebHyDrationBridge *self,const char * id){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();

    char *formatted_query_selecor = private_CWeb_format("[id='%s']",id);
    cJSON_AddStringToObject(obj,CWEB_HYDRATON_JSON_QUERY_SELECTOR, formatted_query_selecor);
    free(formatted_query_selecor);

    privateCWebHyDrationBridge_add_response(self,"destroy_by_query_selector",obj);
}

void CWebHydration_redirect(CWebHyDrationBridge *self, const char *url){
    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj, CWEB_HYDRATION_JSON_URL, url);
    privateCWebHyDrationBridge_add_response(self,"redirect",obj);
}

void CWebHyDration_console_log(CWebHyDrationBridge *self, const char *menssage, ...){

    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args, menssage);
    char *menssage_formated = private_CWeb_format_vaarg(menssage, args);
    va_end(args);

    cJSON_AddStringToObject(obj, "message", menssage_formated);
    privateCWebHyDrationBridge_add_response(self, "log", obj);
}
void CWebHyDration_console_warn(CWebHyDrationBridge *self, const char *menssage, ...){

    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args, menssage);
    char *menssage_formated = private_CWeb_format_vaarg(menssage, args);
    va_end(args);

    cJSON_AddStringToObject(obj, "message", menssage_formated);
    privateCWebHyDrationBridge_add_response(self, "warn", obj);
}
void CWebHyDration_console_error(CWebHyDrationBridge *self, const char *menssage, ...){

    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    va_list  args;
    va_start(args, menssage);
    char *menssage_formated = private_CWeb_format_vaarg(menssage, args);
    va_end(args);

    cJSON_AddStringToObject(obj, "message", menssage_formated);
    privateCWebHyDrationBridge_add_response(self, "error", obj);
}
void CWebHyDration_console_clear(CWebHyDrationBridge *self){

    if(CWebHyDrationBridge_has_errors(self)){
        return ;
    }
    cJSON *obj = cJSON_CreateObject();
    privateCWebHyDrationBridge_add_response(self, "clear", obj);
}






//path: src/functions/hydratation/bridge_array/bridge_array.c




privateCWebHyDrationBridgeArray * private_new_privateCWebHyDrationBridgeArray() {
    privateCWebHyDrationBridgeArray *self = (privateCWebHyDrationBridgeArray*)malloc(sizeof(privateCWebHyDrationBridgeArray));
    *self = (privateCWebHyDrationBridgeArray){0};
    self->elments = (CWebHyDrationBridge**)malloc(0);
    return  self;
}

void privateCWebHyDrationBridgeArray_append(privateCWebHyDrationBridgeArray *self,CWebHyDrationBridge *element) {
    self->elments = (CWebHyDrationBridge**)realloc(self->elments, (self->size +1 )* sizeof(CWebHyDrationBridge*));
    self->elments[self->size] = element;
    self->size+=1;
}

void privateCWebHyDrationBridgeArray_free(privateCWebHyDrationBridgeArray *self) {
    for(int i = 0; i  < self->size;i++) {
        private_CWebHyDrationBridge_free(self->elments[i]);
    }
    free(self->elments);
    free(self);
}



//path: src/functions/hydratation/search_requirements/search_requirements.c






CWebHyDrationSearchRequirements * private_newCWebHyDrationSearchRequirements_getting_name_ownership(
    CWebHyDrationBridge *bridge, char *name
){
    CWebHyDrationSearchRequirements *self = malloc(sizeof(CWebHyDrationSearchRequirements));
    self->bridge =bridge;
    self->name =name;
    return self;
}


void private_CWebHyDrationSearchRequirements_free(CWebHyDrationSearchRequirements *self){
        free(self->name);
        free(self);
}


void CWebHyDrationSearchRequirements_add_function(CWebHyDrationSearchRequirements *self,const char *function,...){
    va_list  args;
    va_start(args,function);
    char *func_value = private_CWeb_format_vaarg(function,args);
    va_end(args);


    CTextStack *callback = newCTextStack_string_format(
        "private_cweb_handle_required_data(%s,args,content,'%s');",
        func_value,
        self->name
    );

    free(func_value);
    char *callback_str = CTextStack_self_transform_in_string_and_self_clear(callback);
    CwebStringArray_add_getting_ownership(self->bridge->requirements_code, callback_str);
}

void private_CWebHyDrationSearchRequirements_add_elements_by_query_selector(
    CWebHyDrationSearchRequirements *self,
    const char *query_selector,bool auto_convert
){
    const char *auto_convert_str = "false";
    if(auto_convert){
        auto_convert_str = "true";
    }
    CWebHyDrationSearchRequirements_add_function(self,
        "function (args){\
            return private_cweb_get_elements({\
            query_selector:`%s`,\
            auto_convert:%s\
            })\
        }",
        query_selector,
        auto_convert_str
    );

}



void CWebHyDrationSearchRequirements_add_elements_by_query_selector(
    CWebHyDrationSearchRequirements *self,
    const char *query_selector,
    ...
){

    va_list  args;
    va_start(args,query_selector);
    char *formmated_query_selector = private_CWeb_format_vaarg(query_selector,args);
    va_end(args);

    private_CWebHyDrationSearchRequirements_add_elements_by_query_selector(
        self,
        formmated_query_selector,
        true
    );
    free(formmated_query_selector);
}




void CWebHyDrationSearchRequirements_add_elements_by_query_selector_not_auto_converting(
    CWebHyDrationSearchRequirements *self,const char *query_selector,...){

    va_list  args;
    va_start(args,query_selector);
    char *formmated_query_selector = private_CWeb_format_vaarg(query_selector,args);
    va_end(args);

    private_CWebHyDrationSearchRequirements_add_elements_by_query_selector(
        self,
        formmated_query_selector,
        false
    );
    free(formmated_query_selector);
}




void CWebHyDrationSearchRequirements_add_elements_by_attribute(
    CWebHyDrationSearchRequirements *self,
   const char *attribute,
   const char*attribute_value,
   ...
){

    va_list  args;
    va_start(args,attribute_value);
    char *formmated_attribute = private_CWeb_format_vaarg(attribute_value,args);
    va_end(args);

    CWebHyDrationSearchRequirements_add_elements_by_query_selector(
        self,
        "[%s='%s']",
        attribute,
        attribute_value
    );
    free(formmated_attribute);
}

void CWebHyDrationSearchRequirements_add_elements_by_attribute_not_auto_converting(
    CWebHyDrationSearchRequirements *self,
    const char *attribute,
    const char*attribute_value,
    ...
){

    va_list  args;
    va_start(args,attribute_value);
    char *formmated_attribute = private_CWeb_format_vaarg(attribute_value,args);
    va_end(args);

    CWebHyDrationSearchRequirements_add_elements_by_query_selector_not_auto_converting(
        self,
        "[%s='%s']",
        attribute,
        attribute_value
    );
    free(formmated_attribute);
}



void CWebHyDrationSearchRequirements_add_elements_by_class_name(
    CWebHyDrationSearchRequirements *self,
    const char*class_value,
    ...
){

    va_list  args;
    va_start(args,class_value);
    char *formmatted_class = private_CWeb_format_vaarg(class_value,args);
    va_end(args);

    CWebHyDrationSearchRequirements_add_elements_by_query_selector(
        self,
        "[class='%s']",
        formmatted_class
    );
    free(formmatted_class);
}

void CWebHyDrationSearchRequirements_add_elements_by_class_name_not_auto_converting(
    CWebHyDrationSearchRequirements *self,
    const char*class_value,...
){
    va_list  args;
    va_start(args,class_value);
    char *formmatted_class = private_CWeb_format_vaarg(class_value,args);
    va_end(args);

    CWebHyDrationSearchRequirements_add_elements_by_query_selector_not_auto_converting(
        self,
        "[class='%s']",
        formmatted_class
    );
    free(formmatted_class);
}


void CWebHyDrationSearchRequirements_add_elements_by_id(
    CWebHyDrationSearchRequirements *self,
    const char*id_values,
    ...
){

    va_list  args;
    va_start(args,id_values);
    char *formmated_id = private_CWeb_format_vaarg(id_values,args);
    va_end(args);

    CWebHyDrationSearchRequirements_add_elements_by_query_selector(
        self,
        "[id='%s']",
        formmated_id
    );
    free(formmated_id);
}

void CWebHyDrationSearchRequirements_add_elements_by_id_not_auto_converting(
    CWebHyDrationSearchRequirements *self,
    const char*id_values,
    ...
){

    va_list  args;
    va_start(args,id_values);
    char *formmated_id = private_CWeb_format_vaarg(id_values,args);
    va_end(args);

    CWebHyDrationSearchRequirements_add_elements_by_query_selector_not_auto_converting(
        self,
        "[id='%s']",
        formmated_id
    );
    free(formmated_id);
}

void CWebHyDrationSearchRequirements_add_session_storage_item_not_converting(
    CWebHyDrationSearchRequirements *self,
    const char *name,
    ...
){

    va_list  args;
    va_start(args,name);
    char *formmated_name = private_CWeb_format_vaarg(name,args);
    va_end(args);

    CWebHyDrationSearchRequirements_add_function(self,
        "function (args){\
            return private_cweb_get_session_storage_item({\
            name:`%s`,\
            auto_convert:false\
            })\
        }",
        formmated_name
    );
    free(formmated_name);
}


void CWebHyDrationSearchRequirements_add_session_storage_item(
    CWebHyDrationSearchRequirements *self,
    const char *name,
    ...
){

    va_list  args;
    va_start(args,name);
    char *formmated_name = private_CWeb_format_vaarg(name,args);
    va_end(args);

    CWebHyDrationSearchRequirements_add_function(self,
        "function (args){\
            return private_cweb_get_session_storage_item({\
            name:`%s`,\
            auto_convert:true\
            })\
        }",
        formmated_name
    );
    free(formmated_name);
}

void CWebHyDrationSearchRequirements_add_cookie_item(CWebHyDrationSearchRequirements *self, const char *name){
    
    CWebHyDrationSearchRequirements_add_function(self, 
        "\
        function(args){\
            return private_cweb_get_value_cookie_by_key(\"%s\")\
        }\
        ",
        name
    );
}

void CWebHyDrationSearchRequirements_add_confirm(CWebHyDrationSearchRequirements *self, const char *message, ...){

    va_list  args;
    va_start(args, message);
    char *formmated_name = private_CWeb_format_vaarg(message, args);
    va_end(args);

    CWebHyDrationSearchRequirements_add_function(self, 
        "\
        function(args){\
            let userConfirmed = confirm(\"%s\");\
            if (userConfirmed) {\
                return true;\
            } else {\
                return false;\
            }\
        }\
        ",
        formmated_name);

    free(formmated_name);
}

void CWebHyDrationSearchRequirements_add_prompt(CWebHyDrationSearchRequirements *self, const char *message, ...){

    va_list  args;
    va_start(args, message);
    char *formmated_name = private_CWeb_format_vaarg(message, args);
    va_end(args);

    CWebHyDrationSearchRequirements_add_function(self, 
        "\
        function(args){\
            let userConfirmed = prompt(%s);\
            if (userConfirmed) {\
                return userConfirmed;\
            } else {\
                return '';\
            }\
        }\
        ",
        formmated_name);

    free(formmated_name);
}



//path: src/functions/hydratation/search_result/search_result.c





CWebHyDrationSearchResult * private_newCWebHyDrationSearchResult(CWebHyDrationBridge *bridge,cJSON *search){

    CWebHyDrationSearchResult *self = (CWebHyDrationSearchResult*)malloc(sizeof(CWebHyDrationSearchResult));
    self->bridge = bridge;
    self->search = search;
    self->name = search->string;
    return  self;
}

void privateCWebHyDrationSearchResult_free(CWebHyDrationSearchResult *self){
    free(self);
}

int  CWebHyDrationSearchResult_get_total_itens(CWebHyDrationSearchResult *self){
    if(CWebHyDrationBridge_has_errors(self->bridge)){
        return -1;
    }

    return cJSON_GetArraySize(self->search);
}

bool  privateCWebHyDrationSearchResult_has_erorrs(CWebHyDrationSearchResult *self){
    if(self == NULL){
        return true;
    }
    if(CWebHyDrationBridge_has_errors(self->bridge)){
        return true;
    }
    return false;
}

bool  CWebHyDrationSearchResult_search_item_exist(CWebHyDrationSearchResult *self,int index){

    if(privateCWebHyDrationSearchResult_has_erorrs(self)){
        return false;
    }

    cJSON *item = cJSON_GetArrayItem(self->search, index);
   return item != NULL;
}



bool  CWebHyDrationSearchResult_is_search_item_number(CWebHyDrationSearchResult *self,int index){
    if(privateCWebHyDrationSearchResult_has_erorrs(self)){
        return false;
    }


    cJSON *item = cJSON_GetArrayItem(self->search, index);
    if(item == NULL){
        return false;
    }
   return cJSON_IsNumber(item);
}

bool  CWebHyDrationSearchResult_is_search_item_bool(CWebHyDrationSearchResult *self,int index){
    if(privateCWebHyDrationSearchResult_has_erorrs(self)){
        return false;
    }

    cJSON *item = cJSON_GetArrayItem(self->search, index);
    if(item == NULL){
        return false;
    }
   return cJSON_IsBool(item);
}




bool  CWebHyDrationSearchResult_is_search_item_string(CWebHyDrationSearchResult *self,int index){
    if(privateCWebHyDrationSearchResult_has_erorrs(self)){
        return false;
    }


    cJSON *item = cJSON_GetArrayItem(self->search, index);
    if(item == NULL){
        return false;
    }
   return cJSON_IsString(item);
}


cJSON * private_CWebHyDrationSearchResult_get_cJSON_item_verifying_type(

    CWebHyDrationSearchResult *self,
    int index,
    cJSON_bool (*callback_verifier)(const cJSON * const item),
    const char *expected_type
){
    if(privateCWebHyDrationSearchResult_has_erorrs(self)){
        return NULL;
    }


    cJSON *item  = cJSON_GetArrayItem(self->search,index);
    CWebHyDrationBridge *bridge = (CWebHyDrationBridge*)self->bridge;
    CWebHyDration *hydration = (CWebHyDration*)bridge->hydration;
    if(item == NULL){
        privateCWebHydration_raise_error(
            hydration,
            bridge,
            CWEB_HYDRATION_SEARCH_ITEM_NOT_EXIST,
            CWEB_HYDRATION_SEARCH_ITEM_NOT_EXIST_MSG,
            self->name,
            index
        );
        return NULL;
    }

    if(!callback_verifier(item)){
        privateCWebHydration_raise_error(
            hydration,
            bridge,
            CWEB_HYDRATION_SEARCH_ITEM_WRONG_TYPE,
            CWEB_HYDRATION_SEARCH_ITEM_WRONG_TYPE_MSG,
            self->name,
            index,
            expected_type
        );
        return NULL;
    }

    return item;
}

double CWebHyDrationSearchResult_get_double(CWebHyDrationSearchResult *self,int  index){
    if(privateCWebHyDrationSearchResult_has_erorrs(self)){
        return -1;
    }


    cJSON *item = private_CWebHyDrationSearchResult_get_cJSON_item_verifying_type(self,index,cJSON_IsNumber,CWEB_HYDRATION_NUMBER);
    if(item == NULL){
        return -1;
    }
    return cJSON_GetNumberValue(item);
}

long CWebHyDrationSearchResult_get_long(CWebHyDrationSearchResult *self,int  index){
    if(privateCWebHyDrationSearchResult_has_erorrs(self)){
        return -1;
    }

    cJSON *item = private_CWebHyDrationSearchResult_get_cJSON_item_verifying_type(
        self,index,cJSON_IsNumber,CWEB_HYDRATION_NUMBER);
    if(item == NULL){
        return -1;
    }
    return (long)cJSON_GetNumberValue(item);
}

bool CWebHyDrationSearchResult_get_bool(CWebHyDrationSearchResult *self,int  index){
    if(privateCWebHyDrationSearchResult_has_erorrs(self)){
        return false;
    }


    cJSON *item = private_CWebHyDrationSearchResult_get_cJSON_item_verifying_type(
        self,index,cJSON_IsBool,CWEB_HYDRATION_BOOL);
    if(item == NULL){
        return -1;
    }
    return (bool)item->valueint;
}


char*  CWebHyDrationSearchResult_get_string(CWebHyDrationSearchResult *self,int  index){
    if(privateCWebHyDrationSearchResult_has_erorrs(self)){
        return NULL;
    }


    cJSON *item = private_CWebHyDrationSearchResult_get_cJSON_item_verifying_type(
        self,index,cJSON_IsString,CWEB_HYDRATION_STRING);
    if(item == NULL){
        return NULL;
    }
    return cJSON_GetStringValue(item);
}

cJSON *  CWebHyDrationSearchResult_get_cJSON(CWebHyDrationSearchResult *self,int  index){
    if(privateCWebHyDrationSearchResult_has_erorrs(self)){
        return NULL;
    }


    cJSON *item = private_CWebHyDrationSearchResult_get_cJSON_item_verifying_type(
        self,index,NULL,NULL

    );
    return item;
}


//path: src/functions/hydratation/hydration/hydration.c




CWebHyDration *newCWebHyDration(CwebHttpRequest *request) {

    if(request->hydratation){
        return (CWebHyDration*)request->hydratation;
    }

    CWebHyDration *self = (CWebHyDration*)malloc(sizeof(CWebHyDration));
    *self = (CWebHyDration){0};
    self->all_bridges = private_new_privateCWebHyDrationBridgeArray();
    self->request =  request;
    self->response = cJSON_CreateArray();
    self->max_content_size = CWEB_HYDRATION_DEFAULT_BODY_SIZE;
    request->hydratation = (void *)self;

    return self;
}

CWebHyDrationBridge * CWebHyDration_get_child_bridge(CWebHyDration *self,const char *name){
    for(int i = 0; i < self->all_bridges->size;i++){
        CWebHyDrationBridge *current =  self->all_bridges->elments[i];
        if(strcmp(current->name,name) == 0){
            return  current;
        }
    }

    return CWebHyDration_create_bridge(self,name,NULL);
}


CTextStack  * CWebHyDration_create_stack(CWebHyDration *self){
    return CwebHttpRequest_create_stack(self->request);
}

CTextStack  * CWebHyDration_create_empty_stack(CWebHyDration *self){
    return CwebHttpRequest_create_empty_stack(self->request);

}


CWebHyDrationBridge * CWebHyDration_create_bridge(CWebHyDration *self,const char *name,void (*callback)(CWebHyDrationBridge *)){
    CWebHyDrationBridge *created = private_newCWebHyDrationBridge(name,callback,self);
    privateCWebHyDrationBridgeArray_append(self->all_bridges,created);
    return created;
}

bool CWebHyDration_is_the_trigger(CWebHyDration *self){
    if(strcmp(self->request->route,CWEB_HYDRATION_CALBACK_HANDLER_ROUTE) == 0){
        return true;
    }
    return false;
}

void privateCWebHydration_raise_error(CWebHyDration *self,CWebHyDrationBridge *bridge, int error_code, const char *format,...){
    va_list  args;
    va_start(args,format);
    self->error_msg = private_CWeb_format_vaarg(format,args);
    va_end(args);
    self->error_code = error_code;
    if(bridge){
        self->error_bridge_name = bridge->name;
    }
}


CwebHttpResponse *CWebHydration_generate_response(CWebHyDration *self){
    if(!CWebHyDration_is_the_trigger(self)){
        return NULL;
    }
    cJSON *body = CWebHttpRequest_read_cJSON(self->request, self->max_content_size);


    if(body ==NULL){
        privateCWebHydration_raise_error(
            self,
            NULL,
            CWEB_HYDRATION_NOT_BODY_JSON_PROVIDED,
            CWEB_HYDRATION_NOT_BODY_JSON_PROVIDED_MSG
        );
        return private_CWebHydration_formmat_error_response(self);
    }

    if(!cJSON_IsObject(body)){
        privateCWebHydration_raise_error(
            self,
            NULL,
            CWEB_HYDRATION_NOT_BODY_IS_NOT_OBJECT,
            CWEB_HYDRATION_NOT_BODY_IS_NOT_OBJECT_MSG
        );
        return private_CWebHydration_formmat_error_response(self);
    }

    cJSON *name = cJSON_GetObjectItem(body, CWEB_HYDRATON_JSON_NAME);


    if(name == NULL){
        privateCWebHydration_raise_error(
            self,
            NULL,
            CWEB_HYDRATION_NAME_NOT_PROVIDED,
            CWEB_HYDRATION_NAME_NOT_PROVIDED_MSG
        );
        return private_CWebHydration_formmat_error_response(self);
    }


    if(!cJSON_IsString(name)){
            privateCWebHydration_raise_error(
                self,
                NULL,
                CWEB_HYDRATION_NAME_NOT_STRING,
                CWEB_HYDRATION_NAME_NOT_STRING_MSG
            );
            return private_CWebHydration_formmat_error_response(self);
    }

    cJSON *args = cJSON_GetObjectItem(body, CWEB_HYDRATON_JSON_ARGS);
    if(args == NULL){
        privateCWebHydration_raise_error(
            self,
            NULL,
            CWEB_HYDRATION_ARGS_NOT_PROVIDED,
            CWEB_HYDRATION_ARGS_NOT_PROVIDED_MSG
        );
        return private_CWebHydration_formmat_error_response(self);
    }

    if(!cJSON_IsArray(args)){
        privateCWebHydration_raise_error(
            self,
            NULL,
            CWEB_HYDRATION_ARGS_NOT_ARRAY,
            CWEB_HYDRATION_ARGS_NOT_ARRAY_MSG
        );
        return private_CWebHydration_formmat_error_response(self);
    }

    cJSON *content = cJSON_GetObjectItem(body, CWEB_HYDRATON_JSON_CONTENT);

    if(content == NULL){
        privateCWebHydration_raise_error(
            self,
            NULL,
            CWEB_HYDRATION_CONTENT_NOT_PROVIDED,
            CWEB_HYDRATION_CONTENT_NOT_PROVIDED_MSG
        );
        return private_CWebHydration_formmat_error_response(self);
    }
    if(!cJSON_IsObject(content)){
        privateCWebHydration_raise_error(
            self,
            NULL,
            CWEB_HYDRATION_CONTENT_NOT_OBJECT,
            CWEB_HYDRATION_CONTENT_NOT_OBJECT_MSG
        );
        return private_CWebHydration_formmat_error_response(self);
    }

    int size =cJSON_GetArraySize(content);
    for(int i = 0; i < size;i++){
        cJSON *current_search  = cJSON_GetArrayItem(content, i);
        if(!cJSON_IsArray(current_search)){
            privateCWebHydration_raise_error(
                self,
                NULL,
                CWEB_HYDRATION_CONTENT_SEARCH_NOT_ARRAY,
                CWEB_HYDRATION_CONTENT_SEARCH_NOT_ARRAY_MSG,
                current_search->string
            );
            return private_CWebHydration_formmat_error_response(self);
        }
    }


    char *name_str = cJSON_GetStringValue(name);
    CWebHyDrationBridge *target_bridge = NULL;
    for(int i = 0; i < self->all_bridges->size;i++){
        CWebHyDrationBridge *current = self->all_bridges->elments[i];
        if(strcmp(current->name,name_str)==0){
                target_bridge = current;
                break;
        }
    }
    if(target_bridge == NULL){
        privateCWebHydration_raise_error(
            self,
            NULL,
            CWEB_BRIDGE_NOT_FOUND,
            CWEB_BRIDGE_NOT_FOUND_MSG,
            name_str
        );
        return private_CWebHydration_formmat_error_response(self);
    }

    self->args =args;
    self->content = content;
    target_bridge->callback(target_bridge);
    if(self->error_code){
        return private_CWebHydration_formmat_error_response(self);

    }
    CwebHttpResponse *final_response = cweb_send_cJSON_cleaning_memory(self->response, 200);
    self->response = NULL;
    return final_response;

}
CwebHttpResponse *private_CWebHydration_formmat_error_response(CWebHyDration *self){
    cJSON * response = cJSON_CreateObject();
    cJSON_AddStringToObject(response, CWEB_HYDRATION_JSON_ERROR_MENSSAGE,self->error_msg);
    cJSON_AddNumberToObject(response, CWEB_HYDRATION_JSON_ERROR_CODE_KEY,self->error_code);
    return cweb_send_cJSON_cleaning_memory(response, 404);
}

char *CWebHyDration_create_script(CWebHyDration *self) {

    if(self->script_text) {
        CTextStack_free(self->script_text);
    }

    self->script_text = newCTextStack_string_empty();

    CTextStack_format(self->script_text,"%s", private_cweb_hydration_js_content);

    for(int i =0; i < self->all_bridges->size;i++) {
        CWebHyDrationBridge *current = self->all_bridges->elments[i];
        CTextStack* created_code =private_CWebHyDrationBridge_create_script(current);
        CTextStack_format(self->script_text,"%tc",created_code);
    }
    return self->script_text->rendered_text;

}

void private_CWebHyDration_free(CWebHyDration *self) {
    if(self->script_text) {
        CTextStack_free(self->script_text);
    }
    if(self->error_msg){
        free(self->error_msg);
    }
    if(self->response){
        cJSON_Delete(self->response);
    }


    privateCWebHyDrationBridgeArray_free(self->all_bridges);
    free(self);
}









#endif