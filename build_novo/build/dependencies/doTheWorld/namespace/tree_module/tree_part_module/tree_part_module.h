

typedef struct DtwTreePartModule{

    DtwTreePart  *(*newPart)(const char *path, DtwTreeProps props);
    DtwTreePart  *(*newPartEmpty)(const char *path);
    DtwTreePart * (*newPartLoading)(const char *path);

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

    bool(*hardware_remove)(struct DtwTreePart *self, int transaction);
    bool(*hardware_write)(struct DtwTreePart *self, int transaction);
    bool(*hardware_modify)(struct DtwTreePart *self, int transaction);
    bool(*hardware_commit)(struct DtwTreePart *self);

    void (*free)(struct DtwTreePart *self);
    struct DtwTreePart *(*self_copy)(struct DtwTreePart *self);
}DtwTreePartModule;


DtwTreePartModule newDtwTreePartModule();