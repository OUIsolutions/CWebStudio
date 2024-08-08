
LuaCEmbedResponse * create_tree_from_json_tree_string(LuaCEmbed *args){
    char *content = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }
    UniversalGarbage *garbage =  newUniversalGarbage();
    DtwTree *tree = newDtwTree();
    UniversalGarbage_add_return(garbage,DtwTree_free,tree);

   bool result = DtwTree_loads_json_tree(tree,content);

    if(result ==false){
        DtwTree_free(tree);
        DtwJsonTreeError *error_tree = DtwJsonTreeError_validate_json_tree_by_content(content);
        UniversalGarbage_add(garbage,DtwJsonTreeError_free,error_tree);

        LuaCEmbedResponse *response = LuaCEmbed_send_error(
            "%s at index %d",
                error_tree->menssage,
                error_tree->position
            );
        UniversalGarbage_free_including_return(garbage);
        return response;
    }
    LuaCEmbedTable * self = raw_create_tree(args,tree);
    UniversalGarbage_free(garbage);
    return LuaCEmbed_send_table(self);
}

LuaCEmbedResponse * create_tree_from_json_tree_file(LuaCEmbed *args){

    char *path = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }
    UniversalGarbage *garbage = newUniversalGarbage();

    char *content = dtw_load_string_file_content(path);
    UniversalGarbage_add_simple(garbage,content);
    if(content == NULL){
        UniversalGarbage_free(garbage);
        return LuaCEmbed_send_error(FILE_NOT_FOUND,path);
    }

    DtwTree *tree = newDtwTree();
    UniversalGarbage_add_return(garbage,DtwTree_free,tree);

    bool result = DtwTree_loads_json_tree(tree,content);

    if(result ==false){
        DtwTree_free(tree);
        DtwJsonTreeError *error_tree = DtwJsonTreeError_validate_json_tree_by_content(content);
        UniversalGarbage_add(garbage,DtwJsonTreeError_free,error_tree);
        LuaCEmbedResponse *response = LuaCEmbed_send_error(
            "%s at index %d",
                error_tree->menssage,
                error_tree->position
            );

        UniversalGarbage_free_including_return(garbage);
        return response;
    }
    LuaCEmbedTable * self = raw_create_tree(args,tree);
    UniversalGarbage_free(garbage);
    return LuaCEmbed_send_table(self);
}


LuaCEmbedResponse *tree_dump_to_json_string(LuaCEmbedTable *self, LuaCEmbed *args){
    LuaCEmbedTable *props_table = NULL;
    if(LuaCEmbed_get_arg_type(args,0) != LUA_CEMBED_NIL){
        props_table = LuaCEmbed_get_arg_table(args,0);
    }
    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }

    DtwTreeProps props = create_tree_props(props_table);
    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }
    DtwTree *self_tree = (DtwTree*)LuaCembedTable_get_long_prop(self,TREE_POINTER);
    char *result = DtwTree_dumps_tree_json(self_tree,props);
    LuaCEmbedResponse *response = LuaCEmbed_send_str(result);
    free(result);
    return  response;
}

LuaCEmbedResponse *tree_dump_to_json_file(LuaCEmbedTable *self, LuaCEmbed *args){
    char *path = LuaCEmbed_get_str_arg(args,0);
    LuaCEmbedTable *props_table = NULL;
    if(LuaCEmbed_get_arg_type(args,1) != LUA_CEMBED_NIL){
        props_table = LuaCEmbed_get_arg_table(args,1);
    }
    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }

    DtwTreeProps props = create_tree_props(props_table);
    if(LuaCEmbed_has_errors(args)){
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }
    DtwTree *self_tree = (DtwTree*)LuaCembedTable_get_long_prop(self,TREE_POINTER);
    DtwTree_dumps_tree_json_to_file(self_tree,path,props);
    return  LuaCEmbed_send_table(self);
}