

DtwActionTransaction * newDtwActionTransaction(){
    DtwActionTransaction *self = (DtwActionTransaction*) malloc(sizeof (DtwActionTransaction));
    *self= (DtwActionTransaction){0};
    return self;
}


DtwActionTransaction * DtwActionTransaction_write_any(const char *source, unsigned  char *content,long size,bool is_binary){
    DtwActionTransaction *self = newDtwActionTransaction();
    self->action_type = DTW_ACTION_WRITE;
    self->content = (unsigned char*)malloc(size +2);
    memcpy(self->content,content,size);
    self->content[size] = '\0';
    self->size = size;
    self->source = strdup(source);
    self->is_binary = is_binary;
    return self;
}


DtwActionTransaction * DtwActionTransaction_move_any(const char *source, const char *dest){
    DtwActionTransaction *self = newDtwActionTransaction();
    self->action_type = DTW_ACTION_MOVE;
    self->source = strdup(source);
    self->dest = strdup(dest);
    return self;

}


DtwActionTransaction * DtwActionTransaction_copy_any(const char *source, const char *dest){
    DtwActionTransaction *self = newDtwActionTransaction();
    self->action_type = DTW_ACTION_COPY;
    self->source = strdup(source);
    self->dest = strdup(dest);
    return self;
}
DtwActionTransaction * DtwActionTransaction_move_any_merging(const char *source, const char *dest){
    DtwActionTransaction *self = newDtwActionTransaction();
    self->action_type = DTW_ACTION_MOVE_MERGING;
    self->source = strdup(source);
    self->dest = strdup(dest);
    return self;
}

DtwActionTransaction * DtwActionTransaction_copy_any_merging(const char *source, const char *dest){
    DtwActionTransaction *self = newDtwActionTransaction();
    self->action_type = DTW_ACTION_COPY_MERGING;
    self->source = strdup(source);
    self->dest = strdup(dest);
    return self;
}

DtwActionTransaction * DtwActionTransaction_delete_any(const char *source){
    DtwActionTransaction *self = newDtwActionTransaction();
    self->action_type = DTW_ACTION_DELETE;
    self->source = strdup(source);
    return self;
}



void DtwActionTransaction_commit(DtwActionTransaction* self,const char *path){

    char *formated_source = dtw_concat_path(path,self->source);


    if(self->action_type == DTW_ACTION_WRITE){
        dtw_write_any_content(formated_source,self->content,self->size);
        free(formated_source);
        return;
    }
    if(self->action_type == DTW_ACTION_DELETE){
        dtw_remove_any(formated_source);
        free(formated_source);
        return;
    }
    char *formated_dest = dtw_concat_path(path,self->dest);

    if(self->action_type == DTW_ACTION_MOVE){
        dtw_move_any(formated_source,formated_dest,DTW_NOT_MERGE);
    }

    if(self->action_type == DTW_ACTION_MOVE_MERGING){
        dtw_move_any(formated_source,formated_dest,DTW_MERGE);
    }

    if(self->action_type == DTW_ACTION_COPY){
        dtw_copy_any(formated_source,formated_dest,DTW_NOT_MERGE);
    }

    if(self->action_type == DTW_ACTION_COPY_MERGING){
        dtw_copy_any(formated_source,formated_dest,DTW_MERGE);
    }

    free(formated_dest);
    free(formated_source);

}


void DtwActionTransaction_free(DtwActionTransaction* self){

    if(self->content){
        free(self->content);
    }
    if(self->source){
        free(self->source);
    }
    if(self->dest){
        free(self->dest);
    }
    free(self);
}
