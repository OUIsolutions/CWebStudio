
privateDtwFlockArray * private_new_privateFlockArray(){
    privateDtwFlockArray * self = (privateDtwFlockArray*) malloc(sizeof (privateDtwFlockArray));
    self->elements = (privateDtwFlockLockedElement **) malloc(0);
    self->size = 0;
    return self;
}


int  privateDtwFlockArray_index_of(privateDtwFlockArray *self, const char *filename){
    for(int i = 0 ; i <self->size;i++){
        privateDtwFlockLockedElement  *current = self->elements[i];
        if(strcmp(current->filename,filename) ==0){
            return  i;
        }
    }
    return  -1;
}
void privateDtwFlockArray_append(privateDtwFlockArray *self, const char *filename, int file_descriptor){

    self->elements = (privateDtwFlockLockedElement**) realloc(
            self->elements,
            sizeof(privateDtwFlockLockedElement**) * (self->size + 1)
            );
    privateDtwFlockLockedElement  *created = private_new_privateDtwFlockLockedElement(filename, file_descriptor);
    self->elements[self->size] = created;
    self->size+=1;
}

void privateDtwFlockArray_destroy_by_index(privateDtwFlockArray *self, int position){
    if(position >= self->size){
        return ;
    }
    privateDtwFlockLockedElement *finded = self->elements[position];
    privateDtwFlockLockedElement_free(finded);
    for(int i = position; i  < self->size-1; i++){
        self->elements[i] = self->elements[i+1];
    }
    self->size-=1;
}


void privateDtwFlockArray_represent(privateDtwFlockArray *self){
    for(int i = 0 ; i <self->size;i++){

        privateDtwFlockLockedElement  *current = self->elements[i];
        printf("=============================\n");
        privateDtwFlockLockedElement_represent(current);
    }
}

void privateDtwFlockArray_free(privateDtwFlockArray *self){
    for(int i = 0 ; i <self->size;i++){
        privateDtwFlockLockedElement  *current = self->elements[i];
        privateDtwFlockLockedElement_free(current);
    }
    free(self->elements);
    free(self);
}