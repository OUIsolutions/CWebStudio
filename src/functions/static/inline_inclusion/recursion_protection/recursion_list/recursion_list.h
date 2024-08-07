#include "../uniq.declaration_requirements.h"




privateCwebRecursionList * newprivateCwebRecursionList();


privateCwebRecursionElement * privateCwebRecursionList_add_if_not_colide(privateCwebRecursionList *self,const char *file,const char *included);

void privateCwebRecursionList_represent(privateCwebRecursionList *self);

void privateCwebRecursionList_free(privateCwebRecursionList *self);
