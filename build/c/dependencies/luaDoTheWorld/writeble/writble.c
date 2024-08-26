
bool handle_table_writble(Writeble *self,LuaCEmbed *args,int index){
    LuaCEmbedTable * element = LuaCEmbed_get_arg_table(args,index);
    if(LuaCEmbedTable_get_type_prop(element,DTW_TYPE) != LUA_CEMBED_NUMBER){
        return false;
    }

    int type = LuaCembedTable_get_long_prop(element,DTW_TYPE);


    if(type == DTW_RESOURCE_TYPE) {
        DtwResource *resource = (DtwResource *) LuaCembedTable_get_long_prop(element, RESOURCE_POINTER);
        self->content = DtwResource_get_any(resource, &self->size, &self->is_binary);
        if (DtwResource_error(resource)) {
            char *message = DtwResource_get_error_message(resource);
            self->error = LuaCEmbed_send_error(message);
            DtwResource_clear_errors(resource);
            return false;
        }
        return true;
    }

    if(type == DTW_TREE_PART_TYPE){
        DtwTreePart *part = (DtwTreePart*)LuaCembedTable_get_long_prop(element,TREE_PART_POINTER);
        DtwTreePart_load_content_from_hardware(part);
        if(part->content==NULL){
            return false;
        }
        self->content = part->content;
        self->size =part->content_size;
        self->is_binary = part->content_size;
        return true;
    }
    if(type == DTW_ACTION_TRANSACTION_TYPE){
        DtwActionTransaction *transaction= (DtwActionTransaction*)LuaCembedTable_get_long_prop(element,TRANSACTION_POINTER);
        if(transaction->content == NULL){
            return false;
        }
        self->content = transaction->content;
        self->size=  transaction->size;
        self->is_binary =transaction->is_binary;
        return true;
    }

    return false;

}
Writeble  * create_writeble(LuaCEmbed *args,int index){
    Writeble *self =  (Writeble*)malloc(sizeof(Writeble));
    *self = (Writeble){0};
    long total_args = LuaCEmbed_get_total_args(args);
    if(total_args == 0){
        self->error = LuaCEmbed_send_error(ARGUMENT_NOT_PROVIDED);
        return self;
    }

    int type_to_write = LuaCEmbed_get_arg_type(args,index);
    bool writeble = false;
    if(type_to_write == LUA_CEMBED_STRING){
        self->content = (unsigned  char*)LuaCEmbed_get_raw_str_arg(args,&self->size,index);
        for(long i = 0; i < self->size;i++){
            if(self->content[i] == 0){
                self->is_binary = true;
                break;
            }
        }

        writeble = true;
    }

    if(type_to_write == LUA_CEMBED_NUMBER){
        self->clear_content = true;
        double content = LuaCEmbed_get_double_arg(args,index);
        double rest = content - (double)(long ) content;
        if(rest == 0){
            char formatted[20] = {0};
            sprintf(formatted,"%ld",(long)content);
            self->content = (unsigned char*)strdup(formatted);
            self->size = (long)strlen(formatted);
        }
        else{
            char formatted[20] = {0};
            sprintf(formatted,"%lf",content);
            self->content = (unsigned char*)strdup(formatted);
            self->size = (long)strlen(formatted);
        }
        writeble = true;
    }
    if(type_to_write == LUA_CEMBED_BOOL){
        bool content  = LuaCEmbed_get_bool_arg(args,index);
        const char *converted = content ? "true":"false";
        self->content = (unsigned char*)converted;
        self->size = (long)strlen(converted);
        writeble = true;
    }

    if(type_to_write == LUA_CEMBED_TABLE){
        writeble = handle_table_writble(self,args,index);
    }

    bool its_not_writible_and_no_other_errors = !writeble && self->error == NULL;
    if(its_not_writible_and_no_other_errors){
        char *error = private_LuaCembed_format(NOT_WRITEBLE_ELEMENT,LuaCembed_convert_arg_code(type_to_write));
        self->error = LuaCEmbed_send_error(error);
        free(error);
        return self;
    }

    return self;
}
void Writeble_free(Writeble *self){
    if(self->clear_content){
        free(self->content);
    }
    free(self);
}