//
// Created by jurandi on 11-04-2023.
//
struct DtwTreePart *DtwTree_find_tree_part_by_function(
        struct DtwTree *self,
        bool (*caller)(struct  DtwTreePart *part)
){
    for(int i = 0;i < self->size; i++){
        struct DtwTreePart *current = self->tree_parts[i];
        bool result = caller(current);
        if(result){
            return current;
        }
    }
    return NULL;
}

struct DtwTree *DtwTree_filter(
        struct DtwTree *self,
        bool (*caller)(struct  DtwTreePart *part)
){
    DtwTree *filtered_tree = newDtwTree();

    for(int i = 0;i < self->size; i++){

        DtwTreePart *current = self->tree_parts[i];

        bool result = caller(current);

        if(result){
            DtwTree_add_tree_part_copy(filtered_tree,current);
        }

    }
    return filtered_tree;
}


 DtwTree *DtwTree_map(DtwTree *self,DtwTreePart *(*caller)( DtwTreePart *part)){
     DtwTree *mapped_tree = newDtwTree();

    for(int i = 0;i < self->size; i++){
         DtwTreePart *current = self->tree_parts[i];
         DtwTreePart *copy = DtwTreePart_self_copy(current);
         DtwTreePart *result = caller(copy);
        DtwTree_add_tree_part_getting_onwership(mapped_tree, result);
    }
    return mapped_tree;
}


 DtwTreePart *DtwTree_find_tree_part_by_name( DtwTree *self, const char *name){
    for(int i = 0;i < self->size; i++){
        DtwTreePart *current = self->tree_parts[i];
        DtwPath *current_path = current->path;
        char *current_name = DtwPath_get_full_name(current_path);
        if(current_name){

            if(strcmp(current_name, name) == 0){
                return current;
            }
        }

    }

    return NULL;
}

 DtwTreePart *DtwTree_find_tree_part_by_path( DtwTree *self, const char *path){
    for(int i = 0;i < self->size; i++){
         DtwTreePart *current = self->tree_parts[i];
         DtwPath *current_path = current->path;
        char *current_path_string = DtwPath_get_path(current_path);
        if(current_path_string){
            if(strcmp(current_path_string, path) == 0){
                return current;
            }
        }

    }

    return NULL;
}