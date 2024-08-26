

#define writeble_protect(writeble,args)if(writeble->error){\
        LuaCEmbedTable *multi_response = LuaCembed_new_anonymous_table(args);\
        LuaCEmbedTable_append_bool(multi_response,false);\
        LuaCEmbedResponse *response =  write_obj->error;\
        LuaCEmbedTable_append_string(multi_response,response->string_val);\
        Writeble_free(write_obj);\
        private_LuaCEmbedResponse_free(write_obj->error);\
        return  LuaCEmbed_send_multi_return(multi_response);\
}

#define resource_protect(resource,args)if(DtwResource_error(resource)){\
        LuaCEmbedTable *multi_response = LuaCembed_new_anonymous_table(args);\
char *error_mensage = DtwResource_get_error_message(resource);\
LuaCEmbedTable_append_bool(multi_response,false);\
LuaCEmbedTable_append_string(multi_response,error_mensage);\
DtwResource_clear_errors(resource);\
return  LuaCEmbed_send_multi_return(multi_response);\
    }

#define args_protect(args) if(LuaCEmbed_has_errors(args)){\
        char *error_message = LuaCEmbed_get_error_message(args);\
        LuaCEmbedTable *multi_response = LuaCembed_new_anonymous_table(args);\
        LuaCEmbedTable_append_bool(multi_response,false);\
        LuaCEmbedTable_append_string(multi_response,error_message);\
        LuaCEmbed_clear_errors(args);\
        return  LuaCEmbed_send_multi_return(multi_response);\
}
