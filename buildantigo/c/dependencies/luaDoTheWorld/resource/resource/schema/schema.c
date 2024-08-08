//
// Created by mateusmoutinho on 22/05/24.
//
LuaCEmbedResponse  * Resource_new_insertion(LuaCEmbedTable *self, LuaCEmbed *args){
    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResource  *created = DtwResource_new_schema_insertion(resource);
    LuaCEmbedTable  *sub = raw_create_resource(args,created);
    if(DtwResource_error(resource)){
        char *message = DtwResource_get_error_message(resource);
        return LuaCEmbed_send_error(message);
    }

    return LuaCEmbed_send_table(sub);
}


LuaCEmbedResponse  * get_resource_match_schema_by_primary_key(LuaCEmbedTable *self, LuaCEmbed *args){
    char *key = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(error_message);
    }
    Writeble  write_obj = create_writeble(args,1);
    if(write_obj.error){
        return write_obj.error;
    }
    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);

    DtwResource *founded = DtwResource_find_by_primary_key_with_binary(resource,key,write_obj.content,write_obj.size);
    if(DtwResource_error(resource)){
        char *message = DtwResource_get_error_message(resource);
        return LuaCEmbed_send_error(message);
    }
    if(!founded){
        return NULL;
    }
    LuaCEmbedTable  *sub = raw_create_resource(args,founded);
    return LuaCEmbed_send_table(sub);
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
        return LuaCEmbed_send_error(message);
    }
    if(!founded){
        return NULL;
    }
    
    LuaCEmbedTable  *sub = raw_create_resource(args,founded);

    return LuaCEmbed_send_table(sub);
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
        return LuaCEmbed_send_error(message);
    }
    return LuaCEmbed_send_table(self);
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
        return LuaCEmbed_send_error(message);
    }
    return LuaCEmbed_send_table(self);
}

LuaCEmbedResponse  * Resource_new_schema(LuaCEmbedTable *self, LuaCEmbed *args){
    DtwResource *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwSchema  *schema = DtwResource_newSchema(resource);
    LuaCEmbedTable *created_table = raw_create_schema(args,schema);
    if(DtwResource_error(resource)){
        char *message = DtwResource_get_error_message(resource);
        return LuaCEmbed_send_error(message);
    }
    return LuaCEmbed_send_table(created_table);
}

