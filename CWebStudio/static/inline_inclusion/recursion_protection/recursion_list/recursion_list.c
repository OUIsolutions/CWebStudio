

privateCwebRecursionList * newprivateCwebRecursionList(){
    privateCwebRecursionList *self = (privateCwebRecursionList*)malloc(sizeof(privateCwebRecursionList));
    *self = (privateCwebRecursionList){0};
    self->elements = (privateCwebRecursionList**)malloc(0);

}


bool privateCwebRecursionList_add_if_not_colide(privateCwebRecursionList *self,const char *file,const char *included){
    for(int i = 0; i < self->size;i++){

        privateCwebRecursionElement *possible_colision = self->elements[i];
        bool not_included = strcmp(file,possible_colision->included) != 0;
        if(not_included){
            continue;
        }
        bool including = strcmp(included,possible_colision->file);
        if(including){
            return true;
        }
    }

    self->elements = (privateCwebRecursionList**) realloc(
            self->elements,
            (self->size +1) * sizeof(privateCwebRecursionList*)
     );
    self->elements[self->size] = newPrivateCwebRecursionElement(file,included);
    self->size+=1;
    return false;
}

void privateCwebRecursionList_free(privateCwebRecursionList *self){
    for(int i =0; i < self->size; i++){
        PrivateCwebRecursionElement_free(self->elements[i]);
    }
    free(self->elements);
    free(self);
}

