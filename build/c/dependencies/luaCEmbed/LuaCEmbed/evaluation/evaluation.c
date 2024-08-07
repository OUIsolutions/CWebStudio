

#ifdef _WIN32
VOID CALLBACK TimerHandler(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime) {

    privateLuaCEmbed_raise_error_not_jumping(global_current_lua_embed_object, PRIVATE_LUA_CEMBED_TIMEOUT_ERROR);
    lua_pushstring(global_current_lua_embed_object->state,PRIVVATE_LUA_CEMBED_TIMEOUT_ERROR);
    lua_error(global_current_lua_embed_object->state);
}

#else 

void private_LuaCembed_handle_timeout(int signum) {

    privateLuaCEmbed_raise_error_not_jumping(global_current_lua_embed_object, PRIVATE_LUA_CEMBED_TIMEOUT_ERROR);
    lua_pushstring(global_current_lua_embed_object->state,PRIVVATE_LUA_CEMBED_TIMEOUT_ERROR);
    lua_error(global_current_lua_embed_object->state);
}

#endif 



int privateLuaCEmbed_start_func_evaluation(lua_State *state){

    int evaluation_type = lua_tointeger(state, lua_upvalueindex(1));
    char *text_value = (char*)lua_touserdata(state,lua_upvalueindex(2));
    LuaCEmbed  *self = (LuaCEmbed*)lua_touserdata(state,lua_upvalueindex(3));
    global_current_lua_embed_object = self;
        #ifdef _WIN32
            if (lua_cembed_timeout > 0) {
                SetTimer(NULL, 0,lua_cembed_timeout > 0 * 1000, TimerHandler);
            }
        #else
            if (lua_cembed_timeout > 0) {
                signal(SIGALRM, private_LuaCembed_handle_timeout);
                alarm(lua_cembed_timeout);
            }
        #endif

    int error  = 0;
    if(evaluation_type == PRIVATE_LUA_EMBED_FILE_EVALUATION_TYPE){
        error =luaL_dofile(self->state,text_value);
    }
    if(evaluation_type == PRIVATE_LUA_EMBED_STRING_EVALUATION_TYPE){
        error = luaL_dostring(self->state,text_value);
    }
    if(error){
        privateLuaCEmbed_raise_error_not_jumping(self,lua_tostring(self->state,-1));
    }
    lua_pushinteger(self->state,error);

    return 1;

}
int LuaCEmbed_evaluate(LuaCEmbed *self, const char *code, ...){

    PRIVATE_LUA_CEMBED_PROTECT_NUM

    va_list args;
    va_start(args,code);
    char * formated_expresion = private_LuaCembed_format_vaarg(code,args);
    va_end(args);
    lua_pushinteger(self->state,PRIVATE_LUA_EMBED_STRING_EVALUATION_TYPE);
    lua_pushlightuserdata(self->state,(void*)formated_expresion); //code
    lua_pushlightuserdata(self->state,(void*)self); //code
    lua_pushcclosure(self->state,privateLuaCEmbed_start_func_evaluation,3);
    lua_pcall(self->state,0,1,0);
    int error = lua_tointeger(self->state,-1);
    free(formated_expresion);

    return error;

}

int LuaCEmbed_evaluete_file(LuaCEmbed *self, const char *file){
    PRIVATE_LUA_CEMBED_PROTECT_NUM


    lua_pushinteger(self->state,PRIVATE_LUA_EMBED_FILE_EVALUATION_TYPE);
    lua_pushlightuserdata(self->state,(void*)file); //code
    lua_pushlightuserdata(self->state,(void*)self); //code
    lua_pushcclosure(self->state,privateLuaCEmbed_start_func_evaluation,3);
    lua_pcall(self->state,0,1,0);
    int error = lua_tointeger(self->state,-1);
    return error;

}

