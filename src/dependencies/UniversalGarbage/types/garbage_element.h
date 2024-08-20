
#ifndef PRIVATE_UNIVERSGAL_GARBAGE_ELEMENT_TYPE
#define PRIVATE_UNIVERSGAL_GARBAGE_ELEMENT_TYPE
typedef struct privateUniversalGarbageElement{
    void **pointer;
    void (*deallocator_callback)(void *element);
    void *pointed_value;
}privateUniversalGarbageElement;
#endif
