
typedef struct {
    char  *file;
    char *included;

}privateCwebRecursionElement;

privateCwebRecursionElement * newPrivateCwebRecursionElement(const char *file, const char *included);

void PrivateCwebRecursionElement_free(privateCwebRecursionElement *self);
