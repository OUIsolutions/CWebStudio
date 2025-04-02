

privateLuaCEmbedTableArray *newprivateLuaCEmbedTableArray(){
    privateLuaCEmbedTableArray *self = (privateLuaCEmbedTableArray*) malloc(sizeof (privateLuaCEmbedTableArray));
    *self = (privateLuaCEmbedTableArray){0};
    self->tables = (LuaCEmbedTable**)malloc(0);
    return self;
}

void privateLuaCEmbedTableArray_append(privateLuaCEmbedTableArray *self,LuaCEmbedTable *element){

    self->tables = (LuaCEmbedTable **)realloc(
            self->tables,
           (self->size+1)* sizeof (LuaCEmbedTable**)
    );
    self->tables[self->size] = element;
    self->size+=1;
}


LuaCEmbedTable  *privateLuaCEmbedTableArray_find_by_prop_name(privateLuaCEmbedTableArray *self, const char *name){
    for(int i = 0; i < self->size;i++){
        LuaCEmbedTable  *current_table = self->tables[i];
        if(current_table->prop_name){
            if(strcmp(current_table->prop_name,name) ==0){
                return  current_table;
            }
        }
    }
    return NULL;
}

LuaCEmbedTable  *privateLuaCEmbedTableArray_find_by_global_name(privateLuaCEmbedTableArray *self, const char *name){
    for(int i = 0; i < self->size;i++){
        LuaCEmbedTable  *current_table = self->tables[i];
            if(strcmp(current_table->global_name,name) ==0){
                return  current_table;
            }
    }
    return NULL;
}

LuaCEmbedTable  *privateLuaCEmbedTableArray_find_by_internal_index(privateLuaCEmbedTableArray *self, long internal_index){
    for(int i = 0; i < self->size;i++){
        LuaCEmbedTable  *current_table = self->tables[i];
        if(current_table->index == internal_index){
            return current_table;
        }
    }
    return NULL;
}

void  privateLuaCEmbedTableArray_free(privateLuaCEmbedTableArray *self){

    for(int i = 0; i < self->size;i++){
        LuaCEmbedTable  *current_table = self->tables[i];
        privateLuaCEmbedTable_free(current_table);
    }

    free(self->tables);
    free(self);
}
