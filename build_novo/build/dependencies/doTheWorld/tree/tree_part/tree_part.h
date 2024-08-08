

#define DTW_IS_BINARY true
#define DTW_IS_NOT_BINARY false
#define DTW_IGNORE true
#define DTW_NOT_IGNORE false

#define DTW_SET_AS_ACTION 1
#define DTW_EXECUTE_NOW 2

#define DTW_MODIFY 1
#define DTW_WRITE 2
#define DTW_REMOVE 3

typedef struct DtwTreePart{
    
    struct DtwPath *path;
    void *owner;
    size_t  hardware_content_size;
    long last_modification_time;
    bool content_exist_in_hardware;
    bool ignore;
    bool is_binary;
    bool metadata_loaded;
    char *current_sha;
    char * last_modification_in_str;
    char *hawdware_content_sha;

    unsigned char *content;
    int pending_action;

    size_t content_size;

}DtwTreePart;


char *DtwTreePart_get_content_string_by_reference(struct DtwTreePart *self);
unsigned char *DtwTreePart_get_content_binary_by_reference(struct DtwTreePart *self);
char *DtwTreePart_get_content_sha(struct DtwTreePart *self);
char *DtwTreePart_last_modification_time_in_string(struct DtwTreePart *self);
void DtwTreePart_set_any_content(struct DtwTreePart *self, unsigned char *content, int content_size, bool is_binary);
void DtwTreePart_set_string_content(struct DtwTreePart *self, const char *content);
void DtwTreePart_set_binary_content(struct DtwTreePart *self, unsigned char *content, int content_size);
void DtwTreePart_load_content_from_hardware(struct DtwTreePart *self);
void DtwTreePart_free_content(struct DtwTreePart *self);
void DtwTreePart_represent(struct DtwTreePart *self);

bool DtwTreePart_hardware_remove(struct DtwTreePart *self,int transaction);
bool DtwTreePart_hardware_write(struct DtwTreePart *self,int transaction);
bool DtwTreePart_hardware_modify(struct DtwTreePart *self,int transaction);


bool DtwTreePart_hardware_commit(struct DtwTreePart *self);

void DtwTreePart_free(struct DtwTreePart *self);
struct DtwTreePart * DtwTreePart_self_copy(struct DtwTreePart *self);

struct DtwTreePart * newDtwTreePart(const char *path, DtwTreeProps props);
struct DtwTreePart * newDtwTreePartEmpty(const char *path);
struct DtwTreePart * newDtwTreePartLoading(const char *path);
