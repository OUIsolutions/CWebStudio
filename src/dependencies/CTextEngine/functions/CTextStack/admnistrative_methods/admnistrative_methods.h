


#include "../unique.declaration_requirements.h"




char * CTextStack_self_transform_in_string_and_self_clear(struct CTextStack *self);

void private_CTextStack_parse_ownership(struct CTextStack *self, struct CTextStack *new_stack);

void CTextStack_restart(struct CTextStack *self);

void CTextStack_represent(struct CTextStack *self);

void CTextStack_free(struct CTextStack *self);

 CTextStack * CTextStack_clone(struct CTextStack *self);
