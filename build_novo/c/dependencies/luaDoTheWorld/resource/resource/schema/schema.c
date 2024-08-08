//
// Created by mateusmoutinho on 22/05/24.
//

LuaCEmbedResponse * resource_new_schema(LuaCEmbedTable  *self, LuaCEmbed *args){
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwDatabaseSchema *schema = DtwResource_newDatabaseSchema(resource);
    if(DtwResource_error(resource)){
        char *error_mensage = DtwResource_get_error_message(resource);
        LuaCEmbedResponse *response = LuaCEmbed_send_error(error_mensage);
        DtwResource_clear_errors(resource);
        return  response;
    }

    LuaCEmbedTable  *created = raw_create_database_schema(args,schema);
    return LuaCEmbed_send_table(created);

}

LuaCEmbedResponse * resource_try_new_schema(LuaCEmbedTable  *self, LuaCEmbed *args) {
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwDatabaseSchema *schema = DtwResource_newDatabaseSchema(resource);
    LuaCEmbedTable *multi_response = LuaCembed_new_anonymous_table(args);

    resource_protect(resource,args)

    LuaCEmbedTable_append_bool(multi_response,true);
    LuaCEmbedTable  *created = raw_create_database_schema(args,schema);
    LuaCEmbedTable_append_table(multi_response,created);
    return  LuaCEmbed_send_multi_return(multi_response);

}

LuaCEmbedResponse  * Resource_new_insertion(LuaCEmbedTable *self, LuaCEmbed *args){
    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource  *created = DtwResource_new_schema_insertion(resource);
    if(DtwResource_error(resource)){
        char *message = DtwResource_get_error_message(resource);
        LuaCEmbedResponse *response = LuaCEmbed_send_error(message);
        DtwResource_clear_errors(resource);
        return  response;
    }

    LuaCEmbedTable  *sub = raw_create_resource(args,created);

    return LuaCEmbed_send_table(sub);
}
LuaCEmbedResponse  * Resource_try_new_insertion(LuaCEmbedTable *self, LuaCEmbed *args) {
    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource  *created = DtwResource_new_schema_insertion(resource);
    resource_protect(resource,args)
    LuaCEmbedTable *multi_response =  LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_append_bool(multi_response,true);
    LuaCEmbedTable  *sub = raw_create_resource(args,created);
    LuaCEmbedTable_append_table(multi_response,sub);
    return  LuaCEmbed_send_multi_return(multi_response);

}


LuaCEmbedResponse  * get_resource_match_schema_by_primary_key(LuaCEmbedTable *self, LuaCEmbed *args){
    char *key = LuaCEmbed_get_str_arg(args,0);
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
    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);

    DtwResource *founded = DtwResource_find_by_primary_key_with_binary(resource,key,write_obj->content,write_obj->size);
    Writeble_free(write_obj);
    if(DtwResource_error(resource)){
        char *message = DtwResource_get_error_message(resource);
        LuaCEmbedResponse *response = LuaCEmbed_send_error(message);
        DtwResource_clear_errors(resource);
        return  response;
    }
    if(founded ==NULL){
        return NULL;
    }
    LuaCEmbedTable  *sub = raw_create_resource(args,founded);
    return LuaCEmbed_send_table(sub);
}

LuaCEmbedResponse  * try_get_resource_match_schema_by_primary_key(LuaCEmbedTable *self, LuaCEmbed *args) {
    char *key = LuaCEmbed_get_str_arg(args,0);
    args_protect(args)
    Writeble  *write_obj = create_writeble(args,1);
    writeble_protect(write_obj,args)
    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource *founded = DtwResource_find_by_primary_key_with_binary(resource,key,write_obj->content,write_obj->size);
    Writeble_free(write_obj);
    resource_protect(resource,args)
    LuaCEmbedTable *multi_response =  LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_append_bool(multi_response,true);
    if(founded== NULL){
        return  LuaCEmbed_send_multi_return(multi_response);
    }

    LuaCEmbedTable  *sub = raw_create_resource(args,founded);
    LuaCEmbedTable_append_table(multi_response,sub);
    return  LuaCEmbed_send_multi_return(multi_response);
}

