





void private_dtw_load_content_from_hardware(struct DtwTreePart *self){
    int size;
    bool is_binary;
    char *path = self->path->get_path(self->path);
    if(dtw_entity_type(path) != DTW_FILE_TYPE){
        free(path);
        return;
    }
    self->content = dtw_load_any_content(path,&size,&is_binary);
    self->content_exist_in_memory = true;
    self->is_binary = is_binary;
    self->content_size = size;
    self->hardware_content_size = size;
    self->last_modification_time = dtw_get_file_last_motification_in_unix(path);
    self->content_exist_in_hardware = true;
    free(self->hawdware_content_sha);
    self->hawdware_content_sha = dtw_generate_sha_from_string((const char*)self->content);
    free(path);
    
}



bool private_dtw_hardware_remove(struct DtwTreePart *self,bool set_as_action){
     if(self->ignore == true){
        return false;
     }
     if(set_as_action){
        self->pending_action = DTW_REMOVE;
        return false;
     }

    char *path = self->path->get_path(self->path);

    dtw_remove_any(path);
    
    free(path);
    self->content_exist_in_hardware = false;
    return true;
}

bool private_dtw_hardware_write(struct DtwTreePart *self,bool set_as_action){
    if(self->ignore == true){
        return false;
    }
    if(set_as_action){
        self->pending_action = DTW_WRITE;
        return false;
    }   
    //means that the content not exist in memory
    if(self->content_exist_in_memory == false){
        char *path = self->path->get_path(self->path);
        char *dir = self->path->get_dir(self->path);
        int entity_type = dtw_entity_type(path);
       
        if(entity_type== DTW_NOT_FOUND && dir!= NULL){
            dtw_create_dir_recursively(dir);
        
        }
        if(path!=NULL){
            free(path);
        }
        if(dir!=NULL){
            free(dir);
        }

        return true;
    }
    char *path = self->path->get_path(self->path);

    dtw_write_any_content(path,self->content,self->content_size);
    free(self->hawdware_content_sha);
    self->hawdware_content_sha = dtw_generate_sha_from_string((const char  *)self->content);
    self->content_exist_in_hardware = true;
    int now = time(NULL);
    self->last_modification_time = now;

    free(path);
    return true;
  
}

bool private_dtw_hardware_modify(struct DtwTreePart *self,bool set_as_action){
    if(self->ignore == true){
        return false;
    }
    if(set_as_action){
        self->pending_action = DTW_MODIFY;
        return false;
    }
    bool changed_path = self->path->changed(self->path);

    
    if(changed_path == true && self->content_exist_in_memory == false){
        char *old_path = self->path->original_path;
        char *new_path = self->path->get_path(self->path);
        dtw_move_any(old_path,new_path,true);
        free(new_path);
        return true;
    }
    bool write = false;

    if(changed_path == true && self->content_exist_in_memory == true ){
        char *old_path = self->path->original_path;
        dtw_remove_any(old_path);
        write = true;
    }

    if(changed_path== false && self->content_exist_in_memory == true ){
    
        if(self->content_exist_in_hardware == true){
            char *hardware_sha = self->hawdware_content_sha;
            char *memory_sha = self->get_content_sha(self);
            if(strcmp(hardware_sha,memory_sha) != 0){
                write = true;
            }
        }
        else{
            write = true;
        }
    }

    if(write){
        char *path = self->path->get_path(self->path);
        dtw_write_any_content(
            path,
            self->content,
            self->content_size
        );
        free(self->hawdware_content_sha);
        self->hawdware_content_sha = dtw_generate_sha_from_string((const char *)self->content);
        self->content_exist_in_hardware = true;
        int now = time(NULL);
        self->last_modification_time = now;

        free(path);
        return true;
    }
    return false;
}
bool private_dtw_hardware_commit(struct DtwTreePart *self){
    if(self->ignore == true){
        return false;
    }
    if(self->pending_action == DTW_REMOVE){
        return self->hardware_remove(self,DTW_EXECUTE_NOW);
    }
    if(self->pending_action == DTW_WRITE){
        return self->hardware_write(self,DTW_EXECUTE_NOW);
    }
    if(self->pending_action == DTW_MODIFY){
        return self->hardware_modify(self,DTW_EXECUTE_NOW);
    }
    return false;
}
