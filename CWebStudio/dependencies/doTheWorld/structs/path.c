

struct DtwPath * dtw_constructor_path( const char *path) {
    struct DtwPath *self = (struct DtwPath *)malloc(sizeof(struct DtwPath));

    self->dir = (char *)malloc(0);
    self->name = (char *)malloc(0);
    self->extension = (char *)malloc(0);
    self->dir_exists = false;
    self->name_exists = false;
    self->extension_exists = false;

    self->changed = private_dtw_path_changed;
    self->get_full_name =private_dtw_get_full_name;
    self->get_name = private_dtw_get_name;
    self->get_extension = private_dtw_get_extension;


    self->get_path = private_dtw_get_path;
    self->get_dir = private_dtw_get_dir;

    self->set_extension = private_dtw_set_extension;
    self->set_name = private_dtw_set_name;
    self->set_dir = private_dtw_set_dir;
    self->set_full_name = private_dtw_set_full_name;
    self->set_path = private_dtw_set_path;
    self->add_start_dir = private_dtw_add_start_dir;
    self->add_end_dir = private_dtw_add_end_dir;
    self->represent = private_dtw_represent_path;   
    self->free_path = private_dtw_destructor_path;

    self->set_path(self, path);
    self->original_path = self->get_path(self);
    
    return self;
}
bool private_dtw_path_changed(struct DtwPath *self){
    char *path = self->get_path(self);
    if(strcmp(self->original_path,path ) == 0){
        free(path);
        return false;
    }
    free(path);
    return true;
}


char * private_dtw_get_name(struct DtwPath *self){
    if(self->name_exists == false){
        return NULL;
    }
    char *name = (char *)malloc(strlen(self->name) + 1);
    strcpy(name, self->name);

    return name;
}
char * private_dtw_get_extension(struct DtwPath *self){
    if(self->extension_exists == false){
        return NULL;
    }
    char *extension = (char *)malloc(strlen(self->extension) + 1);
    strcpy(extension, self->extension);
    return extension;
}

char * private_dtw_get_full_name(struct DtwPath *self){

    if(self->name_exists == true &&  self->extension_exists == true){
        char *full_name = (char *)malloc(strlen(self->name) + strlen(self->extension) + 2);
        sprintf(full_name, "%s.%s",self->name, self->extension);
        return full_name;
    }

    if(self->name_exists == true &&  self->extension_exists == false){
        char *full_name = (char *)malloc(strlen(self->name) + 1);
        sprintf(full_name, "%s",self->name);
        return full_name;
    }
    
    if(self->name_exists == false &&  self->extension_exists == true){
        char *full_name = (char *)malloc(strlen(self->extension) + 1);
        sprintf(full_name, "%s",self->extension);
        return full_name;
    }    
    return NULL;
}

char * private_dtw_get_dir(struct DtwPath *self){
    if(self->dir_exists == false){
        return NULL;
    }
    char *dir = (char *)malloc(strlen(self->dir) + 1);
    strcpy(dir, self->dir);
    return dir;
}

char * private_dtw_get_path(struct DtwPath *self){
    //concat the path, name and extension with / 
    char *full_name = self->get_full_name(self);
    char *dir = self->get_dir(self);

    #define FULL_NAME_EXIST full_name != NULL
    #define FULL_NAME_NOT_EXIST full_name == NULL
    #define DIR_EXIST dir != NULL
    #define DIR_NOT_EXIST dir == NULL

    if(FULL_NAME_EXIST && DIR_EXIST){
        char *path = dtw_concat_path(dir, full_name);
        free(dir);
        free(full_name);
        return path;
    }
    if(FULL_NAME_EXIST && DIR_NOT_EXIST){
        char *path = (char *)malloc(strlen(full_name) + 1);
        sprintf(path, "%s",full_name);
        free(dir);
        free(full_name);
        return path;
    }
    if(FULL_NAME_NOT_EXIST && DIR_EXIST){
        char *path = dtw_concat_path(dir, "");
        free(dir);
        free(full_name);
        return path;
    }
    free(dir);
    free(full_name);
    return NULL;
}



