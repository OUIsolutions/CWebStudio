


privateCwebRecursionElement * newPrivateCwebRecursionElement(const char *file, const char *included){
    privateCwebRecursionElement *self = (privateCwebRecursionElement*) malloc(sizeof (privateCwebRecursionElement));
    self->file = strdup(file);
    self->included = strdup(included);
    return self;
}

void PrivateCwebRecursionElement_free(privateCwebRecursionElement *self){
    free(self->file);
    free(self->included);
    free(self);
}

