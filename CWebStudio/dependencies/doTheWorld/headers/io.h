
#define DTW_FILE_TYPE 1
#define DTW_FOLDER_TYPE 2
#define DTW_ALL_TYPE 3
#define DTW_NOT_FOUND -1
#define DTW_MERGE true 
#define DTW_NOT_MERGE false
#ifdef __linux__
#define dtw_create_dir(path) mkdir(path,0777)
#elif _WIN32
#define dtw_create_dir(path) _mkdir(path)
#endif

void dtw_create_dir_recursively(const char *path);

void dtw_remove_any(const char* path);

char *dtw_get_current_dir();


unsigned char *dtw_load_any_content(const char * path,int *size,bool *is_binary);
char *dtw_load_string_file_content(const char * path);

unsigned char *dtw_load_binary_content(const char * path,int *size);


bool dtw_write_any_content(const char *path,unsigned  char *content,int size);
bool dtw_write_string_file_content(const char *path,const char *content);
int dtw_entity_type(const char *path);

#ifdef __cplusplus
    bool dtw_copy_any(const char* src_path,const  char* dest_path,bool merge=false);
#else
    bool dtw_copy_any(const char* src_path,const  char* dest_path,bool merge);
#endif 

void dtw_move_any(const char* src_path, const char* dest_path,bool merge);