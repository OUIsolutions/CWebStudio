

bool DtwTree_loads_json_tree(struct DtwTree *self, const char *all_tree){
    //load json
    cJSON *json_tree = cJSON_Parse(all_tree);
    if(json_tree == NULL){
        return false;
    }
    DtwJsonTreeError *json_error = DtwJsonTreeError_validate_json_tree_by_cJSON(json_tree);
    if(json_error){
        DtwJsonTreeError_free(json_error);
        return  false;
    }

    int size = cJSON_GetArraySize(json_tree);
    for(int i = 0; i < size; i++){

        cJSON *json_tree_part = cJSON_GetArrayItem(json_tree, i);
        cJSON *path = cJSON_GetObjectItemCaseSensitive(json_tree_part, "path");
        cJSON *original_path = cJSON_GetObjectItemCaseSensitive(json_tree_part, "original_path");
        cJSON *hardware_sha = cJSON_GetObjectItemCaseSensitive(json_tree_part, "hardware_sha256");
        cJSON *hardware_content_size = cJSON_GetObjectItemCaseSensitive(json_tree_part, "hardware_content_size");
        cJSON *last_modification_in_unix_time = cJSON_GetObjectItemCaseSensitive(json_tree_part, "last_modification_in_unix_time");
        cJSON *content_size = cJSON_GetObjectItemCaseSensitive(json_tree_part, "content_size");
        cJSON *is_binary = cJSON_GetObjectItemCaseSensitive(json_tree_part, "is_binary");
        cJSON *content = cJSON_GetObjectItemCaseSensitive(json_tree_part, "content");
        cJSON *pending_action = cJSON_GetObjectItemCaseSensitive(json_tree_part, "pending_action");
        cJSON *ignore = cJSON_GetObjectItemCaseSensitive(json_tree_part, "ignore");
   
        struct DtwTreePart *part = newDtwTreePartEmpty(
                path->valuestring
                );

        if(original_path != NULL){
            if(  part->path->original_path_string){
                free(  part->path->original_path_string);
            }
            part->path->original_path_string = strdup(original_path->valuestring);

        }

        if(hardware_sha != NULL){
            part->content_exist_in_hardware = true;
            part->hawdware_content_sha = (char *)realloc(part->hawdware_content_sha,strlen(hardware_sha->valuestring)+1);
            strcpy(part->hawdware_content_sha,hardware_sha->valuestring);
            
        }

        if(hardware_content_size != NULL){
            part->content_exist_in_hardware = true;
            part->hardware_content_size = hardware_content_size->valueint;
        }
        
        if(last_modification_in_unix_time != NULL){
            part->last_modification_time = last_modification_in_unix_time->valueint;
        }
    
        if(is_binary != NULL){
            part->is_binary = is_binary->valueint;
        }
        
        if(content_size != NULL){
            part->content_size = content_size->valueint;
        }

        if(content != NULL){

            if(part->is_binary){
                long out_size;
                unsigned char *decoded =dtw_base64_decode(
                    content->valuestring,
                    &out_size
                );
                DtwTreePart_set_binary_content(part,decoded,out_size);
                free(decoded);
            }
           else{
                DtwTreePart_set_string_content(part,content->valuestring);
           } 
        }
        if(pending_action != NULL &&  pending_action->valuestring){
    
            part->pending_action = private_dtw_convert_string_to_action(
                pending_action->valuestring
            );
        }
        if(ignore != NULL){
            part->ignore = ignore->valueint;
        }

        DtwTree_add_tree_part_getting_onwership(self, part);
        
    }
    cJSON_Delete(json_tree);
    return  true;
}


bool DtwTree_loads_json_tree_from_file( DtwTree *self, const char *path){
    char *content = dtw_load_string_file_content(path);
    if(content == NULL){
        return false;
    }
    bool result = DtwTree_loads_json_tree(self,content);
    free(content);
    return result;
}

