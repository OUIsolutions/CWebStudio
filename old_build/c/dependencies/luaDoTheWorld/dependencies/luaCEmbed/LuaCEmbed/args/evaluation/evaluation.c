

int private_LuaCembed_run_code_with_args(LuaCEmbed *self,int index,const char *code,va_list args){
    PRIVATE_LUA_CEMBED_PROTECT_NUM

    int formatted_index = index + LUA_CEMBED_INDEX_DIF;

    if(LuaCEmbed_ensure_arg_exist(self,formatted_index)){
        return LUA_CEMBED_GENERIC_ERROR;
    }

    char *formated_expresion = private_LuaCembed_format_vaarg(code,args);

    char *buffer = private_LuaCembed_format(
            PRIVATE_LUA_CEMBED_GLOBAL_EVALUATION_CODE,
            PRIVATE_LUA_CEMBED_EVALUATION_NAME,
            formated_expresion
    );

    if(LuaCEmbed_evaluate(self, buffer)){
        free(formated_expresion);
        free(buffer);
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    free(buffer);

    lua_getglobal(self->state,PRIVATE_LUA_CEMBED_EVALUATION_NAME);

    int type = lua_type(self->state,-1);

    if(type != LUA_CEMBED_FUNCTION){
        privateLuaCEmbed_raise_error_not_jumping(self,PRIVATE_LUA_CEMBED_CODE_ITS_NOT_A_FUNCTION,formated_expresion);
        free(formated_expresion);
        return LUA_CEMBED_GENERIC_ERROR;
    }

    free(formated_expresion);
    lua_getglobal(self->state,PRIVATE_LUA_CEMBED_EVALUATION_NAME);
    privateLuaCEmbed_put_arg_on_top(self,index);

    if(lua_pcall(self->state,1,1,0)){
        const char *generated_error = lua_tostring(self->state,-1);
        privateLuaCEmbed_raise_error_not_jumping(self, generated_error);
    }
    return LUA_CEMBED_OK;
}

int privateLuaCembed_ensure_arg_evaluation_type(LuaCEmbed *self,int index,int expected_type){
    PRIVATE_LUA_CEMBED_PROTECT_NUM

    int actual_type = lua_type(self->state,-1);
    if(actual_type== expected_type){
        return LUA_CEMBED_OK;
    }

    privateLuaCEmbed_raise_error_not_jumping(self,
             PRIVATE_LUA_CEMBED_RESULT_EVALUATION_ARG_WRONG_TYPE,
             self->current_function,
             index,
             LuaCembed_convert_arg_code(actual_type),
             LuaCembed_convert_arg_code(expected_type)
     );
    return LUA_CEMBED_GENERIC_ERROR;
}
int LuaCEmbed_get_type_clojure_evalation(LuaCEmbed *self,int index,const char *code,...){
    PRIVATE_LUA_CEMBED_PROTECT_NUM

    va_list args;
    va_start(args,code);
    int possible_error = private_LuaCembed_run_code_with_args(self,index,code,args);
    va_end(args);
    if(possible_error){
        return possible_error;
    }
    return lua_type(self->state,-1);
}
int LuaCEmbed_generate_arg_clojure_evalation(LuaCEmbed *self,int index,const char *code,...){
    PRIVATE_LUA_CEMBED_PROTECT_NUM

    va_list args;
    va_start(args,code);
    int possible_error = private_LuaCembed_run_code_with_args(self,index,code,args);
    va_end(args);
    if(possible_error){
        return possible_error;
    }
    return LUA_CEMBED_OK;
}
long long LuaCEmbed_get_long_arg_clojure_evalation(LuaCEmbed *self,int index,const char *code,...){
    PRIVATE_LUA_CEMBED_PROTECT_NUM

    va_list args;
    va_start(args,code);
    int possible_error = private_LuaCembed_run_code_with_args(self,index,code,args);
    va_end(args);
    if(possible_error){
        return possible_error;
    }
    if(privateLuaCembed_ensure_arg_evaluation_type(self,index,LUA_CEMBED_NUMBER)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    return (long long) lua_tonumber(self->state,-1);

}


double LuaCEmbed_get_double_arg_clojure_evalation(LuaCEmbed *self,int index,const char *code,...){
    PRIVATE_LUA_CEMBED_PROTECT_NUM

    va_list args;
    va_start(args,code);
    int possible_error = private_LuaCembed_run_code_with_args(self,index,code,args);
    va_end(args);
    if(possible_error){
        return possible_error;
    }
    if(privateLuaCembed_ensure_arg_evaluation_type(self,index,LUA_CEMBED_NUMBER)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    return (double ) lua_tonumber(self->state,-1);

}

bool LuaCEmbed_get_bool_arg_clojure_evalation(LuaCEmbed *self,int index,const  char *code,...){
    PRIVATE_LUA_CEMBED_PROTECT_BOOL
    va_list args;
    va_start(args,code);
    int possible_error = private_LuaCembed_run_code_with_args(self,index,code,args);
    va_end(args);
    if(possible_error){
        return possible_error;
    }
    if(privateLuaCembed_ensure_arg_evaluation_type(self,index,LUA_CEMBED_NUMBER)){
        return  false;
    }
    return lua_toboolean(self->state,-1);

}

char* LuaCEmbed_get_string_arg_clojure_evalation(LuaCEmbed *self,int index,const  char *code,...){
    PRIVATE_LUA_CEMBED_PROTECT_NULL
    va_list args;
    va_start(args,code);
    int possible_error = private_LuaCembed_run_code_with_args(self,index,code,args);
    va_end(args);
    if(possible_error){
        return  NULL;
    }
    if(privateLuaCembed_ensure_arg_evaluation_type(self,index,LUA_CEMBED_NUMBER)){
        return  NULL;
    }
    return (char*)lua_tostring(self->state,-1);

}

