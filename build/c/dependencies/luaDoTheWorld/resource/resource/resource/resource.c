
#include "../../../constants/resource_methods.h"

LuaCEmbedResponse * free_resource(LuaCEmbedTable  *self, LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);

    DtwResource_free(resource);


    return  NULL;

}


LuaCEmbedResponse * resource_get_path(LuaCEmbedTable  *self,LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    return LuaCEmbed_send_str(resource->path);
}

LuaCEmbedResponse * resource_rename(LuaCEmbedTable  *self,LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    char *new_name = LuaCEmbed_get_str_arg(args,0);
    DtwResource_rename(resource,new_name);
    if(DtwResource_error(resource)){
        char *error_mensage = DtwResource_get_error_message(resource);
        LuaCEmbedResponse *response = LuaCEmbed_send_error(error_mensage);
        DtwResource_clear_errors(resource);
        return  response;
    }
    return  LuaCEmbed_send_table(self);

}

LuaCEmbedResponse * resource_set_value(LuaCEmbedTable  *self,LuaCEmbed *args){
    Writeble  write_obj = create_writeble(args,0);
    if(write_obj.error){
        return write_obj.error;
    }
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource_set_binary(resource,write_obj.content, write_obj.size);
    if(DtwResource_error(resource)){
        char *error_mensage = DtwResource_get_error_message(resource);
        LuaCEmbedResponse *response = LuaCEmbed_send_error(error_mensage);
        DtwResource_clear_errors(resource);
        return  response;
    }

    return  LuaCEmbed_send_table(self);
}



LuaCEmbedResponse * resource_commit(LuaCEmbedTable  *self,LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource_commit(resource);
    return  LuaCEmbed_send_table(self);

}

LuaCEmbedResponse * resource_destroy(LuaCEmbedTable  *self,LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource_destroy(resource);
    if(DtwResource_error(resource)){
        char *error_mensage = DtwResource_get_error_message(resource);
        LuaCEmbedResponse *response = LuaCEmbed_send_error(error_mensage);
        DtwResource_clear_errors(resource);
        return  response;
    }
    return  LuaCEmbed_send_table(self);
}
LuaCEmbedResponse * unload_resurce(LuaCEmbedTable  *self, LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource_unload(resource);
    return  LuaCEmbed_send_table(self);
}

LuaCEmbedResponse * lock_resource(LuaCEmbedTable  *self, LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource_lock(resource);
    return  LuaCEmbed_send_table(self);
}

LuaCEmbedResponse * unlock_resource(LuaCEmbedTable  *self, LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource_unlock(resource);
    return  LuaCEmbed_send_table(self);
}

LuaCEmbedResponse * resource_new_schema(LuaCEmbedTable  *self, LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwSchema *schema = DtwResource_newSchema(resource);
    LuaCEmbedTable  *created = raw_create_schema(args,schema);
    return LuaCEmbed_send_table(created);

}

LuaCEmbedResponse * resource_set_value_in_sub_resource(LuaCEmbedTable  *self,LuaCEmbed *args){

    char *folder = LuaCEmbed_get_str_arg(args,0);
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }

    Writeble  write_obj = create_writeble(args,1);
    if(write_obj.error){
        return write_obj.error;
    }

    DtwResource *values = DtwResource_sub_resource(resource,folder);
    DtwResource_set_binary(values,write_obj.content,write_obj.size);
    if(DtwResource_error(resource)){
        char *error_mensage = DtwResource_get_error_message(resource);
        LuaCEmbedResponse *response = LuaCEmbed_send_error(error_mensage);
        DtwResource_clear_errors(resource);
        return  response;
    }

    return LuaCEmbed_send_table(self);

}
LuaCEmbedResponse * resource_is_blob(LuaCEmbedTable  *self,LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource_load(resource);
    return LuaCEmbed_send_bool(resource->is_binary);
}



