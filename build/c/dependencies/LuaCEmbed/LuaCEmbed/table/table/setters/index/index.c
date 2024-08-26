

void  LuaCEmbedTable_set_string_by_index(LuaCEmbedTable *self, long index, const char *value){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID

    char *possible_key = LuaCembedTable_get_key_by_index(self,index);
    if(possible_key){
        LuaCEmbedTable_set_string_prop(self,possible_key,value);
        return;
    }
    long formatted_index = index + LUA_CEMBED_INDEX_DIF;
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushnumber(self->main_object->state,(double)formatted_index);
    lua_pushstring(self->main_object->state,value);
    lua_settable(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);

}

void  LuaCEmbedTable_set_long_by_index(LuaCEmbedTable *self, long long  index, long  value){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID

    char *possible_key = LuaCembedTable_get_key_by_index(self,index);
    if(possible_key){
        LuaCEmbedTable_set_long_prop(self,possible_key,value);
        return;
    }
    long formatted_index = index + LUA_CEMBED_INDEX_DIF;
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushnumber(self->main_object->state,(double)formatted_index);
    lua_pushnumber(self->main_object->state,(double )value);
    lua_settable(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);

}

void  LuaCEmbedTable_set_double_by_index(LuaCEmbedTable *self, long index, double  value){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID

    char *possible_key = LuaCembedTable_get_key_by_index(self,index);
    if(possible_key){
        LuaCEmbedTable_set_double_prop(self,possible_key,value);
        return;
    }

    long formatted_index = index + LUA_CEMBED_INDEX_DIF;
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushnumber(self->main_object->state,(double)formatted_index);
    lua_pushnumber(self->main_object->state,(double )value);
    lua_settable(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);

}

void  LuaCEmbedTable_set_bool_by_index(LuaCEmbedTable *self, long index, bool value){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID

    char *possible_key = LuaCembedTable_get_key_by_index(self,index);
    if(possible_key){
        LuaCEmbedTable_set_bool_prop(self,possible_key,value);
        return;
    }

    long formatted_index = index + LUA_CEMBED_INDEX_DIF;
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushnumber(self->main_object->state,(double)formatted_index);
    lua_pushboolean(self->main_object->state,value);
    lua_settable(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);

}


void  LuaCEmbedTable_set_evaluation_by_index(LuaCEmbedTable *self, long index, const char *code, ...){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID

    long formatted_index = index + LUA_CEMBED_INDEX_DIF;
    va_list  args;
    va_start(args,code);
    char *  buffer = private_LuaCembed_format_vaarg(code,args);
    va_end(args);

    LuaCEmbed_evaluate(self->main_object,
                       PRIVATE_LUA_CEMBED_GLOBAL_EVALUATION_CODE,
                       PRIVATE_LUA_CEMBED_EVALUATION_NAME,
                       buffer
    );
    free(buffer);
    if(LuaCEmbed_has_errors(self->main_object)){
        return;
    }
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushnumber(self->main_object->state,(double)formatted_index);
    lua_getglobal(self->main_object->state,PRIVATE_LUA_CEMBED_EVALUATION_NAME);
    lua_settable(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);

}