LuaCEmbedResponse  * get_resource_by_name_id(LuaCEmbedTable *self, LuaCEmbed *args){
    char *name_id = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }

    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource *founded = DtwResource_find_by_name_id(resource,name_id);
    if(DtwResource_error(resource)){
        char *message = DtwResource_get_error_message(resource);
        LuaCEmbedResponse *response = LuaCEmbed_send_error(message);
        DtwResource_clear_errors(resource);
        return  response;
    }
    if(founded ==NULL){
        return NULL;
    }
    LuaCEmbedTable  *sub = raw_create_resource(args,founded);
    return LuaCEmbed_send_table(sub);

}

LuaCEmbedResponse  * try_get_resource_by_name_id(LuaCEmbedTable *self, LuaCEmbed *args) {
    char *name_id = LuaCEmbed_get_str_arg(args,0);
    args_protect(args)
    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource *founded = DtwResource_find_by_name_id(resource,name_id);
   resource_protect(resource,args)
    LuaCEmbedTable *multi_response =  LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_append_bool(multi_response,true);
    if(founded== NULL){
        return  LuaCEmbed_send_multi_return(multi_response);
    }

    LuaCEmbedTable  *sub = raw_create_resource(args,founded);
    LuaCEmbedTable_append_table(multi_response,sub);
    return  LuaCEmbed_send_multi_return(multi_response);
}


LuaCEmbedResponse  * dangerous_rename_schema_prop(LuaCEmbedTable *self,LuaCEmbed *args){
    char *key = LuaCEmbed_get_str_arg(args,0);
    char *new_name = LuaCEmbed_get_str_arg(args,1);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }


    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource_dangerous_rename_schema_prop(resource,key,new_name);
    if(DtwResource_error(resource)){
        char *message = DtwResource_get_error_message(resource);
        LuaCEmbedResponse *response = LuaCEmbed_send_error(message);
        DtwResource_clear_errors(resource);
        return  response;
    }
    return LuaCEmbed_send_table(self);
}
LuaCEmbedResponse  * try_dangerous_rename_schema_prop(LuaCEmbedTable *self,LuaCEmbed *args) {
    char *key = LuaCEmbed_get_str_arg(args,0);
    char *new_name = LuaCEmbed_get_str_arg(args,1);
    args_protect(args)

    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource_dangerous_rename_schema_prop(resource,key,new_name);
    resource_protect(resource,args)
    LuaCEmbedTable *multi_response =  LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_append_bool(multi_response,true);
    return LuaCEmbed_send_multi_return(multi_response);
}

LuaCEmbedResponse  * dangerous_remove_schema_prop(LuaCEmbedTable *self,LuaCEmbed *args){
    char *key_to_remove = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }

    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource_dangerous_remove_schema_prop(resource,key_to_remove);
    if(DtwResource_error(resource)){
        char *message = DtwResource_get_error_message(resource);
        LuaCEmbedResponse *response = LuaCEmbed_send_error(message);
        DtwResource_clear_errors(resource);
        return  response;
    }
    return LuaCEmbed_send_table(self);
}
LuaCEmbedResponse  * try_dangerous_remove_schema_prop(LuaCEmbedTable *self,LuaCEmbed *args) {
    char *key_to_remove = LuaCEmbed_get_str_arg(args,0);
    args_protect(args)

    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource_dangerous_remove_schema_prop(resource,key_to_remove);
    LuaCEmbedTable *multi_response =  LuaCembed_new_anonymous_table(args);
    resource_protect(resource,args)
    LuaCEmbedTable_append_bool(multi_response,true);
    return LuaCEmbed_send_multi_return(multi_response);
}



