
#include "../../../constants/resource_methods.h"
#include "../schema/schema.h"

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
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }

    DtwResource_rename(resource,new_name);
    if(DtwResource_error(resource)){
        char *error_mensage = DtwResource_get_error_message(resource);
        LuaCEmbedResponse *response = LuaCEmbed_send_error(error_mensage);
        DtwResource_clear_errors(resource);
        return  response;
    }
    return  LuaCEmbed_send_table(self);

}
LuaCEmbedResponse * resource_try_rename(LuaCEmbedTable  *self,LuaCEmbed *args) {
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    char *new_name = LuaCEmbed_get_str_arg(args,0);
    args_protect(args)
    DtwResource_rename(resource,new_name);
    resource_protect(resource,args)
    LuaCEmbedTable *multi_response = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_append_bool(multi_response,true);
    return LuaCEmbed_send_multi_return(multi_response);

}
LuaCEmbedResponse * resource_set_value(LuaCEmbedTable  *self,LuaCEmbed *args){
    Writeble  *write_obj = create_writeble(args,0);
    if(write_obj->error){
        LuaCEmbedResponse *response =  write_obj->error;
        Writeble_free(write_obj);
        return  response;
    }
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource_set_any(resource,write_obj->content, write_obj->size,write_obj->is_binary);
    Writeble_free(write_obj);
    if(DtwResource_error(resource)){
        char *error_mensage = DtwResource_get_error_message(resource);
        LuaCEmbedResponse *response = LuaCEmbed_send_error(error_mensage);
        DtwResource_clear_errors(resource);
        return  response;
    }

    return  LuaCEmbed_send_table(self);
}

LuaCEmbedResponse * resource_try_set_value(LuaCEmbedTable  *self,LuaCEmbed *args) {
    Writeble  *write_obj = create_writeble(args,1);
    writeble_protect(write_obj,args)


    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource_set_any(resource,write_obj->content, write_obj->size,write_obj->is_binary);
    Writeble_free(write_obj);
    resource_protect(resource,args)

    LuaCEmbedTable * multi_response = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_append_bool(multi_response,true);
    return LuaCEmbed_send_multi_return(multi_response);
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

LuaCEmbedResponse * resource_try_destroy(LuaCEmbedTable  *self,LuaCEmbed *args) {
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource_destroy(resource);
    resource_protect(resource,args)
    LuaCEmbedTable *multi_response =  LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_append_bool(multi_response,true);
    return LuaCEmbed_send_multi_return(multi_response);
}

LuaCEmbedResponse * unload_resurce(LuaCEmbedTable  *self, LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource_unload(resource);
    return  LuaCEmbed_send_table(self);
}

LuaCEmbedResponse * lock_resource(LuaCEmbedTable  *self, LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    if(DtwResource_lock(resource)) {
        return LuaCEmbed_send_bool(false);
    }
    return LuaCEmbed_send_bool(true);
}

LuaCEmbedResponse * unlock_resource(LuaCEmbedTable  *self, LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource_unlock(resource);
    return  LuaCEmbed_send_table(self);
}


LuaCEmbedResponse * resource_set_value_in_sub_resource(LuaCEmbedTable  *self,LuaCEmbed *args){

    char *folder = LuaCEmbed_get_str_arg(args,0);
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }
    Writeble  *write_obj = create_writeble(args,1);
    if(write_obj->error){
        LuaCEmbedResponse *response =  write_obj->error;
        Writeble_free(write_obj);
        return  response;
    }
    DtwResource *values = DtwResource_sub_resource(resource,folder);
    DtwResource_set_any(values,write_obj->content,write_obj->size,write_obj->is_binary);
    Writeble_free(write_obj);
    if(DtwResource_error(resource)){
        char *error_mensage = DtwResource_get_error_message(resource);
        LuaCEmbedResponse *response = LuaCEmbed_send_error(error_mensage);
        DtwResource_clear_errors(resource);
        return  response;
    }

    return LuaCEmbed_send_table(self);

}
LuaCEmbedResponse * resource_try_set_value_in_sub_resource(LuaCEmbedTable  *self,LuaCEmbed *args) {
    char *folder = LuaCEmbed_get_str_arg(args,0);
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    args_protect(args)
    Writeble  *write_obj = create_writeble(args,1);
    writeble_protect(write_obj,args)

    DtwResource *values = DtwResource_sub_resource(resource,folder);
    DtwResource_set_binary(values,write_obj->content,write_obj->size);
    Writeble_free(write_obj);
    LuaCEmbedTable *multi_response =  LuaCembed_new_anonymous_table(args);
    resource_protect(resource,args)
    return LuaCEmbed_send_multi_return(multi_response);
}

LuaCEmbedResponse * resource_is_blob(LuaCEmbedTable  *self,LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource_load(resource);
    return LuaCEmbed_send_bool(resource->is_binary);
}


LuaCEmbedResponse * resource_get_type(LuaCEmbedTable  *self,LuaCEmbed *args) {
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    const char *type = DtwResource_type_in_str(resource);

    return LuaCEmbed_send_str(type);
}


