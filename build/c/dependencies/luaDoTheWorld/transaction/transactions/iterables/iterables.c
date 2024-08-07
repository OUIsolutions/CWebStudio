


LuaCEmbedResponse  * transaction_index(LuaCEmbedTable *self,LuaCEmbed *args){

    long index = LuaCEmbed_get_long_arg(args,1);
    if(LuaCEmbed_has_errors(args)){
        printf("pegou aqui passando %s\n",LuaCEmbed_get_str_arg(args,1));
        char *error = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error);
    }
    long converted = index -1;

    DtwTransaction *transaction = (DtwTransaction*)LuaCembedTable_get_long_prop(self,TRANSACTION_POINTER);
    if(converted >= transaction->size || converted < 0){
        return NULL;
    }
    LuaCEmbedTable  *table = raw_create_action_transaction(args,transaction->actions[converted]);
    return LuaCEmbed_send_table(table);
}

LuaCEmbedResponse  * transaction_foreach(LuaCEmbedTable *self,LuaCEmbed *args){
    DtwTransaction *transaction = (DtwTransaction*)LuaCembedTable_get_long_prop(self,TRANSACTION_POINTER);
    for(long i = 0 ; i < transaction->size; i++){
        DtwActionTransaction *action = transaction->actions[i];
        LuaCEmbedTable  *table = raw_create_action_transaction(args,action);
        LuaCEmbedTable  * args_of_callbac = LuaCembed_new_anonymous_table(args);
        LuaCEmbedTable_append_table(args_of_callbac,table);
        LuaCEmbed_run_args_lambda(args,0,args_of_callbac,0);
        if(LuaCEmbed_has_errors(args)){
            char *error = LuaCEmbed_get_error_message(args);
            return LuaCEmbed_send_error(error);
        }
    }
    return  NULL;
}

LuaCEmbedResponse  * transaction_map(LuaCEmbedTable *self,LuaCEmbed *args){

    DtwTransaction *transaction = (DtwTransaction*)LuaCembedTable_get_long_prop(self,TRANSACTION_POINTER);
    LuaCEmbedTable *final_map = LuaCembed_new_anonymous_table(args);
    for(long i = 0 ; i < transaction->size; i++){
        DtwActionTransaction *action = transaction->actions[i];
        LuaCEmbedTable  *table = raw_create_action_transaction(args,action);
        LuaCEmbedTable  * args_of_callbac = LuaCembed_new_anonymous_table(args);
        LuaCEmbedTable_append_table(args_of_callbac,table);
        LuaCEmbedTable * response_values = LuaCEmbed_run_args_lambda(args,0,args_of_callbac,0);
        if(LuaCEmbed_has_errors(args)){

            char *error = LuaCEmbed_get_error_message(args);
            return LuaCEmbed_send_error(error);
        }

        int response_type =LuaCEmbedTable_get_type_by_index(response_values,0);
        if(response_type!= LUA_CEMBED_NIL && response_type != LUA_CEMBED_NOT_FOUND){
            LuaCEmbedTable_append_evaluation(final_map,"%s[1]",response_values->global_name);
        }
    }

    return  LuaCEmbed_send_table(final_map);
}

LuaCEmbedResponse  * transaction_find(LuaCEmbedTable *self,LuaCEmbed *args){

    DtwTransaction *transaction = (DtwTransaction*)LuaCembedTable_get_long_prop(self,TRANSACTION_POINTER);
    for(long i = 0 ; i < transaction->size; i++){
        DtwActionTransaction *action = transaction->actions[i];
        LuaCEmbedTable  *table = raw_create_action_transaction(args,action);
        LuaCEmbedTable  * args_of_callbac = LuaCembed_new_anonymous_table(args);
        LuaCEmbedTable_append_table(args_of_callbac,table);
        LuaCEmbedTable * response_values = LuaCEmbed_run_args_lambda(args,0,args_of_callbac,1);
        if(LuaCEmbed_has_errors(args)){
            char *error = LuaCEmbed_get_error_message(args);
            return LuaCEmbed_send_error(error);
        }
        int response_type =LuaCEmbedTable_get_type_by_index(response_values,0);
        if(response_type ==  LUA_CEMBED_BOOL){
            return LuaCEmbed_send_bool(
                    LuaCEmbedTable_get_bool_by_index(response_values,0)
                    );
        }
    }

    return  NULL;
}


LuaCEmbedResponse  * transaction_count(LuaCEmbedTable *self,LuaCEmbed *args){

    DtwTransaction *transaction = (DtwTransaction*)LuaCembedTable_get_long_prop(self,TRANSACTION_POINTER);
    long total  = 0;
    for(long i = 0 ; i < transaction->size; i++){
        DtwActionTransaction *action = transaction->actions[i];
        LuaCEmbedTable  *table = raw_create_action_transaction(args,action);
        LuaCEmbedTable  * args_of_callbac = LuaCembed_new_anonymous_table(args);
        LuaCEmbedTable_append_table(args_of_callbac,table);
        LuaCEmbedTable * response_values = LuaCEmbed_run_args_lambda(args,0,args_of_callbac,1);
        if(LuaCEmbed_has_errors(args)){
            char *error = LuaCEmbed_get_error_message(args);
            return LuaCEmbed_send_error(error);
        }
        int response_type =LuaCEmbedTable_get_type_by_index(response_values,0);
        if(response_type !=  LUA_CEMBED_BOOL){
            continue;
        }
        bool value = LuaCEmbedTable_get_bool_by_index(response_values,0);
        if(value){
            total+=1;
        }

    }

    return  LuaCEmbed_send_long(total);
}

