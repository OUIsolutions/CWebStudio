

void private_DtwTreePart_set_last_modification(DtwTreePart *self,long last_modification) {
    self->last_modification_time = last_modification;
    if(self->last_modification_in_str) {
        free(self->last_modification_in_str);
    }
    self->last_modification_in_str = dtw_convert_unix_time_to_string(last_modification);
}
 DtwTreePart * newDtwTreePart(const char *path, DtwTreeProps props){
    DtwTreeProps formated_props = DtwTreeProps_format_props(props);

    DtwTreePart *self = (DtwTreePart *)malloc(sizeof(struct DtwTreePart));
    *self = (DtwTreePart){0};
    self->path = newDtwPath(path);


    if(formated_props.content == DTW_INCLUDE || formated_props.hadware_data == DTW_INCLUDE){
        
        DtwTreePart_load_content_from_hardware(self);
        if(formated_props.hadware_data == DTW_INCLUDE && self->content){

            self->metadata_loaded = true;
            private_DtwTreePart_set_last_modification(self,dtw_get_entity_last_motification_in_unix(path));
            free(self->hawdware_content_sha);
            self->hawdware_content_sha = dtw_generate_sha_from_string((const char*)self->content);
        }

        if(formated_props.content == DTW_HIDE){
            DtwTreePart_free_content(self);
        }
    }

    return self;
}
char *DtwTreePart_get_content_string_by_reference(struct DtwTreePart *self){
    return (char *)self->content;
}

unsigned char *DtwTreePart_get_content_binary_by_reference(struct DtwTreePart *self){
    return self->content;
}


  DtwTreePart * DtwTreePart_self_copy( DtwTreePart *self){
    char *path = DtwPath_get_path(self->path);

    DtwTreeProps props = {.content =DTW_NOT_LOAD,.hadware_data = DTW_NOT_LOAD};
    DtwTreePart *new_tree_part = newDtwTreePart(
            path,
            props
    );

    new_tree_part->content_exist_in_hardware = self->content_exist_in_hardware;
    new_tree_part->is_binary = self->is_binary;
    new_tree_part->ignore = self->ignore;
    new_tree_part->content_size = self->content_size;

    char * current_sha = DtwTreePart_get_content_sha(self);

    if(current_sha) {
        new_tree_part->current_sha = strdup(current_sha);
    }

    if(self->hawdware_content_sha){
        new_tree_part->hawdware_content_sha = strdup(self->hawdware_content_sha);
    }

    if(self->content) {
        new_tree_part->content = (unsigned char *)malloc(self->content_size + 2);
        memcpy(new_tree_part->content,self->content,self->content_size);

        if(self->is_binary == false){
            new_tree_part->content[self->content_size] = '\0';
        }

    }


    
    return new_tree_part;
}

void DtwTreePart_set_any_content( DtwTreePart *self, unsigned char *content, long content_size, bool is_binary){

    DtwTreePart_free_content(self);
    self->is_binary = is_binary;
    self->content = (unsigned char *)malloc(content_size+2);
    memcpy(self->content,content,content_size);
    self->content_size = content_size;


}

void DtwTreePart_set_string_content( DtwTreePart *self, const char *content){
    DtwTreePart_set_any_content(
        self,
        (unsigned char*)content,
        strlen(content),
        false
    );
    
    self->content[self->content_size] = '\0';
}

void DtwTreePart_set_binary_content( DtwTreePart *self, unsigned char *content, long content_size){
    DtwTreePart_set_any_content(self,content,content_size,true);
}


char *DtwTreePart_get_content_sha( DtwTreePart *self){
    if(self->content == NULL) {
        return NULL;
    }
    if(self->current_sha) {
        free(self->current_sha);
    }
    self->current_sha =dtw_generate_sha_from_any(self->content,self->content_size);;
    return self->current_sha;
}







void DtwTreePart_represent(struct DtwTreePart *self){
    printf("------------------------------------------------------------\n");
    DtwPath_represent(self->path);
    printf("Content Exist in Memory: %s\n",self->content ? "true" : "false");
    printf("Ignore: %s\n",self->ignore ? "true" : "false");

    printf("Content Exist In Hardware: %s\n",self->content_exist_in_hardware ? "true" : "false");
    printf("Is Binary: %s\n",self->is_binary ? "true" : "false");

    if(self->last_modification_in_str){
        printf("Last Modification Time in Unix: %li\n",self->last_modification_time);
        printf("Last Modification Time: %s\n",self->last_modification_in_str);
    }

    printf("Content Size: %ld\n",(long)self->content_size);

    char *content_sha = DtwTreePart_get_content_sha(self);
    if(content_sha){
        printf("Content SHA:  %s\n",content_sha);
    }
    if(self->content && self->is_binary == false){
        printf ("Content: %s\n",(char*)self->content);
    }

    if(self->hawdware_content_sha) {
        printf("Original Hardware SHA:%s\n",self->hawdware_content_sha);
    }

    if(self->is_binary == true){
        printf("Content: Binary\n");
    }
    
    const char *action = private_dtw_convert_action_to_string(self->pending_action);
    if(action){
        printf("Pending Action: %s\n",action);

    }

}


void DtwTreePart_free_content(struct DtwTreePart *self){
    if(self->content){
        free(self->content);
    }
    self->content = NULL;

}
void DtwTreePart_free(struct DtwTreePart *self){
    if(self->path) {
        DtwPath_free(self->path);
    }

    if(self->hawdware_content_sha) {
        free(self->hawdware_content_sha);
    }
    if(self->current_sha) {
        free(self->current_sha);
    }
    if(self->last_modification_in_str) {
        free(self->last_modification_in_str);
    }
    DtwTreePart_free_content(self);
    free(self);
}

 DtwTreePart * newDtwTreePartEmpty(const char *path){
    DtwTreeProps  props = {.content =DTW_NOT_LOAD,.hadware_data = DTW_NOT_LOAD};
    return newDtwTreePart(
            path,
         props
    );

}


 DtwTreePart * newDtwTreePartLoading(const char *path){
    DtwTreeProps  props = {.content =DTW_LOAD,.hadware_data = DTW_LOAD};
    return newDtwTreePart(
            path,
            props
    );
}
