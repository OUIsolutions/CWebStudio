

DtwTransaction * newDtwTransaction(){
    DtwTransaction *self = (DtwTransaction*) malloc(sizeof(DtwTransaction));
    self->actions = (DtwActionTransaction **) malloc(sizeof (DtwActionTransaction**));
    self->size = 0;

    return self;
}

void DtwTransaction_append_action(struct DtwTransaction *self,struct DtwActionTransaction  *action){
    self->actions =  (DtwActionTransaction**)realloc(
            self->actions,
            (sizeof(DtwActionTransaction*) * (self->size+1))
    );
    self->actions[self->size] = action;
    self->size++;
}


void DtwTransaction_remove_from_index(DtwTransaction *self,long index){


    DtwActionTransaction_free(self->actions[index]);
    self->size -=1;
    if(self->size == 0){
        return;
    }
    for(long i = index; i < self->size; i++){
        self->actions[i] = self->actions[i+1];
    }

}
void DtwTransaction_filter(DtwTransaction *self,bool (*callback)(DtwActionTransaction *action)){
    for(long i = 0; i < self->size; i++){
        DtwActionTransaction *current = self->actions[i];
        if(!callback(current)){
            DtwTransaction_remove_from_index(self,i);
            i-=1;
        }
    }
}

void DtwTransaction_remove_from_source(DtwTransaction *self,const char *source){
    for(long i = 0; i < self->size; i++){
        DtwActionTransaction *current = self->actions[i];
        if(strcmp(current->source,source) ==0){
            DtwTransaction_remove_from_index(self,i);
            i-=1;
        }
    }
}


void DtwTransaction_write_any(struct DtwTransaction *self,const char *path,unsigned char *content, long size,bool is_binary){
    DtwActionTransaction * action = DtwActionTransaction_write_any(path,content,size,is_binary);
    DtwTransaction_append_action(self,action);
}

void DtwTransaction_write_string(struct DtwTransaction *self,const char *path,const char *content){
    DtwActionTransaction * action = DtwActionTransaction_write_any(path,(unsigned char*)content, strlen(content),false);
    DtwTransaction_append_action(self,action);
}


void DtwTransaction_write_long(struct DtwTransaction *self,const char *path,long value){
    char converted[20] ={0};
    sprintf(converted,"%ld",value);
    DtwTransaction_write_string(self,path,converted);
}

void DtwTransaction_write_bool(struct DtwTransaction *self,const char *path,bool value){
    if(value){
        DtwTransaction_write_string(self,path,"t");
    }
    else{
        DtwTransaction_write_string(self,path,"f");
    }
}

void DtwTransaction_write_double(struct DtwTransaction *self,const char *path,double value){
    char converted[20] ={0};
    sprintf(converted,"%lf",value);
    DtwTransaction_write_string(self,path,converted);
}


void DtwTransaction_move_any(struct DtwTransaction *self,const char *source,const char *dest){
    DtwActionTransaction * action = DtwActionTransaction_move_any(source,dest);
    DtwTransaction_append_action(self,action);
}

void DtwTransaction_copy_any(struct DtwTransaction *self,const char *source,const char *dest){
    DtwActionTransaction * action = DtwActionTransaction_copy_any(source,dest);
    DtwTransaction_append_action(self,action);
}

void DtwTransaction_move_any_merging(struct DtwTransaction *self,const char *source,const char *dest){
    DtwActionTransaction * action = DtwActionTransaction_move_any_merging(source,dest);
    DtwTransaction_append_action(self,action);
}


void DtwTransaction_copy_any_merging(struct DtwTransaction *self,const char *source,const char *dest){
    DtwActionTransaction * action = DtwActionTransaction_copy_any_merging(source,dest);
    DtwTransaction_append_action(self,action);
}


void DtwTransaction_delete_any(struct DtwTransaction *self,const char *source){
     DtwActionTransaction  *action = DtwActionTransaction_delete_any(source);
     DtwTransaction_append_action(self,action);
}



void DtwTransaction_commit(struct DtwTransaction *self,const char *path){
    for(int i = 0; i < self->size; i++){
        DtwActionTransaction_commit(self->actions[i],path);
    }
}



void DtwTransaction_free(struct DtwTransaction *self){
    for(int i =0; i < self->size; i++){
        DtwActionTransaction_free(self->actions[i]);
    }
    free(self->actions);
    free(self);
}
