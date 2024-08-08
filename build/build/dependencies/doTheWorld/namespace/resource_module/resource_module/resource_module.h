
typedef struct DtwResourceModule{

    DtwResource *(*newResource)(const char *path);
    int (*get_error_code)(DtwResource *self);
    bool (*error)(DtwResource *self);

    char * (*get_error_message)(DtwResource *self);
    bool (*is_file)(DtwResource *self);
    void (*destroy_sub_resource)(DtwResource *self, const char *key);
    void (*rename_sub_resource)(DtwResource *self,const char *old_name,const  char *new_name);
    DtwResource * (*sub_resource)(struct DtwResource *self,const  char *format,...);
    unsigned char *(*get_any_from_sub_resource)(DtwResource *self, long *size, bool *is_binary,const char *format,...);
    unsigned char *(*get_binary_from_sub_resource)(DtwResource *self, long *size,const char *format,...);
    char *(*get_string_from_sub_resource)(DtwResource *self,const char *format,...);
    long (*get_long_from_sub_resource)(DtwResource *self,const char *format,...);
    double (*get_double_from_sub_resource)(DtwResource *self,const char *format,...);
    bool (*get_bool_from_sub_resource)(DtwResource *self,const char *format,...);
    void (*set_binary_in_sub_resource)(DtwResource *self,const char *key, unsigned char *element, long size);
    void (*set_string_in_sub_resource)(DtwResource *self,const char *key,const  char *element);
    void (*set_long_in_sub_resource)(DtwResource *self,const char *key,long element);
    void (*set_double_in_sub_resource)(DtwResource *self,const char *key,double element);
    void (*set_bool_in_sub_resource)( DtwResource *self,const char *key,bool element);
    void (*set_binary_sha)(DtwResource *self, unsigned  char *value, long size);
    void (*set_string_sha)(DtwResource *self,const char *value);

    void (*set_binary_sha_in_sub_resource)(DtwResource *self,const char *key, unsigned  char *value, long size);
    void (*set_string_sha_in_sub_resource)(DtwResource *self,const char *key,const char *value);



    DtwResource * (*new_schema_insertion)(DtwResource *self);
    DtwResource  *(*find_by_name_id)(DtwResource *self, const char *name);
    DtwResource * (*find_by_primary_key_with_binary)(DtwResource *self, const char *primary_key, unsigned  char *value, long size);
    DtwResource * (*find_by_primary_key_with_string)(DtwResource *self, const char *key, const char *value);
    void (*dangerous_remove_schema_prop)(DtwResource*self,const char *prop);
    void (*dangerous_rename_schema_prop)(DtwResource*self,const char *prop,const char *new_name);
    DtwSchema * (*newSchema_with_custom_folders)(DtwResource *self,const char *values_name,const char *index_name, const char *format, ...);
    DtwSchema * (*newSchema)(DtwResource *self);
    char * (*get_error_path)(DtwResource *self);
    DtwResourceArray * (*get_schema_values)(DtwResource *self);


    DtwResource * (*sub_resource_ensuring_not_exist)(DtwResource *self,const  char *format, ...);
    DtwResource * (*sub_resource_next)(DtwResource *self, const char *end_path);
    DtwResource * (*sub_resource_now)(DtwResource *self, const char *end_path);

    DtwResource * (*sub_resource_now_in_unix)(DtwResource *self,const char *end_path);
    DtwResource * (*sub_resource_random)(DtwResource *self,const char *end_path);


    void (*load)(DtwResource *self);

    void (*unload)(DtwResource *self);

    int (*lock)(DtwResource *self);
    void (*unlock)(DtwResource *self);

    void (*destroy)(DtwResource *self);
    void  (*clear_errors)(DtwResource *self);
    unsigned char *(*get_any)(struct DtwResource *self, long *size, bool *is_binary);

    unsigned char *(*get_binary)(struct DtwResource *self, long *size);

    char *(*get_string)(struct DtwResource *self);

    long (*get_long)(struct DtwResource *self);

    double (*get_double)(struct DtwResource *self);

    bool (*get_bool)(struct DtwResource *self);

    void (*set_binary)(DtwResource *self, unsigned char *element, long size);

    void (*set_string)(DtwResource *self,const  char *element);

    void (*set_long)(DtwResource *self,long element);

    void (*set_double)(DtwResource *self,double element);

    void (*set_bool)(DtwResource *self,bool element);



    DtwStringArray *(*list_names)(DtwResource *self);

    long (*size)(DtwResource *self);
    int (*type)(DtwResource *self);

    const char *(*type_in_str)(DtwResource *self);
    void (*commit)(DtwResource *self);

    void (*represent)(DtwResource *self);

    void (*rename)(DtwResource *self,const char *new_name);

    void (*free)(DtwResource *self);
    DtwResourceArray * (*sub_resources)(DtwResource *self);
    DtwResourceArrayModule array;


}DtwResourceModule;

DtwResourceModule newDtwResourceModule();