void private_dtw_set_extension(struct DtwPath *self, const char *extension){
    if(strcmp(extension, "") == 0){
        return;
    }
    self->extension_exists = true;
    int extension_size = strlen(extension);
    self->extension = (char *)realloc(self->extension, extension_size+2);
    strcpy(self->extension, extension);
    self->extension[extension_size] = '\0';
}


void private_dtw_set_name(struct DtwPath * self, const char * name){
    if(strcmp(name, "") == 0){
        return;
    }
    self->name_exists = true;
    int name_size = strlen(name);
    self->name = (char *)realloc(self->name, name_size +1);
   
    strcpy(self->name, name);
    self->name[name_size] = '\0';
}



void private_dtw_set_full_name(struct DtwPath * self, const char * full_name){
    self->name_exists = false;
    self->extension_exists = false;

    int full_name_size = strlen(full_name);
    for(int i = 0; i < full_name_size; i++){
        if(full_name[i] == '.'){
            int name_size = i;
            int extension_size = full_name_size - i - 1;

            char *name = (char *)malloc(name_size + 1);
            strncpy(name, full_name, name_size);
            name[name_size] = '\0';
            self->set_name(self, name);
            free(name);

            char *extension = (char *)malloc(extension_size + 1);
            strncpy(extension, full_name + i + 1, extension_size);
            extension[extension_size] = '\0';
            self->set_extension(self, extension);
            free(extension);
            return;
        }
    }
    self->set_name(self, full_name);
}


void private_dtw_set_dir(struct DtwPath *self, const char *path){
    if(strcmp(path, "") == 0){
        return;
    }
    self->dir_exists = true;
    int path_size = strlen(path);
    self->dir = (char *)realloc(self->dir, path_size+1);
    strcpy(self->dir, path);
    self->dir[path_size] = '\0';
}

void private_dtw_set_path(struct DtwPath *self, const char *target_path) {
    self->dir_exists = false;
    self->name_exists = false;
    self->extension_exists = false;
    
    int path_size = strlen(target_path);
  
    for(int i = path_size - 1; i >= 0; i--){
        if(target_path[i] == '/' || target_path[i] == '\\'){
            
            char *path = (char *)malloc(i + 1);
            strncpy(path, target_path, i);
            path[i] = '\0';
            self->set_dir(self, path);
            free(path);

            char *full_name = (char *)malloc(path_size - i);
            strcpy(full_name, target_path + i + 1);
            full_name[path_size - i - 1] = '\0';
            self->set_full_name(self, full_name);
            free(full_name);
            return;
        }
    }

    self->set_full_name(self, target_path);
}

void private_dtw_add_start_dir(struct DtwPath *self, const char *start_dir){

    char *dir = self->get_dir(self);
    //concat the path, with start_dir at beguining
    if(dir != NULL){
        char *path = dtw_concat_path(start_dir, dir);
        self->set_dir(self, path);
        free(path);
        free(dir);
    }
}

void private_dtw_add_end_dir(struct DtwPath *self, const char *end_dir){
    char *dir = self->get_dir(self);
    //concat the path, with start_dir at beguining
    if(dir != NULL){
        char *path = dtw_concat_path(dir, end_dir);
        self->set_dir(self, path);
        free(path);
        free(dir);
    }
}

  

void private_dtw_represent_path(struct DtwPath *self){
    char  *path = self->get_path(self);
    char *full_name = self->get_full_name(self);
    char *dir = self->get_dir(self);
    char *name = self->get_name(self);
    char *extension = self->get_extension(self);
    bool changed = self->changed(self);
    printf("First Path: %s\n", self->original_path ? self->original_path : "NULL");
    printf("Path: %s\n", path  ? path : "NULL");
    printf("Path Changed: %s\n", changed ? "true" : "false");
    printf("Dir: %s\n", dir ? dir : "NULL");
    printf("Full Name: %s\n", full_name ? full_name : "NULL");
    printf("Name: %s\n", name ? name : "NULL");
    printf("Extension: %s\n", extension ? extension : "NULL");

    free(dir);
    free(name);
    free(extension);
    free(path);
    free(full_name);
    
}



void private_dtw_destructor_path(struct DtwPath *self) {
    free(self->original_path);
    free(self->dir);
    free(self->name);
    free(self->extension);
    free(self);
}

