
short DtwActionTransaction_convert_action_to_integer(char *action){
    if(strcmp(action,"write") == 0){
        return DTW_ACTION_WRITE;
    }

    if(strcmp(action,"move") == 0){
        return DTW_ACTION_MOVE;
    }

    if(strcmp(action,"copy") == 0){
        return DTW_ACTION_COPY;
    }

    if(strcmp(action,"delete") == 0){
        return DTW_ACTION_DELETE;
    }
    return -1;

}

const char * DtwActionTransaction_convert_action_to_string(int action){
    if(action == DTW_ACTION_WRITE){
        return "write";
    }
    if(action == DTW_ACTION_MOVE){
        return "move";
    }

    if(action == DTW_ACTION_COPY){
        return "copy";
    }
    if(action == DTW_ACTION_DELETE){
        return "delete";
    }
    return NULL;
}

DtwJsonTransactionError * private_dtw_validate_json_action_transaction(cJSON *json_obj){

    if(json_obj->type != cJSON_Object ){
        return private_new_DtwJsonTransactionError(
                JSON_TRANSACTION_WRONG_TYPE,
                "the action object its not an object",
                NULL
        );
    }

    cJSON *action = cJSON_GetObjectItem(json_obj,"action");

    if(!action){
        return private_new_DtwJsonTransactionError(
                JSON_TRANSACTION_NOT_PRESENT_VALUE,
                "the action is not present",
                "[\"action\"]"
        );
    }

    if(action->type != cJSON_String){
        return private_new_DtwJsonTransactionError(
                JSON_TRANSACTION_WRONG_TYPE,
                "the action is not an string",
                "[\"action\"]"
        );
    }


    int converted_action = DtwActionTransaction_convert_action_to_integer(action->valuestring);

    if(converted_action == -1){

        char *formated_mensage = (char*)calloc(sizeof (char),strlen(action->valuestring) + 30);
        sprintf(formated_mensage,"the action: %s its not valid",action->valuestring);
        DtwJsonTransactionError  *error = private_new_DtwJsonTransactionError(
                JSON_TRANSACTION_INVALID_ACTION,
                formated_mensage,
                "[\"action\"]"
        );
        free(formated_mensage);
        return error;
    }

    if(converted_action == DTW_ACTION_WRITE){
        cJSON  *content = cJSON_GetObjectItem(json_obj,"content");
        if(!content){
            return private_new_DtwJsonTransactionError(
                    JSON_TRANSACTION_NOT_PRESENT_VALUE,
                    "the content is not present",
                    "[\"content\"]"
            );
        }
        if(content->type != cJSON_String){
            return private_new_DtwJsonTransactionError(
                    JSON_TRANSACTION_WRONG_TYPE,
                    "the content is not an string",
                    "[\"content\"]"
            );
        }
        cJSON *is_binary = cJSON_GetObjectItem(json_obj,"is binary");
        if(is_binary){
            if(!cJSON_IsBool(is_binary)){
                return private_new_DtwJsonTransactionError(
                        JSON_TRANSACTION_WRONG_TYPE,
                        "the is binary is not an bool",
                        "[\"is binary\"]"
                );
            }
        }

    }




    cJSON *source = cJSON_GetObjectItem(json_obj,"source");
    if(!source){
        return private_new_DtwJsonTransactionError(
                JSON_TRANSACTION_NOT_PRESENT_VALUE,
                "the source is not present",
                "[\"source\"]"
        );
    }

    if(source->type != cJSON_String){
        return private_new_DtwJsonTransactionError(
                JSON_TRANSACTION_WRONG_TYPE,
                "the source is not an string",
                "[\"source\"]"
        );
    }

    if(converted_action == DTW_ACTION_MOVE || converted_action == DTW_ACTION_COPY){
        cJSON *dest = cJSON_GetObjectItem(json_obj,"dest");

        if(!dest){
            return private_new_DtwJsonTransactionError(
                    JSON_TRANSACTION_NOT_PRESENT_VALUE,
                    "the dest is not present",
                    "[\"dest\"]"
            );
        }
        if(dest->type != cJSON_String){
            return private_new_DtwJsonTransactionError(
                    JSON_TRANSACTION_WRONG_TYPE,
                    "the dest is not an string",
                    "[\"dest\"]"
            );
        }
    }
    return NULL;

}


DtwActionTransaction * private_DtwActionTransaction_parse_json_object(cJSON *json_obj){
    DtwActionTransaction  *self = newDtwActionTransaction();

    char *action = cJSON_GetObjectItem(json_obj,"action")->valuestring;
    self->action_type  = DtwActionTransaction_convert_action_to_integer(action);

    char *source = cJSON_GetObjectItem(json_obj,"source")->valuestring;
    self->source = strdup(source);

    if(self->action_type == DTW_ACTION_DELETE){
        return self;
    }

    if(self->action_type == DTW_ACTION_WRITE){
        cJSON *is_binary = cJSON_GetObjectItem(json_obj,"is binary");

        if(is_binary){
            if(is_binary->valueint){
                self->is_binary= true;
            }
        }

        char *content = cJSON_GetObjectItem(json_obj,"content")->valuestring;
        if(self->is_binary){
            self->content = dtw_base64_decode(content,&self->size);
        }
        else{
            self->content =(unsigned char*)strdup(content);
            self->size =(long)strlen(content);
        }

        return self;
    }
    char *dest  = cJSON_GetObjectItem(json_obj,"dest")->valuestring;
    self->dest = strdup(dest);
    return self;
}

cJSON *  private_DtwActionTransaction_create_json_object(DtwActionTransaction* self){
    cJSON * json_object = cJSON_CreateObject();
    cJSON_AddStringToObject(json_object,"action",DtwActionTransaction_convert_action_to_string(self->action_type));

    cJSON_AddStringToObject(json_object,"source",self->source);
    if(self->action_type ==DTW_ACTION_WRITE){
        if(self->is_binary){
            char *converted = dtw_base64_encode(self->content,self->size);
            cJSON_AddStringToObject(json_object,"content",converted);
            free(converted);
            cJSON_AddBoolToObject(json_object,"is binary",true);
        }
        else{
            cJSON_AddStringToObject(json_object,"content",(char*)self->content);
        }
    }
    if(self->action_type != DTW_ACTION_DELETE){
        cJSON_AddStringToObject(json_object,"dest",self->dest);
    }

    return json_object;
}



void DtwActionTransaction_represent(DtwActionTransaction* self){

    printf("\taction: %s\n", DtwActionTransaction_convert_action_to_string(self->action_type));
    printf("\tsource:%s\n",self->source);
    if(self->action_type == DTW_ACTION_WRITE){

        if(!self->is_binary && self->size <  30){

            printf("\tcontent : %s\n",(char*)self->content);
        }
        else{
            printf("\tcontent: impossible to show\n");
        }

        printf("\tsize:%ld\n",self->size);
        printf("\tis binary: %s\n",self->is_binary? "true":"false");
        return;
    }

    if(self->action_type != DTW_ACTION_DELETE){
        printf("\tdest: %s\n",self->dest);
    }

}

