

typedef struct DtwPathModule{
    //Getters

    DtwPath * (*newPath)(const char *path);
    bool  (*changed)(struct DtwPath *self);
    char *(*get_full_name) (struct DtwPath *self);
    char *(*get_name) (struct DtwPath *self);
    char *(*get_extension) (struct DtwPath *self);

    char *(*get_path) (struct DtwPath *self);
    char *(*get_dir) (struct DtwPath *self);

    int (*get_total_dirs)(DtwPath *self);
    char *(*get_sub_dirs_from_index)(DtwPath *self, int start,int end);
    void (*insert_dir_at_index)(DtwPath *self,int index,const char *dir);
    void (*remove_sub_dirs_at_index)(DtwPath *self,int start,int end);
    void (*insert_dir_after)(DtwPath *self,const char *str,const char *dir);
    void (*insert_dir_before)(DtwPath *self,const char *str,const char *dir);
    void (*replace_dirs)(DtwPath *self,const char *str,const char *dir);
    void (*remove_sub_dirs_at)(DtwPath *self,const char *str);


    //Setters
    void (*set_extension) (struct DtwPath *self, const char *extension);
    void (*set_name) (struct DtwPath *self, const char *name);
    void (*set_dir) (struct DtwPath *self, const char *path);
    void (*set_full_name) (struct DtwPath *self, const char *full_name);
    void (*set_path) (struct DtwPath *self, const char *target_path);
    
    void (*add_start_dir)(struct DtwPath *self, const char *start_dir);
    void (*add_end_dir)(struct DtwPath *self, const char *end_dir);

    void (*represent)(struct DtwPath *self);
    void (*free) (struct DtwPath *self);

}DtwPathModule;

DtwPathModule newDtwPathModule();