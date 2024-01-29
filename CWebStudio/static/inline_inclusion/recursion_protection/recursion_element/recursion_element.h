
typedef struct {
    char  *file;
    char *included;

}PrivateCwebRecursionElement;

PrivateCwebRecursionElement * newPrivateCwebRecursionElement(const char *file,const char *included);

void PrivateCwebRecursionElement_free(PrivateCwebRecursionElement *self);
