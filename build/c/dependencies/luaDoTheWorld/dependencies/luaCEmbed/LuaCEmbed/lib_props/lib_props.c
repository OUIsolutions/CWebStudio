

void LuaCEmbed_set_long_lib_prop(LuaCEmbed *self,const char *name,long long value){
    char *main_lib_table = private_LuaCembed_format(PRIVATE_LUA_CEMBED_MAIN_LIB_TABLE_NAME__,self->lib_identifier);

    lua_getglobal(self->state,main_lib_table);
    lua_pushvalue(self->state,-1);
    //set the function name
    lua_pushstring(self->state,name);
    lua_pushinteger(self->state,value);
    lua_settable(self->state,-3);
    free(main_lib_table);
}

void LuaCEmbed_set_double_lib_prop(LuaCEmbed *self,const char *name,double value){

    lua_getglobal(self->state,self->main_lib_table);
    lua_pushvalue(self->state,-1);
    //set the function name
    lua_pushstring(self->state,name);
    lua_pushnumber(self->state,value);
    lua_settable(self->state,-3);

}

void LuaCEmbed_set_bool_lib_prop(LuaCEmbed *self,const char *name,bool value){

    lua_getglobal(self->state,self->main_lib_table);
    lua_pushvalue(self->state,-1);
    //set the function name
    lua_pushstring(self->state,name);
    lua_pushboolean(self->state,value);
    lua_settable(self->state,-3);

}

void LuaCEmbed_set_string_lib_prop(LuaCEmbed *self,const char *name,const char * value){

    lua_getglobal(self->state,self->main_lib_table);
    lua_pushvalue(self->state,-1);
    //set the function name
    lua_pushstring(self->state,name);
    lua_pushstring(self->state,value);
    lua_settable(self->state,-3);

}

void LuaCEmbed_set_table_lib_prop(LuaCEmbed *self,const char *name,LuaCEmbedTable *value){

    lua_getglobal(self->state,self->main_lib_table);
    lua_pushvalue(self->state,-1);
    lua_pushstring(self->state,name);
    lua_getglobal(self->state,value->global_name);
    lua_settable(self->state,-3);

}

int private_LuaCEmbed_ensure_lib_prop_type(LuaCEmbed *self,const char *name,int expected_type){
    int type = lua_type(self->state,-1);
    if(type!= expected_type){
        privateLuaCEmbed_raise_error_not_jumping(
                self,
                PRIVATE_LUA_CEMBED_LIB_PROP_WRONG_TYPE,
                name,
                LuaCembed_convert_arg_code(type),
                LuaCembed_convert_arg_code(expected_type)
        );
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return LUA_CEMBED_OK;
}

long long  LuaCEmbed_get_long_lib_prop(LuaCEmbed *self,const char *name){
    lua_getglobal(self->state,self->main_lib_table);
    lua_getfield(self->state, -1,name);
    if(private_LuaCEmbed_ensure_lib_prop_type(self,name,LUA_CEMBED_NUMBER)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return lua_tointeger(self->state,-1);

}

double LuaCEmbed_get_double_lib_prop(LuaCEmbed *self,const char *name){

    lua_getglobal(self->state,self->main_lib_table);

    lua_getfield(self->state, -1,name);
    if(private_LuaCEmbed_ensure_lib_prop_type(self,name,LUA_CEMBED_NUMBER)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return lua_tonumber(self->state,-1);
}

bool LuaCEmbed_get_bool_lib_prop(LuaCEmbed *self,const char *name){

    lua_getglobal(self->state,self->main_lib_table);

    lua_getfield(self->state, -1,name);
    if(private_LuaCEmbed_ensure_lib_prop_type(self,name,LUA_CEMBED_BOOL)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return lua_toboolean(self->state,-1);
}

char * LuaCEmbed_get_string_lib_prop(LuaCEmbed *self,const char *name){
    lua_getglobal(self->state,self->main_lib_table);

    lua_getfield(self->state, -1,name);
    if(private_LuaCEmbed_ensure_lib_prop_type(self,name,LUA_CEMBED_STRING)){
        return NULL;
    }
    return (char*)lua_tostring(self->state,-1);
}

LuaCEmbedTable *LuaCEmbed_get_table_lib_prop(LuaCEmbed *self,const char *name){
;
    lua_getglobal(self->state,self->main_lib_table);

    lua_getfield(self->state, -1,name);
    if(private_LuaCEmbed_ensure_lib_prop_type(self,name,LUA_CEMBED_TABLE)){
        return NULL;
    }

    char *global_sub_table_name  = private_LuaCembed_format(
            PRIVATE_LUA_CEMBED_MAIN_LIB_SUB_TABLE,
            self->lib_identifier,
            name
            );
    lua_setglobal(self->state,global_sub_table_name);

    privateLuaCEmbedTableArray *target = (privateLuaCEmbedTableArray*)privateLuaCEmbed_get_current_table_array(self);

    LuaCEmbedTable  *possible = privateLuaCEmbedTableArray_find_by_global_name(target,global_sub_table_name);
    if(possible){
        free(global_sub_table_name);
        return possible;
    }

    LuaCEmbedTable  *creaeted = private_newLuaCembedTable(self, "%s",global_sub_table_name);
    free(global_sub_table_name);

    privateLuaCEmbedTableArray_append(
            target,
            creaeted
    );
    return creaeted;
}
