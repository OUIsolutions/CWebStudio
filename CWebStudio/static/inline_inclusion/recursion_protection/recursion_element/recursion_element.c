


PrivateCwebRecursionElement * newPrivateCwebRecursionElement(const char *file,const char *included){
    PrivateCwebRecursionElement *self = (PrivateCwebRecursionElement*) malloc(sizeof (PrivateCwebRecursionElement));
    self->file = strdup(file);
    self->included = strdup(included);
}

void PrivateCwebRecursionElement_free(PrivateCwebRecursionElement *self){
    free(self->file);
    free(self->included);
    free(self);
}

