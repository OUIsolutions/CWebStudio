
//listages
 DtwStringArray *DtwTree_list_files( DtwTree *self, const char *path,bool concat_path){
    DtwStringArray *formated_elements = newDtwStringArray();
    for(int i = 0; i < self->size; i++){
        DtwTreePart *current = self->tree_parts[i];
        DtwPath *current_path = current->path;
        char *current_path_string = DtwPath_get_path(current_path);

        long size = strlen(current_path_string);
        char last_char = current_path_string[size-1];
        if(last_char =='/'){
            continue;
        }

        if(dtw_starts_with(current_path_string,path)){
            //means its not an path from these dimension
            int path_size = strlen(path);
            bool insert = true;

            for(int i =path_size +1; i < size;i++){
                if(current_path_string[i] == '/'){
                    insert = false;
                    continue;
                }
            }

            if(insert){
                DtwStringArray_append(formated_elements,current_path_string);
            }

        }


    }
    if(!concat_path){

        DtwStringArray  *not_concatened = private_dtw_remove_start_path(formated_elements,path);
        DtwStringArray_free(formated_elements);
        return not_concatened;
    }


    return formated_elements;
}

 DtwStringArray *DtwTree_list_dirs( DtwTree *self, const char *path,bool concat_path){

    DtwStringArray *formated_elements = newDtwStringArray();
    for(int i = 0; i < self->size; i++){
        DtwTreePart *current = self->tree_parts[i];
        DtwPath *current_path = current->path;
        char *current_path_string = DtwPath_get_path(current_path);

        long size = strlen(current_path_string);
        char last_char = current_path_string[size-1];
        if(last_char !='/'){
            continue;
        }

        if(dtw_starts_with(current_path_string,path)){
            //means its not an path from these dimension
            int path_size = strlen(path);

            int total_found = 0;
            for(int i =path_size +1; i < size;i++){
                if(current_path_string[i] == '/'){
                    total_found+=1;
                    continue;
                }
            }

            if(total_found ==1){
                DtwStringArray_append(formated_elements,current_path_string);
            }

        }


    }
    if(!concat_path){

        DtwStringArray  *not_concatened = private_dtw_remove_start_path(formated_elements,path);
        DtwStringArray_free(formated_elements);
        return not_concatened;
    }


    return formated_elements;
}

struct DtwStringArray *DtwTree_list_all( DtwTree *self, const char *path,bool concat_path){

    DtwStringArray *formated_elements = newDtwStringArray();
    for(int i = 0; i < self->size; i++){
        DtwTreePart *current = self->tree_parts[i];
        DtwPath *current_path = current->path;
        char *current_path_string = DtwPath_get_path(current_path);

        if(dtw_starts_with(current_path_string,path)){
            //means its not an path from these dimension
            int path_size = strlen(path);
            long size = strlen(current_path_string);
            char last_char = current_path_string[size-1];

            int total_found = 0;
            for(int i =path_size+1; i < size;i++){
                if(current_path_string[i] == '/'){
                    total_found+=1;
                    continue;
                }
            }

            if(total_found ==1 && last_char == '/'){
                DtwStringArray_append(formated_elements,current_path_string);
            }
            if(total_found ==0){
                DtwStringArray_append(formated_elements,current_path_string);

            }



        }


    }
    if(!concat_path){

        DtwStringArray  *not_concatened = private_dtw_remove_start_path(formated_elements,path);
        DtwStringArray_free(formated_elements);
        return not_concatened;
    }


    return formated_elements;

}

 DtwStringArray *DtwTree_list_files_recursively( DtwTree *self, const char *path,bool concat_path){
    DtwStringArray *formated_elements = newDtwStringArray();
    for(int i = 0; i < self->size; i++){
        DtwTreePart *current = self->tree_parts[i];
        DtwPath *current_path = current->path;
        char *current_path_string = DtwPath_get_path(current_path);


        long size = strlen(current_path_string);
        char last_char = current_path_string[size-1];
        if(last_char =='/'){
            continue;
        }

        if(dtw_starts_with(current_path_string,path)){
            DtwStringArray_append(formated_elements,current_path_string);

        }


    }
    if(!concat_path){

        DtwStringArray  *not_concatened = private_dtw_remove_start_path(formated_elements,path);
        DtwStringArray_free(formated_elements);
        return not_concatened;
    }


    return formated_elements;
}

 DtwStringArray *DtwTree_list_dirs_recursively( DtwTree *self, const char *path,bool concat_path){
    DtwStringArray *formated_elements = newDtwStringArray();
    for(int i = 0; i < self->size; i++){
        DtwTreePart *current = self->tree_parts[i];
        DtwPath *current_path = current->path;
        char *current_path_string = DtwPath_get_path(current_path);

        long size = strlen(current_path_string);
        char last_char = current_path_string[size-1];
        if(last_char !='/'){
            continue;
        }

        if(dtw_starts_with(current_path_string,path)){
            DtwStringArray_append(formated_elements,current_path_string);

        }

    }
    if(!concat_path){

        DtwStringArray  *not_concatened = private_dtw_remove_start_path(formated_elements,path);
        DtwStringArray_free(formated_elements);
        return not_concatened;
    }


    return formated_elements;
}


 DtwStringArray *DtwTree_list_all_recursively( DtwTree *self, const char *path,bool concat_path){
    DtwStringArray *formated_elements = newDtwStringArray();
    for(int i = 0; i < self->size; i++){
        DtwTreePart *current = self->tree_parts[i];
        DtwPath *current_path = current->path;
        char *current_path_string = DtwPath_get_path(current_path);



        if(dtw_starts_with(current_path_string,path)){
            DtwStringArray_append(formated_elements,current_path_string);

        }

    }
    if(!concat_path){

        DtwStringArray  *not_concatened = private_dtw_remove_start_path(formated_elements,path);
        DtwStringArray_free(formated_elements);
        return not_concatened;
    }


    return formated_elements;
}

