

DtwJsonTransactionError * dtw_validate_json_transaction(cJSON *json_entry){
    if(json_entry->type != cJSON_Array){
        return private_new_DtwJsonTransactionError(
                JSON_TRANSACTION_WRONG_TYPE,
                "the initial value its not an array",
                NULL
                );
    }
    long  element_size = cJSON_GetArraySize(json_entry);
    for(long  i = 0; i <element_size; i++){

        cJSON *current_obj = cJSON_GetArrayItem(json_entry,i);

        DtwJsonTransactionError  *current_error = private_dtw_validate_json_action_transaction(current_obj);
        if(current_error){
            char formated_path[20] = {0};
            sprintf(formated_path,"[%ld]",i);
            DtwJsonTransactionError_prepend_path(current_error,formated_path);

            return current_error;
        }

    }

    return NULL;
}

DtwJsonTransactionError * dtw_validate_json_transaction_file(const char *filename){
    char *content = dtw_load_string_file_content(filename);
    if(!content){
        char *formated_mensage = (char*)calloc(sizeof (char), strlen(filename) + 50);
        sprintf(formated_mensage, "file: %s not found",filename);
        DtwJsonTransactionError  *error = private_new_DtwJsonTransactionError(
                DTW_ACTION_FILE_NOT_FOUND,
                formated_mensage,
                NULL
                );
        free(formated_mensage);
        return error;
    }
    cJSON *parsed = cJSON_Parse(content);
    if(!parsed){
        char *formated_mensage = (char*)calloc(sizeof (char), strlen(filename) + 50);
        sprintf(formated_mensage, "file: %s its not an valid json",filename);
        DtwJsonTransactionError  *error = private_new_DtwJsonTransactionError(
                DTW_ACTION_ITS_NOT_JSON,
                formated_mensage,
                NULL
        );
        free(formated_mensage);
        free(content);
        return error;
    }
    DtwJsonTransactionError *generated_error = dtw_validate_json_transaction(parsed);

    free(content);
    cJSON_Delete(parsed);
    return generated_error;
}


DtwTransaction * newDtwTransaction_from_json(cJSON *json_entry){
    DtwJsonTransactionError *generated_error = dtw_validate_json_transaction(json_entry);
    if(generated_error) {
        DtwJsonTransactionError_free(generated_error);
        return NULL;
    }
    DtwTransaction *self = newDtwTransaction();
    long size = cJSON_GetArraySize(json_entry);
    for(int i  = 0; i < size; i ++){
        cJSON  *object_action = cJSON_GetArrayItem(json_entry,i);
        DtwActionTransaction  *current_action = private_DtwActionTransaction_parse_json_object(object_action);
        DtwTransaction_append_action(self,current_action);
    }
    return self;
}



DtwTransaction * newDtwTransaction_from_json_file(const char *filename){
    char *content = dtw_load_string_file_content(filename);
    if(!content){
        return NULL;
    }

    cJSON  *element = cJSON_Parse(content);
    free(content);
    if(!element){
        return NULL;
    }

    DtwJsonTransactionError *error = dtw_validate_json_transaction(element);
    if(error){
        DtwJsonTransactionError_free(error);
        cJSON_Delete(element);
        return NULL;
    }


    DtwTransaction  *self = newDtwTransaction_from_json(element);
    cJSON_Delete(element);

    return self;
}

cJSON * DtwTransaction_dumps_to_json(struct DtwTransaction *self){
    cJSON * json_array = cJSON_CreateArray();
    for(int i =0; i < self->size; i ++){

        cJSON_AddItemToArray(
                json_array,
                private_DtwActionTransaction_create_json_object(self->actions[i])
        );

    }
    return json_array;
}


void DtwTransaction_dumps_to_json_file(struct DtwTransaction *self,const char *filename){
    cJSON *json_array = DtwTransaction_dumps_to_json(self);
    char *result = cJSON_Print(json_array);
    dtw_write_string_file_content(filename,result);
    free(result);
    cJSON_Delete(json_array);
}

void DtwTransaction_represent(struct DtwTransaction *self){

    for(int i = 0; i < self->size; i++){

        DtwActionTransaction_represent(self->actions[i]);
        printf("------------------------------------\n");

    }

}