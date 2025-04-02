

int LuaCEmbed_get_global_type(LuaCEmbed *self,const char *name){
    PRIVATE_LUA_CEMBED_PROTECT_NUM

    lua_getglobal(self->state, name);
    return lua_type(self->state,-1);
}

long long  LuaCEmbed_get_global_long(LuaCEmbed *self,const char *name){
    PRIVATE_LUA_CEMBED_PROTECT_NUM

    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_NUMBER)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    lua_getglobal(self->state, name);
    return (long )lua_tonumber(self->state,-1);
}

double LuaCEmbed_get_global_double(LuaCEmbed *self,const char *name){
    PRIVATE_LUA_CEMBED_PROTECT_NUM

    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_NUMBER)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    lua_getglobal(self->state, name);
    return (double )lua_tonumber(self->state,-1);
}

bool LuaCEmbed_get_global_bool(LuaCEmbed *self,const char *name){
    PRIVATE_LUA_CEMBED_PROTECT_BOOL

    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_BOOL)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    lua_getglobal(self->state, name);
    return lua_toboolean(self->state,-1);
}

char * LuaCEmbed_get_global_raw_string(LuaCEmbed *self,const char *name,long *size){
    PRIVATE_LUA_CEMBED_PROTECT_NULL

    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_STRING)){
        return  NULL;
    }
    lua_getglobal(self->state, name);
    return (char*)lua_tolstring(self->state,-1,(size_t*)size);
}

char * LuaCEmbed_get_global_string(LuaCEmbed *self,const char *name){
    PRIVATE_LUA_CEMBED_PROTECT_NULL

    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_STRING)){
        return  NULL;
    }
    lua_getglobal(self->state, name);
    return (char*)lua_tostring(self->state,-1);
}

LuaCEmbedTable * LuaCembed_new_anonymous_table(LuaCEmbed *self){
    PRIVATE_LUA_CEMBED_PROTECT_NULL


    const char *format_raw = PRIVATE_LUA_CEMBED_ANONYMOUS_TABLE_;
    if(self->current_function){
       format_raw  =PRIVATE_LUA_CEMBED_ANONYMOUS_FUNC_TABLE_;
    }
    privateLuaCEmbedTableArray *target = (privateLuaCEmbedTableArray*)privateLuaCEmbed_get_current_table_array(self);
    char *buffer= private_LuaCembed_format(format_raw, self->stack_leve, target->size);
    LuaCEmbedTable  *created_table =LuaCembed_new_global_table(self,buffer);

    free(buffer);
    return created_table;
}



LuaCEmbedTable * LuaCembed_get_global_table(LuaCEmbed *self, const char *name){
    PRIVATE_LUA_CEMBED_PROTECT_NULL

    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_TABLE)){
        return  NULL;
    }

    privateLuaCEmbedTableArray *target = (privateLuaCEmbedTableArray*)privateLuaCEmbed_get_current_table_array(self);

    LuaCEmbedTable  *possible = privateLuaCEmbedTableArray_find_by_global_name(target,name);
    if(possible){
        return possible;
    }

    LuaCEmbedTable  *creaeted = private_newLuaCembedTable(self, "%s", name);

    privateLuaCEmbedTableArray_append(
            target,
            creaeted
    );
    return creaeted;
}

LuaCEmbedTable * LuaCembed_new_global_table(LuaCEmbed *self, const char *name){
    PRIVATE_LUA_CEMBED_PROTECT_NULL

    lua_newtable(self->state);
    lua_setglobal(self->state,name);
    privateLuaCEmbedTableArray *target = (privateLuaCEmbedTableArray*)privateLuaCEmbed_get_current_table_array(self);

    LuaCEmbedTable  *possible = privateLuaCEmbedTableArray_find_by_global_name(target,name);
    if(possible){
        return possible;
    }

    LuaCEmbedTable  *creaeted = private_newLuaCembedTable(self, "%s", name);

    privateLuaCEmbedTableArray_append(
            target,
            creaeted
    );
    return creaeted;
}

LuaCEmbedTable* LuaCEmbed_run_global_lambda(LuaCEmbed *self, const char *name, LuaCEmbedTable *args_to_call, int total_returns){

    PRIVATE_LUA_CEMBED_PROTECT_NULL

    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_FUNCTION)){
        return  NULL;
    }

    int total_args = private_lua_cEmbed_unpack(args_to_call,name);
    if(lua_pcall(self->state,total_args,total_returns,0)){
        privateLuaCEmbed_raise_error_not_jumping(self, lua_tostring(self->state,-1));
        return  NULL;
    }

    for(int i = 0; i < total_returns; i++){
        char *formatted = private_LuaCembed_format(PRIVATE_LUA_CEMBED_MULTIRETURN_, self->stack_leve, i);
        int position = (i +1) * -1;
        lua_pushvalue(self->state,position);
        lua_setglobal(self->state,formatted);
        free(formatted);
    }

    LuaCEmbedTable  *result = LuaCembed_new_anonymous_table(self);
    for(int i = 0; i < total_returns; i++){
        lua_getglobal(self->state,result->global_name);
        lua_pushinteger(self->state,i+1);
        char *formatted = private_LuaCembed_format(PRIVATE_LUA_CEMBED_MULTIRETURN_,self->stack_leve,i);
        lua_getglobal(self->state,formatted);
        lua_settable(self->state,-3);
        free(formatted);
    }

    return result;
}

