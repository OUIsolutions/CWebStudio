

#include "../unique.declaration_requirements.h"

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