char * DtwTree_dumps_tree_json( DtwTree *self, DtwTreeProps  props){


    DtwTreeProps formated_props = DtwTreeProps_format_props(props);

    cJSON *json_array = cJSON_CreateArray();
    for(int i = 0; i < self->size; i++){
       
        cJSON *json_tree_part = cJSON_CreateObject();
        DtwTreePart *tree_part = self->tree_parts[i];
        char *path_string = DtwPath_get_path(tree_part->path);
        if(path_string ==NULL){
            cJSON_Delete(json_tree_part);
            continue;
        }

        if(formated_props.ignored_elements == DTW_INCLUDE && tree_part->ignore){
            continue;
        }
        
        if(tree_part->ignore){
            cJSON_AddItemToObject(
                json_tree_part, 
                "ignore", 
                cJSON_CreateBool(true)
            );
        }

        cJSON_AddItemToObject(
            json_tree_part, 
            "path", 
            cJSON_CreateString(path_string)
        );
        
        
        
        if(formated_props.path_atributes == DTW_INCLUDE ){
                char *dir_string = DtwPath_get_dir(tree_part->path);
                char *full_name_string = DtwPath_get_full_name(tree_part->path);
                char *name_string = DtwPath_get_name(tree_part->path);
                char *extension_string = DtwPath_get_extension(tree_part->path);
                if(tree_part->path->original_path_string != path_string){
                    cJSON_AddItemToObject(
                        json_tree_part, 
                        "original_path", 
                        cJSON_CreateString(tree_part->path->original_path_string)
                    );
                }
                cJSON_AddItemToObject(
                    json_tree_part, 
                    "dir", 
                    cJSON_CreateString(dir_string)
                );
                
                cJSON_AddItemToObject(
                    json_tree_part, 
                    "full_name", 
                    cJSON_CreateString(full_name_string)
                );
                
                cJSON_AddItemToObject(
                    json_tree_part, 
                    "name", 
                    cJSON_CreateString(name_string)
                );
                
                cJSON_AddItemToObject(
                    json_tree_part, 
                    "extension", 
                    cJSON_CreateString(extension_string)
                );


        }


        if(formated_props.hadware_data == DTW_INCLUDE && tree_part->metadata_loaded){
            cJSON_AddItemToObject(
                json_tree_part, 
                "hardware_sha256", 
                cJSON_CreateString(tree_part->hawdware_content_sha)
            );
            cJSON_AddItemToObject(
                json_tree_part, 
                "last_modification_in_unix", 
                cJSON_CreateNumber(tree_part->last_modification_time)
            );

            cJSON_AddItemToObject(
                json_tree_part, 
                "hardware_content_size", 
                cJSON_CreateNumber(tree_part->hardware_content_size)
            );

            cJSON_AddItemToObject(
                json_tree_part, 
                "last_modification", 
                cJSON_CreateString(tree_part->last_modification_in_str)
            );
        }

        if(formated_props.content_data == DTW_INCLUDE && tree_part->content){
            char *content_sha = DtwTreePart_get_content_sha(tree_part);
            cJSON_AddItemToObject(
                json_tree_part, 
                "content_size", 
                cJSON_CreateNumber(tree_part->content_size)
            );

            cJSON_AddItemToObject(
                json_tree_part, 
                "content_sha256", 
                cJSON_CreateString(content_sha)
            );

        }

        if(formated_props.content == DTW_INCLUDE && tree_part->content){

            cJSON_AddItemToObject(
                json_tree_part, 
                "is_binary", 
                cJSON_CreateBool(tree_part->is_binary)
            );  
            if(tree_part->is_binary == false){
                cJSON_AddItemToObject(
                    json_tree_part, 
                    "content", 
                    cJSON_CreateString(DtwTreePart_get_content_string_by_reference(tree_part))
                );
            }
            else{
                char *content_base64 = dtw_base64_encode(tree_part->content, tree_part->content_size);
         
     
                cJSON_AddItemToObject(
                    json_tree_part, 
                    "content", 
                    cJSON_CreateString(content_base64)
                );  
                free(content_base64);
            }
        }
       
        //adding action 
        const char *action_string = private_dtw_convert_action_to_string(tree_part->pending_action);
        if(action_string != NULL){
            cJSON_AddItemToObject(
                json_tree_part, 
                "pending_action", 
                cJSON_CreateString(action_string)
            );
        } 
        //Add json_tree_part  
        cJSON_AddItemToArray(json_array,json_tree_part);

    }
    
    char *json_string = cJSON_Print(json_array);
    //set ident to 4 spaces
    if(formated_props.minification == DTW_MIMIFY){
        cJSON_Minify(json_string);
    }
    cJSON_Delete(json_array);
    return json_string;
}

void  DtwTree_dumps_tree_json_to_file(struct DtwTree *self, const char *path, DtwTreeProps  props){
    char *json_string = DtwTree_dumps_tree_json(self,props);
    dtw_write_string_file_content(path,json_string);
    free(json_string);
}