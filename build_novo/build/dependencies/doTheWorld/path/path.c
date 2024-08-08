

struct DtwPath * newDtwPath(const char *path) {
    struct DtwPath *self = (struct DtwPath *)malloc(sizeof(struct DtwPath));
    self->garbage = newDtwStringArray();
    self->path = private_dtw_format_path(path);
    self->original_path_string = strdup(self->path);


    return self;
}
bool DtwPath_changed(struct DtwPath *self){
    return strcmp(self->path,self->original_path_string) != 0;
}




void DtwPath_represent(struct DtwPath *self){
    char  *path = DtwPath_get_path(self);
    char *full_name = DtwPath_get_full_name(self);
    char *dir = DtwPath_get_dir(self);
    char *name = DtwPath_get_name(self);
    char *extension = DtwPath_get_extension(self);
    bool changed = DtwPath_changed(self);

    printf("First Path: %s\n", self->original_path_string ? self->original_path_string : "NULL");
    printf("Path: %s\n", path  ? path : "NULL");
    printf("Path Changed: %s\n", changed ? "true" : "false");
    printf("Dir: %s\n", dir ? dir : "NULL");
    printf("Full Name: %s\n", full_name ? full_name : "NULL");
    printf("Name: %s\n", name ? name : "NULL");
    printf("Extension: %s\n", extension ? extension : "NULL");

    
}



void DtwPath_free(struct DtwPath *self) {
    DtwStringArray_free(self->garbage);
    free(self->original_path_string);
    free(self->path);
    free(self);
}