LuaCEmbedTable *raw_create_resource(LuaCEmbed *args,DtwResource *resource){

    LuaCEmbedTable * self  = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_set_long_prop(self,DTW_TYPE,DTW_RESOURCE_TYPE);


    LuaCEmbedTable_set_long_prop(self,RESOURCE_POINTER,(long long )resource);
    LuaCEmbedTable_set_method(self,TO_STRING_METHOD,resource_to_string);
    LuaCEmbedTable_set_method(self,TO_NUMBER_METHOD,resource_to_number);
    LuaCEmbedTable_set_method(self,TO_BOOLEAN_METHOD,resource_to_boolean);
    LuaCEmbedTable_set_method(self,GET_VALUE_METHOD,resource_value);
    LuaCEmbedTable_set_method(self, INDEX_METHOD, resource_sub_resource_index);
    LuaCEmbedTable_set_method(self, SUB_RESOURCE_METHOD, resource_sub_resource_method);
    LuaCEmbedTable_set_method(self,RESOURCE_RENAME_METHOD,resource_rename);

    LuaCEmbedTable_set_method(self,RESOURCE_GET_STRING,resource_value_string);
    LuaCEmbedTable_set_method(self,RESOURCE_GET_NUMBER,resource_value_number);
    LuaCEmbedTable_set_method(self,RESOURCE_GET_BOOL,resource_value_bool);

    LuaCEmbedTable_set_method(self, SUB_RESOURCE_NEXT_METHOD, resource_sub_resource_next);
    LuaCEmbedTable_set_method(self, SUB_RESOURCE_NOW_METHOD, resource_sub_resource_now);
    LuaCEmbedTable_set_method(self, SUB_RESOURCE_NOW_IN_UNIX, resource_sub_resource_now_in_unix);
    LuaCEmbedTable_set_method(self,LOCK_METHOD,lock_resource);
    LuaCEmbedTable_set_method(self,UNLOCK_METHOD,unlock_resource);
    LuaCEmbedTable_set_method(self,UNLOAD_METHOD,unload_resurce);
    LuaCEmbedTable_set_method(self,IS_BLOB_FUNC,resource_is_blob);

    LuaCEmbedTable_set_method(self,SET_VALUE_METHOD,resource_set_value);
    LuaCEmbedTable_set_method(self,COMMIT_METHOD,resource_commit);
    LuaCEmbedTable_set_method(self,DESTROY_METHOD,resource_destroy);

    LuaCEmbedTable_set_method(self, GET_PATH_STRING_METHOD, resource_get_path);

    LuaCEmbedTable_set_method(self, SET_VALUE_IN_SUB_RESOURCE_METHOD, resource_set_value_in_sub_resource);
    LuaCEmbedTable_set_method(self,GET_VALUE_FROM_SUB_RESOURCE_METHOD,resource_value_from_sub_resource);

    LuaCEmbedTable_set_method(self, SUB_SCHEMA_METHOD, resource_new_schema);
    LuaCEmbedTable_set_method(self,DANGEROUS_REMOVE_PROP_METHOD,dangerous_remove_schema_prop);
    LuaCEmbedTable_set_method(self,DANGEROUS_RENAME_PROP_METHOD,dangerous_rename_schema_prop);
    LuaCEmbedTable_set_method(self, GET_RESOURCE_MATCHING_PRIMARY_KEY_METHOD, get_resource_match_schema_by_primary_key);
    LuaCEmbedTable_set_method(self,GET_RESOURCE_BY_NAME_ID,get_resource_by_name_id);

    LuaCEmbedTable_set_method(self,RESOURCE_NEW_SCHEMA,resource_new_schema);
    LuaCEmbedTable_set_method(self,SCHEMA_LIST_RESOURCE_METHOD,schema_list_resources);
    LuaCEmbedTable_set_method(self, SCHEMA_FIND_RESOURCE_METHOD, schema_find_resource);
    LuaCEmbedTable_set_method(self,SCHEMA_MAP_RESOURCE_METHOD,schema_map_resource);
    LuaCEmbedTable_set_method(self,SCHEMA_COUNT_RESOURCE_METHOD,schema_count_resource);
    LuaCEmbedTable_set_method(self, SCHEMA_EACH_METHOD, resource_schema_each);


    LuaCEmbedTable_set_method(self,LIST_METHOD,resource_list);
    LuaCEmbedTable_set_method(self,EACH_METHOD,resource_foreach);
    LuaCEmbedTable_set_method(self, SCHEMA_NEW_INSERTION, Resource_new_insertion);

    if(resource->mother ==NULL){
        LuaCEmbedTable_set_method(self, DELETE_METHOD, free_resource);
    }

    return self;
}



LuaCEmbedResponse * create_resource(LuaCEmbed *args){
    char *folder = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }
    DtwResource *resource = new_DtwResource(folder);

    LuaCEmbedTable  *self = raw_create_resource(args,resource);
    return LuaCEmbed_send_table(self);

}