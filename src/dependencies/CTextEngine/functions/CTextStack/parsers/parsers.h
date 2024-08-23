#include "../unique.declaration_requirements.h"

int CTextStack_typeof(struct CTextStack *self);

bool CTextStack_is_a_num(struct CTextStack *self);

const char * CTextStack_typeof_in_str(struct CTextStack *self);

bool  CTextStack_parse_to_bool(struct CTextStack *self);

long  CTextStack_parse_to_integer(struct CTextStack *self);

double  CTextStack_parse_to_double(struct CTextStack *self);
