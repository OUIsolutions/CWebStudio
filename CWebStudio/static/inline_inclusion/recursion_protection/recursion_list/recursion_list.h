
typedef struct{

    privateCwebRecursionElement **elements;
    int size;

}privateCwebRecursionList;


privateCwebRecursionList * newprivateCwebRecursionList();


privateCwebRecursionElement *
privateCwebRecursionList_add_if_not_colide(privateCwebRecursionList *self,const char *file,const char *included);

void privateCwebRecursionList_free(privateCwebRecursionList *self);


