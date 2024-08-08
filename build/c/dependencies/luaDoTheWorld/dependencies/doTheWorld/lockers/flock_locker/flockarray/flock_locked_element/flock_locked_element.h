
typedef struct {

    char *filename;
    int file_descriptor;


}privateDtwFlockLockedElement;

privateDtwFlockLockedElement * private_new_privateDtwFlockLockedElement(const char *filename, int file_descriptor);

void privateDtwFlockLockedElement_represent(privateDtwFlockLockedElement *self);

void privateDtwFlockLockedElement_free(privateDtwFlockLockedElement *self);