
typedef struct DtwNamespace{
    //IO
    void (*create_dir_recursively)(const char *path);

    bool (*remove_any)(const char* path);

    char *(*get_current_dir)();

    unsigned char *(*load_any_content)(const char * path,long *size,bool *is_binary);

    char *(*load_string_file_content)(const char * path);

    unsigned char *(*load_binary_content)(const char * path,long *size);
    
    bool (*write_any_content)(const char *path,unsigned  char *content,long size);

    bool (*write_string_file_content)(const char *path,const char *content);

    int (*entity_type)(const char *path);

    int (*complex_entity_type)(const char *path);

    const char *(*convert_entity)(int entity_type);

    bool (*copy_any)(const char* src_path,const  char* dest_path,bool merge);

    bool (*move_any)(const char* src_path, const char* dest_path,bool merge);

    //numeral io

    long (*load_long_file_content)(const char * path);

    double (*load_double_file_content)(const char * path);

    bool (*load_bool_file_content)(const char * path);



    void (*write_long_file_content)(const char *path, long value);

    void (*write_bool_file_content)(const char *path, bool value);

    void (*write_double_file_content)(const char *path,double value);



    //listage

    DtwStringArray * (*list_files)(const char *path, bool concat_path);
    DtwStringArray * (*list_dirs)(const char *path, bool concat_path);

    DtwStringArray *  (*list_all)(const char *path,  bool concat_path);
    DtwStringArray * (*list_dirs_recursively)(const char *path,bool concat_path);
    DtwStringArray *  (*list_files_recursively)(const char *path,bool concat_path);
    DtwStringArray * (*list_all_recursively)(const char *path,bool concat_path);


    //extras

    char * (*generate_sha_from_file)(const char *path);

    char * (*generate_sha_from_string)(const char *string);

    char * (*generate_sha_from_any)(void *anything , long size);

    long int (*get_entity_last_motification_in_unix)(const char *path);

    char * (*convert_unix_time_to_string)(long int unix_time);

    char * (*get_entity_last_motification_in_string)(const char *path);

    char *(*concat_path)(const char *path1, const char *path2);


    //base64

    char *(*base64_encode)(unsigned char *data, long input_length);

    unsigned char *(*base64_decode)(const char *data, long *output_length);

    char *(*convert_binary_file_to_base64)(const char *path);
    //string array

    DtwStringArrayModule string_array;

    DtwPathModule path;

    DtwLockerModule locker;

    DtwSchemaModule schema;
    DtwTreeModule tree;
    DtwHashModule  hash;
    DtwTransactionModule transaction;

    DtwResourceModule resource;
    DtwRandonizerModule randonizer;

}DtwNamespace;

DtwNamespace newDtwNamespace();