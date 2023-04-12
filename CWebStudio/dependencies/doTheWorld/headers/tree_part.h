
#define DTW_LOAD_CONTENT  true
#define DTW_NOT_LOAD_CONTENT  false 
#define DTW_NOT_PRESERVE_CONTENT  false
#define DTW_PRESERVE_CONTENT  true

#define DTW_IS_BINARY true
#define DTW_IS_NOT_BINARY false
#define DTW_IGNORE true
#define DTW_NOT_IGNORE false

#define DTW_SET_AS_ACTION true
#define DTW_EXECUTE_NOW false

#define DTW_MODIFY 1
#define DTW_WRITE 2
#define DTW_REMOVE 3

struct DtwTreePart{
    
    struct DtwPath *path;
    bool content_exist_in_memory;
    size_t  hardware_content_size; 
    long last_modification_time;
    bool content_exist_in_hardware;
    bool ignore;
    bool is_binary;
    char *hawdware_content_sha;
    unsigned char *content;
    int pending_action;

    size_t content_size;
    char *(*get_content_string_by_reference)(struct DtwTreePart *self);
    unsigned char *(*get_content_binary_by_reference)(struct DtwTreePart *self);

    char *(*get_content_sha)(struct DtwTreePart *self);
    char *(*last_modification_time_in_string)(struct DtwTreePart *self);
    void (*set_any_content)(struct DtwTreePart *self,unsigned char *content,int content_size,bool is_binary);
    void (*set_string_content)(struct DtwTreePart *self,const char *content);
    void (*set_binary_content)(struct DtwTreePart *self,unsigned char *content,int content_size);
    void (*load_content_from_hardware)(struct DtwTreePart *self);
    void (*free_content)(struct DtwTreePart *self);
    void(*represent)(struct DtwTreePart *self);
    
    bool(*hardware_remove)(struct DtwTreePart *self,bool set_as_action);
    bool(*hardware_write)(struct DtwTreePart *self,bool set_as_action);
    bool(*hardware_modify)(struct DtwTreePart *self,bool set_as_action);
    bool(*hardware_commit)(struct DtwTreePart *self);


    void (*free_tree_part)(struct DtwTreePart *self);
    struct DtwTreePart *(*copy_tree_part)(struct DtwTreePart *self);
};

char *private_dtw_get_content_string_by_reference(struct DtwTreePart *self);
unsigned char *private_dtw_get_content_binary_by_reference(struct DtwTreePart *self);
char *private_dtw_get_content_sha(struct DtwTreePart *self);
char *private_dtw_last_modification_time_in_string(struct DtwTreePart *self);
void private_dtw_set_any_content(struct DtwTreePart *self,unsigned char *content,int content_size,bool is_binary);
void private_dtw_set_string_content(struct DtwTreePart *self,const char *content);
void private_dtw_set_binary_content(struct DtwTreePart *self,unsigned char *content,int content_size);
void private_dtw_load_content_from_hardware(struct DtwTreePart *self);
void private_dtw_free_content(struct DtwTreePart *self);
void private_dtw_represent_tree_part(struct DtwTreePart *self);
#ifdef __cplusplus
bool private_dtw_hardware_remove(struct DtwTreePart *self,bool set_as_action=true);
bool private_dtw_hardware_write(struct DtwTreePart *self,bool set_as_action=true);
bool private_dtw_hardware_modify(struct DtwTreePart *self,bool set_as_action=true);
#else
bool private_dtw_hardware_remove(struct DtwTreePart *self,bool set_as_action);
bool private_dtw_hardware_write(struct DtwTreePart *self,bool set_as_action);
bool private_dtw_hardware_modify(struct DtwTreePart *self,bool set_as_action);
#endif

bool private_dtw_hardware_commit(struct DtwTreePart *self);

void private_dtw_tree_part_destructor(struct DtwTreePart *self);
struct DtwTreePart * private_dtw_copy_tree(struct DtwTreePart *self);

struct DtwTreePart * dtw_tree_part_constructor(const char *path,bool load_content,bool preserve_content);