

void DtwPath_set_extension(struct DtwPath *self, const char *extension);


void DtwPath_set_name(struct DtwPath * self, const char * name);


void DtwPath_set_full_name(struct DtwPath * self, const char * full_name);


void DtwPath_set_dir(struct DtwPath *self, const char *dir);



void DtwPath_set_path(struct DtwPath *self, const char *target_path);


void DtwPath_add_start_dir(struct DtwPath *self, const char *start_dir);


void DtwPath_add_end_dir(struct DtwPath *self, const char *end_dir);


void DtwPath_replace_dirs(DtwPath *self,const char *str,const char *dir);
