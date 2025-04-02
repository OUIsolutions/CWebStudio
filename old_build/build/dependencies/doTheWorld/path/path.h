
typedef struct DtwPath {
    char *original_path_string;
    char *path;
    DtwStringArray *garbage;


}DtwPath;
struct DtwPath * newDtwPath(const char *path);
bool  DtwPath_changed(DtwPath *self);

char *DtwPath_get_full_name(DtwPath *self);

char *DtwPath_get_name(DtwPath *self);

char *DtwPath_get_extension( DtwPath *self);

char *DtwPath_get_path(DtwPath *self);

char *DtwPath_get_dir(DtwPath *self);

void DtwPath_set_extension(DtwPath *self, const char *extension);

void DtwPath_set_name(DtwPath * self, const char * name);

void DtwPath_set_dir(DtwPath *self, const char *path);

void DtwPath_set_full_name(DtwPath * self, const char * full_name);

void DtwPath_set_path(DtwPath *self, const char *target_path);

void DtwPath_add_start_dir(DtwPath *self, const char *start_dir);

void DtwPath_add_end_dir(DtwPath *self, const char *end_dir);

void DtwPath_represent(DtwPath *self);

int DtwPath_get_total_dirs(DtwPath *self);

char *DtwPath_get_sub_dirs_from_index(DtwPath *self, int start, int end);

void DtwPath_insert_dir_at_index(DtwPath *self, int index, const char *dir);

void DtwPath_remove_sub_dirs_at_index(DtwPath *self, int start, int end);


int private_dtw_count_dirs_before(const char *dirs,int index);



void DtwPath_insert_dir_after(DtwPath *self,const char *str,const char *dir);

void DtwPath_insert_dir_before(DtwPath *self,const char *str,const char *dir);

void DtwPath_replace_dirs(DtwPath *self,const char *str,const char *dir);

void DtwPath_remove_sub_dirs_at(DtwPath *self,const char *str);

void DtwPath_free(DtwPath *self);


