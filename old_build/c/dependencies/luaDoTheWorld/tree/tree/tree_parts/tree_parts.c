
LuaCEmbedResponse *new_tree_part(LuaCEmbedTable *self, LuaCEmbed *args){
    char *path = LuaCEmbed_get_str_arg(args,0);

    LuaCEmbedTable *props_table = NULL;
    if(LuaCEmbed_get_arg_type(args,1) != LUA_CEMBED_NIL){
        props_table = LuaCEmbed_get_arg_table(args,1);
    }
    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }


    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }

    DtwTree *self_tree = (DtwTree*)LuaCembedTable_get_long_prop(self,TREE_POINTER);
    DtwTreeProps props = create_tree_props(props_table);
    DtwTreePart *tree_part = newDtwTreePart(path,props);
    DtwTree_add_tree_part_getting_onwership(self_tree,tree_part);
    LuaCEmbedTable *tree_part_table = create_tree_part_reference(args,tree_part);
    return LuaCEmbed_send_table(tree_part_table);
}

LuaCEmbedResponse *new_tree_part_loading(LuaCEmbedTable *self, LuaCEmbed *args){
    char *path = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }
    DtwTree *self_tree = (DtwTree*)LuaCembedTable_get_long_prop(self,TREE_POINTER);
    DtwTreePart *tree_part = newDtwTreePartLoading(path);
    DtwTree_add_tree_part_getting_onwership(self_tree,tree_part);
    LuaCEmbedTable *tree_part_table = create_tree_part_reference(args,tree_part);
    return LuaCEmbed_send_table(tree_part_table);
}

LuaCEmbedResponse *new_tree_part_empty(LuaCEmbedTable *self, LuaCEmbed *args){

    char *path = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }
    DtwTree *self_tree = (DtwTree*)LuaCembedTable_get_long_prop(self,TREE_POINTER);
    DtwTreePart *tree_part = newDtwTreePartEmpty(path);
    DtwTree_add_tree_part_getting_onwership(self_tree,tree_part);
    LuaCEmbedTable *tree_part_table = create_tree_part_reference(args,tree_part);
    return LuaCEmbed_send_table(tree_part_table);
}

LuaCEmbedResponse *get_tree_part_by_index(LuaCEmbedTable *self, LuaCEmbed *args){

    long index = LuaCEmbed_get_long_arg(args,0)-1;
    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }

    DtwTree *self_tree = (DtwTree*)LuaCembedTable_get_long_prop(self,TREE_POINTER);
    if(index>=self_tree->size){
        return NULL;
    }

    LuaCEmbedTable *result  = create_tree_part_reference(args,self_tree->tree_parts[index]);
    return  LuaCEmbed_send_table(result);
}



LuaCEmbedResponse *tree_get_tree_part_by_name(LuaCEmbedTable *self, LuaCEmbed *args){
    char *name = LuaCEmbed_get_str_arg(args,0);

    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }

    DtwTree *self_tree = (DtwTree*)LuaCembedTable_get_long_prop(self,TREE_POINTER);
    DtwTreePart * possible = DtwTree_find_tree_part_by_name(self_tree,name);
    if(possible == NULL){
        return NULL;
    }
    LuaCEmbedTable *created_table = create_tree_part_reference(args,possible);
    return LuaCEmbed_send_table(created_table);
}



LuaCEmbedResponse *tree_get_tree_part_by_path(LuaCEmbedTable *self, LuaCEmbed *args){
    char *path = LuaCEmbed_get_str_arg(args,0);

    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }

    DtwTree *self_tree = (DtwTree*)LuaCembedTable_get_long_prop(self,TREE_POINTER);
    DtwTreePart * possible = DtwTree_find_tree_part_by_path(self_tree,path);
    if(possible == NULL){
        return NULL;
    }
    LuaCEmbedTable *created_table = create_tree_part_reference(args,possible);
    return LuaCEmbed_send_table(created_table);
}