LuaCEmbedResponse *resource_get_transaction(LuaCEmbedTable *self,LuaCEmbed *args) {
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    LuaCEmbedTable * transaction_table = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_set_bool_prop(transaction_table,IS_A_REF,true);
    DtwTransaction *transaction = resource->root_props->transaction;
    private_transaction_add_base_methods(transaction_table,transaction);
    return LuaCEmbed_send_table(transaction_table);

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

    LuaCEmbedTable_set_method(self,RESOURCE_GET_TYPE,resource_get_type);
    LuaCEmbedTable_set_method(self,LIST_METHOD,resource_list);
    LuaCEmbedTable_set_method(self,EACH_METHOD,resource_foreach);
    LuaCEmbedTable_set_method(self,MAP_METHOD,resource_map);
    LuaCEmbedTable_set_method(self,COUNT_METHOD,resource_count);
    LuaCEmbedTable_set_method(self,FIND_METHOD,resource_find);
    LuaCEmbedTable_set_method(self,FILTER_METHOD,resource_filter);

    LuaCEmbedTable_set_method(self,RESOURCE_GET_STRING,resource_value_string);
    LuaCEmbedTable_set_method(self,RESOURCE_GET_NUMBER,resource_value_number);
    LuaCEmbedTable_set_method(self,RESOURCE_GET_BOOL,resource_value_bool);

    LuaCEmbedTable_set_method(self, SUB_RESOURCE_NEXT_METHOD, resource_sub_resource_next);
    LuaCEmbedTable_set_method(self, SUB_RESOURCE_NOW_METHOD, resource_sub_resource_now);
    LuaCEmbedTable_set_method(self, SUB_RESOURCE_NOW_IN_UNIX, resource_sub_resource_now_in_unix);
    LuaCEmbedTable_set_method(self,SUB_RESOURCE_RANDOM,resource_sub_resource_random);
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

    LuaCEmbedTable_set_method(self,DANGEROUS_REMOVE_PROP_METHOD,dangerous_remove_schema_prop);
    LuaCEmbedTable_set_method(self,DANGEROUS_RENAME_PROP_METHOD,dangerous_rename_schema_prop);
    LuaCEmbedTable_set_method(self, GET_RESOURCE_MATCHING_PRIMARY_KEY_METHOD, get_resource_match_schema_by_primary_key);
    LuaCEmbedTable_set_method(self,GET_RESOURCE_BY_NAME_ID,get_resource_by_name_id);

    LuaCEmbedTable_set_method(self,RESOURCE_NEW_DATABASE_SCHEMA,resource_new_schema);
    LuaCEmbedTable_set_method(self,SCHEMA_LIST_RESOURCE_METHOD,schema_list_resources);
    LuaCEmbedTable_set_method(self, SCHEMA_FIND_RESOURCE_METHOD, schema_find_resource);
    LuaCEmbedTable_set_method(self,SCHEMA_MAP_RESOURCE_METHOD,schema_map_resource);
    LuaCEmbedTable_set_method(self,SCHEMA_COUNT_RESOURCE_METHOD,schema_count_resource);
    LuaCEmbedTable_set_method(self, SCHEMA_EACH_METHOD, resource_schema_each);
    LuaCEmbedTable_set_method(self,SCHEMA_FILTER_METHOD,schema_filter_resource);

    LuaCEmbedTable_set_method(self, SCHEMA_NEW_INSERTION, Resource_new_insertion);

    LuaCEmbedTable_set_method(self, RESOURCE_TRY_SET_VALUE_METHOD, resource_try_set_value);
    LuaCEmbedTable_set_method(self,RESOURCE_TRY_RENAME_METHOD,resource_try_rename);
    LuaCEmbedTable_set_method(self,RESOURCE_TRY_DESTROY,resource_try_destroy);
    LuaCEmbedTable_set_method(self,RESOURCE_TRY_NEW_SCHEMA,resource_try_new_schema);
    LuaCEmbedTable_set_method(self,RESOURCE_TRY_SET_VALUE_IN_SUB_RESOURCE_METHOD,resource_try_set_value_in_sub_resource);
    LuaCEmbedTable_set_method(self,RESOURCE_TRY_NEW_INSERTION_METHOD,Resource_try_new_insertion);
    LuaCEmbedTable_set_method(self,TRY_GET_RESOURCE_MATCHING_PRIMARY_KEY_METHOD,try_get_resource_match_schema_by_primary_key);
    LuaCEmbedTable_set_method(self,TRY_GET_RESOURCE_BY_NAME_ID,try_get_resource_by_name_id);
    LuaCEmbedTable_set_method(self,TRY_DANGEROUS_RENAME_PROP_METHOD,try_dangerous_rename_schema_prop);
    LuaCEmbedTable_set_method(self,TRY_DANGEROUS_REMOVE_PROP_METHOD,try_dangerous_remove_schema_prop);
    LuaCEmbedTable_set_method(self,TRY_SUB_RESOURCE_METHOD,try_resource_sub_resource_method);
    LuaCEmbedTable_set_method(self,TRY_SUB_RESOURCE_NEXT_METHOD,try_resource_sub_resource_next);
    LuaCEmbedTable_set_method(self,TRY_SUB_RESOURCE_NOW_METHOD,try_resource_sub_resource_now);
    LuaCEmbedTable_set_method(self,TRY_SUB_RESOURCE_NOW_IN_UNIX,try_resource_sub_resource_now_in_unix);
    LuaCEmbedTable_set_method(self,TRY_SUB_RESOURCE_RANDON,try_resource_sub_resource_random);
    LuaCEmbedTable_set_method(self,TRY_SCHEMA_LIST,try_schema_list_resources);
    LuaCEmbedTable_set_method(self,GET_TRANSACTION_METHOD,resource_get_transaction);


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