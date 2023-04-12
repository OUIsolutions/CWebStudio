


struct DtwTreePart * dtw_tree_part_constructor(const char *path,bool load_content,bool preserve_content){
    struct DtwTreePart *self = (struct DtwTreePart *)malloc(sizeof(struct DtwTreePart));
    self->path = dtw_constructor_path(path);
    self->content_exist_in_memory = false;
    self->content_exist_in_hardware = false;
    self->is_binary = false;
    self->ignore = false;
    self->pending_action = 0;
    self->hawdware_content_sha = (char *)malloc(0);
    self->content = (unsigned char *)malloc(0);
    self->content_size = 0;
    self->hardware_content_size = 0;
    self->get_content_string_by_reference = private_dtw_get_content_string_by_reference;
    self->get_content_binary_by_reference = private_dtw_get_content_binary_by_reference;
    self->load_content_from_hardware = private_dtw_load_content_from_hardware;
    self->set_any_content = private_dtw_set_any_content;
    self->set_string_content = private_dtw_set_string_content;
    self->set_binary_content = private_dtw_set_binary_content;
    self->get_content_sha = private_dtw_get_content_sha;
    self->last_modification_time_in_string = private_dtw_last_modification_time_in_string;
    self->free_content = private_dtw_free_content;
    self->represent = private_dtw_represent_tree_part;
    self->hardware_remove = private_dtw_hardware_remove;
    self->hardware_write = private_dtw_hardware_write;
    self->hardware_modify = private_dtw_hardware_modify;
    self->hardware_commit = private_dtw_hardware_commit;
    self->free_tree_part = private_dtw_tree_part_destructor;
    self->copy_tree_part = private_dtw_copy_tree;
    if(load_content){
        
        self->load_content_from_hardware(self);
        if(preserve_content == false){
            self->free_content(self);
        }
    }
    return self;
}
char *private_dtw_get_content_string_by_reference(struct DtwTreePart *self){
    if(self->content_exist_in_memory == true){
        return (char *)self->content;
    }
    return NULL;
}

unsigned char *private_dtw_get_content_binary_by_reference(struct DtwTreePart *self){
    if(self->content_exist_in_memory == true){
        return self->content;
    }
    return NULL;
}


struct  DtwTreePart * private_dtw_copy_tree(struct DtwTreePart *self){
    char *path = self->path->get_path(self->path);

    struct DtwTreePart *new_tree_part = dtw_tree_part_constructor(path,false,false);
    free(path);

    new_tree_part->content_exist_in_memory = self->content_exist_in_memory;
    new_tree_part->content_exist_in_hardware = self->content_exist_in_hardware;
    new_tree_part->is_binary = self->is_binary;
    new_tree_part->ignore = self->ignore;
    new_tree_part->content_size = self->content_size;
    

    new_tree_part->hawdware_content_sha = (char *)malloc(strlen(self->hawdware_content_sha)+1);
    
    strcpy(new_tree_part->hawdware_content_sha,self->hawdware_content_sha);
    new_tree_part->content = (unsigned char *)malloc(self->content_size);
    
    if(new_tree_part->is_binary == false){
            new_tree_part->content[self->content_size] = '\0';    
    }
    
    memcpy(new_tree_part->content,self->content,self->content_size);

    
    return new_tree_part;
}

void private_dtw_set_any_content(struct DtwTreePart *self,unsigned char *content,int content_size,bool is_binary){

    self->free_content(self);
    self->content_exist_in_memory = true;
    self->is_binary = is_binary;
    self->content = (unsigned char *)realloc(self->content,content_size+2);
    memcpy(self->content,content,content_size);
    self->content_size = content_size;


}

void private_dtw_set_string_content(struct DtwTreePart *self,const char *content){
    self->set_any_content(
        self,
        (unsigned char*)content,
        strlen(content),
        false
    );
    
    self->content[self->content_size] = '\0';
}

void private_dtw_set_binary_content(struct DtwTreePart *self,unsigned char *content,int content_size){
    self->set_any_content(self,content,content_size,true);
}


char *private_dtw_get_content_sha(struct DtwTreePart *self){
    if(self->content_exist_in_memory){
        return dtw_generate_sha_from_string((char *)self->content);
    }
    return NULL;
}

char *private_dtw_last_modification_time_in_string(struct DtwTreePart *self){
    return dtw_convert_unix_time_to_string(self->last_modification_time);
}



void private_dtw_represent_tree_part(struct DtwTreePart *self){
    char *path = self->path->get_path(self->path);
    printf("------------------------------------------------------------\n");
    self->path->represent(self->path);
    printf("Content Exist in Memory: %s\n",self->content_exist_in_memory ? "true" : "false");
    printf("Ignore: %s\n",self->ignore ? "true" : "false");
    
    if(self->content_exist_in_memory == true || self->content_exist_in_hardware == true){
        
        char *last_moditication_in_string = self->last_modification_time_in_string(self);

        printf("Content Exist In Hardware: %s\n",self->content_exist_in_hardware ? "true" : "false");
        printf("Is Binary: %s\n",self->is_binary ? "true" : "false");
   
        
        printf("Content Size: %li\n",self->content_size);
        if(self->content_exist_in_hardware == true){
            printf("Last Modification Time in Unix: %li\n",self->last_modification_time);
            printf("Last Modification Time: %s\n",last_moditication_in_string);
            printf("Hardware SHA: %s\n",self->hawdware_content_sha);
        }

        if(self->content_exist_in_memory == true){
            char *content_sha = self->get_content_sha(self);
            printf("Content SHA:  %s\n",content_sha);
            printf ("Content: %s\n",self->content);
            free(content_sha);
        }
        
        free(last_moditication_in_string);
    }
    const char *action = private_dtw_convert_action_to_string(self->pending_action);
    printf("Pending Action: %s\n",action);
    free(path);

}


void private_dtw_free_content(struct DtwTreePart *self){
    self->content_exist_in_memory = false;
    self->content = (unsigned char *)realloc(self->content,0);
}
void private_dtw_tree_part_destructor(struct DtwTreePart *self){
    self->path->free_path(self->path);
    free(self->hawdware_content_sha);
    free(self->content);
    free(self);
}
