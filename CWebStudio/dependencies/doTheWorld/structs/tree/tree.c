


struct  DtwTree * dtw_tree_constructor(){
    struct DtwTree *self = (struct DtwTree*)malloc(sizeof(struct DtwTree));
    self->size = 0;
    self->tree_parts = (struct DtwTreePart**)malloc(1);
    self->add_tree_part_by_copy = private_dtw_add_tree_part_copy;
    self->get_sub_tree = private_dtw_get_sub_tree;
    self->add_tree_part_by_reference = private_dtw_add_tree_part_reference;
    self->free_tree = private_dtw_free_tree;
    self->represent = private_dtw_represent_tree;
    self->add_tree_parts_from_string_array = private_dtw_add_tree_parts_from_string_array;
    self->add_tree_from_hardware = private_dtw_add_tree_from_hardware;
   
    self->report = private_dtw_create_report;
    //{%if not  lite %}
    
    self->loads_json_tree = private_dtw_loads_json_tree;
    self->loads_json_tree_from_file = private_dtw_loads_json_tree_from_file;
    
    self->dumps_json_tree = private_dtw_dumps_tree_json;
    self->dumps_json_tree_to_file = private_dtw_dumps_tree_json_to_file;

    //{%endif%}
    self->insecure_hardware_remove_tree = private_insecure_dtw_hardware_remove_tree;
    self->insecure_hardware_write_tree = private_insecure_dtw_hardware_write_tree;
    self->hardware_commit_tree = private_dtw_hardware_commit_tree;
    return self;
}


struct DtwTree *private_dtw_get_sub_tree(struct DtwTree *self,const char *path,bool copy_content){
    struct DtwTree *sub_tree = dtw_tree_constructor();
    for(int i = 0; i < self->size; i++){
        struct DtwTreePart *tree_part = self->tree_parts[i];
        char *current_path = tree_part->path->get_path(tree_part->path);
        if(dtw_starts_with(current_path,path)){
            if(copy_content){
                sub_tree->add_tree_part_by_copy(sub_tree,tree_part->copy_tree_part(tree_part));
            }
            else{
                sub_tree->add_tree_part_by_reference(sub_tree,tree_part);

            }
        }
        free(current_path);
    }
    return sub_tree;
}


void private_dtw_add_tree_part_copy(struct DtwTree *self, struct DtwTreePart *tree_part){
    self->size++;
    self->tree_parts =  (struct DtwTreePart**)realloc(self->tree_parts, self->size * sizeof(struct DtwTreePart *));
    self->tree_parts[self->size - 1] = tree_part->copy_tree_part(tree_part);
       
}

struct DtwTransactionReport * private_dtw_create_report(struct DtwTree *self){
    struct DtwTransactionReport *report = dtw_constructor_transaction_report();
    for(int i = 0; i < self->size; i++){
        struct DtwTreePart *tree_part = self->tree_parts[i];
        int pending_action = tree_part->pending_action;
        char *path = tree_part->path->get_path(tree_part->path);
        if (pending_action == DTW_WRITE){

            report->write->add_string(report->write,path);
        }
        else if (pending_action == DTW_MODIFY){
            report->modify->add_string(report->modify,path);
        }
        else if (pending_action == DTW_REMOVE){
            report->remove->add_string(report->remove,path);
        }
        free(path);
    
    }
    return report;
}


void private_dtw_add_tree_part_reference(struct DtwTree *self, struct DtwTreePart *tree_part){
    self->size++;
    self->tree_parts =  (struct DtwTreePart**)realloc(self->tree_parts, self->size * sizeof(struct DtwTreePart *));
    self->tree_parts[self->size - 1] = tree_part;
}


void private_dtw_represent_tree(struct DtwTree *self){
    for(int i = 0; i < self->size; i++){
        self->tree_parts[i]->represent(self->tree_parts[i]);
    }
}

void private_dtw_add_tree_parts_from_string_array(struct DtwTree *self,struct DtwStringArray *paths,bool load_content,bool preserve_content){
    for(int i = 0; i < paths->size; i++){

        const char *current_path = paths->strings[i];
        struct DtwTreePart *tree_part = dtw_tree_part_constructor(
            current_path,
            load_content,
            preserve_content
        );
        self->add_tree_part_by_reference(self, tree_part);
    }
}


void private_dtw_add_tree_from_hardware(struct DtwTree *self,const char *path,bool load_content, bool preserve_content){
    
    struct DtwStringArray *path_array = dtw_list_all_recursively(path);
    self->add_tree_parts_from_string_array(self,path_array,load_content,preserve_content);
    path_array->free_string_array(path_array);

}

void private_dtw_free_tree(struct DtwTree *self){
    for(int i = 0; i < self->size; i++){
        self->tree_parts[i]->free_tree_part(self->tree_parts[i]);
    }
    
    free(self->tree_parts);
    free(self);
}
void private_insecure_dtw_hardware_remove_tree(struct DtwTree *self){
    for(int i = 0; i < self->size; i++){
        self->tree_parts[i]->hardware_remove(self->tree_parts[i],DTW_EXECUTE_NOW);
    }
}

void private_insecure_dtw_hardware_write_tree(struct DtwTree *self){
    
    for(int i = 0; i < self->size; i++){
        struct DtwTreePart *tree_part = self->tree_parts[i];
        tree_part->hardware_write(tree_part,DTW_EXECUTE_NOW);
    }
}

void private_dtw_hardware_commit_tree(struct DtwTree *self){
    for(int i = 0; i < self->size; i++){
        self->tree_parts[i]->hardware_commit(self->tree_parts[i]);
    }
}
