
#include "../unique.definition_requirements.h"


privateUniversalGarbageElement * private_newUniversalGarbageSimpleElement(void (*dealocator_callback)(void *element), void **pointer){

    privateUniversalGarbageElement * self = UniversalGarbage_create_empty_struct(
        self,
        privateUniversalGarbageElement
    );
    self->pointer = pointer;
    self->deallocator_callback = dealocator_callback;
    self->pointed_value = *pointer;
    return  self;
}
void private_UniversalGarbageSimpleElement_free_pointed_value(privateUniversalGarbageElement *self){
    if(self->pointed_value){
        self->deallocator_callback(self->pointed_value);
        self->pointed_value = NULL;
    }
}

void private_UniversalGarbageSimpleElement_free(privateUniversalGarbageElement *self){
    private_UniversalGarbageSimpleElement_free_pointed_value(self);
    free(self);
}
