

privateCwebRecursionList * newprivateCwebRecursionList(){
    privateCwebRecursionList *self = (privateCwebRecursionList*)malloc(sizeof(privateCwebRecursionList));
    *self = (privateCwebRecursionList){0};
    self->elements = (privateCwebRecursionElement **)malloc(0);
    return self;
}


privateCwebRecursionElement *
privateCwebRecursionList_add_if_not_colide(privateCwebRecursionList *self,const char *file,const char *included){
    for(int i = 0; i < self->size;i++){

        privateCwebRecursionElement *possible_colision = self->elements[i];
        bool not_included = strcmp(file,possible_colision->included) != 0;

        if(not_included){
            continue;
        }
        bool including = strcmp(included,possible_colision->file) == 0;
        if(including){
            return possible_colision;
        }
    }

    self->elements = (privateCwebRecursionElement **) realloc(
            self->elements,
            (self->size +1) * sizeof(privateCwebRecursionList*)
     );
    self->elements[self->size] = newPrivateCwebRecursionElement(file,included);
    self->size+=1;
    return NULL;
}
void privateCwebRecursionList_represent(privateCwebRecursionList *self){
       for(int i =0; i < self->size; i++){
        PrivateCwebRecursionElement_represent(self->elements[i]);
    }
}
void privateCwebRecursionList_free(privateCwebRecursionList *self){
    for(int i =0; i < self->size; i++){
        PrivateCwebRecursionElement_free(self->elements[i]);
    }
    free(self->elements);
    free(self);
}
