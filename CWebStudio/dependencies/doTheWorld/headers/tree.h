
#define DTW_NOT_MINIFY  false
#define DTW_MINIFY  true
#define DTW_NOT_PRESERVE_PATH_ATRIBUTES  false
#define DTW_PRESERVE_PATH_ATRIBUTES  true
#define DTW_NOT_PRESERVE_HARDWARE_DATA  false
#define DTW_PRESERVE_HARDWARE_DATA  true
#define DTW_NOT_PRESERVE_CONTENT_DATA  false
#define DTW_PRESERVE_CONTENT_DATA  true
#define DTW_COPY_CONTENT  true 
#define DTW_PASS_BY_REFERENCE  false
#define DTW_CONSIDER_IGNORE  true
#define DTW_NOT_CONSIDER_IGNORE  false

struct  DtwTree{
    int size;
    struct DtwTreePart **tree_parts;
    void (*add_tree_part_by_copy)(
        struct DtwTree *self,
         struct DtwTreePart *tree_part
    );
    void (*add_tree_part_by_reference)(
        struct DtwTree *self,
        struct DtwTreePart *tree_part
    );
    void (*add_tree_parts_from_string_array)(
        struct DtwTree *self,
        struct DtwStringArray *paths,
        bool load_content,
        bool preserve_content
    );
    
    struct DtwTree *(*get_sub_tree)(
        struct DtwTree *self,
        const char *path,
        bool copy_content
    );

    void (*add_tree_from_hardware)(
        struct DtwTree *self,
        const char *path,
        bool load_content,
        bool preserve_content
    );
    struct DtwTransactionReport * (*report)(struct DtwTree *self);    
    //{%if not  lite %}

    void (*loads_json_tree)(
        struct DtwTree *self,
        const char *content
    );

    void (*loads_json_tree_from_file)(
        struct DtwTree *self,
        const char *path
    );

    char *(*dumps_json_tree)(
        struct DtwTree *self,
        bool minify,
        bool preserve_content,
        bool preserve_path_atributes,
        bool preserve_hadware_data,
        bool preserve_content_data,
        bool consider_igonore
    ); 
    
    void (*dumps_json_tree_to_file)(
        struct DtwTree *self,
        const char *path,
        bool minify,
        bool preserve_content,
        bool preserve_path_atributes,
        bool preserve_hadware_data,
        bool preserve_content_data,
        bool consider_igonore
    );

    //{%endif%}
    void (*free_tree)(struct DtwTree *self);
    void (*represent)(struct DtwTree *self);
    void (*insecure_hardware_remove_tree)(struct DtwTree *self);
    void (*insecure_hardware_write_tree)(struct DtwTree *self);
    void (*hardware_commit_tree)(struct DtwTree *self);
};

#ifdef __cplusplus
struct DtwTree *private_dtw_get_sub_tree(
    struct DtwTree *self,
    const char *path,
    bool copy_content=false
);
#else 
struct DtwTree *private_dtw_get_sub_tree(
    struct DtwTree *self,
    const char *path,
    bool copy_content
);
#endif
void private_dtw_add_tree_part_copy(struct DtwTree *self, struct DtwTreePart *tree_part);
void private_dtw_add_tree_part_reference(struct DtwTree *self, struct DtwTreePart *tree_part);
void private_dtw_free_tree(struct DtwTree *self);
void private_dtw_represent_tree(struct DtwTree *self);
void private_dtw_add_tree_parts_from_string_array(
    struct DtwTree *self,
    struct DtwStringArray *paths,
    bool load_content,
    bool preserve_content
);
void private_dtw_add_tree_from_hardware(
    struct DtwTree *self,
    const char *path,
    bool load_content,
    bool preserve_content
);

struct DtwTransactionReport * private_dtw_create_report(struct DtwTree *self);


void private_insecure_dtw_hardware_remove_tree(struct DtwTree *self);
void private_insecure_dtw_hardware_write_tree(struct DtwTree *self);
void private_dtw_hardware_commit_tree(struct DtwTree *self);

//{%if not  lite %}
void private_dtw_loads_json_tree(struct DtwTree *self,const char *content);
void private_dtw_loads_json_tree_from_file(struct DtwTree *self,const char *path);

#ifdef __cplusplus
char * private_dtw_dumps_tree_json(
    struct DtwTree *self,
    bool minify=false,
    bool preserve_content=true,
    bool preserve_path_atributes=true,
    bool preserve_hadware_data=false,
    bool preserve_content_data=true,
    bool consider_igonore=false
    );
void private_dtw_dumps_tree_json_to_file(
    struct DtwTree *self,
    const char *path,
    bool minify=false,
    bool preserve_content=true,
    bool preserve_path_atributes=true,
    bool preserve_hadware_data=false,
    bool preserve_content_data=true,
    bool consider_igonore=false
    );
#else 
char * private_dtw_dumps_tree_json(
    struct DtwTree *self,
    bool minify,
    bool preserve_content,
    bool preserve_path_atributes,
    bool preserve_hadware_data,
    bool preserve_content_data,
    bool consider_igonore
    );
void private_dtw_dumps_tree_json_to_file(
    struct DtwTree *self,
    const char *path,
    bool minify,
    bool preserve_content,
    bool preserve_path_atributes,
    bool preserve_hadware_data,
    bool preserve_content_data,
    bool consider_igonore
    );
#endif
//{%endif%}
struct  DtwTree * dtw_tree_constructor();

