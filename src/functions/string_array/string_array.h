#include "../uniq.declaration_requirements.h"

CwebStringArray * newCwebStringArray();

int  CwebStringArray_find(struct CwebStringArray *self, const char *string);
void CwebStringArray_add(struct CwebStringArray *self, const char *string);

void CwebStringArray_add_getting_ownership(struct CwebStringArray *self, char *string);

void CwebStringArray_merge(struct CwebStringArray *self, struct CwebStringArray *other);
void CwebStringArray_represent(struct CwebStringArray *self);
void CwebStringArray_free(struct CwebStringArray *self);
void CwebStringArray_set(struct CwebStringArray *self, int index, const char *value);
