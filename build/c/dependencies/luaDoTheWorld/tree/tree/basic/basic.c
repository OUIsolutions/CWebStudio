

#include "../iterables/iterables.h"

LuaCEmbedResponse *hardware_commit_tree(LuaCEmbedTable *self, LuaCEmbed *args){
    DtwTree *self_tree = (DtwTree*)LuaCembedTable_get_long_prop(self,TREE_POINTER);
    DtwTree_hardware_commit_tree(self_tree);
    return  LuaCEmbed_send_table(self);
}


LuaCEmbedResponse *tree_get_size(LuaCEmbedTable *self, LuaCEmbed *args){
    DtwTree *self_tree = (DtwTree*)LuaCembedTable_get_long_prop(self,TREE_POINTER);
    return LuaCEmbed_send_long(self_tree->size);
}



LuaCEmbedResponse *insecure_hardware_write_tree(LuaCEmbedTable *self, LuaCEmbed *args){
    DtwTree *self_tree = (DtwTree*)LuaCembedTable_get_long_prop(self,TREE_POINTER);
    DtwTree_insecure_hardware_write_tree(self_tree);
    return LuaCEmbed_send_table(self);
}


LuaCEmbedResponse *insecure_hardware_remove_tree(LuaCEmbedTable *self, LuaCEmbed *args){
    DtwTree *self_tree = (DtwTree*)LuaCembedTable_get_long_prop(self,TREE_POINTER);
    DtwTree_insecure_hardware_remove_tree(self_tree);
    return LuaCEmbed_send_table(self);
}

LuaCEmbedResponse * tree_delete(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwTree *self_tree = (DtwTree*)LuaCembedTable_get_long_prop(self,TREE_POINTER);
    DtwTree_free(self_tree);
    return  NULL;
}

LuaCEmbedTable * raw_create_tree(LuaCEmbed *args,DtwTree *tree){
    LuaCEmbedTable *self = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_set_long_prop(self,TREE_POINTER,(long long)tree);
    LuaCEmbedTable_set_method(self,TREE_NEW_TREE_PART_EMPTY,new_tree_part_empty);
    LuaCEmbedTable_set_method(self,TREE_NEW_TREE_PART_LOADING,new_tree_part_loading);
    LuaCEmbedTable_set_method(self,GET_TREE_PART_BY_INDEX_METHOD,get_tree_part_by_index);
    LuaCEmbedTable_set_method(self,INSECURE_HARDWARE_WRITE_TREE,insecure_hardware_write_tree);
    LuaCEmbedTable_set_method(self,INSECURE_HARDWARE_REMOVE_TREE,insecure_hardware_remove_tree);
    LuaCEmbedTable_set_method(self,COMMIT_METHOD,hardware_commit_tree);
    LuaCEmbedTable_set_method(self,GET_SIZE_METHOD,tree_get_size);
    LuaCEmbedTable_set_method(self,GET_TREE_PART_BY_NAME,tree_get_tree_part_by_name);
    LuaCEmbedTable_set_method(self,GET_TREE_PART_BY_PATH,tree_get_tree_part_by_path);
    LuaCEmbedTable_set_method(self,LIST_METHOD,tree_list);
    LuaCEmbedTable_set_method(self,FIND_METHOD,tree_find);
    LuaCEmbedTable_set_method(self,COUNT_METHOD,tree_count);
    LuaCEmbedTable_set_method(self,MAP_METHOD,tree_map);
    LuaCEmbedTable_set_method(self,EACH_METHOD,tree_foreach);
    LuaCEmbedTable_set_method(self,FILTER_METHOD,tree_filter);
    LuaCEmbedTable_set_method(self,DUMP_TO_JSON_STRING,tree_dump_to_json_string);
    LuaCEmbedTable_set_method(self,DUMP_TO_JSON_FILE_METHOD,tree_dump_to_json_file);
    LuaCEmbedTable_set_method(self,ADD_TREE_FROM_HARDWARE,add_tree_fro_hardware);
    LuaCEmbedTable_set_method(self,DELETE_METHOD,tree_delete);
    return self;
}

LuaCEmbedResponse * create_empty_tree(LuaCEmbed *args){
    DtwTree * tree = newDtwTree();
    LuaCEmbedTable *self = raw_create_tree(args,tree);
    return LuaCEmbed_send_table(self);
}

DtwTreeProps create_tree_props(LuaCEmbedTable *user_props){
    DtwTreeProps  tree_props = {0};
    tree_props.content = get_table_props_or_default_bool(user_props,TREE_PROPS_CONTENT,DTW_INCLUDE) +1;
    tree_props.content_data = get_table_props_or_default_bool(user_props,TREE_PROPS_CONTENT_DATA,DTW_INCLUDE)+1;
    tree_props.hadware_data = get_table_props_or_default_bool(user_props,TREE_PROPS_HARDWARE_DATA,DTW_INCLUDE)+1;
    tree_props.ignored_elements = get_table_props_or_default_bool(user_props,TREE_PROPS_IGNORED_ELEMENTS,DTW_INCLUDE)+1;
    tree_props.minification = get_table_props_or_default_bool(user_props,TREE_PROPS_MIMIFICATION,DTW_NOT_MIMIFY)+1;
    tree_props.path_atributes = get_table_props_or_default_bool(user_props,TREE_PROPS_PATH_ATTRIBUTES,DTW_INCLUDE)+1;
    return tree_props;
}

LuaCEmbedResponse * create_tree_fro_hardware(LuaCEmbed *args){

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
    DtwTree * tree = newDtwTree();
    LuaCEmbedTable *self = raw_create_tree(args,tree);
    DtwTree_add_tree_from_hardware(tree,path,props);
    return LuaCEmbed_send_table(self);
}
LuaCEmbedResponse * add_tree_fro_hardware(LuaCEmbedTable *self,LuaCEmbed *args) {

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
    DtwTree_add_tree_from_hardware(self_tree,path,props);
    return LuaCEmbed_send_table(self);
}