int private_LuaCEmbed_evaluate_puting_on_top_of_stack(LuaCEmbed *self,const char *code, va_list args){

    char * formated_expresion =private_LuaCembed_format_vaarg(code,args);

    char * buffer =private_LuaCembed_format(
            PRIVATE_LUA_CEMBED_GLOBAL_EVALUATION_CODE,
            PRIVATE_LUA_CEMBED_EVALUATION_NAME,
            formated_expresion
    );

    if(LuaCEmbed_evaluate(self, buffer)){
        free(formated_expresion);
        free(buffer);
        return  LUA_CEMBED_GENERIC_ERROR;
    }

    lua_getglobal(self->state,PRIVATE_LUA_CEMBED_EVALUATION_NAME);

    int type = lua_type(self->state,-1);

    if(type == LUA_CEMBED_FUNCTION){
        if(lua_pcall(self->state,0,1,0)){
            const char *generated_error = lua_tostring(self->state,-1);
            privateLuaCEmbed_raise_error_not_jumping(self, generated_error);
        }
    }
    free(formated_expresion);
    free(buffer);
    return LUA_CEMBED_OK;

}
int private_LuaCEmbed_ensure_evaluation_type(LuaCEmbed *self,int type){

    int actual_type = lua_type(self->state,-1);
    if(actual_type== type){
        return LUA_CEMBED_OK;
    }


    privateLuaCEmbed_raise_error_not_jumping(self,
         PRIVATE_LUA_CEMBED_RESULT_EVALUATION_WRONG_TYPE,
         LuaCembed_convert_arg_code(actual_type),
         LuaCembed_convert_arg_code(type)
    );

    return LUA_CEMBED_GENERIC_ERROR;
}

char * LuaCEmbed_get_evaluation_string(LuaCEmbed *self,const char *code, ...){
    PRIVATE_LUA_CEMBED_PROTECT_NULL

    va_list args;
    va_start(args,code);
    int possible_error = private_LuaCEmbed_evaluate_puting_on_top_of_stack(self,code,args);
    va_end(args);
    if(possible_error){
        return  NULL;
    }

    if(private_LuaCEmbed_ensure_evaluation_type(self,LUA_CEMBED_STRING)){
        return NULL;
    }
    return (char*)lua_tostring(self->state,-1);

}


int  LuaCEmbed_get_evaluation_type(LuaCEmbed *self,const char *code, ...){
    PRIVATE_LUA_CEMBED_PROTECT_NUM

    va_list args;
    va_start(args,code);
    int possible_error = private_LuaCEmbed_evaluate_puting_on_top_of_stack(self,code,args);
    va_end(args);
    if(possible_error){
        return  LUA_CEMBED_GENERIC_ERROR;
    }

    return lua_type(self->state,-1);
}


long LuaCEmbed_get_evaluation_table_size(LuaCEmbed *self,const char *code, ...){
    PRIVATE_LUA_CEMBED_PROTECT_NUM

    va_list args;
    va_start(args,code);
    int possible_error = private_LuaCEmbed_evaluate_puting_on_top_of_stack(self,code,args);
    va_end(args);
    if(possible_error){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    if(private_LuaCEmbed_ensure_evaluation_type(self,LUA_CEMBED_TABLE)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    /*
    long  size = 0;
    lua_pushnil(self->state); // Coloca a chave nula na pilha
    while (lua_next(self->state, -1) != 0) { // Enquanto houver elementos na tabela
        size+=1;
        lua_pop(self->state, 1);
    }
     */

    return (long)lua_rawlen(self->state,-1);
}



long long  LuaCEmbed_get_evaluation_long(LuaCEmbed *self,const char *code, ...){
    PRIVATE_LUA_CEMBED_PROTECT_NUM

    va_list args;
    va_start(args,code);
    int possible_error = private_LuaCEmbed_evaluate_puting_on_top_of_stack(self,code,args);
    va_end(args);
    if(possible_error){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    if(private_LuaCEmbed_ensure_evaluation_type(self,LUA_CEMBED_NUMBER)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return (long)lua_tonumber(self->state,-1);

}

double LuaCEmbed_get_evaluation_double(LuaCEmbed *self,const char *code, ...){
    PRIVATE_LUA_CEMBED_PROTECT_NUM

    va_list args;
    va_start(args,code);
    int possible_error = private_LuaCEmbed_evaluate_puting_on_top_of_stack(self,code,args);
    va_end(args);
    if(possible_error){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    if(private_LuaCEmbed_ensure_evaluation_type(self,LUA_CEMBED_NUMBER)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return (double)lua_tonumber(self->state,-1);
}

bool LuaCEmbed_get_evaluation_bool(LuaCEmbed *self,const char *code, ...){
    PRIVATE_LUA_CEMBED_PROTECT_BOOL

    va_list args;
    va_start(args,code);
    int possible_error = private_LuaCEmbed_evaluate_puting_on_top_of_stack(self,code,args);
    va_end(args);
    if(possible_error){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    if(private_LuaCEmbed_ensure_evaluation_type(self,LUA_CEMBED_BOOL)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return (bool)lua_toboolean(self->state,-1);
}

